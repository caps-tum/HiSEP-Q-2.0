# HiSEP-Q ISA Specification v2.0 (Vector Extension)

> **Status**: This document reflects the **currently implemented** RTL as of April 2026.
> Features not yet implemented are marked with `[TODO]`.

---

## 1 Introduction

The HiSEP-Q extension leverages the RISC-V Vector (RVV) architecture to efficiently control
intermediate-scale quantum processors. By decoupling physical qubit addressing from the instruction
stream using vector registers, this ISA supports high code density, scalable qubit parallelism, and
mixed-precision rotation operations.

All four quantum vector instructions share the standard RVV major opcode `1010111` (OP-V) and are
decoded by the vector co-processor (qvproc) through the CORE-V XIF interface. Classical control
flow and scalar operations remain on the Ibex scalar core using standard RISC-V instructions.

---

## 2 Addressing Mode

### 2.1 Current Implementation: Direct Index Mode

Qubit indices are stored as **8-bit unsigned integers** directly in vector registers (v0–v31).
Each active vector element contains one physical qubit index in the range `[0, 127]`.
The number of qubits processed per instruction is determined by the `vsetvli` configuration
(`SEW=8`, `LMUL`).

```
Physical Qubit ID = Vector Element[7:0]
```

The **MSB (bit 7)** of each element is currently unused and should be written as zero.

### 2.2 Block Immediate Field

The `Block_imm` field (instruction bits `[11:7]`) is a **4-bit scheduling/metadata field**.
In the current implementation it is exported as part of `elem3` and is used by the programmer
to carry a software-defined tag (e.g., a timestamp, circuit layer ID, or measurement token)
to the quantum backend. It does **not** perform address translation in the current RTL.

```
elem3[10:7] = Block_imm[3:0]
```

> **[TODO]** A hierarchical addressing extension is planned:
> ```
> Physical Qubit ID = (Block_imm × 128) + Vector Element[6:0]
> ```
> This would allow a single instruction to address up to 128 qubits within a 128-qubit block,
> and the 4-bit `Block_imm` would select among up to 16 blocks (2048 qubits total).
> The MSB (bit 7) of each vector element would then be reserved for masking or validity.

---

## 3 Register Usage

| Register Type      | Role           | Used by                        | Description                                                              |
|--------------------|----------------|--------------------------------|--------------------------------------------------------------------------|
| Vector (`SEW=8`)   | `v_target`     | `QV.SINGLE`, `QV.PAIR`, `QV.ROT.G`, `QV.ROT.V` | 8-bit qubit indices of target qubits.                |
| Vector (`SEW=8`)   | `v_source`     | `QV.PAIR`                      | 8-bit qubit indices of control/source qubits.                            |
| Vector (`SEW=32`)  | `v_angle`      | `QV.ROT.V`                     | Per-qubit 32-bit fixed-point rotation angles (one per element).          |
| Scalar (Integer)   | `rs2` (angle)  | `QV.ROT.G`                     | Global 32-bit fixed-point rotation angle applied uniformly to all targets.|
| Scalar (Integer)   | `rs2` (payload)| `QV.SINGLE`                    | 32-bit scalar tag or timestamp forwarded to the backend on `elem2`.      |
| Vector (`SEW=8`)   | `v_single`     | `QV.SINGLE` (Mask Mode)        | Dense bitmask buffer: bit `j` targets qubit `j`. **[TODO]**             |

> **Angle encoding**: Rotation angles are represented as **32-bit fixed-point** values in integer
> GPRs. The hardware treats the 32-bit payload as opaque and forwards it to the quantum backend
> via `elem2`; the backend is responsible for interpreting the fixed-point encoding into a physical
> rotation angle. The specific fixed-point format (e.g., Q16.16, or full-scale mapping to 2π) is
> a software/backend convention and should be documented at the system integration level.

---

## 4 ISA Specification

### 4.1 Classical Control

Standard RISC-V scalar instructions handle all classical control flow (branches, loops, memory
loads/stores). No custom scalar instructions are defined. Timing tags or scalar payloads are
loaded into integer GPRs using standard `li` / `addi` before issuing quantum vector instructions.

### 4.2 Vector Configuration and Memory

Standard RVV instructions are used without modification:

- `vsetvli` — configures `SEW`, `LMUL`, and active vector length (`VL`).
- `vle8.v` — unit-stride load into vector register (`SEW=8`).
- `vle32.v` — unit-stride load into vector register (`SEW=32`, used for angle operands in `QV.ROT.V`).

