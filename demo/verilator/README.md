# Opcode simulator (Verilator)

This builds the HiSEP-Q testbench into a normal program with Verilator, so you
can run a `.mem` and get the opcode log **without Vivado**.

It runs the same testbench as `demo/run.sh` and prints the same log (the quantum
opcode stream and the per-qubit gate fires). It's meant as a fast, free way to
check what a program does (issue #4).

## What you need

- Verilator 5.x or newer  (needs `--binary` and `--timing`)
- a C++ compiler (`g++`)

Check it:

```bash
verilator --version
```

On Ubuntu/Debian: `sudo apt-get install verilator`.

## Build and run

The argument can be a case name, a name with `.mem`, or a path - all work
(e.g. `bell_generic`, `bell_generic.mem`, `../bell_generic.mem`).

```bash
cd demo/verilator
```
Shown with an Example in the following
- On a machine with verilator:
  - First time, or after changing the RTL source — build then run:
    `./run_verilator.sh mqtbench_qft_8`
  - After that, just run (no rebuild needed when you only change the .mem):
    `./run_verilator.sh --no-build mqtbench_qft_8`

- On another machine (no verilator needed):
  - Copy `obj_dir/sim_hisepq` AND the `.mem` files you want to run.
  - Must be the same OS/arch (x86_64 Linux).
  - Run with the full plusarg form:
    `./obj_dir/sim_hisepq +MEM_FILE=../mqtbench_qft_8.mem`
    (adjust the path to wherever you put the .mem)

## What the output means

- `[QX] ...`   one quantum instruction beat (op, qubit index, elem2/elem3, t_cnt)
- `[AWG][t_cnt=..] qubit[n] gate=0x.. role=..`   a gate actually fired on qubit n
- the summary at the end shows the event/fire counts and `PASS` if no FIFO overflow

## Notes

- The result matches Vivado xsim. The only difference is the `t_cnt` start value
  is off by 1 cycle (reset timing); the events and order are the same.
- Illegal programs (`qv_rot_v_illegal_m4/m8`) produce no quantum events, so they
  run to the cycle limit and stop. xsim does the same thing.
- First build takes a minute or two; after that runs are fast.
