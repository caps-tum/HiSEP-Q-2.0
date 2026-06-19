// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vvproc_qdisp_bell_tb.h for the primary calling header

#ifndef VERILATED_VVPROC_QDISP_BELL_TB_VPROC_XIF__XB3_XC20_H_
#define VERILATED_VVPROC_QDISP_BELL_TB_VPROC_XIF__XB3_XC20_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vvproc_qdisp_bell_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ mem_valid;
    CData/*7:0*/ mem_resp;
    VlWide<3>/*80:0*/ mem_req;
    QData/*36:0*/ mem_result;

    // INTERNAL VARIABLES
    Vvproc_qdisp_bell_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20(Vvproc_qdisp_bell_tb__Syms* symsp, const char* v__name);
    ~Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20();
    VL_UNCOPYABLE(Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20* obj);

#endif  // guard
