`define REGWE_READ  1'b0
`define REGWE_WRITE 1'b1
`define PC_JUMP     1'b1
`define PC_4        1'b0
//`define MEM_READ    1'b1
`define MEM_WRITE   1'b1

`define REGSRC_MEM  3'b001
`define REGSRC_COMP 3'b010
`define REGSRC_ALU  3'b011
`define REGSRC_MEA  3'b100
`define REGSRC_IMM  3'b101

`define ADD  3'b001
`define SUB  3'b010
`define AND  3'b011
`define OR   3'b100
`define NOT  3'b101
`define XOR  3'b110
`define CMP  3'b111

`define TIME_IMM  1'b1
`define TIME_REG  1'b0


`define IMM_M     3'b000
`define IMM_LDI   3'b001
`define IMM_LDUI  3'b010
`define IMM_BR    3'b011
`define IMM_NOP   3'b100

//quantum gates
`define QNOP  4'b0000
`define X180  4'b0001
`define X90   4'b0010
`define X90R  4'b0011
`define Y180  4'b0100
`define Y90   4'b0101
`define Y90R  4'b0110
`define MEAS  4'b0111
`define CNOT  4'b1000
`define HAMD  4'b1001

// `define C_S_AXI_DATA_WIDTH 32
// `define C_S_AXI_ADDR_WIDTH 11