> **Implementation note**: A guard `nop` must be placed immediately after every `vsetvli`.
> The current RTL may reject a `vle8.v` that follows `vsetvli` too closely due to a
> one-cycle `vtype/vl` settling latency.

### 4.3 Quantum Vector Extension

All four quantum instructions use opcode `1010111` (OP-V). The `funct3` field distinguishes
the instruction class. The `funct7` / `GateID` field identifies the gate type within each class.

---

#### `QV.SINGLE` — Single-Qubit Gate

Applies a single-qubit gate to the qubits listed in `vs1`. The 32-bit scalar payload from `rs2`
is forwarded to the quantum backend on the `elem2` channel (e.g., as a software tag or timestamp).

```
 31      25   24    20   19    15   14  12   11     7   6       0
+---------+----------+----------+--------+----------+---------+
|  GateID |   rs2    |  vs1 (S) | 000(S) | Block_imm | 1010111 |
+---------+----------+----------+--------+----------+---------+
```

**Exported signals per active element:**
- `elem1` — 8-bit qubit index from `vs1`
- `elem2` — 32-bit scalar from `rs2`
- `elem3[31:25]` — GateID; `elem3[10:7]` — Block_imm; `elem3[11]` — mask bit `m`

<!-- **Implemented GateIDs:**

| GateID   | Mnemonic    | Status         |
|----------|-------------|----------------|
| `7'h64`  | `qv.h`      | Implemented    |
| `7'h68`  | `qv.meas`   | Implemented (see Section 5) |
| `7'h78`  | Resume marker | Implemented (post-measure placeholder) | -->

> **[TODO]** The following standard gates are not yet assigned fixed GateIDs in the decoder:
<!-- > `X` (`NOT`), `Y`, `Z`. The legacy placeholder funct6 space (`7'h78`/`7'h79`) is reserved -->
<!-- > for exploratory use during development. -->

> **[TODO]** Mask Mode (`m = 1`): `vs1` contains a dense bitmask where bit `j` targets qubit `j`.
> Currently only Index Mode (`m = 0`) is implemented.

---

#### `QV.PAIR` — Two-Qubit Gate

Applies a two-qubit gate to element-wise pairs from `vs2` (source/control) and `vs1` (target).

```
 31      25   24    20   19    15   14  12   11     7   6       0
+---------+----------+----------+--------+----------+---------+
|  GateID | vs2(src) | vs1(tgt) | 001(P) | Block_imm | 1010111 |
+---------+----------+----------+--------+----------+---------+
```

**Exported signals per active element:**
- `elem1` — 8-bit target qubit index from `vs1`
- `elem2` — 8-bit source qubit index from `vs2`
- `elem3` — GateID and Block_imm metadata

<!-- **Implemented GateIDs:**

| GateID   | Mnemonic    | Status         |
|----------|-------------|----------------|
| `7'h66`  | `qv.cx`     | Implemented    |

> **[TODO]** `SWAP` gate is specified but not yet assigned a GateID or implemented in the decoder. -->

---

#### `QV.ROT.G` — Global Rotation (Scalar Angle)

Applies the same rotation angle to all target qubits listed in `vs1`. The angle is read from
an **integer** scalar register `rs2`.

```
 31      25   24    20   19    15   14  12   11     7   6       0
+---------+----------+----------+--------+----------+---------+
|   Res   | rs2(ang) | vs1(tgt) | 010(gr)| Block_imm | 1010111 |
+---------+----------+----------+--------+----------+---------+
```

**Exported signals per active element:**
- `elem1` — 8-bit qubit index from `vs1`
- `elem2` — 32-bit scalar angle from `rs2`
- `elem3` — Block_imm metadata

> **Compiler note**: It is recommended to reserve a dedicated integer GPR for the `rs2` angle
> operand to avoid scheduling conflicts with normal scalar traffic. The ABI register `a5` or
> a callee-saved register is a reasonable candidate; verify against hazard control timing.

> **Angle encoding**: The rotation angle in `rs2` is a **32-bit fixed-point** value. The hardware
> forwards the full 32-bit payload to the quantum backend via `elem2` without interpretation;
> the backend converts the fixed-point value to a physical rotation angle. The fixed-point format
> (e.g., Q16.16 or a full-scale 2π mapping) is a system-level software convention.

