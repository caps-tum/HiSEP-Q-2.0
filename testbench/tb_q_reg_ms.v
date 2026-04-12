module tb_q_reg_ms(

);

  // Ports
  reg clk = 0;
  reg reset = 0;
  reg [4:0] wr_addr;
  reg [4:0] rd_addr;
  reg wr_data = 0;
  reg wr_en = 0;
  reg wr_valid = 0;
  wire [32:0] measure_data;

  q_reg_ms  q_reg_ms_dut(
    .clk (clk ),
    .reset (reset ),
    .wr_addr (wr_addr ),
    .rd_addr (rd_addr ),
    .wr_data (wr_data ),
    .wr_en (wr_en ),
    .wr_valid (wr_valid ),
    .measure_data  ( measure_data)
  );

parameter PERIOD = 100;
initial clk = 1'b1;
always #(PERIOD/2.0) clk = !clk;

initial begin
    begin
    #(PERIOD) reset  =  0;
    #(PERIOD) reset  =  1;
    #(PERIOD) reset  =  0;
    #(3*PERIOD);
    wr_addr = 5'd1;
    wr_en   = 1'b1;
    #(PERIOD)
    wr_en   = 1'b0;
    wr_addr = 5'd0;  
    #(PERIOD)
    wr_valid = 1'b1;
    wr_data  = 1'b1;
    #(PERIOD)
    wr_valid = 1'b0;
    wr_data  = 1'b0;
    #(PERIOD)
    rd_addr = 5'd1;
    #(2*PERIOD)
    $finish;
    end
  end

endmodule