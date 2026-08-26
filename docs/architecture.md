# HiSEP-Q Architecture

This document is the authoritative description of the HiSEP-Q hardware architecture and timing contract. Instruction encodings belong in [`HiSEPQ_ISA_spec.md`](HiSEPQ_ISA_spec.md); test evidence belongs in [`verification.md`](verification.md).

## System structure

```text
RISC-V program
    |
    v
Ibex scalar core -- CORE-V XIF --> vproc RVV core
                                      |
                                      | quantum element stream
                                      v
                              quantum_dispatcher
                                      |
                         per-qubit timed FIFO/controller
                                      |
                   qubit_gate / qubit_valid / qubit_ctrl
                                      |
                                      v
                               AWG/control backend
```

- **Ibex** executes RV32 scalar control flow and offloads vector/custom instructions through XIF.
- **vproc** executes standard RVV operations and converts each HiSEP-Q vector instruction into an element stream.
- **quantum_dispatcher** converts that stream into per-qubit timed gate events.
- One **timed FIFO + time controller** exists for each configured physical qubit output.

The integration wrapper is `qvproc_prj/rtl/vproc_qdisp_top.sv`. The lower-level `vproc_top.sv` does not instantiate the per-qubit dispatcher.

## Quantum stream

An accepted beat satisfies:

```text
quantum_valid && quantum_data_ready
```

| Signal | Meaning |
|---|---|
| `quantum_op` | `QV.SINGLE`, `QV.PAIR`, `QV.ROT.G`, or `QV.ROT.V` |
| `quantum_elem1` | Primary qubit index in bits `[7:0]` |
| `quantum_elem2` | Scalar payload, second qubit index, or 32-bit vector angle |
| `quantum_elem3` | GateID and `block_imm` metadata |
| `quantum_first_cycle` | First beat of the instruction stream |
| `quantum_last_cycle` | Exported sideband; currently observed not to mark QV.SINGLE/QV.PAIR stream completion reliably |

`QV.PAIR` produces one primary/control qubit from `elem1` and one secondary/target qubit from `elem2` per accepted beat. The role mapping is exported through `qubit_ctrl_o`.

## Addressing and capacity

The instruction stream uses 8-bit direct qubit indices. The current ISA specification restricts direct-index software to `0..127`, with bit 7 reserved. The number of actual output channels is the `NUM_QUBITS` parameter:

- wrapper default: 8;
- unified co-simulation configuration: 16;
- larger physical configurations have not yet been demonstrated by a self-checking synthesis/simulation regression.

Architectural index width, configured physical outputs, and verified capacity are different quantities. A claim such as "256 qubits" is not considered verified until an appropriate `NUM_QUBITS` configuration passes the criteria in [`verification.md`](verification.md).

## Dispatcher timing contract

### Previous implementation

The original dispatcher computed one target time from the first stream beat:

```text
dispatch_time = t_cnt_at_first_beat + block_imm
```

Elements reached per-qubit FIFOs serially. For long streams, later elements could arrive after that shared deadline and were released late on consecutive cycles. The corresponding large-VL regression requirement is recorded in [`verification.md`](verification.md).

### Current working-tree implementation

The dispatcher now accumulates the touched-qubit set, GateID, role bits, and `block_imm` for one instruction. It burst-writes all accumulated per-qubit FIFOs when that instruction is flushed:

```text
flush = next accepted beat has a different quantum_instr_id
     OR pending stream has been idle for IDLE_FLUSH_CYCLES (currently 8)

dispatch_time = t_cnt_at_flush + effective_offset
effective_offset = block_imm != 0 ? block_imm : FIXED_LATENCY
```

`quantum_last_cycle` is deliberately not used: directed tracing showed it remained low on every beat of representative QV.SINGLE/QV.PAIR streams. Instruction-ID transition handles all non-final instructions; the idle path handles a final instruction for which no next ID arrives.

This removes stream length from the 5-bit offset requirement because the target time is created only after the selected set has been accumulated. Verilator and xsim regressions have shown a VL=128/m8 `qv_pair` instruction firing its selected in-range outputs on one common AWG line instead of consecutive `t_cnt` values.

The core race is resolved, but the complete contract still has open items:

- a bitmap collapses repeated occurrences of one qubit within an instruction; the intended multiset/conflict behavior is not defined;
- `QV.PAIR` repeated-index role resolution needs an ISA policy;
- burst behavior with full per-qubit FIFOs needs a directed test;
- the 8-cycle idle threshold needs a proven bound against every legal intra-stream bubble;
- `block_imm=0` must leave enough FIFO/controller setup margin;
- invalid indices now produce a same-cycle `invalid_index_error_o` pulse, but it is not yet sticky or part of trusted pass/fail.

## Timed FIFO and controller

Each per-qubit entry contains `{dispatch_time, role, GateID}`. The time controller follows `IDLE -> WAIT -> ISSUE`. In the current RTL, WAIT uses an unsigned expiration comparison:

```text
t_inst <= t_cnt + 1
```

This deliberately releases late entries but is unsafe across time-counter wraparound. The required wraparound regression is listed in [`verification.md`](verification.md).

## Measurement and feedback

`QV.SINGLE` with GateID `0x68` is the measurement operation:

1. `qvsg_meas_o` asserts and blocks new offload work.
2. The current measurement element stream drains.
3. `measure_issued_done_o` pulses for two cycles.
4. The machine remains paused until `measure_done_i`.
5. On completion, execution resumes.

The current working tree also accepts `measure_result_i[31:0]` and latches it into read-only CSR `0xCC0`. Detailed control behavior remains in [`qsg_measure_spec.md`](../qvproc_prj/docs/qsg_measure_spec.md). Program-visible feedback still requires the CSR regression listed in [`verification.md`](verification.md).

## Build boundary

The documented Vivado rebuild script currently selects `vproc_top`, not `vproc_qdisp_top`, and omits the dispatcher RTL from the synthesis fileset. Therefore the rebuild flow does not yet produce the complete diagram shown above. See [`qvproc_prj/README.md`](../qvproc_prj/README.md) for the current build command.
