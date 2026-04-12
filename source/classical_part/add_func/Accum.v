module Accum #(
    parameter       NUM_Q = 8, //number of qubits，
    parameter       TRAIL = 10,
    parameter       COUNT_WIDTH = 4, //log2(TRAIL)
    parameter       ADDR_WIDTH = 4   //log2(TRAIL)
  ) (
    input clk,
    input reset,
    input acc_en, //enable signal for accumulation
    //input acc_over,
    input  [NUM_Q-1:0] data,
    //input from sorter to get top 4
    input  [ADDR_WIDTH-1:0] addr1,
    input  [ADDR_WIDTH-1:0]addr2,
    input  [ADDR_WIDTH-1:0]addr3,
    input  [ADDR_WIDTH-1:0]addr4,

    output [COUNT_WIDTH-1:0] count,//output the occurrence of the newlt updated state
    output reg sort_en,                 //state updated, let sorter part work
    output [ADDR_WIDTH-1:0] state_addr, // record the address of the count
    output [NUM_Q-1:0] states1,           //output the states, corresponds to the address
    output [NUM_Q-1:0] states2,           
    output [NUM_Q-1:0] states3,           
    output [NUM_Q-1:0] states4
  );

  reg [NUM_Q-1:0] state_reg [TRAIL-1:0];
  reg [COUNT_WIDTH - 1 : 0] count_reg [TRAIL-1:0];

  reg [NUM_Q-1:0] r_data;
  reg [ADDR_WIDTH-1:0] match_addr;
  reg match_found;
  reg [ADDR_WIDTH-1:0] addr_pointer;
  reg r_sort_en;

  reg [ADDR_WIDTH-1:0] r_match_addr;
  reg r_match_found;

  //wires
  integer i;
  //comparater logic
  always @(posedge clk)
  begin
    if(acc_en)
    begin
      // Iterate over each entry in the register file
      // match_found <= 1'b0;
      // match_addr  <= 'd0;
      r_sort_en <= 1'b1;

      if(data == 'd0)
      begin
        match_found <= 1'b1;
        match_addr <= 'd0;
      end
      else
      begin
        for (i = 1; i < TRAIL; i = i + 1)
        begin
          // Compare the input value with each data in the register file
          if (state_reg[i] == data)
          begin
            // A match is found
            match_found <= 1;
            match_addr <= i;
          end
        end
      end
    end
    else
    begin
      r_sort_en <= 1'b0;
      match_found <= 1'b0;
      match_addr <= 'd0;
    end

  end

  always @(posedge clk)
  begin
    if(reset)
    begin
      r_data <= 'd0;
      r_sort_en <= 'd0;
      sort_en <= 1'b0;
    end
    else
    begin
      r_data <= data;
      sort_en <= r_sort_en;
    end
  end

  always @(posedge clk)
  begin
    if(reset)
    begin
      r_match_addr <=  'd0;
      r_match_found <= 'd0;
    end
    else
    begin
      r_match_addr <= match_addr;
      r_match_found <= match_found;
    end
  end

  always @(posedge clk)
  begin
    if(reset)
    begin
      addr_pointer <= 'd0;
      for (i = 0; i < TRAIL; i = i + 1)
      begin
        state_reg[i] <= 'd0;
        count_reg[i] <= 'd0;
      end
    end
    else if (r_sort_en)
    begin
      if(match_found)
      begin
        state_reg[match_addr] <= r_data;
        count_reg[match_addr] <= count_reg[match_addr]+1'b1;
        addr_pointer <= addr_pointer;
      end

      else
      begin
        addr_pointer <= addr_pointer+1'b1;
        state_reg[addr_pointer + 1'b1] <= r_data;
        count_reg[addr_pointer + 1'b1] <= 1'b1;
      end
    end
  end

  assign state_addr = r_match_addr ? r_match_addr : addr_pointer;
  assign count = r_match_addr ? count_reg[r_match_addr] : count_reg[addr_pointer];
  //assign states = r_match_addr ? state_reg[r_match_addr] : state_reg[addr_pointer];
  assign states1 = state_reg[addr1];
  assign states2 = state_reg[addr2];
  assign states3 = state_reg[addr3];
  assign states4 = state_reg[addr4];
endmodule
