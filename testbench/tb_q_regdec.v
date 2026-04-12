module q_reg_decoder_tb;

  // Parameters

  // Ports
reg clk;
  reg [7:0] sreg_data_s;
  reg [99:0] sreg_data_l;
  reg [13:0] treg_data_s;
  reg [104:0] treg_data_l;
  reg [3:0] reg_off;
  reg [4:0] reg_read_addr;
  reg [1:0] q_reg_sel;
  wire [199:0] q_op_out;

  q_reg_decoder q_reg_decoder_dut (
    .sreg_data_s (sreg_data_s ),
    .sreg_data_l (sreg_data_l ),
    .treg_data_s (treg_data_s ),
    .treg_data_l (treg_data_l ),
    .reg_off (reg_off ),
    .reg_read_addr (reg_read_addr ),
    .q_reg_sel (q_reg_sel ),
    .q_op_out  ( q_op_out)
  );

  parameter PERIOD = 100;
  initial
    clk = 1'b1;
  always #(PERIOD/2.0) clk = !clk;

  initial
  begin
    // write test
    begin
    # (PERIOD);
    sreg_data_s = 8;
    sreg_data_l = 1016;
    treg_data_s = 16;
    treg_data_l = 2017;
    reg_off    = 3;
    reg_read_addr = 0;
    q_reg_sel  = 2'b01;

    #(PERIOD)
    sreg_data_s = 8;
    sreg_data_l = 1016;
    treg_data_s = 16;
    treg_data_l = 2017;
    reg_off    = 3;
    reg_read_addr = 18;
    q_reg_sel  = 2'b01;

    #(PERIOD)
    sreg_data_s = 8;
    sreg_data_l = 1016;
    treg_data_s = 16;
    treg_data_l = 2017;
    reg_off    = 0;
    reg_read_addr = 0;
    q_reg_sel  = 2'b01;
    #(PERIOD)
    sreg_data_s = 8;
    sreg_data_l = 1016;
    treg_data_s = 16;
    treg_data_l = 2017;
    reg_off    = 3;
    reg_read_addr = 0;
    q_reg_sel  = 2'b10;
    #(PERIOD)
    sreg_data_s = 8;
    sreg_data_l = 1016;
    treg_data_s = 16;
    treg_data_l = 105'h1FC_0000_0000_0000_0000_0000_07e1;//all 7 valid
    reg_off    = 3;
    reg_read_addr = 20;
    q_reg_sel  = 2'b10;
    
    #(PERIOD)
    sreg_data_s = 8;
    sreg_data_l = 1016;
    treg_data_s = 16;
    treg_data_l = 105'h1020000000000000000000007e1;//0 and 3 pair valid
    reg_off    = 3;
    reg_read_addr = 20;
    q_reg_sel  = 2'b10;
    
    #(PERIOD)
    sreg_data_s = 8;
    sreg_data_l = 1016;
    treg_data_s = 16;
    treg_data_l = 2017;
    reg_off    = 0;
    reg_read_addr = 5;
    q_reg_sel  = 2'b01;

    #(2*PERIOD)
    $finish;
    end
  end



endmodule
