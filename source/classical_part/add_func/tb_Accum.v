module Accum_tb;

  // Parameters
  localparam  NUM_Q = 8;
  localparam  TRAIL = 10;
  localparam  COUNT_WIDTH = 4;
  localparam  ADDR_WIDTH = 4;

  // Ports
  reg clk = 0;
  reg reset = 0;
  reg acc_en = 0;
  reg [NUM_Q-1:0] data;
  wire [COUNT_WIDTH-1:0] count;
  wire sort_en;
  wire [ADDR_WIDTH-1:0] state_addr;
  wire [NUM_Q-1:0] states;

  Accum 
  #(
    .NUM_Q(NUM_Q ),
    .TRAIL(TRAIL ),
    .COUNT_WIDTH(COUNT_WIDTH ),
    .ADDR_WIDTH (
        ADDR_WIDTH )
  )
  Accum_dut (
    .clk (clk ),
    .reset (reset ),
    .acc_en (acc_en ),
    .data (data ),
    .count (count ),
    .sort_en (sort_en ),
    .state_addr (state_addr ),
    .states  ( states)
  );

  parameter PERIOD = 100;
  initial clk = 1'b1;
  always #(PERIOD/2.0) clk = !clk;

  initial begin
    begin
      reset = 1'b1;
      # (PERIOD);
      reset = 1'b0;
      
      @(posedge clk);
      acc_en <= 1;
      data <= 1;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);

      @(posedge clk);
      acc_en <= 1;
      data <= 2;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);

      
      @(posedge clk);
      acc_en <= 1;
      data <= 5;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      
      
      @(posedge clk);
      acc_en <= 1;
      data <= 8;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      

     
      @(posedge clk);
      acc_en <= 1;
      data <= 2;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      
     
      @(posedge clk);
      acc_en <= 1;
      data <= 2;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      

      @(posedge clk);
      acc_en <= 1;
      data <= 8;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      
      
      @(posedge clk);
      acc_en <= 1;
      data <= 1;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      

     
      @(posedge clk);
      acc_en <= 1;
      data <= 9;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      
     
      @(posedge clk);
      acc_en <= 1;
      data <= 2;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      
     
      @(posedge clk);
      acc_en <= 1;
      data <= 8;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      
     
      @(posedge clk);
      acc_en <= 1;
      data <= 5;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      

      
      @(posedge clk);
      acc_en <= 1;
      data <= 8;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      
      
      @(posedge clk);
      acc_en <= 1;
      data <= 1;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      
      @(posedge clk);
      acc_en <= 1;
      data <= 0;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      
      @(posedge clk);
      acc_en <= 1;
      data <= 8;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*2);
      
      
      # (PERIOD*2);
      $finish;
    end
end
endmodule
