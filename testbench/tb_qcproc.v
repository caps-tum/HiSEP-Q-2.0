`timescale 1ns / 1ps

module tb_qcpro;

  // =========================================================
  // Parameters (匹配 qcpro 的配置)
  // =========================================================
  localparam NCH            = 7;  // 你可以随意修改这个值，比如改成 100
  localparam TIME_WIDTH     = 20;
  localparam OP_WIDTH       = 6;
  localparam TMANAGER_DEPTH = 32;
  localparam FIFO_DEPTH     = 8;
  localparam PERIOD         = 10;

  // =========================================================
  // Ports & Registers
  // =========================================================
  reg clk = 0;
  reg reset = 0;

  reg [31:0] start_sig = 32'b0;
  reg [31:0] reg2 = 32'b0;
  reg [31:0] reg1 = 32'b0;
  wire [31:0] end_sig; 

  // 接收参数化后的平坦化输出向量
  wire [(OP_WIDTH * NCH) - 1 : 0] data_q_out;
  wire error;

  // =========================================================
  // 使用数组和 Generate 循环自动解包 (完全参数化)
  // =========================================================
  // 声明一个包含 NCH 个元素的数组，每个元素位宽为 OP_WIDTH
  wire [OP_WIDTH-1:0] data_q [0:NCH-1];

  genvar i;
  generate
      for (i = 0; i < NCH; i = i + 1) begin : UNPACK_DATA_Q
          // 将平坦化总线的对应切片赋值给数组的对应元素
          assign data_q[i] = data_q_out[OP_WIDTH*(i+1)-1 : OP_WIDTH*i];
      end
  endgenerate

  // =========================================================
  // internal wires
  // =========================================================
  wire pram_en;
  wire pram_rd_en ;
  wire [11-1:0] pram_addr ;
  wire [31:0] instruction ;
  
  wire inverted_clk ;
  wire dram_en ;
  wire dram_rd_en ;
  wire dram_wr_en ;
  wire [11-1:0] dram_addr ;
  wire [31:0] dram_din;
  wire [31:0] data_read ;

  // =========================================================
  // Module Instantiations
  // =========================================================
  
  // 1. 例化参数化的 qcpro
  qcpro #(
    .NCH            (NCH),
    .TIME_WIDTH     (TIME_WIDTH),
    .OP_WIDTH       (OP_WIDTH),
    .TMANAGER_DEPTH (TMANAGER_DEPTH),
    .FIFO_DEPTH     (FIFO_DEPTH)
  ) qcpro_i (
    .clk          (clk ),
    .reset        (reset ),
    .pram_en      (pram_en ),
    .pram_rd_en   (pram_rd_en ),
    .pram_addr    (pram_addr ),
    .instruction  (instruction ),
    .inverted_clk (inverted_clk ),
    .dram_en      (dram_en ),
    .dram_rd_en   (dram_rd_en ),
    .dram_wr_en   (dram_wr_en ),
    .dram_addr    (dram_addr ),
    .dram_din     (dram_din ),
    .data_read    (data_read ),
    .start_sig    (start_sig ),
    .reg1         (reg1 ),
    .reg2         (reg2 ),
    .end_sig      (end_sig ),
    .data_q_out   (data_q_out ), // 连接合并后的数据总线
    .error        (error)
  );

  // 2. 例化 PRAM
  pram pram_dut (
    .clk         (clk ),
    .ena         (pram_en ),
    .rea         (pram_rd_en ),
    .reset       (reset ),
    .addr        (pram_addr ),
    .program_out (instruction)
  );

  // 3. 例化 DRAM (BRAM)
  bram bram_dut (
    .clk   (inverted_clk ),
    .ena   (dram_en ),
    .rea   (dram_rd_en),
    .wea   (dram_wr_en ),
    .reset (reset ),
    .addra (dram_addr ),
    .dia   (dram_din ),
    .doa   (data_read)
  );

  // =========================================================
  // Clock Generation & Test Sequence
  // =========================================================
  initial clk = 1'b1;
  always #(PERIOD/2.0) clk = !clk;
  
  initial begin
    // 初始化
    reset <= 1'b1;
    start_sig <= 32'h0;
    
    # (PERIOD*3);
    reset <= 1'b0;
    
    # (PERIOD*2);
    start_sig <= 32'h00000001; // 启动处理器
    
    # (PERIOD*50);
    $stop;
    $finish;
  end
  
  // =========================================================
  // 自动化监控与日志打印 (Automated Monitor & Logger)
  // =========================================================
  
  // 1. 定义操作码解码函数 (4-bit -> String)
  function [39:0] get_op_name;
      input [3:0] op_code;
      begin
          case (op_code)
              4'b0000: get_op_name = "QNOP ";
              4'b0001: get_op_name = "X180 ";
              4'b0010: get_op_name = "X90  ";
              4'b0011: get_op_name = "X90R ";
              4'b0100: get_op_name = "Y180 ";
              4'b0101: get_op_name = "Y90  ";
              4'b0110: get_op_name = "Y90R ";
              4'b0111: get_op_name = "MEAS ";
              4'b1000: get_op_name = "CNOT ";
              4'b1001: get_op_name = "HAMD ";
              default: get_op_name = "UNDEF";
          endcase
      end
  endfunction

  // 2. 定义角色/掩码解码函数 (2-bit -> String)
  function [55:0] get_role_name;
      input [1:0] mask;
      begin
          case (mask)
              2'b00: get_role_name = "None   ";
              2'b01: get_role_name = "Target "; // 目标位
              2'b10: get_role_name = "Control"; // 控制位/源位
              2'b11: get_role_name = "Single "; // 单比特独立操作
              default: get_role_name = "Unknown";
          endcase
      end
  endfunction

  // 3. 监控总线并在 Tcl/Console 窗口打印
  integer ch;
  always @(posedge clk) begin
      // 只有在非复位状态下才进行监控
      if (!reset) begin
          // 遍历每一个通道 (Qubit)
          for (ch = 0; ch < NCH; ch = ch + 1) begin
              // 如果操作码(高4位)不是 QNOP (4'b0000)，说明有实质性量子门被派发
              if (data_q[ch][5:2] != 4'b0000) begin
                  $display("[Time: %8t ns] Qubit[%0d] executed operation: %s (Role: %s)", 
                           $time, 
                           ch, 
                           get_op_name(data_q[ch][5:2]), 
                           get_role_name(data_q[ch][1:0]));
              end
          end
      end
  end
  
reg [10:0] exec_pc  = 11'h7FF;     // 正在执行的指令所对应的 PC 地址
reg [10:0] printed_pc = 11'h7FF;  // 记录已经打印过的 PC，防止处理器停顿时重复打印

  always @(posedge clk) begin
      if (!reset) begin
          // 1. 锁存当前的 PRAM 地址。
          // 因为 PRAM 读取有一拍的延迟，当前拍的 pram_addr，要在下一拍才会变成有效的 instruction 数据。
          exec_pc <= pram_addr;
          
          // 2. 确保处理器已启动，且指令不是全 0 (纯NOP)，且当前 PC 还没有被打印过
          if (start_sig != 0 && instruction != 32'h00000000 && exec_pc != printed_pc) begin
              printed_pc <= exec_pc; // 标记该 PC 已打印

              // 3. 开始解析与反汇编
              if (instruction[31] == 1'b1) begin
                  // 最高位为 1，代表量子门派发指令
                  $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> [Q_OP] Quantum Gate/Micro-op Dispatch", $time, exec_pc, instruction);
              end else begin
                  // 最高位为 0，按照经典控制指令的 Opcode [30:25] 翻译
                  case (instruction[30:25])
                      6'b010110: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> LDI    R%0d, %0d", $time, exec_pc, instruction, instruction[24:20], instruction[19:0]);
                      6'b010111: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> LDUI   R%0d, R%0d, %0d", $time, exec_pc, instruction, instruction[24:20], instruction[19:15], instruction[14:0]);
                      6'b001001: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> LD     R%0d, R%0d(Offset: %0d)", $time, exec_pc, instruction, instruction[24:20], instruction[14:10], instruction[9:0]);
                      6'b001010: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> ST     R%0d, R%0d(Offset: %0d)", $time, exec_pc, instruction, instruction[19:15], instruction[14:10], instruction[9:0]);
                      6'b001101: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> CMP    R%0d, R%0d", $time, exec_pc, instruction, instruction[19:15], instruction[14:10]);
                      6'b000001: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> BR     Flag[%0d], Offset: %0d", $time, exec_pc, instruction, instruction[3:0], instruction[24:4]);
                      6'b000010: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> JUMP   Offset: %0d", $time, exec_pc, instruction, instruction[24:4]);
                      6'b010101: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> FMR    R%0d, Q%0d", $time, exec_pc, instruction, instruction[24:20], instruction[2:0]);
                      6'b011110: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> ADD    R%0d, R%0d, R%0d", $time, exec_pc, instruction, instruction[24:20], instruction[19:15], instruction[14:10]);
                      6'b011111: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> SUB    R%0d, R%0d, R%0d", $time, exec_pc, instruction, instruction[24:20], instruction[19:15], instruction[14:10]);
                      6'b111000: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> SMSOL  S%0d [VLIW Mask Header]", $time, exec_pc, instruction, instruction[24:20]);
                      6'b101100: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> SITO   T%0d", $time, exec_pc, instruction, instruction[24:20]);
                      6'b100000: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> QWAIT  %0d", $time, exec_pc, instruction, instruction[19:0]);
                      6'b100001: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> QWAITR R%0d", $time, exec_pc, instruction, instruction[19:15]);
                      6'b001000: $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> STOP", $time, exec_pc, instruction);
                      default:   $display("[Time: %8t ns] [PC: @%02X] Fetch: %08X -> [VLIW Payload / Unknown]", $time, exec_pc, instruction);
                  endcase
              end
          end
      end
  end
  
endmodule