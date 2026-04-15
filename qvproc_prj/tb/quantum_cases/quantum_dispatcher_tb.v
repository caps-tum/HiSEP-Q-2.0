`timescale 1ns / 1ps
//
// quantum_dispatcher_tb.v
//
// Verifies three core properties of quantum_dispatcher (TIMED mode):
//
//  Case 1 – QV.SINGLE, block_imm=0, qubits [2,5]
//    All qubits in the same instruction must fire at the SAME t_cnt
//    (= base_time + FIXED_LATENCY), even though they arrive in
//    consecutive cycles from the vector core.
//
//  Case 2 – QV.SINGLE, block_imm=6, qubits [0,3]
//    All qubits fire at base_time + block_imm.
//
//  Case 3 – QV.PAIR, block_imm=0, tgt=qubit1, src=qubit4
//    Both the target and the source qubit fire at the same t_cnt.
//
// Checking strategy:
//   All pass/fail checks run inside the initial block.  After
//   @(posedge clk) resumes, all NBA updates and combinational
//   delta cycles for that timestep have settled, so qubit_valid_o
//   and qubit_gate_o are stable and correct to sample.

module quantum_dispatcher_tb;

    // --------------------------------------------------------------------- //
    // Parameters – must match DUT instantiation below
    // --------------------------------------------------------------------- //
    parameter NUM_QUBITS    = 8;
    parameter FIFO_DEPTH    = 4;
    parameter TIME_WIDTH    = 12;
    parameter GATE_WIDTH    = 7;
    parameter BLOCK_IMM_W   = 4;
    parameter FIXED_LATENCY = 8;    // must be > max_vl + 1; max_vl=2 here

    parameter ELEM_QSINGLE  = 5'd16;
    parameter ELEM_QPAIR    = 5'd17;

    // --------------------------------------------------------------------- //
    // DUT signals
    // --------------------------------------------------------------------- //
    reg                          clk;
    reg                          reset;
    reg  [TIME_WIDTH-1:0]        t_cnt;

    reg                          quantum_valid;
    reg  [4:0]                   quantum_op;
    reg  [31:0]                  quantum_elem1;
    reg  [31:0]                  quantum_elem2;
    reg  [31:0]                  quantum_elem3;
    reg                          quantum_data_ready;
    reg                          quantum_first_cycle;
    reg                          quantum_last_cycle;

    wire [GATE_WIDTH*NUM_QUBITS-1:0] qubit_gate_o;
    wire [NUM_QUBITS-1:0]            qubit_valid_o;
    wire [NUM_QUBITS-1:0]            qubit_error_o;

    // --------------------------------------------------------------------- //
    // Clock
    // --------------------------------------------------------------------- //
    initial clk = 0;
    always  #5 clk = ~clk;

    // --------------------------------------------------------------------- //
    // DUT
    // --------------------------------------------------------------------- //
    quantum_dispatcher #(
        .NUM_QUBITS    (NUM_QUBITS),
        .FIFO_DEPTH    (FIFO_DEPTH),
        .TIME_WIDTH    (TIME_WIDTH),
        .GATE_WIDTH    (GATE_WIDTH),
        .BLOCK_IMM_W   (BLOCK_IMM_W),
        .FIXED_LATENCY (FIXED_LATENCY)
    ) dut (
        .clk                (clk),
        .reset              (reset),
        .t_cnt              (t_cnt),
        .quantum_valid      (quantum_valid),
        .quantum_op         (quantum_op),
        .quantum_elem1      (quantum_elem1),
        .quantum_elem2      (quantum_elem2),
        .quantum_elem3      (quantum_elem3),
        .quantum_data_ready (quantum_data_ready),
        .quantum_first_cycle(quantum_first_cycle),
        .quantum_last_cycle (quantum_last_cycle),
        .qubit_gate_o       (qubit_gate_o),
        .qubit_valid_o      (qubit_valid_o),
        .qubit_error_o      (qubit_error_o)
    );

    // --------------------------------------------------------------------- //
    // Free-running t_cnt
    // --------------------------------------------------------------------- //
    always @(posedge clk) begin
        if (reset) t_cnt <= {TIME_WIDTH{1'b0}};
        else       t_cnt <= t_cnt + 1'b1;
    end

    // --------------------------------------------------------------------- //
    // Monitor: fires whenever any qubit output is active or an error occurs.
    // This always block is informational only; pass/fail is in the initial block.
    // --------------------------------------------------------------------- //
    integer qi_mon;
    always @(posedge clk) begin
        if (|qubit_valid_o) begin
            for (qi_mon = 0; qi_mon < NUM_QUBITS; qi_mon = qi_mon + 1) begin
                if (qubit_valid_o[qi_mon])
                    $display("[QDISP][t=%0d] qubit %0d fires  gate=0x%02x",
                             t_cnt, qi_mon,
                             qubit_gate_o[(qi_mon+1)*GATE_WIDTH-1 -: GATE_WIDTH]);
            end
        end
        if (|qubit_error_o)
            $display("[QDISP][t=%0d][ERROR] FIFO overflow mask=%b",
                     t_cnt, qubit_error_o);
    end

    // --------------------------------------------------------------------- //
    // Helper: build elem3  [31:25]=GateID  [10:7]=block_imm
    // --------------------------------------------------------------------- //
    function [31:0] make_elem3;
        input [6:0] gate;
        input [3:0] blk;
        begin
            make_elem3 = {gate, 14'b0, blk, 7'b0};
        end
    endfunction

    // --------------------------------------------------------------------- //
    // Helper tasks
    // --------------------------------------------------------------------- //
    task drive_beat;
        input [4:0] op;
        input [7:0] tgt;
        input [7:0] src;
        input [6:0] gate;
        input [3:0] blk;
        input       is_first;
        input       is_last;
        begin
            quantum_valid       = 1'b1;
            quantum_op          = op;
            quantum_elem1       = {24'b0, tgt};
            quantum_elem2       = {24'b0, src};
            quantum_elem3       = make_elem3(gate, blk);
            quantum_data_ready  = 1'b1;
            quantum_first_cycle = is_first;
            quantum_last_cycle  = is_last;
        end
    endtask

    task idle_quantum;
        begin
            quantum_valid       = 1'b0;
            quantum_op          = 5'b0;
            quantum_elem1       = 32'b0;
            quantum_elem2       = 32'b0;
            quantum_elem3       = 32'b0;
            quantum_data_ready  = 1'b0;
            quantum_first_cycle = 1'b0;
            quantum_last_cycle  = 1'b0;
        end
    endtask

    // Wait until t_cnt reaches 'target' (checked post-NBA after posedge)
    task wait_until;
        input [TIME_WIDTH-1:0] target;
        begin
            while (t_cnt < target) @(posedge clk);
            // t_cnt == target, all NBA + combinational delta cycles done
        end
    endtask

    // Inline pass/fail check.
    // Call AFTER wait_until(dispatch_time) so outputs have settled.
    // 'label'  : string printed with result
    // 'exp_mask': expected qubit_valid_o bitmask
    // 'exp_gate': expected gate word for every asserted bit
    integer qi_chk;
    integer fail_count;
    integer pass_count;
    task check_outputs;
        input [NUM_QUBITS-1:0] exp_mask;
        input [GATE_WIDTH-1:0] exp_gate;
        input [8*32-1:0]       label;
        begin
            if (qubit_valid_o !== exp_mask) begin
                $display("[FAIL][t=%0d] %0s  valid_o=%b  expected=%b",
                         t_cnt, label, qubit_valid_o, exp_mask);
                fail_count = fail_count + 1;
            end else begin
                for (qi_chk = 0; qi_chk < NUM_QUBITS; qi_chk = qi_chk + 1) begin
                    if (exp_mask[qi_chk]) begin
                        if (qubit_gate_o[(qi_chk+1)*GATE_WIDTH-1 -: GATE_WIDTH] !== exp_gate) begin
                            $display("[FAIL][t=%0d] %0s  qubit %0d gate=0x%02x expected=0x%02x",
                                     t_cnt, label, qi_chk,
                                     qubit_gate_o[(qi_chk+1)*GATE_WIDTH-1 -: GATE_WIDTH],
                                     exp_gate);
                            fail_count = fail_count + 1;
                        end else begin
                            $display("[PASS][t=%0d] %0s  qubit %0d gate=0x%02x OK",
                                     t_cnt, label, qi_chk, exp_gate);
                            pass_count = pass_count + 1;
                        end
                    end
                end
            end
        end
    endtask

    // --------------------------------------------------------------------- //
    // Stimulus and checking
    // --------------------------------------------------------------------- //
    reg [TIME_WIDTH-1:0] base;

    initial begin
        fail_count          = 0;
        pass_count          = 0;
        reset               = 1'b1;
        idle_quantum;

        repeat (5) @(posedge clk);
        #1; reset = 1'b0;

        // ================================================================= //
        // Case 1 – QV.SINGLE, block_imm=0, qubits [2,5], gate=0x10
        //   dispatch_time = base + FIXED_LATENCY
        //   Both qubits must fire on the same t_cnt cycle
        // ================================================================= //
        wait_until(10); #1;
        base = t_cnt;
        $display("[TB] --- Case 1: QV.SINGLE qubits=[2,5] gate=0x10 block_imm=0 ---");
        $display("[TB]   base=%0d  dispatch_time=%0d", base, base+FIXED_LATENCY);

        drive_beat(ELEM_QSINGLE, 8'd2, 8'd0, 7'h10, 4'h0, 1'b1, 1'b0);
        @(posedge clk); #1;
        drive_beat(ELEM_QSINGLE, 8'd5, 8'd0, 7'h10, 4'h0, 1'b0, 1'b1);
        @(posedge clk); #1;
        idle_quantum;

        // Wait for the exact fire cycle and check
        wait_until(base + FIXED_LATENCY);
        check_outputs(8'b00100100, 7'h10, "Case1");

        // Verify nothing fires on the surrounding cycles
        @(posedge clk);
        if (|qubit_valid_o)
            $display("[FAIL][t=%0d] Case1: unexpected fire after dispatch_time", t_cnt);

        // ================================================================= //
        // Case 2 – QV.SINGLE, block_imm=6, qubits [0,3], gate=0x20
        //   dispatch_time = base + 6
        // ================================================================= //
        wait_until(30); #1;
        base = t_cnt;
        $display("[TB] --- Case 2: QV.SINGLE qubits=[0,3] gate=0x20 block_imm=6 ---");
        $display("[TB]   base=%0d  dispatch_time=%0d", base, base+6);

        drive_beat(ELEM_QSINGLE, 8'd0, 8'd0, 7'h20, 4'h6, 1'b1, 1'b0);
        @(posedge clk); #1;
        drive_beat(ELEM_QSINGLE, 8'd3, 8'd0, 7'h20, 4'h6, 1'b0, 1'b1);
        @(posedge clk); #1;
        idle_quantum;

        wait_until(base + 6);
        check_outputs(8'b00001001, 7'h20, "Case2");

        @(posedge clk);
        if (|qubit_valid_o)
            $display("[FAIL][t=%0d] Case2: unexpected fire after dispatch_time", t_cnt);

        // ================================================================= //
        // Case 3 – QV.PAIR, block_imm=0, tgt=qubit1, src=qubit4, gate=0x30
        //   Single-beat instruction; BOTH tgt and src must fire together
        //   dispatch_time = base + FIXED_LATENCY
        // ================================================================= //
        wait_until(50); #1;
        base = t_cnt;
        $display("[TB] --- Case 3: QV.PAIR tgt=1 src=4 gate=0x30 block_imm=0 ---");
        $display("[TB]   base=%0d  dispatch_time=%0d", base, base+FIXED_LATENCY);

        drive_beat(ELEM_QPAIR, 8'd1, 8'd4, 7'h30, 4'h0, 1'b1, 1'b1);
        @(posedge clk); #1;
        idle_quantum;

        wait_until(base + FIXED_LATENCY);
        check_outputs(8'b00010010, 7'h30, "Case3");

        @(posedge clk);
        if (|qubit_valid_o)
            $display("[FAIL][t=%0d] Case3: unexpected fire after dispatch_time", t_cnt);

        // ================================================================= //
        // Summary
        // ================================================================= //
        repeat (5) @(posedge clk);
        $display("[TB] --- DONE: %0d passed, %0d failed ---", pass_count, fail_count);
        $finish;
    end

endmodule
