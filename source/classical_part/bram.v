`include "../parameter.v"
module bram (clk,ena,rea,wea,reset,addra,dia,doa);


  input 			clk;
  input       ena;
  input       rea;
  input 			wea;
  input 			reset;
  input [11-1:0]	addra;
  input [32-1:0]	dia;
  output reg [32-1:0]	doa;

  // Ram type.
  reg [32-1:0]    BRAM [0:2**4-1]; // pram addr 0-15

  initial
  begin
    $readmemh("./init_data_bram.mem", BRAM);
  end

  always @(posedge clk)
	begin
		if (ena)
			begin
			if (wea)
      BRAM[addra] <= dia;
			end
	end

always @(posedge clk)
	begin
		if (ena & rea) doa <= BRAM[addra];
	end

endmodule

