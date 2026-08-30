// quantum_dispatcher.v
//
// Accumulates accepted beats by instruction ID and commits one per-qubit
// FIFO-write burst. All touched qubits receive one dispatch timestamp.
//
// A new instruction ID flushes the previous instruction; an idle timeout
// flushes the final one. quantum_last_cycle is not a reliable stream-end
// marker on the current QV.SINGLE/QV.PAIR interface.
//
// Each timed_fifo stores {dispatch_time, role, GateID} and emits one gate
// pulse when the global counter reaches dispatch_time.

`timescale 1ns / 1ps

module quantum_dispatcher #(
    // Number of physical qubits this dispatcher handles.
    // Must be <= 256 (8-bit qubit index from elem1/elem2).
    parameter NUM_QUBITS  = 8,

    // Depth of the per-qubit instruction FIFO (passed to timed_fifo).
    parameter FIFO_DEPTH  = 8,

    // Width of the free-running global time counter.
    parameter TIME_WIDTH  = 20,

    // Width of the gate word stored per qubit = GateID width (elem3[31:25]).
    parameter GATE_WIDTH  = 7,

    // Width of Block_imm timing field (elem3[11:7]).
    // 5-bit since the mask bit was removed (RFC #3 / custom-0 migration).
    parameter BLOCK_IMM_W = 5,

    // Flush-relative offset used when Block_imm is zero.
    parameter FIXED_LATENCY = 4
)(
    input  wire                              clk,
    input  wire                              reset,

    // Free-running global time counter (same domain as qvproc clk).
    // Provided externally; used by each per-qubit timed_fifo.
    input  wire [TIME_WIDTH-1:0]             t_cnt,

    // ------------------------------------------------------------------ //
    // qvproc quantum output interface (connect directly to vproc_top ports)
    // ------------------------------------------------------------------ //
    input  wire                              quantum_valid,
    input  wire [4:0]                        quantum_op,
    input  wire [2:0]                        quantum_instr_id, // burst-write trigger (see above)
    input  wire [31:0]                       quantum_elem1,   // [7:0] = primary index (PAIR control)
    input  wire [31:0]                       quantum_elem2,   // [7:0] = PAIR target or payload
    input  wire [31:0]                       quantum_elem3,   // [31:25]=GateID, [11:7]=Block_imm
    input  wire                              quantum_data_ready,
    input  wire                              quantum_first_cycle,
    input  wire                              quantum_last_cycle, // NOT used for burst timing -- see note below

    // ------------------------------------------------------------------ //
    // Per-qubit gate outputs
    //   qubit_gate_o  : flat bus; bits [GATE_WIDTH*(q+1)-1 : GATE_WIDTH*q]
    //                   are the gate word for qubit q.
    //   qubit_valid_o : bit q is high for one cycle when qubit q's gate fires.
    //   qubit_error_o : bit q is high if qubit q's FIFO overflowed.
    // ------------------------------------------------------------------ //
    output wire [GATE_WIDTH*NUM_QUBITS-1:0]  qubit_gate_o,
    output wire [NUM_QUBITS-1:0]             qubit_valid_o,
    output wire [NUM_QUBITS-1:0]             qubit_error_o,
    // For QV.PAIR: 1 = this qubit is the control side (elem1/vs1),
    //              0 = this qubit is the target side  (elem2/vs2).
    // For QV.SINGLE / QV.ROTG / QV.ROTV: always 1.
    output wire [NUM_QUBITS-1:0]             qubit_ctrl_o,
    // Opaque 32-bit payload (currently: ROT.G/ROT.V rotation angle) queued
    // and fired atomically with the gate/role above. RTL never interprets
    // this value -- it is a software/backend ABI, not an RTL contract (same
    // convention as measure_result_i). Valid only when the corresponding
    // qubit_payload_valid_o bit is set; SINGLE/PAIR fires leave it at 0/don't-care.
    output wire [32*NUM_QUBITS-1:0]          qubit_payload_o,
    output wire [NUM_QUBITS-1:0]             qubit_payload_valid_o,

    // Per-event error pulses. QV.PAIR bounds failures are reported only as
    // invalid_pair_error_o; neither endpoint is written for that beat.
    output wire                              invalid_index_error_o,
    output wire                              invalid_pair_error_o,
    // Illegal covers a repeated qubit within one instruction, a QV.PAIR
    // with identical endpoints, or a new instruction that would schedule a
    // qubit at a timestamp already pending in that qubit's timed FIFO.
    output wire                              illegal_error_o,
    // High for one cycle when a whole instruction is atomically rejected
    // because at least one touched qubit's FIFO had no room. Applies to
    // every multi-target instruction class (SINGLE/PAIR/ROT.G/ROT.V), not
    // just PAIR/ROT -- a burst either commits to every touched qubit or to
    // none of them, never partially. Without this signal, a capacity-
    // triggered atomic rejection would produce no error indication at all:
    // the per-qubit `error` pulse inside timed_fifo only fires on an
    // *attempted* write to a full FIFO, and preflight means that write is
    // never attempted in the first place.
    output wire                              capacity_error_o
);

    // ------------------------------------------------------------------ //
    // Quantum op codes (must match vproc_top / vproc_pkg.sv definitions)
    // ------------------------------------------------------------------ //
    localparam ELEM_QSINGLE = 5'd16;
    localparam ELEM_QPAIR   = 5'd17;
    localparam ELEM_QROTG   = 5'd18;
    localparam ELEM_QROTV   = 5'd19;

    // Must exceed every legal gap within one instruction stream.
    localparam IDLE_FLUSH_CYCLES = 8;

    // Latch metadata because the beat that flushes the old ID already drives
    // the new instruction's elem3 values.
    wire [GATE_WIDTH-1:0]  gate_id   = quantum_elem3[31:25];
    wire [BLOCK_IMM_W-1:0] block_imm = quantum_elem3[7 +: BLOCK_IMM_W];  // [11:7]
    // QV.PAIR maps elem1/vs1 to control and elem2/vs2 to target.
    wire [7:0]             elem1_qubit = quantum_elem1[7:0];
    wire [7:0]             elem2_qubit = quantum_elem2[7:0];  // valid for QV.PAIR only

    wire beat_valid = quantum_valid && quantum_data_ready;

    // ------------------------------------------------------------------ //
    // This beat's own contribution to the touched-qubit set.
    // ------------------------------------------------------------------ //
    reg [NUM_QUBITS-1:0] beat_touch, beat_touch_ctrl;
    always @(*) begin
        beat_touch      = {NUM_QUBITS{1'b0}};
        beat_touch_ctrl = {NUM_QUBITS{1'b0}};
        if (beat_valid && (quantum_op == ELEM_QPAIR)) begin
            // A pair beat is atomic: both endpoints must be in range and
            // distinct before either endpoint contributes to the burst.
            if ((elem1_qubit < NUM_QUBITS) &&
                (elem2_qubit < NUM_QUBITS) &&
                (elem2_qubit != elem1_qubit)) begin
                beat_touch     [elem1_qubit] = 1'b1;
                beat_touch_ctrl[elem1_qubit] = 1'b1;   // control / primary
                beat_touch     [elem2_qubit] = 1'b1;
                beat_touch_ctrl[elem2_qubit] = 1'b0;   // target / secondary
            end
        end else if (beat_valid && (elem1_qubit < NUM_QUBITS)) begin
            beat_touch     [elem1_qubit] = 1'b1;
            beat_touch_ctrl[elem1_qubit] = 1'b1;
        end
    end

    wire pair_invalid_index = beat_valid && (quantum_op == ELEM_QPAIR) &&
                              ((elem1_qubit >= NUM_QUBITS) ||
                               (elem2_qubit >= NUM_QUBITS));
    assign invalid_pair_error_o  = pair_invalid_index;
    assign invalid_index_error_o = beat_valid && (quantum_op != ELEM_QPAIR) &&
                                   (elem1_qubit >= NUM_QUBITS);

    // ------------------------------------------------------------------ //
    // Accumulator: touched-qubit set, role bits, GateID and Block_imm for
    // whichever instruction is currently being collected.
    // ------------------------------------------------------------------ //
    reg [NUM_QUBITS-1:0]  touched_q, touched_ctrl_q;
    reg [GATE_WIDTH-1:0]  gate_id_q;
    reg [BLOCK_IMM_W-1:0] block_imm_q;
    reg [4:0]             active_op_q;
    reg [2:0]             active_id_q;
    reg                   active_valid_q;   // touched_q/etc hold a real pending instruction
    reg                   active_illegal_q; // reject the whole accumulated instruction
    reg [$clog2(IDLE_FLUSH_CYCLES+1)-1:0] idle_ctr_q;

    // Per-qubit payload (ROT.G/ROT.V angle). Indexed by physical qubit, not
    // by beat order, so ROT.V's per-element angles land next to the right
    // qubit even though beats for different qubits arrive on different
    // cycles. ROT.G broadcasts the same value to every touched qubit's
    // entry (a beat is issued per target qubit upstream, so this is just
    // "write whichever qubit this beat touches", identical code path to
    // ROT.V -- no special-casing needed here).
    reg [31:0] payload_q [0:NUM_QUBITS-1];
    integer pj;
    // One accumulated instruction is architecturally always one op class
    // (enforced by metadata_mismatch above), so "does this instruction carry
    // a payload" is a single derived bit, not per-qubit state -- avoids a
    // second register that could drift out of sync with active_op_q.
    wire active_has_payload = (active_op_q == ELEM_QROTG) || (active_op_q == ELEM_QROTV);
    wire beat_has_payload = beat_valid &&
                            ((quantum_op == ELEM_QROTG) || (quantum_op == ELEM_QROTV)) &&
                            (elem1_qubit < NUM_QUBITS);

    // A new ID closes the previously accumulated instruction.
    wire new_instr  = beat_valid && (!active_valid_q || (quantum_instr_id != active_id_q));
    wire idle_flush = active_valid_q && !beat_valid && (idle_ctr_q >= IDLE_FLUSH_CYCLES);
    // Flush the old state, not the beat that triggered new_instr.
    wire flush_prev = (new_instr && active_valid_q) || idle_flush;

    wire pair_same_endpoint = beat_valid && (quantum_op == ELEM_QPAIR) &&
                              !pair_invalid_index && (elem2_qubit == elem1_qubit);
    wire repeated_in_instruction = beat_valid && active_valid_q &&
                                   (quantum_instr_id == active_id_q) &&
                                   (|(beat_touch & touched_q));
    // Every beat of one accumulated instruction is architecturally expected to
    // share the same op class, GateID and block_imm (one instruction = one
    // funct3/funct7/block_imm). This was never enforced in RTL -- it relied
    // entirely on an unverified upstream invariant. A later beat that
    // disagrees now rejects the whole instruction instead of silently mixing
    // metadata from two different instructions under one ID.
    wire metadata_mismatch = beat_valid && active_valid_q &&
                             (quantum_instr_id == active_id_q) &&
                             ((quantum_op != active_op_q) ||
                              (gate_id     != gate_id_q)   ||
                              (block_imm   != block_imm_q));
    wire beat_illegal = pair_same_endpoint || repeated_in_instruction || metadata_mismatch;

    always @(posedge clk) begin
        if (reset) begin
            touched_q      <= {NUM_QUBITS{1'b0}};
            touched_ctrl_q <= {NUM_QUBITS{1'b0}};
            gate_id_q      <= {GATE_WIDTH{1'b0}};
            block_imm_q    <= {BLOCK_IMM_W{1'b0}};
            active_op_q    <= 5'b0;
            active_id_q    <= 3'b0;
            active_valid_q <= 1'b0;
            active_illegal_q <= 1'b0;
            idle_ctr_q     <= 0;
            for (pj = 0; pj < NUM_QUBITS; pj = pj + 1)
                payload_q[pj] <= 32'b0;
        end else if (beat_valid && new_instr) begin
            // The old state flushes combinationally; this starts the new ID.
            touched_q      <= beat_touch;
            touched_ctrl_q <= beat_touch_ctrl;
            gate_id_q      <= gate_id;
            block_imm_q    <= block_imm;
            active_op_q    <= quantum_op;
            active_id_q    <= quantum_instr_id;
            active_valid_q <= 1'b1;
            active_illegal_q <= beat_illegal;
            idle_ctr_q     <= 0;
            if (beat_has_payload) payload_q[elem1_qubit] <= quantum_elem2;
        end else if (beat_valid) begin
            // Any repeated qubit invalidates the accumulated instruction.
            touched_q      <= touched_q | beat_touch;
            touched_ctrl_q <= (beat_touch_ctrl & beat_touch) | (touched_ctrl_q & ~beat_touch);
            active_illegal_q <= active_illegal_q | beat_illegal;
            idle_ctr_q     <= 0;
            if (beat_has_payload) payload_q[elem1_qubit] <= quantum_elem2;
        end else if (idle_flush) begin
            // No later ID will flush the final instruction.
            touched_q      <= {NUM_QUBITS{1'b0}};
            touched_ctrl_q <= {NUM_QUBITS{1'b0}};
            active_valid_q <= 1'b0;
            active_illegal_q <= 1'b0;
            idle_ctr_q     <= 0;
        end else if (active_valid_q) begin
            idle_ctr_q <= idle_ctr_q + 1'b1;
        end
    end

    // ------------------------------------------------------------------ //
    // Flush-relative dispatch time shared by the whole instruction.
    // block_imm=0 selects FIXED_LATENCY.
    // ------------------------------------------------------------------ //
    wire use_fixed_latency = (block_imm_q == {BLOCK_IMM_W{1'b0}});
    wire [TIME_WIDTH-1:0] fixed_lat = FIXED_LATENCY;
    wire [TIME_WIDTH-1:0] dispatch_time =
        t_cnt + (use_fixed_latency ? fixed_lat
                                    : {{(TIME_WIDTH-BLOCK_IMM_W){1'b0}}, block_imm_q});

    // ------------------------------------------------------------------ //
    // Commit every touched qubit in the same cycle.
    // ------------------------------------------------------------------ //
    wire [NUM_QUBITS-1:0]  fifo_time_conflict;
    wire [NUM_QUBITS-1:0]  fifo_write_ready;
    wire flush_timestamp_conflict = flush_prev && !active_illegal_q &&
                                    (|(touched_q & fifo_time_conflict));
    // Burst-wide capacity preflight: an instruction commits to every touched
    // qubit or to none of them. Checked independently of the timestamp
    // conflict above (both can be true for the same flush, and both should
    // be reported if so) -- without this, a burst could partially execute
    // when one destination FIFO is full and another is not, applying (say)
    // a rotation to some qubits in the group but not others.
    wire flush_capacity_reject    = flush_prev && !active_illegal_q &&
                                    (|(touched_q & ~fifo_write_ready));
    wire flush_reject = active_illegal_q || flush_timestamp_conflict || flush_capacity_reject;
    wire [NUM_QUBITS-1:0]  fifo_we       =
        (flush_prev && !flush_reject) ? touched_q : {NUM_QUBITS{1'b0}};
    wire [NUM_QUBITS-1:0]  fifo_ctrl     = touched_ctrl_q;
    wire [GATE_WIDTH-1:0]  gate_id_for_write = gate_id_q;

    assign illegal_error_o  = beat_illegal || flush_timestamp_conflict;
    assign capacity_error_o = flush_capacity_reject;

    // ------------------------------------------------------------------ //
    // Per-qubit timed_fifo instances
    // ------------------------------------------------------------------ //
    // Fire-time command word, MSB to LSB: payload(32) : payload_valid(1) :
    // role(1) : gate_id(GATE_WIDTH). One atomic timed_fifo entry, so payload
    // and gate/role can never separate even with several commands queued.
    localparam PAYLOAD_WIDTH = 32;
    localparam CMD_OP_WIDTH  = GATE_WIDTH + 1 + 1 + PAYLOAD_WIDTH;

    genvar i;
    generate
        for (i = 0; i < NUM_QUBITS; i = i + 1) begin : GEN_QUBIT
            wire [CMD_OP_WIDTH-1:0] gate_out_wide;
            wire                    gate_valid;
            wire                    err_out;

            timed_fifo #(
                .FIFO_DEPTH (FIFO_DEPTH),
                .TIME_WIDTH (TIME_WIDTH),
                .OP_WIDTH   (CMD_OP_WIDTH)
            ) u_timed_fifo (
                .clk        (clk),
                .reset      (reset),
                .i_fifo_time(dispatch_time),
                .i_fifo_op  ({payload_q[i], active_has_payload, fifo_ctrl[i], gate_id_for_write}),
                .i_fifo_we  (fifo_we[i]),
                .t_cnt      (t_cnt),
                .o_data     (gate_out_wide),
                .o_valid    (gate_valid),
                .error      (err_out),
                .time_conflict(fifo_time_conflict[i]),
                .write_ready(fifo_write_ready[i])
            );

            // Flat bus slice for qubit i
            assign qubit_gate_o[(i+1)*GATE_WIDTH-1 -: GATE_WIDTH] = gate_out_wide[GATE_WIDTH-1:0];
            assign qubit_ctrl_o[i]          = gate_out_wide[GATE_WIDTH];       // role bit
            assign qubit_payload_valid_o[i] = gate_out_wide[GATE_WIDTH+1];
            assign qubit_payload_o[(i+1)*PAYLOAD_WIDTH-1 -: PAYLOAD_WIDTH] =
                gate_out_wide[CMD_OP_WIDTH-1 -: PAYLOAD_WIDTH];
            assign qubit_error_o[i] = err_out;

            // valid = explicit pulse from time_controller ISSUE state.
            // Valid is independent of the GateID value, including GateID zero.
            assign qubit_valid_o[i] = gate_valid;
        end
    endgenerate

endmodule
