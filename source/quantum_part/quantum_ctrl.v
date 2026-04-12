module quantum_ctrl #(
    parameter NCH            = 7,
    parameter TIME_WIDTH     = 20,
    parameter OP_WIDTH       = 6,
    parameter TMANAGER_DEPTH = 32
)(
    input clk,
    input reset,
    input [31:0] q_instruction,
    input [31:0] i_register, 
    input q_vliw, 
    input q_slm,  
    input q_time_sel,
    input q_time_write,
    input [1:0] q_reg_write,
    input [TIME_WIDTH-1:0] t_cnt,

    output [TIME_WIDTH*NCH-1 : 0] abs_time,
    output [NCH-1 : 0]            fifo_wr_en,
    output [OP_WIDTH*NCH-1 : 0]   fifo_wd,
    output [NCH-1 : 0]            err_bit  
);

//*************************netlist*************************//
wire [TIME_WIDTH-1:0] timing;
wire [2:0]  pi;
wire [4:0]  Si_addr;
wire [4:0]  Ti_addr;
wire [7:0]  Si_reg_s; 
wire [13:0] Ti_reg_s; 
wire [31:0] Q_reg_l; 
wire [3:0]  Si_offset;
wire [4:0]  q_reg_rd_addr1;
wire [4:0]  q_reg_rd_addr2;
wire [8:0]  q_opcode1;
wire [8:0]  q_opcode2;

wire [TIME_WIDTH-1:0] o_tstamp_time;
wire o_tstamp_full;
wire o_tstamp_empty;

wire [3:0] o_q_op1;
wire [3:0] o_q_op2;
wire o_meas_write_en1;
wire o_meas_write_en2;
wire o_tstamp_rd_en1;
wire o_tstamp_rd_en2;
wire meas_wr_en;
wire tstamp_rd_en;
wire [1:0] o_q_op_sel1;
wire [1:0] o_q_op_sel2;

wire [4:0] i_ARd_Rs1 = o_q_op_sel1[0] ? q_reg_rd_addr1 : 5'b0;
wire [4:0] i_ARd_Rs2 = o_q_op_sel2[0] ? q_reg_rd_addr2 : 5'b0;
wire [4:0] i_ARd_Rt1 = o_q_op_sel1[1] ? q_reg_rd_addr1 : 5'b0;
wire [4:0] i_ARd_Rt2 = o_q_op_sel2[1] ? q_reg_rd_addr2 : 5'b0;

wire [3:0] o_DRd_Ro1;
wire [3:0] o_DRd_Ro2;
wire [7:0] o_DRd_Rs1_s;
wire [7:0] o_DRd_Rs2_s;
wire [99:0] o_DRd_Rs1_l;
wire [99:0] o_DRd_Rs2_l;

wire [13:0] o_DRd_Rt1_s;
wire [13:0] o_DRd_Rt2_s;
wire [104:0] o_DRd_Rt1_l;
wire [104:0] o_DRd_Rt2_l;

wire [199:0] q_reg_rd_data1;
wire [199:0] q_reg_rd_data2;

wire [TIME_WIDTH+8+NCH*4-1:0] inst_comb;

reg [199:0] r_reg_rd_data1;
reg [199:0] r_reg_rd_data2;
reg [3:0] r_q_op1;
reg [3:0] r_q_op2;
reg [2:0] time_offset;
reg r_tstamp_empty;

assign meas_wr_en = o_meas_write_en1 | o_meas_write_en2;
assign tstamp_rd_en = o_tstamp_rd_en1 | o_tstamp_rd_en2;

always @(posedge clk ) begin
    if(reset) begin
        r_reg_rd_data1 <= 200'b0;
        r_reg_rd_data2 <= 200'b0;
    end else begin
        r_reg_rd_data1 <= q_reg_rd_data1;
        r_reg_rd_data2 <= q_reg_rd_data2;
    end
end

always @(posedge clk ) begin
    if(reset) begin
        r_q_op1 <= 4'b0; 
        r_q_op2 <= 4'b0;
    end else begin
        r_q_op1 <= o_q_op1;
        r_q_op2 <= o_q_op2;
    end
end

always @(posedge clk ) begin
    if(reset) begin
        time_offset <= 3'b0;
        r_tstamp_empty<=1'b0;
    end else begin
        time_offset <= pi;
        r_tstamp_empty <= o_tstamp_empty;
    end
end

q_decoder #(
    .TIME_WIDTH(TIME_WIDTH)
) q_decoder_i (
    .q_instruction  (q_instruction ),
    .i_register     (i_register ),
    .q_time_sel     (q_time_sel ),
    .t_cnt          (t_cnt ),
    .timing         (timing ),
    .pi             (pi ),
    .Si_addr        (Si_addr ),
    .Ti_addr        (Ti_addr ),
    .Si_reg_s       (Si_reg_s ),
    .Ti_reg_s       (Ti_reg_s ),
    .Q_reg_l        (Q_reg_l ),
    .Si_offset      (Si_offset ),
    .q_reg_rd_addr1 (q_reg_rd_addr1 ),
    .q_reg_rd_addr2 (q_reg_rd_addr2 ),
    .q_opcode1      (q_opcode1 ),
    .q_opcode2      (q_opcode2)
);