> **[TODO]** The internal placeholder computation uses only `rs2[4:0]` as a shift amount for
> `rotl_elem`. This will be replaced by proper angle forwarding once the backend interface is
> finalized.

---

#### `QV.ROT.V` — Variable Rotation (Per-Element Angle)

Applies a per-qubit rotation angle to each target in `vs1`, with angles sourced from `vs2`.
This is a **mixed-width instruction**: `vs1` uses `SEW=8` (qubit indices) and `vs2` uses
`SEW=32` (rotation angles).

```
 31      25   24    20   19    15   14  12   11     7   6       0
+---------+----------+----------+--------+----------+---------+
|   Res   | vs2(ang) | vs1(tgt) | 011(vr)| Block_imm | 1010111 |
+---------+----------+----------+--------+----------+---------+
```

**Exported signals per active element:**
- `elem1` — 8-bit qubit index from `vs1`
- `elem2` — 32-bit angle from `vs2`
- `elem3` — Block_imm metadata

**LMUL constraints** (hardware-enforced):

The hardware always reads `vs1` at `SEW=8` and `vs2` at `SEW=32`. Because the angle operand
is 4× wider than the index operand, `vs2` consumes a 4× larger register group:

| `vs1` config  | Effective `vs2` config | Elements processed |
|---------------|------------------------|--------------------|
| `e8, mf2`     | `e32, m2`              | 8                  |
| `e8, m1`      | `e32, m4`              | 16                 |
| `e8, m2`      | `e32, m8`              | 32                 |
| `e8, m4`      | `e32, m16`             | **Illegal**        |
| `e8, m8`      | `e32, m32`             | **Illegal**        |

`m4` and `m8` on `vs1` are rejected by the hardware. The compiler must check that the
expanded `vs2` register group does not overlap with other live vector registers.

**Required load pair:**
```asm
vle8.v   vs1, (addr_index)   # load 8-bit qubit indices
vle32.v  vs2, (addr_angle)   # load 32-bit rotation angles
```

> **[TODO]** The `vs2` SEW mismatch is currently handled by the conservative hardcode approach
> (op1: 8-bit from vs1, op2: 32-bit from vs2). A future optimization may allow the hardware to
> infer the vs2 group automatically from the vsetvli configuration, reducing programmer burden.

> **[TODO]** Check for potential register-group conflicts: because the LMUL of `vs2` is set
> implicitly by the instruction, it may overlap with another live instruction's legal LMUL
> configuration. A full enumeration of conflict cases is pending.

---

## 5 Measurement: Halt-Resume Protocol (Hardware Design)

`QV.SINGLE` with `GateID = 7'h68` (`qv.meas`) is a special instruction that triggers a
hardware halt-resume sequence for mid-circuit measurement.

### 5.1 Top-Level Signals

| Signal                | Direction | Description                                                          |
|-----------------------|-----------|----------------------------------------------------------------------|
| `qvsg_meas_o`         | Output    | Asserted when a MEASURE instruction is active. Wired to Ibex interrupt. |
| `measure_issued_done_o` | Output  | Pulses high for **2 clock cycles** when the full `elem1` stream has been issued. |
| `measure_done_i`      | Input     | Asserted by the external quantum backend (ADC) when measurement is complete. |

### 5.2 Control Flow

1. `QV.SINGLE(Measure) (GateID=0x68)` is decoded → `qvsg_meas` asserts immediately.
2. New offload work from Ibex is blocked.
3. Ibex enters its native interrupt handler as soon as `qvsg_meas` becomes active.
4. qvproc continues draining the **current** MEASURE instruction's `elem1` index stream.
5. After all `elem1` entries are issued, `measure_issued_done` pulses for 2 cycles.
6. qvproc stalls at the queue-to-dispatch boundary; younger instructions cannot cross.
7. System waits for external `measure_done` assertion.
8. On `measure_done`: `qvsg_meas` clears, pause releases, both cores resume.

> **Timing rule**: Ibex stops early; qvproc stops late. This asymmetry is intentional:
> Ibex is interrupt-driven, while qvproc must finish issuing the in-flight MEASURE stream.

### 5.3 Element Budget per LMUL

The hardware tracks how many `elem1` entries belong to the active MEASURE instruction:

| LMUL  | Element budget |
|-------|---------------|
| `mf2` | 8             |
| `m1`  | 16            |
| `m2`  | 32            |
| `m4`  | 64            |
| `m8`  | 128           |

### 5.4 Current Scope Boundaries

