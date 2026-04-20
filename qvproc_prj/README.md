# qvproc Vivado prj

This folder is a self-contained `version-0` snapshot of the current qvproc Vivado project. It includes the RTL, the Ibex-related sources, the testbenches, and the Tcl needed to rebuild the project on another machine.

## Folder layout

- `configs/`
- `core/`
- `rtl/`
- `tb/`

No absolute source paths are required by the rebuild flow. The folders can be moved as a whole and rebuilt from its new location.

## Rebuild the project

From the `qvproc_prj` root:

```bash
cd qvproc_prj
vivado -mode batch -source rebuild_project.tcl
```

This recreates the project at:

```text
build/qvproc/qvproc.xpr
```

Project settings restored by the Tcl:

- Part: `xcu55c-fsvh2892-2L-e`
- Board part: `xilinx.com:au55c:part0:1.0`
- Design top: `vproc_top`
- Simulation top: `vproc_qrv_mf2_direct_tb`

## Run the quantum test cases

The batch simulation Tcl is here:

- `tb/quantum_cases/run_quantum_case_batch.tcl`

Typical use from the `qvproc_prj` root:

```bash
cd qvproc_prj
QUANTUM_CASE=qsg vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=qpr vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=qrg vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=qrv vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
QUANTUM_CASE=bell vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
```

Supported values:

- `qsg`
- `qpr`
- `qrg`
- `qrv`
- `bell`

If `QUANTUM_CASE` is not set, the script defaults to `qpr`.

`bell` is a Bell-state preparation demo with the current `QSG.MEASURE`
halt-resume flow. It uses one `mf2, vl=8` setup and runs:

- `QV.SINGLE`
- `QV.PAIR`
- `QSG.MEASURE`
- one post-measure `QV.SINGLE` marker to prove resume

The associated files are:

- `tb/quantum_cases/vproc_bell_tb.v`
- `tb/quantum_cases/instruction_bell.mem`
- `tb/quantum_cases/data_bell.mem`
- `tb/quantum_cases/instruction_bell.text`

The script:

- opens the rebuilt `qvproc.xpr`
- switches the simulation top to the matching quantum testbench
- points XSim at the matching `instruction_*.mem` and `data_*.mem`

You can override the default memory files if needed:

```bash
cd qvproc_prj
QUANTUM_CASE=qrv \
QUANTUM_INSTR_FILE=/abs/path/to/instruction_qrv.mem \
QUANTUM_DATA_FILE=/abs/path/to/data_qrv.mem \
vivado -mode batch -source tb/quantum_cases/run_quantum_case_batch.tcl
```

## Quantum instruction summary

Common opcode for the four quantum vector instructions: `1010111`

| Instruction | `funct3` | Main operands | Purpose | Main note |
| --- | --- | --- | --- | --- |
| `QV.SINGLE` | `000` | `GateID`, `rs2(scalar)`, `vs1`, packed control word | Single-qubit gates such as `H`, `X`, `Y`, `Z`, `MEAS` | `elem2` exports the 32-bit scalar from `rs2`, `elem3` carries gate/control metadata |
| `QV.PAIR` | pair class | `vs2(src)`, `vs1(tgt)`, `Block_imm` | Two-qubit gates such as `CNOT`, `SWAP` | Source and target come from separate vectors |
| `QV.ROT.G` | `010` | `rs2(angle)`, `vs1(tgt)`, `Block_imm` | One scalar angle applied to many targets | Best treated as a dedicated scalar-angle form |
| `QV.ROT.V` | `011` | `vs2(angle)`, `vs1(tgt)`, `Block_imm` | Per-target variable rotation | Mixed-width instruction: `vs1=e8`, `vs2=e32` |

## Instruction notes

### QV.SINGLE

`QV.SINGLE` applies a single-qubit gate to the qubits described by `vs1`.

