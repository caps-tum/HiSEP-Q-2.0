module q_reg_t (
    input clk,
    input reset,
    input [4:0] wr_addr, //currently set the size to be 32
    input [4:0] rd_addr1,
    input [4:0] rd_addr2,
    input [15:0] wr_data,
    input [1:0] wr_en, //from classical control 
    output wire [15:0] td_data1,
    output wire [15:0] td_data2
  );

  reg [15:0] regs [31:0];

integer i;

always @(posedge clk)
  begin
    if(reset) begin
        for (i=0;i<32;i=i+1)begin
            regs[i] <= 15'd0;
        end
    end
    else if (wr_en[1])
    begin
      regs[wr_addr] <= wr_data;
    end
  end

  assign td_data1 = regs[rd_addr1];
  assign td_data2 = regs[rd_addr2];

endmodule