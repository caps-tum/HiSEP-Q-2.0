`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/24/2023 12:06:16 PM
// Design Name: 
// Module Name: dispatcher
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


//module dispatcher #(
//    parameter integer NCH = 4
//)
//(
//    input wire clk,
//    input wire reset,
//    input wire [28+NCH*4-1 : 0]     comb,
//    output reg [20*NCH-1 : 0]       abs_time,
//    output reg [NCH-1 : 0]          fifo_wr_en,
//    output reg [6*NCH-1 : 0]        fifo_wd,
//    output reg [NCH-1 : 0]          err_bit    
//    );
//    //  comb
//    //  20-bit      4-bit       2*NCH-bit     4-bit       2*NCH-bit
//    //  abs_time    op_a        mask_a      op_b        mask_b
    
//    wire [3 : 0]        opcode_a;
//    wire [3 : 0]        opcode_b;
//    wire [19: 0]        input_time;
    
//    wire [NCH-1 : 0]    sel_a;
//    wire [NCH-1 : 0]    sel_b;
    
//    wire [2*NCH-1 : 0]  mask_a;
//    wire [2*NCH-1 : 0]  mask_b;
//    wire [4*NCH-1 : 0]  opcode_vec;
//    wire [2*NCH-1 : 0]  mask_vec;
    
//    assign input_time   = comb[28+NCH*4-1               : 28+NCH*4-1-19];
//    assign opcode_a     = comb[28+NCH*4-1-20            : 28+NCH*4-1-20-3];
//    assign mask_a       = comb[28+NCH*4-1-24            : 28+NCH*4-1-24-2*NCH+1];
//    assign opcode_b     = comb[28+NCH*4-1-24-2*NCH      : 28+NCH*4-1-24-2*NCH-3];
//    assign mask_b       = comb[28+NCH*4-1-24-2*NCH-4    : 0];

    
//    genvar i;
//    generate
//        for (i=0;i<NCH;i=i+1)
//        begin
//            assign sel_a[i]           = mask_a[2*i]|| mask_a[2*i+1];
//            assign sel_b[i]           = mask_b[2*i]|| mask_b[2*i+1];
//            assign mask_vec[2*i]      = mask_a[2*i] || mask_b[2*i];
//            assign mask_vec[2*i+1]    = mask_a[2*i+1] || mask_b[2*i+1];
//            assign opcode_vec[4*i+3:4*i]  = err_bit[i]? 4'b0000: sel_a[i]? opcode_a: sel_b[i]? opcode_b : 4'b0000;
        
//            always@(*)
//            begin
//                if (reset)
//                begin
//                    fifo_wr_en[i]           <= 1'b0;
//                    abs_time[20*i+19:20*i]  <= 20'b0000_0000_0000_0000_0000;
//                    err_bit[i]              <= 1'b0;
//                    fifo_wd[6*i+5:6*i]      <= 6'b0;
//                end else begin
//                    fifo_wr_en[i]           <= err_bit[i]? 1'b0: sel_a[i] || sel_b[i];
//                    abs_time[20*i+19:20*i]  <= err_bit[i]? 20'b0000_0000_0000_0000_0000: input_time;
//                    err_bit[i]              <= sel_a[i] && sel_b[i];
//                    fifo_wd[6*i+5:6*i]      <= {opcode_vec[4*i+3:4*i],mask_vec[2*i+1:2*i]};
//                end
//            end
//        end
//    endgenerate
    
      
    
//endmodule

`timescale 1ns / 1ps

module dispatcher #(
    parameter NCH        = 7,
    parameter TIME_WIDTH = 20
)(
    input  wire clk,
    input  wire reset,
    input  wire [TIME_WIDTH + 8 + NCH*4 - 1 : 0] comb,
    output reg  [TIME_WIDTH*NCH-1 : 0]           abs_time,
    output reg  [NCH-1 : 0]                      fifo_wr_en,
    output reg  [6*NCH-1 : 0]                    fifo_wd, // 固定 6-bit (4-bit OP + 2-bit Mask)
    output reg  [NCH-1 : 0]                      err_bit    
);

    // 计算总位宽
    localparam COMB_W = TIME_WIDTH + 8 + 4*NCH;

    wire [3 : 0]            opcode_a;
    wire [3 : 0]            opcode_b;
    wire [TIME_WIDTH-1: 0]  input_time;
    
    wire [NCH-1 : 0]        sel_a;
    wire [NCH-1 : 0]        sel_b;
    
    wire [2*NCH-1 : 0]      mask_a;
    wire [2*NCH-1 : 0]      mask_b;
    wire [4*NCH-1 : 0]      opcode_vec;
    wire [2*NCH-1 : 0]      mask_vec;

    // 参数化精准切片映射
    assign input_time = comb[COMB_W-1                     : COMB_W-TIME_WIDTH];
    assign opcode_a   = comb[COMB_W-1-TIME_WIDTH          : COMB_W-TIME_WIDTH-4];
    assign mask_a     = comb[COMB_W-1-TIME_WIDTH-4        : COMB_W-TIME_WIDTH-4-2*NCH];
    assign opcode_b   = comb[COMB_W-1-TIME_WIDTH-4-2*NCH  : COMB_W-TIME_WIDTH-8-2*NCH];
    assign mask_b     = comb[COMB_W-1-TIME_WIDTH-8-2*NCH  : 0]; 
    
    genvar i;
    generate
        for (i = 0; i < NCH; i = i + 1) begin : DISPATCH_CH
            assign sel_a[i] = mask_a[2*i] || mask_a[2*i+1];
            assign sel_b[i] = mask_b[2*i] || mask_b[2*i+1];
            
            assign mask_vec[2*i]   = mask_a[2*i]   || mask_b[2*i];
            assign mask_vec[2*i+1] = mask_a[2*i+1] || mask_b[2*i+1];
            
            assign opcode_vec[4*i+3 : 4*i] = err_bit[i] ? 4'b0000 : 
                                             sel_a[i]   ? opcode_a : 
                                             sel_b[i]   ? opcode_b : 4'b0000;
            
            always @(*) begin
                if (reset) begin
                    fifo_wr_en[i] <= 1'b0;
                    abs_time[TIME_WIDTH*i + TIME_WIDTH - 1 : TIME_WIDTH*i] <= {TIME_WIDTH{1'b0}};
                    err_bit[i] <= 1'b0;
                    fifo_wd[6*i+5 : 6*i] <= 6'b0;
                end else begin
                    fifo_wr_en[i] <= err_bit[i] ? 1'b0 : (sel_a[i] || sel_b[i]);
                    abs_time[TIME_WIDTH*i + TIME_WIDTH - 1 : TIME_WIDTH*i] <= err_bit[i] ? {TIME_WIDTH{1'b0}} : input_time;
                    err_bit[i] <= sel_a[i] && sel_b[i];
                    fifo_wd[6*i+5 : 6*i] <= {opcode_vec[4*i+3 : 4*i], mask_vec[2*i+1 : 2*i]};
                end
            end
        end
    endgenerate

endmodule