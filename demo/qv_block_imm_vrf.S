# Directed test QW-001: quantum instructions must not touch the vector register file
# through custom-0 bits [11:7] (block_imm, formerly vd).
#
# e8, m4, VL = 8 (16 qubits). Index tables in .data: A = 0..7, B = 8..15.
#   Part C: RESET on v4 (A) with block_imm 3 (not aligned to the m4 group); v0 <- B;
#           RESET on v0 with block_imm 3. The second RESET must fire on B: it must wait
#           for the load. The first RESET used to clear the pending writes of the m4 group
#           that holds v3 (v0..v3) when it completed, so the second could read v0 early.
#   Part A: v8 <- B; v4 <- A; H on v4 with block_imm 8; X on v8.
#           The X must fire on B (v8 not overwritten by the H).
#   Part B: v0 <- B; Z on v4 with block_imm 0; H on v0.
#           The H must fire on B (v0 not overwritten by the Z).
# On every qubit a later gate has a lead no smaller than the earlier one's, so no qubit gets
# two gates at one dispatch time. Expected fires: demo/qv_block_imm_vrf.expect.
# Build (toolchain of ../third_party):
#   riscv-none-elf-gcc -march=rv32im_zve32x -mabi=ilp32 -nostdlib -nostartfiles \
#     -Wl,-Ttext=0 -Wl,-Tdata=0x1000 qv_block_imm_vrf.S -o qv_block_imm_vrf.elf
#   RISCV_OBJCOPY=riscv-none-elf-objcopy ./elf2mem.sh qv_block_imm_vrf.elf qv_block_imm_vrf.mem
#   .insn r opcode, funct3, funct7 (GateID), rd (block_imm), rs1 (vs1), rs2
    .text
    .globl _start
_start:
    addi  x5, x0, 8
    vsetvli x0, x5, e8, m4, ta, ma
    lui   a0, 0x1                       # A at 0x1000
    addi  a1, a0, 16                    # B at 0x1010
    # Part C
    vle8.v v4, (a0)
    .insn r 0x0b, 0, 0x73, x3, x4, x0   # RESET on v4 (A), block_imm 3
    vle8.v v0, (a1)
    .insn r 0x0b, 0, 0x73, x3, x0, x0   # RESET on v0: expect B
    # Part A
    vle8.v v8, (a1)
    vle8.v v4, (a0)
    .insn r 0x0b, 0, 0x64, x8, x4, x0   # H on v4 (A), block_imm 8
    .insn r 0x0b, 0, 0x70, x0, x8, x0   # X on v8: expect B
    # Part B
    vle8.v v0, (a1)
    .insn r 0x0b, 0, 0x72, x0, x4, x0   # Z on v4 (A), block_imm 0
    .insn r 0x0b, 0, 0x64, x0, x0, x0   # H on v0: expect B
1:  jal   x0, 1b

    .data
    .byte 0, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0
    .byte 8, 9, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0
