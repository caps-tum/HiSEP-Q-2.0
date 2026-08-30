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

The raw stream can carry scalar or angle data in `quantum_elem2`, but each timed
FIFO currently stores only `{dispatch_time, role, GateID}`. No payload or
instruction-class tag reaches the fire-time AWG boundary. Fixed gates work with
a globally unique GateID; parameterized rotations remain incomplete.

## Addressing and capacity

The instruction stream uses 8-bit direct qubit indices in the range `0..255`. The number of actual output channels is the `NUM_QUBITS` parameter:

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

This removes stream length from the 5-bit offset requirement because the target
time is created only after the selected set has been accumulated. The standalone
dispatcher regression checks a synchronized burst directly. The checked-in
VL=128 `qv_pair` image is not positive evidence for this property: with the
unified testbench `NUM_QUBITS=16`, most indices are out of range and the case
correctly fails.

The core race is resolved. The repeated-qubit/conflict policy that was previously undefined here has since been decided and implemented (user-confirmed, 2026-08-26): repeating a qubit within one instruction, or scheduling the same qubit at the same absolute `dispatch_time` from different instructions, is illegal and rejects the whole accumulated instruction (zero fires). The same qubit at different `dispatch_time`s is legal and queues normally. This is verified by the standalone `quantum_dispatcher_tb.v` regression (23/23 checks) and by directed `.mem` fixtures (`qv_diff_time_queue.mem` for the legal case).

Remaining open items:

- burst behavior with full per-qubit FIFOs needs a directed test (a burst can currently partially execute if one destination FIFO is full and another is not -- no burst-wide capacity preflight exists);
- the 8-cycle idle threshold needs a proven bound against every legal intra-stream bubble;
- `block_imm=0` must leave enough FIFO/controller setup margin;
- invalid-index/invalid-pair/FIFO-overflow/illegal pulses are separately counted.
  The unified testbench calls `$fatal` on failure; Verilator returns non-zero,
  while the current xsim runner still exits zero. There is no per-case
  expected-error scoreboard. Per-qubit queues are FIFO-ordered rather than
  time-sorted, so a later-enqueued earlier timestamp can be blocked behind the
  queue head and fire late.

## Timed FIFO and controller

Each per-qubit entry contains `{dispatch_time, role, GateID}`. The time controller follows `IDLE -> WAIT -> ISSUE`. The WAIT expiration test is a modular, wraparound-safe comparison, not a plain unsigned one:

```text
time_since_target = (t_cnt + 1) - t_inst    // modular subtraction, wraps by design
target_reached    = ~time_since_target[TIME_WIDTH-1]   // sign bit of the modular delta
```

This is valid as long as the scheduled distance stays under half the counter range, the standard assumption for this kind of modular comparison. Verified with a throwaway `TIME_WIDTH=4` directed test comparing wrapping vs. non-wrapping cases at matching offsets (0, 1, 2, and the maximum supported offset); not yet retained as a permanent checked-in regression. The required permanent wraparound regression is listed in [`verification.md`](verification.md).

## Measurement and feedback

`QV.SINGLE` with GateID `0x68` is the measurement operation:

1. `qvsg_meas_o` asserts and blocks new offload work.
2. The current measurement element stream drains.
3. `measure_issued_done_o` pulses for two cycles.
4. The machine remains paused until `measure_done_i`.
5. On completion, execution resumes.

The current working tree also accepts `measure_result_i[31:0]` and latches it into read-only CSR `0xCC0`. Detailed control behavior remains in [`qsg_measure_spec.md`](../qvproc_prj/docs/qsg_measure_spec.md). Program-visible feedback still requires the CSR regression listed in [`verification.md`](verification.md).

## Build boundary

As of 2026-08-26, the Vivado rebuild script selects `vproc_qdisp_top`, includes
the dispatcher RTL, and completes `synth_design` for its current legacy AU55C
part setting. The intended future board is ZCU216, but that retargeting and the
board-level `mem_*`/`measure_*`/`qubit_*` constraints are not implemented.
Current acceptance is simulation-only; see
[`qvproc_prj/README.md`](../qvproc_prj/README.md).
