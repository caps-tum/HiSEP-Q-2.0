/*features : topology independent 
use binary addressing
32-bit 0_111100(opcode)_xxxxx(register address)_xxxxxxx_xxxxxxx (32bit -1对) 1+6+5+ 14 = 26 only one address
vector : 128 bit 0_111101_R9~12(5)_xxxxxxx_xxxxxxx_xxxxxx_xxxxxx_xxxxxx_xxxxxx_mask (128 - 7对) 1+6+5+14*7+mask(7) = 117bit
register format
14bit register source+target -- use 8 regs
106bit register (source+target)*7 + mask -- use 4 regs, can be extended


*/

module q_reg_double (
    input clk,
    input reset,
    input [4:0] wr_addr, //currently set the size to be 32,0-15 8-bit 16-31 100 bit
    input long_ind, //long register indication,start the FSM
    input [4:0]  rd_addr1,
    input [4:0]  rd_addr2,
    input [13:0]  wr_data_s,
    input [31:0] wr_data_l,
    input [1:0]  wr_en, //from classical control [10] double
    output wire [13:0] sd_data1_s,
    output wire [13:0] sd_data2_s,
    output wire [104:0] sd_data1_l,
    output wire [104:0] sd_data2_l
  );

//register file
  reg [13:0]  reg_s  [0:15];
  reg [104:0] reg_l  [16:31];
  //
  reg [4:0]  reg_wr_addr;// keeping the address for long instructions

  reg [3:0] state;
  reg [3:0] next_state;

  parameter intial = 4'b0001;
  parameter S1 = 4'b0010;
  parameter S2 = 4'b0100;
  parameter S3 = 4'b1000;
  
  integer i;

// FSM
  always @(*) begin
    // State transition logic
    case(state)
        intial: begin
            if(long_ind && wr_en[1]) next_state = S1;
            else next_state = intial;
        end
        S1: begin
            next_state = S2;
        end
        S2: begin
            next_state = S3;
        end
        S3: begin
            next_state = intial;
        end
        default begin
            next_state = intial;
        end
            
    endcase
  end

  always @(posedge clk)
  begin
    if(reset) begin
        state <= intial;
    end
    else begin
      state <= next_state;
      end
  end

  always @(posedge clk ) begin
    case(state)
        intial: begin
            if (wr_en[1]) begin
                if(long_ind) begin
                    reg_l[wr_addr][104:96] <= wr_data_l[8:0];
                end
                else reg_s[wr_addr] <= wr_data_s;
            end
            
        end
        S1: begin
            reg_l[reg_wr_addr][95:64] <= wr_data_l;
        end
        S2: begin
            reg_l[reg_wr_addr][63:32] <= wr_data_l;
        end
        S3: begin
            reg_l[reg_wr_addr][31:0] <= wr_data_l; 
        end
        default begin
            reg_l[wr_addr] <= 105'b0;
        end
            
    endcase
  end

  always @(posedge clk ) begin
    case(state)
        intial: begin
            reg_wr_addr <= wr_addr;
        end
        S1: begin
            reg_wr_addr <= reg_wr_addr;
        end
        S2: begin
            reg_wr_addr <= reg_wr_addr;
        end
        S3: begin
            reg_wr_addr <= reg_wr_addr;
        end
        default begin
            reg_wr_addr <= 'd0;
        end  
    endcase
  end
  
  always @(posedge clk) 
  begin
    if(reset) begin
        for(i=0;i < 16;i = i+1)begin
            reg_s[i] <= 0;
            reg_l[i+16] <= 0;
        end
    end
  end

  assign sd_data1_s = (rd_addr1[4]) ? 'd0 : reg_s[rd_addr1];
  assign sd_data2_s = (rd_addr2[4]) ? 'd0 : reg_s[rd_addr2];

  assign sd_data1_l = (rd_addr1[4]) ? reg_l[rd_addr1] : 'd0;
  assign sd_data2_l = (rd_addr2[4]) ? reg_l[rd_addr2] : 'd0;

endmodule