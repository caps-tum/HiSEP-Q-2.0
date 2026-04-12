// main control logic of the control processor.
// This version uses FSM, and next generation will change to pipeline. ISA is based on eQASM (shown below).

/*Instructions
 
#######################
########control########
#######################
CMP Rs, Rt.                     Compare GPR Rs and Rt and store the result into the comparison flags.
 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  001101  | reserved |    Rs    |   Rt     | reserved |
|---|----------|----------|----------|----------|----------|
 
 
BR <Comp. Flag>, Offset.        Jump to PC + Offset if the specified comparison flag is �?1�?.
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 ..........................4 | 3 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  000001  |                    imm21       |Comp_flag |
|---|----------|----------|----------|----------|----------|


Jump, Offset.        Jump to PC + Offset
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 ..........................4 | 3 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  000010  |                    imm21       |reserved  |
|---|----------|----------|----------|----------|----------|
 
#######################
####Data Transfer######
####################### 
NOP
32 bit 0, no opration
 
FBR <Comp. Flag>, Rd            Fetch the specified comparison flag into GPR Rd.
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 ....20|19..................4| 3 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  010100  |     Rd   |     reserved        |Comp_flag |
|---|----------|----------|----------|----------|----------|
 
LDI Rd, Imm                     Rd = signed_ext(Imm[19:0], 32).
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  010110  |    Rd    |     imm20                      |
|---|----------|----------|----------|----------|----------|
 
LDUI Rd, Imm, Rs                Rd = {Imm[14:0],Rs[16:0]}.
 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  010111  |    Rd    |    Rs    |         imm15       |
|---|----------|----------|----------|----------|----------|
 
LD Rd, Rt(Imm)                  Load data from memory address Rt + Imm into GPR Rd.
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  001001  |    Rd    | reserved |   Rt     |  imm10   |
|---|----------|----------|----------|----------|----------|
ST Rs, Rt(Imm)                  Store the value of GPR Rs in memory address Rt + Imm.
 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  001010  | reserved |  RS      |   Rt     |  imm10   |
|---|----------|----------|----------|----------|----------|
 
STOP
 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 ..................................   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  001000  |                 reserved                  |
|---|----------|----------|----------|----------|----------|
 
FMR Rd, Qi                      Fetch the result of the last measurement instruction on qubit i into GPR Rd.
 
Attention!!! currently only 8 qubits, can be extended to fetch more
 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 ....20|19..................3| 2 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  010101  |     Rd   |     reserved        | Qi       |
|---|----------|----------|----------|----------|----------|
 
#######################
#########ALU###########
####################### 
AND Rd, Rs, Rt
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  011010  |    Rd    |    Rs    |   Rt     | reserved |
|---|----------|----------|----------|----------|----------|
OR Rd, Rs, Rt
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  011000  |    Rd    |    Rs    |   Rt     | reserved |
|---|----------|----------|----------|----------|----------|
XOR Rd, Rs, Rt
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  011001  |    Rd    |    Rs    |   Rt     | reserved |
|---|----------|----------|----------|----------|----------|
NOT Rd, Rt
 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  011011  |    Rd    | reserved |   Rt     | reserved |
|---|----------|----------|----------|----------|----------|
 
ADD Rd, Rs, Rt 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  011110  |    Rd    |    Rs    |   Rt     | reserved |
|---|----------|----------|----------|----------|----------|
 
SUB Rd, Rs, Rt
 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  011111  |    Rd    |    Rs    |   Rt     | reserved |
|---|----------|----------|----------|----------|----------|

end
measurement accumulation
fetch final rsult from histogram
 
#######################
###Quantum related#####
#######################
new QISA 
QSET bit - consideration


QWAIT Imm                       Specify a timing point by waiting for the number of cycles indicated
 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  100000  | reserved |     imm20                      |
|---|----------|----------|----------|----------|----------|
 
QWAITR Rs                       by the immediate value Imm or the value of GPR Rs.
 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 .. 10 | 9 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  100001  | reserved |     Rs   |      imm15          |
|---|----------|----------|----------|----------|----------|
 
SMSO Sd, <Qubit List>   
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 ..  8 | 7 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  101000  |   Sd     |    reserved         |   imm8   |
|---|----------|----------|----------|----------|----------|

SMSOL Sd, <Qubit List>     pcode the same 改为 101011            + 32*3 = 96 bit mask
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 15 | 14 ..  5 | 4 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  111000  |   Sd     |    reserved         |   imm4   |
|---|----------|----------|----------|----------|----------|
 

SSMSO Sd, <Qubit List>     pcode the same 改为 101011  set sliding-mask for single qubit operation_short 8*2^4 = 8*16 = 128
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 12 | 11 ..  8 | 7 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  101001  |   Sd     | reserved |  Offset  |   imm8   |
|---|----------|----------|----------|----------|----------|


SITO Td, <Qubit Pair index>      Update the two qubit operation target register Sd (Td). set immeidate for two-qubit operation
 
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 14 | 13 .. 7  | 6 ..    0|
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  101100  |   Td     |  reserve |   imm7   |    imm7  |
|---|----------|----------|----------|----------|----------|


SITOL Sd, <Qubit List indexex>     pcode the same 改为 101011            + 14*7 = 98 bit
|---|----------|----------|----------|----------|----------|
|31 | 30 .. 25 | 24 .. 20 | 19 .. 9 | 8 ..  2  | 1 ..   0 |
|---|--opcode--|----------|----------|----------|----------|
|---|----------|----------|----------|----------|----------|
| 0 |  111100  |   Td     | reserved | mask(0 unused,1 used) |   imm2(two MSB of the first immediate numebr)   |
|---|----------|----------|----------|----------|----------|

 
[PI,] Q_Op [| Q_Op]*            Applying operations on qubits after waiting for a small number of cycles indicated by PI.
quantum opration depends on gate sets, currently predefined ** gate sets, gate operation can be ranged uptp 2^9
|---|--------------------|----------|----------|----------|----------|
|31 |         30 .. 22   | 22 .. 17 | 16 .. 8  | 7 .. 3   | 2 ..   0 |
|---|--q_opcode--------- |----------|----------|----------|----------|
|---|----------------- --|----------|----------|----------|----------|
| 1 |  quantum opration  |   Si/Ti_0|q_opration| Si/Ti_1  |   PI     |
|---|--------------------|----------|----------|---------------------|
*/
`include "../parameter.v"

module control (
    input            reset,
    input      [5:0] opcode,         // the operation needed to be executed
    input            q_inst_sign,    // the MSB, indicating if this instruction is quantum bubble,the gate operation
    input      [11:0] comp_flag,
    input      [3:0] comp_addr,
    output reg [3:0] ALU_op,         // ALU operation, bitwise execution need to be added
    output reg reg_write,
    //output reg mem_read,
    output reg mem_write,
    //output reg ALU_src,            //current ISA only use register as the ALU source, can be extended
    output reg branch,              // PC select
    output reg q_time_write,
    output reg q_time_sel,
    output reg q_vliw,
    output reg q_slm,
    output reg [1:0] q_reg_write, //[01]for Si [10]for Ti
    output reg [2:0] reg_sel,     //mem, imm, comp, measure, alu
    output reg [2:0] imm_sel,      //M(LD/ST), LDI, LDUI�? BR
    output reg o_time_reg_en,       //select if the output of register will be forward to quantum or not
    output reg sel_mux_b           // input of b port of alu is imm or reg
  );
  //internal wire declaration
  wire q,r,l,a,m,c,b; // register, logic, alu, memery operation, compare, branch
  wire type_mem, type_comp, type_imm, type_measure;
  //register
  reg [6:0] type_reg;

  //netlist
  assign {q,r,l,a,m,c,b} = type_reg[6: 0];
  assign type_comp =   (opcode == 6'b010100) ? 1'b1 : 1'b0;
  assign type_measure   = (opcode == 6'b010101) ? 1'b1 : 1'b0;
  assign type_imm     = ( r && (opcode[1] == 1'b1)); //LDI/LDUI
  assign type_mem   = (m && (opcode[0]==1'b1)) ? 1'b1 : 1'b0; // LD

  //判断指令类型, 排除Quantum
  always @ (*)
  begin
    if(q_inst_sign || opcode[5])
    begin //quantum operation
      type_reg = 7'b1000000;
    end
    else
    begin
      case (opcode[5:2])
        4'b0101:
        begin
          type_reg = 7'b0100000; // R - register type
        end
        4'b0110:
        begin
          type_reg = 7'b0010000; // L - and/or/not
        end
        4'b0111:
        begin
          type_reg = 7'b0001000; // A - add/sub
        end
        4'b0010:
        begin
          type_reg = 7'b0000100; // M 
        end
        4'b0011:
        begin
          type_reg = 7'b0000010; // C 
        end
        4'b0001 | 4'b0001:
        begin
          type_reg = 7'b0000001; // B
        end
        default:
        begin
          type_reg = 7'b0010000; // L
        end
      endcase
    end
  end

  // branch update logic
  always@(*)
  begin
    if(b)
    begin
      if((comp_flag[comp_addr] == 1'b1) | opcode[1:0] == 2'b10)
      begin
        branch = `PC_JUMP; //jump
      end
      else
        branch = `PC_4;//pc = pc+4
    end
    else
    begin
      branch = `PC_4;
    end
  end

  //register file logic
  always@(*)
  begin
    if (r|l|a|reset|type_mem)
    begin
      reg_write = `REGWE_WRITE;
    end
    else
    begin
      reg_write = `REGWE_READ;
    end
  end

  //memory read/write logic
  always @(*)
  begin
    if (reset)
    begin
      //mem_read  = `MEM_READ;
      mem_write = ~`MEM_WRITE;
    end
    else if (opcode == 6'b001010)
    begin //store
      //mem_read  = ~`MEM_READ;
      mem_write = `MEM_WRITE;
    end
    else
    begin
      //mem_read  = `MEM_READ;
      mem_write = ~`MEM_WRITE;
    end
  end

  // register write selection
  always @(*)
  begin
    if (type_mem)
    begin
      reg_sel = `REGSRC_MEM; // Load 指令
    end
    else if (type_comp)
    begin
      reg_sel = `REGSRC_COMP; // comparison
    end
    else if (type_measure)
    begin
      reg_sel = `REGSRC_MEA; // comparison flag
    end
    else if(type_imm)
    begin
      reg_sel = `REGSRC_IMM; // extended immediate
    end
    else
    begin
      reg_sel = `REGSRC_ALU; //alu
    end
  end

  //ALU operation
  always@(*)
  begin
    case (opcode)
      6'b011010:
        ALU_op = `AND;
      6'b011000:
        ALU_op = `OR;
      6'b011001:
        ALU_op = `XOR;
      6'b011011:
        ALU_op = `NOT;
      6'b011110:
        ALU_op = `ADD;
      // qk
      6'b010111:
        ALU_op = `ADD; // LD needs an ADD operation: rd = rt+imm
      6'b001101: 
        ALU_op = `CMP;
      6'b011111:
        ALU_op = `SUB;
      default:
        ALU_op = `ADD;
    endcase
  end


  //imm_gen selection
  always @(*)
  begin
    if (reset | m)
    begin
      imm_sel = `IMM_M;  //LD & ST
      sel_mux_b = 1'b1;
    end
    else if (b)
    begin                       //BR
      imm_sel = `IMM_BR;
      sel_mux_b = 1'b1;
    end
    else if (r && (opcode[1:0] == 2'b10))
    begin//LDI
      imm_sel = `IMM_LDI;
      sel_mux_b = 1'b0;
    end
    else if (r && (opcode[1:0] == 2'b11))
    begin//LDUI
      imm_sel = `IMM_LDUI;
      sel_mux_b = 1'b0;
    end
    else
    begin
      imm_sel = `IMM_NOP;
      sel_mux_b = 1'b0;
    end
  end

  //quantum time operation
  always @(*)
  begin
    if(q_inst_sign) begin
      q_time_write = 1'b0;
    end
    else begin
      if(q)
        begin
          case (opcode)
            6'b100000:
            begin //QTIME
              q_time_write = 1'b1;
              q_time_sel = `TIME_IMM;
            end
            6'b100001:
            begin
              q_time_write = 1'b1;
              q_time_sel = `TIME_REG;
            end
            default:
            begin
              q_time_write = 1'b0;
              q_time_sel = `TIME_IMM;
            end
          endcase
        end
      else begin
        q_time_write = 1'b0;
        q_time_sel = 1'b0;
      end
    end
  end

  //quantum register write
  always @(*)
  begin
    q_reg_write = 2'b00;
    q_slm = 1'b0;
    q_vliw = 1'b0;

    if(q && !q_inst_sign)
    begin
      case (opcode)
        6'b101000:
        begin //SMSO
          q_reg_write = 2'b01;
        end
        6'b101001: //SSMSO
        begin
          q_reg_write = 2'b01;
          q_slm = 1'b1;
        end
        6'b111000: //SMSOL
        begin
          q_reg_write = 2'b01;
          q_vliw = 1'b1;
        end
        6'b101100: //SITO
        begin
          q_reg_write = 2'b10;
        end
        6'b111100: //SISOL
        begin 
          q_reg_write = 2'b10;
          q_vliw = 1'b1;
        end
      endcase
    end
  end

  always @(*) begin
    if(opcode == 6'b100001) //QWAITR
      o_time_reg_en = 1'b1;
    else
      o_time_reg_en = 1'b0;
  end

endmodule
