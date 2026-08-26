# Bell-State Co-Simulation Tutorial

This tutorial explains the small Bell-state flow without defining ISA or verification policy. For encoding details see [`HiSEPQ_ISA_spec.md`](HiSEPQ_ISA_spec.md); for current evidence and checker limitations see [`verification.md`](verification.md).

## Algorithm

For each control/target pair `(q_c, q_t)`:

1. apply H to `q_c`;
2. apply CNOT with `q_c` as control and `q_t` as target;
3. measure the selected control qubits;
4. wait for backend completion and resume classical/vector execution.

The two supplied demos are:

| Image | Active pairs | Purpose |
|---|---:|---|
| `demo/bell_generic.mem` | 4 | small smoke and measurement flow |
| `demo/bell_8pair.mem` | 8 | larger reference stimulus |

## Program construction

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

After backend completion, software can read the latest result from custom CSR `0xCC0`; the authoritative result contract is in [`HiSEPQ_ISA_spec.md`](HiSEPQ_ISA_spec.md).


## Run

```bash
cd demo
./run.sh bell_generic
./run.sh bell_8pair
```

The log has two useful layers:

- `[QX]` records accepted/observed quantum element-stream beats;
- `[AWG]` records per-qubit dispatcher outputs and roles.

Do not rely only on the historical PASS banner. Check the expected event set against the contract in [`verification.md`](verification.md).

## Expected logical sequence

For `bell_generic`, the intended sequence is:

```text
QV.SINGLE(H)      controls [0, 2, 4, 6]
QV.PAIR(CNOT)     pairs [(0,1), (2,3), (4,5), (6,7)]
QV.SINGLE(MEAS)   controls [0, 2, 4, 6]
QV.SINGLE(marker) targets  [1, 3, 5, 7] after measurement completion
```

The measurement handshake should show:

```text
qvsg_meas_o rises
measure element stream drains
measure_issued_done_o pulses
testbench/backend asserts measure_done_i
qvsg_meas_o falls
post-measure marker appears
```

## Timing interpretation

The dispatcher uses a burst/commit design, so exact historical `t_cnt` values are not normative. The required property is that all selected qubits from one committed vector gate fire at the same intended `t_cnt`; see [`architecture.md`](architecture.md).

## Reference source files

The source/annotated Bell material remains under `qvproc_prj/tb/quantum_cases/bell_state_reference/`. Some files document legacy OP-V encodings; new programs should use the custom-0 encoding defined by the ISA specification.
