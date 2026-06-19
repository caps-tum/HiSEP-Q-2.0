// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vvproc_qdisp_bell_tb__pch.h"

//============================================================
// Constructors

Vvproc_qdisp_bell_tb::Vvproc_qdisp_bell_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vvproc_qdisp_bell_tb__Syms(contextp(), _vcname__, this)}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__vcore_xif}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe_xif{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe_xif}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe_xif{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__1__KET____DOT__pipe_xif}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit_xif{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__0__KET____DOT__genblk1__DOT__unit_xif}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit_xif{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__1__KET____DOT__genblk1__DOT__unit_xif}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit_xif{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_vproc__DOT__v_core__DOT__genblk9__BRA__0__KET____DOT__pipe__DOT__genblk2__DOT__pipeline__DOT__unit_mux__DOT__genblk1__BRA__4__KET____DOT__genblk1__DOT__unit_xif}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__0__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__0__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__1__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__1__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__2__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__2__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__3__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__3__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__4__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__4__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__5__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__5__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__6__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__6__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__7__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__7__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__8__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__8__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__9__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__9__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__10__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__10__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__11__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__11__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__12__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__12__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__13__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__13__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__14__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__14__KET____DOT__u_timed_fifo}
    , __PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__15__KET____DOT__u_timed_fifo{vlSymsp->TOP.__PVT__vproc_qdisp_bell_tb__DOT__dut__DOT__u_qdisp__DOT__GEN_QUBIT__BRA__15__KET____DOT__u_timed_fifo}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vvproc_qdisp_bell_tb::Vvproc_qdisp_bell_tb(const char* _vcname__)
    : Vvproc_qdisp_bell_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vvproc_qdisp_bell_tb::~Vvproc_qdisp_bell_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vvproc_qdisp_bell_tb___024root___eval_debug_assertions(Vvproc_qdisp_bell_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vvproc_qdisp_bell_tb___024root___eval_static(Vvproc_qdisp_bell_tb___024root* vlSelf);
void Vvproc_qdisp_bell_tb___024root___eval_initial(Vvproc_qdisp_bell_tb___024root* vlSelf);
void Vvproc_qdisp_bell_tb___024root___eval_settle(Vvproc_qdisp_bell_tb___024root* vlSelf);
void Vvproc_qdisp_bell_tb___024root___eval(Vvproc_qdisp_bell_tb___024root* vlSelf);

void Vvproc_qdisp_bell_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvproc_qdisp_bell_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vvproc_qdisp_bell_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vvproc_qdisp_bell_tb___024root___eval_static(&(vlSymsp->TOP));
        Vvproc_qdisp_bell_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vvproc_qdisp_bell_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vvproc_qdisp_bell_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vvproc_qdisp_bell_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vvproc_qdisp_bell_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vvproc_qdisp_bell_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vvproc_qdisp_bell_tb___024root___eval_final(Vvproc_qdisp_bell_tb___024root* vlSelf);

VL_ATTR_COLD void Vvproc_qdisp_bell_tb::final() {
    Vvproc_qdisp_bell_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vvproc_qdisp_bell_tb::hierName() const { return vlSymsp->name(); }
const char* Vvproc_qdisp_bell_tb::modelName() const { return "Vvproc_qdisp_bell_tb"; }
unsigned Vvproc_qdisp_bell_tb::threads() const { return 1; }
void Vvproc_qdisp_bell_tb::prepareClone() const { contextp()->prepareClone(); }
void Vvproc_qdisp_bell_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vvproc_qdisp_bell_tb::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vvproc_qdisp_bell_tb::trace()' called on model that was Verilated without --trace option");
}
