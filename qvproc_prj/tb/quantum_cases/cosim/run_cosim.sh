#!/usr/bin/env bash
# run_cosim.sh  –  Bell co-simulation: vproc_top + quantum_dispatcher
#
# Run from anywhere; the script resolves all paths from its own location.
# Requires Xilinx xvlog / xelab / xsim on PATH.
#
# Usage:
#   ./run_cosim.sh           # run with default Bell memory files
#   ./run_cosim.sh --gui     # open in Vivado waveform viewer

set -e
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
QC_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"              # quantum_cases/
PRJ_DIR="$(cd "${QC_DIR}/../.." && pwd)"              # qvproc_prj/
RTL_DIR="${PRJ_DIR}/rtl"
CFG_DIR="${PRJ_DIR}/configs"
IBEX_DIR="${PRJ_DIR}/core/ibex"
PRIM_DIR="${IBEX_DIR}/vendor/lowrisc_ip/ip/prim/rtl"
DV_DIR="${IBEX_DIR}/vendor/lowrisc_ip/dv/sv/dv_utils"

GUI=0
for arg in "$@"; do
    [[ "$arg" == "--gui" ]] && GUI=1
done

echo "=== HiSEP-Q Co-Sim: vproc + quantum_dispatcher ==="
echo "  Project : ${PRJ_DIR}"
echo "  Work dir: ${SCRIPT_DIR}"
echo ""

cd "${SCRIPT_DIR}"

# ---------------------------------------------------------------
# 1. Compile Verilog primitives (Ibex clock-gating stub)
# ---------------------------------------------------------------
echo "[1/4] Compiling Verilog primitives..."
xvlog --work xil_defaultlib \
    "${IBEX_DIR}/syn/rtl/prim_clock_gating.v" \
    2>&1 | tee xvlog_v1.log

# ---------------------------------------------------------------
# 2. Compile all SystemVerilog (Ibex + vproc + dispatcher top)
# ---------------------------------------------------------------
echo "[2/4] Compiling SystemVerilog..."
xvlog --sv --relax --work xil_defaultlib \
    -i "${PRIM_DIR}" \
    -i "${DV_DIR}" \
    "${IBEX_DIR}/rtl/ibex_pkg.sv" \
    "${IBEX_DIR}/rtl/ibex_alu.sv" \
    "${IBEX_DIR}/rtl/ibex_branch_predict.sv" \
    "${IBEX_DIR}/rtl/ibex_compressed_decoder.sv" \
    "${IBEX_DIR}/rtl/ibex_controller.sv" \
    "${IBEX_DIR}/rtl/ibex_core.sv" \
    "${IBEX_DIR}/rtl/ibex_counter.sv" \
    "${IBEX_DIR}/rtl/ibex_cs_registers.sv" \
    "${IBEX_DIR}/rtl/ibex_csr.sv" \
    "${IBEX_DIR}/rtl/ibex_decoder.sv" \
    "${IBEX_DIR}/rtl/ibex_dummy_instr.sv" \
    "${IBEX_DIR}/rtl/ibex_ex_block.sv" \
    "${IBEX_DIR}/rtl/ibex_fetch_fifo.sv" \
    "${IBEX_DIR}/rtl/ibex_icache.sv" \
    "${IBEX_DIR}/rtl/ibex_id_stage.sv" \
    "${IBEX_DIR}/rtl/ibex_if_stage.sv" \
    "${IBEX_DIR}/rtl/ibex_load_store_unit.sv" \
    "${IBEX_DIR}/rtl/ibex_lockstep.sv" \
    "${IBEX_DIR}/rtl/ibex_multdiv_fast.sv" \
    "${IBEX_DIR}/rtl/ibex_multdiv_slow.sv" \
    "${IBEX_DIR}/rtl/ibex_pmp.sv" \
    "${IBEX_DIR}/rtl/ibex_prefetch_buffer.sv" \
    "${IBEX_DIR}/rtl/ibex_register_file_ff.sv" \
    "${IBEX_DIR}/rtl/ibex_register_file_fpga.sv" \
    "${IBEX_DIR}/ibex_register_file_latch.sv" \
    "${IBEX_DIR}/vendor/lowrisc_ip/ip/prim/rtl/prim_ram_1p_pkg.sv" \
    "${IBEX_DIR}/rtl/ibex_top.sv" \
    "${IBEX_DIR}/rtl/ibex_wb_stage.sv" \
    "${IBEX_DIR}/prim_buf.sv" \
    "${IBEX_DIR}/prim_generic_buf.sv" \
    "${IBEX_DIR}/prim_generic_ram_1p.sv" \
    "${IBEX_DIR}/prim_ram_1p.sv" \
    "${RTL_DIR}/vproc_pkg.sv" \
    "${CFG_DIR}/vproc_config_dual_128_32.sv" \
    "${RTL_DIR}/vproc_alu.sv" \
    "${RTL_DIR}/vproc_cache.sv" \
    "${RTL_DIR}/vproc_core.sv" \
    "${RTL_DIR}/vproc_decoder.sv" \
    "${RTL_DIR}/vproc_dispatcher.sv" \
    "${RTL_DIR}/vproc_elem.sv" \
    "${RTL_DIR}/vproc_lsu.sv" \
    "${RTL_DIR}/vproc_mul.sv" \
    "${RTL_DIR}/vproc_mul_block.sv" \
    "${RTL_DIR}/vproc_pending_wr.sv" \
    "${RTL_DIR}/vproc_pipeline.sv" \
    "${RTL_DIR}/vproc_pipeline_wrapper.sv" \
    "${RTL_DIR}/vproc_queue.sv" \
    "${RTL_DIR}/vproc_result.sv" \
    "${RTL_DIR}/vproc_sld.sv" \
    "${RTL_DIR}/vproc_top.sv" \
    "${RTL_DIR}/vproc_unit_mux.sv" \
    "${RTL_DIR}/vproc_unit_wrapper.sv" \
    "${RTL_DIR}/vproc_vreg_wr_mux.sv" \
    "${RTL_DIR}/vproc_vregfile.sv" \
    "${RTL_DIR}/vproc_vregpack.sv" \
    "${RTL_DIR}/vproc_vregunpack.sv" \
    "${RTL_DIR}/vproc_xif.sv" \
    "${RTL_DIR}/vproc_qdisp_top.sv" \
    2>&1 | tee xvlog_sv.log

