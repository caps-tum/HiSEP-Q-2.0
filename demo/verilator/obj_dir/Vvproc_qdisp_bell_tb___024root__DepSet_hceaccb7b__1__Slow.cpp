// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvproc_qdisp_bell_tb.h for the primary calling header

#include "Vvproc_qdisp_bell_tb__pch.h"
#include "Vvproc_qdisp_bell_tb__Syms.h"
#include "Vvproc_qdisp_bell_tb___024root.h"

extern const VlUnpacked<CData/*0:0*/, 64> Vvproc_qdisp_bell_tb__ConstPool__TABLE_h6451e8c0_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vvproc_qdisp_bell_tb__ConstPool__TABLE_h2aabc56c_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vvproc_qdisp_bell_tb__ConstPool__TABLE_hf64aebe0_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vvproc_qdisp_bell_tb__ConstPool__TABLE_h323b7bc3_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vvproc_qdisp_bell_tb__ConstPool__TABLE_h6d182578_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vvproc_qdisp_bell_tb__ConstPool__TABLE_hbf9cbdd6_0;
extern const VlUnpacked<CData/*2:0*/, 256> Vvproc_qdisp_bell_tb__ConstPool__TABLE_ha97e7bf2_0;
extern const VlUnpacked<CData/*2:0*/, 256> Vvproc_qdisp_bell_tb__ConstPool__TABLE_hfcf48252_0;

