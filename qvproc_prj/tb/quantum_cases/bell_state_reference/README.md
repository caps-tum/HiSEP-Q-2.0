# Bell State Reference (HiSEP-Q 2.0)

Verified-good reference encoding for the 8-Bell-pair demo on the
`vproc_qdisp_bell_tb` co-simulation. Use these files as the canonical
mapping `QASM -> .s -> binary` for HiSEP-Q quantum extensions.

## Files

| File | Purpose |
|---|---|
| `bell_state.qasm`               | Source quantum program (8 Bell pairs) |
| `bell_state.s`                  | RVV + HiSEP-Q quantum extension assembly |
| `instruction_bell.mem`          | Hex machine code (`$readmemh` format), bit-identical to a clean assembly of `bell_state.s` |
| `instruction_bell_annotated.txt`| Same machine code with field-by-field decode of every word |
| `data_bell.mem`                 | Qubit-index data memory (`$readmemh`) |
| `data_bell_annotated.txt`       | Data memory with byte-by-byte decode |

## Cosim verification

Running `vproc_qdisp_bell_tb` with these files produces:

```
quantum events : 32     (H8 + CNOT8 + MEAS8 + RESUME8)
qubit fires    : 40
FIFO errors    : 0
RESULT         : PASS - no FIFO overflows
```

Full halt-resume cycle is observed:
`qvsg_meas=1` -> `measure_done=1` (external) -> `qvsg_meas=0` -> resume
events drain.

## Why these files succeed where `bell_4pair_generic_machine_code.txt` failed

The original `.s` (`bell_state_generic_qasm_only.s`) had four structural
bugs that this reference fixes:

1. **`vsetvli` clobbered `x7`**
   - Old: `vsetvli t2, a0, ...`  (`t2` == `x7`, overwrites the gate tag set
     two lines earlier)
   - New: `vsetvli x0, x5, ...`  (discard VL into `x0`, leave `x7` intact)

2. **`LMUL=m1 + AVL=4`** -> `VL=4`, but `vlmax(m1)=16`
   - The MEASURE element budget is tied to LMUL, so VL != vlmax
     desynchronises halt-resume.
   - New: `mf2 + AVL=8` -> `VL = vlmax = 8`.

3. **Per-batch `vsetvli + vle` repeated three times**
   - Adds ~30 cycles of Ibex-side commit traffic that arrive at vproc
     before vproc has executed the previous batch.
   - `qvsg_meas` latches well before MEASURE actually issues, so the
     resume marker is dropped.
   - New: single setup, four quantum ops back-to-back.

4. **No resume marker after MEASURE**
   - Without `qv.single(resume) ..., x6, ...` (gate ID `0x78`), the halt
     state machine never returns to RUNNING.
   - New: explicit `F0610657` after MEASURE.

## Encoding cheat-sheet (HiSEP-Q quantum ops, opcode `0x57`)

| Field | Bits  | Meaning |
|---|---|---|
| opcode    | `[6:0]`   | `1010111` = `0x57` (RVV OP-V) |
| vd        | `[11:7]`  | Vector destination (also reused for `block_imm`) |
| funct3    | `[14:12]` | `000` for fixed gate ops |
| vs1       | `[19:15]` | Control qubit vector |
| vs2 / rs2 | `[24:20]` | SINGLE/MEAS: scalar reg index (gate tag); PAIR: target qubit vector |
| vm        | `[25]`    | Must be `0` |
| gate ID   | `[31:25]` | `0x64` H, `0x66` CNOT, `0x68` MEASURE, `0x78` resume marker |

## Running the cosim

The combined-format equivalent of these split `.mem` files lives in
`demo/bell_8pair.mem` at the repo root. The simplest way to run the
canonical Bell demo is:

```bash
cd demo
./run.sh bell_8pair
```

If you specifically want to load the split-format files in *this* folder
(via the legacy `INSTR_MEM_FILE` / `DATA_MEM_FILE` plusargs which the
testbench still accepts), first build the snapshot once with
`./run.sh bell_8pair`, then from `demo/`:

```bash
xsim vproc_qdisp_bell_tb_sim --runall \
    --testplusarg "INSTR_MEM_FILE=../qvproc_prj/tb/quantum_cases/bell_state_reference/instruction_bell.mem" \
    --testplusarg "DATA_MEM_FILE=../qvproc_prj/tb/quantum_cases/bell_state_reference/data_bell.mem"
```

The split files here are byte-identical to the originals at
`../instruction_bell.mem` + `../data_bell.mem` (which the legacy
`vproc_bell_tb` testbench loads by default).
