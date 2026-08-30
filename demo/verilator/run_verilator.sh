#!/usr/bin/env bash
# Build and run the opcode simulator with Verilator.
#
# Same testbench as demo/run.sh, but compiled to a plain binary so we don't
# need Vivado. Feed it a .mem and it prints the opcode log (issue #4).
#
# Usage:
#   ./run_verilator.sh [case]        build (if needed) and run demo/<case>.mem
#   ./run_verilator.sh --build-only  build only
#   ./run_verilator.sh --no-build c  skip build, run case c
#   ./run_verilator.sh --mem file    run a specific .mem path
#
# Needs verilator >= 5 (for --binary --timing) and g++.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DEMO_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
PRJ_DIR="$(cd "${DEMO_DIR}/../qvproc_prj" && pwd)"
QC_DIR="${PRJ_DIR}/tb/quantum_cases"
RTL_DIR="${PRJ_DIR}/rtl"
CFG_DIR="${PRJ_DIR}/configs"
IBEX_DIR="${PRJ_DIR}/core/ibex"
PRIM_DIR="${IBEX_DIR}/vendor/lowrisc_ip/ip/prim/rtl"
DV_DIR="${IBEX_DIR}/vendor/lowrisc_ip/dv/sv/dv_utils"

OBJ_DIR="${SCRIPT_DIR}/obj_dir"
BIN="${OBJ_DIR}/sim_hisepq"
TOP="vproc_qdisp_bell_tb"

BUILD=1
RUN=1
CASE_NAME="bell_generic"
MEM_FILE=""
MEASURE_RESULT=""
MEASURE_FILE=""
MEASURE_DELAY=""
AWG_OUTPUT=""
MAX_CYCLES_ARG=""

while [[ $# -gt 0 ]]; do
    case "$1" in
        --build-only) RUN=0 ;;
        --no-build)   BUILD=0 ;;
        --mem)            MEM_FILE="$2"; shift ;;
        --measure-result) MEASURE_RESULT="$2"; shift ;;
        --measure-file)   MEASURE_FILE="$2"; shift ;;
        --measure-delay)  MEASURE_DELAY="$2"; shift ;;
        --output)         AWG_OUTPUT="$2"; shift ;;
        --max-cycles)     MAX_CYCLES_ARG="$2"; shift ;;
        --*)          echo "Unknown option: $1" >&2; exit 1 ;;
        *)            CASE_NAME="$1" ;;
    esac
    shift
done

