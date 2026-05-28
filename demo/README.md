# HiSEP-Q Demo Programs

This directory is the single entry point for running co-simulation. It holds:

- `run.sh` — the simulation driver (xvlog + xelab + xsim)
- `elf2mem.sh` — converts a HiSEP-Q ELF into a combined `.mem`
- `<name>.mem` — combined memory images, one per test program

All `.mem` files here are **combined**: instruction words at word 0, data at
`@00000400` (byte 0x1000). The testbench loads them via plusarg `+MEM_FILE=…`
(set automatically by `run.sh`).

To run your own program, drop a new `<name>.mem` into this directory (or use
`./run.sh --elf path/to/program.elf` to convert from ELF) and:

```bash
./run.sh <name>
```

The flat layout is intentional — filename prefix encodes the category:

| Prefix       | Category                       | Count |
|--------------|--------------------------------|------:|
| `bell_*`     | Hand-written Bell-state demos  | 2     |
| `mqtbench_*` | Programs from MQT-Bench suite  | 11    |
| `qv_*`       | ISA unit tests (per-instruction) | 7   |
| **Total**    |                                | **20** |

---

## `bell_*` — Bell-state demos

| Case | Qubits | Notes |
|------|-------:|-------|
| `bell_8pair`    | 16 (VL=8) | Reference Bell demo — matches the `[QDISP_TB] ===== CO-SIM SUMMARY =====` baseline of 372 cycles / 32 events / 40 fires. |
| `bell_generic`  | 8  (VL=4) | Small smoke test. **Hits the MEASURE-race bug** documented in `CLAUDE.md` (VL ≤ 4): `qvsg_meas` asserts but never clears, CPU halts until the testbench 200-idle-cycle watchdog. |

## `mqtbench_*` — MQT-Bench programs

QASM and `.s` sources for these live in `qvproc_prj/mqtbench_compiled/`.

| Case | Qubits | Notes |
|------|-------:|-------|
| `mqtbench_bell_4`                      | 4  | Tiny VL → same MEASURE-race symptom as `bell_generic`. |
| `mqtbench_bell_8`                      | 8  | Equivalent to `bell_8pair` (32 events / 40 fires). |
| `mqtbench_ghz_8` / `_16`               | 8 / 16 | GHZ state preparation. |
| `mqtbench_graphstate_8_deg2_seed10`    | 8  | deg=2 graph-state, seed 10. |
| `mqtbench_graphstate_16_deg2_seed16`   | 16 | deg=2, seed 16. |
| `mqtbench_graphstate_32_deg2_seed32`   | 32 | deg=2, seed 32. |
| `mqtbench_qaoa_8_r2_seed10`            | 8  | QAOA, r=2, seed 10. No MEASURE. |
| `mqtbench_qaoa_16_r2_seed10`           | 16 | QAOA, r=2, seed 10. No MEASURE. |
| `mqtbench_qft_8` / `_16`               | 8 / 16 | QFT. The 16-qubit version is the longest in the suite (~16k cycles). |
| `mqtbench_twolocal_16_r3`              | 16 | Two-local ansatz, r=3. |

## `qv_*` — ISA unit tests

Targeted exercise of each quantum instruction in isolation.

| Case | Tests | Notes |
|------|-------|-------|
| `qv_single`              | `QV.SINGLE` | Single-qubit gate fan-out. |
| `qv_pair`                | `QV.PAIR`   | Two-qubit gate, ctrl/tgt vector pairs. |
| `qv_rot_g`               | `QV.ROT.G`  | Global angle to a vector of qubits. |
| `qv_rot_v`               | `QV.ROT.V`  | Per-qubit angle (e32 angle vec, e8 idx vec). |
| `qv_rot_v_illegal_m4`    | `QV.ROT.V` LMUL=m4 | Hardware-illegal (vs2 would need m16). Currently runs to the testbench's 200000-cycle watchdog without producing quantum events — there is no explicit illegal-detection signal yet. |
| `qv_rot_v_illegal_m8`    | `QV.ROT.V` LMUL=m8 | Same — illegal, falls through to watchdog. |

---

## Running

Source Vivado first (`xvlog`/`xelab`/`xsim` must be on PATH), then from `demo/`:

```bash
./run.sh                          # default: bell_generic
./run.sh bell_8pair                # reference Bell demo (matches CLAUDE.md baseline)
./run.sh mqtbench_qft_16           # longest case
./run.sh --no-compile <case>       # reuse existing snapshot for fast re-runs
./run.sh --gui <case>              # open in Vivado waveform viewer
./run.sh --elf path/to/program.elf # load a HiSEP-Q ELF
```
