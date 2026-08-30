`timescale 1ns / 1ps
// LEGACY TRACE BENCH: observational/debug use only; not an acceptance test.
// See docs/verification.md for maintained regression scope.

module vproc_bell_tb;

  /*
   * Standalone Bell-style quantum program testbench.
   *
   * Program shape:
   *   1. QV.SINGLE      (Hadamard-style single gate on the control group)
   *   2. QV.PAIR        (Bell-style CNOT/CX stage)
   *   3. QSG.MEASURE    (measure the control group)
   *   4. QV.SINGLE      (resume marker after measure_done)
   *
   * This keeps the flow close to the original Bell-state preparation example
   * while still exercising the current top-level measure halt-resume contract.
   */

  parameter MEM_W       = 32;
  parameter MEM_SZ      = 262144;
  parameter MEM_LATENCY = 1;
  parameter VMEM_W      = 32;
  parameter MAX_CYCLES  = 200000;
  parameter EVENT_LOG_LIMIT = 128;
  parameter POST_EVENT_IDLE_CYCLES = 200;
  parameter MEASURE_DONE_DELAY_CYCLES = 50;
  parameter MEM_WORDS   = MEM_SZ / (MEM_W / 8);

  parameter [4:0] ELEM_QSINGLE = 5'd16;
  parameter [4:0] ELEM_QPAIR   = 5'd17;
  parameter [4:0] ELEM_QROTG   = 5'd18;
  parameter [4:0] ELEM_QROTV   = 5'd19;

  integer cycle_count;
  integer quantum_event_idx;
  integer last_quantum_event_cycle;
  integer resume_event_count;

  function [8*12-1:0] bell_op_name;
    input [4:0] op;
    begin
      case (op)
        ELEM_QSINGLE: bell_op_name = "QV.SINGLE   ";
        ELEM_QPAIR:   bell_op_name = "QV.PAIR     ";
        ELEM_QROTG:   bell_op_name = "QV.ROT.G    ";
        ELEM_QROTV:   bell_op_name = "QV.ROT.V    ";
        default:      bell_op_name = "UNKNOWN     ";
      endcase
    end
  endfunction

  function [8*28-1:0] bell_instr_name;
    input [31:0] instr;
    begin
      case (instr)
        32'h06600313: bell_instr_name = "addi x6, x0, 0x66          ";
        32'h05500393: bell_instr_name = "addi x7, x0, 0x55          ";
        32'h00800293: bell_instr_name = "addi x5, x0, 8             ";
        32'h0C72F057: bell_instr_name = "vsetvli x0, x5, e8, mf2    ";
        32'h00000013: bell_instr_name = "nop                        ";
        32'h00001537: bell_instr_name = "lui a0, 0x1                ";
        32'h02050087: bell_instr_name = "vle8.v v1, (a0)            ";
        32'h00850593: bell_instr_name = "addi a1, a0, 8             ";
        32'h02058107: bell_instr_name = "vle8.v v2, (a1)            ";
        32'hC8708657: bell_instr_name = "QV.SINGLE(H) vd3, v1, x7   ";
        32'hCC208657: bell_instr_name = "QV.PAIR(CNOT) vd3, v1, v2  ";
        32'hD0708657: bell_instr_name = "QSG.MEASURE vd3, v1, x7    ";
        32'hF0610657: bell_instr_name = "QV.SINGLE(resume) vd6, v2, x6";
        32'h0000006F: bell_instr_name = "jal x0, 0                  ";
        default:     bell_instr_name = "unknown                    ";
      endcase
    end
  endfunction

  task print_bell_summary;
    begin
      $display("[BELL][cycle=%0d][SUMMARY] observed %0d quantum events.", cycle_count, quantum_event_idx);
      $display("[BELL][cycle=%0d][SUMMARY] last quantum event arrived at cycle %0d.", cycle_count, last_quantum_event_cycle);
      $display("[BELL][cycle=%0d][SUMMARY] use the transcript to inspect the Bell-state flow and the measure halt-resume handshake.", cycle_count);
    end
  endtask

  reg clk;
  reg rst;

  wire        mem_req;
  wire [31:0] mem_addr;
  wire        mem_we;
  wire [3:0]  mem_be;
  wire [31:0] mem_wdata;
  reg         mem_rvalid;
  reg         mem_err;
  reg  [31:0] mem_rdata;

  wire        quantum_valid;
  wire [4:0]  quantum_op;
  wire [2:0]  quantum_instr_id;
  wire [4:0]  quantum_vd_addr;
  wire [31:0] quantum_elem1;
  wire [31:0] quantum_elem2;
  wire [31:0] quantum_elem3;
  wire [1:0]  quantum_emul;
  wire [2:0]  quantum_count_mul;
  wire        quantum_first_cycle;
  wire        quantum_last_cycle;
  wire        quantum_vl_part_0;
  wire [4:0]  quantum_res_vaddr;
  wire        quantum_data_ready;
  wire        quantum_first_valid_result;
  wire        quantum_has_valid_result;
  wire        qvsg_meas;
  wire        measure_issued_done;
  reg         measure_done;
  wire [31:0] ibex_id_instr;

  reg  [MEM_W-1:0] mem [0:MEM_WORDS-1];

  integer mem_idx;
  integer i;
  reg [1023:0] instr_mem_file;
  reg [1023:0] data_mem_file;
  reg [2:0]    prev_quantum_instr_id;
  reg          prev_quantum_instr_id_valid;
  reg          prev_qvsg_meas;
  reg          prev_measure_issued_done;
  reg          measure_wait_pending;
  reg          resume_stream_seen;
  integer      measure_wait_cycles_left;
  reg [31:0]   prev_ibex_id_instr;

  reg        mem_rvalid_queue [0:MEM_LATENCY-1];
  reg [31:0] mem_rdata_queue  [0:MEM_LATENCY-1];
  reg        mem_err_queue    [0:MEM_LATENCY-1];

  vproc_top #(
    .MEM_W         ( MEM_W ),
    .VMEM_W        ( VMEM_W ),
    .VREG_TYPE     ( 0 ),
    .MUL_TYPE      ( 0 ),
    .ICACHE_SZ     ( 0 ),
    .ICACHE_LINE_W ( 128 ),
    .DCACHE_SZ     ( 0 ),
    .DCACHE_LINE_W ( 64 )
  ) dut (
    .clk_i              ( clk ),
    .rst_ni             ( ~rst ),
    .mem_req_o          ( mem_req ),
    .mem_addr_o         ( mem_addr ),
    .mem_we_o           ( mem_we ),
    .mem_be_o           ( mem_be ),
    .mem_wdata_o        ( mem_wdata ),
    .mem_rvalid_i       ( mem_rvalid ),
    .mem_err_i          ( mem_err ),
    .mem_rdata_i        ( mem_rdata ),
    .measure_done_i     ( measure_done ),
    .qvsg_meas_o        ( qvsg_meas ),
    .measure_issued_done_o( measure_issued_done ),
    .pend_vreg_wr_map_o ( ),
    .quantum_valid_o    ( quantum_valid ),
    .quantum_op_o       ( quantum_op ),
    .quantum_instr_id_o ( quantum_instr_id ),
    .quantum_vd_addr_o  ( quantum_vd_addr ),
    .quantum_elem1_o    ( quantum_elem1 ),
    .quantum_elem2_o    ( quantum_elem2 ),
    .quantum_elem3_o    ( quantum_elem3 ),
    .quantum_emul_o     ( quantum_emul ),
    .quantum_count_mul_o( quantum_count_mul ),
    .quantum_first_cycle_o( quantum_first_cycle ),
    .quantum_last_cycle_o ( quantum_last_cycle ),
    .quantum_vl_part_0_o  ( quantum_vl_part_0 ),
    .quantum_res_vaddr_o  ( quantum_res_vaddr ),
    .quantum_data_ready_o ( quantum_data_ready ),
    .quantum_first_valid_result_o( quantum_first_valid_result ),
    .quantum_has_valid_result_o  ( quantum_has_valid_result )
  );

  assign ibex_id_instr = dut.u_core.u_ibex_core.id_stage_i.instr_rdata_i;

  initial begin
    clk = 1'b0;
    forever #5 clk = ~clk;
  end

  always @(*) begin
    mem_idx = mem_addr >> 2;
  end

  always @(posedge clk) begin
    cycle_count = cycle_count + 1;

    if (mem_req && mem_we && (mem_idx >= 0) && (mem_idx < MEM_WORDS)) begin
      for (i = 0; i < (MEM_W/8); i = i + 1) begin
        if (mem_be[i]) begin
          mem[mem_idx][(i*8) +: 8] <= mem_wdata[(i*8) +: 8];
        end
      end
    end

    if (MEM_LATENCY == 1) begin
      mem_rvalid <= mem_req;
      mem_err    <= (mem_addr >= MEM_SZ);
      mem_rdata  <= ((mem_idx >= 0) && (mem_idx < MEM_WORDS)) ? mem[mem_idx] : 32'h0;
    end else begin
      mem_rvalid_queue[0] <= mem_req;
      mem_err_queue[0]    <= (mem_addr >= MEM_SZ);
      mem_rdata_queue[0]  <= ((mem_idx >= 0) && (mem_idx < MEM_WORDS)) ? mem[mem_idx] : 32'h0;
      for (i = 1; i < MEM_LATENCY; i = i + 1) begin
        mem_rvalid_queue[i] <= mem_rvalid_queue[i-1];
        mem_rdata_queue[i]  <= mem_rdata_queue[i-1];
        mem_err_queue[i]    <= mem_err_queue[i-1];
      end
      mem_rvalid <= mem_rvalid_queue[MEM_LATENCY-1];
      mem_rdata  <= mem_rdata_queue[MEM_LATENCY-1];
      mem_err    <= mem_err_queue[MEM_LATENCY-1];
    end
  end

  always @(posedge clk) begin
    if (rst) begin
      measure_done             <= 1'b0;
      prev_qvsg_meas           <= 1'b0;
      prev_measure_issued_done <= 1'b0;
      measure_wait_pending     <= 1'b0;
      measure_wait_cycles_left <= 0;
    end else begin
      measure_done <= 1'b0;

      if (!resume_stream_seen &&
          (ibex_id_instr != prev_ibex_id_instr) &&
          (bell_instr_name(ibex_id_instr) != "unknown                    ")) begin
        $display("[BELL][cycle=%0d][INSTR] %08x (%0s)",
                 cycle_count, ibex_id_instr, bell_instr_name(ibex_id_instr));
      end

      if (qvsg_meas && !prev_qvsg_meas) begin
        $display("[BELL][cycle=%0d][MEASURE] qvsg_meas=1 start %08x (%0s)",
                 cycle_count, ibex_id_instr, bell_instr_name(ibex_id_instr));
      end
      if (!qvsg_meas && prev_qvsg_meas) begin
        $display("[BELL][cycle=%0d][MEASURE] qvsg_meas=0 resume", cycle_count);
      end
      if (measure_issued_done && !prev_measure_issued_done) begin
        $display("[BELL][cycle=%0d][MEASURE] measure_issued_done=1", cycle_count);
      end

      if (measure_issued_done && !prev_measure_issued_done) begin
        measure_wait_pending     <= 1'b1;
        measure_wait_cycles_left <= MEASURE_DONE_DELAY_CYCLES;
        $display("[BELL][cycle=%0d][WAIT] Waiting for external ADC (%0d cycles).",
                 cycle_count, MEASURE_DONE_DELAY_CYCLES);
      end else if (measure_wait_pending) begin
        if (measure_wait_cycles_left == 0) begin
          measure_done         <= 1'b1;
          measure_wait_pending <= 1'b0;
          $display("[BELL][cycle=%0d][MEASURE] measure_done=1", cycle_count);
        end else begin
          measure_wait_cycles_left <= measure_wait_cycles_left - 1;
        end
      end

      prev_qvsg_meas           <= qvsg_meas;
      prev_measure_issued_done <= measure_issued_done;
      prev_ibex_id_instr       <= ibex_id_instr;
    end
  end

  always @(posedge clk) begin
    if (!rst && quantum_valid) begin
      if (quantum_event_idx >= EVENT_LOG_LIMIT) begin
        $display("[BELL][cycle=%0d][FAIL] reached EVENT_LOG_LIMIT=%0d before the trace quiesced.",
                 cycle_count, EVENT_LOG_LIMIT);
        $finish;
      end

      if (!prev_quantum_instr_id_valid || (quantum_instr_id != prev_quantum_instr_id)) begin
        $display("[BELL][cycle=%0d][QX] stream start: op=%0d(%0s) id=%0d vd=%0d elem2=%08x elem3=%08x ready=%0b",
                 cycle_count, quantum_op, bell_op_name(quantum_op), quantum_instr_id,
                 quantum_vd_addr, quantum_elem2, quantum_elem3, quantum_data_ready);
      end

      $display("[BELL] %0d: idx=%0d op=%0d(%0s) id=%0d vd=%0d elem1=%08x elem2=%08x elem3=%08x ready=%0b",
               cycle_count, quantum_event_idx, quantum_op, bell_op_name(quantum_op),
               quantum_instr_id, quantum_vd_addr, quantum_elem1, quantum_elem2,
               quantum_elem3, quantum_data_ready);

      if (!resume_stream_seen &&
          !qvsg_meas &&
          (quantum_op == ELEM_QSINGLE) &&
          (quantum_elem2 == 32'h00000066)) begin
        resume_stream_seen <= 1'b1;
        resume_event_count <= 1;
        $display("[BELL][cycle=%0d][RESUME] observed the first post-measure resume-marker event.", cycle_count);
      end else if (resume_stream_seen) begin
        resume_event_count <= resume_event_count + 1;
        if (quantum_last_cycle || (resume_event_count >= 8)) begin
          $display("[BELL][cycle=%0d][DONE] observed a full post-measure resume-marker stream.", cycle_count);
          print_bell_summary();
          $finish;
        end
      end

      prev_quantum_instr_id       = quantum_instr_id;
      prev_quantum_instr_id_valid = 1'b1;
      last_quantum_event_cycle    = cycle_count;
      quantum_event_idx           = quantum_event_idx + 1;
    end
  end

  initial begin
    cycle_count                = 0;
    quantum_event_idx          = 0;
    last_quantum_event_cycle   = -1;
    mem_rvalid                 = 1'b0;
    mem_err                    = 1'b0;
    mem_rdata                  = 32'h0;
    prev_quantum_instr_id      = 3'b000;
    prev_quantum_instr_id_valid= 1'b0;
    measure_done               = 1'b0;
    prev_qvsg_meas             = 1'b0;
    prev_measure_issued_done   = 1'b0;
    measure_wait_pending       = 1'b0;
    measure_wait_cycles_left   = 0;
    resume_stream_seen         = 1'b0;
    resume_event_count         = 0;
    prev_ibex_id_instr         = 32'h0;

    for (i = 0; i < MEM_WORDS; i = i + 1) begin
      mem[i] = {MEM_W{1'b0}};
    end
    for (i = 0; i < MEM_LATENCY; i = i + 1) begin
      mem_rvalid_queue[i] = 1'b0;
      mem_rdata_queue[i]  = 32'h0;
      mem_err_queue[i]    = 1'b0;
    end

    if (!$value$plusargs("INSTR_MEM_FILE=%s", instr_mem_file)) instr_mem_file = "instruction_bell.mem";
    if (!$value$plusargs("DATA_MEM_FILE=%s",  data_mem_file))  data_mem_file  = "data_bell.mem";

    $display("[BELL][cycle=%0d][INIT] instruction=%s", cycle_count, instr_mem_file);
    $readmemh(instr_mem_file, mem);
    $display("[BELL][cycle=%0d][INIT] data=%s", cycle_count, data_mem_file);
    $readmemh(data_mem_file, mem);
    $display("[BELL][cycle=%0d][INIT] Bell program with measure halt-resume.", cycle_count);

    rst = 1'b1;
    repeat (10) @(posedge clk);
    rst = 1'b0;

    for (i = 0; i < MAX_CYCLES; i = i + 1) begin
      @(posedge clk);
      if ((last_quantum_event_cycle >= 0) &&
          ((cycle_count - last_quantum_event_cycle) >= POST_EVENT_IDLE_CYCLES)) begin
        $display("[BELL][cycle=%0d][DONE] no new quantum events for %0d cycles after the last event.",
                 cycle_count, POST_EVENT_IDLE_CYCLES);
        print_bell_summary();
        $finish;
      end
    end

    $display("[BELL][cycle=%0d][FAIL] timeout after %0d cycles with %0d observed events.",
             cycle_count, MAX_CYCLES, quantum_event_idx);
    print_bell_summary();
    $finish;
  end

endmodule