# Same file list as demo/run.sh. The latch register file is left out: Verilator
# can't simulate latches, and Ibex uses the FF regfile here anyway.
SOURCES=(
    # clock gating cell
    "${IBEX_DIR}/syn/rtl/prim_clock_gating.v"

    # Ibex + prim (SystemVerilog)
    "${IBEX_DIR}/rtl/ibex_pkg.sv"
    "${IBEX_DIR}/rtl/ibex_alu.sv"
    "${IBEX_DIR}/rtl/ibex_branch_predict.sv"
    "${IBEX_DIR}/rtl/ibex_compressed_decoder.sv"
    "${IBEX_DIR}/rtl/ibex_controller.sv"
    "${IBEX_DIR}/rtl/ibex_core.sv"
    "${IBEX_DIR}/rtl/ibex_counter.sv"
    "${IBEX_DIR}/rtl/ibex_cs_registers.sv"
    "${IBEX_DIR}/rtl/ibex_csr.sv"
    "${IBEX_DIR}/rtl/ibex_decoder.sv"
    "${IBEX_DIR}/rtl/ibex_dummy_instr.sv"
    "${IBEX_DIR}/rtl/ibex_ex_block.sv"
    "${IBEX_DIR}/rtl/ibex_fetch_fifo.sv"
    "${IBEX_DIR}/rtl/ibex_icache.sv"
    "${IBEX_DIR}/rtl/ibex_id_stage.sv"
    "${IBEX_DIR}/rtl/ibex_if_stage.sv"
    "${IBEX_DIR}/rtl/ibex_load_store_unit.sv"
    "${IBEX_DIR}/rtl/ibex_lockstep.sv"
    "${IBEX_DIR}/rtl/ibex_multdiv_fast.sv"
    "${IBEX_DIR}/rtl/ibex_multdiv_slow.sv"
    "${IBEX_DIR}/rtl/ibex_pmp.sv"
    "${IBEX_DIR}/rtl/ibex_prefetch_buffer.sv"
    "${IBEX_DIR}/rtl/ibex_register_file_ff.sv"
    "${IBEX_DIR}/vendor/lowrisc_ip/ip/prim/rtl/prim_ram_1p_pkg.sv"
    "${IBEX_DIR}/rtl/ibex_top.sv"
    "${IBEX_DIR}/rtl/ibex_wb_stage.sv"
    "${IBEX_DIR}/prim_buf.sv"
    "${IBEX_DIR}/prim_generic_buf.sv"
    "${IBEX_DIR}/prim_generic_ram_1p.sv"
    "${IBEX_DIR}/prim_ram_1p.sv"

    # vproc (SystemVerilog)
    "${RTL_DIR}/vproc_pkg.sv"
    "${CFG_DIR}/vproc_config_dual_128_32.sv"
    "${RTL_DIR}/vproc_alu.sv"
    "${RTL_DIR}/vproc_cache.sv"
    "${RTL_DIR}/vproc_core.sv"
    "${RTL_DIR}/vproc_decoder.sv"
    "${RTL_DIR}/vproc_dispatcher.sv"
    "${RTL_DIR}/vproc_elem.sv"
    "${RTL_DIR}/vproc_lsu.sv"
    "${RTL_DIR}/vproc_mul.sv"
    "${RTL_DIR}/vproc_mul_block.sv"
    "${RTL_DIR}/vproc_pending_wr.sv"
    "${RTL_DIR}/vproc_pipeline.sv"
    "${RTL_DIR}/vproc_pipeline_wrapper.sv"
    "${RTL_DIR}/vproc_queue.sv"
    "${RTL_DIR}/vproc_result.sv"
    "${RTL_DIR}/vproc_sld.sv"
    "${RTL_DIR}/vproc_top.sv"
    "${RTL_DIR}/vproc_unit_mux.sv"
    "${RTL_DIR}/vproc_unit_wrapper.sv"
    "${RTL_DIR}/vproc_vreg_wr_mux.sv"
    "${RTL_DIR}/vproc_vregfile.sv"
    "${RTL_DIR}/vproc_vregpack.sv"
    "${RTL_DIR}/vproc_vregunpack.sv"
    "${RTL_DIR}/vproc_xif.sv"
    "${RTL_DIR}/vproc_qdisp_top.sv"

    # dispatcher + testbench (Verilog)
    "${RTL_DIR}/inst_fifo.v"
    "${RTL_DIR}/time_controller.v"
    "${RTL_DIR}/timed_fifo.v"
    "${RTL_DIR}/quantum_dispatcher.v"
    "${QC_DIR}/${TOP}.v"
)

# ---------------------------------------------------------------------------
# Build
# ---------------------------------------------------------------------------
if [[ $BUILD -eq 1 ]]; then
    command -v verilator >/dev/null || { echo "ERROR: verilator not on PATH (need >=5.x)"; exit 1; }
    echo "=== [verilator] building ${TOP} -> ${BIN} ==="
    verilator --version
    cd "${SCRIPT_DIR}"
    verilator \
        --binary --timing -j 1 \
        --top-module "${TOP}" \
        -o "$(basename "${BIN}")" \
        -Mdir "${OBJ_DIR}" \
        -Wno-fatal \
        --timescale 1ns/1ps \
        --x-initial unique --x-assign unique \
        -CFLAGS "-O2" \
        -I"${PRIM_DIR}" -I"${DV_DIR}" \
        "${SCRIPT_DIR}/hisepq.vlt" \
        "${SOURCES[@]}"
    echo "=== [verilator] build OK: ${BIN} ==="
fi

