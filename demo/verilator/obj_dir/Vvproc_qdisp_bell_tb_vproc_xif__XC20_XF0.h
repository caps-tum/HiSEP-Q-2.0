// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vvproc_qdisp_bell_tb.h for the primary calling header

#ifndef VERILATED_VVPROC_QDISP_BELL_TB_VPROC_XIF__XC20_XF0_H_
#define VERILATED_VVPROC_QDISP_BELL_TB_VPROC_XIF__XC20_XF0_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vvproc_qdisp_bell_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vvproc_qdisp_bell_tb_vproc_xif__XC20_XF0 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ issue_valid;
    CData/*0:0*/ issue_ready;
    CData/*7:0*/ issue_resp;
    VlWide<4>/*102:0*/ issue_req;
    VlWide<3>/*80:0*/ mem_req;

    // INTERNAL VARIABLES
    Vvproc_qdisp_bell_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vvproc_qdisp_bell_tb_vproc_xif__XC20_XF0(Vvproc_qdisp_bell_tb__Syms* symsp, const char* v__name);
    ~Vvproc_qdisp_bell_tb_vproc_xif__XC20_XF0();
    VL_UNCOPYABLE(Vvproc_qdisp_bell_tb_vproc_xif__XC20_XF0);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vvproc_qdisp_bell_tb_vproc_xif__XC20_XF0* obj);

#endif  // guard
