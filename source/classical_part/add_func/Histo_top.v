module Histo_top #(
    parameter       NUM_Q = 8, //number of qubits，
    parameter       TRAIL = 100,
    parameter       COUNT_WIDTH = 4, //log2(TRAIL)
    parameter       ADDR_WIDTH = 4   //log2(TRAIL)
  ) (
    input clk,
    input reset,
    input acc_en, //enable signal for accumulation
    //input acc_over,
    input  [NUM_Q-1:0] data,

   output [NUM_Q-1:0] states1,           //output the states, corresponds to the address
   output [NUM_Q-1:0] states2,           
   output [NUM_Q-1:0] states3,           
   output [NUM_Q-1:0] states4,

   output [COUNT_WIDTH-1:0] count1,           //output the states, corresponds to the address
   output [COUNT_WIDTH-1:0] count2,           
   output [COUNT_WIDTH-1:0] count3,           
   output [COUNT_WIDTH-1:0] count4

    //  output states, implementation to reduce IO
    //  output count
  );

  wire [ADDR_WIDTH -1:0] top_addr1;
  wire [ADDR_WIDTH -1:0] top_addr2;
  wire [ADDR_WIDTH -1:0] top_addr3;
  wire [ADDR_WIDTH -1:0] top_addr4;

  wire [COUNT_WIDTH-1:0] count_temp;
  wire [ADDR_WIDTH -1:0] addr_temp;
  wire sorting_en;


// implementation specific


    // wire [NUM_Q-1:0] states1;           //output the states, corresponds to the address
    // wire [NUM_Q-1:0] states2;           
    // wire [NUM_Q-1:0] states3;           
    // wire [NUM_Q-1:0] states4;

    // wire [COUNT_WIDTH-1:0] count1;           //output the states, corresponds to the address
    // wire [COUNT_WIDTH-1:0] count2;           
    // wire [COUNT_WIDTH-1:0] count3;           
    // wire [COUNT_WIDTH-1:0] count4;

//
  Accum #(
    .NUM_Q(NUM_Q ),
    .TRAIL(TRAIL ),
    .COUNT_WIDTH(COUNT_WIDTH ),
    .ADDR_WIDTH (
        ADDR_WIDTH )
  )
  Accum_dut (
    .clk (clk ),
    .reset (reset ),
    .acc_en (acc_en ),
    .data (data ),
    .addr1 (top_addr1 ),
    .addr2 (top_addr2 ),
    .addr3 (top_addr3 ),
    .addr4 (top_addr4 ),
    .count (count_temp ),
    .sort_en (sorting_en ),
    .state_addr (addr_temp ),
    .states1 (states1 ),
    .states2 (states2 ),
    .states3 (states3 ),
    .states4  ( states4)
  );


  sorter #(
    .COUNT_WIDTH(COUNT_WIDTH ),
    .ADDR_WIDTH (
        ADDR_WIDTH )
  )
  sorter_dut (
    .clk (clk ),
    .reset (reset ),
    .data (count_temp),
    .state_addr (addr_temp ),
    .enable (sorting_en),
    .top_0_addr (top_addr1 ),
    .top_1_addr (top_addr2 ),
    .top_2_addr (top_addr3 ),
    .top_3_addr (top_addr4 ),
    .top_0_count (count1 ),
    .top_1_count (count2 ),
    .top_2_count (count3 ),
    .top_3_count (count4 )
  );
   
  //  assign states = ((states1 + states2 + states3 + states4)==0) ? 1'b0 : 1'b1;
   
  //  assign count = ((count1 + count2 + count3 + count4)==0) ? 1'b0 : 1'b1;
endmodule