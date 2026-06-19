// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vvproc_qdisp_bell_tb.h for the primary calling header

#ifndef VERILATED_VVPROC_QDISP_BELL_TB_TIMED_FIFO__O8_H_
#define VERILATED_VVPROC_QDISP_BELL_TB_TIMED_FIFO__O8_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vvproc_qdisp_bell_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vvproc_qdisp_bell_tb_timed_fifo__O8 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(i_fifo_op,7,0);
    VL_IN8(i_fifo_we,0,0);
    VL_OUT8(o_data,7,0);
    VL_OUT8(o_valid,0,0);
    VL_OUT8(error,0,0);
    CData/*0:0*/ __PVT__fifo_rd_en;
    CData/*0:0*/ __PVT__fifo_empty;
    CData/*0:0*/ __PVT__fifo_full;
    CData/*3:0*/ __PVT__u_inst_fifo__DOT__write_ptr;
    CData/*3:0*/ __PVT__u_inst_fifo__DOT__read_ptr;
    CData/*1:0*/ __PVT__u_time_ctrl__DOT__state;
    CData/*1:0*/ __PVT__u_time_ctrl__DOT__next_state;
    VL_IN(i_fifo_time,19,0);
    VL_IN(t_cnt,19,0);
    IData/*27:0*/ __PVT__u_inst_fifo__DOT__data_out_reg;
    VlUnpacked<IData/*27:0*/, 8> __PVT__u_inst_fifo__DOT__memory;

    // INTERNAL VARIABLES
    Vvproc_qdisp_bell_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vvproc_qdisp_bell_tb_timed_fifo__O8(Vvproc_qdisp_bell_tb__Syms* symsp, const char* v__name);
    ~Vvproc_qdisp_bell_tb_timed_fifo__O8();
    VL_UNCOPYABLE(Vvproc_qdisp_bell_tb_timed_fifo__O8);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
