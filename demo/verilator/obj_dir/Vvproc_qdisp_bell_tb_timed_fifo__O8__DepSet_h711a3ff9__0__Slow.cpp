// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvproc_qdisp_bell_tb.h for the primary calling header

#include "Vvproc_qdisp_bell_tb__pch.h"
#include "Vvproc_qdisp_bell_tb__Syms.h"
#include "Vvproc_qdisp_bell_tb_timed_fifo__O8.h"

VL_ATTR_COLD void Vvproc_qdisp_bell_tb_timed_fifo__O8___stl_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__0__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___stl_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__0__KET____DOT__u_timed_fifo__0\n"); );
    // Body
    vlSelf->__PVT__fifo_rd_en = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__next_state 
            = ((IData)(vlSelf->__PVT__fifo_empty) ? 0U
                : 1U);
    } else {
        vlSelf->__PVT__u_time_ctrl__DOT__next_state 
            = ((1U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))
                ? (((0xfffffU & (vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                                 >> 8U)) <= (0xfffffU 
                                             & ((IData)(1U) 
                                                + vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__t_cnt_r)))
                    ? 2U : 1U) : 0U);
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_full = (((1U & ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr) 
                                        >> 3U)) != 
                                 (1U & ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                        >> 3U))) & 
                                ((7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)) 
                                 == (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))));
    vlSelf->o_data = 0U;
    if ((0U != (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        if ((2U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
            vlSelf->o_valid = 1U;
            vlSelf->o_data = (0xffU & vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg);
        }
    }
}
