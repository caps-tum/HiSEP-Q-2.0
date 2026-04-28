# Auto-generated HiSEP-Q assembly for mqtbench_bell_8
# Source: mqtbench_bell_8.qasm
# Batches: 3, max VL: 8

.text
.globl _start
_start:
    addi x6, x0, 0x66        # resume tag
    addi x7, x0, 0x55        # gate tag
    addi x5, x0, 8             # AVL
    vsetvli x0, x5, e8, mf2, ta, ma
    lui  a0, 0x1             # data base = 0x1000
    vle8.v v1, (a0)         # v1 <- ctrl qubits
    qv.h     v3, v1, x7, 12    # H x8
    addi x7, x0, 0x55      # refresh gate tag
    addi a0, a0, 8
    vle8.v v1, (a0)         # v1 <- ctrl qubits
    addi a1, a0, 8
    vle8.v v2, (a1)         # v2 <- tgt qubits
    qv.cx    v3, v1, v2, 12    # CNOT x8
    addi x7, x0, 0x55      # refresh gate tag
    addi a0, a0, 16
    vle8.v v1, (a0)         # v1 <- ctrl qubits
    qv.meas  v3, v1, x7, 12    # MEAS x8
    qv.single resume, v6, v1, x6, 12   # resume marker
    jal x0, 0
