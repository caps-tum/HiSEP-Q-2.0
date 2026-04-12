`timescale 1ns / 1ps

module qcpro #(
    // =========================================================
    // 全局系统级可配置参数 (Configurable Parameters)
    // =========================================================
    parameter NCH            = 7,  // the number of qubits
    parameter TIME_WIDTH     = 20, // the length of absolute time
    parameter OP_WIDTH       = 6,  // the length of qubit output (4-bit operand + 2-bit mask (00 nop, 01 target, 10 source 11 single))
    parameter TMANAGER_DEPTH = 32, // depth of time queue
    parameter FIFO_DEPTH     = 8   // depth of time-fifo
)(
    input clk,
    input reset,
    
    // dram/pram
    output pram_en,
    output pram_rd_en,
    output [11-1 :0]    pram_addr, 
    input  [32-1 :0]    instruction, 

    output inverted_clk, 
    output dram_en,
    output dram_rd_en,
    output dram_wr_en,
    output [11-1 :0]    dram_addr,
    output [32-1 :0]    dram_din,
    input  [32-1 :0]    data_read, 

    input  [32-1 : 0]   start_sig, 
    input  [32-1 : 0]   reg1, 
    input  [32-1 : 0]   reg2,
    output [32-1 : 0]   end_sig,
    
    // data of channel i  = data_q_out[OP_WIDTH*(i+1)-1 : OP_WIDTH*i]
    output [(OP_WIDTH*NCH)-1 : 0] data_q_out, 
    output error
);

//***************** reg & wire ***************************//
reg [TIME_WIDTH-1:0] t_cnt;
reg meas_wr_data = 0;
reg meas_wr_valid = 0;

wire [(TIME_WIDTH*NCH)-1 : 0] abs_time;
wire [(OP_WIDTH*NCH)-1   : 0] fifo_op;
wire [NCH-1:0]                fifo_we_i;
wire [NCH-1:0]                error_i;
wire [NCH-1:0]                error_control;

//***************** always *******************//
always @(posedge clk) begin
    if(reset) begin
        t_cnt <= {TIME_WIDTH{1'b0}};
    end else begin
        t_cnt <= t_cnt + 1'b1;
    end
end

//*************** instance ******************//
main_ctrl #(
    .NCH            (NCH),
    .TIME_WIDTH     (TIME_WIDTH),
    .OP_WIDTH       (OP_WIDTH),
    .TMANAGER_DEPTH (TMANAGER_DEPTH)
) main_ctrl_dut (
    .clk           (clk),
    .reset         (reset),
    .t_cnt         (t_cnt),
    .meas_wr_data  (meas_wr_data),
    .meas_wr_valid (meas_wr_valid),
    
    .pram_en       (pram_en),
    .pram_rd_en    (pram_rd_en),
    .pram_addr     (pram_addr),
    .instruction   (instruction),
    
    .inverted_clk  (inverted_clk),
    .dram_en       (dram_en),
    .dram_rd_en    (dram_rd_en),
    .dram_wr_en    (dram_wr_en),
    .dram_addr     (dram_addr),
    .dram_din      (dram_din),
    .data_read     (data_read),
    
    .start_sig     (start_sig),
    .reg1          (reg1),
    .reg2          (reg2),
    .end_sig       (end_sig),
    
    .abs_time      (abs_time),
    .fifo_wr_en    (fifo_we_i),
    .fifo_wd       (fifo_op),
    .err_bit       (error_control)
);

// 参数化例化底层的 timed_fifo
genvar i;
generate
    for (i = 0; i < NCH; i = i + 1) begin : GEN_CH
        timed_fifo #(
            .FIFO_DEPTH (FIFO_DEPTH),
            .TIME_WIDTH (TIME_WIDTH),
            .OP_WIDTH   (OP_WIDTH)
        ) timed_fifo_i (
            .clk         (clk),
            .reset       (reset),
            .i_fifo_time (abs_time[(TIME_WIDTH * (i + 1) - 1) : (TIME_WIDTH * i)]),
            .i_fifo_op   (fifo_op [(OP_WIDTH   * (i + 1) - 1) : (OP_WIDTH   * i)]),
            .i_fifo_we   (fifo_we_i[i]),
            .t_cnt       (t_cnt),
            .o_data      (data_q_out[(OP_WIDTH * (i + 1) - 1) : (OP_WIDTH * i)]),
            .error       (error_i[i])
        );
    end
endgenerate

assign error = (|error_control) | (|error_i);

endmodule