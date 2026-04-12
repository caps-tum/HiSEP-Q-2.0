module inst_fifo #(      
    parameter DEPTH      = 8,
    parameter DATA_WIDTH = 26
)(
    input clk,
    input reset,
    input wr_en, 
    input rd_en, 
    input  [DATA_WIDTH-1:0] data_in, 
    output [DATA_WIDTH-1:0] data_out,
    output full, 
    output empty
);

reg [DATA_WIDTH-1:0] memory [0:DEPTH-1];
reg [DATA_WIDTH-1:0] data_out_reg;
reg [DEPTH-1:0] write_ptr;
reg [DEPTH-1:0] read_ptr;

assign full  = (write_ptr + 1'b1 == read_ptr);
assign empty = (write_ptr == read_ptr);
    
integer i;
always @(posedge clk) begin
    if (reset) begin
        write_ptr <= 0;
        read_ptr  <= 0;
        for (i = 0; i < DEPTH; i = i + 1) begin
            memory[i] <= {DATA_WIDTH{1'b0}};
        end
    end else begin
        if (wr_en && !full) begin
            memory[write_ptr] <= data_in;
            write_ptr <= write_ptr + 1'b1;
        end
        if (rd_en && !empty) begin
            data_out_reg <= memory[read_ptr];
            read_ptr <= read_ptr + 1'b1;
        end
    end
end
    
assign data_out = data_out_reg;
endmodule