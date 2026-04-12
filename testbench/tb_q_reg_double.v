module tb_q_reg_double();
  // Ports
reg clk = 0;
reg reset = 0;
reg [4:0] wr_addr;
reg long_ind = 0;
reg [4:0] rd_addr1;
reg [4:0] rd_addr2;
reg [13:0] wr_data_s;
reg [31:0] wr_data_l;
reg [1:0] wr_en;
wire [13:0] sd_data1_s;
wire [13:0] sd_data2_s;
wire [104:0] sd_data1_l;
wire [104:0] sd_data2_l;

q_reg_double q_reg_double_dut (
  .clk (clk ),
  .reset (reset ),
  .wr_addr (wr_addr ),
  .long_ind (long_ind ),
  .rd_addr1 (rd_addr1 ),
  .rd_addr2 (rd_addr2 ),
  .wr_data_s (wr_data_s ),
  .wr_data_l (wr_data_l ),
  .wr_en (wr_en ),
  .sd_data1_s (sd_data1_s ),
  .sd_data2_s (sd_data2_s ),
  .sd_data1_l (sd_data1_l ),
  .sd_data2_l  ( sd_data2_l)
);

parameter PERIOD = 100;
  initial
    clk = 1'b1;
  always #(PERIOD/2.0) clk = !clk;

  initial
  begin
    // write test
    begin
    reset = 1'b1;
    rd_addr1 = 5'b00000;
    rd_addr2 = 5'b00000;
    wr_addr = 5'b00000;
    wr_data_s = 14'd0;
    wr_data_l = 32'd0;
    wr_en = 2'b0;
    # (PERIOD*2);
    reset = 1'b0;
    #(PERIOD)
    wr_addr = 5'd1;
    wr_en   = 2'b10;
    wr_data_s = 14'b0000011_0000001;
    #(PERIOD)
    wr_en   = 2'b10;
    wr_addr = 5'd0;
    wr_data_s = 14'b0000011_1000001;
    #(PERIOD)
    wr_en   = 2'b01;
    wr_addr = 5'd2;
    wr_data_s = 14'b0000011_1000001;
    rd_addr1 = 'd1;
    #(PERIOD)
    //long instruction
    long_ind = 1'b1;    
    wr_en   = 2'b10;
    wr_addr = 5'd10;
    wr_data_l = 32'h0001;
    #(PERIOD)
    wr_en   = 1'b1;
    wr_addr = 5'd0;
    wr_data_l = 32'h0000;
    #(PERIOD)
    wr_en   = 1'b1;
    wr_addr = 5'd0;
    wr_data_l = 32'h0000;
    #(PERIOD)
    wr_en   = 1'b1;
    wr_addr = 5'd0;
    wr_data_l = 32'h0011;
    #(PERIOD)
    wr_en   = 1'b0;
    rd_addr2 = 'd10;
    #(2*PERIOD)
    $finish;
    end
  end


endmodule