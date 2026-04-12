//this file defines the quantum control store which translates quantum instrcutions into microinstructions
//v1.0 
//two connect to one decoder
`include "../parameter.v"
module q_control_lut (
    input [8:0] q_opcode,
    input q_op_sign, //quantum instructions that for executing a gate
    output reg [3:0] q_micro_op, //operation type
    output reg meas_write_en,
    output reg timestamp_rd_en,
    output reg [1:0] q_op_sel //operation is single or two qubit gates [01] single [10]doule
);

 always @(*) begin
    q_op_sel = 2'b0;
    if(q_op_sign) begin
        case(q_opcode) //just an example
            9'd0: begin //QNOP
                q_micro_op = `QNOP;
                q_op_sel[0] = 1'b0;
            end
            9'd1: begin //X(180)
                q_micro_op = `X180;
                q_op_sel[0] = 1'b1;
            end
            9'd2: begin //X(90)
                q_micro_op = `X90;
                q_op_sel[0] = 1'b1;
            end//
            9'd3: begin //X(-90)
                q_micro_op = `X90R;
                q_op_sel[0] = 1'b1;
            end//
            9'd4: begin //Y(180)
                q_micro_op = `Y180;
                q_op_sel[0] = 1'b1;
            end
            9'd5: begin //Y(90)
                q_micro_op = `Y90;
                q_op_sel[0] = 1'b1;
            end
            9'd6: begin //Y(-90)
                q_micro_op = `Y90R;
                q_op_sel[0] = 1'b1;
            end
            9'd7: begin //Measure
                q_micro_op = `MEAS;
                q_op_sel[0] = 1'b1;
            end
            9'd8:begin //CNOT,Hammad
                q_micro_op = `CNOT;
                q_op_sel[1] = 1'b1;
            end
            9'd9:begin
                q_micro_op = `HAMD;
                q_op_sel[1] = 1'b1;
            end

            default: begin
            q_micro_op = `QNOP;
            q_op_sel = 2'b00;
            end
        endcase
        timestamp_rd_en = 1'b1;
    end
    else begin
        q_micro_op = `QNOP;
        timestamp_rd_en = 1'b0;
        q_op_sel = 2'b00;
    end
 end

 always @(*) begin //perhaps move to event distributor
    if(q_opcode == 9'd7) meas_write_en = 1'b1;
    else                 meas_write_en = 1'b0;
 end
endmodule