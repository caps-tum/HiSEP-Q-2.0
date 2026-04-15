`timescale 1ns / 1ps
// timed_fifo.v
//
// Wraps inst_fifo and time_controller into one per-qubit scheduling unit.
// Write a (time, op) pair via i_fifo_time / i_fifo_op / i_fifo_we.
// The op appears on o_data for one cycle when t_cnt reaches i_fifo_time.

module timed_fifo #(
    parameter FIFO_DEPTH = 8,
    parameter TIME_WIDTH = 20,
    parameter OP_WIDTH   = 6
)(
    input  clk,
    input  reset,
    input  [TIME_WIDTH-1:0] i_fifo_time,
    input  [OP_WIDTH-1:0]   i_fifo_op,
    input                   i_fifo_we,
    input  [TIME_WIDTH-1:0] t_cnt,
    output [OP_WIDTH-1:0]   o_data,
    output                  o_valid,        // pulses one cycle when gate issues
    output                  error           // FIFO full on a write attempt
);

    wire [TIME_WIDTH+OP_WIDTH-1:0] fifo_din  = {i_fifo_time, i_fifo_op};
    wire [TIME_WIDTH+OP_WIDTH-1:0] fifo_dout;
    wire fifo_rd_en, fifo_empty, fifo_full;

    inst_fifo #(
        .DEPTH      (FIFO_DEPTH),
        .DATA_WIDTH (TIME_WIDTH + OP_WIDTH)
    ) u_inst_fifo (
        .clk      (clk),
        .reset    (reset),
        .wr_en    (i_fifo_we),
        .rd_en    (fifo_rd_en),
        .data_in  (fifo_din),
        .data_out (fifo_dout),
        .full     (fifo_full),
        .empty    (fifo_empty)
    );

    time_controller #(
        .TIME_WIDTH (TIME_WIDTH),
        .OP_WIDTH   (OP_WIDTH)
    ) u_time_ctrl (
        .clk        (clk),
        .reset      (reset),
        .t_cnt      (t_cnt),
        .fifo_rd_en (fifo_rd_en),
        .fifo_data  (fifo_dout),
        .fifo_empty (fifo_empty),
        .o_data     (o_data),
        .o_valid    (o_valid)
    );

    assign error = fifo_full & i_fifo_we;   // write attempted on a full FIFO

endmodule
