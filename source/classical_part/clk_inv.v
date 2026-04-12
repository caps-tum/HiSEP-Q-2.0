module clk_inverter(
    input wire clk,
    input wire reset,
    output reg inverted_clk = 1'b0
  );
  
  reg inverted_clk_p = 1'b0;
  reg inverted_clk_n = 1'b0;

  always @(negedge clk)
  begin
    inverted_clk_n <= ~inverted_clk_n;
  end
  
  always @(posedge clk)
  begin
    inverted_clk_p <= ~inverted_clk_p;
  end
  
  always@(*)
  begin
  if(reset) begin
    inverted_clk = 1'b0;
  end
  else begin
    inverted_clk = inverted_clk_n ^ inverted_clk_p;
  end
  end

endmodule

