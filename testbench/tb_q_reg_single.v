module tb_q_reg_single();
  // Ports
reg clk = 0;
reg reset = 0;
reg [4:0] wr_addr;
reg q_slm = 0;
reg long_ind = 0;
reg [3:0]  Si_offset;
reg [4:0] rd_addr1;
reg [4:0] rd_addr2;
reg [7:0] wr_data_s;
reg [31:0] wr_data_l;
reg [1:0] wr_en;
wire [7:0] sd_data1_s;
wire [7:0] sd_data2_s;
wire [99:0] sd_data1_l;
wire [99:0] sd_data2_l;
wire [3:0] sd_offset1;
wire [3:0] sd_offset2;

q_reg_single q_reg_single_dut (
  .clk (clk ),
  .reset (reset ),
  .wr_addr (wr_addr ),
  .q_slm(q_slm),
  .long_ind (long_ind ),
  .rd_addr1 (rd_addr1 ),
  .rd_addr2 (rd_addr2 ),
  .Si_offset(Si_offset),
  .wr_data_s (wr_data_s ),
  .wr_data_l (wr_data_l ),
  .wr_en (wr_en ),
  .sd_data1_s (sd_data1_s ),
  .sd_data2_s (sd_data2_s ),
  .sd_data1_l (sd_data1_l ),
  .sd_data2_l  ( sd_data2_l),
  .sd_offset1(sd_offset1),
  .sd_offset2(sd_offset2)
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
    wr_data_s = 8'd0;
    wr_data_l = 32'd0;
    wr_en = 2'b0;
    # (PERIOD*2);
    reset = 1'b0;
    @(posedge clk) //write normal
    wr_addr = 5'd1;
    wr_en   = 1'b1;
    wr_data_s = 8'b01110111;
    @(posedge clk) //do not write
    wr_en   = 1'b0;
    wr_addr = 5'd0;
    wr_data_s = 8'b01110111 ;
    @(posedge clk) 
    wr_en   <= 1'b0;
    wr_addr <= 5'd2;
    q_slm <= 1'b1;
    Si_offset <= 'd3;
    wr_data_s <= 8'b01110111 ;
    rd_addr1 <= 'd1;
    @(posedge clk)
    q_slm <= 0;
    long_ind <= 1'b1;    
    wr_en   <= 1'b1;
    wr_addr <= 5'd18;
    wr_data_l <= 32'h0001;
    @(posedge clk)
    wr_en   <= 1'b0;
    wr_addr <= 5'd0;
    wr_data_l <= 32'h0000;
    @(posedge clk)
    wr_en   <= 1'b0;
    wr_addr <= 5'd0;
    wr_data_l <= 32'h0000;
    @(posedge clk)
    wr_en   <= 1'b0;
    wr_addr <= 5'd0;
    wr_data_l <= 32'h0011;
    @(posedge clk)
    long_ind <= 1'b0; 
    wr_en   <= 1'b0;
    rd_addr1 <= 'd2;
    @(posedge clk) 
    wr_en   = 1'b1;
    wr_addr = 5'd2;
    q_slm = 1'b0;
    Si_offset = 'd6;
    wr_data_s = 8'b01111000 ;
    rd_addr1 = 'd1;
    @(posedge clk)
    wr_en   = 1'b0;
    rd_addr2 = 'd18;
    @(posedge clk)
    wr_en   = 1'b0;
    rd_addr1 = 'd2;
    #(2*PERIOD)
    $finish;
    end
  end


endmodule