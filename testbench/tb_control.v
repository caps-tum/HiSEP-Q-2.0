`timescale 1ns / 10ps
`include "./../parameter.v"

module control_tb;

  // Parameters

  // Ports
  reg clk;
  reg rst_n = 0;
  reg [5:0] opcode;
  reg q_inst_sign = 0;
  reg [3:0] comp_flag;
  wire [3:0] ALU_op;
  wire reg_write;
  wire mem_read;
  wire mem_write;
  wire branch;
  wire q_time_write;
  wire q_time_sel;
  wire [1:0] q_reg_write;
  wire [2:0] reg_sel;
  wire [2:0] imm_sel;

  control 
  control_dut (
    .rst_n (rst_n ),
    .opcode (opcode ),
    .q_inst_sign (q_inst_sign ),
    .comp_flag (comp_flag ),
    .ALU_op (ALU_op ),
    .reg_write (reg_write ),
    .mem_read (mem_read ),
    .mem_write (mem_write ),
    .branch (branch ),
    .q_time_write (q_time_write ),
    .q_time_sel (q_time_sel ),
    .q_reg_write (q_reg_write ),
    .reg_sel  ( reg_sel),
    .imm_sel (imm_sel)
  );
  
  
parameter PERIOD = 100;
initial clk = 1'b1;
always #(PERIOD/2.0) clk = !clk;

  initial begin
    begin
    #(PERIOD) rst_n  =  1;
    #(PERIOD) rst_n  =  0;
    #(PERIOD) rst_n  =  1;
    #(3*PERIOD);
    opcode = 6'b001101;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b000001;
    q_inst_sign = 0;
    comp_flag = 1;
    #(PERIOD)
    opcode = 6'b010100;
    q_inst_sign = 0;
    comp_flag = 3;
    #(PERIOD)
    opcode = 6'b010110;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b010111;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b001101;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b001001;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b001010;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b010101;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b011010;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b011000;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b011001;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b011011;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b011110;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b011111;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b100000;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b100001;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b101001;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    opcode = 6'b101000;
    q_inst_sign = 0;
    comp_flag = 0;
    #(PERIOD)
    $finish;
    end
  end


endmodule
