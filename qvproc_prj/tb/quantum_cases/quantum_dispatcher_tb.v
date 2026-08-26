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
    wire invalid_index_error;
    wire invalid_pair_error;
    wire illegal_error;

    integer invalid_index_count;
    integer invalid_pair_count;
    integer overflow_count;
    integer illegal_count;
    integer fire_count;
    integer fire_per_q [0:NUM_QUBITS-1];
    reg [TIME_WIDTH-1:0] last_fire_time [0:NUM_QUBITS-1];
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
        .invalid_index_error_o(invalid_index_error),
        .invalid_pair_error_o(invalid_pair_error),
        .illegal_error_o(illegal_error)
    );

    always @(posedge clk) begin
        if (reset) begin
            invalid_index_count = 0;
            invalid_pair_count  = 0;
            overflow_count      = 0;
            illegal_count       = 0;
            fire_count          = 0;
            for (i = 0; i < NUM_QUBITS; i = i + 1) begin
                fire_per_q[i]   = 0;
                last_fire_time[i] = 0;
            end
        end else begin
            if (invalid_index_error) invalid_index_count = invalid_index_count + 1;
            if (invalid_pair_error)  invalid_pair_count  = invalid_pair_count + 1;
            if (|qubit_error)        overflow_count      = overflow_count + 1;
            if (illegal_error)       illegal_count       = illegal_count + 1;
            for (i = 0; i < NUM_QUBITS; i = i + 1) begin
                if (qubit_valid[i]) begin
                    fire_count        = fire_count + 1;
                    fire_per_q[i]     = fire_per_q[i] + 1;
                    last_fire_time[i] = t_cnt;
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
        if (overflow_count < 1) begin
            failures = failures + 1;
            $display("[FAIL] FIFO overflow category was not exercised");
        end else begin
            $display("[PASS] FIFO overflow pulses: %0d", overflow_count);
        end
        check_equal(invalid_index_count, 0, "overflow is not invalid-index");
        check_equal(invalid_pair_count, 0, "overflow is not invalid-pair");
        check_equal(illegal_count, 0, "overflow is not illegal");

        $display("[TB] DONE: checks=%0d failures=%0d", checks, failures);
        if (failures != 0)
            $fatal(1, "quantum_dispatcher directed regression failed");
        $finish;
    end
endmodule
