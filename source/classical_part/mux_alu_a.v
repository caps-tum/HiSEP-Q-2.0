//////////////////////////////////////////////////////////////////////////////////
// Company: TUM
// Engineer: Xiaorang
//
// Create Date: 2023/02/08
// Design Name:
// Module Name: mux_alu_a
// Project Name:
// Target Devices:
// Tool Versions:
// Description: mux before the op_a of ALU, if the operation is branch, input is PC(plus imm in ALU), other wise, input is reg
//
// Dependencies: License Apache 2.0
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////
`include "../parameter.v"

`timescale 1ns / 1ps

module mux_alu_a (
    input [31:0] i_reg,
    input [31:0] i_pc,
    input        i_branch_sel, //connect to branch, one branch controls alu op_a selection and pc selection.
    output reg [31:0] o_alu_a
  );

  always @(*)
  begin
    if(i_branch_sel == `PC_JUMP)
        o_alu_a = i_pc;
    else
        o_alu_a = i_reg;
  end

endmodule

