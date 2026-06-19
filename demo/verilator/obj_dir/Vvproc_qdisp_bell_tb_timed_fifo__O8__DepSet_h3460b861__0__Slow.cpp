// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvproc_qdisp_bell_tb.h for the primary calling header

#include "Vvproc_qdisp_bell_tb__pch.h"
#include "Vvproc_qdisp_bell_tb_timed_fifo__O8.h"

VL_ATTR_COLD void Vvproc_qdisp_bell_tb_timed_fifo__O8___ctor_var_reset(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->i_fifo_time = VL_RAND_RESET_I(20);
    vlSelf->i_fifo_op = VL_RAND_RESET_I(8);
    vlSelf->i_fifo_we = VL_RAND_RESET_I(1);
    vlSelf->t_cnt = VL_RAND_RESET_I(20);
    vlSelf->o_data = VL_RAND_RESET_I(8);
    vlSelf->o_valid = VL_RAND_RESET_I(1);
    vlSelf->error = VL_RAND_RESET_I(1);
    vlSelf->__PVT__fifo_rd_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__fifo_full = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vi0] = VL_RAND_RESET_I(28);
    }
    vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = VL_RAND_RESET_I(28);
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = VL_RAND_RESET_I(4);
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = VL_RAND_RESET_I(4);
    vlSelf->__PVT__u_time_ctrl__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->__PVT__u_time_ctrl__DOT__next_state = VL_RAND_RESET_I(2);
}