The current implementation does **not** handle:
- Multiple outstanding measurement commands
- A general backend transaction queue
- Speculative overlap of post-measure scalar work
- Interrupt prioritization beyond existing Ibex behavior

---

## 6 Programming Example: Bell-State Preparation

This example demonstrates the complete workflow: initializing memory with qubit indices,
configuring the vector unit, and executing parallel quantum gates. The program prepares
4 Bell pairs across qubits [0,2,4,6] (control) and [1,3,5,7] (target).

### Step 1: Memory Initialization (Data Preparation)

Eight-bit qubit indices are packed four-per-word into 32-bit little-endian words and
written to memory before the vector unit is configured.

- Control group: qubits [0, 2, 4, 6] → packed hex `0x06040200` (little-endian)
- Target group:  qubits [1, 3, 5, 7] → packed hex `0x07050301` (little-endian)

```asm
# ── 1. Prepare Data in Memory ──────────────────────────────────────────────
# s0 = base address of the qubit-index buffer
li      s0, 0x1000

# Pack control indices [0, 2, 4, 6] into one 32-bit word (little-endian byte order:
# byte0=0x00, byte1=0x02, byte2=0x04, byte3=0x06).
# The assembler expands 'li' into lui/addi for 32-bit immediates.
li      t0, 0x06040200
sw      t0, 0(s0)           # Memory[0x1000..0x1003] = [0, 2, 4, 6]

# Pack target indices [1, 3, 5, 7] into one 32-bit word (little-endian byte order:
# byte0=0x01, byte1=0x03, byte2=0x05, byte3=0x07).
li      t1, 0x07050301
sw      t1, 4(s0)           # Memory[0x1004..0x1007] = [1, 3, 5, 7]
```

### Step 2: Vector Configuration

The vector unit is configured for 4 active elements of 8-bit width (SEW=8, LMUL=m1).
Two scalar tags are preloaded into integer GPRs so they can be forwarded to the backend
as 32-bit payloads on the `elem2` channel.

> The `vlmax` for this configuration is `VLEN × LMUL / SEW = 128 × 1 / 8 = 16`.
> Setting AVL=4 uses only the first 4 lanes. To use the full register width, set
> AVL=16, or increase LMUL (e.g., `e8, m4` gives vlmax=64 elements).

```asm
# ── 2. Configure Vector Unit ───────────────────────────────────────────────
# Preload scalar tags that will be forwarded on elem2 to the quantum backend.
# x7 (0x55) is used as the payload tag for the H gate and MEASURE stages.
# x6 (0x66) is used as the payload tag for the post-measure resume marker.
addi    x7, x0, 0x55

addi    x6, x0, 0x66

# Set Application Vector Length (AVL) = 4.
li      a0, 4

# Configure: SEW=8 (8-bit elements), LMUL=m1 (single register per group),
# tail-agnostic (ta), mask-agnostic (ma). Result VL is written to t2.
vsetvli t2, a0, e8, m1, ta, ma

# Guard NOP: the current RTL requires one cycle for vtype/vl to settle before
# the first vector memory instruction. Omitting this NOP may cause the
# following vle8.v to be rejected.
nop
```

### Step 3: Vector Load

Standard RVV unit-stride loads move the prepared indices from memory into vector registers.
Unit-stride loads do not accept immediate offsets, so the second address is computed
explicitly with `addi`.

```asm
# ── 3. Load Indices from Memory into Vector Registers ─────────────────────
# Set base pointer to the qubit-index buffer.
lui     a0, 0x1              # a0 = 0x1000

# Load control indices into v1.
# After load: v1 = [0, 2, 4, 6, -, -, -, -, ...]  (active lanes 0–3)
vle8.v  v1, (a0)

# Compute address of the target-index word (4 bytes past the control word).
addi    t1, a0, 4            # t1 = 0x1004

# Load target indices into v2.
# After load: v2 = [1, 3, 5, 7, -, -, -, -, ...]  (active lanes 0–3)
vle8.v  v2, (t1)
```

### Step 4: Quantum Execution

The three-instruction Bell-state sequence (H → CNOT → MEASURE) is issued as quantum
vector instructions. A post-measure marker confirms that execution resumes correctly
after the halt-resume handshake.

