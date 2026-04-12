module classical_ctrl_tb;

  // Parameters

  // Ports
  reg clk = 0;
  reg rst = 0;
  reg [31:0] i_q_measurement;
  reg [31:0] start_sig = 32'b0;
  reg [31:0] reg2 = 32'b0;
  reg [31:0] reg1 = 32'b0;
  wire q_time_write;
  wire q_time_sel;
  wire [1:0] q_reg_write;
  wire [31:0] q_inst;
  wire  end_sig;



  //internal wires
  wire pram_en;
  wire pram_rd_en ;
  wire [31:0] pram_addr ;
  wire [31:0] instruction ;
  wire inverted_clk ;
  wire dram_en ;
  wire dram_rd_en ;
  wire dram_wr_en ;
  wire [31:0] dram_addr ;
  wire [31:0] dram_din;
  wire [31:0] data_read ;



  classical_ctrl classical_ctrl_dut (
    .clk (clk ),
    .rst (rst ),
    .i_q_measurement (i_q_measurement ),
    .q_time_write (q_time_write ),
    .q_time_sel (q_time_sel ),
    .q_reg_write (q_reg_write ),
    .q_inst (q_inst ),
    .q_time_reg (q_time_reg ),
    .meas_rd_addr (meas_rd_addr ),
    .pram_en (pram_en ),
    .pram_rd_en (pram_rd_en ),
    .pram_addr (pram_addr ),
    .instruction (instruction ),
    .inverted_clk (inverted_clk ),
    .dram_en (dram_en ),
    .dram_rd_en (dram_rd_en ),
    .dram_wr_en (dram_wr_en ),
    .dram_addr (dram_addr ),
    .dram_din (dram_din ),
    .data_read (data_read ),
    .start_sig (start_sig ),
    .reg1 (reg1 ),
    .reg2 (reg2 ),
    .end_sig  ( end_sig)
  );

  pram pram_dut (
    .clk (clk ),
    .ena (pram_en ),
    .rea (pram_rd_en ),
    .reset (rst ),
    .addr (pram_addr ),
    .program_out(instruction)
  );

  bram bram_dut (
    .clk (inverted_clk ),
    .ena (dram_en ),
    .rea (dram_rd_en),
    .wea (dram_wr_en ),
    .reset (rst ),
    .addra (dram_addr ),
    .dia (dram_din ),
    .doa  ( data_read)
  );

  parameter PERIOD = 100;
  initial clk = 1'b1;
  always #(PERIOD/2.0) clk = !clk;
  
  initial begin
    begin
      rst =1'b1;
      start_sig = 32'b0;
      # (PERIOD*3);
      rst = 1'b0;
      start_sig <= 32'h00000001;
      # (PERIOD*25);
      $stop;
      $finish;
    end
  end

endmodule