- `vs1` remains the vector of 8-bit target indices.
- Instruction bits `[24:20]` now select a normal scalar `rs2` register.
- The 32-bit contents of that scalar register are exported on the `elem2` channel.
- Gate/control metadata is exported on `elem3`.

Field layout:

- `[31:25]` `GateID`
- `[24:20]` `rs2(scalar)`
- `[19:15]` `vs1`

Exported `elem3` layout:

- `elem3[31:25]` `GateID`
- `elem3[11]` `m`
- `elem3[10:7]` `Block_imm[3:0]`

#### QSG MEASURE mode

`GateID = 7'h68` is reserved for `MEASURE`.

In the current implementation:

- `qvsg_meas` is asserted as soon as the active `QSG` decode is recognized as `MEASURE`.
- Ibex is expected to enter its normal interrupt path immediately after `qvsg_meas` becomes active.
- vproc is allowed to finish issuing the current `QSG-MEASURE` index stream on `elem1`.
- After that stream drains, `measure_issued_done` pulses high for 2 cycles.
- New offload work is blocked as soon as the measure becomes active, and later vector work is held behind the pause boundary until `measure_done` arrives.
- `measure_done` is an external top-level input from external ADC. When it is asserted, `qvsg_meas` is cleared and execution resumes.

Top-level measure signals:

- `qvsg_meas_o`
- `measure_issued_done_o`
- `measure_done_i`

The main design note for this flow is kept in:

- `docs/qsg_measure_spec.md`

### QV.PAIR

`QV.PAIR` applies a two-qubit gate to source/target pairs.

- `vs2` carries the source indices.
- `vs1` carries the target indices.
- `Block_imm` remains the scheduling/immediate field.

Field layout:

- `[31:25]` `Res`
- `[24:20]` `vs2(src)`
- `[19:15]` `vs1(tgt)`
- `[11:7]` `Block_imm`

### QV.ROT.G

`QV.ROT.G` rotates all targets listed in `vs1` by one scalar angle from `rs2` / `f_rs2`.

Field layout:

- `[31:25]` `Res`
- `[24:20]` `rs2(angle)`
- `[19:15]` `vs1(tgt)`
- `[11:7]` `Block_imm`

### QV.ROT.V

`QV.ROT.V` rotates each target in `vs1` by its own angle from `vs2`.

Field layout:

- `[31:25]` `Res`
- `[24:20]` `vs2(angle)`
- `[19:15]` `vs1(tgt)`
- `[11:7]` `Block_imm`

This instruction is mixed-width:

- `vs1` carries 8-bit qubit indices
- `vs2` carries 32-bit angle values

The current conservative hardware model treats:

- `op1` from `vs1` as `e8`
- `op2` from `vs2` as `e32`

## Programming example: Bell-state preparation

This example shows one simple software flow: write qubit indices into memory,
configure RVV, load the index vectors, then issue the quantum operations.

### Step 1: prepare data in memory

The control and target qubit groups are stored as packed 32-bit words. Each
word holds four 8-bit qubit indices in little-endian order.

- Control group `[0, 2, 4, 6]` -> `0x06040200`
- Target group `[1, 3, 5, 7]` -> `0x07050301`

```asm
# base address for the software-prepared index buffer
li      s0, 0x1000

# control indices [0, 2, 4, 6]
li      t0, 0x06040200
sw      t0, 0(s0)

# target indices [1, 3, 5, 7]
li      t1, 0x07050301
sw      t1, 4(s0)
```

### Step 2: configure the vector unit

For this example the active vector length is 4, with 8-bit elements and
`LMUL=m1`.

```asm
li      a0, 4
vsetvli t2, a0, e8, m1, ta, ma
```

The same pattern can be scaled to larger `vl` values up to `vlmax`, as long as
the register-group choice remains legal for the instruction being used.

### Step 3: load the index vectors

Standard RVV unit-stride loads are used to move the prepared indices into
vector registers.

```asm
vle8.v  v1, (s0)      # v1 = [0, 2, 4, 6]

addi    t1, s0, 4
vle8.v  v2, (t1)      # v2 = [1, 3, 5, 7]
```

