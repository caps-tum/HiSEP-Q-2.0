#!/usr/bin/env bash
# run.sh  –  Unified HiSEP-Q co-simulation driver
#
# All test programs live as <name>.mem alongside this script in demo/.
# Drop a new combined .mem (or use --elf) into demo/ and run ./run.sh <name>.
#
# Usage:
#   ./run.sh [OPTIONS] [CASE]
#
#   CASE        Basename of a .mem file in demo/ (without extension).
#               Default: bell_generic
#
# Options:
#   --gui          Open in Vivado waveform viewer.
#   --elf FILE     Load from ELF instead of a demo/ .mem file.
#                  (converts via elf2mem.sh, then simulates)
#   --no-compile   Skip xvlog/xelab; reuse the existing snapshot.
#                  Speeds up re-runs when only the .mem file changed.
#
# Examples:
#   ./run.sh                              # Bell generic demo (default)
#   ./run.sh bell_8pair --gui             # 8-pair Bell state in GUI
#   ./run.sh mqtbench_ghz_16             # MQTBench GHZ 16-qubit
#   ./run.sh --elf build/program.elf     # load from ELF

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PRJ_DIR="$(cd "${SCRIPT_DIR}/../qvproc_prj" && pwd)"
QC_DIR="${PRJ_DIR}/tb/quantum_cases"
RTL_DIR="${PRJ_DIR}/rtl"
CFG_DIR="${PRJ_DIR}/configs"
IBEX_DIR="${PRJ_DIR}/core/ibex"
PRIM_DIR="${IBEX_DIR}/vendor/lowrisc_ip/ip/prim/rtl"
DV_DIR="${IBEX_DIR}/vendor/lowrisc_ip/dv/sv/dv_utils"

GUI=0
NO_COMPILE=0
ELF_FILE=""
CASE_NAME="bell_generic"

# ── argument parsing ────────────────────────────────────────────────────────
while [[ $# -gt 0 ]]; do
    case "$1" in
        --gui)        GUI=1 ;;
        --no-compile) NO_COMPILE=1 ;;
        --elf)
            ELF_FILE="$2"; shift
            ;;
        --*)
            echo "Unknown option: $1" >&2; exit 1 ;;
        *)
            CASE_NAME="$1" ;;
    esac
    shift
done

echo "=== HiSEP-Q Co-Sim ==="
echo "  Project : ${PRJ_DIR}"
echo "  Work dir: ${SCRIPT_DIR}"
echo ""

cd "${SCRIPT_DIR}"

# ── compile + elaborate ─────────────────────────────────────────────────────
compile_and_elab() {
    echo "[1/3] Compiling Verilog primitives..."
    xvlog --work xil_defaultlib \
        "${IBEX_DIR}/syn/rtl/prim_clock_gating.v" \
        2>&1 | tee xvlog_v1.log

    echo "[2/3] Compiling SystemVerilog..."
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

    echo "[3/3] Compiling Verilog (dispatcher + TB)..."
    xvlog --work xil_defaultlib \
        "${RTL_DIR}/inst_fifo.v" \
        "${RTL_DIR}/time_controller.v" \
        "${RTL_DIR}/timed_fifo.v" \
        "${RTL_DIR}/quantum_dispatcher.v" \
        "${QC_DIR}/vproc_qdisp_bell_tb.v" \
        2>&1 | tee xvlog_v2.log

    echo "[elab] Elaborating..."
    xelab \
        --incr --debug typical --relax \
        -L xil_defaultlib \
        --snapshot vproc_qdisp_bell_tb_sim \
        xil_defaultlib.vproc_qdisp_bell_tb \
        2>&1 | tee xelab.log
}

# ── single simulation run ───────────────────────────────────────────────────
run_one() {
    local mem_file="$1"
    local log_file="${2:-xsim.log}"
    local gui="${3:-0}"
    local -a testplusargs=(--testplusarg "MEM_FILE=${mem_file}")

    if [[ "${mem_file##*/}" == "qv_rot_gateid.mem" ]]; then
        testplusargs+=(--testplusarg "EXPECT_ROT_GATEID")
    fi
    # Per-case exact AWG scoreboard: demo/<case>.expect, one expected fire per
    # line (<qubit> <gate_hex> <C|T> <pv> <payload_hex>).
    local expect_file="${mem_file%.mem}.expect"
    [[ -f "$expect_file" ]] && testplusargs+=(--testplusarg "AWG_EXPECT=${expect_file}")
    # Negative tests: PASS when the coprocessor rejects the instruction.
    case "${mem_file##*/}" in
        qv_rot_v_illegal_m4.mem|qv_rot_v_illegal_m8.mem) testplusargs+=(--testplusarg "EXPECT_TRAP") ;;
    esac

    if [[ $gui -eq 1 ]]; then
        xsim vproc_qdisp_bell_tb_sim --gui \
            "${testplusargs[@]}"
    else
        xsim vproc_qdisp_bell_tb_sim --runall \
            "${testplusargs[@]}" \
            2>&1 | tee "${log_file}"
    fi
}

# Resolve the .mem file to use
if [[ -n "$ELF_FILE" ]]; then
    [[ ! -f "$ELF_FILE" ]] && { echo "ELF not found: $ELF_FILE" >&2; exit 1; }
    MEM_FILE="${SCRIPT_DIR}/elf_combined.mem"
    echo "[ELF] Converting ${ELF_FILE} -> ${MEM_FILE}"
    bash "${SCRIPT_DIR}/elf2mem.sh" "$ELF_FILE" "$MEM_FILE"
elif [[ -f "${SCRIPT_DIR}/${CASE_NAME}.mem" ]]; then
    MEM_FILE="${SCRIPT_DIR}/${CASE_NAME}.mem"
else
    echo "Case not found: ${SCRIPT_DIR}/${CASE_NAME}.mem" >&2
    echo "Available cases:"
    ( cd "${SCRIPT_DIR}" && ls *.mem 2>/dev/null | sed 's/\.mem$//' | sed 's/^/  /' )
    exit 1
fi

echo "  Case: ${CASE_NAME}  (${MEM_FILE})"
echo ""

[[ $NO_COMPILE -eq 0 ]] && compile_and_elab

echo "[sim] Simulating..."
if [[ $GUI -eq 1 ]]; then
    run_one "$MEM_FILE" "" 1
else
    run_one "$MEM_FILE" "xsim.log" 0
    echo ""
    echo "=== Simulation log (last 40 lines) ==="
    tail -40 xsim.log
    # xsim exits 0 even after $fatal; derive the exit code from the TB verdict
    # so this script can gate CI.
    if ! grep -q "RESULT         : PASS" xsim.log; then
        echo "[sim] testbench reported FAIL -> exiting non-zero"
        exit 1
    fi
fi
