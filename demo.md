# HiSEP-Q 2.0 Bell State Demo

## System Overview

We set up 16 qubits for the experiments demo, here is the block diagram of the demo architecture

```
┌─────────────────────────────────────────────────────┐
│                  vproc_qdisp_top                    │
│                                                     │
│  ┌──────────────┐      ┌────────────────────────┐   │
│  │  Ibex        │      │  quantum_dispatcher    │   │
│  │  RISC-V core │      │                        │   │
│  │      +       │─────▶│  16× timed_fifo        │   │
│  │  vproc RVV   │      │  (per qubit)           │   │
│  │  vector core │      │                        │   │
│  └──────────────┘      └──────────┬─────────────┘   │
│                                   │                 │
│         free-running t_cnt ───────┘                 │
└───────────────────────────────────┬─────────────────┘
                                    │ qubit_gate_o / qubit_valid_o / qubit_ctrl_o
                                    ▼
                               (Virtual, simulated) AWG / Control Electronics
```

- **Ibex** decodes RISC-V scalar instructions and offloads vector instructions to vproc.
- **vproc** (RVV vector core) executes quantum gate instructions element-by-element, emitting a stream of `(op, elem1, elem2, elem3)` signals — one beat per qubit per cycle.
- **quantum_dispatcher** receives this stream, extracts the target qubit index and GateID from each beat, and schedules gate firing via per-qubit timed FIFOs.
- Each **timed_fifo** holds a `(dispatch_time, GateID, role)` entry. A `time_controller` FSM watches the global `t_cnt` counter and pulses `qubit_valid_o` for exactly one clock cycle when `t_cnt == dispatch_time`. This pulse is the signal sent to the AWG to physically drive the qubit. An accompanying `qubit_ctrl_o` bit indicates whether the qubit is the **control** side (elem1, from v1) or **target** side (elem2, from v2) of a two-qubit gate.

---

## Demo Program: Bell State Preparation

### Algorithm

Prepare 8 Bell pairs across 16 physical qubits:

```
qubits (control): 0, 2, 4, 6, 8, 10, 12, 14   (loaded from v1)
qubits (target) : 1, 3, 5, 7, 9, 11, 13, 15   (loaded from v2)

Step 1:  H  on all control qubits   (QV.SINGLE, GateID=0x64)
Step 2:  CX on all 8 pairs          (QV.PAIR,   GateID=0x00)
Step 3:  MEASURE on control group   (QV.SINGLE, GateID=0x68) → halts CPU
Step 4:  Resume marker              (QV.SINGLE, GateID=0x78) → resumes after ADC done
```

### Instruction Binaries/Assembly (`instruction_bell.mem`)

| Line | Hex Word   | Instruction                         |
|------|------------|-------------------------------------|
| 1    | `06600313` | `addi x6, x0, 0x66`  (resume tag)  |
| 2    | `05500393` | `addi x7, x0, 0x55`  (gate tag)    |
| 3    | `00800293` | `addi x5, x0, 8`     (AVL=8)       |
| 4    | `0C72F057` | `vsetvli x0, x5, e8, mf2`           |
| 5    | `00000013` | `nop`                               |
| 6    | `00001537` | `lui a0, 0x1`         (base=0x1000) |
| 7    | `02050087` | `vle8.v v1, (a0)`    (control idx) |
| 8    | `00850593` | `addi a1, a0, 8`                    |
| 9    | `02058107` | `vle8.v v2, (a1)`    (target idx)  |
| 10   | `C8708657` | `QV.SINGLE` H gate, **block_imm=12** |
| 11   | `CC208657` | `QV.PAIR`   CX gate, **block_imm=12** |
| 12   | `D0708657` | `QV.SINGLE` MEASURE, **block_imm=12** |
| 13   | `F0610657` | `QV.SINGLE` resume,  **block_imm=12** |
| 14   | `0000006F` | `jal x0, 0`  (self-loop)            |

**block_imm** is encoded in instruction bits `[11:7]`. 
It sets the gate scheduling time relative to instruction dispatch: `dispatch_time = t_cnt_at_first_beat + block_imm`. With `block_imm=12` and VL=8 (8 beats per instruction), all 8 beats are written to their FIFOs before `dispatch_time` arrives, so all qubits fire at the same `t_cnt`.

NOTE!: Since the vector push out qubit index on after each other, so the scheduling time has to be larger than VL+1. Otherwise, the scheduling time is small than the actual time stamp, so the qubit will be fired asap, instead of at scheduling time.

<!-- ### Data Layout (`data_bell.mem`, base address `0x1000`)

