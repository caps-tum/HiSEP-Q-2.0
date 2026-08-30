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

### Measurement input and AWG output

Supply one measurement result directly:

```bash
./run_verilator.sh qv_feedback --measure-result 1 --measure-delay 7 \
  --output feedback.csv
```

For more than one measurement transaction, use a stimulus file:

```text
00000001 7
a5a5a5a5 20
```

Each row is `result_word delay_cycles`. One row is consumed when a measurement request completes. Malformed or exhausted input fails immediately and does not schedule a measurement response. The result word is 32 bits: bit k maps to element k of that measurement vector, not permanently to physical qubit k. See [Measurement Result Semantics](../qvproc_prj/docs/qsg_measure_spec.md) for the full contract.

```bash
./run_verilator.sh <case> --measure-file results.stim --output awg.csv
```

The CSV columns are:

```text
event_id,cycle,t_cnt,valid_mask,qubit,gate_id,role
```

One firing qubit occupies one row. Rows with the same `event_id` fired together. Use `--max-cycles N` to override the testbench timeout.

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

> **Generated assembly warning:** the checked-in `mqtbench_compiled/*.s` files
> use an obsolete four-operand display such as `qv.h v3, v1, x7, 12`. Canonical
> custom-0 assembly has three operands and no `vd`. These `.s` files are not used
> to build `demo/*.mem`, and the repository contains no reproducible `.s`-to-
> `.mem` generation step. The matching `.mem` words have been field-decoded
> independently, but must not be treated as products of the displayed `.s`.
> Regenerating both forms from one compiler is deferred; do not hand-edit the
> generated `.s` files in the meantime.

## Confirmed observations

On 2026-08-25, the pre-burst dispatcher baseline compiled and elaborated with Vivado 2024.2.

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

### Current full regression snapshot

On 2026-08-30, all 30 `demo/*.mem` images ran through a clean Verilator build
of the unified testbench: **29 PASS, 1 FAIL**. The single failure is
`graphstate_32`, which addresses 32 qubits while the snapshot is fixed at
`NUM_QUBITS=16` (open item CFG-001). Notable contract changes vs. the older
2026-08-27 snapshot:

- the QRV m4/m8 illegal images now PASS: the testbench taps the coprocessor's
  filtered rejection pulse (`cpi_instr_illegal`), and `+EXPECT_TRAP`
  (auto-injected by both runners for these images) makes the run terminate
  cleanly ~220 cycles after the expected rejection instead of timing out;
- any coprocessor rejection **without** `+EXPECT_TRAP` now fails the run --
  "unexpected illegal instruction" is part of the pass/fail contract;
- the four `qv_single/qv_pair/qv_rot_g/qv_rot_v` stream fixtures (vector
  arithmetic data, never legal qubit streams) moved to
  `demo/legacy_stream_fixtures/` and are no longer regression cases;
- `elf_combined.mem` used to "pass" by accident: its `@00000000` marker put
  the code at byte 0 while Ibex boots at 0x80, so every run booted into
  mid-program garbage, trapped, and vectored to the real entry. The image
  and `elf2mem.sh` now place `.text` at the boot address (`@00000020`);
  the image boots with zero traps.

The standalone dispatcher test passes 40/40 self-checking checks. It covers
valid synchronized bursts, index and pair bounds, atomic pair rejection,
repeated qubits, identical pair endpoints, timestamp conflicts, legal
increasing-time queuing, capacity-preflight atomic rejection, metadata
consistency, and bit-exact payload round-trips.

Focused checks reproduced these values:

- block-imm 8 and 24 fire at `t_cnt` 50 and 66;
- one qubit queued at increasing times fires at `t_cnt` 50 and 78;
- feedback result 0 omits GateID `0x70`, while result 1 includes it;
- `qv_measfetch` stores an injected `0xdeadbeef` at address `0x1010`;
- a two-row measurement file drives two transactions, while a truncated file
  fails at the missing transaction.

