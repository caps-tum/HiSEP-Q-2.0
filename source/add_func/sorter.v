module sorter #(
    parameter       COUNT_WIDTH = 4, //log2(TRAIL)
    parameter       ADDR_WIDTH = 4   //log2(TRAIL)
  ) (
    input clk,
    input reset,
    input [COUNT_WIDTH -1:0] data,
    input [ADDR_WIDTH-1:0] state_addr,
    input enable,


    output [ADDR_WIDTH -1:0]  top_0_addr,
    output [ADDR_WIDTH -1:0]  top_1_addr,
    output [ADDR_WIDTH -1:0]  top_2_addr,
    output [ADDR_WIDTH -1:0]  top_3_addr,

    output [COUNT_WIDTH -1:0]  top_0_count,
    output [COUNT_WIDTH -1:0]  top_1_count,
    output [COUNT_WIDTH -1:0]  top_2_count,
    output [COUNT_WIDTH -1:0]  top_3_count
  );
  // regiser
  reg [COUNT_WIDTH -1:0]  new_state;
  reg [ADDR_WIDTH-1:0]    r_state_addr;
  reg [COUNT_WIDTH+ADDR_WIDTH-1:0]  top_m [0:3]; // top_m = [counter,addr]

  reg [2-1:0] match_addr;
  reg match_found;

  //combinational logic//
  wire [COUNT_WIDTH+ADDR_WIDTH-1:0]  res_top1;
  wire [COUNT_WIDTH+ADDR_WIDTH-1:0]  res_top2;
  wire [COUNT_WIDTH+ADDR_WIDTH-1:0]  res_top3;
  wire [COUNT_WIDTH+ADDR_WIDTH-1:0]  res_top0;

  //always
  always @(posedge clk )
  begin
    if(reset)
      new_state <= 'd0;
    else if (enable)
      new_state<=data;
    else
      new_state<='d0;
  end

  //always
  always @(posedge clk )
  begin
    if(reset)
      r_state_addr <= 'd0;
    else if (enable)
      r_state_addr<=state_addr;
    else
      r_state_addr<='d0;
  end

  //test if state is already in the sorting!!!!!!!!!!!!
  integer i;
  //comparater logic
  always @(posedge clk)
  begin
    if(enable)
    begin
      for (i = 0; i < 4; i = i + 1)
      begin
        // Compare the input value with each data in the register file
        if (top_m[i][ADDR_WIDTH-1:0] == state_addr)
        begin
          // A match is found
          match_found <= 1'b1;
          match_addr <= i;
        end
      end
    end
    else
    begin
      match_found <= 1'b0;
      match_addr <= 'd0;
    end

  end

  always @(posedge clk)
  begin
    if(reset)
    begin
      top_m[0] <= 'd0;
      top_m[1] <= 'd0;
      top_m[2] <= 'd0;
      top_m[3] <= 'd0;
    end

    else if(match_found)
    begin
      top_m[match_addr] <= {new_state,r_state_addr};
    end

    else begin
      if (new_state > res_top0[COUNT_WIDTH+ADDR_WIDTH-1:ADDR_WIDTH])
        begin
          top_m[0]<={new_state,r_state_addr};
        end

      else if (res_top0[COUNT_WIDTH+ADDR_WIDTH-1:ADDR_WIDTH] > res_top1[COUNT_WIDTH+ADDR_WIDTH-1:ADDR_WIDTH])
        begin
          top_m[1]<=res_top0;
          top_m[0]<=res_top1;
        end 
      else  if (res_top1[COUNT_WIDTH+ADDR_WIDTH-1:ADDR_WIDTH] > res_top2[COUNT_WIDTH+ADDR_WIDTH-1:ADDR_WIDTH])
        begin
          top_m[1]<=res_top2;
          top_m[2]<=res_top1;
        end
      else  if (res_top2[COUNT_WIDTH+ADDR_WIDTH-1:ADDR_WIDTH] > res_top3[COUNT_WIDTH+ADDR_WIDTH-1:ADDR_WIDTH])
        begin
          top_m[3]<=res_top2;
          top_m[2]<=res_top3;
        end
      
      
    end
  end

  //netlist
  assign res_top0 = top_m[0];
  assign res_top1 = top_m[1];
  assign res_top2 = top_m[2];
  assign res_top3 = top_m[3];

  assign {top_0_count,top_0_addr}  = top_m[0];
  assign {top_1_count,top_1_addr}  = top_m[1];
  assign {top_2_count,top_2_addr}  = top_m[2];
  assign {top_3_count,top_3_addr}  = top_m[3];

endmodule //sorter minimum feeding inerval 5 clock cycles
