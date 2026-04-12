`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/24/2023 09:26:19 PM
// Design Name: 
// Module Name: tb_dispatcher
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
`timescale 10 ns / 100 ps

module tb_dispatcher();
    parameter integer N = 10;
    
    
     reg clk;
     reg reset;
     reg  [28+N*4-1 : 0]     comb;      
     wire [20*N-1 : 0]       abs_time;  
     wire [N-1 : 0]          fifo_wr_e;
     wire [6*N-1 : 0]        fifo_wd;
     wire [N-1 : 0]          err_bit;
     
     dispatcher #(
        .NCH(N)
     )
     dut_0(
        .clk(clk),
        .reset(reset),
        .comb(comb),      
        .abs_time(abs_time) ,  
        .fifo_wr_en(fifo_wr_en),
        .fifo_wd(fifo_wd),   
        .err_bit(err_bit)    
     );
     
    always
    #5  clk = ! clk ;
     
     initial begin
     # 10;
     reset = 1'b1;
     # 10;
     reset = 1'b0;
     # 10; // all error
     comb = 68'b1111_1111_1111_1111_1111_1001_1010_1010_1010_1010_1010_0110_1010_1010_1010_1010_1010;
     # 10; // all error
     comb = 68'b1111_1111_1111_1111_1111_1001_1010_1010_1010_1010_1010_0110_0101_0101_0101_0101_0101;
     # 10; // all correct
     comb = 68'b1111_1111_1111_1111_1111_1001_0101_0101_0101_0000_0000_0110_0000_0000_0000_1010_1010;
     
     $finish;
     end
     
endmodule
