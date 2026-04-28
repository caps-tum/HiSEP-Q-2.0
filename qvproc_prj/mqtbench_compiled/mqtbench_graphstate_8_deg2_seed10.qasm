OPENQASM 3.0;
include "stdgates.inc";

qubit[8] q;
bit[8] c;

// MQTBench family: graphstate, num_qubits=8, degree=2, seed=10
// GraphStateGate is decomposed into H layers and CZ edges; each CZ is lowered as H-CX-H.
h q[0];
h q[1];
h q[2];
h q[3];
h q[4];
h q[5];
h q[6];
h q[7];

h q[2];
cx q[0], q[2];
h q[2];
h q[5];
cx q[0], q[5];
h q[5];
h q[4];
cx q[1], q[4];
h q[4];
h q[5];
cx q[1], q[5];
h q[5];
h q[6];
cx q[2], q[6];
h q[6];
h q[6];
cx q[3], q[6];
h q[6];
h q[7];
cx q[3], q[7];
h q[7];
h q[7];
cx q[4], q[7];
h q[7];

measure q[0] -> c[0];
measure q[1] -> c[1];
measure q[2] -> c[2];
measure q[3] -> c[3];
measure q[4] -> c[4];
measure q[5] -> c[5];
measure q[6] -> c[6];
measure q[7] -> c[7];
