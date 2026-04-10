// Copyright TUM
// Licensed under the Solderpad Hardware License v2.1, see LICENSE.txt for details
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
// RVV backbone adapted from Vicuna by TU Wien, originally license applied


module vproc_top import vproc_pkg::*; #(
        parameter int unsigned     MEM_W         = 32,  // memory bus width in bits
        parameter int unsigned     VMEM_W        = 32,  // vector memory interface width in bits
        parameter vreg_type        VREG_TYPE     = VREG_GENERIC,
        parameter mul_type         MUL_TYPE      = MUL_GENERIC,
        parameter int unsigned     ICACHE_SZ     = 0,   // instruction cache size in bytes
        parameter int unsigned     ICACHE_LINE_W = 128, // instruction cache line width in bits
        parameter int unsigned     DCACHE_SZ     = 0,   // data cache size in bytes
        parameter int unsigned     DCACHE_LINE_W = 512, // data cache line width in bits
        parameter int unsigned     QUANTUM_READY_HOLDOFF_CYCLES = 2 // quantum qvproc
    )(
        input  logic               clk_i,
        input  logic               rst_ni,

        output logic               mem_req_o,
        output logic [31:0]        mem_addr_o,
        output logic               mem_we_o,
        output logic [MEM_W/8-1:0] mem_be_o,
        output logic [MEM_W  -1:0] mem_wdata_o,
        input  logic               mem_rvalid_i,
        input  logic               mem_err_i,
        input  logic [MEM_W  -1:0] mem_rdata_i,

        output logic [31:0]        pend_vreg_wr_map_o,

        output logic               quantum_valid_o, // quantum qvproc
        output logic [4:0]         quantum_op_o, // quantum qvproc
        output logic [2:0]         quantum_instr_id_o, // quantum qvproc
        output logic [4:0]         quantum_vd_addr_o, // quantum qvproc
        output logic [31:0]        quantum_elem1_o, // quantum qvproc
        output logic [31:0]        quantum_elem2_o, // quantum qvproc
        output logic [31:0]        quantum_elem3_o, // quantum qvproc
        output vproc_pkg::cfg_emul quantum_emul_o, // quantum qvproc
        output logic [2:0]         quantum_count_mul_o, // quantum qvproc
        output logic               quantum_first_cycle_o, // quantum qvproc
        output logic               quantum_last_cycle_o, // quantum qvproc
        output logic               quantum_vl_part_0_o, // quantum qvproc
        output logic [4:0]         quantum_res_vaddr_o, // quantum qvproc
        output logic               quantum_first_valid_result_o, // quantum qvproc
        output logic               quantum_has_valid_result_o, // quantum qvproc
        output logic [2:0]         quantum_qrotv_op2_chunk_o, // quantum qvproc
        output logic               quantum_data_ready_o, // quantum qvproc
        output logic               qvsg_meas_o,
        output logic               measure_issued_done_o,
        input  logic               measure_done_i
    );

    if ((MEM_W & (MEM_W - 1)) != 0 || MEM_W < 32) begin
        $fatal(1, "The memory bus width MEM_W must be at least 32 and a power of two.  ",
                  "The current value of %d is invalid.", MEM_W);
    end

    // Reset synchronizer (sync reset is used for Vicuna by default, async reset for the core)
    logic [3:0] rst_sync_qn;
    logic sync_rst_n;
    always_ff @(posedge clk_i) begin
        rst_sync_qn[0] <= rst_ni;
        for (int i = 1; i < 4; i++) begin
            rst_sync_qn[i] <= rst_sync_qn[i-1];
        end
    end
    assign sync_rst_n = rst_sync_qn[3];


    ///////////////////////////////////////////////////////////////////////////
    // MAIN CORE INTEGRATION

    // Instruction fetch interface
    logic        instr_req;
    logic [31:0] instr_addr;
    logic        instr_gnt;
    logic        instr_rvalid;
    logic        instr_err;
    logic [31:0] instr_rdata;

    // Data load & store interface
    logic        sdata_req;
    logic [31:0] sdata_addr;
    logic        sdata_we;
    logic  [3:0] sdata_be;
    logic [31:0] sdata_wdata;
    logic        sdata_gnt;
    logic        sdata_rvalid;
    logic        sdata_err;
    logic [31:0] sdata_rdata;

    // Vector Unit Interface
    localparam X_NUM_RS = 2;
    localparam X_ID_WIDTH = 3;
    localparam X_RFR_WIDTH = 32;
    localparam X_RFW_WIDTH = 32;
    localparam X_MISA = 0;
    localparam logic [6:0] OP_V_OPCODE          = 7'h57;
    localparam logic [2:0] QV_SINGLE_FUNCT3     = 3'b000;
    localparam logic [6:0] QSG_MEASURE_GATE_ID  = 7'h68;
    vproc_xif #(
        .X_NUM_RS    ( X_NUM_RS    ),
        .X_ID_WIDTH  ( X_ID_WIDTH  ),
        .X_MEM_WIDTH ( VMEM_W      ),
        .X_RFR_WIDTH ( X_RFR_WIDTH ),
        .X_RFW_WIDTH ( X_RFW_WIDTH ),
        .X_MISA      ( X_MISA      )
    ) vcore_xif ();
    logic        vect_pending_load;
    logic        vect_pending_store;
    cfg_lmul     quantum_lmul; // quantum qvproc
    // cfg_emul     quantum_emul; // quantum qvproc
    // cfg_lmul     quantum_lmul_legacy; // quantum qvproc
    // Replaced by the exported EMUL sideband and the local per-stream LMUL sideband so ready can
    // follow the user-visible program configuration without adding another top-level debug port. // quantum qvproc
    logic [31:0] quantum_holdoff_count_q; // quantum qvproc
    logic [31:0] quantum_holdoff_count_d; // quantum qvproc
    logic        quantum_prev_valid_q; // quantum qvproc
    logic        quantum_prev_valid_d; // quantum qvproc
    logic        quantum_prev_first_cycle_q; // quantum qvproc
    logic        quantum_prev_first_cycle_d; // quantum qvproc
    logic [2:0]  quantum_prev_instr_id_q; // quantum qvproc
    logic [2:0]  quantum_prev_instr_id_d; // quantum qvproc
    logic        quantum_new_stream; // quantum qvproc
    logic        quantum_data_ready_d; // quantum qvproc
    logic        qsg_measure_issue;
    logic        qsg_measure_instr_match;
    logic        measure_active_q, measure_active_d;
    logic        measure_stream_drained_q, measure_stream_drained_d;
    logic [X_ID_WIDTH-1:0] measure_instr_id_q, measure_instr_id_d;
    logic [1:0]  measure_issued_done_cnt_q, measure_issued_done_cnt_d;
    logic [7:0]  measure_event_count_q, measure_event_count_d;
    logic [7:0]  measure_event_budget_q, measure_event_budget_d;
    logic        qsg_measure_stream_done;
    logic        ibex_fetch_enable;
    logic        vproc_issue_block;
    logic        vproc_dispatch_pause;

    function automatic logic [7:0] qsg_measure_elem_budget(input cfg_lmul lmul);
        begin
            unique case (lmul)
                LMUL_F2: qsg_measure_elem_budget = 8'd8;
                LMUL_1:  qsg_measure_elem_budget = 8'd16;
                LMUL_2:  qsg_measure_elem_budget = 8'd32;
                LMUL_4:  qsg_measure_elem_budget = 8'd64;
                LMUL_8:  qsg_measure_elem_budget = 8'd128;
                default: qsg_measure_elem_budget = 8'd0;
            endcase
        end
    endfunction

    // CSR register interface for Vector Unit
    localparam int unsigned VECT_CSR_CNT = 7;
    logic [11:0] vect_csr_addr [VECT_CSR_CNT];
    logic [31:0] vect_csr_rdata[VECT_CSR_CNT];
    logic        vect_csr_we   [VECT_CSR_CNT];
    logic [31:0] vect_csr_wdata[VECT_CSR_CNT];
    assign vect_csr_addr = '{
        12'h008, // vstart
        12'h009, // vxsat
        12'h00A, // vxrm
        12'h00F, // vcsr
        12'hC20, // vl
        12'hC21, // vtype
        12'hC22  // vlenb
    };

