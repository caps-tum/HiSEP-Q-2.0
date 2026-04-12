//////////////////////////////////////////////////////////////////////////////////
// Company: TUM
// Engineer: QK
//
// Create Date: 2023/02/08
// Design Name:
// Module Name: mux_2_reg
// Project Name:
// Target Devices:
// Tool Versions:
// Description: 7-1 multiplexer to regfile
//
// Dependencies: License Apache 2.0
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////

`timescale 1ns / 1ns
`include "../parameter.v"

module mux_2_reg (
    input [31:0] i_from_data_mem,
    input [31:0] i_from_alu,
    input [31:0] i_from_q_measure,
    input [31:0] i_from_comp_flg,
    input [31:0] i_from_imm,
    input [2:0] sel_from_ctrl,
    output reg [31:0] o_2_regfile
  );

  always @(*)
  begin
    case(sel_from_ctrl)
      `REGSRC_MEM:
        o_2_regfile = i_from_data_mem;
      `REGSRC_ALU:
        o_2_regfile = i_from_alu;
      `REGSRC_MEA:
        o_2_regfile = i_from_q_measure;
      `REGSRC_COMP:
        o_2_regfile = i_from_comp_flg;
      `REGSRC_IMM:
        o_2_regfile = i_from_imm;
      default:
        o_2_regfile = i_from_alu;
    endcase
  end

endmodule
