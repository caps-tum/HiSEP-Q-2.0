module Histo_top_tb;

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
  wire [NUM_Q-1:0] states1;
  wire [NUM_Q-1:0] states2;
  wire [NUM_Q-1:0] states3;
  wire [NUM_Q-1:0] states4;
  wire [COUNT_WIDTH-1:0] count1;
  wire [COUNT_WIDTH-1:0] count2;
  wire [COUNT_WIDTH-1:0] count3;
  wire [COUNT_WIDTH-1:0] count4;

  Histo_top 
  #(
    .NUM_Q(NUM_Q ),
    .TRAIL(TRAIL ),
    .COUNT_WIDTH(COUNT_WIDTH ),
    .ADDR_WIDTH (
        ADDR_WIDTH )
  )
  Histo_top_dut (
    .clk (clk ),
    .reset (reset ),
    .acc_en (acc_en ),
    .data (data ),
    .states1 (states1 ),
    .states2 (states2 ),
    .states3 (states3 ),
    .states4 (states4 ),
    .count1 (count1 ),
    .count2 (count2 ),
    .count3 (count3 ),
    .count4  ( count4)
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
      # (PERIOD*5);

      @(posedge clk);
      acc_en <= 1;
      data <= 2;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);

      
      @(posedge clk);
      acc_en <= 1;
      data <= 5;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      
      
      @(posedge clk);
      acc_en <= 1;
      data <= 8;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      

     
      @(posedge clk);
      acc_en <= 1;
      data <= 2;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      
     
      @(posedge clk);
      acc_en <= 1;
      data <= 2;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      

      @(posedge clk);
      acc_en <= 1;
      data <= 8;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      
      
      @(posedge clk);
      acc_en <= 1;
      data <= 1;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      

     
      @(posedge clk);
      acc_en <= 1;
      data <= 9;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      
     
      @(posedge clk);
      acc_en <= 1;
      data <= 2;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      
     
      @(posedge clk);
      acc_en <= 1;
      data <= 8;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      
     
      @(posedge clk);
      acc_en <= 1;
      data <= 5;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      

      
      @(posedge clk);
      acc_en <= 1;
      data <= 8;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      
      
      @(posedge clk);
      acc_en <= 1;
      data <= 1;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      
      @(posedge clk);
      acc_en <= 1;
      data <= 0;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      
      @(posedge clk);
      acc_en <= 1;
      data <= 8;
      @(posedge clk);
      acc_en <= 0;
      # (PERIOD*5);
      
      
      # (PERIOD*5);
      $finish;
    end
end

endmodule
