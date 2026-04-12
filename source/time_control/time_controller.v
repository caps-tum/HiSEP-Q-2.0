module time_controller #(
    parameter TIME_WIDTH = 20,
    parameter OP_WIDTH   = 6
)(
    input clk,
    input reset,
    input [TIME_WIDTH-1:0] t_cnt,
    
    output reg fifo_rd_en,
    input [TIME_WIDTH+OP_WIDTH-1:0] fifo_data,
    input fifo_empty,

    output reg [OP_WIDTH-1:0] o_data
);

parameter IDLE  = 2'b00;
parameter WAIT  = 2'b01;
parameter ISSUE = 2'b10;

wire [OP_WIDTH-1:0]   opcode;
wire [TIME_WIDTH-1:0] t_inst;

assign opcode = fifo_data[OP_WIDTH-1 : 0];
assign t_inst = fifo_data[TIME_WIDTH+OP_WIDTH-1 : OP_WIDTH];

reg [1:0] state;
reg [1:0] next_state;

always @(*) begin
    case (state)
        IDLE: begin
            if(!fifo_empty) next_state = WAIT;
            else next_state = IDLE;
        end
        WAIT:begin
            if(t_inst == (t_cnt + 1'b1)) next_state = ISSUE;
            else next_state = WAIT;
        end
        ISSUE:begin
            next_state = IDLE;
        end
        default: next_state = IDLE;
    endcase
end

always @(posedge clk ) begin
    if (reset) begin
        state <= IDLE;
    end else begin
        state <= next_state;
    end
end

always @(*) begin
    fifo_rd_en = 0;
    o_data = 0;
    case (state)
        IDLE:  fifo_rd_en = 1'b1;
        ISSUE: o_data = opcode;
    endcase
end
endmodule