# ---------------------------------------------------------------
# 3. Compile Verilog: quantum_dispatcher + new top + TB
# ---------------------------------------------------------------
echo "[3/4] Compiling Verilog (dispatcher + wrapper + TB)..."
xvlog --work xil_defaultlib \
    "${RTL_DIR}/inst_fifo.v" \
    "${RTL_DIR}/time_controller.v" \
    "${RTL_DIR}/timed_fifo.v" \
    "${RTL_DIR}/quantum_dispatcher.v" \
    "${QC_DIR}/vproc_qdisp_bell_tb.v" \
    2>&1 | tee xvlog_v2.log

# ---------------------------------------------------------------
# 4. Elaborate
# ---------------------------------------------------------------
echo "[4/4a] Elaborating..."
xelab \
    --incr --debug typical --relax \
    -L xil_defaultlib \
    --snapshot vproc_qdisp_bell_tb_sim \
    xil_defaultlib.vproc_qdisp_bell_tb \
    2>&1 | tee xelab.log

# ---------------------------------------------------------------
# 5. Simulate
# ---------------------------------------------------------------
echo "[4/4b] Simulating..."
if [ $GUI -eq 1 ]; then
    xsim vproc_qdisp_bell_tb_sim --gui \
        --testplusarg "INSTR_MEM_FILE=${QC_DIR}/instruction_bell.mem" \
        --testplusarg "DATA_MEM_FILE=${QC_DIR}/data_bell.mem"
else
    xsim vproc_qdisp_bell_tb_sim --runall \
        --testplusarg "INSTR_MEM_FILE=${QC_DIR}/instruction_bell.mem" \
        --testplusarg "DATA_MEM_FILE=${QC_DIR}/data_bell.mem" \
        2>&1 | tee xsim.log
    echo ""
    echo "=== Simulation log (last 40 lines) ==="
    tail -40 xsim.log
fi
