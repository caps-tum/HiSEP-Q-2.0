module dispatch_tb;

  // Parameters

  // Ports
  reg clk = 0;
  reg rest_n = 0;
  reg [55:0] comb;
  reg  q_mod_sel = 0;
  wire [19:0] abs_time;
  wire [1:0] index_type_q0;
  wire fifo_wr_q0;
  wire [3:0] op_q0;
  wire err_q0;
  wire [1:0] index_type_q1;
  wire fifo_wr_q1;
  wire [3:0] op_q1;
  wire err_q1;
  wire [1:0] index_type_q2;
  wire fifo_wr_q2;
  wire [3:0] op_q2;
  wire err_q2;
  wire [1:0] index_type_q3;
  wire fifo_wr_q3;
  wire [3:0] op_q3;
  wire err_q3;
  wire [1:0] index_type_q4;
  wire fifo_wr_q4;
  wire [3:0] op_q4;
  wire err_q4;
  wire [1:0] index_type_q5;
  wire fifo_wr_q5;
  wire [3:0] op_q5;
  wire err_q5;
  wire [1:0] index_type_q6;
  wire fifo_wr_q6;
  wire [3:0] op_q6;
  wire err_q6;

  dispatch 
  dispatch_dut (
    .clk (clk ),
    .rest_n (rest_n ),
    .comb (comb ),
    .q_mod_sel (q_mod_sel ),
    .abs_time (abs_time ),
    .index_type_q0 (index_type_q0 ),
    .fifo_wr_q0 (fifo_wr_q0 ),
    .op_q0 (op_q0 ),
    .err_q0 (err_q0 ),
    .index_type_q1 (index_type_q1 ),
    .fifo_wr_q1 (fifo_wr_q1 ),
    .op_q1 (op_q1 ),
    .err_q1 (err_q1 ),
    .index_type_q2 (index_type_q2 ),
    .fifo_wr_q2 (fifo_wr_q2 ),
    .op_q2 (op_q2 ),
    .err_q2 (err_q2 ),
    .index_type_q3 (index_type_q3 ),
    .fifo_wr_q3 (fifo_wr_q3 ),
    .op_q3 (op_q3 ),
    .err_q3 (err_q3 ),
    .index_type_q4 (index_type_q4 ),
    .fifo_wr_q4 (fifo_wr_q4 ),
    .op_q4 (op_q4 ),
    .err_q4 (err_q4 ),
    .index_type_q5 (index_type_q5 ),
    .fifo_wr_q5 (fifo_wr_q5 ),
    .op_q5 (op_q5 ),
    .err_q5 (err_q5 ),
    .index_type_q6 (index_type_q6 ),
    .fifo_wr_q6 (fifo_wr_q6 ),
    .op_q6 (op_q6 ),
    .err_q6  ( err_q6)
  );

initial begin
  begin
    rest_n <= 1'b1;
    # 10;
    rest_n <= 1'b0;
    # 10;
    comb <= 56'b11111111111111111111_0101_00011011000110_1010_00000000000000;
    # 10;
    comb <= 56'b11111111111111111111_0101_00000000000000_1010_00011011000110;
    # 10;
    comb <= 56'b11111111111111111111_0101_10101010101010_1010_00010101000101;
    $finish;
  end
end

  always
    #5  clk = ! clk ;

endmodule
