module main_ctrl #(
    parameter NCH            = 7,
    parameter TIME_WIDTH     = 20,
    parameter OP_WIDTH       = 6,
    parameter TMANAGER_DEPTH = 32
)(
    input clk,
    input reset,
    input [TIME_WIDTH-1:0] t_cnt,
    input meas_wr_data,
    input meas_wr_valid,
    
    output pram_en,
    output pram_rd_en,
    output [11-1 :0]    pram_addr, 
    input  [32-1 :0]    instruction, 

    output inverted_clk, 
    output dram_en,
    output dram_rd_en,
    output dram_wr_en,
    output [11-1 :0]    dram_addr,
    output [32-1 :0]    dram_din,
    input  [32-1 :0]    data_read, 

    input  [32-1 : 0]   start_sig, 
    input  [32-1 : 0]   reg1, 
    input  [32-1 : 0]   reg2,
    output [32-1 : 0]   end_sig,
    
    output [TIME_WIDTH*NCH-1 : 0] abs_time,
    output [NCH-1 : 0]            fifo_wr_en,
    output [OP_WIDTH*NCH-1 : 0]   fifo_wd,
    output [NCH-1 : 0]            err_bit
);

//******************register******************//
reg r_time_write;
reg r_time_sel;
reg [1:0] r_reg_write; 
reg [31:0] r_inst;
reg [31:0] r_time_reg;
reg r_vliw ;
reg r_slm ;

//******************wire*********************//
wire q_time_write;
wire q_time_sel;
wire [1:0] q_reg_write;
wire [31:0] q_inst;      
wire [31:0] q_time_reg;
wire [31:0] q_measurement;
wire [4:0] meas_rd_addr;
wire [4:0] meas_wr_addr;
wire meas_wr_en;

//******************always********************//
always @(posedge clk ) begin
    if(reset) begin
        r_vliw       <= 1'b0;
        r_slm        <= 1'b0;
        r_time_write <= 1'b0;
        r_time_sel   <= 1'b0;
        r_reg_write  <= 2'b0;
        r_inst       <= 31'b0;
        r_time_reg   <= 31'b0;
    end
    else begin
        r_time_write <= q_time_write;
        r_time_sel   <= q_time_sel;
        r_reg_write  <= q_reg_write; 
        r_inst       <= q_inst;
        r_time_reg   <= q_time_reg;
        r_vliw       <= q_vliw;
        r_slm        <= q_slm;
    end
end

classical_ctrl classical_ctrl_i (
    .clk             (clk ),
    .rst             (reset),
    .i_q_measurement (q_measurement ),
    .q_time_write    (q_time_write ),
    .q_time_sel      (q_time_sel ),
    .q_reg_write     (q_reg_write ),
    .q_vliw          (q_vliw ),
    .q_slm           (q_slm ),
    .q_inst          (q_inst ),
    .q_time_reg      (q_time_reg ),
    .meas_rd_addr    (meas_rd_addr ),
    .pram_en         (pram_en ),
    .pram_rd_en      (pram_rd_en ),
    .pram_addr       (pram_addr ),
    .instruction     (instruction ),
    .inverted_clk    (inverted_clk ),
    .dram_en         (dram_en ),
    .dram_rd_en      (dram_rd_en ),
    .dram_wr_en      (dram_wr_en ),
    .dram_addr       (dram_addr ),
    .dram_din        (dram_din ),
    .data_read       (data_read ),
    .start_sig       (start_sig ),
    .reg1            (reg1 ),
    .reg2            (reg2 ),
    .end_sig         (end_sig)
);

quantum_ctrl #(
    .NCH            (NCH),
    .TIME_WIDTH     (TIME_WIDTH),
    .OP_WIDTH       (OP_WIDTH),
    .TMANAGER_DEPTH (TMANAGER_DEPTH)
) quantum_ctrl_dut (
    .clk            (clk ),
    .reset          (reset ),
    .q_instruction  (r_inst ),
    .i_register     (r_time_reg ),
    .q_vliw         (r_vliw ),
    .q_slm          (r_slm ),
    .q_time_sel     (r_time_sel ),
    .q_time_write   (r_time_write ),
    .q_reg_write    (r_reg_write ),
    .t_cnt          (t_cnt ),
    .abs_time       (abs_time ),
    .fifo_wr_en     (fifo_wr_en ),
    .fifo_wd        (fifo_wd ),
    .err_bit        (err_bit)
);

q_reg_ms q_reg_ms_dut (
    .clk          (clk ),
    .reset        (reset ),
    .wr_addr      (meas_wr_addr ),
    .rd_addr      (meas_rd_addr),
    .wr_data      (meas_wr_data),
    .wr_en        (meas_wr_en ),
    .wr_valid     (meas_wr_valid),
    .measure_data (q_measurement)
);

assign meas_wr_addr = 4'b0; 
assign meas_wr_en = 1'b0;

endmodule