# ---------------------------------------------------------------------------
# Run
# ---------------------------------------------------------------------------
if [[ $RUN -eq 1 ]]; then
    if [[ -n "$MEASURE_RESULT" && -n "$MEASURE_FILE" ]]; then
        echo "ERROR: use either --measure-result or --measure-file, not both" >&2
        exit 1
    fi
    [[ -z "$MEASURE_DELAY" || "$MEASURE_DELAY" =~ ^[0-9]+$ ]] || {
        echo "ERROR: --measure-delay must be a non-negative integer" >&2
        exit 1
    }
    [[ -z "$MAX_CYCLES_ARG" || "$MAX_CYCLES_ARG" =~ ^[1-9][0-9]*$ ]] || {
        echo "ERROR: --max-cycles must be a positive integer" >&2
        exit 1
    }
    if [[ -z "${MEM_FILE}" ]]; then
        # Accept a bare case name, a name with .mem, or a path (with/without .mem).
        cand="${CASE_NAME%.mem}"                       # drop trailing .mem if given
        if   [[ -f "${cand}.mem" ]];                       then MEM_FILE="${cand}.mem"
        elif [[ -f "${DEMO_DIR}/$(basename "${cand}").mem" ]]; then MEM_FILE="${DEMO_DIR}/$(basename "${cand}").mem"
        else MEM_FILE="${DEMO_DIR}/${cand}.mem"; fi
    fi
    [[ -f "${MEM_FILE}" ]] || { echo "ERROR: mem file not found: ${MEM_FILE}"; exit 1; }
    [[ -x "${BIN}" ]]      || { echo "ERROR: binary not built: ${BIN} (run without --no-build)"; exit 1; }
    SIM_ARGS=("+MEM_FILE=${MEM_FILE}")
    if [[ "${MEM_FILE##*/}" == "qv_rot_gateid.mem" ]]; then
        SIM_ARGS+=("+EXPECT_ROT_GATEID")
    fi
    # Per-case exact AWG scoreboard: demo/<case>.expect, one expected fire per
    # line (<qubit> <gate_hex> <C|T> <pv> <payload_hex>).
    EXPECT_FILE="${MEM_FILE%.mem}.expect"
    [[ -f "$EXPECT_FILE" ]] && SIM_ARGS+=("+AWG_EXPECT=${EXPECT_FILE}")
    # Negative tests: PASS when the coprocessor rejects the instruction.
    case "${MEM_FILE##*/}" in
        qv_rot_v_illegal_m4.mem|qv_rot_v_illegal_m8.mem) SIM_ARGS+=("+EXPECT_TRAP") ;;
    esac
    if [[ -n "$MEASURE_RESULT" ]]; then
        MEASURE_RESULT="${MEASURE_RESULT#0x}"
        MEASURE_RESULT="${MEASURE_RESULT#0X}"
        [[ "$MEASURE_RESULT" =~ ^[0-9a-fA-F]{1,8}$ ]] || {
            echo "ERROR: --measure-result must fit in 32 bits" >&2
            exit 1
        }
        SIM_ARGS+=("+MEASURE_RESULT=${MEASURE_RESULT}")
    fi
    if [[ -n "$MEASURE_FILE" ]]; then
        [[ -f "$MEASURE_FILE" ]] || {
            echo "ERROR: measurement file not found: ${MEASURE_FILE}" >&2
            exit 1
        }
        MEASURE_FILE="$(cd "$(dirname "$MEASURE_FILE")" && pwd)/$(basename "$MEASURE_FILE")"
        SIM_ARGS+=("+MEASURE_FILE=${MEASURE_FILE}")
    fi
    [[ -z "$MEASURE_DELAY" ]] || SIM_ARGS+=("+MEASURE_DELAY=${MEASURE_DELAY}")
    [[ -z "$MAX_CYCLES_ARG" ]] || SIM_ARGS+=("+MAX_CYCLES=${MAX_CYCLES_ARG}")
    if [[ -n "$AWG_OUTPUT" ]]; then
        mkdir -p "$(dirname "$AWG_OUTPUT")"
        AWG_OUTPUT="$(cd "$(dirname "$AWG_OUTPUT")" && pwd)/$(basename "$AWG_OUTPUT")"
        SIM_ARGS+=("+AWG_OUTPUT=${AWG_OUTPUT}")
    fi

    echo "=== [sim] ${BIN} ${SIM_ARGS[*]} ==="
    "${BIN}" "${SIM_ARGS[@]}"
fi
