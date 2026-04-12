// this is a histogram
module histogram 
#(      
    parameter       NUM_Q = 7, //number of qubits，
    parameter       DEPTH = 2**NUM_Q,
    parameter       BITWIDTH = 3) //iteration time of the progress
(
    input clk,
    input reset,
    input acc_en, //enable signal for accumulation
    input acc_over,
    input [NUM_Q-1:0] data,
    output [BITWIDTH*DEPTH-1:0] histogram 
);

//calculate the bitwitdh of the output - maybe in toplevel
// function integer clogb2(input integer number);
// begin
//     for(clogb2 = 0 ; number > 0 ; clogb2 = clogb2 + 1 )
//         number = number >> 1;
//     end
// endfunction

// integer BITWIDTH = clogb2(ITER);

integer i = 0;
 
reg [BITWIDTH-1:0] count [DEPTH-1:0];

always @(posedge clk) begin
    if (reset || acc_over) begin
        for (i = 0; i < DEPTH; i = i + 1) begin
            count[i] <= 'd0;
        end
    end
    else if (acc_en) begin
        count[data] <= count[data] + 1;
    end
    else begin
        count[data] <= count[data];
    end
end

generate
    genvar j;
    for(j=0;j<DEPTH;j=j+1) begin : OUT0
    assign histogram[BITWIDTH*(j+1) : BITWIDTH*j] = count[j];
    end
endgenerate

endmodule