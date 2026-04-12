module tb_main_ctrl;


  // Ports
  reg clk = 0;
  reg reset = 0;
  reg [31:0] i_debug_inst = 0;
  reg pram_we = 0;
  reg [31:0] start_sig = 32'b0;
  reg [31:0] reg2 = 32'b0;
  reg [31:0] reg1 = 32'b0;
  reg [19:0] t_cnt = 0;
  reg meas_wr_data = 0;
  reg meas_wr_valid = 0;
  wire [20*100-1 : 0] abs_time;
  wire [100-1 : 0] fifo_wr_en;
  wire [6*100-1 : 0] fifo_wd;
  wire [100-1 : 0] err_bit;
  wire [31:0] end_sig;
  
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

main_ctrl main_ctrl_dut (
    .clk (clk ),
    .reset (reset ),
    .t_cnt (t_cnt ),
    .meas_wr_data (meas_wr_data ),
    .meas_wr_valid (meas_wr_valid ),
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
    .end_sig (end_sig ),
    .abs_time (abs_time ),
    .fifo_wr_en (fifo_wr_en ),
    .fifo_wd (fifo_wd ),
    .err_bit  ( err_bit)
  );


  pram pram_dut (
    .clk (clk ),
    .ena (pram_en ),
    .rea (pram_rd_en ),
    .reset (reset ),
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
  
  always @(posedge clk) begin
    if(reset) begin
        t_cnt <= 'd0;
    end
    else begin
        t_cnt <= t_cnt + 1'b1;
    end
    
  end
  
  initial begin
    begin
      reset <=1'b1;
      # (PERIOD*3);
      reset = 1'b0;
      start_sig <= 32'h00000001;
      # (PERIOD*30);
      $stop;
      $finish;
    end
  end

endmodule
