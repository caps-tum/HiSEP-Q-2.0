// ALU block containing logistic and math operation.
//
// ADD  3'b001
// SUB  3'b010
// AND  3'b011
// OR   3'b100
// NOT  3'b101
// XOR  3'b110
// CMP  3'b111
//can be extended to bit operation
`include "../parameter.v"

module alu (
    input    wire [31: 0]    op_A, //rt
    input    wire [31: 0]    op_B, //rs
    input    wire [3: 0]     ALU_op,
    output   reg  [31: 0]    result,
    output   reg  [9:0]      comp_flag
);

//defining the internal result after calculation 
wire [31:0] add_out;
wire [31:0] sub_out;
wire [31:0] and_out;
wire [31:0] or_out;
wire [31:0] not_out;
wire [31:0] xor_out;

wire [31:0]  op_A_unsign;
wire [31:0]  op_B_unsign;
wire [32: 0] add_A;
wire [32: 0] add_B;
wire         sub_op;
wire         add_trash;
wire         overflow_flag;
//interface for comparison flag
wire equal;
wire less_us;
reg less_s;

assign op_A_unsign = $unsigned(op_A);
assign op_B_unsign = $unsigned(op_B);
assign sub_op = ((ALU_op == `SUB) || (ALU_op ==`CMP));
assign add_A   = {op_A[31: 0], sub_op}; //extend the last bit to one, so if operation is sub, then it is the same as ~B+1.
assign add_B   = (sub_op) ? {(~op_B), 1'b1} : {op_B, 1'b0};

//calculate the output
 assign {overflow_flag,add_out,add_helper} = add_A + add_B; //represent both sub and add
 assign and_out              = op_A & op_B; 
 assign or_out               = op_A | op_B;
 assign xor_out              = op_A ^ op_B;
 assign not_out              = ~op_B;

//assign the final output
always @(*) begin
    case(ALU_op)
        `AND: result = and_out;
        `OR:  result = or_out;
        `NOT: result = not_out;
        `XOR: result = xor_out;
        default: result = add_out; //ADD, SUB and CMP
    endcase
end

//assign the output of comparison flag
assign equal    = (op_A_unsign == op_B_unsign) ? 1'b1 : 1'b0;
assign less_us  = (op_A_unsign < op_B_unsign)  ? 1'b1 : 1'b0;
always @(*) begin
    if(op_A[31] == 1) begin
        if(op_B[31] == 0)  less_s = 1'b1;
        else  less_s = (result[31] == 1'b1);
    end

    else begin
        if(op_B[31] == 0) less_s = (result[31] == 1'b1);
        else less_s = 1'b0;
    end
end

always@(*)begin
    comp_flag[0] = (~less_s) & (~equal);
    comp_flag[1] = less_s | equal;
    comp_flag[2] = (~less_s) | equal;
    comp_flag[3] = less_s & (~equal);
    comp_flag[4] = ~less_us & (~equal);
    comp_flag[5] = less_us | equal;
    comp_flag[6] = (~less_us) | equal;
    comp_flag[7] = less_us & (~equal);
    comp_flag[8] = ~equal;
    comp_flag[9] = equal;

end

endmodule