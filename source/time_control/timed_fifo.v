module timed_fifo #(
    parameter FIFO_DEPTH = 8,
    parameter TIME_WIDTH = 20,
    parameter OP_WIDTH   = 6
)(
    input clk,
    input reset,
    input [TIME_WIDTH-1:0] i_fifo_time,
    input [OP_WIDTH-1:0]   i_fifo_op,
    input                  i_fifo_we,
    input [TIME_WIDTH-1:0] t_cnt,
    output [OP_WIDTH-1:0]  o_data,
    output error
);

wire [TIME_WIDTH+OP_WIDTH-1:0] i_fifo_din;
wire fifo_rd_en;
wire [TIME_WIDTH+OP_WIDTH-1:0] fifo_dout;
wire fifo_empty;
wire fifo_full;

inst_fifo #(
  .DEPTH      (FIFO_DEPTH),
  .DATA_WIDTH (TIME_WIDTH + OP_WIDTH)
) inst_fifo_i (
  .clk      (clk),
  .reset    (reset),
  .wr_en    (i_fifo_we),
  .rd_en    (fifo_rd_en),
  .data_in  (i_fifo_din),
  .data_out (fifo_dout),
  .full     (fifo_full),
  .empty    (fifo_empty)
);

time_controller #(
    .TIME_WIDTH (TIME_WIDTH),
    .OP_WIDTH   (OP_WIDTH)
) time_controller_i (
  .clk        (clk),
  .reset      (reset),
  .t_cnt      (t_cnt),
  .fifo_rd_en (fifo_rd_en),
  .fifo_data  (fifo_dout),
  .fifo_empty (fifo_empty),
  .o_data     (o_data)
);

assign error = fifo_full;
assign i_fifo_din = {i_fifo_time, i_fifo_op};

endmodule