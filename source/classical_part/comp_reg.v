`include "../parameter.v"

// module comp_reg (
//     input [9:0] i_comp_flag,
//     input [3:0] ALU_op,
//     output reg [11:0] o_comp_reg
//   );
//   //////comp_res////////////
//   ///[11,      10,   9,   8,  7,  6,  5,  4,  3, 2, 1, 0] ///////////
//   ///[always,never,equal, ne,ltu,geu,leu,gtu, lt,ge,le,gt]
//   always @(*)
//   begin
//     if(ALU_op == `CMP)
//     begin
//       o_comp_reg = {1'b1,1'b1,i_comp_flag};
//     end
//     else
//       o_comp_reg = 12'b0;
//   end
// endmodule


module comp_reg (
    input clk,
    input reset,
    input [9:0] i_comp_flag,
    input [3:0] ALU_op,
    output reg [11:0] o_comp_reg
  );
 
  always @(posedge clk) // is a reg?
  begin
    if (reset)
    begin
      o_comp_reg <= {1'b1,1'b0,10'b0000_0000_00}; // never = 1'b0
    end
    else if(ALU_op == `CMP)
    begin
      o_comp_reg <= {1'b1,1'b0,i_comp_flag}; // never = 1'b0
    end
    else
    begin
      o_comp_reg <= o_comp_reg;
    end
  end
endmodule