| Address  | Value        | Contents                                  |
|----------|--------------|-------------------------------------------|
| `0x1000` | `0x06040200` | control qubit indices: 0, 2, 4, 6        |
| `0x1004` | `0x0E0C0A08` | control qubit indices: 8, 10, 12, 14     |
| `0x1008` | `0x07050301` | target qubit indices:  1, 3, 5, 7        |
| `0x100C` | `0x0F0D0B09` | target qubit indices:  9, 11, 13, 15     | -->

Output:

```
=== Simulation log (last 40 lines) ===
[AWG][t_cnt=96]   qubit[06]  gate=0x68  role=CTRL
[AWG][t_cnt=96]   qubit[08]  gate=0x68  role=CTRL
[AWG][t_cnt=96]   qubit[10]  gate=0x68  role=CTRL
[AWG][t_cnt=96]   qubit[12]  gate=0x68  role=CTRL
[AWG][t_cnt=96]   qubit[14]  gate=0x68  role=CTRL
[QDISP_TB][cycle=153][MEASURE] measure_done=1 (sent)
[QDISP_TB][cycle=155][MEASURE] qvsg_meas=0 resume
[QDISP_TB][cycle=156][INSTR] f0610657  V.SINGLE(resume) vd6, v2, x6
[QDISP_TB][cycle=157][INSTR] 0000006f  jal x0, 0                  
[QDISP_TB][cycle=165][QX_START] op=16(QV.SINGLE   ) id=6 vd=12 elem2=00000066 elem3=f0000600 ready=1
[QDISP_TB][cycle=165][QX] idx=24 op=QV.SINGLE    id=6 elem1=00000001 elem2=00000066 elem3=f0000600 ready=1 t_cnt=155
[QDISP_TB][cycle=165][RESUME] first post-measure event seen
[QDISP_TB][cycle=166][QX] idx=25 op=QV.SINGLE    id=6 elem1=00000003 elem2=00000066 elem3=f0000600 ready=1 t_cnt=156
[QDISP_TB][cycle=167][QX] idx=26 op=QV.SINGLE    id=6 elem1=00000005 elem2=00000066 elem3=f0000600 ready=1 t_cnt=157
[QDISP_TB][cycle=168][QX] idx=27 op=QV.SINGLE    id=6 elem1=00000007 elem2=00000066 elem3=f0000600 ready=1 t_cnt=158
[QDISP_TB][cycle=169][QX] idx=28 op=QV.SINGLE    id=6 elem1=00000009 elem2=00000066 elem3=f0000600 ready=1 t_cnt=159
[QDISP_TB][cycle=170][QX] idx=29 op=QV.SINGLE    id=6 elem1=0000000b elem2=00000066 elem3=f0000600 ready=1 t_cnt=160
[QDISP_TB][cycle=171][QX] idx=30 op=QV.SINGLE    id=6 elem1=0000000d elem2=00000066 elem3=f0000600 ready=1 t_cnt=161
[QDISP_TB][cycle=172][QX] idx=31 op=QV.SINGLE    id=6 elem1=0000000f elem2=00000066 elem3=f0000600 ready=1 t_cnt=162
[AWG][t_cnt=167] valid_mask=1010101010101010  (cycle=177)
[AWG][t_cnt=167]   qubit[01]  gate=0x78  role=CTRL
[AWG][t_cnt=167]   qubit[03]  gate=0x78  role=CTRL
[AWG][t_cnt=167]   qubit[05]  gate=0x78  role=CTRL
[AWG][t_cnt=167]   qubit[07]  gate=0x78  role=CTRL
[AWG][t_cnt=167]   qubit[09]  gate=0x78  role=CTRL
[AWG][t_cnt=167]   qubit[11]  gate=0x78  role=CTRL
[AWG][t_cnt=167]   qubit[13]  gate=0x78  role=CTRL
[AWG][t_cnt=167]   qubit[15]  gate=0x78  role=CTRL
[QDISP_TB][cycle=372][DONE] 200 idle cycles after last event

[QDISP_TB] ===== CO-SIM SUMMARY =====
[QDISP_TB]  cycles         : 372
[QDISP_TB]  quantum events : 32
[QDISP_TB]  qubit fires    : 40
[QDISP_TB]  FIFO errors    : 0
[QDISP_TB]  RESULT         : PASS – no FIFO overflows
[QDISP_TB] ==========================
```

---

## How to Run

```bash
cd qvproc_prj/tb/quantum_cases/cosim
./run_cosim.sh          # compile + elaborate + simulate (text log)
./run_cosim.sh --gui    # open in Vivado waveform viewer
```