q_time_manager #(
    .DEPTH      (TMANAGER_DEPTH),
    .DATA_WIDTH (TIME_WIDTH)
) q_time_manager_dut (
    .clk      (clk),
    .reset    (reset),
    .wr_en    (q_time_write),
    .rd_en    (tstamp_rd_en),
    .data_in  (timing),
    .data_out (o_tstamp_time),
    .full     (o_tstamp_full),
    .empty    (o_tstamp_empty)
);

q_control_lut q_control_lut_1(
    .q_opcode        (q_opcode1),
    .q_op_sign       (q_instruction[31]),
    .q_micro_op      (o_q_op1),
    .meas_write_en   (o_meas_write_en1),
    .timestamp_rd_en (o_tstamp_rd_en1),
    .q_op_sel        (o_q_op_sel1)
);

q_control_lut q_control_lut_2(
    .q_opcode        (q_opcode2),
    .q_op_sign       (q_instruction[31]),
    .q_micro_op      (o_q_op2),
    .meas_write_en   (o_meas_write_en2 ),
    .timestamp_rd_en (o_tstamp_rd_en2),
    .q_op_sel        (o_q_op_sel2)
);

q_reg_single q_reg_single_i (
    .clk        (clk),
    .reset      (reset),
    .wr_addr    (Si_addr),
    .q_slm      (q_slm),
    .long_ind   (q_vliw),
    .rd_addr1   (i_ARd_Rs1),
    .rd_addr2   (i_ARd_Rs2),
    .Si_offset  (Si_offset),
    .wr_data_s  (Si_reg_s),
    .wr_data_l  (Q_reg_l),
    .wr_en      (q_reg_write),
    .sd_offset1 (o_DRd_Ro1),
    .sd_offset2 (o_DRd_Ro2), 
    .sd_data1_s (o_DRd_Rs1_s),
    .sd_data2_s (o_DRd_Rs2_s),
    .sd_data1_l (o_DRd_Rs1_l),
    .sd_data2_l (o_DRd_Rs2_l)
);

q_reg_double q_reg_double_i (
    .clk        (clk),
    .reset      (reset),
    .wr_addr    (Ti_addr),
    .long_ind   (q_vliw),
    .rd_addr1   (i_ARd_Rt1),
    .rd_addr2   (i_ARd_Rt2),
    .wr_data_s  (Ti_reg_s),
    .wr_data_l  (Q_reg_l),
    .wr_en      (q_reg_write),
    .sd_data1_s (o_DRd_Rt1_s),
    .sd_data2_s (o_DRd_Rt2_s),
    .sd_data1_l (o_DRd_Rt1_l),
    .sd_data2_l (o_DRd_Rt2_l)
);

q_reg_decoder q_reg_decoder_1 (
    .sreg_data_s   (o_DRd_Rs1_s),
    .sreg_data_l   (o_DRd_Rs1_l),
    .treg_data_s   (o_DRd_Rt1_s),
    .treg_data_l   (o_DRd_Rt1_l),
    .reg_off       (o_DRd_Ro1),
    .reg_read_addr (q_reg_rd_addr1),
    .q_reg_sel     (o_q_op_sel1),
    .q_op_out      (q_reg_rd_data1)
);

q_reg_decoder q_reg_decoder_2 (
    .sreg_data_s   (o_DRd_Rs2_s),
    .sreg_data_l   (o_DRd_Rs2_l),
    .treg_data_s   (o_DRd_Rt2_s),
    .treg_data_l   (o_DRd_Rt2_l),
    .reg_off       (o_DRd_Ro2),
    .reg_read_addr (q_reg_rd_addr2),
    .q_reg_sel     (o_q_op_sel2),
    .q_op_out      (q_reg_rd_data2)
);

q_instr_comb #(
    .NCH        (NCH),
    .TIME_WIDTH (TIME_WIDTH)
) q_instr_comb_dut (
    .clk             (clk ),
    .reset           (reset ),
    .oprand_1        (r_q_op1 ),
    .oprand_2        (r_q_op2 ),
    .qubit_address1  (r_reg_rd_data1 ),
    .qubit_address2  (r_reg_rd_data2 ),
    .time_reg        (o_tstamp_time),
    .time_offset     (time_offset),
    .time_fifo_empty (r_tstamp_empty ),
    .inst_comb       (inst_comb)
);

// 此处例化 new_dispatcher.v
dispatcher #(
    .NCH        (NCH),
    .TIME_WIDTH (TIME_WIDTH)
) dispatcher_dut (
    .clk        (clk ),
    .reset      (reset ),
    .comb       (inst_comb ),
    .abs_time   (abs_time ),
    .fifo_wr_en (fifo_wr_en ),
    .fifo_wd    (fifo_wd ),
    .err_bit    (err_bit)
);

endmodule