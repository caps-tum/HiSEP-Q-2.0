`timescale 1ns / 1ps

module vproc_qrv_mf2_direct_tb;

  parameter MEM_W       = 32;
  parameter MEM_SZ      = 262144;
  parameter MEM_LATENCY = 1;
  parameter VMEM_W      = 32;
  parameter MAX_CYCLES  = 20000;
  parameter MEM_WORDS   = MEM_SZ / (MEM_W / 8);
  parameter [4:0] ELEM_QROTV = 5'd19;

  parameter [31:0] INSN_ADDI_T0_16        = 32'h01000293;
  parameter [31:0] INSN_VSETVLI_E8_M1     = 32'h0C02F057;
  parameter [31:0] INSN_NOP               = 32'h00000013;
  parameter [31:0] INSN_QRV_VD12          = 32'hFE823657;
  parameter [31:0] INSN_JAL_X0_0          = 32'h0000006F;

  reg clk;
  reg rst;

  integer cycle_count;
  integer quantum_event_idx;
  integer quantum_warmup_skip;
  integer i;
  integer mem_idx;

  reg  [MEM_W-1:0] mem [0:MEM_WORDS-1];
  reg              mem_rvalid;
  reg              mem_err;
  reg  [31:0]      mem_rdata;
  reg              mem_rvalid_queue [0:MEM_LATENCY-1];
  reg  [31:0]      mem_rdata_queue  [0:MEM_LATENCY-1];
  reg              mem_err_queue    [0:MEM_LATENCY-1];

  wire        mem_req;
  wire [31:0] mem_addr;
  wire        mem_we;
  wire [3:0]  mem_be;
  wire [31:0] mem_wdata;

  wire        quantum_valid;
  wire [4:0]  quantum_op;
  wire [2:0]  quantum_instr_id;
  wire [4:0]  quantum_vd_addr;
  wire [31:0] quantum_elem1;
  wire [31:0] quantum_elem2;
  wire [31:0] quantum_elem3;
  wire [1:0]  quantum_emul;
  wire [2:0]  quantum_qrotv_op2_chunk;
  wire        quantum_data_ready;

  wire [4:0]  dbg_pipe_op_vaddr_1;
  wire        dbg_pipe_op_load_next_1;
  wire        dbg_pipe_op_load_1;
  wire [4:0]  dbg_unpack_pipe_in_op_vaddr_1;
  wire        dbg_unpack_pipe_in_op_load_1;
  wire [4:0]  dbg_vreg_rd_addr_0;
  wire        dbg_unpack_op_addressing_0;
  wire        dbg_unpack_op_addressing_1;
  wire [4:0]  dbg_unpack_op_vreg_addr_0;
  wire [4:0]  dbg_unpack_op_vreg_addr_1;
  wire        dbg_pipe_qrotv_startup;
  wire        dbg_unpack_out_qrotv_startup;
  wire        dbg_unit_in_valid;

  assign dbg_pipe_op_vaddr_1           = dut.v_core.genblk9[0].pipe.genblk2.pipeline.op_vaddr[1];
  assign dbg_pipe_op_load_next_1       = dut.v_core.genblk9[0].pipe.genblk2.pipeline.op_load_next[1];
  assign dbg_pipe_op_load_1            = dut.v_core.genblk9[0].pipe.genblk2.pipeline.op_load[1];
  assign dbg_unpack_pipe_in_op_vaddr_1 = dut.v_core.genblk9[0].pipe.genblk2.pipeline.unpack.pipe_in_op_vaddr_i[1];
  assign dbg_unpack_pipe_in_op_load_1  = dut.v_core.genblk9[0].pipe.genblk2.pipeline.unpack.pipe_in_op_load_i[1];
  assign dbg_vreg_rd_addr_0            = dut.v_core.genblk9[0].pipe.genblk2.pipeline.vreg_rd_addr_o[0];
  assign dbg_unpack_op_addressing_0    = dut.v_core.genblk9[0].pipe.genblk2.pipeline.unpack.op_addressing[0];
  assign dbg_unpack_op_addressing_1    = dut.v_core.genblk9[0].pipe.genblk2.pipeline.unpack.op_addressing[1];
  assign dbg_unpack_op_vreg_addr_0     = dut.v_core.genblk9[0].pipe.genblk2.pipeline.unpack.op_vreg_addr[0];
  assign dbg_unpack_op_vreg_addr_1     = dut.v_core.genblk9[0].pipe.genblk2.pipeline.unpack.op_vreg_addr[1];
  assign dbg_pipe_qrotv_startup        = dut.v_core.genblk9[0].pipe.genblk2.pipeline.state_q.qrotv_startup;
  assign dbg_unpack_out_qrotv_startup  = dut.v_core.genblk9[0].pipe.genblk2.pipeline.unpack_out_ctrl.qrotv_startup;
  assign dbg_unit_in_valid             = dut.v_core.genblk9[0].pipe.genblk2.pipeline.unit_in_valid;

  vproc_top #(
    .MEM_W         ( MEM_W ),
    .VMEM_W        ( VMEM_W ),
    .VREG_TYPE     ( 2 ),
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
    .quantum_count_mul_o( ),
    .quantum_first_cycle_o( ),
    .quantum_last_cycle_o ( ),
    .quantum_vl_part_0_o  ( ),
    .quantum_res_vaddr_o  ( ),
    .quantum_first_valid_result_o( ),
    .quantum_has_valid_result_o  ( ),
    .quantum_qrotv_op2_chunk_o   ( quantum_qrotv_op2_chunk ),
    .quantum_data_ready_o        ( quantum_data_ready )
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
      $display("[QRV-MIN] %0d: idx=%0d op=%0d id=%0d vd=%0d elem1=%08x elem2=%08x elem3=%08x ready=%0b emul=%0d chunk=%0d startup=%0b unpack_startup=%0b unit_in=%0b | op_vaddr1=%0d op_load_next1=%0b op_load1=%0b unpack_vaddr1=%0d unpack_load1=%0b vreg_rd_addr0=%0d | addr0=%0b/%0d addr1=%0b/%0d",
               cycle_count, quantum_event_idx, quantum_op, quantum_instr_id, quantum_vd_addr,
               quantum_elem1, quantum_elem2, quantum_elem3, quantum_data_ready,
               quantum_emul, quantum_qrotv_op2_chunk, dbg_pipe_qrotv_startup,
               dbg_unpack_out_qrotv_startup, dbg_unit_in_valid,
               dbg_pipe_op_vaddr_1, dbg_pipe_op_load_next_1, dbg_pipe_op_load_1,
               dbg_unpack_pipe_in_op_vaddr_1, dbg_unpack_pipe_in_op_load_1, dbg_vreg_rd_addr_0,
               dbg_unpack_op_addressing_0, dbg_unpack_op_vreg_addr_0,
               dbg_unpack_op_addressing_1, dbg_unpack_op_vreg_addr_1);
      if (quantum_op !== ELEM_QROTV) begin
        $display("[QRV-MIN][FAIL] unexpected quantum op=%0d", quantum_op);
        $finish;
      end
      if (quantum_warmup_skip < 4) begin
        quantum_warmup_skip = quantum_warmup_skip + 1;
      end else begin
        quantum_event_idx = quantum_event_idx + 1;
        if (quantum_event_idx >= 16) begin
          $display("[QRV-MIN][DONE] captured 16 post-warmup QRV events.");
          $finish;
        end
      end
    end
  end

  initial begin
    cycle_count       = 0;
    quantum_event_idx = 0;
    quantum_warmup_skip = 0;
    mem_rvalid        = 1'b0;
    mem_err           = 1'b0;
    mem_rdata         = 32'h0;

    for (i = 0; i < MEM_WORDS; i = i + 1) begin
      mem[i] = {MEM_W{1'b0}};
    end
    for (i = 0; i < MEM_LATENCY; i = i + 1) begin
      mem_rvalid_queue[i] = 1'b0;
      mem_rdata_queue[i]  = 32'h0;
      mem_err_queue[i]    = 1'b0;
    end

    mem[0] = INSN_ADDI_T0_16;
    mem[1] = INSN_VSETVLI_E8_M1;
    mem[2] = INSN_NOP;
    mem[3] = INSN_QRV_VD12;
    mem[4] = INSN_JAL_X0_0;

    $display("[QRV-MIN][INIT] seeded direct QRV m1 program into mem[0:4].");
    $display("[QRV-MIN][INIT] v4 will hold e8 indices 0x31..0x40.");
    $display("[QRV-MIN][INIT] v8..v11 will hold sixteen e32 angles.");

    rst = 1'b1;
    repeat (4) @(posedge clk);

    dut.v_core.vregfile.ram_asic[5'd4 ] = 128'h403f3e3d3c3b3a393837363534333231;
    dut.v_core.vregfile.ram_asic[5'd8 ] = 128'h44444444333333332222222211111111;
    dut.v_core.vregfile.ram_asic[5'd9 ] = 128'h88888888777777776666666655555555;
    dut.v_core.vregfile.ram_asic[5'd10] = 128'hccccccccbbbbbbbbaaaaaaaa99999999;
    dut.v_core.vregfile.ram_asic[5'd11] = 128'h10101010ffffffffeeeeeeeedddddddd;

    $display("[QRV-MIN][INIT] seeded dut.v_core.vregfile.ram_asic[v4,v8..v11].");

    repeat (6) @(posedge clk);
    rst = 1'b0;

    for (i = 0; i < MAX_CYCLES; i = i + 1) begin
      @(posedge clk);
    end

    $display("[QRV-MIN][FAIL] timeout after %0d cycles.", MAX_CYCLES);
    $finish;
  end

endmodule
