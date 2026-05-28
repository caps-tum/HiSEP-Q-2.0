`timescale 1ns / 1ps
// inst_fifo.v
//
// Simple synchronous FIFO used by timed_fifo.
//
// Pointer sizing note: write_ptr and read_ptr use $clog2(DEPTH)+1 bits.
// The extra bit distinguishes full from empty when addresses wrap, which
// is the standard two-pointer FIFO technique.  Memory is indexed by the
// lower $clog2(DEPTH) bits so the depth is exactly DEPTH entries.
// DEPTH must be a power of two.

module inst_fifo #(
    parameter DEPTH      = 8,
    parameter DATA_WIDTH = 26
)(
    input  clk,
    input  reset,
    input  wr_en,
    input  rd_en,
    input  [DATA_WIDTH-1:0] data_in,
    output [DATA_WIDTH-1:0] data_out,
    output full,
    output empty
);

    localparam ADDR_W = $clog2(DEPTH);   // address bits (e.g. 3 for DEPTH=8)
    localparam PTR_W  = ADDR_W + 1;     // pointer bits (extra bit for full/empty)

    reg [DATA_WIDTH-1:0] memory [0:DEPTH-1];
    reg [DATA_WIDTH-1:0] data_out_reg;

    reg [PTR_W-1:0] write_ptr;
    reg [PTR_W-1:0] read_ptr;

    // Full when pointers differ only in the MSB; empty when identical
    assign full  = (write_ptr[PTR_W-1] != read_ptr[PTR_W-1]) &&
                   (write_ptr[ADDR_W-1:0] == read_ptr[ADDR_W-1:0]);
    assign empty = (write_ptr == read_ptr);

    integer i;
    always @(posedge clk) begin
        if (reset) begin
            write_ptr   <= 0;
            read_ptr    <= 0;
            data_out_reg <= {DATA_WIDTH{1'b0}};
            for (i = 0; i < DEPTH; i = i + 1)
                memory[i] <= {DATA_WIDTH{1'b0}};
        end else begin
            if (wr_en && !full) begin
                memory[write_ptr[ADDR_W-1:0]] <= data_in;
                write_ptr <= write_ptr + 1'b1;
            end
            if (rd_en && !empty) begin
                data_out_reg <= memory[read_ptr[ADDR_W-1:0]];
                read_ptr <= read_ptr + 1'b1;
            end
        end
    end

    assign data_out = data_out_reg;

endmodule
