// Simple Dual-Port Block RAM with Two Clocks

// File: simple_dual_two_clocks.v

module dp_bram 
#(
	parameter integer N = 8, //mem_addr
	parameter integer B = 16 //mem_data
)
(clka,clkb,ena,enb,rea,reb,wea,web,addra,addrb,dia,dib,doa,dob);

	input clka,clkb,ena,enb,wea,web,rea,reb;
	input [N-1:0] addra,addrb;
	input [B-1:0] dia, dib;
	output reg [B-1:0] dob, doa;
	
	reg [B-1:0] ram [2**N-1:0];

always @(posedge clka)
	begin
		if (ena)
			begin
			if (wea) ram[addra] <= dia;
			end
	end

always @(posedge clka)
	begin
		if (ena & rea) doa <= ram[addra];
	end

always @(posedge clkb)
	begin
		if (enb)
			begin
			if (web)
				ram[addrb] <= dib;
			end
	end

always @(posedge clkb)
	begin
		if (enb & reb) dob <= ram[addrb];
	end
endmodule