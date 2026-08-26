# HiSEP-Q Demo Programs

This directory is the unified co-simulation entry point. ISA definitions live in [`../docs/HiSEPQ_ISA_spec.md`](../docs/HiSEPQ_ISA_spec.md); verification status and PASS/FAIL policy live in [`../docs/verification.md`](../docs/verification.md).

## Run with Vivado

Vivado `xvlog`, `xelab`, and `xsim` must be on `PATH`:

```bash
cd demo
./run.sh bell_generic
./run.sh bell_8pair
./run.sh mqtbench_qft_16
./run.sh --no-compile qv_pair
./run.sh --gui bell_8pair
```

Options:

| Option | Meaning |
|---|---|
| `--no-compile` | reuse the existing simulation snapshot |
| `--gui` | open the Vivado waveform viewer |
| `--elf FILE` | convert an ELF to combined memory, then run it |

## Run with Verilator

Requirements: Verilator 5.x or newer and a C++ compiler such as `g++`.

```bash
verilator --version
cd demo/verilator
./run_verilator.sh bell_generic
./run_verilator.sh --no-build bell_generic
./run_verilator.sh ../mqtbench_qft_8.mem
```

The argument may be a demo case name, a `.mem` filename, or a path. The script builds the same unified testbench used by `demo/run.sh` as a normal Verilator executable.

## Memory-image format

Every `demo/*.mem` file is a combined image:

- instruction words start at word address 0;
- data starts at `@00000400`, corresponding to byte address `0x1000`;
- `run.sh` passes the selected path through `+MEM_FILE=...`.

To create an image from an ELF:

```bash
./elf2mem.sh path/to/program.elf output.mem
./run.sh --elf path/to/program.elf
```

The ELF flow expects `.text` at `0x0`, `.data` at `0x1000`, and a compatible RISC-V objcopy tool.

## Program groups

| Prefix | Purpose | Source location |
|---|---|---|
| `bell_*` | Bell and measurement flows | hand-written/reference material in `qvproc_prj/tb/quantum_cases` |
| `qv_*` | directed ISA, illegal, measurement, and feedback stimuli | associated text/memory files in `qvproc_prj/tb/quantum_cases` |
| `mqtbench_*` | compiled circuit workloads | QASM/assembly in `qvproc_prj/mqtbench_compiled` |

Use `ls *.mem` for the current case list. The set is evolving, so this README does not duplicate a fixed count.

## Reading output

- `[INSTR]`: selected scalar/vector instruction trace;
- `[QX]`: raw quantum element-stream beat;
- `[AWG]`: a dispatcher output event for one or more qubits;
- measurement lines: halt, drain, backend completion, and resume observations.

The existing unified testbench historically reports PASS when no FIFO overflow is seen. That is not sufficient functional verification: an out-of-range program can produce zero fires and still show the old PASS banner. Illegal m4/m8 stimuli, timeout behavior, and exact cycle values must be interpreted using the current contract in [`../docs/verification.md`](../docs/verification.md).

## Bell tutorial

See [`../docs/tutorial-bell.md`](../docs/tutorial-bell.md). Exact historical cycle numbers may change while dispatcher scheduling is being redesigned.
