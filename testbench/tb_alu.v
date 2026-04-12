module alu_tb;

  // Parameters

  // Ports
  reg [31: 0] op_A;
  reg [31: 0] op_B;
  reg [3: 0] ALU_op;
  wire [31: 0] result;
  wire [9:0] comp_flag;
  reg clk = 0;

  alu 
  alu_dut (
    .op_A (op_A ),
    .op_B (op_B ),
    .ALU_op (ALU_op ),
    .result  ( result),
	.comp_flag(comp_flag)
  );


  parameter PERIOD = 100;
    initial clk = 1'b1;
    always #(PERIOD/2.0) clk = !clk;

  initial begin
	// Addition.
	#(PERIOD);
	ALU_op	<= 3'b001;
	op_A	<= 53;
	op_B	<= -38;

	#(PERIOD);
	op_A	<= 530;
	op_B	<= -3000;

	// Substraction.
	#(PERIOD);
	ALU_op	<= 3'b010;
	op_A	<= 583;
	op_B	<= 520;

    // Substraction.
	#(PERIOD);
	ALU_op	<= 3'b010;
	op_A	<= 8'h03;
	op_B	<= 8'b11111110;

	// and
	#(PERIOD);
	ALU_op	<= 3'b011;
	op_A	<= 12;
	op_B	<= 7;

    	// or
	#(PERIOD);
	ALU_op	<= 3'b100;
	op_A	<= 8'h48;
	op_B	<= 8'h12;

    	// not
	#(PERIOD);
	ALU_op	<= 3'b101;
	op_A	<= 0;
	op_B	<= 7;

    	// xor
	#(PERIOD);
	ALU_op	<= 3'b110;
	op_A	<= 8'h96;
	op_B	<= 8'h5D;

    // cmp -ok 0110101010
	#(PERIOD);
	ALU_op	<= 3'b111;
	op_A	<= 12;
	op_B	<= 7;
	// cmp -
	#(PERIOD);
	ALU_op	<= 3'b111;
	op_A	<= -58;
	op_B	<= -9;
	    	// cmp
	#(PERIOD);
	ALU_op	<= 3'b111;
	op_A	<= 200;
	op_B	<= 87;
	    	// cmp
	#(PERIOD);
	ALU_op	<= 3'b111;
	op_A	<= -256;
	op_B	<= -255;
	    	// cmp
	#(PERIOD);
	ALU_op	<= 3'b111;
	op_A	<= 15;
	op_B	<= -7;
	    	// cmp
	#(PERIOD);
	ALU_op	<= 3'b111;
	op_A	<= 32'hFFFFFFF1;
	op_B	<= 32'hFFFFFFF6;
	    	// cmp
	#(PERIOD);
	ALU_op	<= 3'b111;
	op_A	<= 32'h7FFFFFFF;
	op_B	<= 32'h7FFFFFF5;
	#(PERIOD);
	ALU_op	<= 3'b111;
	op_A	<= 32'h70FFFFFF;
	op_B	<= 32'h70FFFFFF;
	    	// cmp
    #100
    $finish;
end


endmodule
//tb pass