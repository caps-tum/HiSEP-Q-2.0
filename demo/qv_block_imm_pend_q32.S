# Directed test QW-001, pending-write part (32 qubits): a quantum instruction must not clear
# the pending writes of an unrelated load when it completes. Same pattern as the d=5 surface
# loop with scheduling leads (ftqc/loop_sim, SURF_PHYS_SCHED), traced on the dual config:
#   e8, m2, index group v2..v3. RESET on v2 = A (VL 25) with block_imm 3; v2 <- B (VL 24);
#   RESET on v2 with block_imm 3. The second RESET must fire on B.
#   Before the fix the first RESET's completion bulk-cleared the pending writes of the m2
#   group holding v3 (v2..v3), i.e. those of the load; the second RESET read v2 before the
#   load wrote it and fired on A[0..15] (0..7 appear, which B does not hold).
# A = 0..24, B = 8..31. Expected fires: demo/qv_block_imm_pend_q32.expect.
# Build as demo/qv_block_imm_vrf.S.
    .text
    .globl _start
_start:
    lui   a0, 0x1                       # A at 0x1000
    addi  a1, a0, 32                    # B at 0x1020
    addi  x5, x0, 25
    vsetvli x0, x5, e8, m2, ta, ma
    vle8.v v2, (a0)
    .insn r 0x0b, 0, 0x73, x3, x2, x0   # RESET on v2 (A), block_imm 3
    addi  x5, x0, 24
    vsetvli x0, x5, e8, m2, ta, ma
    vle8.v v2, (a1)
    .insn r 0x0b, 0, 0x73, x3, x2, x0   # RESET on v2: expect B
1:  jal   x0, 1b

    .data
    .byte 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
    .byte 16, 17, 18, 19, 20, 21, 22, 23, 24, 0, 0, 0, 0, 0, 0, 0
    .byte 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23
    .byte 24, 25, 26, 27, 28, 29, 30, 31
