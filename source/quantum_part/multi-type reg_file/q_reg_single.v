/*5-bit address 32 registers
16 - 8 bit register short instruction
16- 100 bit register long instructions (128bit) 4-32bit -4 state FSM

FSM 
INITIAL normal reg / or long inst-first
S1      second
S2      third
S3      last
*/



module q_reg_single (
    input clk,
    input reset,
    input [4:0] wr_addr, //currently set the size to be 32,0-15 8-bit 16-31 100 bit
    input q_slm,
    input long_ind, //long register indication,start the FSM
    input [4:0]  rd_addr1,
    input [4:0]  rd_addr2,
    input [3:0]  Si_offset,
    input [7:0]  wr_data_s,
    input [31:0] wr_data_l,
    input [1:0]  wr_en, //from classical control 
    output wire [3:0] sd_offset1,
    output wire [3:0] sd_offset2,
    output wire [7:0] sd_data1_s,
    output wire [7:0] sd_data2_s,
    output wire [99:0] sd_data1_l,
    output wire [99:0] sd_data2_l
  );

  //register file
  reg [7:0]  reg_s  [0:15];
  reg [3:0]  reg_offset [0:15]; //sliding mask's offset
  reg [99:0] reg_l  [16:31];
  //
  reg [4:0]  reg_wr_addr;// keeping the address for long instructions

  reg [3:0] state;
  reg [3:0] next_state;

  parameter intial = 4'b0001;
  parameter S1 = 4'b0010;
  parameter S2 = 4'b0100;
  parameter S3 = 4'b1000;

  integer i;

  always @(posedge clk) 
  begin
    if(reset) begin
        for(i=0;i < 16;i = i+1)begin
            reg_offset[i] <= 4'b0;
            reg_s[i] <= 0;
            reg_l[i+16] <= 0;
        end
    end

    else if(wr_en[0] && (~long_ind)) begin
        if (q_slm) reg_offset[wr_addr] <= Si_offset;
        else       reg_offset[wr_addr] <= 4'b0;        
    end

  end

// FSM
  always @(*) begin
    // State transition logic
    case(state)
        intial: begin
            if(long_ind && wr_en[0]) next_state = S1;
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
            if (wr_en[0]) begin
                if(long_ind) begin
                    reg_l[wr_addr][99:96] <= wr_data_l[3:0];
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
            reg_l[wr_addr] <= 100'b0;
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

  assign sd_data1_s = (rd_addr1[4]) ? 'd0 : reg_s[rd_addr1];
  assign sd_data2_s = (rd_addr2[4]) ? 'd0 : reg_s[rd_addr2];
  assign sd_offset1 = (rd_addr1[4]) ? 'd0 : reg_offset[rd_addr1];
  assign sd_offset2 = (rd_addr2[4]) ? 'd0 : reg_offset[rd_addr2];

  assign sd_data1_l = (rd_addr1[4]) ? reg_l[rd_addr1] : 'd0;
  assign sd_data2_l = (rd_addr2[4]) ? reg_l[rd_addr2] : 'd0;

endmodule