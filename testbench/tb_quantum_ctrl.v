module tb_quantum_ctrl;

  // Parameters
  localparam  NCH = 100;
  localparam  DEPTH = 32;
  localparam  DATA_WIDTH = 20;

  // Ports
  reg clk = 0;
  reg reset = 0;
  reg [31:0] q_instruction= 32'b0;
  reg [31:0] i_register= 32'b0;
  reg q_vliw = 0;
  reg q_slm = 0;
  reg q_time_sel = 0;
  reg q_time_write = 0;
  reg [1:0] q_reg_write = 2'b00;
  reg [19:0] t_cnt = 0;
  wire [20*NCH-1 : 0] abs_time;
  wire [NCH-1 : 0] fifo_wr_en;
  wire [6*NCH-1 : 0] fifo_wd;
  wire [NCH-1 : 0] err_bit;

  quantum_ctrl #(
    .NCH(NCH ),
    .DEPTH(DEPTH ),
    .DATA_WIDTH (
        DATA_WIDTH )
  )
  quantum_ctrl_dut (
    .clk (clk ),
    .reset (reset ),
    .q_instruction (q_instruction ),
    .i_register (i_register ),
    .q_vliw (q_vliw ),
    .q_slm (q_slm ),
    .q_time_sel (q_time_sel ),
    .q_time_write (q_time_write ),
    .q_reg_write (q_reg_write ),
    .t_cnt (t_cnt ),
    .abs_time (abs_time ),
    .fifo_wr_en (fifo_wr_en ),
    .fifo_wd (fifo_wd ),
    .err_bit  ( err_bit)
  );

parameter PERIOD = 200;
initial clk = 1'b1;
always #(PERIOD/2.0) clk = !clk;

always #(PERIOD) t_cnt <= t_cnt+1;

initial begin
  begin
    reset = 1'b1;
    # (PERIOD);
    reset = 1'b0;
    @(posedge clk);
    q_vliw <= 1'b1;
    q_instruction <= 32'b0_111000_10001_0000000000000000_0101; //SMSOL  s17 {0,2,4,6,8,10,12,96,98}
    q_reg_write <= 2'b01;
    @(posedge clk);
    q_instruction <= 32'd0; //SMSOL  s7 {0,2,4,6,8,10,12,96,98}
    q_reg_write <= 2'b00;
    @(posedge clk);
    q_instruction <= 32'd0; //SMSOL  s7 {0,2,4,6,8,10,12,96,98}
    q_reg_write <= 2'b00;
    @(posedge clk);
    q_instruction <= 32'b0000_0000_0000_0000_0001_0101_0101_0101; //SMSOL  s17 {0,2,4,6,8,10,12,96,98}
    q_reg_write <= 2'b00;
    @(posedge clk);
    q_instruction <= 32'b0101100_00001_000000_0000001_0000011; //SITO  t1 {(1,3)} / SMIT t0 8
    q_reg_write <= 2'b10;
    q_vliw <= 1'b0;
    @(posedge clk);
    q_reg_write <= 2'b00;
    q_time_sel <= 1'b1; //imm
    q_instruction <= 32'b0100000_00000_00000000000000001111; //QWAIT 15
    q_time_write  <= 1'b1;
    @(posedge clk);
    q_time_write  <= 1'b0;
    q_time_sel <= 1'b0; //imm
    q_instruction <= 32'b1_000000101_10001_000000000_00000_000; //Y90 s7
    @(posedge clk);
    i_register <= 20;
    q_instruction <= 32'b0100001_00000_00000000000000001111; //QWAITR 20
    q_time_write  <= 1'b1;
    q_time_sel <= 1'b0; //reg
    @(posedge clk);
    q_time_write  <= 1'b0;
    q_instruction <= 32'b1_000000010_10001_000001000_00001_010; //X90 s7, CNOT t0, pi<=2
    # (PERIOD*10);
    $finish;
  end
end
//****************************test results*******************************//

//decoder pass
//time manager pass
//control_lut pass
//reg s/t pass
// reg_decoder ok
//combination ok
//dispatch need refinement
//2 clk delay

endmodule
