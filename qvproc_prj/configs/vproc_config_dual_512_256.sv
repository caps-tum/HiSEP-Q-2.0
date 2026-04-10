// Configuration details:
// - Vector register width: 512 bits
// - Vector pipelines:
//   * Pipeline 0: 256 bits wide, contains VLSU, VALU, VELEM
//     Uses 1 512-bit vreg read ports and write port 0
//   * Pipeline 1: 256 bits wide, contains VMUL, VSLD
//     Uses 2 512-bit vreg read ports and write port 0
// - Vector register file needs 4 read ports and 1 write ports

package vproc_config;

    import vproc_pkg::*;

    parameter vreg_type    VREG_TYPE                   = VREG_GENERIC;
    parameter int unsigned VREG_W                      = 512;
    parameter int unsigned VPORT_RD_CNT                = 4;
    parameter int unsigned VPORT_RD_W   [VPORT_RD_CNT] = '{default: VREG_W};
    parameter int unsigned VPORT_WR_CNT                = 1;
    parameter int unsigned VPORT_WR_W   [VPORT_WR_CNT] = '{default: VREG_W};

    parameter int unsigned PIPE_CNT                    = 2;
    parameter bit [UNIT_CNT-1:0] PIPE_UNITS [PIPE_CNT] = '{
        (UNIT_CNT'(1) << UNIT_LSU) | (UNIT_CNT'(1) << UNIT_ALU) | (UNIT_CNT'(1) << UNIT_ELEM), (UNIT_CNT'(1) << UNIT_MUL) | (UNIT_CNT'(1) << UNIT_SLD)
    };
    parameter int unsigned PIPE_W           [PIPE_CNT] = '{256, 256};
    parameter int unsigned PIPE_VPORT_CNT   [PIPE_CNT] = '{1, 2};
    parameter int unsigned PIPE_VPORT_IDX   [PIPE_CNT] = '{1, 2};
    parameter int unsigned PIPE_VPORT_WR    [PIPE_CNT] = '{0, 0};

    parameter int unsigned VLSU_QUEUE_SZ               = 4;
    parameter bit [VLSU_FLAGS_W-1:0] VLSU_FLAGS        = '0;
    parameter mul_type     MUL_TYPE                    = MUL_GENERIC;

    parameter int unsigned INSTR_QUEUE_SZ              = 2;
    parameter bit [BUF_FLAGS_W-1:0] BUF_FLAGS          = (BUF_FLAGS_W'(1) << BUF_DEQUEUE) | (BUF_FLAGS_W'(1) << BUF_VREG_PEND);

endpackage