```asm
# ── 4. Execute Quantum Gates ───────────────────────────────────────────────

# Apply Hadamard gate to all 4 control qubits in v1 simultaneously.
# Encoding: QV.SINGLE with GateID=0x64.
# elem1 stream → [0, 2, 4, 6]  (qubit indices, one per cycle)
# elem2         → 0x00000055   (32-bit scalar payload from x7)
# Format: qv.h  vd, vs1, rs2, Block_imm
qv.h    v3, v1, x7, 0

# Apply CNOT gate: v1 is the control group, v2 is the target group.
# Pairs are matched element-wise: (v1[0],v2[0])=(0,1), (v1[1],v2[1])=(2,3), ...
# Encoding: QV.PAIR with GateID=0x66.
# elem1 stream → [0, 2, 4, 6]  (target qubit indices)
# elem2 stream → [1, 3, 5, 7]  (control qubit indices)
# Format: qv.cx vd, vs1(ctrl), vs2(tgt), Block_imm
qv.cx   v3, v1, v2, 0

# Measure all 4 control qubits in v1.
# Encoding: QV.SINGLE with GateID=0x68 (reserved MEASURE gate).
# This instruction triggers the halt-resume protocol:
#   1. qvsg_meas asserts → Ibex enters interrupt mode immediately.
#   2. qvproc drains the full elem1 stream: [0, 2, 4, 6].
#   3. measure_issued_done pulses for 2 cycles once the stream is drained.
#   4. qvproc stalls; no younger instruction crosses the pause boundary.
#   5. Execution resumes only after external measure_done is asserted.
# elem1 stream → [0, 2, 4, 6]  (qubit indices sent to the measurement backend)
# elem2         → 0x00000055   (scalar tag from x7, forwarded to backend)
# Format: qv.meas vd, vs1, rs2, Block_imm
qv.meas v3, v1, x7, 0

# Post-measure resume marker (not part of the Bell-state algorithm).
# This QV.SINGLE with GateID=0x78 is issued immediately after measure_done
# releases the stall, proving that qvproc correctly resumes execution.
# elem1 stream → [1, 3, 5, 7]  (target qubit indices from v2)
# elem2         → 0x00000066   (resume tag from x6)
qv.h    v6, v2, x6, 0

# Self-loop: program halts here after the resume marker retires.
jal     x0, 0
```

> **[TODO]** Measurement result readback into a GPR is not yet implemented.
> Currently, measurement outcomes are consumed by the external backend via the
> `elem1` index stream and the `measure_done` handshake. A future `fmr`-style
> instruction would allow per-qubit results to be read back into integer registers
> for use in classical feedback logic.

---

## 7 Compiler Requirements and Known Traps

### Requirements

- `QV.SINGLE`: allocate a normal integer GPR for `rs2[24:20]`; the 32-bit value in that
  register appears on `elem2` at the quantum backend.
- `QV.PAIR`: keep `vs2` (source) and `vs1` (target) element-aligned.
- `QV.ROT.G`: use a stable integer GPR for the angle; verify against scalar traffic hazards.
- `QV.ROT.V`: load operands with **two different element widths** (`vle8` for `vs1`,
  `vle32` for `vs2`); only `mf2`, `m1`, `m2` are legal on `vs1`.
- Always place a `nop` immediately after `vsetvli`.

### Known Traps

- `QV.ROT.V` does not follow the normal RVV assumption that both vector operands share one
  SEW/LMUL configuration. The compiler must treat `vs1` and `vs2` as independently sized.
- The expanded `vs2` register group for `QV.ROT.V` must be checked for overlap with other
  live vector register groups during register allocation.
- `m4` and `m8` on `vs1` for `QV.ROT.V` are hardware-illegal and must be rejected at
  compile time or assembly time.
- `Block_imm` is a scheduling/metadata field at the moment, using to indicate the Q_IMM instruction, not a general immediate. The code
  generator should have a clear policy for how this field is assigned (e.g., circuit layer
  counter, zero for single-layer programs).

---

## 8 Open Items

- [ ] Assign fixed GateIDs for gates and implement decoder entries.
<!-- - [ ] Implement `SWAP` gate in `QV.PAIR`. -->
- [ ] Implement Mask Mode (`m=1`) for `QV.SINGLE`.
- [ ] Integrate hierarchical addressing: `Qidx = Block_imm × 128 + Vector Element[6:0]`
- [ ] Implement measurement result readback from backend to GPR.
- [ ] Enumerate all `QV.ROT.V` register-group conflict cases.
- [ ] Investigate `QV.ROT.V` startup invalid-window behavior and define valid/ready contract.
- [ ] Support for multiple outstanding measurement commands.
