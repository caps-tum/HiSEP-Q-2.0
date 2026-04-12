module imm_gen_tb;

  // Parameters

  // Ports
  reg clk;
  reg [24:0] imm_src;
  reg [2:0] imm_sel;
  reg [31:0] i_regs;
  wire [31:0] imm_out;

  imm_gen 
  imm_gen_dut (
    .imm_src (imm_src ),
    .imm_sel (imm_sel ),
    .i_regs (i_regs ),
    .imm_out  ( imm_out)
  );

  parameter PERIOD = 100;
  initial clk = 1'b1;
  always #(PERIOD/2.0) clk = !clk;
  
    initial begin
      begin
      #(3*PERIOD);
      imm_src = 25'b000010110101011_0011011000;
      imm_sel = 3'b000; //ld/st
      i_regs = 32'd0;
      #(PERIOD)
      imm_src = 25'b00001_00101011010011011000;
      imm_sel = 3'b001; //ldi
      i_regs = 32'd0;
      #(PERIOD)
      imm_src = 25'b0000101100_110100000001001;
      imm_sel = 3'b010; //ldui
      i_regs = 32'd6;
      #(PERIOD)
      imm_src = 25'b000010110101011001101_1000;
      imm_sel = 3'b011; // br
      i_regs = 32'd0;
      #(PERIOD)
      imm_src = 25'b000010110101011_0011011000;
      imm_sel = 3'b100; //nop
      i_regs = 32'd0;
      #(PERIOD)
      imm_src = 25'b000010110101011_1010101101;
      imm_sel = 3'b000; //ld
      i_regs = 32'd0;
      #(PERIOD)
      $finish;
      end
    end
  


endmodule
