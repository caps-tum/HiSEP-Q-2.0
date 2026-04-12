//test needed

module q_time_manager
#(      parameter       DEPTH = 32 ,
        parameter       DATA_WIDTH = 20)
(
    input clk,
    input reset,
    input wr_en, // comes from q_time_write from classical controller
    input rd_en, //when an operation comes, put read enable on
    input [DATA_WIDTH-1:0] data_in, //mux is finished in quantum decoder
    output [DATA_WIDTH-1:0] data_out,
    output full, //need consideration
    output empty
);

reg [DATA_WIDTH-1:0] memory [0:DEPTH-1];
reg [DATA_WIDTH-1:0] data_out_reg;
reg [DEPTH-1:0] write_ptr;
reg [DEPTH-1:0] read_ptr;

assign full = (write_ptr + 1'b1 == read_ptr);
assign empty = (write_ptr == read_ptr);

integer i;
    initial begin
        for (i=0;i<32;i=i+1)begin
            memory[i] <= 20'h0000_0000;
        end
    end

always @(posedge clk) begin
    if (reset) begin
        write_ptr <= 0;
        read_ptr <= 0;
        data_out_reg <= 0;
    end 
    else begin
        if (wr_en && !full) begin
            memory[write_ptr] <= data_in;
            write_ptr <= write_ptr + 1;
        end
        if (rd_en && !empty) begin
            data_out_reg <= memory[read_ptr];
            read_ptr <= read_ptr + 1;
        end
    end
end

assign data_out = data_out_reg;


endmodule