`timescale 1ns / 1ps
// time_controller.v
//
// Reads one (t_inst, opcode) entry from the FIFO, waits until the global
// counter t_cnt reaches t_inst, then drives o_data = opcode for one cycle.
//
// State machine:
//   IDLE  : assert fifo_rd_en; when FIFO is non-empty go to WAIT
//   WAIT  : hold until t_cnt + 1 reaches or has passed t_inst, then ISSUE
//   ISSUE : drive o_data = opcode for one cycle, return to IDLE
//
// On-time entries issue at t_inst; an overdue entry issues as soon as it reaches WAIT.

module time_controller #(
    parameter TIME_WIDTH = 20,
    parameter OP_WIDTH   = 6
)(
    input  clk,
    input  reset,
    input  [TIME_WIDTH-1:0] t_cnt,

    output reg fifo_rd_en,
    input  [TIME_WIDTH+OP_WIDTH-1:0] fifo_data,
    input  fifo_empty,

    output reg [OP_WIDTH-1:0] o_data,
    output reg                o_valid     // pulses for exactly one cycle when gate is issued
);

    localparam IDLE  = 2'b00;
    localparam WAIT  = 2'b01;
    localparam ISSUE = 2'b10;

    wire [OP_WIDTH-1:0]   opcode = fifo_data[OP_WIDTH-1 : 0];
    wire [TIME_WIDTH-1:0] t_inst = fifo_data[TIME_WIDTH+OP_WIDTH-1 : OP_WIDTH];

    // Modular reached-or-passed test. Valid while the scheduled or overdue
    // distance is less than half the counter range.
    wire [TIME_WIDTH-1:0] time_since_target = (t_cnt + {{(TIME_WIDTH-1){1'b0}}, 1'b1}) - t_inst;
    wire                  target_reached    = ~time_since_target[TIME_WIDTH-1];

    reg [1:0] state, next_state;

    // Next-state logic
    always @(*) begin
        case (state)
            IDLE:  next_state = fifo_empty ? IDLE : WAIT;
            // ISSUE begins when t_cnt+1 reaches the target.
            WAIT:  next_state = target_reached ? ISSUE : WAIT;
            ISSUE: next_state = IDLE;
            default: next_state = IDLE;
        endcase
    end

    // State register
    always @(posedge clk) begin
        if (reset)
            state <= IDLE;
        else
            state <= next_state;
    end

    // Output logic
    always @(*) begin
        fifo_rd_en = 1'b0;
        o_data     = {OP_WIDTH{1'b0}};
        o_valid    = 1'b0;
        case (state)
            IDLE:  fifo_rd_en = 1'b1;
            ISSUE: begin
                o_data  = opcode;
                o_valid = 1'b1;
            end
            default: ;
        endcase
    end

endmodule
