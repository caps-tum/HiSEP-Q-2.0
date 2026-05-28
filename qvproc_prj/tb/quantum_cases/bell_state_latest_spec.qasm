OPENQASM 3.0;
include "stdgates.inc";

qubit[8] q;
bit[4] c;

// Bell-state pattern from the April 2026 HiSEP-Q ISA spec:
// controls  = q[0], q[2], q[4], q[6]
// targets   = q[1], q[3], q[5], q[7]
h q[0], q[2], q[4], q[6];
cx q[0], q[1];
cx q[2], q[3];
cx q[4], q[5];
cx q[6], q[7];
measure q[0], q[2], q[4], q[6] -> c;
