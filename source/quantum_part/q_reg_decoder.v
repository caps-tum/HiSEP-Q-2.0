module q_reg_decoder(
    input [7:0]  sreg_data_s,
    input [99:0] sreg_data_l,
    input [13:0] treg_data_s,
    input [104:0] treg_data_l,
    input [3:0]  reg_off,
    input [4:0]  reg_read_addr, //select if the register is long or short
    input [1:0] q_reg_sel, //01 for single, 10 for double
    output [199:0] q_op_out //100*2 = 200 bit
);
reg [199:0] q_op_single; //11 for single 00 for no operation
reg [199:0] q_op_double; //10 is target, 01 is source

reg [7:0] t_data_addr1;
reg [7:0] t_data_addr2;
wire [7:0] treg_mask;
integer i;
integer j;

assign treg_mask = treg_data_l[104:98];

always@(*)begin //q_op_single
    q_op_single = 200'b0;
    if(reg_read_addr[4]) begin // address 16-31 long instructions
        for (i = 0; i < 100; i = i + 1)
            q_op_single[(2*i)+:2] = {2{sreg_data_l[i]}};
    end
    else begin
            q_op_single[(16*reg_off)+:16] = {{2{sreg_data_s[7]}},{2{sreg_data_s[6]}},{2{sreg_data_s[5]}},{2{sreg_data_s[4]}},{2{sreg_data_s[3]}},{2{sreg_data_s[2]}},{2{sreg_data_s[1]}},{2{sreg_data_s[0]}}};
    end
end

always@(*) begin //q_op_double
    q_op_double = 200'b0;
    if(reg_read_addr[4]) begin // address 16-31 long instructions
        for (j = 0; j < 7; j = j + 1) begin
            t_data_addr1 = (treg_data_l[(14*j)+:7]);
            t_data_addr2 = (treg_data_l[(14*j+7)+:7]);

            q_op_double[(t_data_addr1<<1)+:2] = treg_mask[j] ? 2'b10 : 2'b00; //<source,target>, so here is target
            q_op_double[(t_data_addr2<<2)+:2] = treg_mask[j] ? 2'b01 : 2'b00; //source
        end
    end
    else begin
        q_op_double[((treg_data_s[6:0])<<1)+:2] = 2'b10;
        q_op_double[((treg_data_s[13:7]))<<1+:2] = 2'b01;
    end
end

assign q_op_out = q_reg_sel[0] ? q_op_single : q_reg_sel[1] ? q_op_double : 200'b0;
endmodule