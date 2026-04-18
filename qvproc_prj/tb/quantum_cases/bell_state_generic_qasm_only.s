.data
L0_h_idx:
    .word 0x06040200    # bytes [0, 2, 4, 6]
L1_cx_ctrl:
    .word 0x06040200    # bytes [0, 2, 4, 6]
L2_cx_tgt:
    .word 0x07050301    # bytes [1, 3, 5, 7]
L3_meas_idx:
    .word 0x06040200    # bytes [0, 2, 4, 6]

.text
.globl _start
_start:
    li      x7, 0x00000055

# ---- Batch 0: SINGLE ----
# direct qubit indices: [0, 2, 4, 6]
    li      a0, 4
    vsetvli t2, a0, e8, m1, ta, ma
    nop
    la      a1, L0_h_idx
    vle8.v  v1, (a1)
    qv.h     v3, v1, x7, 0

# ---- Batch 1: PAIR ----
# control qubits: [0, 2, 4, 6]
# target qubits:  [1, 3, 5, 7]
    li      a0, 4
    vsetvli t2, a0, e8, m1, ta, ma
    nop
    la      a1, L1_cx_ctrl
    vle8.v  v1, (a1)
    la      a2, L2_cx_tgt
    vle8.v  v2, (a2)
    qv.cx    v3, v1, v2, 0

# ---- Batch 2: SINGLE ----
# direct qubit indices: [0, 2, 4, 6]
    li      a0, 4
    vsetvli t2, a0, e8, m1, ta, ma
    nop
    la      a1, L3_meas_idx
    vle8.v  v1, (a1)
    qv.meas  v3, v1, x7, 0
# note: current RTL has halt-resume MEASURE, but no classical result readback instruction yet
# requested QASM destinations: c[0], c[1], c[2], c[3]

    jal     x0, 0

# End of demo program