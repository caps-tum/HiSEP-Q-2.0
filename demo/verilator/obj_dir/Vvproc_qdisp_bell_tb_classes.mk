# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vvproc_qdisp_bell_tb.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 0
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vvproc_qdisp_bell_tb \
	Vvproc_qdisp_bell_tb___024root__DepSet_hceaccb7b__0 \
	Vvproc_qdisp_bell_tb___024root__DepSet_hceaccb7b__1 \
	Vvproc_qdisp_bell_tb___024root__DepSet_hceaccb7b__2 \
	Vvproc_qdisp_bell_tb___024root__DepSet_hceaccb7b__3 \
	Vvproc_qdisp_bell_tb___024root__DepSet_hafab6cdf__0 \
	Vvproc_qdisp_bell_tb___024root__DepSet_hafab6cdf__1 \
	Vvproc_qdisp_bell_tb___024root__DepSet_hafab6cdf__2 \
	Vvproc_qdisp_bell_tb_timed_fifo__O8__DepSet_h711a3ff9__0 \
	Vvproc_qdisp_bell_tb_vproc_xif__XC20_XF0__DepSet_h0a3aa231__0 \
	Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20__DepSet_ha5ba19a0__0 \
	Vvproc_qdisp_bell_tb__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vvproc_qdisp_bell_tb__ConstPool_0 \
	Vvproc_qdisp_bell_tb___024root__Slow \
	Vvproc_qdisp_bell_tb___024root__DepSet_hceaccb7b__0__Slow \
	Vvproc_qdisp_bell_tb___024root__DepSet_hceaccb7b__1__Slow \
	Vvproc_qdisp_bell_tb___024root__DepSet_hceaccb7b__2__Slow \
	Vvproc_qdisp_bell_tb___024root__DepSet_hceaccb7b__3__Slow \
	Vvproc_qdisp_bell_tb___024root__DepSet_hafab6cdf__0__Slow \
	Vvproc_qdisp_bell_tb___024root__DepSet_hafab6cdf__1__Slow \
	Vvproc_qdisp_bell_tb_timed_fifo__O8__Slow \
	Vvproc_qdisp_bell_tb_timed_fifo__O8__DepSet_h711a3ff9__0__Slow \
	Vvproc_qdisp_bell_tb_timed_fifo__O8__DepSet_h3460b861__0__Slow \
	Vvproc_qdisp_bell_tb_vproc_xif__XC20_XF0__Slow \
	Vvproc_qdisp_bell_tb_vproc_xif__XC20_XF0__DepSet_h0a3aa231__0__Slow \
	Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20__Slow \
	Vvproc_qdisp_bell_tb_vproc_xif__XB3_XC20__DepSet_ha5ba19a0__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vvproc_qdisp_bell_tb__Dpi \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vvproc_qdisp_bell_tb__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_dpi \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
