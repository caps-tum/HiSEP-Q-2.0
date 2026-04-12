//////////////////////////////////////////////////////////////////////////////////
// Company: TUM
// Engineer: Xiaorang
//
// Create Date: 2023/02/08
// Design Name:
// Module Name: mux_alu_b
// Project Name:
// Target Devices:
// Tool Versions:
// Description: mux before the op_b of ALU, select from register and imm
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

module mux_alu_b (
    input [31:0] i_reg,
    input [31:0] i_imm,
    input        i_imm_sel, //select if immediate operation
    output reg [31:0] o_alu_a
  );

  always @(*)
  begin
    if(i_imm_sel == 1'b1)
        o_alu_a = i_imm;
    else
        o_alu_a = i_reg;
  end

endmodule