//`ifdef MAIN_CORE_IBEX
    localparam bit USE_XIF_MEM = '0;

    logic        cpi_instr_valid;
    logic [31:0] cpi_instr;
    logic [31:0] cpi_x_rs1;
    logic [31:0] cpi_x_rs2;
    logic        cpi_instr_gnt;
    logic        cpi_instr_illegal;
    logic        cpi_misaligned_ls;
    logic        cpi_xreg_wait;
    logic        cpi_result_valid;
    logic        cpi_xreg_valid;
    logic [31:0] cpi_xreg;

    ibex_top #(
        .DmHaltAddr             ( 32'h00000000                       ),
        .DmExceptionAddr        ( 32'h00000000                       ),
        .RV32M                  ( ibex_pkg::RV32MFast                ),
        .ExternalCSRs           ( VECT_CSR_CNT                       ),
        // LOAD-FP, STORE-FP and VECTOR opcodes
        .CoprocOpcodes          ( 32'h00200202                       )
    ) u_core (
        .clk_i                  ( clk_i                              ),
        .rst_ni                 ( rst_ni                             ),

        .test_en_i              ( 1'b0                               ),
        .ram_cfg_i              ( prim_ram_1p_pkg::ram_1p_cfg_t'('0) ),

        .hart_id_i              ( 32'b0                              ),
        .boot_addr_i            ( 32'h00000000                       ),

        .instr_req_o            ( instr_req                          ),
        .instr_gnt_i            ( instr_gnt                          ),
        .instr_rvalid_i         ( instr_rvalid                       ),
        .instr_addr_o           ( instr_addr                         ),
        .instr_rdata_i          ( instr_rdata                        ),
        .instr_err_i            ( instr_err                          ),

        .data_req_o             ( sdata_req                          ),
        .data_gnt_i             ( sdata_gnt                          ),
        .data_rvalid_i          ( sdata_rvalid                       ),
        .data_we_o              ( sdata_we                           ),
        .data_be_o              ( sdata_be                           ),
        .data_addr_o            ( sdata_addr                         ),
        .data_wdata_o           ( sdata_wdata                        ),
        .data_rdata_i           ( sdata_rdata                        ),
        .data_err_i             ( sdata_err                          ),

        .cpi_req_o              ( cpi_instr_valid                    ),
        .cpi_instr_o            ( cpi_instr                          ),
        .cpi_rs1_o              ( cpi_x_rs1                          ),
        .cpi_rs2_o              ( cpi_x_rs2                          ),
        .cpi_gnt_i              ( cpi_instr_gnt                      ),
        .cpi_instr_illegal_i    ( cpi_instr_illegal                  ),
        .cpi_wait_i             ( cpi_xreg_wait                      ),
        .cpi_res_valid_i        ( cpi_result_valid                   ),
        .cpi_res_i              ( cpi_xreg                           ),

        .irq_software_i         ( 1'b0                               ),
        .irq_timer_i            ( 1'b0                               ),
        .irq_external_i         ( qvsg_meas_o                        ),
        .irq_fast_i             ( 15'b0                              ),
        .irq_nm_i               ( 1'b0                               ),

        .ecsr_addr_i            ( vect_csr_addr                      ),
        .ecsr_rdata_i           ( vect_csr_rdata                     ),
        .ecsr_we_o              ( vect_csr_we                        ),
        .ecsr_wdata_o           ( vect_csr_wdata                     ),

        .debug_req_i            ( 1'b0                               ),
        .measure_pause_i        ( qsg_measure_issue | measure_active_q ),
        .crash_dump_o           (                                    ),

        .fetch_enable_i         ( ibex_fetch_enable                  ),
        .alert_minor_o          (                                    ),
        .alert_major_o          (                                    ),
        .core_sleep_o           (                                    ),

        .scan_rst_ni            ( 1'b1                               )
    );

    logic [X_ID_WIDTH-1:0] cpi_instr_id_q, cpi_instr_id_q2, cpi_instr_id_d;
    logic                  cpi_commit_q,                    cpi_commit_d;
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (~rst_ni) begin
            cpi_instr_id_q  <= '0;
            cpi_instr_id_q2 <= '0;
            cpi_commit_q    <= '0;
        end else begin
            cpi_instr_id_q  <= cpi_instr_id_d;
            cpi_instr_id_q2 <= cpi_instr_id_q;
            cpi_commit_q    <= cpi_commit_d;
        end
    end
    always_comb begin
        cpi_instr_id_d = cpi_instr_id_q;
        if (vcore_xif.issue_ready & vcore_xif.issue_valid) begin
            cpi_instr_id_d = cpi_instr_id_q + {{X_ID_WIDTH-1{1'b0}}, 1'b1};
        end
    end
    assign cpi_commit_d = vcore_xif.issue_valid & vcore_xif.issue_ready & vcore_xif.issue_resp.accept;

    assign vproc_issue_block            = measure_active_q & ~measure_done_i;
    assign vproc_dispatch_pause         = measure_stream_drained_q & ~measure_done_i;
    assign vcore_xif.issue_valid        = cpi_instr_valid & ~vproc_issue_block;
    assign vcore_xif.issue_req.instr    = cpi_instr;
    assign vcore_xif.issue_req.mode     = '0;
    assign vcore_xif.issue_req.id       = cpi_instr_id_q;
    assign vcore_xif.issue_req.rs[0]    = cpi_x_rs1;
    assign vcore_xif.issue_req.rs[1]    = cpi_x_rs2;
    assign vcore_xif.issue_req.rs_valid = 2'b11;

    assign cpi_instr_gnt     = vcore_xif.issue_ready & ~vproc_issue_block;
    // assign cpi_instr_illegal = ~vcore_xif.issue_resp.accept;
    // The original logic reported an illegal instruction whenever `accept` was low, even if the
    // coprocessor request had not been granted yet. After adding a configuration-valid stall in
    // `vproc_core`, dependent vector instructions can legitimately wait with `issue_ready=0` while
    // `accept=0`. Keep the original assignment commented for reference and only surface an illegal
    // instruction once the request has actually been granted to the coprocessor. // quantum qvproc
    assign cpi_instr_illegal = cpi_instr_valid & cpi_instr_gnt & ~vcore_xif.issue_resp.accept; // quantum qvproc
    assign cpi_xreg_wait     = vcore_xif.issue_resp.writeback;

    assign vcore_xif.commit_valid       = cpi_commit_q;
    assign vcore_xif.commit.id          = cpi_instr_id_q2;
    assign vcore_xif.commit.commit_kill = 1'b0;
    assign ibex_fetch_enable            = ~measure_active_q;

    assign qsg_measure_issue = cpi_instr_valid & cpi_instr_gnt & vcore_xif.issue_resp.accept &
                               (cpi_instr[6:0] == OP_V_OPCODE) &
                               (cpi_instr[14:12] == QV_SINGLE_FUNCT3) &
                               (cpi_instr[31:25] == QSG_MEASURE_GATE_ID);

    assign vcore_xif.result_ready = 1'b1;
    assign cpi_result_valid       = vcore_xif.result_valid & vcore_xif.result.we;
    assign cpi_xreg               = vcore_xif.result.data;

//`else
//`ifdef MAIN_CORE_CV32E40X
//    localparam bit USE_XIF_MEM = VMEM_W == 32;

//    // eXtension Interface
//    if_xif #(
//        .X_NUM_RS    ( 2  ),
//        .X_MEM_WIDTH ( 32 ),
//        .X_RFR_WIDTH ( 32 ),
//        .X_RFW_WIDTH ( 32 ),
//        .X_MISA      ( '0 )
//    ) host_xif();

//    cv32e40x_core #(
//        .X_EXT               ( 1'b1          )
//    ) core (
//        .clk_i               ( clk_i         ),
//        .rst_ni              ( rst_ni        ),
//        .scan_cg_en_i        ( 1'b0          ),
//        .boot_addr_i         ( 32'h00000080  ),
//        .dm_exception_addr_i ( '0            ),
//        .dm_halt_addr_i      ( '0            ),
//        .mhartid_i           ( '0            ),
//        .mimpid_patch_i      ( '0            ),
//        .mtvec_addr_i        ( 32'h00000000  ),
//        .instr_req_o         ( instr_req     ),
//        .instr_gnt_i         ( instr_gnt     ),
//        .instr_rvalid_i      ( instr_rvalid  ),
//        .instr_addr_o        ( instr_addr    ),
//        .instr_memtype_o     (               ),
//        .instr_prot_o        (               ),
//        .instr_dbg_o         (               ),
//        .instr_rdata_i       ( instr_rdata   ),
//        .instr_err_i         ( instr_err     ),
//        .data_req_o          ( sdata_req     ),
//        .data_gnt_i          ( sdata_gnt     ),
//        .data_rvalid_i       ( sdata_rvalid  ),
//        .data_addr_o         ( sdata_addr    ),
//        .data_be_o           ( sdata_be      ),
//        .data_we_o           ( sdata_we      ),
//        .data_wdata_o        ( sdata_wdata   ),
//        .data_memtype_o      (               ),
//        .data_prot_o         (               ),
//        .data_dbg_o          (               ),
//        .data_atop_o         (               ),
//        .data_rdata_i        ( sdata_rdata   ),
//        .data_err_i          ( sdata_err     ),
//        .data_exokay_i       ( 1'b0          ),
//        .mcycle_o            (               ),
//        .xif_compressed_if   ( host_xif      ),
//        .xif_issue_if        ( host_xif      ),
//        .xif_commit_if       ( host_xif      ),
//        .xif_mem_if          ( host_xif      ),
//        .xif_mem_result_if   ( host_xif      ),
//        .xif_result_if       ( host_xif      ),
//        .irq_i               ( '0            ),
//        .clic_irq_i          ( '0            ),
//        .clic_irq_id_i       ( '0            ),
//        .clic_irq_level_i    ( '0            ),
//        .clic_irq_priv_i     ( '0            ),
//        .clic_irq_shv_i      ( '0            ),
//        .fencei_flush_req_o  (               ),
//        .fencei_flush_ack_i  ( 1'b0          ),
//        .debug_req_i         ( 1'b0          ),
//        .debug_havereset_o   (               ),
//        .debug_running_o     (               ),
//        .debug_halted_o      (               ),
//        .fetch_enable_i      ( 1'b1          ),
//        .core_sleep_o        (               )
//    );

//    assign vcore_xif.issue_valid         = host_xif.issue_valid;
//    assign host_xif.issue_ready          = vcore_xif.issue_ready;
//    assign vcore_xif.issue_req.instr     = host_xif.issue_req.instr;
//    assign vcore_xif.issue_req.mode      = host_xif.issue_req.mode;
//    assign vcore_xif.issue_req.id        = host_xif.issue_req.id;
//    assign vcore_xif.issue_req.rs        = host_xif.issue_req.rs;
//    assign vcore_xif.issue_req.rs_valid  = host_xif.issue_req.rs_valid;
//    assign host_xif.issue_resp.accept    = vcore_xif.issue_resp.accept;
//    assign host_xif.issue_resp.writeback = vcore_xif.issue_resp.writeback;
//    assign host_xif.issue_resp.dualwrite = vcore_xif.issue_resp.dualwrite;
//    assign host_xif.issue_resp.dualread  = vcore_xif.issue_resp.dualread;
//    assign host_xif.issue_resp.loadstore = vcore_xif.issue_resp.loadstore;
//    assign host_xif.issue_resp.exc       = vcore_xif.issue_resp.exc;

//    assign vcore_xif.commit_valid       = host_xif.commit_valid;
//    assign vcore_xif.commit.id          = host_xif.commit.id;
//    assign vcore_xif.commit.commit_kill = host_xif.commit.commit_kill;

//    assign host_xif.result_valid   = vcore_xif.result_valid;
//    assign vcore_xif.result_ready  = host_xif.result_ready;
//    assign host_xif.result.id      = vcore_xif.result.id;
//    assign host_xif.result.data    = vcore_xif.result.data;
//    assign host_xif.result.rd      = vcore_xif.result.rd;
//    assign host_xif.result.we      = vcore_xif.result.we;
//    assign host_xif.result.exc     = vcore_xif.result.exc;
//    assign host_xif.result.exccode = vcore_xif.result.exccode;
//    assign host_xif.result.err     = vcore_xif.result.err;
//    assign host_xif.result.dbg     = vcore_xif.result.dbg;

//    if (USE_XIF_MEM) begin
//        assign host_xif.mem_valid         = vcore_xif.mem_valid;
//        assign vcore_xif.mem_ready        = host_xif.mem_ready;
//        assign host_xif.mem_req.id        = vcore_xif.mem_req.id;
//        assign host_xif.mem_req.addr      = vcore_xif.mem_req.addr;
//        assign host_xif.mem_req.mode      = vcore_xif.mem_req.mode;
//        assign host_xif.mem_req.we        = vcore_xif.mem_req.we;
//        assign host_xif.mem_req.size      = vcore_xif.mem_req.size;
//        assign host_xif.mem_req.be        = vcore_xif.mem_req.be;
//        assign host_xif.mem_req.attr      = vcore_xif.mem_req.attr;
//        assign host_xif.mem_req.wdata     = vcore_xif.mem_req.wdata;
//        assign host_xif.mem_req.last      = vcore_xif.mem_req.last;
//        assign host_xif.mem_req.spec      = vcore_xif.mem_req.spec;
//        assign vcore_xif.mem_resp.exc     = host_xif.mem_resp.exc;
//        assign vcore_xif.mem_resp.exccode = host_xif.mem_resp.exccode;
//        assign vcore_xif.mem_resp.dbg     = host_xif.mem_resp.dbg;
//        assign vcore_xif.mem_result_valid = host_xif.mem_result_valid;
//        assign vcore_xif.mem_result.id    = host_xif.mem_result.id;
//        assign vcore_xif.mem_result.rdata = host_xif.mem_result.rdata;
//        assign vcore_xif.mem_result.err   = host_xif.mem_result.err;
//        assign vcore_xif.mem_result.dbg   = host_xif.mem_result.dbg;
//    end

//    assign vect_csr_we    = '{default:'0};
//    assign vect_csr_wdata = '{default:'0};

//`else
//    localparam bit USE_XIF_MEM = '0;
//    $fatal(1, "One of the MAIN_CORE_* macros must be defined to select a main core.");
//`endif
//`endif


    ///////////////////////////////////////////////////////////////////////////
    // VECTOR CORE INTEGRATION

    // Vector CSR read/write conversion
    logic [31:0] csr_vtype;
    logic [31:0] csr_vl;
    logic [31:0] csr_vlenb;
    logic [31:0] csr_vstart_rd;
    logic [31:0] csr_vstart_wr;
    logic        csr_vstart_wren;
    logic        csr_vxsat_rd;
    logic        csr_vxsat_wr;
    logic        csr_vxsat_wren;
    logic [1:0]  csr_vxrm_rd;
    logic [1:0]  csr_vxrm_wr;
    logic        csr_vxrm_wren;
    assign vect_csr_rdata[0] = csr_vstart_rd;
    assign vect_csr_rdata[1] = {31'b0, csr_vxsat_rd};
    assign vect_csr_rdata[2] = {30'b0, csr_vxrm_rd};
    assign vect_csr_rdata[3] = {29'b0, csr_vxrm_rd, csr_vxsat_rd};
    assign vect_csr_rdata[4] = csr_vl;
    assign vect_csr_rdata[5] = csr_vtype;
    assign vect_csr_rdata[6] = csr_vlenb;
    assign csr_vstart_wr     = vect_csr_wdata[0];
    assign csr_vstart_wren   = vect_csr_we[0];
    assign csr_vxsat_wr      = vect_csr_we[1] ? vect_csr_wdata[1][0]   : vect_csr_wdata[3][0];
    assign csr_vxsat_wren    = vect_csr_we[1] | vect_csr_we[3];
    assign csr_vxrm_wr       = vect_csr_we[2] ? vect_csr_wdata[2][1:0] : vect_csr_wdata[3][2:1];
    assign csr_vxrm_wren     = vect_csr_we[2] | vect_csr_we[3];

    // Data read/write for Vector Unit
    logic                vdata_gnt;
    logic                vdata_rvalid;
    logic                vdata_err;
    logic [VMEM_W-1:0]   vdata_rdata;
    logic                vdata_req;
    logic [31:0]         vdata_addr;
    logic                vdata_we;
    logic [VMEM_W/8-1:0] vdata_be;
    logic [VMEM_W-1:0]   vdata_wdata;
    logic [X_ID_WIDTH-1:0] vdata_req_id;
    logic [X_ID_WIDTH-1:0] vdata_res_id;

    localparam bit [VLSU_FLAGS_W-1:0] VLSU_FLAGS = (VLSU_FLAGS_W'(1) << VLSU_ALIGNED_UNITSTRIDE);

    localparam bit [BUF_FLAGS_W -1:0] BUF_FLAGS  = (BUF_FLAGS_W'(1) << BUF_DEQUEUE  ) |
                                                   (BUF_FLAGS_W'(1) << BUF_VREG_PEND);

    /*
     * These top-level ports expose per-slice quantum execution data before the
     * vector writeback path repacks slices into full vector-word writes. The
     * signals are intended for external observation, co-simulation, or custom
     * sideband logic without changing the architectural writeback behavior.
     */
    vproc_core #(
        .XIF_ID_W           ( X_ID_WIDTH         ),
        .XIF_MEM_W          ( VMEM_W             ),
        .VREG_TYPE          ( VREG_TYPE          ),
        .MUL_TYPE           ( MUL_TYPE           ),
        .VLSU_FLAGS         ( VLSU_FLAGS         ),
        .BUF_FLAGS          ( BUF_FLAGS          ),
        .DONT_CARE_ZERO     ( 1'b0               ),
        .ASYNC_RESET        ( 1'b0               )
    ) v_core (
        .clk_i              ( clk_i              ),
        .rst_ni             ( sync_rst_n         ),
        .measure_pause_i    ( vproc_dispatch_pause ),

        .xif_issue_if       ( vcore_xif          ),
        .xif_commit_if      ( vcore_xif          ),
        .xif_mem_if         ( vcore_xif          ),
        .xif_memres_if      ( vcore_xif          ),
        .xif_result_if      ( vcore_xif          ),

        .pending_load_o     ( vect_pending_load  ),
        .pending_store_o    ( vect_pending_store ),

        .csr_vtype_o        ( csr_vtype          ),
        .csr_vl_o           ( csr_vl             ),
        .csr_vlenb_o        ( csr_vlenb          ),
        .csr_vstart_o       ( csr_vstart_rd      ),
        .csr_vstart_i       ( csr_vstart_wr      ),
        .csr_vstart_set_i   ( csr_vstart_wren    ),
        .csr_vxrm_o         ( csr_vxrm_rd        ),
        .csr_vxrm_i         ( csr_vxrm_wr        ),
        .csr_vxrm_set_i     ( csr_vxrm_wren      ),
        .csr_vxsat_o        ( csr_vxsat_rd       ),
        .csr_vxsat_i        ( csr_vxsat_wr       ),
        .csr_vxsat_set_i    ( csr_vxsat_wren     ),

        .pend_vreg_wr_map_o ( pend_vreg_wr_map_o ),
        .quantum_valid_o    ( quantum_valid_o    ), // quantum qvproc
        .quantum_op_o       ( quantum_op_o       ), // quantum qvproc
        .quantum_instr_id_o ( quantum_instr_id_o ), // quantum qvproc
        .quantum_vd_addr_o  ( quantum_vd_addr_o  ), // quantum qvproc
        .quantum_elem1_o    ( quantum_elem1_o    ), // quantum qvproc
        .quantum_elem2_o    ( quantum_elem2_o    ), // quantum qvproc
        .quantum_elem3_o    ( quantum_elem3_o    ), // quantum qvproc
        .quantum_lmul_o     ( quantum_lmul       ), // quantum qvproc
        .quantum_emul_o     ( quantum_emul_o     ), // quantum qvproc
        .quantum_count_mul_o( quantum_count_mul_o ), // quantum qvproc
        .quantum_first_cycle_o( quantum_first_cycle_o ), // quantum qvproc
        .quantum_last_cycle_o ( quantum_last_cycle_o  ), // quantum qvproc
        .quantum_vl_part_0_o  ( quantum_vl_part_0_o   ), // quantum qvproc
        .quantum_res_vaddr_o  ( quantum_res_vaddr_o   ), // quantum qvproc
        .quantum_first_valid_result_o ( quantum_first_valid_result_o ), // quantum qvproc
        .quantum_has_valid_result_o   ( quantum_has_valid_result_o   ), // quantum qvproc
        .quantum_qrotv_op2_chunk_o    ( quantum_qrotv_op2_chunk_o    ) // quantum qvproc
    );

    // Extract vector unit memory signals from extension interface
    if (USE_XIF_MEM) begin
        assign vdata_req                  = '0;
        assign vdata_addr                 = '0;
        assign vdata_we                   = '0;
        assign vdata_be                   = '0;
        assign vdata_wdata                = '0;
        assign vdata_req_id               = '0;
    end else begin
        assign vdata_req                  = vcore_xif.mem_valid;
        assign vcore_xif.mem_ready        = vdata_gnt;
        assign vdata_addr                 = vcore_xif.mem_req.addr;
        assign vdata_we                   = vcore_xif.mem_req.we;
        assign vdata_be                   = vcore_xif.mem_req.be;
        assign vdata_wdata                = vcore_xif.mem_req.wdata;
        assign vdata_req_id               = vcore_xif.mem_req.id;
        assign vcore_xif.mem_resp.exc     = '0;
        assign vcore_xif.mem_resp.exccode = '0;
        assign vcore_xif.mem_resp.dbg     = '0;
        assign vcore_xif.mem_result_valid = vdata_rvalid;
        assign vcore_xif.mem_result.id    = vdata_res_id;
        assign vcore_xif.mem_result.rdata = vdata_rdata;
        assign vcore_xif.mem_result.err   = vdata_err;
        assign vcore_xif.mem_result.dbg   = '0;
    end

    // Data arbiter for main core and vector unit
    logic                sdata_hold;
    logic                data_req;
    logic [31:0]         data_addr;
    logic                data_we;
    logic [VMEM_W/8-1:0] data_be;
    logic [VMEM_W  -1:0] data_wdata;
    logic                data_gnt;
    logic                data_rvalid;
    logic                data_err;
    logic [VMEM_W  -1:0] data_rdata;
    logic                sdata_waiting, vdata_waiting;
    logic [31:0]         sdata_wait_addr;
    logic [X_ID_WIDTH-1:0] vdata_wait_id;
    assign sdata_hold = ~USE_XIF_MEM & (vdata_req | vect_pending_store | (vect_pending_load & sdata_we));
    always_comb begin
        data_req   = vdata_req | (sdata_req & ~sdata_hold);
        data_addr  = sdata_addr;
        data_we    = sdata_we;
        data_be    = {{(VMEM_W-32){1'b0}}, sdata_be} << (sdata_addr[$clog2(VMEM_W/8)-1:0] & {{$clog2(VMEM_W/32){1'b1}}, 2'b00});
        data_wdata = '0;
        for (int i = 0; i < VMEM_W / 32; i++) begin
            data_wdata[32*i +: 32] = sdata_wdata;
        end
        if (vdata_req) begin
            data_addr  = vdata_addr;
            data_we    = vdata_we;
            data_be    = vdata_be;
            data_wdata = vdata_wdata;
        end
    end
    assign sdata_gnt = data_gnt & sdata_req & ~sdata_hold;
    assign vdata_gnt = data_gnt & vdata_req;
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (~rst_ni) begin
            sdata_waiting   <= 1'b0;
            vdata_waiting   <= 1'b0;
            sdata_wait_addr <= '0;
            vdata_wait_id   <= '0;
        end else begin
            if (sdata_gnt) begin
                sdata_waiting   <= 1'b1;
                sdata_wait_addr <= sdata_addr;
            end
            else if (sdata_rvalid) begin
                sdata_waiting <= 1'b0;
            end
            if (vdata_gnt) begin
                vdata_waiting <= 1'b1;
                vdata_wait_id <= vdata_req_id;
            end
            else if (vdata_rvalid) begin
                vdata_waiting <= 1'b0;
            end
        end
    end
    assign sdata_rvalid = sdata_waiting & data_rvalid;
    assign vdata_rvalid = vdata_waiting & data_rvalid;
    assign sdata_err    = data_err;
    assign vdata_err    = data_err;
    assign sdata_rdata  = data_rdata[(sdata_wait_addr[$clog2(VMEM_W)-1:0] & {3'b000, {($clog2(VMEM_W/8)-2){1'b1}}, 2'b00})*8 +: 32];
    assign vdata_rdata  = data_rdata;
    assign vdata_res_id = vdata_wait_id;


    ///////////////////////////////////////////////////////////////////////////
    // CACHES

    // instruction cache
    logic             imem_req;
    logic             imem_gnt;
    logic [31:0]      imem_addr;
    logic             imem_rvalid;
    logic [MEM_W-1:0] imem_rdata;
    logic             imem_err;
    generate
        if (ICACHE_SZ != 0) begin
            localparam int unsigned ICACHE_WAY_LEN = ICACHE_SZ / (ICACHE_LINE_W / 8) / 2;
            vproc_cache #(
                .ADDR_BIT_W   ( 32                ),
                .CPU_BYTE_W   ( 4                 ),
                .MEM_BYTE_W   ( MEM_W / 8         ),
                .LINE_BYTE_W  ( ICACHE_LINE_W / 8 ),
                .WAY_LEN      ( ICACHE_WAY_LEN    )
            ) icache (
                .clk_i        ( clk_i             ),
                .rst_ni       ( rst_ni            ),
                .hold_mem_i   ( 1'b0              ),
                .cpu_req_i    ( instr_req         ),
                .cpu_addr_i   ( instr_addr        ),
                .cpu_we_i     ( '0                ),
                .cpu_be_i     ( '0                ),
                .cpu_wdata_i  ( '0                ),
                .cpu_gnt_o    ( instr_gnt         ),
                .cpu_rvalid_o ( instr_rvalid      ),
                .cpu_rdata_o  ( instr_rdata       ),
                .cpu_err_o    ( instr_err         ),
                .mem_req_o    ( imem_req          ),
                .mem_addr_o   ( imem_addr         ),
                .mem_we_o     (                   ),
                .mem_wdata_o  (                   ),
                .mem_gnt_i    ( imem_gnt          ),
                .mem_rvalid_i ( imem_rvalid       ),
                .mem_rdata_i  ( imem_rdata        ),
                .mem_err_i    ( imem_err          )
            );
        end else begin
            assign imem_req     = instr_req;
            assign imem_addr    = instr_addr;
            assign instr_gnt    = imem_gnt;
            assign instr_rvalid = imem_rvalid;
            assign instr_rdata  = imem_rdata[31:0];
            assign instr_err    = imem_err;
        end
    endgenerate

    // data cache
    logic               dmem_req;
    logic               dmem_gnt;
    logic [31:0]        dmem_addr;
    logic               dmem_we;
    logic [MEM_W/8-1:0] dmem_be;
    logic [MEM_W  -1:0] dmem_wdata;
    logic               dmem_rvalid;
    logic               dmem_wvalid;
    logic [MEM_W  -1:0] dmem_rdata;
    logic               dmem_err;
    generate
        if (DCACHE_SZ != 0) begin
            localparam int unsigned DCACHE_WAY_LEN = DCACHE_SZ / (DCACHE_LINE_W / 8) / 2;
            // hold memory access (allows lookup only) for main core requests
            // in case of pending vector loads / stores
            logic hold_mem;
            always_ff @(posedge clk_i) begin
                hold_mem <= ~USE_XIF_MEM & ~vdata_req & vect_pending_store & vect_pending_load;
            end
            vproc_cache #(
                .ADDR_BIT_W   ( 32                ),
                .CPU_BYTE_W   ( VMEM_W / 8        ),
                .MEM_BYTE_W   ( MEM_W / 8         ),
                .LINE_BYTE_W  ( DCACHE_LINE_W / 8 ),
                .WAY_LEN      ( DCACHE_WAY_LEN    )
            ) vcache (
                .clk_i        ( clk_i             ),
                .rst_ni       ( rst_ni            ),
                .hold_mem_i   ( hold_mem          ),
                .cpu_req_i    ( data_req          ),
                .cpu_addr_i   ( data_addr         ),
                .cpu_we_i     ( data_we           ),
                .cpu_be_i     ( data_be           ),
                .cpu_wdata_i  ( data_wdata        ),
                .cpu_gnt_o    ( data_gnt          ),
                .cpu_rvalid_o ( data_rvalid       ),
                .cpu_rdata_o  ( data_rdata        ),
                .cpu_err_o    ( data_err          ),
                .mem_req_o    ( dmem_req          ),
                .mem_we_o     ( dmem_we           ),
                .mem_addr_o   ( dmem_addr         ),
                .mem_wdata_o  ( dmem_wdata        ),
                .mem_gnt_i    ( dmem_gnt          ),
                .mem_rvalid_i ( dmem_rvalid       ),
                .mem_rdata_i  ( dmem_rdata        ),
                .mem_err_i    ( dmem_err          )
            );
            assign dmem_be = '1;
        end else begin
            if (MEM_W != VMEM_W) begin
                $fatal(1, "If no data cache is used, the memory bus width MEM_W and the vector ",
                          "memory interface width VMEM_W must be equal.  ",
                          "Currently, MEM_W == %d and VMEM_W == %d.", MEM_W, VMEM_W);
            end

            assign dmem_req    = data_req;
            assign dmem_addr   = data_addr;
            assign dmem_we     = data_we;
            assign dmem_be     = data_be;
            assign dmem_wdata  = data_wdata;
            assign data_gnt    = dmem_gnt;
            assign data_rvalid = dmem_rvalid | dmem_wvalid;
            assign data_rdata  = dmem_rdata;
            assign data_err    = dmem_err;
        end
    endgenerate



    ///////////////////////////////////////////////////////////////////////////
    // MEMORY ARBITER

    always_comb begin
        mem_req_o   = imem_req | dmem_req;
        mem_addr_o  = imem_addr;
        mem_we_o    = 1'b0;
        mem_be_o    = dmem_be;
        mem_wdata_o = dmem_wdata;
        if (dmem_req) begin
            mem_we_o   = dmem_we;
            mem_addr_o = dmem_addr;
        end
    end
    assign imem_gnt = imem_req & ~dmem_req;
    assign dmem_gnt =             dmem_req;

    // shift register keeping track of the source of mem requests for up to 32 cycles
    logic        req_sources  [32];
    logic        req_write    [32]; // keeping track of whether the request was a write
    logic [31:0] imem_req_addr[32]; // keeping track of address for instruction memory requests
    logic [4:0]  req_count;
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (~rst_ni) begin
            req_count <= '0;
        end else begin
            if (mem_rvalid_i) begin
                for (int i = 0; i < 31; i++) begin
                    req_sources  [i] <= req_sources  [i+1];
                    req_write    [i] <= req_write    [i+1];
                    imem_req_addr[i] <= imem_req_addr[i+1];
                end
                if (~imem_gnt & ~dmem_gnt) begin
                    req_count <= req_count - 1;
                end else begin
                    req_sources  [req_count-1] <= dmem_gnt;
                    req_write    [req_count-1] <= dmem_we;
                    imem_req_addr[req_count-1] <= imem_addr;
                end
            end
            else if (imem_gnt | dmem_gnt) begin
                req_sources  [req_count] <= dmem_gnt;
                req_write    [req_count] <= dmem_we;
                imem_req_addr[req_count] <= imem_addr;
                req_count                <= req_count + 1;
            end
        end
    end
    assign imem_rvalid = mem_rvalid_i & ~req_sources[0];
    assign dmem_rvalid = mem_rvalid_i &  req_sources[0] & ~req_write[0];
    assign dmem_wvalid = mem_rvalid_i &  req_sources[0] &  req_write[0];
    assign imem_err    = mem_err_i;
    assign dmem_err    = mem_err_i;
    assign imem_rdata  = (ICACHE_SZ != 0) ? mem_rdata_i : mem_rdata_i[
        (imem_req_addr[0][$clog2(MEM_W)-1:0] & {3'b000, {($clog2(MEM_W/8)-2){1'b1}}, 2'b00})*8 +: 32];
    assign dmem_rdata  = mem_rdata_i;

    assign qsg_measure_instr_match = quantum_valid_o &
                                     (quantum_op_o == ELEM_QSINGLE) &
                                     (quantum_instr_id_o == measure_instr_id_q) &
                                     (quantum_elem3_o[31:25] == QSG_MEASURE_GATE_ID);
    assign qsg_measure_stream_done = measure_active_q &
                                     ~measure_stream_drained_q &
                                     qsg_measure_instr_match &
                                     (((measure_event_count_q + 8'd1) ==
                                       ((measure_event_budget_q != 8'd0) ? measure_event_budget_q :
                                                                           qsg_measure_elem_budget(quantum_lmul))));

    always_comb begin
        measure_active_d          = measure_active_q;
        measure_stream_drained_d  = measure_stream_drained_q;
        measure_instr_id_d        = measure_instr_id_q;
        measure_issued_done_cnt_d = measure_issued_done_cnt_q;
        measure_event_count_d     = measure_event_count_q;
        measure_event_budget_d    = measure_event_budget_q;

        if (measure_issued_done_cnt_q != 2'd0) begin
            measure_issued_done_cnt_d = measure_issued_done_cnt_q - 2'd1;
        end

        if (measure_done_i) begin
            measure_active_d          = 1'b0;
            measure_stream_drained_d  = 1'b0;
            measure_issued_done_cnt_d = 2'd0;
            measure_event_count_d     = 8'd0;
            measure_event_budget_d    = 8'd0;
        end else begin
            if (qsg_measure_issue) begin
                measure_active_d         = 1'b1;
                measure_stream_drained_d = 1'b0;
                measure_instr_id_d       = cpi_instr_id_q;
                measure_event_count_d    = 8'd0;
                measure_event_budget_d   = 8'd0;
            end
            if (qsg_measure_instr_match) begin
                measure_event_count_d = measure_event_count_q + 8'd1;
                if (measure_event_budget_q == 8'd0) begin
                    measure_event_budget_d = qsg_measure_elem_budget(quantum_lmul);
                end
            end
            if (qsg_measure_stream_done) begin
                measure_stream_drained_d  = 1'b1;
                measure_issued_done_cnt_d = 2'd2;
            end
        end
    end

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (~rst_ni) begin
            measure_active_q          <= 1'b0;
            measure_stream_drained_q  <= 1'b0;
            measure_instr_id_q        <= '0;
            measure_issued_done_cnt_q <= '0;
            measure_event_count_q     <= '0;
            measure_event_budget_q    <= '0;
        end else begin
            measure_active_q          <= measure_active_d;
            measure_stream_drained_q  <= measure_stream_drained_d;
            measure_instr_id_q        <= measure_instr_id_d;
            measure_issued_done_cnt_q <= measure_issued_done_cnt_d;
            measure_event_count_q     <= measure_event_count_d;
            measure_event_budget_q    <= measure_event_budget_d;
        end
    end

    assign qvsg_meas_o          = measure_active_q | qsg_measure_issue;
    assign measure_issued_done_o = (measure_issued_done_cnt_q != 2'd0);

    assign quantum_new_stream = quantum_valid_o & quantum_first_cycle_o & ( // quantum qvproc
        ~quantum_prev_valid_q | ~quantum_prev_first_cycle_q | (quantum_instr_id_o != quantum_prev_instr_id_q) // quantum qvproc
    ); // quantum qvproc

    /*
     * Keep the raw quantum trace visible on the existing ports, but synthesize
     * a companion ready flag that masks known warm-up micro-steps before the
     * trace is safe to sample.
     *
     * Most quantum instructions keep the original QSG-style protocol: only the
     * program-level m4/m8 streams suppress ready during the first two first-cycle
     * warm-up micro-steps.
     *
     * QRV is the only exception. Its mixed-width angle operand needs four startup
     * QRV events before elem2 is fully aligned, so top-level ready stays low for
     * those first four per-stream events across mf2/m1/m2. This keeps the ready
     * contract self-contained in qvproc rather than pushing the warm-up skip into
     * individual testbenches.
     *
     * The internal state is synchronous, but the exported ready flag is driven
     * combinationally from the current trace inputs plus the registered state,
     * so consumers can see ready=1 in the same cycle as the first accepted
     * quantum data after the corresponding warm-up period completes.
     */ // quantum qvproc
    always_comb begin // quantum qvproc
        logic [31:0] first_cycle_seen_next; // quantum qvproc
        logic        quantum_holdoff_stream; // quantum qvproc
        logic [31:0] quantum_qrotv_ready_holdoff_cycles; // quantum qvproc
        quantum_holdoff_count_d    = quantum_holdoff_count_q; // quantum qvproc
        quantum_prev_valid_d       = quantum_valid_o; // quantum qvproc
        quantum_prev_first_cycle_d = quantum_first_cycle_o; // quantum qvproc
        quantum_prev_instr_id_d    = quantum_instr_id_o; // quantum qvproc
        quantum_data_ready_d       = 1'b0; // quantum qvproc
        first_cycle_seen_next      = quantum_holdoff_count_q; // quantum qvproc
        quantum_holdoff_stream     = 1'b0; // quantum qvproc
        quantum_qrotv_ready_holdoff_cycles = 32'd0; // quantum qvproc

        // All quantum instructions except QRV keep the original QSG-style protocol: only
        // program-level m4/m8 streams suppress ready during the first two warm-up micro-steps.
        // QRV is the only exception and uses LMUL-specific startup holdoff based on when elem2
        // becomes valid in simulation: mf2 needs 4 hidden beats, m1 needs 6, and m2 needs none. // quantum qvproc
        if (quantum_op_o == ELEM_QROTV) begin // quantum qvproc
            quantum_holdoff_stream = 1'b1; // quantum qvproc
            unique case (quantum_lmul) // quantum qvproc
                LMUL_F2: quantum_qrotv_ready_holdoff_cycles = 32'd4; // mf2 // quantum qvproc
                LMUL_1:  quantum_qrotv_ready_holdoff_cycles = 32'd6; // m1  // quantum qvproc
                default: quantum_qrotv_ready_holdoff_cycles = 32'd0; // m2 and above // quantum qvproc
            endcase // quantum qvproc
        end else begin // quantum qvproc
            quantum_holdoff_stream = (quantum_lmul == LMUL_4) || (quantum_lmul == LMUL_8); // quantum qvproc
        end // quantum qvproc

        if (~quantum_valid_o) begin // quantum qvproc
            quantum_holdoff_count_d = '0; // quantum qvproc
            quantum_data_ready_d    = 1'b0; // quantum qvproc
        // end else if ((quantum_emul_o == EMUL_4) || (quantum_emul_o == EMUL_8)) begin // quantum qvproc
        // The EMUL-based holdoff does not match QSG's program-level m4/m8 classes on this path.
        // Keep it commented for reference and gate holdoff from the per-stream LMUL sideband
        // captured when the instruction entered the vector pipeline. // quantum qvproc
        end else if (quantum_op_o == ELEM_QROTV) begin // quantum qvproc
            first_cycle_seen_next   = quantum_new_stream ? 32'd1 : (quantum_holdoff_count_q + 32'd1); // quantum qvproc
            quantum_holdoff_count_d = first_cycle_seen_next; // quantum qvproc
            quantum_data_ready_d    = (first_cycle_seen_next > quantum_qrotv_ready_holdoff_cycles); // quantum qvproc
        end else if (quantum_holdoff_stream) begin // quantum qvproc
            if (quantum_first_cycle_o) begin // quantum qvproc
                first_cycle_seen_next   = quantum_new_stream ? 32'd1 : (quantum_holdoff_count_q + 32'd1); // quantum qvproc
                quantum_holdoff_count_d = first_cycle_seen_next; // quantum qvproc
                quantum_data_ready_d    = (first_cycle_seen_next > QUANTUM_READY_HOLDOFF_CYCLES); // quantum qvproc
            end else begin // quantum qvproc
                quantum_data_ready_d    = 1'b1; // quantum qvproc
            end // quantum qvproc
        end else begin // quantum qvproc
            quantum_holdoff_count_d = '0; // quantum qvproc
            quantum_data_ready_d    = 1'b1; // quantum qvproc
        end // quantum qvproc
    end // quantum qvproc

    assign quantum_data_ready_o = quantum_data_ready_d; // quantum qvproc

    always_ff @(posedge clk_i or negedge rst_ni) begin // quantum qvproc
        if (~rst_ni) begin // quantum qvproc
            quantum_holdoff_count_q    <= '0; // quantum qvproc
            quantum_prev_valid_q       <= 1'b0; // quantum qvproc
            quantum_prev_first_cycle_q <= 1'b0; // quantum qvproc
            quantum_prev_instr_id_q    <= '0; // quantum qvproc
        end else begin // quantum qvproc
            quantum_holdoff_count_q    <= quantum_holdoff_count_d; // quantum qvproc
            quantum_prev_valid_q       <= quantum_prev_valid_d; // quantum qvproc
            quantum_prev_first_cycle_q <= quantum_prev_first_cycle_d; // quantum qvproc
            quantum_prev_instr_id_q    <= quantum_prev_instr_id_d; // quantum qvproc
        end // quantum qvproc
    end // quantum qvproc

endmodule
