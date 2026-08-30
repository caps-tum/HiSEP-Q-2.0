`timescale 1ns / 1ps
//
// Dispatcher-integrated simulation/synthesis wrapper.
//   u_vproc : Ibex + vproc and raw quantum stream
//   u_qdisp : per-qubit timed gate scheduler
//
// An internal free-running t_cnt counter (TIME_WIDTH bits) resets together
// with the rest of the design and is shared with quantum_dispatcher.
//
// All vproc_top memory and measure-handshake ports are exposed at the top
// level so the testbench can drive them exactly as it did before.
//
// Quantum stream wires are also exposed as outputs so the testbench can
// observe the raw qvproc stream alongside the per-qubit dispatcher outputs.

module vproc_qdisp_top
    import vproc_pkg::*;
#(
    // vproc_top parameters
    parameter MEM_W         = 32,
    parameter VMEM_W        = 32,

    // quantum_dispatcher parameters
    parameter NUM_QUBITS    = 8,
    parameter FIFO_DEPTH    = 8,
    parameter TIME_WIDTH    = 20,
    parameter GATE_WIDTH    = 7,
    parameter BLOCK_IMM_W   = 5,
    // Flush-relative default offset when block_imm is zero.
    parameter FIXED_LATENCY = 16
)(
    input  wire                              clk,
    input  wire                              rst,        // active-high

    // ------------------------------------------------------------------
    // Memory interface  (pass-through to vproc_top)
    // ------------------------------------------------------------------
    output wire                              mem_req_o,
    output wire [31:0]                       mem_addr_o,
    output wire                              mem_we_o,
    output wire [MEM_W/8-1:0]               mem_be_o,
    output wire [MEM_W-1:0]                  mem_wdata_o,
    input  wire                              mem_rvalid_i,
    input  wire                              mem_err_i,
    input  wire [MEM_W-1:0]                  mem_rdata_i,

    // ------------------------------------------------------------------
    // Measure handshake  (pass-through)
    // ------------------------------------------------------------------
    input  wire                              measure_done_i,
    input  wire [31:0]                       measure_result_i,
    output wire                              qvsg_meas_o,
    output wire                              measure_issued_done_o,

    // ------------------------------------------------------------------
    // Raw quantum stream  (observe in TB without touching vproc_top)
    // ------------------------------------------------------------------
    output wire                              quantum_valid_o,
    output wire [4:0]                        quantum_op_o,
    output wire [2:0]                        quantum_instr_id_o,
    output wire [4:0]                        quantum_vd_addr_o, // legacy diagnostic; not a custom-0 vd
    output wire [31:0]                       quantum_elem1_o,
    output wire [31:0]                       quantum_elem2_o,
    output wire [31:0]                       quantum_elem3_o,
    // quantum_emul_o intentionally not exposed: cfg_emul type incompatible
    // with plain Verilog wires; connect internally below.
    output wire [2:0]                        quantum_count_mul_o,
    output wire                              quantum_first_cycle_o,
    output wire                              quantum_last_cycle_o,
    output wire                              quantum_vl_part_0_o,
    output wire [4:0]                        quantum_res_vaddr_o,
    output wire                              quantum_data_ready_o,
    output wire                              quantum_first_valid_result_o,
    output wire                              quantum_has_valid_result_o,

    // ------------------------------------------------------------------
    // Per-qubit dispatcher outputs
    // ------------------------------------------------------------------
    output wire [GATE_WIDTH*NUM_QUBITS-1:0]  qubit_gate_o,
    output wire [NUM_QUBITS-1:0]             qubit_valid_o,
    output wire [NUM_QUBITS-1:0]             qubit_error_o,
    output wire [NUM_QUBITS-1:0]             qubit_ctrl_o,
    output wire [32*NUM_QUBITS-1:0]          qubit_payload_o,
    output wire [NUM_QUBITS-1:0]             qubit_payload_valid_o,
    output wire                              invalid_index_error_o,
    output wire                              invalid_pair_error_o,
    output wire                              illegal_error_o,
    output wire                              capacity_error_o,

    // Expose t_cnt so the testbench can read dispatch timing
    output wire [TIME_WIDTH-1:0]             t_cnt_o
);

    // ------------------------------------------------------------------
    // Free-running global time counter
    // ------------------------------------------------------------------
    reg [TIME_WIDTH-1:0] t_cnt_r;
    always @(posedge clk) begin
        if (rst) t_cnt_r <= {TIME_WIDTH{1'b0}};
        else     t_cnt_r <= t_cnt_r + 1'b1;
    end
    assign t_cnt_o = t_cnt_r;

    // ------------------------------------------------------------------
    // vproc_top instantiation
    // (VREG_TYPE=0 = VREG_GENERIC, MUL_TYPE=0 = MUL_GENERIC)
    // ------------------------------------------------------------------
    wire [31:0] pend_vreg_wr_map_unused;
    wire [2:0]  quantum_qrotv_op2_chunk_unused;
    cfg_emul    quantum_emul_int;   // internal; not propagated to ports

    vproc_top #(
        .MEM_W         ( MEM_W        ),
        .VMEM_W        ( VMEM_W       ),
        .VREG_TYPE     ( VREG_GENERIC ),
        .MUL_TYPE      ( MUL_GENERIC  ),
        .ICACHE_SZ     ( 0            ),
        .ICACHE_LINE_W ( 128          ),
        .DCACHE_SZ     ( 0            ),
        .DCACHE_LINE_W ( 64           )
    ) u_vproc (
        .clk_i                        ( clk                         ),
        .rst_ni                       ( ~rst                        ),
        .mem_req_o                    ( mem_req_o                   ),
        .mem_addr_o                   ( mem_addr_o                  ),
        .mem_we_o                     ( mem_we_o                    ),
        .mem_be_o                     ( mem_be_o                    ),
        .mem_wdata_o                  ( mem_wdata_o                 ),
        .mem_rvalid_i                 ( mem_rvalid_i                ),
        .mem_err_i                    ( mem_err_i                   ),
        .mem_rdata_i                  ( mem_rdata_i                 ),
        .pend_vreg_wr_map_o           ( pend_vreg_wr_map_unused     ),
        .measure_done_i               ( measure_done_i              ),
        .measure_result_i             ( measure_result_i            ),
        .qvsg_meas_o                  ( qvsg_meas_o                 ),
        .measure_issued_done_o        ( measure_issued_done_o       ),
        .quantum_valid_o              ( quantum_valid_o             ),
        .quantum_op_o                 ( quantum_op_o                ),
        .quantum_instr_id_o           ( quantum_instr_id_o          ),
        .quantum_vd_addr_o            ( quantum_vd_addr_o           ),
        .quantum_elem1_o              ( quantum_elem1_o             ),
        .quantum_elem2_o              ( quantum_elem2_o             ),
        .quantum_elem3_o              ( quantum_elem3_o             ),
        .quantum_emul_o               ( quantum_emul_int            ),
        .quantum_count_mul_o          ( quantum_count_mul_o         ),
        .quantum_first_cycle_o        ( quantum_first_cycle_o       ),
        .quantum_last_cycle_o         ( quantum_last_cycle_o        ),
        .quantum_vl_part_0_o          ( quantum_vl_part_0_o         ),
        .quantum_res_vaddr_o          ( quantum_res_vaddr_o         ),
        .quantum_data_ready_o         ( quantum_data_ready_o        ),
        .quantum_first_valid_result_o ( quantum_first_valid_result_o),
        .quantum_has_valid_result_o   ( quantum_has_valid_result_o  ),
        .quantum_qrotv_op2_chunk_o    ( quantum_qrotv_op2_chunk_unused )
    );

    // ------------------------------------------------------------------
    // quantum_dispatcher instantiation
    // ------------------------------------------------------------------
    quantum_dispatcher #(
        .NUM_QUBITS    ( NUM_QUBITS    ),
        .FIFO_DEPTH    ( FIFO_DEPTH    ),
        .TIME_WIDTH    ( TIME_WIDTH    ),
        .GATE_WIDTH    ( GATE_WIDTH    ),
        .BLOCK_IMM_W   ( BLOCK_IMM_W  ),
        .FIXED_LATENCY ( FIXED_LATENCY )
    ) u_qdisp (
        .clk                 ( clk                  ),
        .reset               ( rst                  ),
        .t_cnt               ( t_cnt_r              ),
        .quantum_valid       ( quantum_valid_o       ),
        .quantum_op          ( quantum_op_o          ),
        .quantum_instr_id    ( quantum_instr_id_o    ),
        .quantum_elem1       ( quantum_elem1_o       ),
        .quantum_elem2       ( quantum_elem2_o       ),
        .quantum_elem3       ( quantum_elem3_o       ),
        .quantum_data_ready  ( quantum_data_ready_o  ),
        .quantum_first_cycle ( quantum_first_cycle_o ),
        .quantum_last_cycle  ( quantum_last_cycle_o  ),
        .qubit_gate_o        ( qubit_gate_o          ),
        .qubit_valid_o       ( qubit_valid_o         ),
        .qubit_error_o       ( qubit_error_o         ),
        .qubit_ctrl_o        ( qubit_ctrl_o          ),
        .qubit_payload_o        ( qubit_payload_o        ),
        .qubit_payload_valid_o  ( qubit_payload_valid_o  ),
        .invalid_index_error_o ( invalid_index_error_o ),
        .invalid_pair_error_o  ( invalid_pair_error_o  ),
        .illegal_error_o       ( illegal_error_o       ),
        .capacity_error_o      ( capacity_error_o      )
    );

endmodule
