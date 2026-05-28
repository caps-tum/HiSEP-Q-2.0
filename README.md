# HiSEP-Q 2.0

**A RISC-V Vector Extension Architecture for Scalable Qubit Control**

HiSEP-Q 2.0 is a quantum control processor that extends the RISC-V V (RVV) vector ISA with four new quantum instructions. A single RISC-V program can configure, schedule, and fire gates across up to 256 physical qubits (can be easily extended to reconfig vector settings) — no separate pulse sequencer required.

---

## Architecture

```
                     RISC-V Assembly Program
                              │
                              ▼
              ┌─────────────────────────────────┐
              │          vproc_qdisp_top        │
              │                                 │
              │  ┌──────────┐   ┌───────────┐   │
              │  │  Ibex    │   │  vproc    │   │
              │  │ RISC-V   │─▶│  RVV      │   │
              │  │  core    │   │  vector   │   │
              │  └──────────┘   │  core     │   │
              │                 └─────┬─────┘   │
              │                       │quantum  │
              │                       │ stream  │
              │                 ┌─────▼──────┐  │
              │   t_cnt ──────▶│  quantum_  │  │
              │   (free-run)    │ dispatcher │  │
              │                 └─────┬──────┘  │
              └────────────────────── │ ────────┘
                                      │
                     qubit_gate_o  ───┤  per-qubit gate ID
                     qubit_valid_o ───┤  one-cycle fire pulse
                     qubit_ctrl_o  ───┘  control vs. target role
                                      │
                                      ▼
                              AWG / Control Electronics
```

**Ibex** ([github](https://github.com/lowrisc/ibex)) is an open-source RISC-V core (lowRISC) that handles scalar computation and program control flow.

**vproc** ([github](https://github.com/vproc/vicuna2_core)) is an RVV-compliant vector core that processes quantum gate instructions element-by-element — one qubit index per clock cycle — producing a streaming output of `(op, elem1, elem2, elem3)` per beat.

**quantum_dispatcher** (this repo) converts the vproc stream into precise, per-qubit timed firing pulses. It writes each qubit's gate into a dedicated FIFO tagged with a `dispatch_time`. A `time_controller` FSM per qubit watches the global `t_cnt` counter and pulses `qubit_valid_o` for exactly one cycle when the scheduled time arrives. The result is a cycle-accurate gate stream ready to drive an Arbitrary Waveform Generator (AWG).

---

## Quantum Instruction Set

Four new instructions extend the standard RVV opcode space (`funct7 = 1010111`):

| Instruction  | Operation | Operands |
|--------------|-----------|----------|
| `QV.SINGLE`  | Single-qubit gate (H, X, Y, Z, MEASURE, …) | `GateID`, `rs2` (scalar tag), `vs1` (qubit indices) |
| `QV.PAIR`    | Two-qubit gate (CNOT, SWAP, …) | `vs1` (control indices), `vs2` (target indices) |
| `QV.ROT.G`   | Single-angle rotation applied to many qubits | `rs2` (angle scalar), `vs1` (qubit indices) |
| `QV.ROT.V`   | Per-qubit variable rotation | `vs2` (angle vector, e32), `vs1` (qubit indices, e8) |

Each instruction carries a `block_imm` field in bits `[10:7]` that sets the gate firing time:

```
dispatch_time = t_cnt_at_first_beat + block_imm
```

Setting `block_imm > VL` guarantees all qubits in the same instruction fire at the **same** `t_cnt` — a hard requirement for AWG-driven multi-qubit gates.

Full ISA encoding details: [`HiSEPQ_ISA_spec.md`](HiSEPQ_ISA_spec.md)

---

## Key Features

- **Vectorized qubit control** — a single `QV.PAIR` instruction schedules a two-qubit gate across up to 256 qubit pairs in one program statement.
- **Cycle-accurate timing** — the `block_imm` field lets software set the exact `t_cnt` at which each gate fires, giving direct control over the AWG trigger timing.
- **Control / target disambiguation** — the `qubit_ctrl_o` output bus identifies, per qubit per cycle, whether it is the control or target side of a two-qubit gate. The AWG can use this to select the correct pulse shape without any software post-processing.
- **Mid-circuit measurement** — `GateID = 0x68` on `QV.SINGLE` asserts `qvsg_meas`, halting the CPU and vector pipeline until the external ADC signals `measure_done`. Execution then resumes from the next instruction automatically.
- **Standard toolchain compatibility** — the scalar program runs unchanged on any RISC-V toolchain; only the four quantum instructions require the HiSEP-Q assembler extension.

---

## Repository Layout

```
HiSEP-Q-2.0/
├── HiSEPQ_ISA_spec.md          # Full ISA specification
├── demo.md                     # Bell-state demo walkthrough and observed results
└── qvproc_prj/
    ├── README.md               # Hardware details, build instructions, instruction reference
    ├── configs/                # vproc configuration packages (SEW, LMUL, VREG type)
    ├── core/ibex/              # Ibex RISC-V core (vendored)
    ├── rtl/                    # HiSEP-Q RTL
    │   ├── vproc_qdisp_top.sv  # Top-level wrapper (Ibex + vproc + dispatcher)
    │   ├── quantum_dispatcher.v
    │   ├── timed_fifo.v
    │   ├── time_controller.v
    │   └── inst_fifo.v
    ├── docs/
    │   └── qsg_measure_spec.md # Mid-circuit measurement flow specification
    └── tb/quantum_cases/
        ├── cosim/
        │   └── run_cosim.sh    # Self-contained co-simulation script (xvlog/xelab/xsim)
        ├── vproc_qdisp_bell_tb.v
        ├── instruction_bell.mem
        └── data_bell.mem
```

---

## Quick Start: Bell-State Demo

The demo prepares 8 Bell pairs across 16 physical qubits and shows the complete gate stream output with control/target role labels.

```bash
cd qvproc_prj/tb/quantum_cases/cosim
./run_cosim.sh          # text log
./run_cosim.sh --gui    # open in Vivado waveform viewer
```

**Requirements:** Xilinx `xvlog` / `xelab` / `xsim` on PATH.

Expected AWG output (abridged):

```
[AWG][t_cnt=50]  valid_mask=0101010101010101   ← Hadamard, control qubits
[AWG][t_cnt=73]  valid_mask=1111111111111111   ← CNOT, all 16 qubits
  qubit[00]  gate=0x00  role=CTRL
  qubit[01]  gate=0x00  role=TGT
  ...
[AWG][t_cnt=96]  valid_mask=0101010101010101   ← Measure (CPU halts)
[AWG][t_cnt=167] valid_mask=1010101010101010   ← Resume marker (post-ADC)
```

Full walkthrough with timing analysis and design notes: [`demo.md`](demo.md)

---

## Hardware Details and Build

See [`qvproc_prj/README.md`](qvproc_prj/README.md) for:

- Vivado project rebuild instructions (target ZCU216; Next target: Alveo U55C, `xcu55c-fsvh2892-2L-e`)
- Complete quantum instruction encoding tables
- `QV.ROT.V` mixed-width LMUL mapping
- Compiler requirements and known traps
- Measurement flow (`qvsg_meas` / `measure_done` handshake)
