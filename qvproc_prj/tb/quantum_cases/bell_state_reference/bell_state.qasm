// =====================================================================
// bell_state.qasm -- 8 Bell pairs across qubits {0..15}
// =====================================================================
OPENQASM 2.0;
include "qelib1.inc";

qreg q[16];
creg c[8];

// Pair i = (q[2i], q[2i+1]),  i in {0..7}
H q[0];  H q[2];  H q[4];  H q[6];
H q[8];  H q[10]; H q[12]; H q[14];

CX q[0], q[1];   CX q[2],  q[3];   CX q[4],  q[5];   CX q[6],  q[7];
CX q[8], q[9];   CX q[10], q[11];  CX q[12], q[13];  CX q[14], q[15];

measure q[0]  -> c[0];
measure q[2]  -> c[1];
measure q[4]  -> c[2];
measure q[6]  -> c[3];
measure q[8]  -> c[4];
measure q[10] -> c[5];
measure q[12] -> c[6];
measure q[14] -> c[7];
