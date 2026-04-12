`include "../parameter.v"
//this is the top level of classical part, which will deal with all classical instructions. details can be found in the block diagram
//high level reset
module classical_ctrl(
    input clk,
    input rst,
    input [31:0] i_q_measurement,
    output q_time_write,
    output q_time_sel,
    output [1:0] q_reg_write, //[01]for Si [10]for Ti
    output q_vliw,
    output q_slm,
    output [31:0] q_inst,      //quantum instructions
    output [31:0] q_time_reg,
    output [4:0] meas_rd_addr,

    //from axi slaves
    //output pram_clk_inv, pram clk is normal clk
		output pram_en,
		output pram_rd_en,
		output [11-1 :0]	pram_addr, //pram_addr
		input	 [32-1 :0]	instruction, //pram_out

    output inverted_clk, //to dram
		output dram_en		,
		output dram_rd_en		,
    output dram_wr_en     ,
		output [11-1 :0]	dram_addr	,
    output [32-1 :0]	dram_din	,
		input	 [32-1 :0]	data_read	, //dram_out

    input  [32-1 : 0]  start_sig, //
    input  [32-1 :0]   reg1, //later extension
    input  [32-1 :0]   reg2,
    output [32-1 : 0]  end_sig
  );

  //connecting with PC
  wire [31:0] next_pc;
  //from pram
  //wire [31:0] instruction;
  //decode instruction
  wire [4:0] rd_addr = instruction[24:20];
  wire [4:0] rs_addr = instruction[19:15];
  wire [4:0] rt_addr = instruction[14:10];
  wire [5:0] opcode  = instruction[30:25];
  wire q_inst_sign   = instruction[31];
  wire [3:0] comp_addr = instruction[3:0];

  //from ctrl
  wire [3:0] ALU_op;
  wire reg_write;
  wire mem_write;
  wire branch;             // PC select
  wire [2:0] reg_sel;     //mem, imm, comp, measure, alu
  wire [2:0] imm_sel;     //M(LD/ST), LDI, LDUI�? BR
  wire sel_mux_b;
  //comp to control
  wire [9:0]comp_from_alu;
  wire [11:0]comp_to_ctrl;
  //register file
  wire [31:0] wr_data;
  wire [31:0] rt_data;
  wire [31:0] rs_data;

  //alu
  wire [31:0] imm;
  wire [31:0] alu_a;
  wire [31:0] alu_b;
  wire [31:0] alu_out;
  //bram
  //wire [31:0] data_read;
  //wire inverted_clk;

  wire s_vliw;

  wire time_reg_en;

  reg end_reg; //end instruction 0-001000-00000

  always @(posedge clk ) begin
    if (rst) end_reg <= 1'b0;
    else if (opcode == 6'b001000) end_reg <= 1'b1;
    else end_reg <= end_reg;
  end

  pc_gen pc_gen_i (
           .clk (clk ),
           .reset (rst),
           .start_sig(start_sig[0]),
           .end_sig(end_reg),
           .i_sel_pc (branch),
           .i_pc_from_alu (alu_out),
           .o_pc (next_pc)
         );

  reg_file reg_file_i (
             .clk (clk ),
             .reset (rst),
             .rs_addr (rs_addr),
             .rt_addr (rt_addr),
             .wr_addr (rd_addr),
             .wr_data (wr_data),
             .wr_en (reg_write),
             .rs_data (rs_data),
             .rt_data (rt_data)
           );

  control control_i (
            .reset (rst),
            .opcode (opcode),
            .q_inst_sign (q_inst_sign),
            .comp_flag (comp_to_ctrl),
            .comp_addr(comp_addr),
            .ALU_op (ALU_op ),
            .reg_write (reg_write ),
            .mem_write (mem_write ),
            .branch (branch ),
            .q_time_write (q_time_write ),
            .q_time_sel (q_time_sel ),
            .q_vliw (s_vliw),
            .q_slm (q_slm),
            .q_reg_write (q_reg_write ),
            .reg_sel (reg_sel ),
            .imm_sel  ( imm_sel),
            .o_time_reg_en(time_reg_en),
            .sel_mux_b (sel_mux_b)
          );
  //in ISA, ST,LD uses Rt data plus immediate date, so they should be seperated.
  mux_alu_a mux_alu_a_i (
              .i_reg (rt_data),
              .i_pc (next_pc),
              .i_branch_sel (branch),
              .o_alu_a  (alu_a)
            );

  mux_alu_b mux_alu_b_i(
              .i_reg (rs_data ),
              .i_imm (imm ),
              .i_imm_sel (sel_mux_b),
              .o_alu_a  (alu_b)
            );

  alu alu_i(
        .op_A (alu_a ),
        .op_B (alu_b ),
        .ALU_op (ALU_op ),
        .result (alu_out),
        .comp_flag (comp_from_alu)
      );

  imm_gen imm_gen_i (
            .imm_src (instruction[24:0]),
            .imm_sel (imm_sel ),
            .i_regs (rs_data),
            .imm_out (imm)
          );

  mux_2_reg mux_2_reg_i (
              .i_from_data_mem (data_read ),
              .i_from_alu (alu_out ),
              .i_from_q_measure (i_q_measurement),
              .i_from_comp_flg ({{20{1'b0}},comp_to_ctrl}),
              .i_from_imm (imm ),
              .sel_from_ctrl(reg_sel),
              .o_2_regfile  (wr_data)
            );

  clk_inverter clk_inverter_i (
                 .clk (clk ),
                 .reset (reset ),
                 .inverted_clk  ( inverted_clk)
               );

  comp_reg comp_reg_i (
             .clk (clk),
             .reset (rst),
             .i_comp_flag (comp_from_alu ),
             .ALU_op (ALU_op),
             .o_comp_reg (comp_to_ctrl)
           );

  //counter for generating long instruction indications

  reg [2:0] cnt;
    
  always@(posedge clk)
    if(rst)begin
      cnt <= 'd5;
    end
           
    else begin
      if(s_vliw) cnt <= 'd1;
      else if (cnt < 3'b101) cnt <= cnt + 1'b1;
      else cnt <= cnt;
  end
           
  assign q_vliw  = ((cnt < 3'b100 & cnt > 3'b000)|(s_vliw))? 1'b1:1'b0;


  assign q_inst = (q_inst_sign || opcode[5] || q_vliw) ? instruction : 32'b0;
  assign q_time_reg = time_reg_en ? rs_data : 32'b0;
    //for measurement
  assign meas_rd_addr  = {2'b0,instruction[2:0]};

  assign pram_en     = start_sig[0] & (~end_reg)    ;
  assign pram_rd_en  = start_sig[0] & (~end_reg)    ;
  assign pram_addr   = next_pc [11-1:0]          ;
  assign dram_en     = start_sig[0] & (~end_reg)    ;
  assign dram_rd_en	 = start_sig[0] & (~end_reg)    ;                  
  assign dram_wr_en  = mem_write                 ;
  assign dram_addr   = alu_out[11-1:0]   ;
  assign dram_din    = rs_data          ;
  assign end_sig     = {{31{1'b0}},end_reg};
endmodule
