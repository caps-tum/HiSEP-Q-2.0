# QSG Measure Microarchitecture Specification

This document defines the internal halt/resume and ordering contract for
`QV.SINGLE` with the reserved MEASURE GateID. Programmer-visible encoding and
CSR behavior belong in [`../../docs/HiSEPQ_ISA_spec.md`](../../docs/HiSEPQ_ISA_spec.md);
the system-level overview belongs in
[`../../docs/architecture.md`](../../docs/architecture.md); regression and
PASS/FAIL requirements belong in
[`../../docs/verification.md`](../../docs/verification.md).

## Scope

The special path applies only when a `QV.SINGLE` instruction has
`GateID = 7'h68`. Other `QV.SINGLE` instructions retain their normal stream
behavior:

- `elem1`: qubit-index vector from `vs1`;
- `elem2`: 32-bit scalar payload selected by instruction bits `[24:20]`;
- `elem3`: QV.SINGLE control metadata.

The design supports one active measurement transaction. Multiple outstanding
measurements and speculative post-measure execution are outside the current
scope.

## External interface

| Signal | Direction | Contract |
|---|---|---|
| `qvsg_meas_o` | output | High while a measurement is active; also drives the Ibex external-interrupt input. |
| `measure_issued_done_o` | output | High for two cycles after the active measurement has issued its full `elem1` stream. |
| `measure_done_i` | input | Backend completion indication; releases the pause. |
| `measure_result_i[31:0]` | input | Sampled when `measure_done_i` is high and stored in CSR `0xCC0`. |

The AWG-facing wrapper `vproc_qdisp_top.sv` forwards these signals to
`vproc_top.sv`, where the measurement state is maintained.

## State sequence

```text
QV.SINGLE GateID 0x68 accepted
        |
        v
measurement active / Ibex interrupt requested
        |
        | current measurement elem1 stream continues
        v
exactly VL matching elements issued
        |
        v
measure_issued_done_o high for two cycles
queue-to-dispatch path paused
        |
        | wait for measure_done_i
        v
sample measure_result_i -> CSR 0xCC0
clear measurement state and resume
```

The central timing rule is: **Ibex stops early; vproc stops after the active
measurement stream drains.** Stopping vproc on the first measurement beat would
truncate a legal vector measurement.

## Completion and ordering contract

### Active-stream completion

Decode or first-beat observation is not completion. The implementation must
count the actual configured `VL`, not LMUL-derived VLMAX. A measurement with
`VL=1` therefore completes after one matching element even when the register
group could contain more elements.

Completion requires all `elem1` entries belonging to the active measurement
instruction to have been exported toward the quantum backend. Once that point
is reached, `measure_issued_done_o` is generated and the dispatch boundary is
paused.

### Ibex boundary

`qvsg_meas_o` is connected to the existing Ibex interrupt path. Ibex must use
its native interrupt, flush, and architectural-commit rules; this feature does
not define a parallel exception model. New Ibex-to-vproc offload work is
blocked while the measurement remains active.

### vproc boundary

The active measurement may drain through dispatcher, pipeline, unpack, and
unit paths. Younger vector work must not produce externally visible quantum
side effects after the measurement drain boundary. The implementation should
stall at the queue-to-dispatch boundary and flush only where existing pipeline
semantics require it.

In the current RTL, these responsibilities correspond to:

```text
vproc_issue_block    = measurement active and not measure_done_i
vproc_dispatch_pause = measurement stream drained and not measure_done_i
```

## Result and resume

When `measure_done_i` is asserted:

1. sample `measure_result_i[31:0]`;
2. overwrite the previous value in read-only custom CSR `0xCC0`;
3. clear the active/drained measurement state;
4. release offload and dispatch pauses;
5. allow subsequent Ibex and vproc work to continue.

Only the latest 32-bit result is retained. Result-to-qubit mapping is a software
and backend convention; the RTL stores the supplied word without decoding it.

## Verification obligations

A trusted measurement test must check:

- immediate assertion of `qvsg_meas_o` for GateID `0x68` only;
- exact drain count for `VL=1`, partial-VLMAX, and full-VL cases;
- a two-cycle `measure_issued_done_o` indication;
- no younger quantum event before backend completion;
- continued pause while `measure_done_i=0`;
- exact CSR `0xCC0` value after completion;
- post-measure instruction execution after resume;
- timeout and protocol violations produce a failing simulator exit status.

The maintained test matrix and current evidence are in
[`../../docs/verification.md`](../../docs/verification.md). This document does
not duplicate simulator commands or historical cycle counts.

## Current scope boundaries

The current implementation does not define:

- multiple outstanding measurement commands;
- a general backend transaction queue;
- speculative overlap of post-measure scalar work;
- interrupt prioritization beyond native Ibex behavior;
- accumulation of more than one 32-bit result word.
