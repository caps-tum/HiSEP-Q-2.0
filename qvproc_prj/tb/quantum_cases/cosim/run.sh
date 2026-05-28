#!/usr/bin/env bash
# run.sh  –  Unified HiSEP-Q co-simulation driver
#
# Combines the previous run_cosim.sh (single-case) and run_mqtbench.sh (batch).
# All test cases live in cases/<name>.mem (instruction + data merged into one file).
#
# Usage:
#   ./run.sh [OPTIONS] [CASE]
#
#   CASE        Name of a .mem file in cases/ (without extension).
#               Default: bell_generic
#
# Options:
#   --gui          Open in Vivado waveform viewer (single-case only).
#   --elf FILE     Load from ELF instead of a cases/ file.
#                  (converts via elf2mem.sh, then simulates)
#   --batch [GLOB] Run all cases (or those matching GLOB) sequentially
#                  and write a summary CSV.
#   --no-compile   Skip xvlog/xelab; reuse the existing snapshot.
#                  Speeds up re-runs when only the .mem file changed.
#
# Examples:
#   ./run.sh                              # Bell generic demo (default)
#   ./run.sh bell_8pair --gui             # 8-pair Bell state in GUI
#   ./run.sh mqtbench_ghz_16             # MQTBench GHZ 16-qubit
#   ./run.sh --batch                     # all cases, CSV summary
#   ./run.sh --batch mqtbench_*          # batch: MQTBench cases only
#   ./run.sh --elf build/program.elf     # load from ELF

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
QC_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
PRJ_DIR="$(cd "${QC_DIR}/../.." && pwd)"
RTL_DIR="${PRJ_DIR}/rtl"
CFG_DIR="${PRJ_DIR}/configs"
IBEX_DIR="${PRJ_DIR}/core/ibex"
PRIM_DIR="${IBEX_DIR}/vendor/lowrisc_ip/ip/prim/rtl"
DV_DIR="${IBEX_DIR}/vendor/lowrisc_ip/dv/sv/dv_utils"
CASES_DIR="${SCRIPT_DIR}/cases"

GUI=0
BATCH=0
BATCH_GLOB="*"
NO_COMPILE=0
ELF_FILE=""
CASE_NAME="bell_generic"

# ── argument parsing ────────────────────────────────────────────────────────
while [[ $# -gt 0 ]]; do
    case "$1" in
        --gui)        GUI=1 ;;
        --no-compile) NO_COMPILE=1 ;;
        --batch)
            BATCH=1
            if [[ $# -gt 1 && "${2}" != --* ]]; then
                BATCH_GLOB="$2"; shift
            fi
            ;;
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

# ── compile + elaborate (shared for single and batch modes) ─────────────────
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

    if [[ $gui -eq 1 ]]; then
        xsim vproc_qdisp_bell_tb_sim --gui \
            --testplusarg "MEM_FILE=${mem_file}"
    else
        xsim vproc_qdisp_bell_tb_sim --runall \
            --testplusarg "MEM_FILE=${mem_file}" \
            2>&1 | tee "${log_file}"
    fi
}

# ── extract metric from a log file ─────────────────────────────────────────
extract_csv_row() {
    local name="$1"
    local log="$2"
    local rc="$3"

    local first_instr first_meas qvsg_clear last_evt nq_evt nq_fires result asserted cleared

    first_instr=$(grep -m1 "INSTR\] "      "$log" | grep -oP "cycle=\K[0-9]+" | head -1)
    first_meas=$(grep -m1  "qvsg_meas=1"   "$log" | grep -oP "cycle=\K[0-9]+" | head -1)
    qvsg_clear=$(grep -m1  "qvsg_meas=0"   "$log" | grep -oP "cycle=\K[0-9]+" | head -1)
    last_evt=$(grep         "QX\] idx="    "$log" | tail -1 | grep -oP "cycle=\K[0-9]+")
    nq_evt=$(grep  -E "quantum events\s*:" "$log" | tail -1 | grep -oP "[0-9]+")
    nq_fires=$(grep -E "qubit fires\s*:"  "$log" | tail -1 | grep -oP "[0-9]+")
    result=$(grep  -E "RESULT\s*:"        "$log" | tail -1 | sed 's/.*RESULT *: *//' | head -c 40)

    asserted=$([ -n "${first_meas:-}" ] && echo "yes" || echo "no")
    cleared=$([ -n "${qvsg_clear:-}" ] && echo "yes" || echo "no")

    echo "${name},${rc},${first_instr:-NA},${first_meas:-NA},${last_evt:-NA},${nq_evt:-NA},${nq_fires:-NA},${asserted},${cleared},${result:-NA}"
}

# ═══════════════════════════════════════════════════════════════════════════
# BATCH MODE
# ═══════════════════════════════════════════════════════════════════════════
if [[ $BATCH -eq 1 ]]; then
    [[ $NO_COMPILE -eq 0 ]] && compile_and_elab

    LOGDIR="${SCRIPT_DIR}/logs"
    mkdir -p "$LOGDIR"
    CSV="${LOGDIR}/summary.csv"

    echo "name,exit_code,first_instr_cycle,first_meas_cycle,last_event_cycle,total_quantum_events,total_qubit_fires,qvsg_meas_asserted,qvsg_meas_cleared,result" \
        > "$CSV"

    shopt -s nullglob
    cases=( "${CASES_DIR}"/${BATCH_GLOB}.mem )
    if [[ ${#cases[@]} -eq 0 ]]; then
        echo "No cases matching '${BATCH_GLOB}' in ${CASES_DIR}" >&2
        exit 1
    fi

    for mem in "${cases[@]}"; do
        name=$(basename "$mem" .mem)
        log="${LOGDIR}/${name}.log"
        echo "==== ${name} ===="
        timeout 120 xsim vproc_qdisp_bell_tb_sim --runall \
            --testplusarg "MEM_FILE=${mem}" \
            > "$log" 2>&1
        rc=$?
        extract_csv_row "$name" "$log" "$rc" >> "$CSV"
    done

    echo ""
    echo "=== Batch summary ==="
    column -t -s, "$CSV"
    echo ""
    echo "Full logs: ${LOGDIR}/"
    echo "CSV:       ${CSV}"
    exit 0
fi

# ═══════════════════════════════════════════════════════════════════════════
# SINGLE-CASE MODE
# ═══════════════════════════════════════════════════════════════════════════

# Resolve the .mem file to use
if [[ -n "$ELF_FILE" ]]; then
    [[ ! -f "$ELF_FILE" ]] && { echo "ELF not found: $ELF_FILE" >&2; exit 1; }
    MEM_FILE="${SCRIPT_DIR}/elf_combined.mem"
    echo "[ELF] Converting ${ELF_FILE} -> ${MEM_FILE}"
    bash "${SCRIPT_DIR}/elf2mem.sh" "$ELF_FILE" "$MEM_FILE"
elif [[ -f "${CASES_DIR}/${CASE_NAME}.mem" ]]; then
    MEM_FILE="${CASES_DIR}/${CASE_NAME}.mem"
else
    echo "Case not found: ${CASES_DIR}/${CASE_NAME}.mem" >&2
    echo "Available cases:"
    ls "${CASES_DIR}/" | sed 's/\.mem$//' | sed 's/^/  /'
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
fi
