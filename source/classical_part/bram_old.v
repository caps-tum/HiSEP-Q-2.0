module bram (clk,wea,addra,dia,doa);


input 			clk;
input 			wea;
input [32-1:0]	addra;
input [32-1:0]	dia;
output [32-1:0]	doa;

// Ram type.
reg [32-1:0]    RAM [0:2**32-1];
reg [32-1:0]	doa;

always @(posedge clk)
begin
    if (wea) begin
    	RAM[addra] <= dia;
	end
	else begin
		doa <= RAM[addra];
    end
end

endmodule