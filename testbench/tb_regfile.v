//////////////////////////////////////////////////////////////////////////////////
// Company: TUM
// Engineer: QK
//
// Create Date: 2023/02/07 17:20:36
// Design Name:
// Module Name: reg_file_tb
// Project Name:
// Target Devices:
// Tool Versions:
// Description: testbench
//
// Dependencies: License MIT
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////

`timescale 1ns / 1ps

module reg_file_tb();

  reg clk;
  reg reset;
  reg [4:0] rd_addr1;
  reg [4:0] rd_addr2;
  reg [4:0] wr_addr;
  reg [31:0] wr_data;
  reg wr_en;
  wire [31:0] rd_data1;
  wire [31:0] rd_data2;

  // contents for test
  // reg [31:0] reg_contents [31:0];

  reg_file regfile_DUT(
             .clk(clk),
             .reset(reset),
             .rd_addr1(rd_addr1),
             .rd_addr2(rd_addr2),
             .wr_addr(wr_addr),
             .wr_data(wr_data),
             .wr_en(wr_en),
             .rd_data1(rd_data1),
             .rd_data2(rd_data2)
           );

  parameter PERIOD = 100;
  initial
    clk = 1'b1;
  always #(PERIOD/2.0) clk = !clk;

  initial
  begin
    reset = 1'b1;
    rd_addr1 = 5'b00000;
    rd_addr2 = 5'b00000;
    wr_addr = 5'b00000;
    wr_data = 32'hzzzzzzzz;
    wr_en = 1'bz;
    # (PERIOD);
    reset = 1'b0;
  end

  integer i;

  initial
  begin
    // write test
    for (i=0;i<32;i=i+1)
    begin
      wr_en = 1'b1;
      wr_addr = 5'b00000+i;
      wr_data = 32'h0000_0000+i;
      # (PERIOD);
    end
    // read test port_1 and port_2
    wr_en = 1'b0;
    rd_addr1 = 5'b10000;
    rd_addr2 = 5'b01000;
    # (PERIOD);

  end

endmodule