Requirements: Xilinx `xvlog` / `xelab` / `xsim` on PATH.

---

## Observed Simulation Results

All results from a single run of `run_cosim.sh` (372 clock cycles total).

### Event 1 — Hadamard Gate (QV.SINGLE, GateID=0x64)

vproc streams 8 beats (one per control qubit) starting at cycle 48, `t_cnt=38`.  
`dispatch_time = 38 + 12 = 50`. All 8 FIFOs are written by `t_cnt=45`, so all fire together.  
Single-qubit gate: all qubits are `CTRL` by convention.

```
[AWG][t_cnt=50] valid_mask=0101010101010101
  qubit[00]  gate=0x64  role=CTRL
  qubit[02]  gate=0x64  role=CTRL
  qubit[04]  gate=0x64  role=CTRL
  qubit[06]  gate=0x64  role=CTRL
  qubit[08]  gate=0x64  role=CTRL
  qubit[10]  gate=0x64  role=CTRL
  qubit[12]  gate=0x64  role=CTRL
  qubit[14]  gate=0x64  role=CTRL
```

`valid_mask=0101010101010101` — even-numbered qubits only, as expected for the control group.

### Event 2 — CNOT Gate (QV.PAIR, GateID=0x00)

vproc streams 8 pair beats starting at cycle 71, `t_cnt=61`.  
`dispatch_time = 61 + 12 = 73`. All 16 FIFOs fire at the same `t_cnt`.  
`qubit_ctrl_o` distinguishes the two roles within each pair:

```
[AWG][t_cnt=73] valid_mask=1111111111111111
  qubit[00]  gate=0x00  role=CTRL    ← v1, CNOT control (not flipped)
  qubit[01]  gate=0x00  role=TGT     ← v2, CNOT target  (flipped)
  qubit[02]  gate=0x00  role=CTRL
  qubit[03]  gate=0x00  role=TGT 
  qubit[04]  gate=0x00  role=CTRL
  qubit[05]  gate=0x00  role=TGT 
  qubit[06]  gate=0x00  role=CTRL
  qubit[07]  gate=0x00  role=TGT 
  qubit[08]  gate=0x00  role=CTRL
  qubit[09]  gate=0x00  role=TGT 
  qubit[10]  gate=0x00  role=CTRL
  qubit[11]  gate=0x00  role=TGT 
  qubit[12]  gate=0x00  role=CTRL
  qubit[13]  gate=0x00  role=TGT 
  qubit[14]  gate=0x00  role=CTRL
  qubit[15]  gate=0x00  role=TGT 
```

All 16 qubits fire simultaneously. The CNOT GateID is `0x00`; `qubit_valid_o` is generated from an explicit FSM pulse (not `gate != 0`), so GateID=0 is correctly detected.

### Event 3 — Measure Gate + CPU Halt (QV.SINGLE, GateID=0x68)

vproc streams the MEASURE instruction (8 beats, cycle 94–101) and asserts `qvsg_meas`.  
Fetch and offload are blocked. The timed dispatcher fires the MEASURE pulse at `t_cnt=96`:

```
[AWG][t_cnt=96] valid_mask=0101010101010101
  qubit[00]  gate=0x68  role=CTRL
  qubit[02]  gate=0x68  role=CTRL
  qubit[04]  gate=0x68  role=CTRL
  qubit[06]  gate=0x68  role=CTRL
  qubit[08]  gate=0x68  role=CTRL
  qubit[10]  gate=0x68  role=CTRL
  qubit[12]  gate=0x68  role=CTRL
  qubit[14]  gate=0x68  role=CTRL
```

Then the testbench simulates 50-cycle ADC readout latency:

```
[cycle=102]  measure_issued_done=1  → CPU halted, waiting for ADC
[cycle=102]  ADC delay = 50 cycles
[cycle=153]  measure_done=1 (sent)  → mid-circuit measurement result received
[cycle=155]  qvsg_meas=0  → CPU resumes
```

### Event 4 — Post-Measure Resume Marker (QV.SINGLE, GateID=0x78)

Execution resumes immediately after `measure_done`. The resume instruction (from v2, odd qubits) fires:

```
[AWG][t_cnt=167] valid_mask=1010101010101010
  qubit[01]  gate=0x78  role=CTRL
  qubit[03]  gate=0x78  role=CTRL
  qubit[05]  gate=0x78  role=CTRL
  qubit[07]  gate=0x78  role=CTRL
  qubit[09]  gate=0x78  role=CTRL
  qubit[11]  gate=0x78  role=CTRL
  qubit[13]  gate=0x78  role=CTRL
  qubit[15]  gate=0x78  role=CTRL
```

