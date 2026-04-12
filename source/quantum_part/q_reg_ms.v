module q_reg_ms (
    input clk,
    input reset,
    input [4:0] wr_addr, //currently set the size to be 32
    input [4:0] rd_addr,
    input wr_data, //0 or 1
    input wr_en, //from classical control 
    input wr_valid, //from readout
    output wire [32:0] measure_data
  );

  reg [31:0] regs;
  reg [4:0]  reg_wr_addr;
  reg [1:0] state;
  reg [1:0] next_state;

  parameter idle = 0;
  parameter write_wait = 1;
  parameter write_start = 2;

integer i;
    initial begin
        for (i=0;i<32;i=i+1)begin
            regs[i] <= 1'b1;
        end
    end
    
always @(*) begin
  // State transition logic
  case(state)
      idle: begin
          if(wr_en) next_state = write_wait;
          else next_state = idle;
      end
      write_wait: begin
          if(wr_valid) next_state = write_start;
          else next_state = write_wait;
      end
      write_start: begin
        next_state = idle;
      end
  endcase
end

always @(posedge clk)
  begin
    if(reset) begin
        state <= idle;
    end
    else begin
      state <= next_state;
      end
  end

assign measure_data = regs[rd_addr];

always @(posedge clk) begin
    case (next_state)
      write_wait: begin
        if(wr_en)
          reg_wr_addr <= wr_addr;
        else
          reg_wr_addr <= reg_wr_addr;  
      end
      write_start: begin
        regs[reg_wr_addr] <= wr_data;
      end 
      default: begin
        reg_wr_addr <= 5'h1F;
      end
    endcase
  
end

endmodule