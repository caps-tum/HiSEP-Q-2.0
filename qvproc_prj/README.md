# qvproc Vivado Project

This directory contains the Ibex/vproc RTL snapshot, HiSEP-Q integration RTL, testbenches, configurations, and the Tcl project-rebuild flow.

Architecture and ISA descriptions are intentionally not duplicated here:

- hardware/timing: [`../docs/architecture.md`](../docs/architecture.md);
- ISA: [`../docs/HiSEPQ_ISA_spec.md`](../docs/HiSEPQ_ISA_spec.md);
- verification: [`../docs/verification.md`](../docs/verification.md);

## Layout

| Path | Purpose |
|---|---|
| `configs/` | vproc configurations |
| `core/ibex/` | vendored Ibex sources |
| `rtl/` | vproc plus HiSEP-Q integration/dispatcher RTL |
| `docs/qsg_measure_spec.md` | detailed measurement control contract |
| `tb/quantum_cases/` | unified and legacy quantum benches/images |
| `mqtbench_compiled/` | workload QASM and assembly |
| `rebuild_project.tcl` | Vivado project recreation |

## Rebuild the current project

From the repository root:

```bash
vivado -mode batch -source qvproc_prj/rebuild_project.tcl
```

or:

```bash
cd qvproc_prj
vivado -mode batch -source rebuild_project.tcl
```

The script currently creates `build/qvproc/qvproc.xpr` for part
`xcu55c-fsvh2892-2L-e` and board part `xilinx.com:au55c:part0:1.0`. These are
legacy script settings, not the intended deployment target.

## Build status

As of 2026-08-26, the rebuild script selects `vproc_qdisp_top` as the synthesis
top and includes `vproc_qdisp_top.sv`, `quantum_dispatcher.v`, `timed_fifo.v`,
`time_controller.v`, and `inst_fifo.v` in the `sources_1` fileset, along with
`constr/timing.xdc` in `constrs_1`. Verified against a real Vivado 2024.2
install: the script recreates the project cleanly, RTL elaboration reports
top = `vproc_qdisp_top` with 0 errors, and a full `synth_design` run completes
with 0 errors (32 pre-existing critical warnings in `vproc_pipeline.sv`,
unrelated to the dispatcher).

The intended future board is ZCU216. Retargeting the Tcl part/board settings,
selecting the board-facing interfaces, and adding pin/timing constraints are
not implemented. `vproc_qdisp_top` ports `mem_*`, `measure_*`, and `qubit_*`
currently have no board-level LOC constraints. The present project rebuild is
a synthesis check, not a board-programmable ZCU216 flow.

## Unified co-simulation

The maintained convenience entry point is at repository-level `demo/`:

```bash
cd ../demo
./run.sh bell_generic
./run.sh bell_8pair
```

It compiles the wrapper and dispatcher explicitly and uses `vproc_qdisp_bell_tb.v`.

## Legacy batch benches

The project still contains older per-feature Vivado benches selected through `tb/quantum_cases/run_quantum_case_batch.tcl`. Their commands, scope, and evidence limitations are maintained in [`../docs/verification.md`](../docs/verification.md) rather than duplicated here.

## Configuration notes

The default checked-in vproc configuration uses a 128-bit vector register width. `QV.ROT.V` uses mixed-width operands: e8 indices and e32 angles. The canonical legal LMUL table and compiler rules are maintained only in [`../docs/HiSEPQ_ISA_spec.md`](../docs/HiSEPQ_ISA_spec.md).

Measurement pause/resume details are in [`docs/qsg_measure_spec.md`](docs/qsg_measure_spec.md).
