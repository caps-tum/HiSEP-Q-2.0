//////////////////////////////////////////////////////////////////////////////////
// Company: TUM
// Engineer: QK
//
// Create Date: 2023/02/07 17:20:36
// Design Name:
// Module Name: reg_file
// Project Name:
// Target Devices:
// Tool Versions:
// Description: dual ports for reading and single port for writing
//
// Dependencies: License MIT
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////
/// r0 is always 0, like riscv//////

`timescale 1ns / 1ps

module reg_file (
    input clk,
    input reset,
    input [4:0] rs_addr,
    input [4:0] rt_addr,
    input [4:0] wr_addr,
    input [31:0] wr_data,
    input wr_en,
    output wire [31:0] rs_data,
    output wire [31:0] rt_data
  );

  reg [31:0] regs [31:0];

//  always @(*)
//  begin
//    if (reset)
//    begin
//      rd_data1 = 32'h0000_0000;
//      rd_data2 = 32'h0000_0000;
//    end
//  end

integer i;
    initial begin
        for (i=0;i<32;i=i+1)begin
            regs[i] <= 32'h0000_0001;
        end
    end
  always @(posedge clk)
  begin
    if (wr_en)
    begin
      regs[wr_addr] <= wr_data;
    end
  end

  assign rs_data = (rs_addr == 0) ? 32'h00000000 : regs[rs_addr];
  assign rt_data = (rt_addr == 0) ? 32'h00000000 : regs[rt_addr];

endmodule
