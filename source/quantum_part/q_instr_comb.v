//this part try to combine time/operation/register together, prepare for final dispatchment
//current 7 qubits supports,需要2bit去决定是什么类型
//20bit time + 4bit oper1 + 14 bit address (maybe offset later) + 4bit oper 2 + 14 bit address (maybe anopther offset) = 56bit instruction
module q_instr_comb #(
    parameter NCH        = 7,
    parameter TIME_WIDTH = 20
)(
    input clk,
    input reset,
    input [3:0] oprand_1,
    input [3:0] oprand_2,
    input [199:0] qubit_address1,
    input [199:0] qubit_address2,
    input [TIME_WIDTH-1:0] time_reg,
    input [2:0]  time_offset,
    input time_fifo_empty,
    
    // Width = TIME_WIDTH + 4(op1) + 2*NCH(addr1) + 4(op2) + 2*NCH(addr2)
    output reg [TIME_WIDTH + 8 + NCH*4 - 1 : 0] inst_comb
);

wire [TIME_WIDTH-1:0] time_abs;
assign time_abs = time_fifo_empty ? time_offset : time_reg + time_offset;

always @(posedge clk ) begin
    if(reset) 
        inst_comb <= 'd0;
    else      
        inst_comb <= {time_abs, oprand_1, qubit_address1[2*NCH-1:0], oprand_2, qubit_address2[2*NCH-1:0]};
end
endmodule