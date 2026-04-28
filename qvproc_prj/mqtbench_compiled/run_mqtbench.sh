#!/usr/bin/env bash
# Run all MQTBench cases through vproc_qdisp_bell_tb cosim, capture timing.
set -u

ROOT=/home/xiaorang/Documents/HiSEP-Q-2.0/qvproc_prj
COSIM_DIR=$ROOT/tb/quantum_cases/cosim
PATCHED=$ROOT/mqtbench_notebook_outputs_texthex/_patched
LOGDIR=$ROOT/mqtbench_notebook_outputs_texthex/_logs
mkdir -p "$LOGDIR"

NAMES=(
  mqtbench_ghz_8
  mqtbench_ghz_16
  mqtbench_graphstate_8_deg2_seed10
  mqtbench_graphstate_16_deg2_seed16
  mqtbench_qaoa_8_r2_seed10
  mqtbench_qaoa_16_r2_seed10
)

cd "$COSIM_DIR"
echo "name,exit_code,first_instr_cycle,first_meas_cycle,last_event_cycle,total_quantum_events,total_qubit_fires,qvsg_meas_asserted,qvsg_meas_cleared,result" \
    > "$LOGDIR/summary.csv"

for n in "${NAMES[@]}"; do
    LOG="$LOGDIR/${n}.log"
    echo "==== running $n ===="
    timeout 90 xsim vproc_qdisp_bell_tb_sim --runall \
        --testplusarg "INSTR_MEM_FILE=mqt/${n}.text.hex" \
        --testplusarg "DATA_MEM_FILE=mqt/${n}.data.hex" \
        > "$LOG" 2>&1
    rc=$?

    # Extract metrics
    first_instr=$(grep -m1 "INSTR\] " "$LOG"      | grep -oP "cycle=\K[0-9]+" | head -1)
    first_meas=$(grep -m1 "qvsg_meas=1"  "$LOG"   | grep -oP "cycle=\K[0-9]+" | head -1)
    qvsg_clear=$(grep -m1 "qvsg_meas=0"  "$LOG"   | grep -oP "cycle=\K[0-9]+" | head -1)
    last_evt=$(grep "QX\] idx=" "$LOG"            | tail -1 | grep -oP "cycle=\K[0-9]+")
    nq_evt=$(grep -E "quantum events\s*:" "$LOG"  | tail -1 | grep -oP "[0-9]+")
    nq_fires=$(grep -E "qubit fires\s*:" "$LOG"   | tail -1 | grep -oP "[0-9]+")
    result=$(grep -E "RESULT\s*:" "$LOG" | tail -1 | sed 's/.*RESULT *: *//' | head -c 40)

    asserted=$([ -n "$first_meas" ] && echo "yes" || echo "no")
    cleared=$([ -n "$qvsg_clear" ] && echo "yes" || echo "no")

    echo "$n,$rc,${first_instr:-NA},${first_meas:-NA},${last_evt:-NA},${nq_evt:-NA},${nq_fires:-NA},$asserted,$cleared,${result:-NA}" \
        >> "$LOGDIR/summary.csv"
done

echo
echo "=== Summary CSV ==="
column -t -s, "$LOGDIR/summary.csv"
