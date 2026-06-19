// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvproc_qdisp_bell_tb.h for the primary calling header

#include "Vvproc_qdisp_bell_tb__pch.h"
#include "Vvproc_qdisp_bell_tb__Syms.h"
#include "Vvproc_qdisp_bell_tb_timed_fifo__O8.h"

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__0__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__0__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                   & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        << 7U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__0__KET____DOT__u_timed_fifo__1(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__0__KET____DOT__u_timed_fifo__1\n"); );
    // Body
    vlSelf->__PVT__u_time_ctrl__DOT__next_state = (
                                                   (0U 
                                                    == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))
                                                    ? 
                                                   ((IData)(vlSelf->__PVT__fifo_empty)
                                                     ? 0U
                                                     : 1U)
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))
                                                     ? 
                                                    (((0xfffffU 
                                                       & (vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                                                          >> 8U)) 
                                                      <= 
                                                      (0xfffffU 
                                                       & ((IData)(1U) 
                                                          + vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__t_cnt_r)))
                                                      ? 2U
                                                      : 1U)
                                                     : 0U));
}

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__1__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__1__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 1U) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        << 6U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__2__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__2__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 2U) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        << 5U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__3__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__3__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 3U) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        << 4U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__4__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__4__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 4U) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        << 3U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__5__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__5__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 5U) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        << 2U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__6__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__6__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 6U) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        << 1U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__7__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__7__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 7U) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & (IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl)) 
                              | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                 >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__8__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__8__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 8U) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        >> 1U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__9__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__9__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 9U) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        >> 2U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__10__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__10__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 0xaU) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        >> 3U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__11__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__11__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 0xbU) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        >> 4U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__12__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__12__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 0xcU) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        >> 5U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__13__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__13__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 0xdU) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        >> 6U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__14__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__14__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((1U & (((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                    >> 0xeU) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        >> 7U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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

VL_INLINE_OPT void Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__15__KET____DOT__u_timed_fifo__0(Vvproc_qdisp_bell_tb_timed_fifo__O8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vvproc_qdisp_bell_tb_timed_fifo__O8___nba_sequent__TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__15__KET____DOT__u_timed_fifo__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__write_ptr;
    __Vdly__u_inst_fifo__DOT__write_ptr = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v0;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__u_inst_fifo__DOT__memory__v8;
    __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 = 0;
    IData/*27:0*/ __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    __Vdlyvval__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*0:0*/ __Vdlyvset__u_inst_fifo__DOT__memory__v8;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0;
    CData/*3:0*/ __Vdly__u_inst_fifo__DOT__read_ptr;
    __Vdly__u_inst_fifo__DOT__read_ptr = 0;
    // Body
    __Vdly__u_inst_fifo__DOT__read_ptr = vlSelf->__PVT__u_inst_fifo__DOT__read_ptr;
    __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 0U;
    __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 0U;
    __Vdly__u_inst_fifo__DOT__write_ptr = vlSelf->__PVT__u_inst_fifo__DOT__write_ptr;
    if (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__rst) {
        __Vdly__u_inst_fifo__DOT__write_ptr = 0U;
        __Vdlyvset__u_inst_fifo__DOT__memory__v0 = 1U;
        vlSelf->__PVT__u_time_ctrl__DOT__state = 0U;
        __Vdly__u_inst_fifo__DOT__read_ptr = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg = 0U;
    } else {
        if ((IData)((((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                      >> 0xfU) & (~ (IData)(vlSelf->__PVT__fifo_full))))) {
            __Vdlyvval__u_inst_fifo__DOT__memory__v8 
                = ((vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__dispatch_time 
                    << 8U) | ((0x80U & ((IData)(vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                                        >> 8U)) | (vlSymsp->TOP.vproc_qdisp_bell_tb__DOT__quantum_elem3 
                                                   >> 0x19U)));
            __Vdlyvset__u_inst_fifo__DOT__memory__v8 = 1U;
            __Vdlyvdim0__u_inst_fifo__DOT__memory__v8 
                = (7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
            __Vdly__u_inst_fifo__DOT__write_ptr = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr)));
        }
        vlSelf->__PVT__u_time_ctrl__DOT__state = vlSelf->__PVT__u_time_ctrl__DOT__next_state;
        if (((IData)(vlSelf->__PVT__fifo_rd_en) & (~ (IData)(vlSelf->__PVT__fifo_empty)))) {
            vlSelf->__PVT__u_inst_fifo__DOT__data_out_reg 
                = vlSelf->__PVT__u_inst_fifo__DOT__memory
                [(7U & (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr))];
            __Vdly__u_inst_fifo__DOT__read_ptr = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr)));
        }
    }
    vlSelf->__PVT__u_inst_fifo__DOT__write_ptr = __Vdly__u_inst_fifo__DOT__write_ptr;
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v0) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[0U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[1U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[2U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[3U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[4U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[5U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[6U] = 0U;
        vlSelf->__PVT__u_inst_fifo__DOT__memory[7U] = 0U;
    }
    if (__Vdlyvset__u_inst_fifo__DOT__memory__v8) {
        vlSelf->__PVT__u_inst_fifo__DOT__memory[__Vdlyvdim0__u_inst_fifo__DOT__memory__v8] 
            = __Vdlyvval__u_inst_fifo__DOT__memory__v8;
    }
    vlSelf->__PVT__u_inst_fifo__DOT__read_ptr = __Vdly__u_inst_fifo__DOT__read_ptr;
    vlSelf->__PVT__fifo_rd_en = 0U;
    if ((0U == (IData)(vlSelf->__PVT__u_time_ctrl__DOT__state))) {
        vlSelf->__PVT__fifo_rd_en = 1U;
    }
    vlSelf->o_valid = 0U;
    vlSelf->__PVT__fifo_empty = ((IData)(vlSelf->__PVT__u_inst_fifo__DOT__read_ptr) 
                                 == (IData)(vlSelf->__PVT__u_inst_fifo__DOT__write_ptr));
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