VL_ATTR_COLD void Vvproc_qdisp_bell_tb___024root___stl_sequent__TOP__1(Vvproc_qdisp_bell_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvproc_qdisp_bell_tb___024root___stl_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__first_cycle_seen_next;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__first_cycle_seen_next = 0;
    IData/*31:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__quantum_qrotv_ready_holdoff_cycles;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__quantum_qrotv_ready_holdoff_cycles = 0;
    IData/*31:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b = 0;
    IData/*31:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev = 0;
    IData/*31:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand = 0;
    QData/*32:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed = 0;
    QData/*32:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext = 0;
    QData/*33:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res = 0;
    CData/*6:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o = 0;
    CData/*1:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 0;
    CData/*1:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0;
    CData/*1:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vsew_o;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vsew_o = 0;
    CData/*0:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_en_d;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_en_d = 0;
    CData/*4:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_addr_d;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_addr_d = 0;
    CData/*1:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__pipe_vreg_wr_ready;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__pipe_vreg_wr_ready = 0;
    CData/*0:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vlvbound_h9642f6c1__0;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vlvbound_h9642f6c1__0 = 0;
    CData/*4:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vlvbound_hf986c43c__0;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vlvbound_hf986c43c__0 = 0;
    CData/*2:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask = 0;
    CData/*2:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask_narrow;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask_narrow = 0;
    IData/*31:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j = 0;
    SData/*15:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o = 0;
    CData/*1:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_store_o;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_store_o = 0;
    CData/*0:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_last_cycle;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_last_cycle = 0;
    CData/*0:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_valid;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_valid = 0;
    QData/*63:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data = 0;
    QData/*63:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask = 0;
    CData/*7:0*/ vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT____Vcellout__unit_mux__pipe_out_res_flags_o;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT____Vcellout__unit_mux__pipe_out_res_flags_o = 0;
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    VlWide<8>/*255:0*/ __Vtemp_3;
    VlWide<5>/*159:0*/ __Vtemp_10;
    // Body
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__issue_id_used 
        = (0U != (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_state_q) 
                        >> (0xfU & VL_SHIFTL_III(4,32,32, 
                                                 (7U 
                                                  & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 2U)), 1U)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[5U] 
        = ((0x1ffffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[5U]) 
           | (0xe000000U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                            << 0x17U)));
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h3dd3c473__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o 
        = (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d96565c__0) 
            << 5U) | (0x1fU & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                               >> 0xeU)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
        = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d9645e9__0)) 
            << 0x25U) | (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d94a629__0)) 
                          << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d93fe75__0))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h4b4b6c32__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__evl_pol = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d8d2c5f__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
        = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d9645e9__1)) 
            << 0x25U) | (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d94a629__1)) 
                          << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d93fe75__1))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_hd027af76__0;
    if ((0x2000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
        if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                      >> 0xcU)))) {
            if ((0x800U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                              >> 0xaU)))) {
                    if ((0x200U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                        if ((0x100U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                            if ((0x80U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                if ((7U != (7U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x13U)))) {
                                    if ((0x40U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((0x20U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x10U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (8U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (4U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        if (
                                                            (2U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                            if (
                                                                (0x200000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (0x100000U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ 
                                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                             >> 0x13U)))) {
                                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                                    }
                                                                }
                                                            } else if (
                                                                       (0x100000U 
                                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                                }
                                                            }
                                                        } else if (
                                                                   (0x200000U 
                                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (0x100000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                                }
                                                            }
                                                        } else if (
                                                                   (0x100000U 
                                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                            }
                                                        }
                                                    } else if (
                                                               (2U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        if (
                                                            (0x200000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (0x100000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                                }
                                                            }
                                                        } else if (
                                                                   (0x100000U 
                                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x200000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                        }
                                                    }
                                                } else if (
                                                           (4U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (2U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                        }
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                >> 1U)))) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (8U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (4U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (2U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 2U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (2U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x200000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (4U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (2U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x200000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (2U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                }
                                            } else if (
                                                       (0x200000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x100000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                            }
                                        } else if (
                                                   (0x10U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((8U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (4U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (2U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        if (
                                                            (0x200000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (0x100000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (~ 
                                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                            >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                    = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                            }
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x14U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                                }
                                                            }
                                                        } else if (
                                                                   (0x100000U 
                                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (0x80000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                    = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                            } else {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                        >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                        }
                                                    } else if (
                                                               (0x200000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x14U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                    = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x80000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                    }
                                                } else if (
                                                           (2U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                        >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x14U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        if (
                                                            (0x80000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                    }
                                                } else if (
                                                           (0x200000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x80000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 3U;
                                                }
                                            } else if (
                                                       (4U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (2U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                        >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                            = 
                                                            ((0x80000U 
                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])
                                                              ? (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q)
                                                              : 2U);
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                    }
                                                } else if (
                                                           (0x200000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x80000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                }
                                            } else if (
                                                       (2U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            } else if (
                                                       (0x200000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                            }
                                        } else if (
                                                   (8U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((4U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (2U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                        >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (2U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            }
                                        } else if (
                                                   (4U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((2U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            }
                                        } else if (
                                                   (2U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                        }
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                    >> 5U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                     >> 4U)))) {
                                                if (
                                                    (8U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (4U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        if (
                                                            (2U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x15U)))) {
                                                                if (
                                                                    (0x100000U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                    if (
                                                                        (0x80000U 
                                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                                        if (
                                                                            (1U 
                                                                             & (~ 
                                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x1aU)))) {
                                                                            if (
                                                                                (1U 
                                                                                & (~ 
                                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x19U)))) {
                                                                                if (
                                                                                (0x1000000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                                if (
                                                                                (0x800000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                                if (
                                                                                (0x400000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 3U;
                                                                                }
                                                                                }
                                                                                } else if (
                                                                                (0x800000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                                if (
                                                                                (0x400000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 2U;
                                                                                }
                                                                                } else {
                                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul 
                                                                                = 
                                                                                ((0x400000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])
                                                                                 ? 1U
                                                                                 : 0U);
                                                                                }
                                                                            }
                                                                        }
                                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__evl_pol = 3U;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else if ((0x20U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((0x10U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((8U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (4U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (2U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        if (
                                                            (0x200000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x14U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                }
                                                            }
                                                        } else if (
                                                                   (0x100000U 
                                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (0x80000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        }
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x15U)))) {
                                                            if (
                                                                (0x100000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 0U;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (
                                                            (0x200000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x14U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                                }
                                                            }
                                                        } else if (
                                                                   (0x100000U 
                                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (0x80000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        }
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x15U)))) {
                                                            if (
                                                                (0x100000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 0U;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (2U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x14U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x80000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x15U)))) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 0U;
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x14U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x80000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x15U)))) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 0U;
                                                            }
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (4U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (2U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x14U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    }
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x15U)))) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 0U;
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x14U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    }
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x15U)))) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 0U;
                                                            }
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (2U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x80000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 0U;
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x80000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 0U;
                                                        }
                                                    }
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                        >> 3U)))) {
                                            if ((4U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (2U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x14U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x80000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                } else if (
                                                           (0x200000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x80000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            } else if (
                                                       (2U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x80000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            } else if (
                                                       (0x200000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                            }
                                        }
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                    >> 4U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                     >> 3U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                         >> 2U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                             >> 1U)))) {
                                                        if (
                                                            (0x200000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (0x100000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    if (
                                                                        (0U 
                                                                         == 
                                                                         (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                          >> 0x1bU))) {
                                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__evl_pol = 1U;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                if (
                                                    (4U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x15U)))) {
                                                            if (
                                                                (0x100000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o = 1U;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else if ((0x10U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                    >> 3U)))) {
                                            if ((4U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (2U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                    = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                        }
                                                    }
                                                } else if (
                                                           (0x200000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                    }
                                                }
                                            } else if (
                                                       (2U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o 
                                                        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vxrm_q;
                                                }
                                            }
                                        }
                                    } else if ((8U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((2U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (0x200000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            }
                                        } else if (
                                                   (2U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                            }
                                        }
                                    } else if ((4U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                            }
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                    >> 1U)))) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o = 2U;
                                        }
                                    }
                                }
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o 
                                    = (0x20U | (0x1fU 
                                                & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                   >> 0xeU)));
                                if ((7U == (7U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x13U)))) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o 
                                        = (0x1fU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o));
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                   >> 6U)))) {
                                    if ((0x20U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                    >> 4U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                     >> 3U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                         >> 2U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x15U)))) {
                                                            if (
                                                                (0x100000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x13U)))) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o 
                                                                        = 
                                                                        (0x1fU 
                                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else if ((0x10U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((4U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                         >> 1U)))) {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o 
                                                                    = 
                                                                    (0x20U 
                                                                     | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o));
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((0x1000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
            if ((0x800U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                              >> 0xaU)))) {
                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                  >> 9U)))) {
                        if ((0x100U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                            if ((0x80U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                if ((0x200000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((0x100000U 
                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                            = ((0x7f00000000ULL 
                                                & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                               | (IData)((IData)(
                                                                 (0x1fU 
                                                                  & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x16U)))));
                                    } else if ((0x80000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                            = ((0x7f00000000ULL 
                                                & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                               | (IData)((IData)(
                                                                 (0x1fU 
                                                                  & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x16U)))));
                                    }
                                } else if ((0x100000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                        = ((0x7f00000000ULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                           | (IData)((IData)(
                                                             ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                               << 0x1eU) 
                                                              | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U] 
                                                                 >> 2U)))));
                                } else if ((0x80000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                        = ((0x7f00000000ULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                           | (IData)((IData)(
                                                             ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                               << 0x1eU) 
                                                              | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U] 
                                                                 >> 2U)))));
                                }
                                if ((0x40U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((0x20U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                    >> 4U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                     >> 3U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                         >> 2U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x1fU)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                         >> 0x1eU)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ 
                                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                             >> 0x1dU)))) {
                                                                        if (
                                                                            (0x10000000U 
                                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                            if (
                                                                                (1U 
                                                                                & (~ 
                                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x1bU)))) {
                                                                                if (
                                                                                (0x100000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                                = 
                                                                                (0x600U 
                                                                                | (0x1ffU 
                                                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                                                }
                                                                            }
                                                                        } else if (
                                                                                (0x8000000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                            if (
                                                                                (0x100000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                                = 
                                                                                (0x200U 
                                                                                | (0x1ffU 
                                                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                                            }
                                                                        } else if (
                                                                                (0x100000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                                = 
                                                                                (0x400U 
                                                                                | (0x1ffU 
                                                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                   >> 5U)))) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                  >> 4U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                    >> 3U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                     >> 2U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                         >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x1fU)))) {
                                                            if (
                                                                (0x40000000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (0x20000000U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                    if (
                                                                        (0x10000000U 
                                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                        if (
                                                                            (0x8000000U 
                                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                            if (
                                                                                (0x100000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                                = 
                                                                                ((0x1ffU 
                                                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                                | (((0x80000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])
                                                                                 ? 0xfU
                                                                                 : 0xeU) 
                                                                                << 9U));
                                                                            } else if (
                                                                                (0x80000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                                = 
                                                                                (0x1a00U 
                                                                                | (0x1ffU 
                                                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                                            }
                                                                        }
                                                                    }
                                                                } else if (
                                                                           (0x10000000U 
                                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ 
                                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                             >> 0x1bU)))) {
                                                                        if (
                                                                            (0x100000U 
                                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                                = 
                                                                                ((0x1ffU 
                                                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                                | (((0x80000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])
                                                                                 ? 0xcU
                                                                                 : 0xbU) 
                                                                                << 9U));
                                                                        } else if (
                                                                                (0x80000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                                = 
                                                                                (0x1400U 
                                                                                | (0x1ffU 
                                                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                                        }
                                                                    }
                                                                } else if (
                                                                           (0x8000000U 
                                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                    if (
                                                                        (0x100000U 
                                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                            = 
                                                                            ((0x1ffU 
                                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                             | (((0x80000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])
                                                                                 ? 9U
                                                                                 : 8U) 
                                                                                << 9U));
                                                                    } else if (
                                                                               (0x80000U 
                                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                            = 
                                                                            (0xe00U 
                                                                             | (0x1ffU 
                                                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                                    }
                                                                } else if (
                                                                           (0x100000U 
                                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                        = 
                                                                        ((0x1ffU 
                                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                         | (((0x80000U 
                                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])
                                                                              ? 6U
                                                                              : 5U) 
                                                                            << 9U));
                                                                } else if (
                                                                           (0x80000U 
                                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                        = 
                                                                        (0x800U 
                                                                         | (0x1ffU 
                                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 5U;
                            }
                        }
                    }
                }
            }
        } else if ((0x800U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
            if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                          >> 0xaU)))) {
                if ((0x200U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                    if ((0x100U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                        if ((0x80U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                            if ((0x200000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                if ((0x100000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((0x80000U & 
                                         vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                            = ((0x1fffffffffULL 
                                                & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                               | ((QData)((IData)(
                                                                  (3U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                       >> 5U))))) 
                                                  << 0x25U));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                            = ((0x7f00000000ULL 
                                                & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                               | (IData)((IData)(
                                                                 ((1U 
                                                                   & (IData)(
                                                                             (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                              >> 0x25U)))
                                                                   ? 
                                                                  ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                                    << 0x1eU) 
                                                                   | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U] 
                                                                      >> 2U))
                                                                   : 
                                                                  (0x1fU 
                                                                   & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                      >> 0x16U))))));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                            = ((0x1fffffffffULL 
                                                & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                               | ((QData)((IData)(
                                                                  (2U 
                                                                   == 
                                                                   (3U 
                                                                    & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                       >> 5U))))) 
                                                  << 0x25U));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                            = ((0x7f00000000ULL 
                                                & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                               | (IData)((IData)(
                                                                 ((1U 
                                                                   & (IData)(
                                                                             (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                                              >> 0x25U)))
                                                                   ? 
                                                                  ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    << 0x1eU) 
                                                                   | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                                      >> 2U))
                                                                   : 
                                                                  (((IData)(
                                                                            (0x20U 
                                                                             == 
                                                                             (0x60U 
                                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]))) 
                                                                    << 0xaU) 
                                                                   | (0x3ffU 
                                                                      & ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                          << 5U) 
                                                                         | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                            >> 0x1bU))))))));
                                    } else {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                            = (0x2000000000ULL 
                                               | (0x1fffffffffULL 
                                                  & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                            = ((0x7f00000000ULL 
                                                & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                               | (IData)((IData)(
                                                                 ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                                   << 0x1eU) 
                                                                  | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U] 
                                                                     >> 2U)))));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                            = (0x4000000000ULL 
                                               | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                            = ((0x60ffffffffULL 
                                                & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                               | ((QData)((IData)(
                                                                  (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                   >> 0x1bU))) 
                                                  << 0x20U));
                                    }
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                   >> 0x13U)))) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                        = (0x2000000000ULL 
                                           | (0x1fffffffffULL 
                                              & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                        = ((0x7f00000000ULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                           | (IData)((IData)(
                                                             ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                               << 0x1eU) 
                                                              | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U] 
                                                                 >> 2U)))));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = (0x4000000000ULL 
                                           | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = ((0x60ffffffffULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                           | ((QData)((IData)(
                                                              (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                               >> 0x1bU))) 
                                              << 0x20U));
                                }
                            } else if ((0x100000U & 
                                        vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                if ((0x80000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                        = (0x1fffffffffULL 
                                           & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o);
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                        = ((0x7f00000000ULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                           | (IData)((IData)(
                                                             (((0xeU 
                                                                == 
                                                                (0x3fU 
                                                                 & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                    >> 1U))) 
                                                               | (0xfU 
                                                                  == 
                                                                  (0x3fU 
                                                                   & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                      >> 1U))))
                                                               ? 
                                                              (0x1fU 
                                                               & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                  >> 0x16U))
                                                               : 
                                                              (((- (IData)(
                                                                           (1U 
                                                                            & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                               >> 0x1aU)))) 
                                                                << 5U) 
                                                               | (0x1fU 
                                                                  & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x16U)))))));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = (0x4000000000ULL 
                                           | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = ((0x60ffffffffULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                           | ((QData)((IData)(
                                                              (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                               >> 0x1bU))) 
                                              << 0x20U));
                                } else {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                        = ((0xffffffffULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                           | ((QData)((IData)(
                                                              (0x40U 
                                                               | (0x1fU 
                                                                  & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x16U))))) 
                                              << 0x20U));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = (0x4000000000ULL 
                                           | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = ((0x60ffffffffULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                           | ((QData)((IData)(
                                                              (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                               >> 0x1bU))) 
                                              << 0x20U));
                                }
                            } else {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                    = ((0xffffffffULL 
                                        & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                       | ((QData)((IData)(
                                                          (0x40U 
                                                           | (0x1fU 
                                                              & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x16U))))) 
                                          << 0x20U));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = (0x4000000000ULL 
                                       | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = ((0x60ffffffffULL 
                                        & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                       | ((QData)((IData)(
                                                          (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                           >> 0x1bU))) 
                                          << 0x20U));
                            }
                            if ((7U != (7U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                              >> 0x13U)))) {
                                if ((0x40U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((0x20U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((0x10U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((8U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (4U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (2U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x15U)))) {
                                                            if (
                                                                (0x100000U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                if (
                                                                    (0x80000U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                        = 
                                                                        ((0xffffffffULL 
                                                                          & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                                                         | ((QData)((IData)(
                                                                                (0x40U 
                                                                                | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x1bU)))) 
                                                                            << 0x20U));
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (0x200000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x14U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                    = 
                                                                    (0x2000000000ULL 
                                                                     | (0x1fffffffffULL 
                                                                        & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o));
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                    = 
                                                                    ((0x7f00000000ULL 
                                                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                                                     | (IData)((IData)(
                                                                                ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                << 0x1eU) 
                                                                                | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                                                >> 2U)))));
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (2U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x15U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x14U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                    = 
                                                                    ((0xffffffffULL 
                                                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                                                     | ((QData)((IData)(
                                                                                (0x40U 
                                                                                | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x1bU)))) 
                                                                        << 0x20U));
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x15U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                = 
                                                                (0x2000000000ULL 
                                                                 | (0x1fffffffffULL 
                                                                    & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                = 
                                                                ((0x7f00000000ULL 
                                                                  & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                                                 | (IData)((IData)(
                                                                                ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                << 0x1eU) 
                                                                                | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                                                >> 2U)))));
                                                        }
                                                    }
                                                }
                                            }
                                        } else if (
                                                   (8U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                     >> 2U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                         >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x15U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x14U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                if (
                                                                    (0x68U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]))) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                        = 
                                                                        (0x2000000000ULL 
                                                                         | (0x1fffffffffULL 
                                                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o));
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                        = 
                                                                        ((0x7f00000000ULL 
                                                                          & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                                                         | (IData)((IData)(
                                                                                ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                << 0x1eU) 
                                                                                | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                                                >> 2U)))));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else if (
                                                   (4U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((2U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            if (
                                                                (0x66U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]))) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                    = 
                                                                    ((0xffffffffULL 
                                                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                                                     | ((QData)((IData)(
                                                                                (0x40U 
                                                                                | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x1bU)))) 
                                                                        << 0x20U));
                                                            }
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x15U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        if (
                                                            (0x64U 
                                                             == 
                                                             (0x7fU 
                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]))) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                = 
                                                                (0x2000000000ULL 
                                                                 | (0x1fffffffffULL 
                                                                    & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                = 
                                                                ((0x7f00000000ULL 
                                                                  & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                                                 | (IData)((IData)(
                                                                                ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                << 0x1eU) 
                                                                                | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                                                >> 2U)))));
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if ((0x20U & 
                                            vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                  >> 4U)))) {
                                        if ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                     >> 2U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                         >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x15U)))) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                if (
                                                                    (0x4000000U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                        = 
                                                                        (0x3fffffffffULL 
                                                                         & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else if (
                                                   (4U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                     >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                                = 
                                                                (0x3fffffffffULL 
                                                                 & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o);
                                                        }
                                                    }
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                        >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x15U)))) {
                                                if (
                                                    (0x100000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                            = 
                                                            (0x3fffffffffULL 
                                                             & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if ((7U == (7U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                              >> 0x13U)))) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x1ffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = ((0x1e7fU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                       | (((0U == (7U 
                                                   & (IData)(
                                                             (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                              >> 3U))))
                                            ? 0U : 
                                           ((1U == 
                                             (7U & (IData)(
                                                           (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                            >> 3U))))
                                             ? 1U : 
                                            ((2U == 
                                              (7U & (IData)(
                                                            (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                             >> 3U))))
                                              ? 2U : 3U))) 
                                          << 7U));
                                if ((0U != (0xffffffU 
                                            & (IData)(
                                                      (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                       >> 8U))))) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x180U | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                }
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = ((0x1f81U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                       | ((0x70U & 
                                           ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                            << 4U)) 
                                          | (0xcU & 
                                             ((IData)(
                                                      (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                       >> 6U)) 
                                              << 2U))));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x1ffeU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                if ((IData)(((0U == 
                                              (0x7c00000U 
                                               & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) 
                                             & (3U 
                                                != 
                                                (3U 
                                                 & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                    >> 5U)))))) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = ((0x1ffcU 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                           | (((0U 
                                                != 
                                                (0x1fU 
                                                 & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0xeU))) 
                                               << 1U) 
                                              | (0U 
                                                 == 
                                                 (0x1fU 
                                                  & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0xeU)))));
                                }
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 5U;
                            } else if ((0x40U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                if ((0x20U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((0x10U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((4U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (2U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    if (
                                                        (0x200000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x100000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                     >> 0x13U)))) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                    = 
                                                                    ((0x3fU 
                                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                     | (0xd00U 
                                                                        | (0x1000U 
                                                                           & ((~ 
                                                                               vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                              << 0xcU))));
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x100000U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (0x80000U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                = 
                                                                (0x980U 
                                                                 | (0x107fU 
                                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                                = 
                                                                (0x4000000000ULL 
                                                                 | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                = 
                                                                (0x1fdfU 
                                                                 & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                                = 
                                                                ((0x60ffffffffULL 
                                                                  & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                                 | ((QData)((IData)(
                                                                                (0x1fU 
                                                                                & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x16U)))) 
                                                                    << 0x20U));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                = 
                                                                ((0xfffU 
                                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                 | (0x1000U 
                                                                    & ((~ 
                                                                        vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                       << 0xcU)));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                                        } else {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                = 
                                                                ((0x3fU 
                                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                 | (0xd00U 
                                                                    | (0x1000U 
                                                                       & ((~ 
                                                                           vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                          << 0xcU))));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x200000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                = 
                                                                ((0x3fU 
                                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                 | (0xc80U 
                                                                    | (0x1000U 
                                                                       & ((~ 
                                                                           vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                          << 0xcU))));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (0x900U 
                                                             | (0x107fU 
                                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                            = 
                                                            (0x4000000000ULL 
                                                             | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (0x1fdfU 
                                                             & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                            = 
                                                            ((0x60ffffffffULL 
                                                              & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                             | ((QData)((IData)(
                                                                                (0x1fU 
                                                                                & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x16U)))) 
                                                                << 0x20U));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0xfffU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0x1000U 
                                                                & ((~ 
                                                                    vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                   << 0xcU)));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x3fU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0xc80U 
                                                                | (0x1000U 
                                                                   & ((~ 
                                                                       vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                      << 0xcU))));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (2U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                = 
                                                                ((0x3fU 
                                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                 | (0xd80U 
                                                                    | (0x1000U 
                                                                       & ((~ 
                                                                           vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                          << 0xcU))));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x3fU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0xd80U 
                                                                | (0x1000U 
                                                                   & ((~ 
                                                                       vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                      << 0xcU))));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x880U 
                                                         | (0x107fU 
                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                        = 
                                                        (0x4000000000ULL 
                                                         | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x1fdfU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                        = 
                                                        ((0x60ffffffffULL 
                                                          & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                         | ((QData)((IData)(
                                                                            (0x1fU 
                                                                             & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x16U)))) 
                                                            << 0x20U));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                                }
                                            } else if (
                                                       (0x200000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x100000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x3fU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0xc00U 
                                                                | (0x1000U 
                                                                   & ((~ 
                                                                       vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                      << 0xcU))));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0xc00U 
                                                            | (0x1000U 
                                                               & ((~ 
                                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                  << 0xcU))));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x800U 
                                                     | (0x107fU 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                    = 
                                                    (0x4000000000ULL 
                                                     | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1fdfU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                    = 
                                                    ((0x60ffffffffULL 
                                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                     | ((QData)((IData)(
                                                                        (0x1fU 
                                                                         & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                            >> 0x16U)))) 
                                                        << 0x20U));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                            }
                                        } else if (
                                                   (4U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((2U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x100000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x3fU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0x180U 
                                                                | (0x1000U 
                                                                   & ((~ 
                                                                       vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                      << 0xcU))));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x80U 
                                                            | (0x1000U 
                                                               & ((~ 
                                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                  << 0xcU))));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                        >> 1U)))) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x1000U 
                                                            & ((~ 
                                                                vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                               << 0xcU)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                }
                                            }
                                        }
                                    } else if ((8U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((2U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x100000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x1c01U 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (8U 
                                                                | (((1U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                     ? 0U
                                                                     : 1U) 
                                                                   << 5U)));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (0xfffU 
                                                             & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (1U 
                                                             | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x1c01U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (8U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x1ffeU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (2U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x1c01U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (((1U 
                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                              ? 0U
                                                              : 1U) 
                                                            << 5U));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (1U 
                                                         | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x1c01U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (((1U 
                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                              ? 0U
                                                              : 1U) 
                                                            << 5U));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x1ffeU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (((1U 
                                                          & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                          ? 0U
                                                          : 1U) 
                                                        << 5U));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1ffeU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            if ((0x68U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x800U 
                                                     | (0x107fU 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                    = 
                                                    (0x4000000000ULL 
                                                     | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1fdfU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                    = 
                                                    ((0x60ffffffffULL 
                                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                     | ((QData)((IData)(
                                                                        (0x1fU 
                                                                         & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                            >> 0x16U)))) 
                                                        << 0x20U));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                            }
                                        }
                                    } else if ((4U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x100000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x1c01U 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (8U 
                                                                | (((1U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                     ? 0U
                                                                     : 1U) 
                                                                   << 5U)));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (0xfffU 
                                                             & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (1U 
                                                             | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x1c01U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (8U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (1U 
                                                         | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                if (
                                                    (0x66U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x880U 
                                                         | (0x107fU 
                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                        = 
                                                        (0x4000000000ULL 
                                                         | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x1fdfU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                        = 
                                                        ((0x60ffffffffULL 
                                                          & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                         | ((QData)((IData)(
                                                                            (0x1fU 
                                                                             & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x16U)))) 
                                                            << 0x20U));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                                }
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x1c01U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (8U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x1ffeU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (8U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1ffeU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            if ((0x64U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x800U 
                                                     | (0x107fU 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                    = 
                                                    (0x4000000000ULL 
                                                     | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1fdfU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                    = 
                                                    ((0x60ffffffffULL 
                                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                     | ((QData)((IData)(
                                                                        (0x1fU 
                                                                         & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                            >> 0x16U)))) 
                                                        << 0x20U));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                            }
                                        }
                                    } else if ((2U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x1c01U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (((1U 
                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                              ? 0U
                                                              : 1U) 
                                                            << 5U));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (1U 
                                                         | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (((1U 
                                                          & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                          ? 0U
                                                          : 1U) 
                                                        << 5U));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (1U 
                                                     | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1fU 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x440U 
                                                      | (0x1000U 
                                                         & ((~ 
                                                             vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                            << 0xcU))));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                        }
                                    } else if ((0x200000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x100000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (((1U 
                                                          & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                          ? 0U
                                                          : 1U) 
                                                        << 5U));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1ffeU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (((1U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                        ? 0U
                                                        : 1U) 
                                                      << 5U));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x1ffeU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((0x1fU 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x400U 
                                                  | (0x1000U 
                                                     & ((~ 
                                                         vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                        << 0xcU))));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                    }
                                } else if ((0x10U & 
                                            vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((2U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                = 
                                                                ((0x3fU 
                                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                 | (0xe00U 
                                                                    | (0x1000U 
                                                                       & ((~ 
                                                                           vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                          << 0xcU))));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (0xa83U 
                                                             | (((1U 
                                                                  & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                  ? 0U
                                                                  : 1U) 
                                                                << 5U));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x80000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (0xa83U 
                                                             | (((1U 
                                                                  & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                  ? 0U
                                                                  : 1U) 
                                                                << 5U));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                    } else {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x3fU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0xe00U 
                                                                | (0x1000U 
                                                                   & ((~ 
                                                                       vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                      << 0xcU))));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xa83U 
                                                         | (((1U 
                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                              ? 0U
                                                              : 1U) 
                                                            << 5U));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            } else if (
                                                       (0x200000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (0x682U 
                                                             | (((1U 
                                                                  & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                  ? 0U
                                                                  : 1U) 
                                                                << 5U));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x682U 
                                                         | (((1U 
                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                              ? 0U
                                                              : 1U) 
                                                            << 5U));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x682U 
                                                     | (((1U 
                                                          & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                          ? 0U
                                                          : 1U) 
                                                        << 5U));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (2U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x100000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x3fU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0xc00U 
                                                                | (0x1000U 
                                                                   & ((~ 
                                                                       vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                      << 0xcU))));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0xa80U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0xa80U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                } else {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0xc00U 
                                                            | (0x1000U 
                                                               & ((~ 
                                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                  << 0xcU))));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0xa80U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x680U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x680U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x680U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((4U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x100000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x3fU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0xe40U 
                                                                | (0x1000U 
                                                                   & ((~ 
                                                                       vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                      << 0xcU))));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0xa80U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0xa80U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                } else {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0xe40U 
                                                            | (0x1000U 
                                                               & ((~ 
                                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                  << 0xcU))));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0xa80U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x680U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x680U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x680U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((2U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0xc40U 
                                                            | (0x1000U 
                                                               & ((~ 
                                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                  << 0xcU))));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0xa80U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0xa80U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            } else {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x3fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0xc40U 
                                                        | (0x1000U 
                                                           & ((~ 
                                                               vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                              << 0xcU))));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0xa80U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((0x200000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x680U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x80000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x680U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((1U 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x680U 
                                                  | (((1U 
                                                       & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                       ? 0U
                                                       : 1U) 
                                                     << 5U)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x100000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x3fU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0x580U 
                                                                | (0x1000U 
                                                                   & ((~ 
                                                                       vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                      << 0xcU))));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x980U 
                                                            | (0x1000U 
                                                               & ((~ 
                                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                  << 0xcU))));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xf00U 
                                                         | (1U 
                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                } else {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x580U 
                                                            | (0x1000U 
                                                               & ((~ 
                                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                  << 0xcU))));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x3fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x980U 
                                                        | (0x1000U 
                                                           & ((~ 
                                                               vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                              << 0xcU))));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x3fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x480U 
                                                        | (0x1000U 
                                                           & ((~ 
                                                               vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                              << 0xcU))));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                            }
                                        }
                                    } else if ((2U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x1000U 
                                                            & ((~ 
                                                                vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                               << 0xcU)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x280U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x280U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            } else {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x3fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x1000U 
                                                        & ((~ 
                                                            vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                           << 0xcU)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x280U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x3fU 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x400U 
                                                      | (0x1000U 
                                                         & ((~ 
                                                             vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                            << 0xcU))));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 2U;
                                        }
                                    }
                                } else if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x488U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x14U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x88U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    }
                                } else if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((0x200000U 
                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x480U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x80000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x480U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((1U 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x480U 
                                                  | (((1U 
                                                       & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                       ? 0U
                                                       : 1U) 
                                                     << 5U)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((0x200000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x14U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x80U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    }
                                } else if ((0x100000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((0x80000U & 
                                         vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((1U 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x80U 
                                                  | (((1U 
                                                       & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                       ? 0U
                                                       : 1U) 
                                                     << 5U)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                   >> 0x13U)))) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                           | (0x80U 
                                              | (((1U 
                                                   & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                   ? 0U
                                                   : 1U) 
                                                 << 5U)));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                }
                            } else if ((0x20U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                if ((0x10U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((2U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                if (
                                                    (0x200000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x14U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                 >> 0x13U)))) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                                = 
                                                                ((1U 
                                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                                 | (0x1804U 
                                                                    | (((1U 
                                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                         ? 0U
                                                                         : 1U) 
                                                                       << 5U)));
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                        }
                                                    }
                                                } else if (
                                                           (0x100000U 
                                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x80000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((1U 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0x1804U 
                                                                | (((1U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                     ? 0U
                                                                     : 1U) 
                                                                   << 5U)));
                                                    } else {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (0x208U 
                                                             | (0x1c01U 
                                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (0xfffU 
                                                             & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    }
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            } else if (
                                                       (0x200000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((1U 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0x1004U 
                                                                | (((1U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                     ? 0U
                                                                     : 1U) 
                                                                   << 5U)));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x1004U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                } else {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x10cU 
                                                         | (0x1c01U 
                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                }
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (2U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((1U 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0x1884U 
                                                                | (((1U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                     ? 0U
                                                                     : 1U) 
                                                                   << 5U)));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x1884U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                } else {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x18cU 
                                                         | (0x1c01U 
                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                }
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x1884U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x1084U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x1084U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                            } else {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x188U 
                                                     | (0x1c01U 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            }
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x1084U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((4U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((1U 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0x1808U 
                                                                | (((1U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                     ? 0U
                                                                     : 1U) 
                                                                   << 5U)));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x200U 
                                                         | (0x1c01U 
                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x1808U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x1008U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x180U 
                                                     | (0x1c01U 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x1008U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((2U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x1c01U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x188U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x1000U 
                                                         | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x188U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1000U 
                                                     | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            } else {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x100U 
                                                     | (0x1c01U 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            }
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x188U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x1000U 
                                                   | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((0x200000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x108U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1000U 
                                                     | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x80000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x108U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x1000U 
                                                   | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        } else {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x108U 
                                                   | (0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        }
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((0x1c01U 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x108U 
                                                  | (((1U 
                                                       & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                       ? 0U
                                                       : 1U) 
                                                     << 5U)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x1000U 
                                               | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x14U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((1U 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0xc08U 
                                                                | ((((1U 
                                                                      & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                      ? 7U
                                                                      : 6U) 
                                                                    << 7U) 
                                                                   | (((1U 
                                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                        ? 0U
                                                                        : 3U) 
                                                                      << 5U))));
                                                        if (
                                                            (1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                                = 
                                                                (0x3fffffffffULL 
                                                                 & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                                        }
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                    }
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0xc08U 
                                                            | ((((1U 
                                                                  & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                  ? 7U
                                                                  : 6U) 
                                                                << 7U) 
                                                               | (((1U 
                                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                    ? 0U
                                                                    : 3U) 
                                                                  << 5U))));
                                                    if (
                                                        (1U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                            = 
                                                            (0x3fffffffffULL 
                                                             & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                                    }
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                } else {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x300U 
                                                         | (0x107fU 
                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x1fdfU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0xfffU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x1000U 
                                                            & ((~ 
                                                                vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                               << 0xcU)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0xc08U 
                                                        | ((((1U 
                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                              ? 7U
                                                              : 6U) 
                                                            << 7U) 
                                                           | (((1U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                ? 0U
                                                                : 3U) 
                                                              << 5U))));
                                                if (
                                                    (1U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                        = 
                                                        (0x3fffffffffULL 
                                                         & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                                }
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                    >> 1U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x15U)))) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    if (
                                                        (0x4000000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x107fU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (((0x400000U 
                                                                  & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])
                                                                  ? 3U
                                                                  : 4U) 
                                                                << 7U));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                            = 
                                                            ((0x3fffffffffULL 
                                                              & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                             | ((QData)((IData)(
                                                                                (1U 
                                                                                & (~ 
                                                                                (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                                >> 0x16U))))) 
                                                                << 0x26U));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            (0x1fdfU 
                                                             & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0xfffU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0x1000U 
                                                                & ((~ 
                                                                    vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                   << 0xcU)));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((1U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x1008U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 2U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x1008U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 2U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x1008U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 2U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((0x200000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x48U 
                                                     | (0x1c01U 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x80000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x48U 
                                                   | (0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        } else {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0xf00U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1ffeU 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (1U 
                                                      & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x16U)));
                                        }
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x48U 
                                               | (0x1c01U 
                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0xfffU 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((0x200000U 
                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x1000U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 2U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x80000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (1U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x1000U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 2U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((1U 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x1000U 
                                                  | (((1U 
                                                       & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                       ? 0U
                                                       : 2U) 
                                                     << 5U)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((0x200000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((0x100000U 
                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                            if ((0U 
                                                 == 
                                                 (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x1bU))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xf88U 
                                                     | (1U 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x40U 
                                               | (0x1c01U 
                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0xfffU 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((0x100000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((0x80000U & 
                                         vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x40U 
                                               | (0x1c01U 
                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0xfffU 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    } else {
                                        if ((0U == 
                                             (0x1fU 
                                              & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                 >> 0x16U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x107fU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        } else if (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x16U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x80U 
                                                   | (0x107fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                        } else if (
                                                   (0x11U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x16U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x100U 
                                                   | (0x107fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                        }
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x20U 
                                               | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((0xfffU 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x1000U 
                                                  & ((~ 
                                                      vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                     << 0xcU)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                    }
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                   >> 0x13U)))) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x40U | 
                                           (0x1c01U 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0xfffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                }
                            } else if ((0x10U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                if ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                            if ((0x200000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x100000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                            = 
                                                            ((0x3ffU 
                                                              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                             | (0xc00U 
                                                                | (0x1000U 
                                                                   & ((~ 
                                                                       vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                      << 0xcU))));
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 3U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3ffU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x800U 
                                                            | (0x1000U 
                                                               & ((~ 
                                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                  << 0xcU))));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 3U;
                                                }
                                            } else if (
                                                       (0x100000U 
                                                        & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x80000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3ffU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x800U 
                                                            | (0x1000U 
                                                               & ((~ 
                                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                  << 0xcU))));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 3U;
                                                }
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x3ffU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x400U 
                                                            | (0x1000U 
                                                               & ((~ 
                                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                                  << 0xcU))));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 3U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x3ffU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x1000U 
                                                        & ((~ 
                                                            vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                           << 0xcU)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 3U;
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x3ffU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x1000U 
                                                        & ((~ 
                                                            vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                           << 0xcU)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 3U;
                                            }
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                    >> 1U)))) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x280U 
                                                         | (0x107fU 
                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x1fdfU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0xfffU 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x1000U 
                                                            & ((~ 
                                                                vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                               << 0xcU)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x280U 
                                                     | (0x107fU 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1fdfU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0xfffU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x1000U 
                                                        & ((~ 
                                                            vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                           << 0xcU)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x280U 
                                                   | (0x107fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x1fdfU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0xfffU 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x1000U 
                                                      & ((~ 
                                                          vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                         << 0xcU)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                        }
                                    }
                                } else if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        ((0x1c01U 
                                                          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                         | (0x14U 
                                                            | (((1U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                 ? 0U
                                                                 : 1U) 
                                                               << 5U)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xfffU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (1U 
                                                         | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x200U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((0x80000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x200U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            } else {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x14U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (1U 
                                                     | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            }
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x200U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((0x200000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x100000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x14U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1ffeU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x180U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x80000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x180U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        } else {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x14U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x1ffeU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        }
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((0x1c01U 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x180U 
                                                  | (((1U 
                                                       & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                       ? 0U
                                                       : 1U) 
                                                     << 5U)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0xfffU 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((0x200000U 
                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x100000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x10U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (1U 
                                                     | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x100U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x80000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x100U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        } else {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x10U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (1U 
                                                   | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        }
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((0x1c01U 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x100U 
                                                  | (((1U 
                                                       & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                       ? 0U
                                                       : 1U) 
                                                     << 5U)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0xfffU 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((0x100000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((0x1c01U 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x10U 
                                                  | (((1U 
                                                       & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                       ? 0U
                                                       : 1U) 
                                                     << 5U)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0xfffU 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x1ffeU 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                }
                            } else if ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x14U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x13U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0xb68U 
                                                         | (1U 
                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                                }
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x780U 
                                                     | (0x107fU 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x1fdfU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0xfffU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (0x1000U 
                                                        & ((~ 
                                                            vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                           << 0xcU)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                        >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xb68U 
                                                   | (1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    } else if ((0x200000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0x368U 
                                                     | (1U 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x700U 
                                                   | (0x107fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x1fdfU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0xfffU 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x1000U 
                                                      & ((~ 
                                                          vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                         << 0xcU)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x368U 
                                               | (1U 
                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((0x200000U 
                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xbe8U 
                                                     | (1U 
                                                        & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x680U 
                                                   | (0x107fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x1fdfU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0xfffU 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x1000U 
                                                      & ((~ 
                                                          vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                         << 0xcU)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0xbe8U 
                                               | (1U 
                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                } else if ((0x200000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x14U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x3e8U 
                                                   | (1U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    }
                                } else if ((0x100000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x600U 
                                               | (0x107fU 
                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x1fdfU 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((0xfffU 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x1000U 
                                                  & ((~ 
                                                      vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                     << 0xcU)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                    }
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                   >> 0x13U)))) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x3e8U | 
                                           (1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                }
                            } else if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    if ((0x200000U 
                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    ((0x1c01U 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                     | (4U 
                                                        | (((1U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                             ? 0U
                                                             : 1U) 
                                                           << 5U)));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                            }
                                        }
                                    } else if ((0x100000U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((0x80000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (4U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        } else {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x580U 
                                                   | (0x107fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x1fdfU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0xfffU 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x1000U 
                                                      & ((~ 
                                                          vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                         << 0xcU)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                        }
                                    }
                                } else if ((0x200000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x14U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0x1c01U 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (8U 
                                                      | (((1U 
                                                           & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                           ? 0U
                                                           : 1U) 
                                                         << 5U)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0xfffU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                        }
                                    }
                                } else if ((0x100000U 
                                            & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x500U 
                                               | (0x107fU 
                                                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0x1fdfU 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((0xfffU 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (0x1000U 
                                                  & ((~ 
                                                      vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                     << 0xcU)));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                    }
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                   >> 0x13U)))) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = ((0x1c01U 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                           | (8U | 
                                              (((1U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                 ? 0U
                                                 : 1U) 
                                               << 5U)));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0xfffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                }
                            } else if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                              >> 0x15U)))) {
                                    if ((0x100000U 
                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x480U 
                                                   | (0x107fU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x1fdfU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (
                                                   (0xfffU 
                                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                                   | (0x1000U 
                                                      & ((~ 
                                                          vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                         << 0xcU)));
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                        }
                                    }
                                }
                            } else if ((0x200000U & 
                                        vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                              >> 0x14U)))) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = ((0x1c01U 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                               | (((1U 
                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                    ? 0U
                                                    : 1U) 
                                                  << 5U));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                            = (0xfffU 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                    }
                                }
                            } else if ((0x100000U & 
                                        vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                if ((0x80000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = ((0x1c01U 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                           | (((1U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                ? 0U
                                                : 1U) 
                                              << 5U));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0xfffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                                } else {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x400U | 
                                           (0x107fU 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x1fdfU 
                                           & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = ((0xfffU 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                           | (0x1000U 
                                              & ((~ 
                                                  vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                 << 0xcU)));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                                }
                            } else if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                 >> 0x13U)))) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = ((0x1c01U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                       | (((1U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                            ? 0U : 1U) 
                                          << 5U));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0xfffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x1000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
        if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                      >> 0xbU)))) {
            if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                          >> 0xaU)))) {
                if ((0x200U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                    if ((0x100U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                        if ((0x80U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o 
                                = (0x20U | (0x1fU & 
                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                             >> 0xeU)));
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                = (0x2000000000ULL 
                                   | (0x1fffffffffULL 
                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o));
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                = ((0x7f00000000ULL 
                                    & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                   | (IData)((IData)(
                                                     ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                       << 0x1eU) 
                                                      | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U] 
                                                         >> 2U)))));
                            if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                          >> 2U)))) {
                                if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                              >> 1U)))) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x1fU)))) {
                                        if ((0x40000000U 
                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x1dU)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x1cU)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x1bU)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                        if (
                                                            (0x40U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                            if (
                                                                (0x20U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                                if (
                                                                    (0x10U 
                                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 3U;
                                                                }
                                                            }
                                                        } else if (
                                                                   (0x20U 
                                                                    & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                            if (
                                                                (0x10U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 2U;
                                                            }
                                                        } else {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul 
                                                                = 
                                                                ((0x10U 
                                                                  & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                                  ? 1U
                                                                  : 0U);
                                                        }
                                                    }
                                                }
                                                if (
                                                    (0x10000000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    if (
                                                        (0x8000000U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__evl_pol = 2U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                >> 0x1bU)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__evl_pol = 3U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                = ((0x7ffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                   | ((0x1000U & ((~ 
                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                  << 0xcU)) 
                                      | ((0x27U == 
                                          (0x7fU & 
                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                            >> 7U))) 
                                         << 0xbU)));
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                = ((0x1f8fU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                   | (0x70U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]));
                            if ((0U == ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                        | (7U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                 >> 0x13U))))) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x1e7fU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                            } else if ((5U == ((8U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                               | (7U 
                                                  & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U))))) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x80U | (0x1e7fU 
                                                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                            } else if ((6U == ((8U 
                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                               | (7U 
                                                  & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U))))) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x100U | (0x1e7fU 
                                                 & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                            }
                            if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x400U | 
                                           (0x19ffU 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = (0x4000000000ULL 
                                           | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = ((0x60ffffffffULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                           | ((QData)((IData)(
                                                              (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                               >> 0x1bU))) 
                                              << 0x20U));
                                } else {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x200U | 
                                           (0x19ffU 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = (0x2000000000ULL 
                                           | (0x1fffffffffULL 
                                              & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = ((0x7f00000000ULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                           | (IData)((IData)(
                                                             ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                               << 0x1eU) 
                                                              | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                                 >> 2U)))));
                                }
                            } else if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x400U | (0x19ffU 
                                                 & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = (0x4000000000ULL 
                                       | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = ((0x60ffffffffULL 
                                        & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                       | ((QData)((IData)(
                                                          (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                           >> 0x1bU))) 
                                          << 0x20U));
                            } else {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x19ffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = (0x3fffffffffULL 
                                       & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = ((0x7f00000000ULL 
                                        & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                       | (IData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d93fe75__2)));
                                if ((0U != (3U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U] 
                                                  >> 2U)))) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x200U | 
                                           (0x19ffU 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                    if ((0U == (7U 
                                                & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                   >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                            = (1ULL 
                                               | (0x7f00000000ULL 
                                                  & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o));
                                    } else if ((5U 
                                                == 
                                                (7U 
                                                 & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                            = (2ULL 
                                               | (0x7f00000000ULL 
                                                  & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o));
                                    } else if ((6U 
                                                == 
                                                (7U 
                                                 & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x13U)))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                            = (4ULL 
                                               | (0x7f00000000ULL 
                                                  & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o));
                                    }
                                }
                                if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                              >> 0x1fU)))) {
                                    if ((0x40000000U 
                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x1dU)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x1cU)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x1bU)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x1f8fU 
                                                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                                }
                                            }
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x1dU)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x1cU)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x1bU)))) {
                                                if (
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                         >> 4U)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                        = 
                                                        (0x200U 
                                                         | (0x19ffU 
                                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                                    if (
                                                        (0U 
                                                         == 
                                                         (7U 
                                                          & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                             >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                            = 
                                                            ((0x7f00000000ULL 
                                                              & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                             | (IData)((IData)(
                                                                               (0xfU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                                >> 4U)))))));
                                                    } else if (
                                                               (5U 
                                                                == 
                                                                (7U 
                                                                 & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                            = 
                                                            ((0x7f00000000ULL 
                                                              & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                             | (IData)((IData)(
                                                                               (0x1eU 
                                                                                & (((IData)(1U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                                >> 4U))) 
                                                                                << 1U)))));
                                                    } else if (
                                                               (6U 
                                                                == 
                                                                (7U 
                                                                 & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                    >> 0x13U)))) {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                            = 
                                                            ((0x7f00000000ULL 
                                                              & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                             | (IData)((IData)(
                                                                               (0x3cU 
                                                                                & (((IData)(1U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                                >> 4U))) 
                                                                                << 2U)))));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 0U;
                        }
                    }
                }
            }
        }
    } else if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                         >> 0xbU)))) {
        if ((0x400U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
            if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                          >> 9U)))) {
                if ((0x100U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                    if ((0x80U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o 
                            = (0x1fU & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                        >> 0xeU));
                        if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                      >> 0x15U)))) {
                            if ((0x100000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                if ((0x80000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                        = ((0xffffffffULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                           | ((QData)((IData)(
                                                              (0x40U 
                                                               | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                  >> 0x1bU)))) 
                                              << 0x20U));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x980U | 
                                           (0x107fU 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = (0x4000000000ULL 
                                           | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x1fdfU 
                                           & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = ((0x60ffffffffULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                           | ((QData)((IData)(
                                                              (0x1fU 
                                                               & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                  >> 0x16U)))) 
                                              << 0x20U));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = ((0xfffU 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                           | (0x1000U 
                                              & ((~ 
                                                  vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                 << 0xcU)));
                                } else {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                        = (0x2000000000ULL 
                                           | (0x1fffffffffULL 
                                              & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                        = ((0x7f00000000ULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                           | (IData)((IData)(
                                                             ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                               << 0x1eU) 
                                                              | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                                 >> 2U)))));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x900U | 
                                           (0x107fU 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = (0x4000000000ULL 
                                           | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = (0x1fdfU 
                                           & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                        = ((0x60ffffffffULL 
                                            & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                           | ((QData)((IData)(
                                                              (0x1fU 
                                                               & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                                  >> 0x16U)))) 
                                              << 0x20U));
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                        = ((0xfffU 
                                            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                                           | (0x1000U 
                                              & ((~ 
                                                  vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                                 << 0xcU)));
                                }
                            } else if ((0x80000U & 
                                        vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                    = ((0xffffffffULL 
                                        & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                       | ((QData)((IData)(
                                                          (0x40U 
                                                           | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                              >> 0x1bU)))) 
                                          << 0x20U));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x880U | (0x107fU 
                                                 & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = (0x4000000000ULL 
                                       | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x1fdfU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = ((0x60ffffffffULL 
                                        & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                       | ((QData)((IData)(
                                                          (0x1fU 
                                                           & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                              >> 0x16U)))) 
                                          << 0x20U));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0xfffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                            } else {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                    = (0x2000000000ULL 
                                       | (0x1fffffffffULL 
                                          & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                    = ((0x7f00000000ULL 
                                        & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                       | (IData)((IData)(
                                                         ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                           << 0x1eU) 
                                                          | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                             >> 2U)))));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x800U | (0x107fU 
                                                 & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = (0x4000000000ULL 
                                       | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0x1fdfU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = ((0x60ffffffffULL 
                                        & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                       | ((QData)((IData)(
                                                          (0x1fU 
                                                           & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                              >> 0x16U)))) 
                                          << 0x20U));
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                    = (0xfffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                            }
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 4U;
                        }
                    }
                }
            }
        } else if ((0x200U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
            if ((0x100U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                if ((0x80U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o 
                        = (0x20U | (0x1fU & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                             >> 0xeU)));
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                        = (0x2000000000ULL | (0x1fffffffffULL 
                                              & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o));
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                        = ((0x7f00000000ULL & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                           | (IData)((IData)(((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                               << 0x1eU) 
                                              | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U] 
                                                 >> 2U)))));
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                        = ((0x7ffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                           | ((0x1000U & ((~ vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                          << 0xcU)) 
                              | ((0x27U == (0x7fU & 
                                            (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                             >> 7U))) 
                                 << 0xbU)));
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                        = ((0x1f8fU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)) 
                           | (0x70U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]));
                    if ((0U == ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                | (7U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                         >> 0x13U))))) {
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                            = (0x1e7fU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                    } else if ((5U == ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                       | (7U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                >> 0x13U))))) {
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                            = (0x80U | (0x1e7fU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                    } else if ((6U == ((8U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U]) 
                                       | (7U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                >> 0x13U))))) {
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                            = (0x100U | (0x1e7fU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                    }
                    if ((4U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                        if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                = (0x400U | (0x19ffU 
                                             & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                = (0x4000000000ULL 
                                   | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                = ((0x60ffffffffULL 
                                    & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                   | ((QData)((IData)(
                                                      (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                       >> 0x1bU))) 
                                      << 0x20U));
                        } else {
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                = (0x200U | (0x19ffU 
                                             & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                = (0x2000000000ULL 
                                   | (0x1fffffffffULL 
                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o));
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                = ((0x7f00000000ULL 
                                    & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                   | (IData)((IData)(
                                                     ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                       << 0x1eU) 
                                                      | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[1U] 
                                                         >> 2U)))));
                        }
                    } else if ((2U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                            = (0x400U | (0x19ffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                            = (0x4000000000ULL | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                            = ((0x60ffffffffULL & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                               | ((QData)((IData)((
                                                   vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                   >> 0x1bU))) 
                                  << 0x20U));
                    } else {
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                            = (0x19ffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                            = (0x3fffffffffULL & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o);
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                            = ((0x7f00000000ULL & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                               | (IData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d93fe75__2)));
                        if ((0U != (3U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U] 
                                          >> 2U)))) {
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                = (0x200U | (0x19ffU 
                                             & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                            if ((0U == (7U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                              >> 0x13U)))) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = (1ULL | (0x7f00000000ULL 
                                               & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o));
                            } else if ((5U == (7U & 
                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                >> 0x13U)))) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = (2ULL | (0x7f00000000ULL 
                                               & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o));
                            } else if ((6U == (7U & 
                                               (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                >> 0x13U)))) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                    = (4ULL | (0x7f00000000ULL 
                                               & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o));
                            }
                        }
                        if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                      >> 0x1fU)))) {
                            if ((0x40000000U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                              >> 0x1dU)))) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x1cU)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x1bU)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x1f8fU 
                                                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode));
                                        }
                                    }
                                }
                            } else if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                 >> 0x1dU)))) {
                                if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                              >> 0x1cU)))) {
                                    if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                  >> 0x1bU)))) {
                                        if ((0U != 
                                             (7U & 
                                              (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                               >> 4U)))) {
                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode 
                                                = (0x200U 
                                                   | (0x19ffU 
                                                      & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)));
                                            if ((0U 
                                                 == 
                                                 (7U 
                                                  & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                    = 
                                                    ((0x7f00000000ULL 
                                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                     | (IData)((IData)(
                                                                       (0xfU 
                                                                        & ((IData)(1U) 
                                                                           + 
                                                                           (7U 
                                                                            & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                               >> 4U)))))));
                                            } else if (
                                                       (5U 
                                                        == 
                                                        (7U 
                                                         & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                    = 
                                                    ((0x7f00000000ULL 
                                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                     | (IData)((IData)(
                                                                       (0x1eU 
                                                                        & (((IData)(1U) 
                                                                            + 
                                                                            (7U 
                                                                             & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                                >> 4U))) 
                                                                           << 1U)))));
                                            } else if (
                                                       (6U 
                                                        == 
                                                        (7U 
                                                         & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x13U)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                                    = 
                                                    ((0x7f00000000ULL 
                                                      & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o) 
                                                     | (IData)((IData)(
                                                                       (0x3cU 
                                                                        & (((IData)(1U) 
                                                                            + 
                                                                            (7U 
                                                                             & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                                                                >> 4U))) 
                                                                           << 2U)))));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit = 0U;
                }
            }
        }
        if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                      >> 0xaU)))) {
            if ((0x200U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                if ((0x100U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                    if ((0x80U & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                        if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                      >> 2U)))) {
                            if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                                          >> 1U)))) {
                                if ((1U & (~ (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                              >> 0x1fU)))) {
                                    if ((0x40000000U 
                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                    >> 0x1dU)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                     >> 0x1cU)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                         >> 0x1bU)))) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override = 1U;
                                                    if (
                                                        (0x40U 
                                                         & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        if (
                                                            (0x20U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                            if (
                                                                (0x10U 
                                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 3U;
                                                            }
                                                        }
                                                    } else if (
                                                               (0x20U 
                                                                & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                        if (
                                                            (0x10U 
                                                             & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])) {
                                                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul = 2U;
                                                        }
                                                    } else {
                                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul 
                                                            = 
                                                            ((0x10U 
                                                              & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U])
                                                              ? 1U
                                                              : 0U);
                                                    }
                                                }
                                            }
                                            if ((0x10000000U 
                                                 & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                if (
                                                    (0x8000000U 
                                                     & vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U])) {
                                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__evl_pol = 2U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                                            >> 0x1bU)))) {
                                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__evl_pol = 3U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT____Vxrand_h8d9668fa__4;
    if ((0x20U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__state_ex1_q[4U])) {
        if ((0x10U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__state_ex1_q[4U])) {
            if ((0U == (3U & ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__state_ex1_q[4U] 
                               << 1U) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__state_ex1_q[3U] 
                                         >> 0x1fU))))) {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
                    = (0xeU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
                    = (0xdU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
                    = (0xbU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
                    = (7U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d));
            } else if ((3U == (3U & ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__state_ex1_q[4U] 
                                      << 1U) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__state_ex1_q[3U] 
                                                >> 0x1fU))))) {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
                    = ((0xeU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d)) 
                       | (1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__operand_mask_q)));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
                    = ((0xdU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d)) 
                       | (2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__operand_mask_q)));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
                    = ((0xbU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d)) 
                       | (4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__operand_mask_q)));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
                    = ((7U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d)) 
                       | (8U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__operand_mask_q)));
            }
        } else {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
                = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__ovflw) 
                   ^ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__sig_res));
        }
    } else {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__cmp_d 
            = (0xfU & ((0x10U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__state_ex1_q[4U])
                        ? (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__ovflw)
                        : ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__state_ex1_subtract)
                            ? (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__carry))
                            : (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__alu__DOT__carry))));
    }
    if ((1U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q)) {
        if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two = 1U;
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_raw 
                = (1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
        } else {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two = 0U;
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_raw 
                = (1U & (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                          >> 1U) | ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid))));
        }
    } else {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two 
            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed;
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_raw 
            = (1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46fac9ec__0 
        = (IData)((((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                    >> 2U) | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h8784150c__0)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf22c316__0 
        = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f4a7__0) 
                 | ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                    >> 1U)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_q;
    if ((((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_q)) 
          & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_valid_q)) 
         & (0x50000U == (0x50000U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[4U])))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_d = 1U;
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_vaddr 
        = ((0xfffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_vaddr) 
           | (((2U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_q)
                       ? (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_emul_q)
                       : ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                           << 0xdU) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                                       >> 0x13U))))
                ? ((1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_q)
                           ? (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_emul_q)
                           : ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                               << 0xdU) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                                           >> 0x13U))))
                    ? ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__base_vaddr) 
                       | (7U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__vd_count_d) 
                                >> 4U))) : ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__base_vaddr) 
                                            | (3U & 
                                               ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__vd_count_d) 
                                                >> 4U))))
                : ((1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_q)
                           ? (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_emul_q)
                           : ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                               << 0xdU) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                                           >> 0x13U))))
                    ? ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__base_vaddr) 
                       | (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__vd_count_d) 
                                >> 4U))) : (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__base_vaddr))) 
              << 0x14U));
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_store_o = 0U;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_store_o 
        = ((2U & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_store_o)) 
           | ((((~ (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                    >> 0x1fU)) & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__result_valid_q)) 
               | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_q)) 
              & (0xfU == (0xfU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__vd_count_d)))));
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_last_cycle = 0U;
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_q) 
         & (0xfU == (0xfU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__vd_count_d))))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_d = 0U;
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_last_cycle = 1U;
    }
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o = 0U;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o 
        = ((0xff7fU & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o)) 
           | ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT____Vxrand_h8d96565c__2) 
              << 7U));
    if ((0U == (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_q)
                       ? (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_eew_q)
                       : ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                           << 8U) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                                     >> 0x18U)))))) {
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o 
            = ((0xff7fU & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o)) 
               | ((0U == (3U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__vd_count_d))) 
                  << 7U));
    } else if ((1U == (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_q)
                              ? (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_eew_q)
                              : ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                                  << 8U) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                                            >> 0x18U)))))) {
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o 
            = ((0xff7fU & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o)) 
               | (0x80U & ((~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__vd_count_d) 
                               >> 1U)) << 7U)));
    } else if ((2U == (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_q)
                              ? (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_eew_q)
                              : ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                                  << 8U) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                                            >> 0x18U)))))) {
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o 
            = (0x80U | (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o));
    }
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o 
        = (0x40U | (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_stream_done 
        = ((((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_active_q) 
             & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_stream_drained_q))) 
            & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_instr_match)) 
           & ((0xffU & ((IData)(1U) + (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_event_count_q))) 
              == ((0U != (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_event_budget_q))
                   ? (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_event_budget_q)
                   : ([&]() {
                        vlSelf->__Vfunc_vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_elem_budget__6__lmul 
                            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_lmul;
                        vlSelf->__Vfunc_vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_elem_budget__6__Vfuncout 
                            = ((4U & (IData)(vlSelf->__Vfunc_vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_elem_budget__6__lmul))
                                ? ((2U & (IData)(vlSelf->__Vfunc_vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_elem_budget__6__lmul))
                                    ? ((1U & (IData)(vlSelf->__Vfunc_vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_elem_budget__6__lmul))
                                        ? 8U : 0U) : 0U)
                                : ((2U & (IData)(vlSelf->__Vfunc_vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_elem_budget__6__lmul))
                                    ? ((1U & (IData)(vlSelf->__Vfunc_vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_elem_budget__6__lmul))
                                        ? 0x80U : 0x40U)
                                    : ((1U & (IData)(vlSelf->__Vfunc_vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_elem_budget__6__lmul))
                                        ? 0x20U : 0x10U)));
                    }(), (IData)(vlSelf->__Vfunc_vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_elem_budget__6__Vfuncout)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_holdoff_count_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_holdoff_count_q;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_data_ready_d = 0U;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__first_cycle_seen_next 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_holdoff_count_q;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__quantum_qrotv_ready_holdoff_cycles = 0U;
    if ((0x13U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__quantum_op))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__quantum_holdoff_stream = 1U;
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__quantum_qrotv_ready_holdoff_cycles 
            = ((7U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_lmul))
                ? 4U : ((0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_lmul))
                         ? 6U : 0U));
    } else {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__quantum_holdoff_stream 
            = ((2U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_lmul)) 
               | (3U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_lmul)));
    }
    if (vlSelf->vproc_qdisp_bell_tb__DOT__quantum_valid) {
        if ((0x13U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__quantum_op))) {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__first_cycle_seen_next 
                = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_new_stream)
                    ? 1U : ((IData)(1U) + vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_holdoff_count_q));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_holdoff_count_d 
                = vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__first_cycle_seen_next;
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_data_ready_d 
                = (vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__first_cycle_seen_next 
                   > vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__quantum_qrotv_ready_holdoff_cycles);
        } else if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__quantum_holdoff_stream) {
            if (vlSelf->vproc_qdisp_bell_tb__DOT__quantum_first_cycle) {
                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__first_cycle_seen_next 
                    = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_new_stream)
                        ? 1U : ((IData)(1U) + vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_holdoff_count_q));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_holdoff_count_d 
                    = vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__first_cycle_seen_next;
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_data_ready_d 
                    = (2U < vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__unnamedblk4__DOT__first_cycle_seen_next);
            } else {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_data_ready_d = 1U;
            }
        } else {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_holdoff_count_d = 0U;
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_data_ready_d = 1U;
        }
    } else {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_holdoff_count_d = 0U;
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_data_ready_d = 0U;
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear_cnt 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d9647ad__0;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT____Vcellout__unit_mux__pipe_out_res_flags_o 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d94df49__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_valid 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d96565c__3;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_store 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d96565c__2;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_vaddr 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d94a629__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h5768b7d7__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_id 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d967414__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d96565c__4;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h7d28236b__1;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h7d28236b__0;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_valid = 0U;
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid) 
         & (2U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear_cnt 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear_cnt) 
                     >> 4U));
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT____Vcellout__unit_mux__pipe_out_res_flags_o 
            = (0xffU & (IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_flags 
                                >> 0x10U)));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_valid 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_valid) 
                     >> 2U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_store 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_store) 
                     >> 2U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_vaddr 
            = (0x1fU & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_vaddr 
                        >> 0xaU));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_eew) 
                     >> 4U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_id 
            = (7U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_id) 
                     >> 6U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear) 
                     >> 2U));
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
            = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_mask[5U])) 
                << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_mask[4U])));
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
            = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_data[5U])) 
                << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_data[4U])));
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_valid 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_valid) 
                     >> 2U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done 
            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d96565c__5;
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_done) 
                     >> 2U));
    } else {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done 
            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d96565c__5;
    }
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid) 
         & (3U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear_cnt 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear_cnt) 
                     >> 6U));
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT____Vcellout__unit_mux__pipe_out_res_flags_o 
            = (0xffU & (IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_flags 
                                >> 0x18U)));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_valid 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_valid) 
                     >> 3U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_store 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_store) 
                     >> 3U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_vaddr 
            = (0x1fU & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_vaddr 
                        >> 0xfU));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_eew) 
                     >> 6U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_id 
            = (7U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_id) 
                     >> 9U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear) 
                     >> 3U));
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
            = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_mask[7U])) 
                << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_mask[6U])));
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
            = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_data[7U])) 
                << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_data[6U])));
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_valid 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_valid) 
                     >> 3U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_done) 
                     >> 3U));
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear_cnt 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d9647ad__2;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_valid 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d9647ad__1;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_id 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d967414__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h7d28236b__1;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h7d28236b__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h5768b7d7__0;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__pipe_vreg_wr_ready = 3U;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_en_d = 0U;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_addr_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vxrand_h8d94a629__1;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_mask_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vxrand_h8d3a71c0__1;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_data_d[0U] 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vxrand_hc1e25d0d__1[0U];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_data_d[1U] 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vxrand_hc1e25d0d__1[1U];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_data_d[2U] 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vxrand_hc1e25d0d__1[2U];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_data_d[3U] 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vxrand_hc1e25d0d__1[3U];
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j = 0U;
    {
        while ((2U > vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j)) {
            if (((0U == vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__PIPE_VPORT_WR
                  [(1U & vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j)]) 
                 & ((((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__1__KET____DOT__pipe__vreg_wr_valid_o) 
                      << 1U) | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__0__KET____DOT__pipe__vreg_wr_valid_o)) 
                    >> (1U & vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j)))) {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vlvbound_h910ec41a__0 = 1U;
                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_en_d 
                    = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vlvbound_h910ec41a__0;
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vlvbound_h9fe68b90__0 
                    = (0x1fU & ((9U >= (0xfU & ((IData)(5U) 
                                                * vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j)))
                                 ? (((0x3e0U & ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[5U] 
                                                 << 8U) 
                                                | (0xe0U 
                                                   & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[4U] 
                                                      >> 0x18U)))) 
                                     | (0x1fU & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[9U] 
                                                 >> 0x16U))) 
                                    >> (0xfU & ((IData)(5U) 
                                                * vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j)))
                                 : (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vxrand_h8d94a629__2)));
                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_addr_d 
                    = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT____Vlvbound_h9fe68b90__0;
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_mask_d 
                    = (0xffffU & ((((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__1__KET____DOT__pipe__vreg_wr_be_o) 
                                    << 0x10U) | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__0__KET____DOT__pipe__vreg_wr_be_o)) 
                                  >> (0x1fU & VL_SHIFTL_III(5,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 4U))));
                __Vtemp_3[0U] = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__0__KET____DOT__pipe__vreg_wr_data_o[0U];
                __Vtemp_3[1U] = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__0__KET____DOT__pipe__vreg_wr_data_o[1U];
                __Vtemp_3[2U] = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__0__KET____DOT__pipe__vreg_wr_data_o[2U];
                __Vtemp_3[3U] = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__0__KET____DOT__pipe__vreg_wr_data_o[3U];
                __Vtemp_3[4U] = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__1__KET____DOT__pipe__vreg_wr_data_o[0U];
                __Vtemp_3[5U] = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__1__KET____DOT__pipe__vreg_wr_data_o[1U];
                __Vtemp_3[6U] = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__1__KET____DOT__pipe__vreg_wr_data_o[2U];
                __Vtemp_3[7U] = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__1__KET____DOT__pipe__vreg_wr_data_o[3U];
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_data_d[0U] 
                    = (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U)))
                         ? 0U : (__Vtemp_3[((IData)(1U) 
                                            + (7U & 
                                               (VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U) 
                                                >> 5U)))] 
                                 << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U))))) 
                       | (__Vtemp_3[(7U & (VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U) 
                                           >> 5U))] 
                          >> (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U))));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_data_d[1U] 
                    = (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U)))
                         ? 0U : (__Vtemp_3[((IData)(2U) 
                                            + (7U & 
                                               (VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U) 
                                                >> 5U)))] 
                                 << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U))))) 
                       | (__Vtemp_3[((IData)(1U) + 
                                     (7U & (VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U) 
                                            >> 5U)))] 
                          >> (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U))));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_data_d[2U] 
                    = (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U)))
                         ? 0U : (__Vtemp_3[((IData)(3U) 
                                            + (7U & 
                                               (VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U) 
                                                >> 5U)))] 
                                 << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U))))) 
                       | (__Vtemp_3[((IData)(2U) + 
                                     (7U & (VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U) 
                                            >> 5U)))] 
                          >> (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U))));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_data_d[3U] 
                    = (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U)))
                         ? 0U : (__Vtemp_3[((IData)(4U) 
                                            + (7U & 
                                               (VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U) 
                                                >> 5U)))] 
                                 << ((IData)(0x20U) 
                                     - (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U))))) 
                       | (__Vtemp_3[((IData)(3U) + 
                                     (7U & (VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U) 
                                            >> 5U)))] 
                          >> (0x1fU & VL_SHIFTL_III(8,32,32, vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j, 7U))));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__unnamedblk6__DOT__k 
                    = ((IData)(1U) + vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j);
                while ((2U > vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__unnamedblk6__DOT__k)) {
                    if ((0U == vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__PIPE_VPORT_WR
                         [(1U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__unnamedblk6__DOT__k)])) {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__pipe_vreg_wr_ready 
                            = ((~ ((IData)(1U) << (1U 
                                                   & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__unnamedblk6__DOT__k))) 
                               & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__pipe_vreg_wr_ready));
                    }
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__unnamedblk6__DOT__k 
                        = ((IData)(1U) + vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__unnamedblk6__DOT__k);
                }
                goto __Vlabel1;
            }
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j 
                = ((IData)(1U) + vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vreg_wr_mux__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j);
        }
        __Vlabel1: ;
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__state_req_stall 
        = (1U & (((~ (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__state_req_q[4U] 
                      >> 5U)) & ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__state_req_q[0U] 
                                  >> 8U) & (IData)(
                                                   (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__pipe_vreg_pend_rd_to_q 
                                                    >> 
                                                    (0x1fU 
                                                     & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__state_req_q[0U] 
                                                        >> 2U)))))) 
                 | ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__lsu_queue_ready)) 
                    | (1U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT____VdfgTmp_h3926f088__0)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT____Vcellinp__lsu_queue__enq_data_i 
        = (((QData)((IData)((3U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__req_addr_q))) 
            << 0x28U) | (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__vmsk_tmp_q)) 
                          << 0x24U) | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__state_req_red));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid 
        = (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__sdata_rvalid) 
            | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q)) 
           & (0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk6__DOT__instr_queue__DOT__wr_pos_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk6__DOT__instr_queue__DOT__wr_pos_q;
    if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk6__DOT__instr_queue__DOT__push) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk6__DOT__instr_queue__DOT__wr_pos_d 
            = (1U & ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk6__DOT__instr_queue__DOT__wr_pos_q)) 
                     & ((IData)(1U) + (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk6__DOT__instr_queue__DOT__wr_pos_q))));
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_ready 
        = (1U & ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_buf_valid_q)) 
                 | ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__queue_ready) 
                    & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__queue_push))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
        = ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel))
            ? ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel))
                ? ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_a_mux_sel)
                    ? 0U : (0x1fU & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0xfU))) : vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_id)
            : ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel))
                ? vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q
                : vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__rf_rdata_a));
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b 
        = ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
            ? ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
                ? 4U : ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
                         ? ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_is_compressed_id)
                             ? 2U : 4U) : (((- (IData)(
                                                       (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                        >> 0x1fU))) 
                                            << 0x14U) 
                                           | ((0xff000U 
                                               & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id) 
                                              | ((0x800U 
                                                  & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 9U)) 
                                                 | (0x7feU 
                                                    & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                       >> 0x14U)))))))
            : ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
                ? ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
                    ? (0xfffff000U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                    : (((- (IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                    >> 0x1fU))) << 0xdU) 
                       | ((0x1000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x13U)) | 
                          ((0x800U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      << 4U)) | ((0x7e0U 
                                                  & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                       >> 7U)))))))
                : ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
                    ? (((- (IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                      >> 7U))))
                    : (((- (IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                          >> 0x14U)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr 
        = ((1U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_op)) 
           | ((2U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_op)) 
              | (3U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_op))));
    __Vtableidx1 = (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q) 
                     << 5U) | (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q) 
                                << 4U) | (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn) 
                                           << 3U) | 
                                          (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn) 
                                            << 2U) 
                                           | (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_q) 
                                               << 1U) 
                                              | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err))))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err_prio 
        = Vvproc_qdisp_bell_tb__ConstPool__TABLE_h6451e8c0_0
        [__Vtableidx1];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_prio 
        = Vvproc_qdisp_bell_tb__ConstPool__TABLE_h2aabc56c_0
        [__Vtableidx1];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio 
        = Vvproc_qdisp_bell_tb__ConstPool__TABLE_hf64aebe0_0
        [__Vtableidx1];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio 
        = Vvproc_qdisp_bell_tb__ConstPool__TABLE_h323b7bc3_0
        [__Vtableidx1];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_prio 
        = Vvproc_qdisp_bell_tb__ConstPool__TABLE_h6d182578_0
        [__Vtableidx1];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_prio 
        = Vvproc_qdisp_bell_tb__ConstPool__TABLE_hbf9cbdd6_0
        [__Vtableidx1];
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res 
        = (0x3ffffffffULL & ((0x7ffffffffULL & VL_MULS_QQQ(35, 
                                                           (0x7ffffffffULL 
                                                            & VL_EXTENDS_QI(35,17, 
                                                                            (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a) 
                                                                              << 0x10U) 
                                                                             | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_a)))), 
                                                           (0x7ffffffffULL 
                                                            & VL_EXTENDS_QI(35,17, 
                                                                            (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b) 
                                                                              << 0x10U) 
                                                                             | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b)))))) 
                             + (0x7ffffffffULL & VL_EXTENDS_QQ(35,34, vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_valid 
        = ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel))) 
           || ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid) 
               | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal 
        = ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold)) 
           & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal 
        = ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold)) 
           & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec) 
           | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q;
    if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__sdata_rvalid) {
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update 
                        = (1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)));
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
                        = vlSelf->vproc_qdisp_bell_tb__DOT__mem_err;
                }
            }
        }
    } else if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
            if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__sdata_rvalid) 
                 | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update 
                    = (1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)));
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
                    = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__mem_err) 
                       | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q));
            }
        }
    } else if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
        if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d = 0U;
        }
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__perf_store = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__perf_load = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out = 0U;
    if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req) {
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__perf_store 
                        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we;
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__perf_load 
                        = (1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we)));
                }
            }
        }
        if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out = 1U;
        } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out = 1U;
        } else if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out = 1U;
        }
    }
    vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_valid 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__cpi_instr_valid) 
           & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vproc_issue_block)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_invalid = 0U;
    __Vtemp_10[3U] = ((((IData)(((4U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit)) 
                                 & (0x800U == (0xf80U 
                                               & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)))))
                         ? ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                             << 0x19U) | (0xf80U & 
                                          (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                           >> 7U)))
                         : (((4U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit)) 
                             & (((0x11U == (0x1fU & 
                                            ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                             >> 7U))) 
                                 | (0x12U == (0x1fU 
                                              & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                                 >> 7U)))) 
                                | (0x13U == (0x1fU 
                                             & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                                >> 7U)))))
                             ? (0x7f80U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                           >> 7U)) : 0U)) 
                       << 8U) | (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit) 
                                  << 5U) | ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                            >> 8U)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[0U] 
        = (IData)(((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                    << 8U) | (QData)((IData)((((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o) 
                                               << 2U) 
                                              | ((((~ 
                                                    ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                                     >> 0xbU)) 
                                                   & (0U 
                                                      == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit))) 
                                                  << 1U) 
                                                 | ((0U 
                                                     == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit)) 
                                                    & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                                       >> 0xbU))))))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[1U] 
        = (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
            << 0xfU) | (IData)((((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                                  << 8U) | (QData)((IData)(
                                                           (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o) 
                                                             << 2U) 
                                                            | ((((~ 
                                                                  ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                                                   >> 0xbU)) 
                                                                 & (0U 
                                                                    == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit))) 
                                                                << 1U) 
                                                               | ((0U 
                                                                   == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit)) 
                                                                  & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                                                     >> 0xbU))))))) 
                                >> 0x20U)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[2U] 
        = (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
            << 0x18U) | (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o) 
                          << 0x16U) | (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o) 
                                        >> 0x11U) | 
                                       ((IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                                                 >> 0x20U)) 
                                        << 0xfU))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[3U] 
        = __Vtemp_10[3U];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[4U] 
        = ((0xffffff00U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[4U]) 
           | (((IData)(((4U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit)) 
                        & (0x800U == (0xf80U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode)))))
                ? ((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[3U] 
                    << 0x19U) | (0xf80U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                           >> 7U)))
                : (((4U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit)) 
                    & (((0x11U == (0x1fU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                            >> 7U))) 
                        | (0x12U == (0x1fU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                              >> 7U)))) 
                       | (0x13U == (0x1fU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                             >> 7U)))))
                    ? (0x7f80U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                  >> 7U)) : 0U)) >> 0x18U));
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vsew_o 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h5768b7d7__0;
    if ((0U != (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit))) {
        if ((0U != (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o))) {
            if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_invalid = 1U;
                    }
                }
            }
        }
        if ((0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o))) {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vsew_o 
                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q;
        } else if ((0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vsew_o = 1U;
        } else if ((1U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vsew_o = 2U;
        }
    }
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d94cf21__0;
    if ((0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit))) {
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h4b4b6c32__1;
        if ((0x100U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode))) {
            if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                          >> 7U)))) {
                if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
                    if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q)))) {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q;
                        if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                            if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                            } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                            }
                        } else {
                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                                = ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                    ? ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                        ? 3U : 2U) : 
                                   ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                     ? 1U : 0U));
                        }
                    }
                } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                        = (1U | (0x7eU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q) 
                                          << 1U)));
                    if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                        } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                        }
                    } else if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q)))) {
                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 3U;
                        }
                    } else {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                            = ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                ? 2U : 1U);
                    }
                } else {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                        = (3U | (0x7cU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q) 
                                          << 2U)));
                    if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                                = ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                    ? 1U : 0U);
                        } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                        }
                    } else if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q) 
                                         >> 1U)))) {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                            = ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                ? 3U : 2U);
                    }
                }
            }
        } else if ((0x80U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode))) {
            if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
                if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q)))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                        = (0x3fU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q) 
                                    >> 1U));
                    if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                        } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                        }
                    } else {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                            = ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                ? ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                    ? 2U : 1U) : 0U);
                    }
                }
            } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                    = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q;
                if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                    } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                    }
                } else {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                        = ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                            ? ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                ? 3U : 2U) : ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                               ? 1U
                                               : 0U));
                }
            } else {
                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                    = (1U | (0x7eU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q) 
                                      << 1U)));
                if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                    } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                    }
                } else if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q)))) {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 3U;
                    }
                } else {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                        = ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                            ? 2U : 1U);
                }
            }
        } else if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
            if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q)))) {
                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                    = (0x1fU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q) 
                                >> 2U));
                if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                    } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                    }
                } else {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                        = ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                            ? ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                ? 1U : 0U) : 0U);
                }
            }
        } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                = (0x3fU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q) 
                            >> 1U));
            if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                }
            } else {
                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                    = ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                        ? ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                            ? 2U : 1U) : 0U);
            }
        } else {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q;
            if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                }
            } else {
                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                    = ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                        ? ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                            ? 3U : 2U) : ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                           ? 1U : 0U));
            }
        }
    } else {
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h4b4b6c32__1;
        if ((0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o))) {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q;
            if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                }
            } else {
                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                    = ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                        ? ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                            ? 3U : 2U) : ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                                           ? 1U : 0U));
            }
        } else {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
                = (1U | (0x7eU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q) 
                                  << 1U)));
            if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
                }
            } else if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))) {
                if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q)))) {
                    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 3U;
                }
            } else {
                vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
                    = ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q))
                        ? 2U : 1U);
            }
        }
    }
    if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul_override) {
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o 
            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__emul;
    }
    if ((1U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__evl_pol))) {
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d94cf21__1;
        if ((0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o = 0U;
        } else if ((1U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o = 1U;
        } else if ((2U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vsew_q))) {
            vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o = 3U;
        }
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
    } else if ((2U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__evl_pol))) {
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o 
            = (0xfU & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_q) 
                       >> 3U));
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o = 0U;
    } else if ((3U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__evl_pol))) {
        vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o = 0x7fU;
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_vaddr 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d94a629__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_store 
        = ((0xffU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_store)) 
           | ((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_store_o) 
              << 8U));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear 
        = ((0xfU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear)) 
           | ((((~ (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__elem__DOT__state_res_q[3U] 
                    >> 0x1fU)) & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT____VdfgTmp_h2d683f5e__0)) 
               | (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_last_cycle)) 
              << 4U));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_done 
        = ((0xfU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_done)) 
           | (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT____VdfgTmp_h2d683f5e__0) 
               | (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__flushing_last_cycle)) 
              << 4U));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_flags[2U] 
        = (0xffffU & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vcellout__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit__pipe_out_res_flags_o));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_issued_done_cnt_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_issued_done_cnt_q;
    if ((0U != (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_issued_done_cnt_q))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_issued_done_cnt_d 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_issued_done_cnt_q) 
                     - (IData)(1U)));
    }
    if (vlSelf->vproc_qdisp_bell_tb__DOT__measure_done) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_issued_done_cnt_d = 0U;
    } else if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__qsg_measure_stream_done) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__measure_issued_done_cnt_d = 2U;
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we = 0U;
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__quantum_valid) 
         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__quantum_data_ready_d))) {
        if ((0x10U > (0xffU & vlSelf->vproc_qdisp_bell_tb__DOT__quantum_elem1))) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl 
                = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl) 
                   | (0xffffU & ((IData)(1U) << (0xfU 
                                                 & vlSelf->vproc_qdisp_bell_tb__DOT__quantum_elem1))));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we 
                = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                   | (0xffffU & ((IData)(1U) << (0xfU 
                                                 & vlSelf->vproc_qdisp_bell_tb__DOT__quantum_elem1))));
        }
        if ((((0x11U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__quantum_op)) 
              & (0x10U > (0xffU & vlSelf->vproc_qdisp_bell_tb__DOT__quantum_elem2))) 
             & ((0xffU & vlSelf->vproc_qdisp_bell_tb__DOT__quantum_elem2) 
                != (0xffU & vlSelf->vproc_qdisp_bell_tb__DOT__quantum_elem1)))) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl 
                = ((~ ((IData)(1U) << (0xfU & vlSelf->vproc_qdisp_bell_tb__DOT__quantum_elem2))) 
                   & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_ctrl));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we 
                = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__fifo_we) 
                   | (0xffffU & ((IData)(1U) << (0xfU 
                                                 & vlSelf->vproc_qdisp_bell_tb__DOT__quantum_elem2))));
        }
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__msk_buffer_next 
        = ((0xff00U & ((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask) 
                       << 8U)) | (0xffU & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[0U] 
                                           >> 4U)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__msk_buffer_next 
        = ((0xff00U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__msk_buffer_next)) 
           | (0xffU & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[0U] 
                       >> 0xcU)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__res_buffer_next[0U] 
        = (IData)((((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[2U])) 
                    << 0x2cU) | (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[1U])) 
                                  << 0xcU) | ((QData)((IData)(
                                                              vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[0U])) 
                                              >> 0x14U))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__res_buffer_next[1U] 
        = (IData)(((((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[2U])) 
                     << 0x2cU) | (((QData)((IData)(
                                                   vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[1U])) 
                                   << 0xcU) | ((QData)((IData)(
                                                               vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[0U])) 
                                               >> 0x14U))) 
                   >> 0x20U));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__res_buffer_next[2U] 
        = (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data);
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__res_buffer_next[3U] 
        = (IData)((vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
                   >> 0x20U));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__res_buffer_next[0U] 
        = (IData)((((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[4U])) 
                    << 0x2cU) | (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[3U])) 
                                  << 0xcU) | ((QData)((IData)(
                                                              vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[2U])) 
                                              >> 0x14U))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__res_buffer_next[1U] 
        = (IData)(((((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[4U])) 
                     << 0x2cU) | (((QData)((IData)(
                                                   vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[3U])) 
                                   << 0xcU) | ((QData)((IData)(
                                                               vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[2U])) 
                                               >> 0x14U))) 
                   >> 0x20U));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vxrand_h8d9668fa__2;
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid) 
         & (0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear_cnt 
            = (3U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear_cnt));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_valid 
            = (3U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_valid));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_id 
            = (7U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_id));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
            = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_mask[1U])) 
                << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_mask[0U])));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
            = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_data[1U])) 
                << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_data[0U])));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew 
            = (3U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_eew));
    }
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid) 
         & (1U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear_cnt 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear_cnt) 
                     >> 2U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_valid 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_valid) 
                     >> 2U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_id 
            = (7U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_id) 
                     >> 3U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
            = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_mask[3U])) 
                << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_mask[2U])));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
            = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_data[3U])) 
                << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_data[2U])));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_eew) 
                     >> 2U));
    }
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid) 
         & (4U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear_cnt 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear_cnt) 
                     >> 8U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_valid 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_valid) 
                     >> 8U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_id 
            = (7U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_id) 
                     >> 0xcU));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
            = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_mask[9U])) 
                << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_mask[8U])));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
            = (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_data[9U])) 
                << 0x20U) | (QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_data[8U])));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_eew) 
                     >> 8U));
    }
    if ((0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem 
            = ((0xeU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem)) 
               | (1U & ((IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
                                 >> 0x20U)) | (~ (IData)(
                                                         (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
                                                          >> 0x20U))))));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem 
            = ((0xdU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem)) 
               | (2U & (((IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
                                  >> 0x21U)) | (~ (IData)(
                                                          (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
                                                           >> 0x21U)))) 
                        << 1U)));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem 
            = ((0xbU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem)) 
               | (4U & (((IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
                                  >> 0x22U)) | (~ (IData)(
                                                          (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
                                                           >> 0x22U)))) 
                        << 2U)));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem 
            = ((7U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem)) 
               | (8U & (((IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
                                  >> 0x23U)) | (~ (IData)(
                                                          (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
                                                           >> 0x23U)))) 
                        << 3U)));
    } else if ((1U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem 
            = ((0xeU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem)) 
               | (1U & ((IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
                                 >> 0x20U)) | (~ (IData)(
                                                         (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
                                                          >> 0x20U))))));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem 
            = ((0xdU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem)) 
               | (2U & (((IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
                                  >> 0x22U)) | (~ (IData)(
                                                          (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
                                                           >> 0x22U)))) 
                        << 1U)));
    } else if ((2U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem 
            = ((0xeU & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__res_elem)) 
               | (1U & ((IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_data 
                                 >> 0x20U)) | (~ (IData)(
                                                         (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_mask 
                                                          >> 0x20U))))));
    }
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vlvbound_h9642f6c1__0 
        = vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_en_d;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_en_q 
        = vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vlvbound_h9642f6c1__0;
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vlvbound_hf986c43c__0 
        = vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_addr_d;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vregfile_wr_addr_q 
        = vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vlvbound_hf986c43c__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_ready 
        = (1U & ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_valid_q)) 
                 | ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_stall)) 
                    & ((~ (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[4U] 
                           >> 0x1cU)) | ((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__pipe_vreg_wr_ready) 
                                         >> 1U)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_ready 
        = (1U & ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_valid_q)) 
                 | ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_stall)) 
                    & ((0U == (3U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[9U] 
                                     >> 0x14U))) | (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__pipe_vreg_wr_ready)))));
    vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit_xif.mem_valid 
        = ((((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__state_req_valid_q) 
             & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__req_suppress))) 
            & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__state_req_stall))) 
           & ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__mem_exc_q)) 
              | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__state_req_q[4U] 
                 >> 0x13U)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT____Vcellout__lsu_queue__deq_data_o 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__lsu_queue__DOT__data
        [vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__lsu_queue__DOT__rd_pos_q];
    if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__lsu_queue__DOT__empty) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT____Vcellout__lsu_queue__deq_data_o 
            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT____Vcellinp__lsu_queue__enq_data_i;
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_d 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err) 
           & ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)) 
              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_d 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err) 
           & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q) 
              & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)));
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev 
        = ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
            << 0x1fU) | ((0x40000000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                         << 0x1dU)) 
                         | ((0x20000000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                            << 0x1bU)) 
                            | ((0x10000000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                               << 0x19U)) 
                               | ((0x8000000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                 << 0x17U)) 
                                  | ((0x4000000U & 
                                      (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                       << 0x15U)) | 
                                     ((0x2000000U & 
                                       (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                        << 0x13U)) 
                                      | ((0x1000000U 
                                          & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                             << 0x11U)) 
                                         | ((0x800000U 
                                             & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                << 0xfU)) 
                                            | ((0x400000U 
                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                   << 0xdU)) 
                                               | ((0x200000U 
                                                   & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                      << 0xbU)) 
                                                  | ((0x100000U 
                                                      & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                         << 9U)) 
                                                     | ((0x80000U 
                                                         & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                            << 7U)) 
                                                        | ((0x40000U 
                                                            & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                               << 5U)) 
                                                           | ((0x20000U 
                                                               & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                  << 3U)) 
                                                              | ((0x10000U 
                                                                  & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                     << 1U)) 
                                                                 | ((0x8000U 
                                                                     & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                        >> 1U)) 
                                                                    | ((0x4000U 
                                                                        & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                           >> 3U)) 
                                                                       | ((0x2000U 
                                                                           & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                              >> 5U)) 
                                                                          | ((0x1000U 
                                                                              & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 7U)) 
                                                                             | ((0x800U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x1dU)) 
                                                                                | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x1fU))))))))))))))))))))))))))))))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex 
        = (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec) 
            | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req))
            ? vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b
            : vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__rf_rdata_b);
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval = 0U;
    if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs)))) {
                    if ((1U & (~ (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                                   | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                                  | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))))) {
                        if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn) {
                            if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_d = 0U;
                            }
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id = 1U;
                        }
                        if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn)))) {
                            if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn) {
                                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id = 1U;
                            }
                        }
                    }
                    if ((((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                          | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                         | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))) {
                        if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err_prio) {
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval 
                                = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err_plus2)
                                    ? ((IData)(2U) 
                                       + vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_id)
                                    : vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_id);
                        } else if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_prio) {
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval 
                                = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_is_compressed_id)
                                    ? (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_c_id)
                                    : vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id);
                        } else if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio)))) {
                            if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio)))) {
                                if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_prio) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval 
                                        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
                                } else if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_prio) {
                                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval 
                                        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = 0U;
    if ((8U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                          >> 1U)))) {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_d = 1U;
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 2U;
                if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug) 
                         & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)))) {
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id = 1U;
                    }
                }
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = 1U;
            }
        }
    } else if ((4U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs)))) {
                if ((1U & (~ (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                               | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                              | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))))) {
                    if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn)))) {
                        if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn) {
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_d = 0U;
                        }
                    }
                }
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = 1U;
                if ((((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                      | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                     | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))) {
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id = 0U;
                    if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err_prio)))) {
                        if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_prio)))) {
                            if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio)))) {
                                if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio) {
                                    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q) 
                                         | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug))) {
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id = 0U;
                                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = 0U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 2U;
            } else if ((((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                         | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                        | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))) {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 2U;
            } else if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn) {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 3U;
            } else if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn) {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 4U;
            }
        } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 1U;
        }
    } else {
        if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                      >> 1U)))) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 0U;
        }
        if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = 1U;
        }
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
        = ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q))
            ? ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q))
                ? vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res
                : ((0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator))
                    ? (((QData)((IData)((0xffffU & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res)))) 
                        << 0x10U) | (QData)((IData)(
                                                    (0xffffU 
                                                     & (IData)(
                                                               vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                               [0U])))))
                    : vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res))
            : ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q))
                ? ((0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator))
                    ? (((QData)((IData)((0xffffU & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res)))) 
                        << 0x10U) | (QData)((IData)(
                                                    (0xffffU 
                                                     & (IData)(
                                                               vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                               [0U])))))
                    : vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res)
                : vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_we_ex 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
            ? (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal) 
                << 1U) | ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal) 
                          | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal)))
            : 0U);
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__perf_branch = 0U;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw = 0U;
    if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) {
        if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q)))) {
            if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec)))) {
                if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec)))) {
                    if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec) {
                        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__perf_branch = 1U;
                    }
                    if ((1U & (~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec)))) {
                        if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec) {
                            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw 
                                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_dec;
                        }
                    }
                }
            }
        }
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[4U] 
        = ((0xffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[4U]) 
           | ((IData)((((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vsew_o)) 
                        << 0x2fU) | (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q)) 
                                      << 0x2cU) | (
                                                   ((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o)) 
                                                    << 0x2aU) 
                                                   | (((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o)) 
                                                       << 0x28U) 
                                                      | (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_0_q)) 
                                                          << 0x27U) 
                                                         | ((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o)) 
                                                            << 0x20U))))))) 
              << 8U));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[5U] 
        = ((0xe000000U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[5U]) 
           | (0xfffffffU & (((IData)((((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vsew_o)) 
                                       << 0x2fU) | 
                                      (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q)) 
                                        << 0x2cU) | 
                                       (((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o)) 
                                         << 0x2aU) 
                                        | (((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o)) 
                                            << 0x28U) 
                                           | (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_0_q)) 
                                               << 0x27U) 
                                              | ((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o)) 
                                                 << 0x20U))))))) 
                             >> 0x18U) | ((IData)((
                                                   (((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vsew_o)) 
                                                     << 0x2fU) 
                                                    | (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__lmul_q)) 
                                                        << 0x2cU) 
                                                       | (((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o)) 
                                                           << 0x2aU) 
                                                          | (((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vxrm_o)) 
                                                              << 0x28U) 
                                                             | (((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__vl_0_q)) 
                                                                 << 0x27U) 
                                                                | ((QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__vl_o)) 
                                                                   << 0x20U)))))) 
                                                   >> 0x20U)) 
                                          << 8U))));
    __Vtableidx7 = (((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__emul_o) 
                     << 6U) | (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d967414__1) 
                                << 3U) | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT____Vxrand_h8d967414__0)));
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask 
        = Vvproc_qdisp_bell_tb__ConstPool__TABLE_ha97e7bf2_0
        [__Vtableidx7];
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask_narrow 
        = Vvproc_qdisp_bell_tb__ConstPool__TABLE_hfcf48252_0
        [__Vtableidx7];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_store 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d9647ad__0;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d96565c__2;
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid) 
         & (0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_vaddr 
            = (0x1fU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_vaddr);
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_store 
            = (3U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_store));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear 
            = (1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done 
            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d96565c__3;
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done 
            = (1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_done));
    } else {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done 
            = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d96565c__3;
    }
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid) 
         & (1U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_vaddr 
            = (0x1fU & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_vaddr 
                        >> 5U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_store 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_store) 
                     >> 2U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear) 
                     >> 1U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_done) 
                     >> 1U));
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT____Vcellout__unit_mux__pipe_out_res_flags_o 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT____Vxrand_h8d3a71c0__0;
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid) 
         & (0U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT____Vcellout__unit_mux__pipe_out_res_flags_o 
            = (0xffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_flags[0U]);
    }
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid) 
         & (1U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT____Vcellout__unit_mux__pipe_out_res_flags_o 
            = (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_flags[0U] 
               >> 0x10U);
    }
    if (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid) 
         & (4U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_vaddr 
            = (0x1fU & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_vaddr 
                        >> 0x14U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_store 
            = (3U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_store) 
                     >> 8U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_pend_clear) 
                     >> 4U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done 
            = (1U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_instr_done) 
                     >> 4U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT____Vcellout__unit_mux__pipe_out_res_flags_o 
            = (0xffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_res_flags[2U]);
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_valid_d 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_valid_q;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__1__KET____DOT__pipe__vreg_wr_clr_o 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_valid_q) 
           & ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[0U] 
               >> 3U) & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_ready)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[0U] 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[0U];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[1U] 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[1U];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[2U] 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[2U];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[3U] 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[3U];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[4U] 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[4U];
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[5U] 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[5U];
    if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_ready) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_valid_d 
            = vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_valid;
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[4U] 
            = ((0xfffffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[4U]) 
               | (0xf0000000U & (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_vaddr) 
                                  << 0x1dU) | ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_store) 
                                               << 0x1cU))));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[5U] 
            = (0x7fU & ((0xffffff0U & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_id) 
                                       << 4U)) | ((0xffffffcU 
                                                   & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_eew) 
                                                      << 2U)) 
                                                  | ((0xfffffffU 
                                                      & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_vaddr) 
                                                         >> 3U)) 
                                                     | ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_store) 
                                                        >> 4U)))));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[4U] 
            = ((0xf00fffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[4U]) 
               | ((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT____Vcellout__unit_mux__pipe_out_res_flags_o) 
                  << 0x14U));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[0U] 
            = ((0xfffffff0U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[0U]) 
               | (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear) 
                   << 3U) | (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_pend_clear_cnt) 
                              << 1U) | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done))));
        if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_res_valid) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[0U] 
                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__res_buffer_next[0U];
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[1U] 
                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__res_buffer_next[1U];
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[2U] 
                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__res_buffer_next[2U];
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[3U] 
                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__res_buffer_next[3U];
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[0U] 
                = ((0xfffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[0U]) 
                   | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[0U] 
                      << 0x14U));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[1U] 
                = ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[0U] 
                    >> 0xcU) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[1U] 
                                << 0x14U));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[2U] 
                = ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[1U] 
                    >> 0xcU) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[2U] 
                                << 0x14U));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[3U] 
                = ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[2U] 
                    >> 0xcU) | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[3U] 
                                << 0x14U));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[4U] 
                = ((0xfff00000U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[4U]) 
                   | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h78f8151c__0[3U] 
                      >> 0xcU));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h881a2e1e__0 
                = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__msk_buffer_next;
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[0U] 
                = ((0xfff0000fU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_d[0U]) 
                   | ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT____Vlvbound_h881a2e1e__0) 
                      << 4U));
        }
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue__DOT__pop = 0U;
    if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue__DOT____VdfgExtracted_h9469d920__1) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue__DOT__pop 
            = ((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_valid) 
               & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_instr_done) 
                  & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_ready)));
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_ready 
        = (0x1fU & (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_ready) 
                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid)) 
                    << (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__genblk9__BRA__0__KET____DOT__pipe__vreg_wr_clr_o 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_valid_q) 
           & ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[0U] 
               >> 3U) & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_ready)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_complete_valid 
        = ((((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_valid_q) 
             & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[0U] 
                & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_ready))) 
            << 1U) | ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_valid_q) 
                      & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__stage_state_q[0U] 
                         & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_ready))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_out_ready 
        = (0x1fU & (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_out_ready) 
                     & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_valid)) 
                    << (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__unit_queue_deq_unit_vector)));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__data_we 
        = vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we;
    if (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit_xif.mem_valid) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__data_we 
            = (1U & (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.mem_req[1U] 
                     >> 0xbU));
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT__xif_mem_result_id_valid 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vdata_rvalid) 
           & ((7U & (IData)((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit_xif.mem_result 
                             >> 0x22U))) == (7U & (IData)(
                                                          (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit__DOT__genblk1__DOT__lsu__DOT____Vcellout__lsu_queue__deq_data_o 
                                                           >> 0x1fU)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_err 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_d) 
           | (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_d));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result 
        = (((3U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)) 
            | (6U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)))
            ? (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
               | vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)
            : (((4U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)) 
                | (7U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)))
                ? (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                   & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)
                : (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                   ^ vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)));
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left)
            ? vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev
            : vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a);
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed 
        = (0x1ffffffffULL & VL_SHIFTRS_QQI(33,33,5, 
                                           (((QData)((IData)(
                                                             ((8U 
                                                               == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)) 
                                                              & (vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand 
                                                                 >> 0x1fU)))) 
                                             << 0x20U) 
                                            | (QData)((IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand))), 
                                           (0x1fU & 
                                            ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id)
                                              ? vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex
                                              : (- vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)))));
    vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext 
        = vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed;
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
        = (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext);
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffffff8U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((4U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                     >> 0x1bU)) | ((2U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                          >> 0x1dU)) 
                                   | (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                      >> 0x1fU))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffffffc7U & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                        >> 0x15U)) | ((0x10U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                >> 0x17U)) 
                                      | (8U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               >> 0x19U)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffffe3fU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x100U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                         >> 0xfU)) | ((0x80U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                >> 0x11U)) 
                                      | (0x40U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                  >> 0x13U)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffff1ffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x800U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                         >> 9U)) | ((0x400U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               >> 0xbU)) 
                                    | (0x200U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 >> 0xdU)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffff8fffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x4000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                          >> 3U)) | ((0x2000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 >> 5U)) 
                                     | (0x1000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                   >> 7U)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffc7fffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                           << 3U)) | ((0x10000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                   << 1U)) 
                                      | (0x8000U & 
                                         (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                          >> 1U)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffe3ffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x100000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                            << 9U)) | ((0x80000U & 
                                        (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                         << 7U)) | 
                                       (0x40000U & 
                                        (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                         << 5U)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xff1fffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x800000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                            << 0xfU)) | ((0x400000U 
                                          & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                             << 0xdU)) 
                                         | (0x200000U 
                                            & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               << 0xbU)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xf8ffffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x4000000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                             << 0x15U)) | ((0x2000000U 
                                            & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               << 0x13U)) 
                                           | (0x1000000U 
                                              & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 << 0x11U)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xc7ffffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20000000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                              << 0x1bU)) | ((0x10000000U 
                                             & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                << 0x19U)) 
                                            | (0x8000000U 
                                               & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                  << 0x17U)))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0x3fffffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
               << 0x1fU) | (0x40000000U & (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                           << 0x1dU))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
        = ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left)
            ? vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev
            : vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result);
    if (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_access) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_idx 
            = (0x1fU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex);
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_addr 
            = (0xfffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex);
    } else {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_idx = 0U;
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__csr_addr = 0U;
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
        = (0x3ffffffffULL & (((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                               ? vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a
                               : (1ULL | ((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a)) 
                                          << 1U))) 
                             + (0x1ffffffffULL & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                                   ? vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b
                                                   : 
                                                  ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate)
                                                    ? 
                                                   (~ 
                                                    ((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                                     << 1U))
                                                    : 
                                                   ((QData)((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                                    << 1U))))));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set 
        = ((~ (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_q)) 
           & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw));
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__source_xreg_valid 
        = (1U & (((~ (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[2U] 
                      >> 0x14U)) | vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U]) 
                 & ((~ (vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec_data_d[1U] 
                        >> 0xdU)) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[0U] 
                                     >> 1U))));
    if ((2U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o))) {
        if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o))) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vd_invalid 
                = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                            << 0x12U) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                         >> 0xeU)) 
                          & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask_narrow)));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs2_invalid 
                = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                            << 5U) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                      >> 0x1bU)) & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask)));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs1_invalid 
                = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                            << 0xaU) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                        >> 0x16U)) 
                          & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask)));
        } else {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vd_invalid 
                = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                            << 0x12U) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                         >> 0xeU)) 
                          & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask)));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs2_invalid 
                = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                            << 5U) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                      >> 0x1bU)) & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask)));
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs1_invalid 
                = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                            << 0xaU) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                        >> 0x16U)) 
                          & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask_narrow)));
        }
    } else if ((1U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__widenarrow_o))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vd_invalid 
            = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                        << 0x12U) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                     >> 0xeU)) & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask)));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs2_invalid 
            = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                        << 5U) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                  >> 0x1bU)) & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask_narrow)));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs1_invalid 
            = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                        << 0xaU) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                    >> 0x16U)) & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask_narrow)));
    } else {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vd_invalid 
            = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                        << 0x12U) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                     >> 0xeU)) & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask)));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs2_invalid 
            = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                        << 5U) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                  >> 0x1bU)) & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask)));
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs1_invalid 
            = (0U != (((vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                        << 0xaU) | (vlSymsp->TOP__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif.issue_req[2U] 
                                    >> 0x16U)) & (IData)(vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__regaddr_mask)));
    }
    if (((1U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit)) 
         & ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
            >> 0xcU))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vd_invalid = 0U;
    }
    if ((4U == (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_unit))) {
        if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                      >> 0xbU)))) {
            if ((0x400U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode))) {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vd_invalid = 0U;
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs1_invalid = 0U;
            }
        }
        if ((0x800U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode))) {
            vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs2_invalid = 0U;
        } else if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                             >> 0xaU)))) {
            if ((0x200U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode))) {
                if ((0x100U & (IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode))) {
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs2_invalid = 0U;
                } else if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__instr_mode) 
                                     >> 7U)))) {
                    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs2_invalid = 0U;
                }
            } else {
                vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs2_invalid = 0U;
            }
        }
    }
    if ((1U & (~ ((IData)(vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rd_o) 
                  >> 5U)))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vd_invalid = 0U;
    }
    if ((1U & (~ (IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs2_o 
                          >> 0x26U))))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs2_invalid = 0U;
    }
    if ((1U & (~ (IData)((vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT____Vcellout__dec__rs1_o 
                          >> 0x26U))))) {
        vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__dec__DOT__vs1_invalid = 0U;
    }
    vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__msk_buffer_next 
        = (0xffffU & vlSelf->vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__pack__DOT__msk_buffer_next);
}
