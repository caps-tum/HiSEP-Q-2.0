`timescale 1ns / 1ns

module pc_gen (
    input clk,
    input reset,
    input i_sel_pc,
    input start_sig,
    input end_sig,
    input [31:0] i_pc_from_alu,
    output reg [31:0] o_pc
  );

  wire [31:0] next_pc;
  wire [31:0] current_pc;

  assign current_pc = o_pc;

  // sequential PC register
  always @(negedge clk)
  begin
    if (reset) o_pc <= 32'h0000_0000;
    else if(start_sig) o_pc <= next_pc;
    else o_pc <= o_pc;
    begin
    end
  end

  // comb adder + mux
//   assign next_pc = (i_sel_pc) ? i_pc_from_alu : current_pc + 32'h4; // PC+4
  assign next_pc = (end_sig) ? current_pc : ((i_sel_pc) ? i_pc_from_alu : current_pc + 32'h1); // PC+1

endmodule
