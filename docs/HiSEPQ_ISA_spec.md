# HiSEP-Q ISA Specification v2.0 (Vector Extension)

> **Status**: This is the authoritative ISA document. It reflects the custom-0
> encoding and the current working tree as of August 2026. Features not yet
> implemented are marked with `[TODO]`; verification gaps and acceptance
> requirements are tracked in [`verification.md`](verification.md).

---

## 1 Introduction

The HiSEP-Q extension leverages the RISC-V Vector (RVV) architecture to efficiently control
intermediate-scale quantum processors. By decoupling physical qubit addressing from the instruction
stream using vector registers, this ISA supports high code density, scalable qubit parallelism, and
mixed-precision rotation operations.

All four quantum instructions use the RISC-V **custom-0** major opcode `0001011` and are
decoded by the vector co-processor (qvproc) through the CORE-V XIF interface. Classical control
flow and scalar operations remain on the Ibex scalar core using standard RISC-V instructions.
Vector configuration and memory access (`vsetvli`, `vle8.v`, `vle32.v`) still use the standard
RVV encodings — only the quantum gate instructions live in the custom opcode.

> **Migration note (RFC #3):** earlier revisions of this ISA squatted in the RVV `OP-V` opcode
> `1010111`, distinguishing the quantum instructions via unused `funct6`/`funct3` code points.
> To avoid collisions with future standard vector extensions and to obtain a private, contiguous
> encoding space, the quantum instructions were moved to the `custom-0` opcode. The legacy
> `OP-V` encodings are still accepted by the current RTL during the transition (dual-decode).

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

The `Block_imm` field (instruction bits `[11:7]`) is a **5-bit scheduling/metadata field**
occupying the R-type `rd` slot (quantum instructions do not write back to a `rd` register).
It is exported as part of `elem3` and is used by the programmer to carry a software-defined tag
(e.g., a timestamp, circuit layer ID, or measurement token) to the quantum backend, and to
compute the per-qubit dispatch time. It does **not** perform address translation in the current RTL.

```
elem3[11:7] = Block_imm[4:0]
```

> **Note:** the standalone mask bit `m` that previously occupied bit `[11]` has been removed;
> the full `[11:7]` field is now a single 5-bit immediate (RFC #3 / custom-0 migration).

> **Scheduling transition:** the original dispatcher interpreted this as an
> offset from the first stream beat. That failed for long streams. The current
> working tree accumulates one instruction and creates
> `dispatch_time = t_cnt_at_flush + offset` only when a different instruction ID
> arrives or the pending stream reaches the idle-flush threshold. The core
> large-VL race is resolved, while repeated-index and flush-bound semantics
> still require definition and directed tests; see
> [`docs/architecture.md`](architecture.md). The 5-bit field is an offset,
> not a 5-bit absolute timestamp.

> **[TODO]** A hierarchical addressing extension is planned:
> ```
> Physical Qubit ID = (Block_imm × 128) + Vector Element[6:0]
> ```
> This would allow a single instruction to address up to 128 qubits within a 128-qubit block,
> and the 5-bit `Block_imm` would select among up to 32 blocks (4096 qubits total).
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

All four quantum instructions use the **custom-0** opcode `0001011`. The `funct3` field
distinguishes the instruction class (`000`=QV.SINGLE, `001`=QV.PAIR, `010`=QV.ROT.G,
`011`=QV.ROT.V). The `funct7` / `GateID` field identifies the gate type within each class.

| `funct3` | Class       | `funct7` usage                 |
|----------|-------------|--------------------------------|
| `000`    | `QV.SINGLE` | GateID (H=`0x64`, MEASURE=`0x68`, resume=`0x78`) |
| `001`    | `QV.PAIR`   | GateID (CNOT=`0x66`)           |
| `010`    | `QV.ROT.G`  | reserved (`0`)                 |
| `011`    | `QV.ROT.V`  | reserved (`0`)                 |

---

#### `QV.SINGLE` — Single-Qubit Gate

Applies a single-qubit gate to the qubits listed in `vs1`. The 32-bit scalar payload from `rs2`
is forwarded to the quantum backend on the `elem2` channel (e.g., as a software tag or timestamp).

```
 31      25   24    20   19    15   14  12   11     7   6       0
+---------+----------+----------+--------+----------+---------+
|  GateID |   rs2    |  vs1 (S) | 000(S) | Block_imm | 0001011 |
+---------+----------+----------+--------+----------+---------+
```

**Exported signals per active element:**
- `elem1` — 8-bit qubit index from `vs1`
- `elem2` — 32-bit scalar from `rs2`
- `elem3[31:25]` — GateID; `elem3[11:7]` — Block_imm (5-bit)

<!-- **Implemented GateIDs:**

| GateID   | Mnemonic    | Status         |
|----------|-------------|----------------|
| `7'h64`  | `qv.h`      | Implemented    |
| `7'h68`  | `qv.meas`   | Implemented (see Section 5) |
| `7'h78`  | Resume marker | Implemented (post-measure placeholder) | -->

> **[TODO]** The following standard gates are not yet assigned fixed GateIDs in the decoder:
<!-- > `X` (`NOT`), `Y`, `Z`. The legacy placeholder funct6 space (`7'h78`/`7'h79`) is reserved -->
<!-- > for exploratory use during development. -->

> **[TODO]** Mask Mode: a future variant where `vs1` contains a dense bitmask (bit `j` targets
> qubit `j`) rather than an index list. Currently only Index Mode is implemented. The dedicated
> `m` mode bit at `[11]` was removed in the custom-0 migration; a future Mask Mode would need to
> reclaim an encoding point (e.g., a `funct7` GateID range or a `funct3` value).

---

#### `QV.PAIR` — Two-Qubit Gate

Applies a two-qubit gate to element-wise pairs from `vs2` (source/control) and `vs1` (target).

```
 31      25   24    20   19    15   14  12   11     7   6       0
+---------+----------+----------+--------+----------+---------+
|  GateID | vs2(src) | vs1(tgt) | 001(P) | Block_imm | 0001011 |
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
|   Res   | rs2(ang) | vs1(tgt) | 010(gr)| Block_imm | 0001011 |
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
|   Res   | vs2(ang) | vs1(tgt) | 011(vr)| Block_imm | 0001011 |
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

## 5 Measurement and Result CSR

`QV.SINGLE` with `GateID = 7'h68` (`qv.meas`) is the measurement operation.
It emits exactly the active `VL` qubit indices and creates an execution barrier:

1. the active measurement element stream is allowed to finish;
2. younger offload/quantum work cannot cross the measurement boundary;
3. execution remains paused until the backend reports completion;
4. the supplied 32-bit result is captured and execution resumes.

Software reads the latest result from read-only custom CSR `0xCC0` using a
standard CSR instruction such as `csrr`. A later measurement overwrites the
previous word. The result-bit mapping is defined by the software/backend
convention; the processor does not reinterpret the word.

The current interface supports one outstanding measurement and one 32-bit
result word. Multiple outstanding requests, a general result queue, and
speculative execution across the measurement boundary are not defined.

Signal-level timing, the two-cycle issued indication, Ibex interrupt handling,
and the vproc drain boundary are microarchitecture details specified in
[`../qvproc_prj/docs/qsg_measure_spec.md`](../qvproc_prj/docs/qsg_measure_spec.md).

---

## 6 Programming Example: Bell-State Preparation

A four-pair Bell program uses control indices `[0, 2, 4, 6]`, target indices
`[1, 3, 5, 7]`, `SEW=8`, `LMUL=m1`, and `VL=4`. After loading the two index
vectors, the quantum sequence is:

```asm
qv.h    v3, v1, x7, 0    # H on all control qubits
qv.cx   v3, v1, v2, 0    # element-wise control/target pairs
qv.meas v3, v1, x7, 0    # measure controls and enter halt/resume flow
qv.h    v6, v2, x6, 0    # post-measure marker used by the demo
```

The complete annotated program, memory packing, vector setup, simulation
commands, and expected logical sequence are maintained in
[`tutorial-bell.md`](tutorial-bell.md). That tutorial is explanatory; the
instruction encodings in this specification remain authoritative.

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

ISA-facing backlog items are listed here; cross-cutting verification gaps and acceptance criteria are maintained in [`verification.md`](verification.md):

- [ ] Assign fixed GateIDs for gates and implement decoder entries.
<!-- - [ ] Implement `SWAP` gate in `QV.PAIR`. -->
- [ ] Implement Mask Mode for `QV.SINGLE` (needs a new encoding point; the old `m` bit at `[11]`
      was reclaimed by the 5-bit `Block_imm` in the custom-0 migration).
- [ ] Integrate hierarchical addressing: `Qidx = Block_imm × 128 + Vector Element[6:0]`
- [ ] Enumerate all `QV.ROT.V` register-group conflict cases.
- [ ] Investigate `QV.ROT.V` startup invalid-window behavior and define valid/ready contract.
- [ ] Support for multiple outstanding measurement commands.
