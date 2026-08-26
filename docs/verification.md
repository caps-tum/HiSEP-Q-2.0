# HiSEP-Q Verification

This document is the authoritative source for verification scope, commands, results, and pass/fail meaning. A simulation log is evidence only when its checker validates the intended behavior.

## Verification levels

| Level | Meaning |
|---|---|
| Implemented | RTL path exists and compiles |
| Observed | A waveform or log shows activity |
| Self-checking verified | Expected values/timing are automatically compared |
| Synthesized | Complete intended top passes FPGA synthesis |
| Hardware validated | Behavior is demonstrated on the target board/backend |

Do not use these terms interchangeably. In particular, the current unified testbench's historical `PASS - no FIFO overflows` banner is not a complete functional pass.

## Simulation entry points

### Unified co-simulation

```bash
cd demo
./run.sh bell_generic
./run.sh bell_8pair
./run.sh --no-compile <case>
```

Requirements: Xilinx Vivado `xvlog`, `xelab`, and `xsim` on `PATH`. The driver compiles Ibex, vproc, the dispatcher, and `qvproc_prj/tb/quantum_cases/vproc_qdisp_bell_tb.v`.

Verilator provides the same unified testbench path:

```bash
cd demo/verilator
./run_verilator.sh <case>
```

### Legacy feature benches

```bash
cd qvproc_prj
QUANTUM_CASE=qsg  vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=qpr  vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=qrg  vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=qrv  vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=bell vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
```

These benches primarily observe exported streams. Their results must not be combined with unified dispatcher results without stating which interface was checked.

## Test program groups

Combined instruction/data images live in `demo/*.mem`:

| Prefix | Purpose |
|---|---|
| `bell_*` | Hand-written Bell/measurement flows |
| `qv_*` | Directed ISA and feedback stimuli |
| `mqtbench_*` | Compiled circuit workloads |

Source QASM/assembly for MQTBench cases is under `qvproc_prj/mqtbench_compiled/`. A `.mem` image by itself is stimulus, not an expected-result specification.

## Confirmed observations

On 2026-08-25, before the in-progress last-beat burst-dispatch change, Vivado 2024.2 successfully compiled and elaborated the unified design.

The small `bell_generic` run observed:

```text
quantum events : 16
qubit fires    : 20
FIFO errors    : 0
```

The log showed H, CNOT roles, MEASURE halt/drain, external completion, and a post-measure resume marker. This is useful end-to-end evidence for the small configuration, but the historical checker only failed on FIFO overflow.

Directed runs also observed raw streams for `qv_single`, `qv_pair`, `qv_rot_g`, and `qv_rot_v`. They did not establish functional PASS because:

- out-of-range indices could be silently discarded;
- expected values and times were not scored;
- `qv_rot_v` produced 56 raw events and zero qubit fires while still printing PASS;
- unexpected illegal-instruction messages were not included in pass/fail.

The long `qv_pair` stimulus reproduced the former scheduling defect: after the first-beat-relative deadline passed, qubits fired over consecutive `t_cnt` values rather than one common cycle.

These observations are a historical baseline; old cycle numbers are not normative.

### Current burst-dispatch regression

After the instruction-ID/idle-flush implementation, both Verilator and Vivado xsim regressions were run over the available `demo/*.mem` images, including VL=1 measurement boundaries and the VL=128/m8 `qv_pair` stimulus. The large instruction's selected in-range qubits fired together on one AWG line and existing event/fire/error counts matched the pre-change baseline except `mqtbench_graphstate_32_deg2_seed32`.

That graph-state case changed from 70 to 67 fires because repeated occurrences of the same qubit within one instruction are now collapsed by the touched-qubit bitmap. This is not classified as pass or fail until the ISA defines repeated-index semantics. FIFO-full burst behavior and the exact idle-flush margin still need directed tests.

## Required pass/fail contract

A positive test should check all relevant items:

- accepted raw element count and order;
- instruction class and instruction ID;
- qubit index and bounds;
- scalar or angle payload;
- GateID;
- control/target role;
- expected `t_cnt` and simultaneous valid mask;
- measurement assertion, stream completion, pause, result, and resume;
- absence of FIFO overflow, invalid-index error, deadline miss, and unexpected illegal instruction;
- completion before timeout.

A negative test passes only when its specified error/trap occurs. Timeout must never fall through to a PASS summary. The simulator process should return a non-zero status for a failed regression.

## Minimum trusted regression

| Case | Required checks |
|---|---|
| Small `QV.SINGLE` | exact index, GateID, payload, valid mask, common fire time |
| Small `QV.PAIR` | exact pair mapping, GateID, roles, common fire time |
| `QV.ROT.G` | exact index and 32-bit scalar angle |
| `QV.ROT.V` mf2/m1/m2 | exact index-angle pairing and legal LMUL behavior |
| `QV.ROT.V` m4/m8 | specified illegal trap/error, no silent watchdog pass |
| Bell measurement | H, pair, measure drain, result CSR, feedback, resume |
| Invalid target/source | explicit bounds error; no silent drop |
| Large VL | all selected outputs fire at one `t_cnt` |
| Counter wrap | no early or indefinitely delayed event |
| FIFO full | observable error and defined recovery/failure behavior |

## Current verification gaps

The minimum trusted regression above is not complete. The highest-priority gaps are:

- make zero-fire, timeout, invalid-index, FIFO-overflow, deadline-miss, and unexpected illegal-instruction outcomes fail the simulator process;
- add exact expected-event scoreboards for all four quantum instruction classes;
- define and test repeated-index and `QV.PAIR` role-conflict semantics;
- test burst commit with full per-qubit FIFOs and every legal intra-stream bubble;
- add counter-wrap and measurement-result CSR regressions;
- synthesize the AWG-facing `vproc_qdisp_top` rather than only the lower-level vproc top.

Local development checkouts may use the ignored `existing_problem.md` for owners and work-in-progress notes, but the tracked acceptance contract is this document.
