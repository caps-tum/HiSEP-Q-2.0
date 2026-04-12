module tb_time_control;

  // Ports
  reg clk = 0;
  reg reset = 0;
  reg [19:0] t_cnt;
  wire fifo_rd_en;
  reg [25:0] fifo_data;
  reg fifo_empty = 1;
  wire [5:0] o_data;

  time_controller time_controller_dut (
    .clk (clk ),
    .reset (reset ),
    .t_cnt (t_cnt ),
    .fifo_rd_en (fifo_rd_en ),
    .fifo_data (fifo_data ),
    .fifo_empty (fifo_empty ),
    .o_data  ( o_data)
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
      fifo_empty = 1'b0;
      #(PERIOD)
      fifo_empty = 1'b1;
      t_cnt = 5;
      fifo_data = 26'h0000202;
      #(PERIOD)
      t_cnt = 6;
      fifo_data = 26'h0000202;  
      #(PERIOD)
      t_cnt = 7;
      fifo_data = 26'h0000202;
      #(PERIOD)
      t_cnt = 8;
      fifo_data = 26'h0000202;
      #(2*PERIOD)
      $finish;
      end
    end
endmodule