`valid_mask=1010101010101010` — odd-numbered qubits (target group from v2), confirming the correct register and qubit mapping post-resume.

### Summary

```
[QDISP_TB] ===== CO-SIM SUMMARY =====
[QDISP_TB]  cycles         : 372
[QDISP_TB]  quantum events : 32
[QDISP_TB]  qubit fires    : 40
[QDISP_TB]  FIFO errors    : 0
[QDISP_TB]  RESULT         : PASS – no FIFO overflows
```

| t_cnt | valid_mask           | Gate   | Roles          | Description                    |
|-------|----------------------|--------|----------------|--------------------------------|
| 50    | `0101010101010101`   | `0x64` | all CTRL       | Hadamard on control qubits     |
| 73    | `1111111111111111`   | `0x00` | CTRL/TGT alternating | CNOT across all 8 pairs  |
| 96    | `0101010101010101`   | `0x68` | all CTRL       | Measure on control qubits      |
| 167   | `1010101010101010`   | `0x78` | all CTRL       | Resume marker on target qubits |

---

## Design Notations

### Simultaneous Firing via block_imm

Each quantum instruction encodes a `block_imm` field in bits `[11:7]` of the instruction word. The dispatcher computes:

```
dispatch_time = t_cnt_at_first_beat + block_imm
```

All beats of the same instruction share the same `dispatch_time`. For simultaneous firing, `block_imm` must be larger than the vector length (VL):

```
block_imm >= VL + 1
```

This demo uses `block_imm = 12`, `VL = 8`. The condition `12 >= 9` is satisfied, so all qubits in each instruction enter their time_controller WAIT state before `dispatch_time` arrives, and all fire at the same `t_cnt`.

### time_controller FSM

Each qubit has a dedicated `time_controller` that implements:

```
IDLE  →  WAIT  (FIFO non-empty)
WAIT  →  ISSUE (t_inst <= t_cnt + 1)
ISSUE →  IDLE  (one-cycle pulse on qubit_valid_o)
```

The `<=` condition (rather than strict `==`) ensures that qubits whose FIFOs were written late still fire promptly rather than missing the window permanently.

### GateID=0 Detection

`qubit_valid_o` is driven by the time_controller's ISSUE state pulse — not by checking whether `gate_output != 0`. This correctly handles the CNOT instruction whose GateID is `0x00`.

### Control / Target Role (`qubit_ctrl_o`)

For two-qubit gates (QV.PAIR), the dispatcher writes both the control qubit (from `quantum_elem1`, vector register v1) and the target qubit (from `quantum_elem2`, v2) to their respective FIFOs at the same `dispatch_time`. The stored FIFO word is `{role_bit, GateID}` (GATE_WIDTH+1 bits total). On readout:

```
qubit_gate_o[i]  = FIFO_data[GATE_WIDTH-1:0]   (GateID, unchanged)
qubit_ctrl_o[i]  = FIFO_data[GATE_WIDTH]        (1 = control, 0 = target)
```

For single-qubit gates (QV.SINGLE), only elem1 qubits are written, so `qubit_ctrl_o` is always 1.  
For QV.PAIR, even and odd qubits in each pair receive opposite role bits simultaneously, allowing the AWG to distinguish which physical line should apply the control pulse and which should receive the conditional flip.
### TODO:
[] add conditional logics based on the measurement input, rightnow we only simulate the waiting time
[] one bug:

MEASURE Halt-Resume Does Not Complete

With VL=4, the program is compact enough that Ibex issues all three quantum instructions — H, CX, and MEASURE — into vproc's queue within approximately 3 clock cycles. As a result, qvsg_meas asserts at cycle 31, roughly 63 cycles before the MEASURE element stream actually begins executing at cycle 94.

The measure_issued_done pulse is expected to fire after vproc finishes streaming the MEASURE instruction's elem1 entries. However, because MEASURE was enqueued so far ahead of its actual execution, the internal state machine's timing is disrupted and measure_issued_done never asserts. Without measure_issued_done, the testbench never sends measure_done, the CPU remains halted indefinitely, and the simulation exits via the 200-cycle idle timeout rather than through the normal resume path.

Root cause: The hardware measurement protocol assumes that the MEASURE instruction enters vproc's pipeline close to the time vproc is ready to execute it. The original Bell demo satisfies this constraint because VL=8 combined with several scalar instructions between quantum gates keeps Ibex from getting far ahead of vproc. With VL=4 and a per-batch program structure, Ibex races ahead and deep-queues MEASURE before vproc has finished executing the preceding gates, violating the implicit timing assumption of the halt-resume state machine.