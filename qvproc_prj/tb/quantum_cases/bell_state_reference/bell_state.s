// =====================================================================
// bell_state.s -- HiSEP-Q 2.0 reference assembly for 8 Bell pairs
//
// Implements:
//   for i in 0..7:
//       H q[2i]
//       CX q[2i] -> q[2i+1]
//       MEASURE q[2i] -> c[i]
//
// Key fixes vs. earlier `bell_state_generic_qasm_only.s`:
//   1. vsetvli rd is x0 (do NOT clobber x7, which holds the gate tag)
//   2. LMUL = mf2 with AVL = 8 so VL = vlmax = 8 (halt-resume budget OK)
//   3. Single setup (one vsetvli + two vle8.v) before all quantum gates
//   4. Resume marker (qv.single resume) added after MEASURE so qvsg_meas
//      gets cleared and the per-qubit timed FIFOs can drain
// =====================================================================

.data
ctrl_qubits:                                 // 8 bytes loaded into v1
    .word 0x06040200                         //   q[0, 2, 4, 6]
    .word 0x0E0C0A08                         //   q[8, 10, 12, 14]
tgt_qubits:                                  // 8 bytes loaded into v2
    .word 0x07050301                         //   q[1, 3, 5, 7]
    .word 0x0F0D0B09                         //   q[9, 11, 13, 15]

.text
.globl _start
_start:
    // ---- scalar tag registers ----
    addi    x6, x0, 0x66                     // resume tag (used by F0... marker)
    addi    x7, x0, 0x55                     // gate tag   (used by qv.h, qv.meas)

    // ---- vector configuration: AVL=8, e8, mf2 -> VL = vlmax = 8 ----
    addi    x5, x0, 8                        // x5 = AVL = 8
    vsetvli x0, x5, e8, mf2, ta, ma          // rd=x0 so x7 stays intact
    nop

    // ---- single qubit-vector setup (used by all 4 quantum ops) ----
    lui     a0, 0x1                          // a0 = 0x00001000
    vle8.v  v1, (a0)                         // v1 <- ctrl qubits [0..14 even]
    addi    a1, a0, 8                        // a1 = 0x00001008
    vle8.v  v2, (a1)                         // v2 <- tgt qubits [1..15 odd]

    // ---- back-to-back quantum operations (no per-batch reload!) ----
    qv.h     v3, v1, x7, 12                  // 8 x H gates on v1
    qv.cx    v3, v1, v2, 12                  // 8 x CNOTs (v1[i] -> v2[i])
    qv.meas  v3, v1, x7, 12                  // 8 x MEASURE; asserts qvsg_meas, halts Ibex

    // ---- resume marker: clears halt after external measure_done ----
    qv.single resume, v6, v2, x6, 12         // 8 x 0x78 events drain the FIFOs

    jal     x0, 0                            // halt (self-loop)
