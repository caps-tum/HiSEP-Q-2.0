module pram (clk,ena,rea,reset,addr,program_out);


  input 			clk;
  input       ena;
  input 			rea;
  input 			reset;
  input [11-1:0]	addr;
  output [32-1:0]	program_out;

  // Ram type.
  reg [32-1:0]    PRAM [0:2**5-1]; // pram addr 0-31
  reg [32-1:0]	program_out;

  initial
  begin
    $readmemh("./init_instr.mem", PRAM);
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      program_out <= 32'h0;
    end
    else if (ena & rea)
    begin
      program_out <= PRAM[addr];
    end
  end

endmodule
