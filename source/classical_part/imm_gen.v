//////////////////////////////////////////////////////////////////////////////////
// Company: TUM
// Engineer: Xiaorang
//
// Create Date: 2023/02/10
// Design Name:
// Module Name: imm_gen
// Project Name:
// Target Devices:
// Tool Versions:
// Description: immediate number generator, 32bit output, for LDUI and BR, needs more operations to truncate the signal
//
// Dependencies: License Apache 2.0
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////
`include "../parameter.v"

module imm_gen (
    input wire [24:0] imm_src,
    input wire [2:0]  imm_sel,
    input wire [31:0] i_regs,
    output reg [31:0] imm_out
);
    //wires for the output
    wire [31:0] imm_M;
    wire [31:0] imm_BR;
    wire [31:0] imm_LDI;
    wire [31:0] imm_LDUI;

    //internal wires
    wire inst0 = imm_src[9]; //signbit for LD/ST
    wire inst1 = imm_src[19]; //signbit for LDI
    wire [9:0] inst_m = imm_src[9:0];
    wire [19:0] inst_ldi = imm_src[19:0];
    wire [14:0] inst_ldui = imm_src[14:0];
    wire [20:0] inst_br_temp   = imm_src[24:4];

    wire [16:0] inst_br = {inst_br_temp[12],{4{1'b0}},inst_br_temp[11:0]};
    //calculate the corresponding output
    assign imm_M =   {{22{inst0}},inst_m};
    assign imm_LDI = {{12{inst1}}, inst_ldi};
    assign imm_LDUI = {inst_ldui,i_regs[16:0]};
    assign imm_BR = {{15{1'b0}},inst_br};

    always@(*)begin
        case (imm_sel)
            `IMM_M: imm_out = imm_M;
            `IMM_BR: imm_out = imm_BR;
            `IMM_LDI: imm_out = imm_LDI;
            `IMM_LDUI: imm_out = imm_LDUI;
            default: imm_out = 32'b0;
        endcase
    end


endmodule