module sorter_tb;

  // Parameters
  localparam integer NCH = 4;

  // Ports
  reg clk = 0;
  reg reset = 0;
  reg [NCH -1:0] data;
  reg enable = 0;
  wire [NCH -1:0] top_0;
  wire [NCH -1:0] top_1;
  wire [NCH -1:0] top_2;
  wire [NCH -1:0] top_3;

  sorter #(.NCH (
        NCH ))
  sorter_dut (
    .clk (clk ),
    .reset (reset ),
    .data (data ),
    .enable (enable ),
    .top_0 (top_0 ),
    .top_1 (top_1 ),
    .top_2 (top_2 ),
    .top_3  ( top_3)
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
      data <= 1;
      enable<=1;
      @(posedge clk);
      data <= 1;
      enable<=0;
      # (PERIOD*4);

      @(posedge clk);
      data <= 3;
      enable<=1;
      @(posedge clk);
      data <= 3;
      enable<=0;
      # (PERIOD*4);

      @(posedge clk);
      data <= 5;
      enable<=1;
      @(posedge clk);
      data <= 5;
      enable<=0;
      # (PERIOD*4);

      @(posedge clk);
      data <= 6;
      enable<=1;
      @(posedge clk);
      data <= 6;
      enable<=0;
      # (PERIOD*4);

      @(posedge clk);
      data <= 9;
      enable<=1;
      @(posedge clk);
      data <= 9;
      enable<=0;
      # (PERIOD*4);

      @(posedge clk);
      data <= 8;
      enable<=1;
      @(posedge clk);
      data <= 8;
      enable<=0;
      # (PERIOD*4);

      @(posedge clk);
      data <= 1;
      enable<=1;
      @(posedge clk);
      data <= 1;
      enable<=0;
      # (PERIOD*4);
      $finish;
    end
  end
endmodule
