`timescale 1ns / 1ps
// LEGACY TRACE BENCH: observational/debug use only; not an acceptance test.
// See docs/verification.md for maintained regression scope.

module vproc_qpr_tb;

  /*
   * Standalone QPR testbench for QV.PAIR.
   * This testbench now mirrors the exploratory QSG flow: it logs the live
   * quantum event stream, annotates each new instruction stream with the
   * inferred program-level LMUL block, and stops once the stream has been
   * idle for a fixed number of cycles.
   *
   * The older version used a strict 5-event packed-word check. That older
   * approach is intentionally not used here because QPR now needs the same
   * slice-level characterization flow as QSG, including `ready` and `phase`
   * observations for the exported quantum ports. // quantum qvproc
   */

  parameter MEM_W       = 32;
  parameter MEM_SZ      = 262144;
  parameter MEM_LATENCY = 1;
  parameter VMEM_W      = 32;
  parameter MAX_CYCLES  = 200000;
  parameter EVENT_LOG_LIMIT = 256;
  parameter POST_EVENT_IDLE_CYCLES = 200;
  parameter MEM_WORDS   = MEM_SZ / (MEM_W / 8);

  parameter [31:0] INSN_VSETIVLI_E8_MF2_AVL4 = 32'hCC727057;
  parameter [31:0] INSN_VSETIVLI_E8_M1_AVL4  = 32'hCC027057;
  parameter [31:0] INSN_VSETIVLI_E8_M2_AVL4  = 32'hCC127057;
  parameter [31:0] INSN_VSETIVLI_E8_M4_AVL4  = 32'hCC227057;
  parameter [31:0] INSN_VSETIVLI_E8_M8_AVL4  = 32'hCC327057;
  parameter [31:0] INSN_LUI_A0_0X1           = 32'h00001537;
  parameter [31:0] INSN_JAL_X0_0             = 32'h0000006F;
  parameter [4:0]  ELEM_QPAIR                = 5'd17;

  integer cycle_count;
  integer stream_order_idx;
  integer quantum_event_idx;
  integer last_quantum_event_cycle;

  function [8*24-1:0] qpr_instr_name;
    input [31:0] instr;
    begin
      case (instr)
        32'h0C72F057: qpr_instr_name = "vsetvli e8,mf2         ";
        32'h0C02F057: qpr_instr_name = "vsetvli e8,m1          ";
        32'h0C12F057: qpr_instr_name = "vsetvli e8,m2          ";
        32'h0C22F057: qpr_instr_name = "vsetvli e8,m4          ";
        32'h0C32F057: qpr_instr_name = "vsetvli e8,m8          ";
        32'h00000013: qpr_instr_name = "nop                    ";
        32'h00001537: qpr_instr_name = "lui a0,0x1             ";
        32'h10050513: qpr_instr_name = "addi a0,a0,0x100       ";
        32'h20050513: qpr_instr_name = "addi a0,a0,0x200       ";
        32'h30050513: qpr_instr_name = "addi a0,a0,0x300       ";
        32'h40050513: qpr_instr_name = "addi a0,a0,0x400       ";
        32'h02050087: qpr_instr_name = "vle8.v v1,(a0)         ";
        32'h02050207: qpr_instr_name = "vle8.v v4,(a0)         ";
        32'h02050407: qpr_instr_name = "vle8.v v8,(a0)         ";
        32'h02058087: qpr_instr_name = "vle8.v v1,(a1)         ";
        32'h02058207: qpr_instr_name = "vle8.v v4,(a1)         ";
        32'h02058407: qpr_instr_name = "vle8.v v8,(a1)         ";
        32'hFA50C1D7: qpr_instr_name = "QV.PAIR vd3            ";
        32'hFA524357: qpr_instr_name = "QV.PAIR vd6            ";
        32'hFA544657: qpr_instr_name = "QV.PAIR vd12,vs1=v8    ";
        32'hFA524657: qpr_instr_name = "QV.PAIR vd12,vs1=v4    ";
        32'hFA548857: qpr_instr_name = "QV.PAIR vd16,vs1=v8    ";
        32'h0000006F: qpr_instr_name = "jal x0,0               ";
        default:     qpr_instr_name = "unknown                ";
      endcase
    end
  endfunction

  function [8*8-1:0] qpr_vsew_name;
    input [1:0] vsew;
    begin
      case (vsew)
        2'd0:    qpr_vsew_name = "e8      ";
        2'd1:    qpr_vsew_name = "e16     ";
        2'd2:    qpr_vsew_name = "e32     ";
        default: qpr_vsew_name = "invalid ";
      endcase
    end
  endfunction

  function [8*8-1:0] qpr_lmul_name;
    input [2:0] lmul;
    begin
      case (lmul)
        3'd0:    qpr_lmul_name = "m1      ";
        3'd1:    qpr_lmul_name = "m2      ";
        3'd2:    qpr_lmul_name = "m4      ";
        3'd3:    qpr_lmul_name = "m8      ";
        3'd5:    qpr_lmul_name = "mf8     ";
        3'd6:    qpr_lmul_name = "mf4     ";
        3'd7:    qpr_lmul_name = "mf2     ";
        default: qpr_lmul_name = "invalid ";
      endcase
    end
  endfunction

  task print_qpr_stream_context;
    input [2:0] stream_id;
    begin
      case (stream_order_idx)
        0: $display("[QPR][cycle=%0d][STREAM] instr_id=%0d inferred_program_cfg={sew=e8 lmul=mf2 vl=8} active_global_cfg={sew=%0s lmul=%0s vl=%0d vl_0=%0b}", cycle_count, stream_id, qpr_vsew_name(dut.v_core.vsew_q), qpr_lmul_name(dut.v_core.lmul_q), dut.v_core.vl_q + 1, dut.v_core.vl_0_q); // quantum qvproc
        1: $display("[QPR][cycle=%0d][STREAM] instr_id=%0d inferred_program_cfg={sew=e8 lmul=m1 vl=16} active_global_cfg={sew=%0s lmul=%0s vl=%0d vl_0=%0b}", cycle_count, stream_id, qpr_vsew_name(dut.v_core.vsew_q), qpr_lmul_name(dut.v_core.lmul_q), dut.v_core.vl_q + 1, dut.v_core.vl_0_q); // quantum qvproc
        2: $display("[QPR][cycle=%0d][STREAM] instr_id=%0d inferred_program_cfg={sew=e8 lmul=m2 vl=32} active_global_cfg={sew=%0s lmul=%0s vl=%0d vl_0=%0b}", cycle_count, stream_id, qpr_vsew_name(dut.v_core.vsew_q), qpr_lmul_name(dut.v_core.lmul_q), dut.v_core.vl_q + 1, dut.v_core.vl_0_q); // quantum qvproc
        3: $display("[QPR][cycle=%0d][STREAM] instr_id=%0d inferred_program_cfg={sew=e8 lmul=m4 vl=64} active_global_cfg={sew=%0s lmul=%0s vl=%0d vl_0=%0b}", cycle_count, stream_id, qpr_vsew_name(dut.v_core.vsew_q), qpr_lmul_name(dut.v_core.lmul_q), dut.v_core.vl_q + 1, dut.v_core.vl_0_q); // quantum qvproc
        4: $display("[QPR][cycle=%0d][STREAM] instr_id=%0d inferred_program_cfg={sew=e8 lmul=m8 vl=128} active_global_cfg={sew=%0s lmul=%0s vl=%0d vl_0=%0b}", cycle_count, stream_id, qpr_vsew_name(dut.v_core.vsew_q), qpr_lmul_name(dut.v_core.lmul_q), dut.v_core.vl_q + 1, dut.v_core.vl_0_q); // quantum qvproc
        default: $display("[QPR][cycle=%0d][STREAM] instr_id=%0d inferred_program_cfg={unknown} active_global_cfg={sew=%0s lmul=%0s vl=%0d vl_0=%0b}", cycle_count, stream_id, qpr_vsew_name(dut.v_core.vsew_q), qpr_lmul_name(dut.v_core.lmul_q), dut.v_core.vl_q + 1, dut.v_core.vl_0_q); // quantum qvproc
      endcase
    end
  endtask

  task print_qpr_summary;
    begin
      $display("[QPR][cycle=%0d][SUMMARY] observed %0d quantum events.", cycle_count, quantum_event_idx); // quantum qvproc
      $display("[QPR][cycle=%0d][SUMMARY] last quantum event arrived at cycle %0d.", cycle_count, last_quantum_event_cycle); // quantum qvproc
      $display("[QPR][cycle=%0d][SUMMARY] use the transcript to derive the real per-instruction micro-step protocol.", cycle_count); // quantum qvproc
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

  reg  [MEM_W-1:0] mem [0:MEM_WORDS-1];

  integer mem_idx;
  integer i;
  reg [1023:0] instr_mem_file;
  reg [1023:0] data_mem_file;
  reg [2:0]    prev_quantum_instr_id;
  reg          prev_quantum_instr_id_valid;

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
    .measure_done_i     ( 1'b0 ),
    .qvsg_meas_o        ( ),
    .measure_issued_done_o( ),
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
    if (!rst && quantum_valid) begin
      if (quantum_event_idx >= EVENT_LOG_LIMIT) begin
        $display("[QPR][cycle=%0d][FAIL] reached EVENT_LOG_LIMIT=%0d before the trace quiesced.", cycle_count, EVENT_LOG_LIMIT); // quantum qvproc
        $finish;
      end
      if (!prev_quantum_instr_id_valid || (quantum_instr_id != prev_quantum_instr_id)) begin
        print_qpr_stream_context(quantum_instr_id);
        stream_order_idx = stream_order_idx + 1;
      end
      $display("[QPR] %0d: idx=%0d op=%0d id=%0d vd=%0d elem1=%08x elem2=%08x elem3=%08x ready=%0b phase={emul=%0d count_mul=%0d first=%0b last=%0b vl_part_0=%0b first_valid=%0b has_valid=%0b}",
               cycle_count, quantum_event_idx, quantum_op, quantum_instr_id, quantum_vd_addr,
               quantum_elem1, quantum_elem2, quantum_elem3, quantum_data_ready,
               quantum_emul, quantum_count_mul, quantum_first_cycle, quantum_last_cycle, quantum_vl_part_0,
               quantum_first_valid_result, quantum_has_valid_result); // quantum qvproc

      if (quantum_op !== ELEM_QPAIR) begin
        $display("[QPR][cycle=%0d][FAIL] expected QV.PAIR op=%0d got=%0d at idx=%0d.",
                 cycle_count, ELEM_QPAIR, quantum_op, quantum_event_idx); // quantum qvproc
        $finish;
      end

      prev_quantum_instr_id       = quantum_instr_id;
      prev_quantum_instr_id_valid = 1'b1;
      last_quantum_event_cycle    = cycle_count;
      quantum_event_idx           = quantum_event_idx + 1;
    end
  end

  initial begin
    cycle_count                 = 0;
    quantum_event_idx           = 0;
    last_quantum_event_cycle    = -1;
    mem_rvalid                  = 1'b0;
    mem_err                     = 1'b0;
    mem_rdata                   = 32'h0;
    prev_quantum_instr_id       = 3'b000;
    prev_quantum_instr_id_valid = 1'b0;
    stream_order_idx            = 0;

    for (i = 0; i < MEM_WORDS; i = i + 1) begin
      mem[i] = {MEM_W{1'b0}};
    end
    for (i = 0; i < MEM_LATENCY; i = i + 1) begin
      mem_rvalid_queue[i] = 1'b0;
      mem_rdata_queue[i]  = 32'h0;
      mem_err_queue[i]    = 1'b0;
    end

    if (!$value$plusargs("INSTR_MEM_FILE=%s", instr_mem_file)) instr_mem_file = "instruction_qpr.mem";
    if (!$value$plusargs("DATA_MEM_FILE=%s",  data_mem_file))  data_mem_file  = "data_qpr.mem";

    $display("[QPR][cycle=%0d][INIT] loading instruction mem from %s", cycle_count, instr_mem_file); // quantum qvproc
    $readmemh(instr_mem_file, mem);
    $display("[QPR][cycle=%0d][INIT] overlaying data mem from %s", cycle_count, data_mem_file); // quantum qvproc
    $readmemh(data_mem_file, mem);
    $display("[QPR][cycle=%0d][INIT] exploratory trace mode is enabled.", cycle_count); // quantum qvproc
    $display("[QPR][cycle=%0d][INIT] QPR now follows the same slice-level trace flow as QSG.", cycle_count); // quantum qvproc
    $display("[QPR][cycle=%0d][INIT] element1/element2 remain slice data, while element3 carries instr[14:7] at bits[14:7].", cycle_count); // quantum qvproc

    rst = 1'b1;
    repeat (10) @(posedge clk);
    rst = 1'b0;

    for (i = 0; i < MAX_CYCLES; i = i + 1) begin
      @(posedge clk);
      if ((last_quantum_event_cycle >= 0) &&
          ((cycle_count - last_quantum_event_cycle) >= POST_EVENT_IDLE_CYCLES)) begin
        $display("[QPR][cycle=%0d][DONE] no new quantum events for %0d cycles after the last event.", cycle_count, POST_EVENT_IDLE_CYCLES); // quantum qvproc
        print_qpr_summary(); // quantum qvproc
        $finish;
      end
    end
    $display("[QPR][cycle=%0d][FAIL] timeout after %0d cycles with %0d observed events.", cycle_count, MAX_CYCLES, quantum_event_idx); // quantum qvproc
    print_qpr_summary(); // quantum qvproc
    $finish;
  end

endmodule