All five legacy xsim feature benches reach their DONE condition, but each logs
an illegal instruction and none has a strict output scoreboard. The separate
`qrv_mf2_direct` debug bench times out because its own completion counter skips
four valid cycles and then still expects 16 more, although only 12 remain. These
legacy/debug benches are not acceptance tests.

Vivado xsim agrees with Verilator on the checked Bell, feedback, rotation,
trap, and dispatcher results. Both runners now return a non-zero exit status
on FAIL: Verilator via `$fatal`, and `demo/run.sh` by checking the testbench
verdict in the log (xsim itself still exits 0 after `$fatal`). Both flows can
gate CI.

### Rotation directed checks

As of 2026-08-30, both runners automatically enable an exact scoreboard for
`qv_rot_gateid.mem`. The expected result is four raw beats, two AWG events,
and one fire each on q0/q1 with RZ (`0x6e`) and payload `0x00000555`,
q2 with RX (`0x6a`) and payload `0x00000aaa`, and q3 with RX and payload
`0x00000bbb`.

This scoreboard **passes** on current RTL, on both Verilator and Vivado xsim.
The two defects it was written to catch are both fixed as of 2026-08-30:
ROT.G's byte-replicated scalar payload (an operand-width override missing
`ELEM_QROTG` in `vproc_pipeline.sv`) and ROT.V's silent non-fire / misaligned
index-angle pairing (the ROT.V angle buffer shifted during discarded warm-up
beats; fixed by a tag-based freeze in `vproc_vregunpack.sv`, which also
allowed `vproc_top.sv`'s LMUL-guessed ROT.V ready-holdoff to be deleted).

Four further ROT.V images extend the pairing coverage. Each is checked
automatically: both runners inject `+AWG_EXPECT=demo/<case>.expect` whenever
that file exists, and the testbench then requires an exact multiset match of
qubit fires (one line per expected fire: `<qubit> <gate_hex> <C|T> <pv>
<payload_hex>`) -- any missing fire, unexpected fire, or count mismatch fails
the run:

| Image | Configuration | Expected |
|---|---|---|
| `qv_rot_vl1.mem` | mf2, VL=1 | q5 fires once with `0x00000abc` |
| `qv_rot_chunk.mem` | mf2, VL=6 | q4-q9 fire together with `0x111..0x666`, crossing the 128-bit vs2 chunk boundary |
| `qv_rot_m1.mem` | m1, VL=2 | q2/q3 fire with `0xaaa`/`0xbbb` |
| `qv_rot_m2.mem` | m2, VL=2 (vs1=v2, vs2=v8) | q2/q3 fire with `0xaaa`/`0xbbb` |

Both simulators agree on all of these. No LMUL-specific tuning remains in the
ready path; the alignment window is derived from pipeline tags and
self-adjusts across LMUL configurations.

A clean testbench summary is not circuit-equivalence evidence. Some generated
MQTBench assembly deliberately lowers unsupported rotations to H, for example
`qv.h ... # FALLBACK (rz)` in the QFT programs. These runs validate the emitted
substitute program, not the original QASM semantics.

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

- extend `.expect` scoreboards beyond the ROT images to the Bell/measure
  cases, and add fire-time (`t_cnt`) checking to the format -- the current
  scoreboard matches qubit/gate/role/payload but not timing;
- make `NUM_QUBITS` selectable for the 32-qubit workload;
- fix or archive the stale `qrv_mf2_direct` bench and add checks to the five
  legacy trace benches before treating them as regressions;
- test burst commit with full per-qubit FIFOs, decreasing timestamps, and legal
  intra-stream bubbles;
- retain self-checking counter-wrap and bit-exact measurement-result scoreboards;
- distinguish circuit-equivalent compiler output from documented fallback gates;
- enumerate ROT.V register-group overlap rules (vs1 vs. the implicit vs2
  LMUL group) with directed legal/illegal cases.

Local development checkouts may use the ignored `existing_problem.md` for owners and work-in-progress notes, but the tracked acceptance contract is this document.
