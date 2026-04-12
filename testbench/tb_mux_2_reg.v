module mux_2_reg_tb;

  // Parameters

  // Ports
  reg   [31:0]  i_from_data_mem ;
  reg   [31:0]  i_from_alu      ;
  reg   [31:0]  i_from_q_measure;
  reg   [31:0]  i_from_comp_flg ;
  reg   [31:0]  i_from_inst_mem ;
  reg   [2:0]   sel_from_alu    ;
  wire  [31:0]  o_2_regfile     ;

  mux_2_reg
    mux_2_reg_dut (
      .i_from_data_mem  (i_from_data_mem )  ,
      .i_from_alu       (i_from_alu )       ,
      .i_from_q_measure (i_from_q_measure ) ,
      .i_from_comp_flg  (i_from_comp_flg )  ,
      .i_from_inst_mem  (i_from_inst_mem )  ,
      .sel_from_alu     (sel_from_alu )     ,
      .o_2_regfile      ( o_2_regfile)
    );

  
  parameter PERIOD = 100;
//  initial
//    clk = 1'b1;
//  always #(PERIOD/2.0) clk = !clk;
    
  integer i;

  initial
  begin
    begin
        // $monitor("@%0t", $time)
        // $monitor("sel=0x%0h", sel_from_alu)
        sel_from_alu      <= 3'b000 ;
        i_from_data_mem   <= $random;
        i_from_alu        <= $random;
        i_from_q_measure  <= $random;
        i_from_comp_flg   <= $random;
        i_from_inst_mem   <= $random;

        for (i=0; i<5; i=i+1)
          begin
          # (PERIOD)
          sel_from_alu <= i;  
          end

      $finish;
    end
  end
endmodule