### Step 4: issue the quantum operations

Using assembler-style mnemonics, the Bell-state sequence is:

```asm
# apply H to the control group
qv.h    v1, x0, 0

# apply CX with v1 as control and v2 as target
qv.cx   v2, v1, 0

# issue measurement on v1
li      t3, 0
qv.meas v1, t3, 0
```

Notes:

- `qv.h` and `qv.meas` lower to `QV.SINGLE` with different `GateID` values.
- In the current `QV.SINGLE` encoding, bits `[24:20]` select a normal scalar
  `rs2` register. If a gate does not need a payload, `x0` is a reasonable
  source. If measurement uses a timestamp or software tag later, that value
  should be placed in the selected GPR before issuing `qv.meas`.
- `qv.cx` lowers to `QV.PAIR`.
- The example above shows four parallel operations. The same structure can be
  extended to longer vectors by increasing `vl` and loading longer source
  arrays.

## QV.ROT.V LMUL mapping

Because the angle operand is 4x wider than the target-index operand, `vs2` consumes a larger register group than `vs1`.

| `vs1` setting | Effective `vs2` setting | 32-bit angle count |
| --- | --- | --- |
| `e8,mf2` | `e32,m2` | 8 |
| `e8,m1` | `e32,m4` | 16 |
| `e8,m2` | `e32,m8` | 32 |
| `e8,m4` | illegal | unsupported |
| `e8,m8` | illegal | unsupported |

## Compiler requirements and traps

### Requirements

- `QV.SINGLE` must allocate a normal scalar register for bits `[24:20]` and ensure that the 32-bit value carried there is the one intended to appear on `elem2`.
- `QV.PAIR` must keep `vs2(src)` and `vs1(tgt)` aligned element by element.
- `QV.ROT.G` should use a stable scalar register source for the angle operand, or at least be scheduled carefully against normal scalar traffic.
- `QV.ROT.V` must load its operands with different vector element widths:
  - `vle8` for `vs1`
  - `vle32` for `vs2`

### Traps

- `QV.ROT.V` does not follow the normal RVV assumption that both vector operands share one SEW/LMUL configuration.
- A `vsetvli` for `QV.ROT.V` mainly describes `vs1`; the effective `vs2` grouping must be inferred from the mixed-width rule.
- The compiler must check the scaled `vs2` register group, not just `vs1`, when looking for overlap with other live vector values.
- `m4` and `m8` on `vs1` would imply unsupported larger groups on `vs2`, so those cases should be rejected.
- `QV.SINGLE` still has one open architectural question: the vector form may overlap conceptually with a VLIW-style gate form, so the final encoding and compiler lowering should keep gate identification explicit.
- `Block_imm` is better treated as a scheduling field than a generic immediate. The code generator should have a clear policy for how this field is assigned.
- `vsetvli` 需要跟一条 nop

### Practical compiler policy

- For `QV.ROT.V`, start from the `vs1` configuration.
- Only allow `vs1` settings that map to a legal `vs2` group.
- Emit `vle8` for `vs1` and `vle32` for `vs2`.
- Reject any allocation where the expanded `vs2` group overlaps with another live vector register group.
- Keep the logical element counts matched:
  - `mf2` -> 8 angles
  - `m1` -> 16 angles
  - `m2` -> 32 angles

## To-do

- [x] Review the remaining `QV.ROT.V` issues and record the preferred fix direction. This should cover the startup invalid-window behavior, the valid/ready indicator, and whether the final fix belongs in the trace/export path or in the operand-prefetch path.
- [x] Revisit `QV.SINGLE` scalar-source conventions further if the `rs2`-based 32-bit payload should be reserved specifically for timestamps.
- [x] Define and implement the `MEASURE`-gate interrupt flow for `QV.SINGLE`. The current behavior and interface are recorded in `docs/qsg_measure_spec.md`.
