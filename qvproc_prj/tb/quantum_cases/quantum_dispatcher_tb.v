`timescale 1ns / 1ps

// Directed specification test for quantum_dispatcher error semantics.
module quantum_dispatcher_tb;
    parameter NUM_QUBITS    = 8;
    parameter FIFO_DEPTH    = 2;
    parameter TIME_WIDTH    = 12;
    parameter GATE_WIDTH    = 7;
    parameter BLOCK_IMM_W   = 5;
    parameter FIXED_LATENCY = 100;

    localparam ELEM_QSINGLE = 5'd16;
    localparam ELEM_QPAIR   = 5'd17;
    localparam ELEM_QROTG   = 5'd18;
    localparam ELEM_QROTV   = 5'd19;

    reg clk;
    reg reset;
    reg [TIME_WIDTH-1:0] t_cnt;
    reg quantum_valid;
    reg [4:0] quantum_op;
    reg [2:0] quantum_instr_id;
    reg [31:0] quantum_elem1;
    reg [31:0] quantum_elem2;
    reg [31:0] quantum_elem3;
    reg quantum_data_ready;
    reg quantum_first_cycle;
    reg quantum_last_cycle;

    wire [GATE_WIDTH*NUM_QUBITS-1:0] qubit_gate;
    wire [NUM_QUBITS-1:0] qubit_valid;
    wire [NUM_QUBITS-1:0] qubit_error;
    wire [NUM_QUBITS-1:0] qubit_ctrl;
    wire [32*NUM_QUBITS-1:0] qubit_payload;
    wire [NUM_QUBITS-1:0] qubit_payload_valid;
    wire invalid_index_error;
    wire invalid_pair_error;
    wire illegal_error;
    wire capacity_error;

    integer invalid_index_count;
    integer invalid_pair_count;
    integer overflow_count;
    integer illegal_count;
    integer capacity_error_count;
    integer fire_count;
    integer fire_per_q [0:NUM_QUBITS-1];
    reg [TIME_WIDTH-1:0] last_fire_time [0:NUM_QUBITS-1];
    reg [31:0] last_fire_payload [0:NUM_QUBITS-1];
    reg last_fire_payload_valid [0:NUM_QUBITS-1];
    integer failures;
    integer checks;
    integer i;

    initial clk = 1'b0;
    always #5 clk = ~clk;

    always @(posedge clk) begin
        if (reset)
            t_cnt <= {TIME_WIDTH{1'b0}};
        else
            t_cnt <= t_cnt + 1'b1;
    end

    quantum_dispatcher #(
        .NUM_QUBITS(NUM_QUBITS),
        .FIFO_DEPTH(FIFO_DEPTH),
        .TIME_WIDTH(TIME_WIDTH),
        .GATE_WIDTH(GATE_WIDTH),
        .BLOCK_IMM_W(BLOCK_IMM_W),
        .FIXED_LATENCY(FIXED_LATENCY)
    ) dut (
        .clk(clk),
        .reset(reset),
        .t_cnt(t_cnt),
        .quantum_valid(quantum_valid),
        .quantum_op(quantum_op),
        .quantum_instr_id(quantum_instr_id),
        .quantum_elem1(quantum_elem1),
        .quantum_elem2(quantum_elem2),
        .quantum_elem3(quantum_elem3),
        .quantum_data_ready(quantum_data_ready),
        .quantum_first_cycle(quantum_first_cycle),
        .quantum_last_cycle(quantum_last_cycle),
        .qubit_gate_o(qubit_gate),
        .qubit_valid_o(qubit_valid),
        .qubit_error_o(qubit_error),
        .qubit_ctrl_o(qubit_ctrl),
        .qubit_payload_o(qubit_payload),
        .qubit_payload_valid_o(qubit_payload_valid),
        .invalid_index_error_o(invalid_index_error),
        .invalid_pair_error_o(invalid_pair_error),
        .illegal_error_o(illegal_error),
        .capacity_error_o(capacity_error)
    );

    always @(posedge clk) begin
        if (reset) begin
            invalid_index_count = 0;
            invalid_pair_count  = 0;
            overflow_count      = 0;
            illegal_count       = 0;
            capacity_error_count = 0;
            fire_count          = 0;
            for (i = 0; i < NUM_QUBITS; i = i + 1) begin
                fire_per_q[i]   = 0;
                last_fire_time[i] = 0;
                last_fire_payload[i] = 0;
                last_fire_payload_valid[i] = 0;
            end
        end else begin
            if (invalid_index_error) invalid_index_count = invalid_index_count + 1;
            if (invalid_pair_error)  invalid_pair_count  = invalid_pair_count + 1;
            if (|qubit_error)        overflow_count      = overflow_count + 1;
            if (illegal_error)       illegal_count       = illegal_count + 1;
            if (capacity_error)      capacity_error_count = capacity_error_count + 1;
            for (i = 0; i < NUM_QUBITS; i = i + 1) begin
                if (qubit_valid[i]) begin
                    fire_count        = fire_count + 1;
                    fire_per_q[i]     = fire_per_q[i] + 1;
                    last_fire_time[i] = t_cnt;
                    last_fire_payload[i] = qubit_payload[(i+1)*32-1 -: 32];
                    last_fire_payload_valid[i] = qubit_payload_valid[i];
                end
            end
        end
    end

    function [31:0] make_elem3;
        input [GATE_WIDTH-1:0] gate;
        input [BLOCK_IMM_W-1:0] block_imm;
        begin
            make_elem3 = {gate, 13'b0, block_imm, 7'b0};
        end
    endfunction

    task idle_bus;
        begin
            quantum_valid       = 1'b0;
            quantum_op          = 5'b0;
            quantum_instr_id    = 3'b0;
            quantum_elem1       = 32'b0;
            quantum_elem2       = 32'b0;
            quantum_elem3       = 32'b0;
            quantum_data_ready  = 1'b0;
            quantum_first_cycle = 1'b0;
            quantum_last_cycle  = 1'b0;
        end
    endtask

    task tick;
        begin
            @(posedge clk);
            #1;
        end
    endtask

    task wait_cycles;
        input integer count;
        integer n;
        begin
            for (n = 0; n < count; n = n + 1)
                tick;
        end
    endtask

    task reset_case;
        begin
            reset = 1'b1;
            idle_bus;
            wait_cycles(3);
            reset = 1'b0;
            tick;
        end
    endtask

    task put_beat;
        input [2:0] id;
        input [4:0] op;
        input [7:0] tgt;
        input [7:0] src;
        input [GATE_WIDTH-1:0] gate;
        input [BLOCK_IMM_W-1:0] block_imm;
        begin
            quantum_valid       = 1'b1;
            quantum_op          = op;
            quantum_instr_id    = id;
            quantum_elem1       = {24'b0, tgt};
            quantum_elem2       = {24'b0, src};
            quantum_elem3       = make_elem3(gate, block_imm);
            quantum_data_ready  = 1'b1;
            quantum_first_cycle = 1'b1;
            quantum_last_cycle  = 1'b1;
            tick;
        end
    endtask

    // Like put_beat, but takes a full 32-bit elem2 payload (ROT.G/ROT.V
    // angle) instead of the 8-bit PAIR-only `src` field.
    task put_beat_payload;
        input [2:0] id;
        input [4:0] op;
        input [7:0] tgt;
        input [31:0] payload;
        input [GATE_WIDTH-1:0] gate;
        input [BLOCK_IMM_W-1:0] block_imm;
        begin
            quantum_valid       = 1'b1;
            quantum_op          = op;
            quantum_instr_id    = id;
            quantum_elem1       = {24'b0, tgt};
            quantum_elem2       = payload;
            quantum_elem3       = make_elem3(gate, block_imm);
            quantum_data_ready  = 1'b1;
            quantum_first_cycle = 1'b1;
            quantum_last_cycle  = 1'b1;
            tick;
        end
    endtask

    task check_equal;
        input integer actual;
        input integer expected;
        input [8*64-1:0] label_text;
        begin
            checks = checks + 1;
            if (actual != expected) begin
                failures = failures + 1;
                $display("[FAIL] %0s: actual=%0d expected=%0d", label_text, actual, expected);
            end else begin
                $display("[PASS] %0s: %0d", label_text, actual);
            end
        end
    endtask

    initial begin
        failures = 0;
        checks   = 0;
        reset    = 1'b1;
        t_cnt    = 0;
        idle_bus;

        // Valid synchronized burst: distinct qubits in one instruction.
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd1, 0, 7'h11, 5'd12);
        quantum_first_cycle = 1'b0;
        put_beat(3'd0, ELEM_QSINGLE, 8'd3, 0, 7'h11, 5'd12);
        idle_bus;
        wait_cycles(30);
        check_equal(fire_per_q[1], 1, "valid burst q1 fires once");
        check_equal(fire_per_q[3], 1, "valid burst q3 fires once");
        check_equal(last_fire_time[1], last_fire_time[3], "valid burst is synchronous");
        check_equal(illegal_count, 0, "valid burst has no illegal");

        // Non-pair out-of-range index: one invalid-index pulse, no write.
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd8, 0, 7'h12, 5'd10);
        idle_bus;
        wait_cycles(25);
        check_equal(invalid_index_count, 1, "single OOB invalid-index pulse");
        check_equal(invalid_pair_count, 0, "single OOB is not invalid-pair");
        check_equal(fire_count, 0, "single OOB writes no FIFO");

        // Either pair endpoint OOB: each beat rejected atomically.
        reset_case;
        put_beat(3'd0, ELEM_QPAIR, 8'd8, 8'd2, 7'h20, 5'd10);
        put_beat(3'd0, ELEM_QPAIR, 8'd1, 8'd9, 7'h20, 5'd10);
        idle_bus;
        wait_cycles(25);
        check_equal(invalid_pair_count, 2, "pair OOB pulses once per bad beat");
        check_equal(invalid_index_count, 0, "pair OOB not double-counted as invalid-index");
        check_equal(fire_count, 0, "pair OOB writes neither endpoint");

        // Repeating a qubit inside one instruction rejects the instruction.
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd2, 0, 7'h30, 5'd10);
        quantum_first_cycle = 1'b0;
        put_beat(3'd0, ELEM_QSINGLE, 8'd2, 0, 7'h30, 5'd10);
        idle_bus;
        wait_cycles(25);
        check_equal(illegal_count, 1, "duplicate qubit emits illegal");
        check_equal(fire_count, 0, "duplicate instruction is rejected");

        // A pair cannot use the same physical qubit as both endpoints.
        reset_case;
        put_beat(3'd0, ELEM_QPAIR, 8'd4, 8'd4, 7'h31, 5'd10);
        idle_bus;
        wait_cycles(25);
        check_equal(illegal_count, 1, "same-endpoint pair emits illegal");
        check_equal(invalid_pair_count, 0, "same-endpoint pair is semantic illegal");
        check_equal(fire_count, 0, "same-endpoint pair is rejected");

        // A later beat under the same instruction ID with a different op
        // class is illegal. A real, correctly-functioning upstream stream
        // can never produce this (one instruction = one funct3), but the
        // dispatcher must not silently trust that invariant instead of
        // checking it (ROT-002 follow-up, implementation-order step 2).
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd1, 0, 7'h70, 5'd10);
        quantum_first_cycle = 1'b0;
        put_beat(3'd0, ELEM_QPAIR, 8'd2, 8'd3, 7'h70, 5'd10);
        idle_bus;
        wait_cycles(25);
        check_equal(illegal_count, 1, "op-class mismatch within one instruction emits illegal");
        check_equal(fire_count, 0, "op-class mismatch rejects the whole instruction");

        // A later beat with the same op but a different GateID is also
        // illegal -- one instruction must carry exactly one GateID.
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd1, 0, 7'h71, 5'd10);
        quantum_first_cycle = 1'b0;
        put_beat(3'd0, ELEM_QSINGLE, 8'd2, 0, 7'h72, 5'd10);
        idle_bus;
        wait_cycles(25);
        check_equal(illegal_count, 1, "GateID mismatch within one instruction emits illegal");
        check_equal(fire_count, 0, "GateID mismatch rejects the whole instruction");

        // A later beat with the same op/GateID but a different block_imm is
        // also illegal -- one instruction must carry exactly one block_imm.
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd1, 0, 7'h73, 5'd10);
        quantum_first_cycle = 1'b0;
        put_beat(3'd0, ELEM_QSINGLE, 8'd2, 0, 7'h73, 5'd15);
        idle_bus;
        wait_cycles(25);
        check_equal(illegal_count, 1, "block_imm mismatch within one instruction emits illegal");
        check_equal(fire_count, 0, "block_imm mismatch rejects the whole instruction");

        // Different instructions may queue the same qubit at different times.
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd0, 0, 7'h40, 5'd20);
        put_beat(3'd1, ELEM_QSINGLE, 8'd0, 0, 7'h41, 5'd20);
        put_beat(3'd2, ELEM_QSINGLE, 8'd7, 0, 7'h42, 5'd25);
        idle_bus;
        wait_cycles(55);
        check_equal(fire_per_q[0], 2, "same qubit at different times is legal");
        check_equal(illegal_count, 0, "different timestamps have no illegal");

        // Offsets 20 then 19 on consecutive flush cycles target one timestamp.
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd0, 0, 7'h50, 5'd20);
        put_beat(3'd1, ELEM_QSINGLE, 8'd0, 0, 7'h51, 5'd19);
        put_beat(3'd2, ELEM_QSINGLE, 8'd7, 0, 7'h52, 5'd25);
        idle_bus;
        wait_cycles(55);
        check_equal(illegal_count, 1, "same qubit and timestamp emits illegal");
        check_equal(fire_per_q[0], 1, "conflicting instruction is atomically rejected");

        // Fill a small FIFO with far-future, distinct timestamps.
        //
        // time_controller drains inst_fifo's head into its own WAIT register
        // as soon as it is IDLE, independent of whether that entry's own
        // dispatch_time has arrived -- so with FIFO_DEPTH=2, inst_fifo itself
        // does not read "full" until 3 pending writes exist for one qubit
        // (1 siphoned into time_controller's WAIT register + 2 resident in
        // inst_fifo). The first 3 of the 6 attempted writes below succeed;
        // writes 4-6 land on a full FIFO. Since quantum_dispatcher now runs a
        // burst-wide capacity preflight (implementation-order step 3), those
        // attempts are intercepted *before* reaching inst_fifo's write port
        // -- the per-qubit `error`/qubit_error_o pulse inside timed_fifo
        // (fifo_full & i_fifo_we) can therefore never fire anymore; the new
        // dispatcher-level capacity_error_o is the correct signal to check.
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd0, 0, 7'h60, 5'd0);
        put_beat(3'd1, ELEM_QSINGLE, 8'd0, 0, 7'h61, 5'd0);
        put_beat(3'd2, ELEM_QSINGLE, 8'd0, 0, 7'h62, 5'd0);
        put_beat(3'd3, ELEM_QSINGLE, 8'd0, 0, 7'h63, 5'd0);
        put_beat(3'd4, ELEM_QSINGLE, 8'd0, 0, 7'h64, 5'd0);
        put_beat(3'd5, ELEM_QSINGLE, 8'd0, 0, 7'h65, 5'd0);
        put_beat(3'd6, ELEM_QSINGLE, 8'd7, 0, 7'h66, 5'd0);
        idle_bus;
        wait_cycles(15);
        checks = checks + 1;
        if (capacity_error_count < 1) begin
            failures = failures + 1;
            $display("[FAIL] FIFO overflow category was not exercised (capacity_error_count=0)");
        end else begin
            $display("[PASS] FIFO overflow now surfaces as capacity_error pulses: %0d", capacity_error_count);
        end
        check_equal(overflow_count, 0, "preflight means the per-qubit overflow pulse no longer fires");
        check_equal(invalid_index_count, 0, "overflow is not invalid-index");
        check_equal(invalid_pair_count, 0, "overflow is not invalid-pair");
        check_equal(illegal_count, 0, "overflow is not illegal");

        // Burst-wide capacity preflight (ROT-series implementation-order step 3):
        // fill qubit 5's FIFO to true capacity (3 successful writes -- see the
        // siphon-timing note above, not 2), then issue one QPAIR instruction
        // touching both qubit 5 (now full) and qubit 6 (empty, has room). The
        // whole instruction must be rejected atomically -- qubit 6 must NOT
        // get a silent partial write just because its own FIFO had room.
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd5, 0, 7'h80, 5'd0);
        put_beat(3'd1, ELEM_QSINGLE, 8'd5, 0, 7'h81, 5'd0);
        put_beat(3'd2, ELEM_QSINGLE, 8'd5, 0, 7'h82, 5'd0);
        put_beat(3'd3, ELEM_QPAIR, 8'd6, 8'd5, 7'h83, 5'd0);
        idle_bus;
        wait_cycles(150); // long enough for the three legit qubit-5 entries
                           // (FIXED_LATENCY=100) to actually fire
        checks = checks + 1;
        if (capacity_error_count < 1) begin
            failures = failures + 1;
            $display("[FAIL] capacity_error was not exercised");
        end else begin
            $display("[PASS] capacity_error pulses: %0d", capacity_error_count);
        end
        check_equal(fire_per_q[5], 3, "qubits queued before the rejected burst still fire normally");
        check_equal(fire_per_q[6], 0, "the ready-but-atomically-rejected qubit never fires");
        check_equal(illegal_count, 0, "capacity rejection is not also counted as illegal");

        // Payload round-trip (ROT-series implementation-order step 5): a
        // ROT.G angle with non-zero upper 24 bits must reach qubit_payload_o
        // bit-exact, with qubit_payload_valid_o set at fire time.
        reset_case;
        put_beat_payload(3'd0, ELEM_QROTG, 8'd2, 32'hdeadbeef, 7'h6e, 5'd10);
        idle_bus;
        wait_cycles(25);
        check_equal(fire_per_q[2], 1, "ROT.G payload test qubit fires once");
        checks = checks + 1;
        if ((last_fire_payload[2] !== 32'hdeadbeef) || (last_fire_payload_valid[2] !== 1'b1)) begin
            failures = failures + 1;
            $display("[FAIL] ROT.G payload round-trip: payload=%08x valid=%0d expected payload=deadbeef valid=1",
                     last_fire_payload[2], last_fire_payload_valid[2]);
        end else begin
            $display("[PASS] ROT.G payload round-trip: payload=%08x valid=%0d",
                     last_fire_payload[2], last_fire_payload_valid[2]);
        end

        // A SINGLE fire must leave payload_valid clear (no payload channel
        // for non-ROT classes).
        reset_case;
        put_beat(3'd0, ELEM_QSINGLE, 8'd4, 0, 7'h64, 5'd10);
        idle_bus;
        wait_cycles(25);
        check_equal(fire_per_q[4], 1, "SINGLE fire test qubit fires once");
        checks = checks + 1;
        if (last_fire_payload_valid[4] !== 1'b0) begin
            failures = failures + 1;
            $display("[FAIL] SINGLE fire leaves payload_valid clear: actual=%0d expected=0", last_fire_payload_valid[4]);
        end else begin
            $display("[PASS] SINGLE fire leaves payload_valid clear: %0d", last_fire_payload_valid[4]);
        end

        // Two rotations queued for the same qubit at different times must
        // each fire with their own angle, in order -- not overwritten or
        // swapped by the second instruction's payload_q write landing before
        // the first instruction's entry has fired.
        reset_case;
        put_beat_payload(3'd0, ELEM_QROTG, 8'd3, 32'h11111111, 7'h6e, 5'd10);
        put_beat_payload(3'd1, ELEM_QROTG, 8'd3, 32'h22222222, 7'h6e, 5'd26);
        put_beat(3'd2, ELEM_QSINGLE, 8'd7, 0, 7'h64, 5'd10);
        idle_bus;
        wait_cycles(20); // past the first (block_imm=10) fire, before the second (block_imm=26)
        checks = checks + 1;
        if ((fire_per_q[3] != 1) || (last_fire_payload[3] !== 32'h11111111)) begin
            failures = failures + 1;
            $display("[FAIL] first queued rotation fires with its own angle: fires=%0d payload=%08x expected fires=1 payload=11111111",
                     fire_per_q[3], last_fire_payload[3]);
        end else begin
            $display("[PASS] first queued rotation fires with its own angle: payload=%08x", last_fire_payload[3]);
        end
        wait_cycles(20); // now past the second fire too
        checks = checks + 1;
        if ((fire_per_q[3] != 2) || (last_fire_payload[3] !== 32'h22222222)) begin
            failures = failures + 1;
            $display("[FAIL] second queued rotation fires with its own, different angle: fires=%0d payload=%08x expected fires=2 payload=22222222",
                     fire_per_q[3], last_fire_payload[3]);
        end else begin
            $display("[PASS] second queued rotation fires with its own, different angle: payload=%08x", last_fire_payload[3]);
        end

        $display("[TB] DONE: checks=%0d failures=%0d", checks, failures);
        if (failures != 0)
            $fatal(1, "quantum_dispatcher directed regression failed");
        $finish;
    end
endmodule
