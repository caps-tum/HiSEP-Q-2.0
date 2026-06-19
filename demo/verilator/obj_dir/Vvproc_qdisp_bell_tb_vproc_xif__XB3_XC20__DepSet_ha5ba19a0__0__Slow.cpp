// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvproc_qdisp_bell_tb.h for the primary calling header

#include "Vvproc_qdisp_bell_tb__pch.h"
#include "Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20.h"

VL_ATTR_COLD void Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20___ctor_var_reset(Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvproc_qdisp_bell_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                        Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20___ctor_var_reset\n"); );
    // Body
    vlSelf->mem_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(81, vlSelf->mem_req);
    vlSelf->mem_resp = VL_RAND_RESET_I(8);
    vlSelf->mem_result = VL_RAND_RESET_Q(37);
}
