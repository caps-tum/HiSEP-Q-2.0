module tb_timed_fifo(
);

// Parameters
localparam  DEPTH = 8;
localparam  DATA_WIDTH = 26;

// Ports
reg clk = 0;
reg reset = 0;
reg [25:0] i_fifo_din;
reg i_fifo_we = 0;
reg [19:0] t_cnt;
wire [5:0] o_data;

timed_fifo #(
  .DEPTH(DEPTH ),
  .DATA_WIDTH (
      DATA_WIDTH )
)
timed_fifo_dut (
  .clk (clk ),
  .reset (reset ),
  .i_fifo_din (i_fifo_din ),
  .i_fifo_we (i_fifo_we ),
  .t_cnt (t_cnt ),
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
      i_fifo_din = 26'h0000202; //time = 8
      i_fifo_we = 1;
      #(PERIOD)
      i_fifo_we = 0;
      t_cnt = 5;
      #(PERIOD)
      t_cnt = 6;
      i_fifo_din = 26'h00002C6; //time = 15
      i_fifo_we = 1;
      #(PERIOD)
      t_cnt = 7;
      i_fifo_we = 0;
      #(PERIOD)
      t_cnt = 8;
      #(PERIOD)
      t_cnt = 9;
      #(PERIOD)
      t_cnt = 10;
      #(PERIOD)
      t_cnt = 11;
      #(PERIOD)
      t_cnt = 12;
      #(PERIOD)
      t_cnt = 13;
      #(PERIOD)
      t_cnt = 14;
      #(PERIOD)
      t_cnt = 15;
      #(2*PERIOD)
      $finish;
      end
    end


endmodule

