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
    output                  error,          // FIFO full on a write attempt
    // Combinational preflight result for i_fifo_time. High when this qubit
    // already has an accepted, not-yet-fired gate at the same timestamp.
    output                  time_conflict,
    // Combinational preflight result: high when this qubit's FIFO has room
    // for one more write right now. Callers doing an atomic multi-qubit
    // commit should check this for every touched qubit *before* asserting
    // i_fifo_we on any of them, since a write attempted while this is low is
    // silently dropped by inst_fifo (see `error` above) rather than queued.
    output                  write_ready
);

    wire [TIME_WIDTH+OP_WIDTH-1:0] fifo_din  = {i_fifo_time, i_fifo_op};
    wire [TIME_WIDTH+OP_WIDTH-1:0] fifo_dout;
    wire fifo_rd_en, fifo_empty, fifo_full;

    // inst_fifo releases its head to time_controller before the gate fires,
    // so collision detection cannot inspect inst_fifo alone. Keep a shadow
    // queue containing every accepted timestamp until o_valid consumes it.
    // The extra slot accounts for the entry currently held by time_controller.
    localparam TRACK_DEPTH = FIFO_DEPTH + 1;
    localparam TRACK_PTR_W = (TRACK_DEPTH <= 1) ? 1 : $clog2(TRACK_DEPTH);
    localparam TRACK_CNT_W = $clog2(TRACK_DEPTH + 1);

    reg [TIME_WIDTH-1:0] pending_time_q [0:TRACK_DEPTH-1];
    reg [TRACK_DEPTH-1:0] pending_valid_q;
    reg [TRACK_PTR_W-1:0] pending_wr_ptr_q;
    reg [TRACK_PTR_W-1:0] pending_rd_ptr_q;
    reg [TRACK_CNT_W-1:0] pending_count_q;
    integer ti;

    reg time_conflict_r;
    always @(*) begin
        time_conflict_r = 1'b0;
        for (ti = 0; ti < TRACK_DEPTH; ti = ti + 1) begin
            if (pending_valid_q[ti] && (pending_time_q[ti] == i_fifo_time))
                time_conflict_r = 1'b1;
        end
    end
    assign time_conflict = time_conflict_r;

    wire accepted_write = i_fifo_we && !fifo_full && !time_conflict;
    wire issued_entry   = o_valid && (pending_count_q != 0);

    inst_fifo #(
        .DEPTH      (FIFO_DEPTH),
        .DATA_WIDTH (TIME_WIDTH + OP_WIDTH)
    ) u_inst_fifo (
        .clk      (clk),
        .reset    (reset),
        .wr_en    (accepted_write),
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
    assign write_ready = !fifo_full;

    always @(posedge clk) begin
        if (reset) begin
            pending_valid_q  <= {TRACK_DEPTH{1'b0}};
            pending_wr_ptr_q <= {TRACK_PTR_W{1'b0}};
            pending_rd_ptr_q <= {TRACK_PTR_W{1'b0}};
            pending_count_q  <= {TRACK_CNT_W{1'b0}};
        end else begin
            if (issued_entry) begin
                pending_valid_q[pending_rd_ptr_q] <= 1'b0;
                pending_rd_ptr_q <= (pending_rd_ptr_q == TRACK_DEPTH-1) ?
                                    {TRACK_PTR_W{1'b0}} : pending_rd_ptr_q + 1'b1;
            end

            if (accepted_write) begin
                pending_time_q[pending_wr_ptr_q]  <= i_fifo_time;
                pending_valid_q[pending_wr_ptr_q] <= 1'b1;
                pending_wr_ptr_q <= (pending_wr_ptr_q == TRACK_DEPTH-1) ?
                                    {TRACK_PTR_W{1'b0}} : pending_wr_ptr_q + 1'b1;
            end

            case ({accepted_write, issued_entry})
                2'b10: pending_count_q <= pending_count_q + 1'b1;
                2'b01: pending_count_q <= pending_count_q - 1'b1;
                default: pending_count_q <= pending_count_q;
            endcase
        end
    end

endmodule
