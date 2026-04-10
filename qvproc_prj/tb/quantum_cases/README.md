# Quantum TB Cases

This folder contains one standalone Verilog testbench per quantum instruction:

- `vproc_qsg_tb.v` for `QV.SINGLE`
- `vproc_qpr_tb.v` for `QV.PAIR`
- `vproc_qrg_tb.v` for `QV.ROT.G`
- `vproc_qrv_tb.v` for `QV.ROT.V`
- `vproc_bell_tb.v` for a compact mixed Bell-style demo

Each testbench has its own paired memory files:

- `instruction_qsg.mem`, `data_qsg.mem`
- `instruction_qpr.mem`, `data_qpr.mem`
- `instruction_qrg.mem`, `data_qrg.mem`
- `instruction_qrv.mem`, `data_qrv.mem`
- `instruction_bell.mem`, `data_bell.mem`

Common test intent:

- `SEW=8` is fixed.
- `LMUL=mf2, m1, m2, m4, m8` are each exercised.
- Source vectors are loaded by the program itself using `vle8.v`.
- The testbench checks only the exported quantum slice ports from `vproc_top`.

## QSG measure scenario

The `qsg` case now starts with a `QSG.MEASURE` instruction:

- `GateID = 7'h68`
- `elem1` carries the qubit index stream from `vs1`
- `elem2` carries the 32-bit scalar value from `rs2`
- `elem3` carries the packed `GateID/m/block_imm` metadata

The QSG testbench also exercises the current halt-resume handshake:

- it prints `qvsg_meas`
- it prints `measure_issued_done`
- it drives `measure_done`
- after `measure_issued_done`, it waits `50` clock cycles before asserting `measure_done`

This is meant to show the current `QSG-MEASURE` contract:

- Ibex is interrupted as soon as `qvsg_meas` goes active
- vproc drains the active measure stream
- later work is held until `measure_done`

## Batch simulation from qvproc_prj root

Run from the project root:

```bash
cd qvproc_prj
QUANTUM_CASE=qsg vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=qpr vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=qrg vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=qrv vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=bell vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
```

If `QUANTUM_CASE` is not set, the Tcl defaults to `qpr`.

You can override the default instruction or data memory file:

```bash
cd qvproc_prj
QUANTUM_CASE=qrv \
QUANTUM_INSTR_FILE=/abs/path/to/instruction_qrv.mem \
QUANTUM_DATA_FILE=/abs/path/to/data_qrv.mem \
vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
```
