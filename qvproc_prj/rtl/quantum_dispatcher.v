// quantum_dispatcher.v
//
// Sits between the qvproc vector core quantum output ports and a bank of
// per-qubit timed_fifo instances.
//
// Each cycle that quantum_valid && quantum_data_ready are high, the module:
//   1. Extracts the target qubit index from quantum_elem1[7:0].
//   2. Extracts the GateID  from quantum_elem3[31:25] (7-bit operation word).
//   3. Extracts Block_imm  from quantum_elem3[10:7]  (4-bit timing offset).
//   4. Computes dispatch_time = base_time + Block_imm, where base_time is
//      t_cnt latched at the first cycle of the current instruction stream.
//   5. Writes {GateID} into the target qubit's timed_fifo.
//   6. For QV.PAIR instructions, also writes to the source qubit's FIFO
//      (source index from quantum_elem2[7:0]).
//
// Each timed_fifo holds the (dispatch_time, GateID) pair and releases
// GateID on qubit_gate_o when the global counter t_cnt reaches
// dispatch_time (matching the time_controller ISSUE condition).
//
// Port naming:
//   quantum_*  : directly driven from vproc_top output ports (same names)
//   qubit_gate_o : flat bus [GATE_WIDTH*NUM_QUBITS-1:0], LSB = qubit 0
//   qubit_valid_o: high for one cycle when the gate is being issued
//   qubit_error_o: FIFO overflow per qubit

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

    // Fixed latency (in t_cnt ticks) used when Block_imm == 0.
    // Must be large enough that the timed_fifo write completes before
    // t_cnt reaches dispatch_time.  A value of 4-8 is typically sufficient.
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
    input  wire [31:0]                       quantum_elem1,   // [7:0] = target qubit index
    input  wire [31:0]                       quantum_elem2,   // [7:0] = source qubit (QV.PAIR)
    input  wire [31:0]                       quantum_elem3,   // [31:25]=GateID, [10:7]=Block_imm
    input  wire                              quantum_data_ready,
    input  wire                              quantum_first_cycle,
    input  wire                              quantum_last_cycle,  // reserved, available for future use

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
    output wire [NUM_QUBITS-1:0]             qubit_ctrl_o
);

    // ------------------------------------------------------------------ //
    // Quantum op codes (must match vproc_top / vproc_pkg.sv definitions)
    // ------------------------------------------------------------------ //
    localparam ELEM_QSINGLE = 5'd16;
    localparam ELEM_QPAIR   = 5'd17;
    localparam ELEM_QROTG   = 5'd18;
    localparam ELEM_QROTV   = 5'd19;

    // ------------------------------------------------------------------ //
    // Field extraction
    // ------------------------------------------------------------------ //
    wire [GATE_WIDTH-1:0]  gate_id   = quantum_elem3[31:25];
    wire [BLOCK_IMM_W-1:0] block_imm = quantum_elem3[7 +: BLOCK_IMM_W];  // [11:7]
    wire [7:0]             tgt_qubit = quantum_elem1[7:0];
    wire [7:0]             src_qubit = quantum_elem2[7:0];  // valid for QV.PAIR only

    // ------------------------------------------------------------------ //
    // Base time: latch t_cnt at quantum_first_cycle of each instruction
    // stream, then hold for the remaining beats of that stream.
    //
    // On the very first beat (first_cycle is high this cycle), use t_cnt
    // directly in the combinational dispatch_time to avoid a one-cycle
    // pipeline stall.
    // ------------------------------------------------------------------ //
    reg [TIME_WIDTH-1:0] base_time_q;

    always @(posedge clk) begin
        if (reset) begin
            base_time_q <= {TIME_WIDTH{1'b0}};
        end else if (quantum_valid && quantum_first_cycle) begin
            base_time_q <= t_cnt;
        end
    end

    // Combinational: correct on first_cycle AND on subsequent beats
    wire [TIME_WIDTH-1:0] cur_base =
        (quantum_valid && quantum_first_cycle) ? t_cnt : base_time_q;

    // Dispatch time selection:
    //   block_imm != 0  ->  cur_base + block_imm   (scheduled: fire at specified slot)
    //   block_imm == 0  ->  cur_base + FIXED_LATENCY  (unscheduled: fixed offset from
    //                        instruction start, same for every element in the stream)
    //
    // Both cases anchor to cur_base (= t_cnt latched at first_cycle), so all elements
    // of the same vector instruction share one dispatch_time and fire together.
    //
    // FIXED_LATENCY constraint: must be > VL_MAX + 1, where VL_MAX is the longest
    // qubit-index stream this dispatcher will receive.  This guarantees the last
    // FIFO write completes before the time_controller's WAIT window expires.
    wire use_fixed_latency = (block_imm == {BLOCK_IMM_W{1'b0}});
    wire [TIME_WIDTH-1:0] fixed_lat    = FIXED_LATENCY;   // parameter -> wire, width extended
    wire [TIME_WIDTH-1:0] dispatch_time =
        cur_base + (use_fixed_latency ? fixed_lat
                                      : {{(TIME_WIDTH-BLOCK_IMM_W){1'b0}}, block_imm});

    // ------------------------------------------------------------------ //
    // FIFO write enable per qubit
    //
    // Gate the write on quantum_data_ready to suppress QROTV startup-window
    // beats where elem1/elem2 are not yet valid.
    // ------------------------------------------------------------------ //
    // fifo_we   : write enable per qubit
    // fifo_ctrl : role bit per qubit (1 = control/primary elem1, 0 = target/secondary elem2)
    reg [NUM_QUBITS-1:0] fifo_we;
    reg [NUM_QUBITS-1:0] fifo_ctrl;
    integer ch;

    always @(*) begin
        fifo_we   = {NUM_QUBITS{1'b0}};
        fifo_ctrl = {NUM_QUBITS{1'b0}};
        if (quantum_valid && quantum_data_ready) begin
            // All op types: write gate to the target qubit (primary / control side)
            if (tgt_qubit < NUM_QUBITS) begin
                fifo_we  [tgt_qubit] = 1'b1;
                fifo_ctrl[tgt_qubit] = 1'b1;   // control / primary
            end

            // QV.PAIR only: source qubit is the target side of the two-qubit gate
            if ((quantum_op == ELEM_QPAIR) &&
                (src_qubit < NUM_QUBITS) &&
                (src_qubit != tgt_qubit)) begin
                fifo_we  [src_qubit] = 1'b1;
                fifo_ctrl[src_qubit] = 1'b0;   // target / secondary
            end
        end
    end

    // ------------------------------------------------------------------ //
    // Per-qubit timed_fifo instances
    // ------------------------------------------------------------------ //
    genvar i;
    generate
        for (i = 0; i < NUM_QUBITS; i = i + 1) begin : GEN_QUBIT
            // OP_WIDTH = GATE_WIDTH + 1: the extra MSB carries the role bit.
            //   stored word = { fifo_ctrl[i], gate_id }
            //   on output  : gate = o_data[GATE_WIDTH-1:0]
            //                ctrl = o_data[GATE_WIDTH]   (1=control, 0=target)
            wire [GATE_WIDTH:0] gate_out_wide;   // GATE_WIDTH+1 bits
            wire                gate_valid;
            wire                err_out;

            timed_fifo #(
                .FIFO_DEPTH (FIFO_DEPTH),
                .TIME_WIDTH (TIME_WIDTH),
                .OP_WIDTH   (GATE_WIDTH + 1)
            ) u_timed_fifo (
                .clk        (clk),
                .reset      (reset),
                .i_fifo_time(dispatch_time),
                .i_fifo_op  ({fifo_ctrl[i], gate_id}),   // MSB = role
                .i_fifo_we  (fifo_we[i]),
                .t_cnt      (t_cnt),
                .o_data     (gate_out_wide),
                .o_valid    (gate_valid),
                .error      (err_out)
            );

            // Flat bus slice for qubit i
            assign qubit_gate_o[(i+1)*GATE_WIDTH-1 -: GATE_WIDTH] = gate_out_wide[GATE_WIDTH-1:0];
            assign qubit_ctrl_o[i]  = gate_out_wide[GATE_WIDTH];   // role bit
            assign qubit_error_o[i] = err_out;

            // valid = explicit pulse from time_controller ISSUE state.
            // This correctly handles GateID == 0 (e.g. QV.PAIR CNOT in Bell program).
            assign qubit_valid_o[i] = gate_valid;
        end
    endgenerate

endmodule
