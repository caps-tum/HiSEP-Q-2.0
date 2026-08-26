# HiSEP-Q 2.0

**A RISC-V vector architecture for scalable quantum-control experiments**

HiSEP-Q combines an Ibex RV32 scalar core, an RVV-compatible vproc vector core, and a per-qubit timed dispatcher. Four custom vector instructions generate qubit-index, gate, role, and angle streams for an AWG/control backend.

The project is an active RTL prototype. Small Bell/measurement flows have been observed end to end in simulation; large-vector timing, strict self-checking regression, and complete FPGA-top integration are still in progress. Verification scope and remaining gaps are documented in [`docs/verification.md`](docs/verification.md).

## Architecture

```text
RISC-V program
      |
      v
Ibex -- XIF --> vproc -- quantum stream --> quantum_dispatcher
                                                |
                                   per-qubit timed FIFOs
                                                |
                                   gate / valid / role --> AWG
```

The full architecture, stream interface, timing contract, capacity terminology, and measurement flow are defined in [`docs/architecture.md`](docs/architecture.md).

## Quantum ISA

The current instruction encoding uses RISC-V **custom-0** opcode `0x0B`. Legacy OP-V encodings remain dual-decoded during migration but are not the canonical encoding for new programs.

| Instruction | `funct3` | Main operands | Purpose |
|---|---:|---|---|
| `QV.SINGLE` | `000` | GateID, scalar payload, index vector | Single-qubit gate or measurement |
| `QV.PAIR` | `001` | source/control and target index vectors | Two-qubit gate |
| `QV.ROT.G` | `010` | scalar angle and index vector | Shared-angle rotation |
| `QV.ROT.V` | `011` | e32 angle vector and e8 index vector | Per-qubit rotation |

Instruction fields, LMUL rules, GateIDs, CSR behavior, and compiler constraints are defined only in [`HiSEPQ_ISA_spec.md`](docs/HiSEPQ_ISA_spec.md).

## Quick start

Vivado `xvlog`, `xelab`, and `xsim` must be available on `PATH`:

```bash
cd demo
./run.sh bell_generic
./run.sh bell_8pair
./run.sh --no-compile qv_pair
```

A Verilator path is also available:

```bash
cd demo/verilator
./run_verilator.sh bell_generic
```

Commands and memory-image conventions are in [`demo/README.md`](demo/README.md). Verification scope and the meaning of PASS are in [`docs/verification.md`](docs/verification.md).

## Repository layout

```text
HiSEP-Q-2.0/
├── README.md                     # project entry and document map
├── docs/
│   ├── HiSEPQ_ISA_spec.md        # authoritative instruction-set specification
│   ├── architecture.md           # hardware and timing contract
│   ├── verification.md           # tests, evidence, and PASS/FAIL contract
│   └── tutorial-bell.md          # Bell-state walkthrough
├── demo/
│   ├── README.md                 # unified simulation commands and images
│   ├── run.sh                    # Vivado co-simulation driver
│   ├── elf2mem.sh                # ELF to combined-memory converter
│   └── *.mem                     # test-program images
└── qvproc_prj/
    ├── README.md                 # Vivado project/rebuild notes
    ├── rtl/                      # vproc integration and HiSEP-Q RTL
    ├── configs/                  # vector-core configurations
    ├── docs/qsg_measure_spec.md  # detailed measurement control specification
    ├── tb/quantum_cases/         # unified and legacy testbenches
    └── mqtbench_compiled/        # QASM and assembly sources
```

## Documentation ownership

| Subject | Authoritative document |
|---|---|
| Project overview and navigation | [`README.md`](README.md) |
| ISA encoding and programming contract | [`HiSEPQ_ISA_spec.md`](docs/HiSEPQ_ISA_spec.md) |
| Hardware/timing architecture | [`docs/architecture.md`](docs/architecture.md) |
| Verification commands and evidence | [`docs/verification.md`](docs/verification.md) |
| Demo usage and memory images | [`demo/README.md`](demo/README.md) |
| Vivado rebuild flow | [`qvproc_prj/README.md`](qvproc_prj/README.md) |
| Measurement microarchitecture | [`qvproc_prj/docs/qsg_measure_spec.md`](qvproc_prj/docs/qsg_measure_spec.md) |

`CLAUDE.md` and `existing_problem.md` are optional local coordination files and are intentionally not tracked. A clean clone must not depend on them; durable conclusions belong in the tracked documents above.

## Current status

- custom-0 decode for all four instruction classes: implemented;
- small Bell/measurement stream and AWG activity: observed in simulation;
- measurement-result CSR `0xCC0`: present in the current working tree, trusted regression pending;
- complete self-checking suite: open (see verification);
- large-vector simultaneous dispatch: core burst mechanism implemented; repeated-index and boundary semantics remain open (see verification);
- complete FPGA wrapper synthesis flow: open (see qvproc project notes).

Detailed gaps and acceptance conditions are maintained in [`docs/verification.md`](docs/verification.md). Local development checkouts may additionally use the ignored `existing_problem.md` as a working issue ledger.
