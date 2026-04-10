// Copyright TUM
// Licensed under the Solderpad Hardware License v2.1, see LICENSE.txt for details
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
// RVV backbone adapted from Vicuna by TU Wien, originally license applied


module vproc_elem #(
        parameter int unsigned         VREG_W         = 128,  // width in bits of vector registers
        parameter int unsigned         GATHER_OP_W    = 32,   // ELEM unit GATHER operand width in bits
        parameter int unsigned         XIF_ID_W       = 3,    // width of forwarded instruction IDs // quantum qvproc
        parameter bit                  BUF_RESULTS    = 1'b1, // insert pipeline stage after computing result
        parameter type                 CTRL_T         = logic,
        parameter bit                  DONT_CARE_ZERO = 1'b0  // initialize don't care values to zero
    )(
        input  logic                   clk_i,
        input  logic                   async_rst_ni,
        input  logic                   sync_rst_ni,

        input  logic                   pipe_in_valid_i,
        output logic                   pipe_in_ready_o,
        input  CTRL_T                  pipe_in_ctrl_i,
        input  logic [31           :0] pipe_in_op1_i,
        input  logic [31           :0] pipe_in_op2_i,
        input  logic                   pipe_in_op2_mask_i,
        input  logic [GATHER_OP_W-1:0] pipe_in_op_gather_i,
        input  logic                   pipe_in_mask_i,

        output logic                   pipe_out_valid_o,
        input  logic                   pipe_out_ready_i,
        output CTRL_T                  pipe_out_ctrl_o,
        output logic                   pipe_out_xreg_valid_o,
        output logic [31           :0] pipe_out_xreg_data_o,
        output logic [4            :0] pipe_out_xreg_addr_o,
        output logic                   pipe_out_res_valid_o,
        output logic [31           :0] pipe_out_res_o,
        output logic [3            :0] pipe_out_mask_o,

        output logic                   quantum_valid_o, // quantum qvproc
        output logic [4            :0] quantum_op_o, // quantum qvproc
        output logic [XIF_ID_W     -1:0] quantum_instr_id_o, // quantum qvproc
        output logic [4            :0] quantum_vd_addr_o, // quantum qvproc
        output logic [31           :0] quantum_elem1_o, // quantum qvproc
        output logic [31           :0] quantum_elem2_o, // quantum qvproc
        output logic [31           :0] quantum_elem3_o, // quantum qvproc
        output vproc_pkg::cfg_lmul    quantum_lmul_o, // quantum qvproc
        output vproc_pkg::cfg_emul    quantum_emul_o, // quantum qvproc
        output logic [2            :0] quantum_count_mul_o, // quantum qvproc
        output logic                  quantum_first_cycle_o, // quantum qvproc
        output logic                  quantum_last_cycle_o, // quantum qvproc
        output logic                  quantum_vl_part_0_o, // quantum qvproc
        output logic [4            :0] quantum_res_vaddr_o // quantum qvproc
    );

    import vproc_pkg::*;


    ///////////////////////////////////////////////////////////////////////////
    // ELEM BUFFERS

    logic  state_res_ready;
    logic  state_res_valid_q, state_res_valid_d;
    CTRL_T state_res_q,       state_res_d;

    /*
     * Quantum trace storage keeps the exact element-sized operands that fed the
     * custom ELEM quantum operation aligned with the buffered result stream.
     * This lets upper hierarchy levels observe the same slice payload that the
     * ELEM unit actually consumed, rather than reconstructing it later after
     * packing/writeback has already merged multiple slices together.
     */
    logic [31:0] quantum_elem1_q, quantum_elem1_d; // quantum qvproc
    logic [31:0] quantum_elem2_q, quantum_elem2_d; // quantum qvproc

    // counter, operands and result
    logic [31:0] counter_q,        counter_d;
    logic [31:0] result_q,         result_d;
    logic        result_mask_q,    result_mask_d;
    logic        result_valid_q,   result_valid_d;

    generate
        if (BUF_RESULTS) begin
            always_ff @(posedge clk_i or negedge async_rst_ni) begin : vproc_elem_stage_res_valid
                if (~async_rst_ni) begin
                    state_res_valid_q <= 1'b0;
                end
                else if (~sync_rst_ni) begin
                    state_res_valid_q <= 1'b0;
                end
                else if (state_res_ready) begin
                    state_res_valid_q <= state_res_valid_d;
                end
            end
            always_ff @(posedge clk_i) begin : vproc_elem_stage_res
                if (state_res_ready & state_res_valid_d) begin
                    state_res_q    <= state_res_d;
                    quantum_elem1_q <= quantum_elem1_d; // quantum qvproc
                    quantum_elem2_q <= quantum_elem2_d; // quantum qvproc
                    counter_q      <= counter_d;
                    result_q       <= result_d;
                    result_mask_q  <= result_mask_d;
                    result_valid_q <= result_valid_d;
                end
            end
            assign state_res_ready = ~state_res_valid_q | pipe_out_ready_i;
        end else begin
            // TODO result needs always to be buffered as well
            always_comb begin
                state_res_valid_q = state_res_valid_d;
                state_res_q       = state_res_d;
                quantum_elem1_q   = quantum_elem1_d; // quantum qvproc
                quantum_elem2_q   = quantum_elem2_d; // quantum qvproc
                result_q          = result_d;
                result_mask_q     = result_mask_d;
                result_valid_q    = result_valid_d;
            end
            always_ff @(posedge clk_i) begin
                if (state_res_ready & state_res_valid_d) begin
                    counter_q <= counter_d;
                end
            end
            assign state_res_ready = pipe_out_ready_i;
        end
    endgenerate


    ///////////////////////////////////////////////////////////////////////////
    // ELEM OPERAND AND RESULT CONVERSION

    assign pipe_in_ready_o   = state_res_ready;
    assign state_res_valid_d = pipe_in_valid_i;
    assign state_res_d       = pipe_in_ctrl_i;
    // assign quantum_elem1_d   = pipe_in_op1_i; // quantum qvproc
    // assign quantum_elem2_d   = pipe_in_op2_i; // quantum qvproc
    // The original export forwarded the full 32-bit packed operand word. // quantum qvproc
    // That exposed unpacker micro-steps and x-filled padding instead of a stable, meaningful quantum slice. // quantum qvproc

    logic [31:0]            elem1, elem2;
    logic                   elem_idx_valid_q;
    logic                   mask_q;
    logic [GATHER_OP_W-1:0] gather_shift_q;
    logic                   v0msk_q;
    assign elem1          = pipe_in_op1_i;
    assign elem2          = pipe_in_op2_i;
    assign mask_q         = pipe_in_op2_mask_i;
    assign gather_shift_q = pipe_in_op_gather_i;
    assign v0msk_q        = pipe_in_mask_i;

    logic [31:0] gather_byte_idx;
    always_comb begin
        gather_byte_idx = DONT_CARE_ZERO ? '0 : 'x;
        unique case (pipe_in_ctrl_i.eew)
            VSEW_8:  gather_byte_idx = {24'b0                            , elem2[7 :0]       };
            VSEW_16: gather_byte_idx = {15'b0                            , elem2[15:0], 1'b0 };
            VSEW_32: gather_byte_idx = {elem2[31] | elem2[30] | elem2[29], elem2[28:0], 2'b00};
            default: ;
        endcase
    end
    always_comb begin
        elem_idx_valid_q = DONT_CARE_ZERO ? '0 : 'x;
        unique case (pipe_in_ctrl_i.emul)
            EMUL_1: elem_idx_valid_q = gather_byte_idx[31:$clog2(VREG_W/8)  ] == '0;
            EMUL_2: elem_idx_valid_q = gather_byte_idx[31:$clog2(VREG_W/8)+1] == '0;
            EMUL_4: elem_idx_valid_q = gather_byte_idx[31:$clog2(VREG_W/8)+2] == '0;
            EMUL_8: elem_idx_valid_q = gather_byte_idx[31:$clog2(VREG_W/8)+3] == '0;
            default: ;
        endcase
    end

    // XREG write-back
    assign pipe_out_xreg_valid_o = state_res_q.mode.elem.xreg & ((state_res_q.mode.elem.op == ELEM_XMV) ? state_res_q.first_cycle : state_res_q.last_cycle);
    assign pipe_out_xreg_data_o  = result_q;
    assign pipe_out_xreg_addr_o  = state_res_q.res_vaddr;

    assign pipe_out_valid_o     = state_res_valid_q;
    assign pipe_out_ctrl_o      = state_res_q;
    assign pipe_out_res_valid_o = result_valid_q;
    assign pipe_out_res_o       = result_q;
    assign pipe_out_mask_o      = {4{result_mask_q}};

    function automatic logic [31:0] quantum_trace_slice(input logic [31:0] in, input cfg_vsew eew); // quantum qvproc
        begin // quantum qvproc
            quantum_trace_slice = 32'h00000000; // quantum qvproc
            unique case (eew) // quantum qvproc
                VSEW_8:  quantum_trace_slice = {24'h000000, in[7 :0 ]}; // quantum qvproc
                VSEW_16: quantum_trace_slice = {16'h0000  , in[15:0 ]}; // quantum qvproc
                VSEW_32: quantum_trace_slice =               in[31:0 ]; // quantum qvproc
                default: ; // quantum qvproc
            endcase // quantum qvproc
        end // quantum qvproc
    endfunction // quantum qvproc

    logic quantum_slice_valid_q; // quantum qvproc
    assign quantum_elem1_d       = quantum_trace_slice(pipe_in_op1_i, pipe_in_ctrl_i.eew); // quantum qvproc
    // assign quantum_elem2_d       = quantum_trace_slice(pipe_in_op2_i, pipe_in_ctrl_i.eew); // quantum qvproc
    // assign quantum_elem2_d       = (pipe_in_ctrl_i.mode.elem.op == ELEM_QSINGLE) ? pipe_in_op2_i : quantum_trace_slice(pipe_in_op2_i, pipe_in_ctrl_i.eew); // quantum qvproc
    // QSG now forwards a scalar 32-bit payload selected by rs2, while QRV forwards a full 32-bit
    // angle operand. Other quantum instructions continue to use the normal EEW-sized slice export. // quantum qvproc
    assign quantum_elem2_d       = ((pipe_in_ctrl_i.mode.elem.op == ELEM_QSINGLE) || (pipe_in_ctrl_i.mode.elem.op == ELEM_QROTV)) ?
                                   pipe_in_op2_i : quantum_trace_slice(pipe_in_op2_i, pipe_in_ctrl_i.eew); // quantum qvproc
    // assign quantum_slice_valid_q = state_res_valid_q & result_valid_q & result_mask_q & ~state_res_q.vl_part_0 & quantum_phase_valid_q;
    // The EMUL-based phase filter added here proved too aggressive in simulation: instead of
    // removing only the two warm-up micro-steps for large LMUL cases, it also suppressed most of
    // the valid m4/m8 element stream. Keep that experimental filter commented for reference and
    // restore the broader slice-valid condition until a more precise phase discriminator is
    // characterized. // quantum qvproc
    assign quantum_slice_valid_q = state_res_valid_q & result_valid_q & result_mask_q & ~state_res_q.vl_part_0; // quantum qvproc

    /*
     * Export per-slice quantum activity before the later vector pack/writeback
     * stages merge slices into full vector-word writes. These outputs are only
     * marked valid for the custom quantum opcodes so external logic can sample
     * a clean, operation-aligned trace stream.
     */
    function automatic logic is_quantum_opcode(input opcode_elem op); // quantum qvproc
        begin
            is_quantum_opcode = (op == ELEM_QSINGLE) | 
                                (op == ELEM_QPAIR  ) | 
                                (op == ELEM_QROTG  ) | 
                                (op == ELEM_QROTV  ); 
        end
    endfunction
    // assign quantum_valid_o       = state_res_valid_q & is_quantum_opcode(state_res_q.mode.elem.op);
    // assign quantum_op_o          = state_res_q.mode.elem.op;
    // assign quantum_instr_id_o    = state_res_q.id;
    // assign quantum_vd_addr_o     = state_res_q.res_vaddr;
    // assign quantum_elem1_o       = quantum_elem1_q;
    // assign quantum_elem2_o       = quantum_elem2_q;
    // The original export marked every buffered ELEM micro-step as valid and exposed the raw packed operand words. // quantum qvproc
    // Keep these lines commented for reference while switching the trace interface to one meaningful slice per valid quantum element. // quantum qvproc
    assign quantum_valid_o       = quantum_slice_valid_q & is_quantum_opcode(state_res_q.mode.elem.op); // quantum qvproc
    assign quantum_op_o          = state_res_q.mode.elem.op; // quantum qvproc
    assign quantum_instr_id_o    = state_res_q.id; // quantum qvproc
    assign quantum_vd_addr_o     = state_res_q.res_vaddr; // quantum qvproc
    assign quantum_elem1_o       = quantum_trace_slice(quantum_elem1_q, state_res_q.eew); // quantum qvproc
    // assign quantum_elem2_o       = quantum_trace_slice(quantum_elem2_q, state_res_q.eew); // quantum qvproc
    // assign quantum_elem2_o       = (state_res_q.mode.elem.op == ELEM_QSINGLE) ? quantum_elem2_q : quantum_trace_slice(quantum_elem2_q, state_res_q.eew); // quantum qvproc
    // QSG exports the scalar rs2 payload on elem2 and its packed gate/control metadata on elem3.
    // QRV exports its full 32-bit angle operand on elem2 every cycle. // quantum qvproc
    assign quantum_elem2_o       = ((state_res_q.mode.elem.op == ELEM_QSINGLE) || (state_res_q.mode.elem.op == ELEM_QROTV)) ?
                                   quantum_elem2_q : quantum_trace_slice(quantum_elem2_q, state_res_q.eew); // quantum qvproc
    assign quantum_elem3_o       = ((state_res_q.mode.elem.op == ELEM_QSINGLE) || (state_res_q.mode.elem.op == ELEM_QPAIR) || (state_res_q.mode.elem.op == ELEM_QROTG) || (state_res_q.mode.elem.op == ELEM_QROTV)) ?
                                   state_res_q.quantum_elem3_raw : 32'b0; // quantum qvproc
    assign quantum_lmul_o        = state_res_q.lmul; // quantum qvproc
    assign quantum_emul_o        = state_res_q.emul; // quantum qvproc
    assign quantum_count_mul_o   = state_res_q.count_mul; // quantum qvproc
    assign quantum_first_cycle_o = state_res_q.first_cycle; // quantum qvproc
    assign quantum_last_cycle_o  = state_res_q.last_cycle; // quantum qvproc
    assign quantum_vl_part_0_o   = state_res_q.vl_part_0; // quantum qvproc
    assign quantum_res_vaddr_o   = state_res_q.res_vaddr; // quantum qvproc


    ///////////////////////////////////////////////////////////////////////////
    // ELEM OPERATION:

    logic counter_inc;
    assign counter_d = (pipe_in_ctrl_i.first_cycle ? 32'b0 : counter_q) + {31'b0, counter_inc};

    logic        v0msk;
    logic [31:0] reduct_val;
    assign v0msk      = v0msk_q | ~pipe_in_ctrl_i.mode.elem.masked;
    assign reduct_val = pipe_in_ctrl_i.first_cycle ? elem2 : result_q;

    // Helper for quantum rotation operations: rotate left within active EEW lane width.
    function automatic logic [31:0] rotl_elem(
        input logic [31:0] in,
        input logic [4:0]  shamt,
        input cfg_vsew     eew
    );
        logic [31:0] out;
        logic [4:0]  sh;
        begin
            out = in;
            unique case (eew)
                VSEW_8: begin
                    // 8-bit lane rotation keeps operation local to one quantum index byte.
                    sh = {2'b00, shamt[2:0]};
                    // Guard shift-by-zero to avoid undefined opposite-shift expression.
                    out[7:0] = (sh == '0) ? in[7:0] : ((in[7:0] << sh) | (in[7:0] >> (5'd8 - sh)));
                end
                VSEW_16: begin
                    // 16-bit lane rotation keeps operation local to one half-word lane.
                    sh = {1'b0, shamt[3:0]};
                    // Guard shift-by-zero to avoid undefined opposite-shift expression.
                    out[15:0] = (sh == '0) ? in[15:0] : ((in[15:0] << sh) | (in[15:0] >> (5'd16 - sh)));
                end
                VSEW_32: begin
                    // 32-bit lane rotation applies to the full lane.
                    sh = shamt;
                    // Guard shift-by-zero to avoid undefined opposite-shift expression.
                    out = (sh == '0) ? in : ((in << sh) | (in >> (6'd32 - {1'b0, sh})));
                end
                default: ;
            endcase
            rotl_elem = out;
        end
    endfunction

    always_comb begin
        counter_inc    = DONT_CARE_ZERO ? '0 : 'x;
        result_d       = DONT_CARE_ZERO ? '0 : 'x;
        result_mask_d  = DONT_CARE_ZERO ? '0 : 'x;
        result_valid_d = DONT_CARE_ZERO ? '0 : 'x;
        unique case (pipe_in_ctrl_i.mode.elem.op)
            // move from vreg index 0 to xreg with sign extension
            ELEM_XMV: begin
                unique case (pipe_in_ctrl_i.eew)
                    VSEW_8:  result_d = {{24{elem1[7 ]}}, elem1[7 :0]};
                    VSEW_16: result_d = {{16{elem1[15]}}, elem1[15:0]};
                    VSEW_32: result_d =                   elem1       ;
                    default: ;
                endcase
            end
            // vid writes each element's index to the destination vreg and can
            // be masked by v0
            ELEM_VID: begin
                counter_inc    = 1'b1;
                result_d       = pipe_in_ctrl_i.first_cycle ? '0 : counter_q;
                result_mask_d  = ~pipe_in_ctrl_i.vl_part_0 & v0msk;
                result_valid_d = 1'b1;
            end
            // vpopc and viota count the number of set bits in a mask vreg;
            // both can be masked by v0, in which case only unmasked elements
            // contribute to the sum and for viota only unmasked elements are
            // written
            ELEM_VPOPC,
            ELEM_VIOTA: begin
                counter_inc    = mask_q & ~pipe_in_ctrl_i.vl_part_0 & v0msk;
                result_d       = pipe_in_ctrl_i.first_cycle ? '0 : counter_q;
                result_mask_d  = ~pipe_in_ctrl_i.vl_part_0 & v0msk;
                result_valid_d = 1'b1;
            end
            // vfirst finds the index of the first set bit in a mask vreg and
            // returns -1 if there is none; can be masked by v0
            ELEM_VFIRST: begin
                counter_inc    = pipe_in_ctrl_i.first_cycle | (result_q[31] & ~mask_q);
                result_d       = pipe_in_ctrl_i.first_cycle ? {32{~mask_q}} : (result_q[31] & ~mask_q) ? '1 : counter_q;
                result_mask_d  = ~pipe_in_ctrl_i.vl_part_0 & v0msk;
                result_valid_d = 1'b1;
            end
            // vcompress packs elements for which the corresponding bit in a
            // mask vreg is set; cannot be masked by v0
            ELEM_VCOMPRESS: begin
                result_d       = elem2;
                result_mask_d  = ~pipe_in_ctrl_i.vl_part_0;
                result_valid_d = mask_q;
            end
            // vgather gathers elements from a vreg based on indices from a
            // second vreg; can be masked by v0
            ELEM_VRGATHER: begin
                result_d = (pipe_in_ctrl_i.aux_count == '0) ? '0 : result_q;
                //if (pipe_in_ctrl_i.aux_count == elem2[$clog2(VREG_W/8)-1:$clog2(GATHER_OP_W/8)]) begin
                if (pipe_in_ctrl_i.aux_count == gather_byte_idx[$clog2(VREG_W/8)-1:$clog2(GATHER_OP_W/8)]) begin
                    result_d       = gather_shift_q[{{$clog2(VREG_W/GATHER_OP_W){1'b0}}, gather_byte_idx[$clog2(GATHER_OP_W/8)-1:0] & ({$clog2(GATHER_OP_W/8){1'b1}} << 2)} * 8 +: 32];
                    result_d[15:0] = gather_shift_q[{{$clog2(VREG_W/GATHER_OP_W){1'b0}}, gather_byte_idx[$clog2(GATHER_OP_W/8)-1:0] & ({$clog2(GATHER_OP_W/8){1'b1}} << 1)} * 8 +: 16];
                    result_d[7 :0] = gather_shift_q[{{$clog2(VREG_W/GATHER_OP_W){1'b0}}, gather_byte_idx[$clog2(GATHER_OP_W/8)-1:0] & ({$clog2(GATHER_OP_W/8){1'b1}}     )} * 8 +: 8 ];
                    if (~elem_idx_valid_q) begin
                        result_d = '0;
                    end
                end
                result_mask_d  = ~pipe_in_ctrl_i.vl_part_0 & v0msk;
                result_valid_d = pipe_in_ctrl_i.aux_count == '1;
            end
            // flush the destination register after a vcompress or reduction
            // (note that a flush might potentially write to more registers
            // than are part of the vreg group, but for these the write mask
            // will be all 0s)
            ELEM_FLUSH: begin
                result_mask_d  = 1'b0;
                result_valid_d = 1'b1;
            end

            // reduction operations
            // TODO support masked reductions (currently only unmasked)
            ELEM_VREDSUM: begin
                result_d       = ~pipe_in_ctrl_i.vl_part_0 ? (elem1 + reduct_val) : reduct_val;
                result_mask_d  = ~pipe_in_ctrl_i.vl_0;
                result_valid_d = pipe_in_ctrl_i.last_cycle;
            end
            ELEM_VREDAND: begin
                result_d       = ~pipe_in_ctrl_i.vl_part_0 ? (elem1 & reduct_val) : reduct_val;
                result_mask_d  = ~pipe_in_ctrl_i.vl_0;
                result_valid_d = pipe_in_ctrl_i.last_cycle;
            end
            ELEM_VREDOR: begin
                result_d       = ~pipe_in_ctrl_i.vl_part_0 ? (elem1 | reduct_val) : reduct_val;
                result_mask_d  = ~pipe_in_ctrl_i.vl_0;
                result_valid_d = pipe_in_ctrl_i.last_cycle;
            end
            ELEM_VREDXOR: begin
                result_d       = ~pipe_in_ctrl_i.vl_part_0 ? (elem1 ^ reduct_val) : reduct_val;
                result_mask_d  = ~pipe_in_ctrl_i.vl_0;
                result_valid_d = pipe_in_ctrl_i.last_cycle;
            end
            ELEM_VREDMINU: begin
                result_d = reduct_val;
                if (~pipe_in_ctrl_i.vl_part_0) begin
                    unique case (pipe_in_ctrl_i.eew)
                        VSEW_8:  result_d[7 :0] = (elem1[7 :0] < reduct_val[7 :0]) ? elem1[7 :0] : reduct_val[7 :0];
                        VSEW_16: result_d[15:0] = (elem1[15:0] < reduct_val[15:0]) ? elem1[15:0] : reduct_val[15:0];
                        VSEW_32: result_d       = (elem1       < reduct_val      ) ? elem1       : reduct_val      ;
                        default: ;
                    endcase
                end
                result_mask_d  = ~pipe_in_ctrl_i.vl_0;
                result_valid_d = pipe_in_ctrl_i.last_cycle;
            end
            ELEM_VREDMIN: begin
                result_d = reduct_val;
                if (~pipe_in_ctrl_i.vl_part_0) begin
                    unique case (pipe_in_ctrl_i.eew)
                        VSEW_8:  result_d[7 :0] = ($signed(elem1[7 :0]) < $signed(reduct_val[7 :0])) ? elem1[7 :0] : reduct_val[7 :0];
                        VSEW_16: result_d[15:0] = ($signed(elem1[15:0]) < $signed(reduct_val[15:0])) ? elem1[15:0] : reduct_val[15:0];
                        VSEW_32: result_d       = ($signed(elem1      ) < $signed(reduct_val      )) ? elem1       : reduct_val      ;
                        default: ;
                    endcase
                end
                result_mask_d  = ~pipe_in_ctrl_i.vl_0;
                result_valid_d = pipe_in_ctrl_i.last_cycle;
            end
            ELEM_VREDMAXU: begin
                result_d = reduct_val;
                if (~pipe_in_ctrl_i.vl_part_0) begin
                    unique case (pipe_in_ctrl_i.eew)
                        VSEW_8:  result_d[7 :0] = (elem1[7 :0] > reduct_val[7 :0]) ? elem1[7 :0] : reduct_val[7 :0];
                        VSEW_16: result_d[15:0] = (elem1[15:0] > reduct_val[15:0]) ? elem1[15:0] : reduct_val[15:0];
                        VSEW_32: result_d       = (elem1       > reduct_val      ) ? elem1       : reduct_val      ;
                        default: ;
                    endcase
                end
                result_mask_d  = ~pipe_in_ctrl_i.vl_0;
                result_valid_d = pipe_in_ctrl_i.last_cycle;
            end
            ELEM_VREDMAX: begin
                result_d = reduct_val;
                if (~pipe_in_ctrl_i.vl_part_0) begin
                    unique case (pipe_in_ctrl_i.eew)
                        VSEW_8:  result_d[7 :0] = ($signed(elem1[7 :0]) > $signed(reduct_val[7 :0])) ? elem1[7 :0] : reduct_val[7 :0];
                        VSEW_16: result_d[15:0] = ($signed(elem1[15:0]) > $signed(reduct_val[15:0])) ? elem1[15:0] : reduct_val[15:0];
                        VSEW_32: result_d       = ($signed(elem1      ) > $signed(reduct_val      )) ? elem1       : reduct_val      ;
                        default: ;
                    endcase
                end
                result_mask_d  = ~pipe_in_ctrl_i.vl_0;
                result_valid_d = pipe_in_ctrl_i.last_cycle;
            end
            ELEM_QSINGLE: begin // quantum qvproc
                // Gate selection remains encoded in the QSG control word at bits [31:25], while
                // elem2 now carries a separate 32-bit scalar payload from rs2.
                result_d       = elem1 ^ {25'b0, pipe_in_ctrl_i.quantum_elem3_raw[31:25]};
                // Respect VL truncation and vm masking so semantics match vector ops.
                result_mask_d  = ~pipe_in_ctrl_i.vl_part_0 & v0msk; 
                // Emit one valid result per active element.
                result_valid_d = 1'b1; 
            end
            ELEM_QPAIR: begin // quantum qvproc
                // Pair operation maps to element-wise mixing of source and target.
                // Model pair interaction as deterministic two-source XOR transform.
                result_d       = elem1 ^ elem2;
                // Respect VL truncation and vm masking so semantics match vector ops.
                result_mask_d  = ~pipe_in_ctrl_i.vl_part_0 & v0msk; 
                // Emit one valid result per active element.
                result_valid_d = 1'b1; 
            end
            ELEM_QROTG: begin // quantum qvproc
                // Global rotation amount comes from scalar xval (rs2 in decode override).
                // Apply per-lane rotate-left using current EEW lane width.
                result_d       = rotl_elem(elem1, pipe_in_ctrl_i.xval[4:0], pipe_in_ctrl_i.eew); 
                // Respect VL truncation and vm masking so semantics match vector ops.
                result_mask_d  = ~pipe_in_ctrl_i.vl_part_0 & v0msk; 
                // Emit one valid result per active element.
                result_valid_d = 1'b1; 
            end
            ELEM_QROTV: begin // quantum qvproc TODO: the second operand from the second vector register should have sew = 32 instead of 8.
                // Per-element rotation amount comes from second vector operand.
                // Apply per-lane rotate-left with lane-specific shift from elem2.
                result_d       = rotl_elem(elem1, elem2[4:0], pipe_in_ctrl_i.eew); 
                // Respect VL truncation and vm masking so semantics match vector ops.
                result_mask_d  = ~pipe_in_ctrl_i.vl_part_0 & v0msk;
                // Emit one valid result per active element.
                result_valid_d = 1'b1; 
            end
            default: ;

        endcase
    end


endmodule
