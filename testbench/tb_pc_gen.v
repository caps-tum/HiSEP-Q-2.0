module pc_gen_tb;

  // Ports
  reg clk = 0;
  reg resetn = 0;
  reg i_sel_pc = 0;
  reg [31:0] i_pc_from_alu;
  wire [31:0] o_pc;

  // Parameters
  parameter PERIOD = 100;
  initial
    clk = 1'b1;
  always #(PERIOD/2.0) clk = !clk;

  pc_gen
    pc_gen_dut (
      .clk (clk),
      .resetn (resetn ),
      .i_sel_pc (i_sel_pc ),
      .i_pc_from_alu (i_pc_from_alu ),
      .o_pc (o_pc )
    );

  initial
  begin
    begin
      #(PERIOD);
      resetn = 1'b1;

      #(PERIOD);
      resetn = 1'b0;
      i_sel_pc = 1'b0;
      i_pc_from_alu = 32'h0000_0001;

      #(PERIOD);
      i_sel_pc = 1'b1;
      i_pc_from_alu = 32'h0000_000f;

      #(PERIOD);
      i_sel_pc = 1'b0;
      i_pc_from_alu = 32'h0000_00ff;

      #(PERIOD);
      i_sel_pc = 1'b1;
      i_pc_from_alu = 32'h0000_0fff;

      #(PERIOD);
      i_sel_pc = 1'b0;
      i_pc_from_alu = 32'h0000_ffff;

      $finish;
    end
  end

endmodule
