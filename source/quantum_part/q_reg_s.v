module q_reg_s (
    input clk,
    input reset,
    input [4:0] wr_addr, //currently set the size to be 32
    input [4:0] rd_addr1,
    input [4:0] rd_addr2,
    input [6:0] wr_data,
    input [1:0] wr_en, //from classical control 
    output wire [6:0] sd_data1,
    output wire [6:0] sd_data2
  );

  reg [6:0] regs [31:0];

integer i;

always @(posedge clk)
  begin
    if(reset) begin
        for (i=0;i<32;i=i+1)begin
            regs[i] <= 6'd0;
        end
    end
    else if (wr_en[0])
    begin
      regs[wr_addr] <= wr_data;
    end
  end

  assign sd_data1 = regs[rd_addr1];
  assign sd_data2 = regs[rd_addr2];

endmodule