`timescale 1ns / 1ps
//
// Unified Ibex + vproc + timed-dispatch co-simulation testbench.
// The selected image is supplied through +MEM_FILE. The bench logs raw stream
// beats and fire-time AWG events, drives measurement responses, and fails on
// timeout, input/logging errors, or any classified dispatcher error. Directed
// images may enable an exact scoreboard through a plusarg.

module vproc_qdisp_bell_tb;

    // -----------------------------------------------------------------
    // Simulation parameters
    // -----------------------------------------------------------------
    parameter MEM_W                    = 32;
    parameter MEM_SZ                   = 262144;
    parameter MEM_LATENCY              = 1;
    parameter VMEM_W                   = 32;
    parameter MAX_CYCLES               = 200000;
    parameter EVENT_LOG_LIMIT          = 32768;
    parameter POST_EVENT_IDLE_CYCLES   = 200;
    parameter MEASURE_DONE_DELAY_CYCLES= 50;
    parameter MEM_WORDS                = MEM_SZ / (MEM_W / 8);
    // Ibex reset fetch is {boot_addr_i[31:8], 8'h80}. vproc_top supplies
    // boot_addr_i=0, so instruction images must begin at byte 0x80.
    parameter BOOT_WORD_ADDR           = 32;

    // quantum_dispatcher parameters (must match vproc_qdisp_top defaults)
    parameter NUM_QUBITS    = 16;   // Maintained unified snapshot capacity.
    parameter GATE_WIDTH    = 7;
    parameter TIME_WIDTH    = 20;
    parameter FIXED_LATENCY = 16;

    parameter [4:0] ELEM_QSINGLE = 5'd16;
    parameter [4:0] ELEM_QPAIR   = 5'd17;
    parameter [4:0] ELEM_QROTG   = 5'd18;
    parameter [4:0] ELEM_QROTV   = 5'd19;

    // -----------------------------------------------------------------
    // Counters / tracking
    // -----------------------------------------------------------------
    integer cycle_count;
    integer quantum_event_idx;
    integer last_quantum_event_cycle;
    integer idle_count;             // cycles since the last quantum event
    integer resume_event_count;
    integer qubit_fire_count;
    integer invalid_index_count;
    integer invalid_pair_count;
    integer fifo_overflow_count;
    integer illegal_count;
    integer capacity_error_count;
    integer awg_event_idx;
    integer measurement_count;
    integer tb_failure_count;
    integer rot_gateid_fire_per_q [0:NUM_QUBITS-1];
    integer rot_gateid_bad_fire_count;
    reg     expect_rot_gateid;

    // Generic per-case AWG scoreboard, loaded from +AWG_EXPECT=<file>.
    // One line per expected qubit fire: <qubit> <gate_hex> <C|T> <pv> <payload_hex>
    localparam AWG_EXPECT_MAX = 64;
    reg          awg_expect_en;
    integer      awg_expect_count;
    integer      awg_unexpected_count;
    integer      exp_qubit   [0:AWG_EXPECT_MAX-1];
    reg  [6:0]   exp_gate    [0:AWG_EXPECT_MAX-1];
    reg          exp_ctrl    [0:AWG_EXPECT_MAX-1];
    reg          exp_pv      [0:AWG_EXPECT_MAX-1];
    reg  [31:0]  exp_payload [0:AWG_EXPECT_MAX-1];
    reg          exp_used    [0:AWG_EXPECT_MAX-1];

    // Expected-trap mode for negative tests (+EXPECT_TRAP): PASS when the
    // coprocessor rejects the instruction, instead of timing out.
    reg     expect_trap;
    integer trap_count;
    integer trap_idle_count;

    // -----------------------------------------------------------------
    // Trace-name helper
    // -----------------------------------------------------------------
    function [8*12-1:0] bell_op_name;
        input [4:0] op;
        begin
            case (op)
                ELEM_QSINGLE: bell_op_name = "QV.SINGLE   ";
                ELEM_QPAIR:   bell_op_name = "QV.PAIR     ";
                ELEM_QROTG:   bell_op_name = "QV.ROT.G    ";
                ELEM_QROTV:   bell_op_name = "QV.ROT.V    ";
                default:      bell_op_name = "UNKNOWN     ";
            endcase
        end
    endfunction

    function [8*28-1:0] bell_instr_name;
        input [31:0] instr;
        begin
            case (instr)
                32'h06600313: bell_instr_name = "addi x6, x0, 0x66          ";
                32'h05500393: bell_instr_name = "addi x7, x0, 0x55          ";
                32'h00800293: bell_instr_name = "addi x5, x0, 8             ";
                32'h0C72F057: bell_instr_name = "vsetvli x0, x5, e8, mf2    ";
                32'h00000013: bell_instr_name = "nop                        ";
                32'h00001537: bell_instr_name = "lui a0, 0x1                ";
                32'h02050087: bell_instr_name = "vle8.v v1, (a0)            ";
                32'h00850593: bell_instr_name = "addi a1, a0, 8             ";
                32'h02058107: bell_instr_name = "vle8.v v2, (a1)            ";
                32'hC8708657: bell_instr_name = "QV.SINGLE(H) [legacy OP-V]  ";
                32'hCC208657: bell_instr_name = "QV.PAIR(CNOT) [legacy OP-V]";
                32'hD0708657: bell_instr_name = "QV.MEASURE [legacy OP-V]   ";
                32'hF0610657: bell_instr_name = "QV.SINGLE(resume) [legacy]";
                // custom-0 (0x0B) encodings (RFC #3 migration)
                32'hC870860B: bell_instr_name = "QV.SINGLE(H) [cust0]       ";
                32'hCC20960B: bell_instr_name = "QV.PAIR(CNOT) [cust0]      ";
                32'hD070860B: bell_instr_name = "QSG.MEASURE [cust0]        ";
                32'hF061060B: bell_instr_name = "QV.SINGLE(resume) [cust0]  ";
                32'h0000006F: bell_instr_name = "jal x0, 0                  ";
                default:      bell_instr_name = "unknown                    ";
            endcase
        end
    endfunction

    // -----------------------------------------------------------------
    // Clock and reset
    // -----------------------------------------------------------------
    reg clk;
    reg rst;

    initial begin
        clk = 1'b0;
        forever #5 clk = ~clk;
    end

    // -----------------------------------------------------------------
    // Memory interface signals
    // -----------------------------------------------------------------
    wire                  mem_req;
    wire [31:0]           mem_addr;
    wire                  mem_we;
    wire [MEM_W/8-1:0]   mem_be;
    wire [MEM_W-1:0]      mem_wdata;
    reg                   mem_rvalid;
    reg                   mem_err;
    reg  [MEM_W-1:0]      mem_rdata;

    // -----------------------------------------------------------------
    // Measure handshake
    // -----------------------------------------------------------------
    reg  measure_done;
    reg  [31:0] measure_result;   // result bits sent back alongside measure_done
    wire qvsg_meas;
    wire measure_issued_done;

    // -----------------------------------------------------------------
    // Raw quantum stream
    // -----------------------------------------------------------------
    wire                  quantum_valid;
    wire [4:0]            quantum_op;
    wire [2:0]            quantum_instr_id;
    wire [4:0]            quantum_vd_addr; // legacy field name; custom-0 bits [11:7] are block_imm
    wire [31:0]           quantum_elem1;
    wire [31:0]           quantum_elem2;
    wire [31:0]           quantum_elem3;
    // quantum_emul not exposed by vproc_qdisp_top (cfg_emul type)
    wire [2:0]            quantum_count_mul;
    wire                  quantum_first_cycle;
    wire                  quantum_last_cycle;
    wire                  quantum_vl_part_0;
    wire [4:0]            quantum_res_vaddr;
    wire                  quantum_data_ready;
    wire                  quantum_first_valid_result;
    wire                  quantum_has_valid_result;

    // -----------------------------------------------------------------
    // Dispatcher outputs
    // -----------------------------------------------------------------
    wire [GATE_WIDTH*NUM_QUBITS-1:0] qubit_gate;
    wire [NUM_QUBITS-1:0]            qubit_valid;
    wire [NUM_QUBITS-1:0]            qubit_error;
    wire [NUM_QUBITS-1:0]            qubit_ctrl;   // 1=control side, 0=target side
    wire [32*NUM_QUBITS-1:0]         qubit_payload;
    wire [NUM_QUBITS-1:0]            qubit_payload_valid;
    wire                              invalid_index_error;
    wire                              invalid_pair_error;
    wire                              illegal_error;
    wire                              capacity_error;
    wire [TIME_WIDTH-1:0]            t_cnt;

    // -----------------------------------------------------------------
    // Memory model
    // -----------------------------------------------------------------
    reg [MEM_W-1:0] mem [0:MEM_WORDS-1];

    integer mem_idx;
    integer i;
    reg [1023:0] instr_mem_file;
    reg [1023:0] data_mem_file;
    reg [1023:0] combined_mem_file;

    reg [MEM_LATENCY-1:0] mem_rvalid_queue;
    reg [31:0]            mem_rdata_queue  [0:MEM_LATENCY-1];
    reg [MEM_LATENCY-1:0] mem_err_queue;

    // -----------------------------------------------------------------
    // DUT – vproc_qdisp_top
    // -----------------------------------------------------------------
    vproc_qdisp_top #(
        .MEM_W         ( MEM_W         ),
        .VMEM_W        ( VMEM_W        ),
        .NUM_QUBITS    ( NUM_QUBITS    ),   // 16
        .FIFO_DEPTH    ( 8             ),
        .TIME_WIDTH    ( TIME_WIDTH    ),
        .GATE_WIDTH    ( GATE_WIDTH    ),
        .BLOCK_IMM_W   ( 5             ),  // Architectural field width.
        .FIXED_LATENCY ( FIXED_LATENCY )
    ) dut (
        .clk                        ( clk                      ),
        .rst                        ( rst                      ),
        .mem_req_o                  ( mem_req                  ),
        .mem_addr_o                 ( mem_addr                 ),
        .mem_we_o                   ( mem_we                   ),
        .mem_be_o                   ( mem_be                   ),
        .mem_wdata_o                ( mem_wdata                ),
        .mem_rvalid_i               ( mem_rvalid               ),
        .mem_err_i                  ( mem_err                  ),
        .mem_rdata_i                ( mem_rdata                ),
        .measure_done_i             ( measure_done             ),
        .measure_result_i           ( measure_result           ),
        .qvsg_meas_o                ( qvsg_meas                ),
        .measure_issued_done_o      ( measure_issued_done      ),
        .quantum_valid_o            ( quantum_valid            ),
        .quantum_op_o               ( quantum_op               ),
        .quantum_instr_id_o         ( quantum_instr_id         ),
        .quantum_vd_addr_o          ( quantum_vd_addr          ),
        .quantum_elem1_o            ( quantum_elem1            ),
        .quantum_elem2_o            ( quantum_elem2            ),
        .quantum_elem3_o            ( quantum_elem3            ),
        .quantum_count_mul_o        ( quantum_count_mul        ),
        .quantum_first_cycle_o      ( quantum_first_cycle      ),
        .quantum_last_cycle_o       ( quantum_last_cycle       ),
        .quantum_vl_part_0_o        ( quantum_vl_part_0        ),
        .quantum_res_vaddr_o        ( quantum_res_vaddr        ),
        .quantum_data_ready_o       ( quantum_data_ready       ),
        .quantum_first_valid_result_o( quantum_first_valid_result ),
        .quantum_has_valid_result_o ( quantum_has_valid_result ),
        .qubit_gate_o               ( qubit_gate               ),
        .qubit_valid_o              ( qubit_valid              ),
        .qubit_error_o              ( qubit_error              ),
        .qubit_ctrl_o               ( qubit_ctrl               ),
        .qubit_payload_o            ( qubit_payload            ),
        .qubit_payload_valid_o      ( qubit_payload_valid      ),
        .invalid_index_error_o      ( invalid_index_error      ),
        .invalid_pair_error_o       ( invalid_pair_error       ),
        .illegal_error_o            ( illegal_error            ),
        .capacity_error_o           ( capacity_error           ),
        .t_cnt_o                    ( t_cnt                    )
    );

    // -----------------------------------------------------------------
    // Internal Ibex instruction monitor (hierarchy through new top)
    // -----------------------------------------------------------------
    wire [31:0] ibex_id_instr;
    assign ibex_id_instr = dut.u_vproc.u_core.u_ibex_core.id_stage_i.instr_rdata_i;
    // Pulses when the coprocessor rejects a granted instruction (real illegal,
    // already filtered for the offload-accept race).
    wire cpi_illegal;
    assign cpi_illegal = dut.u_vproc.cpi_instr_illegal;

    // -----------------------------------------------------------------
    // Memory model logic
    // -----------------------------------------------------------------
    always @(*) begin
        mem_idx = mem_addr >> 2;
    end

    always @(posedge clk) begin
        cycle_count = cycle_count + 1;

        // Idle timer: clear it on each quantum beat, otherwise count up. Kept in
        // this block (next to cycle_count) so Verilator propagates it properly.
        if (quantum_valid) idle_count = 0;
        else               idle_count = idle_count + 1;

        if (mem_req && mem_we && (mem_idx >= 0) && (mem_idx < MEM_WORDS)) begin
            $display("[QDISP_TB][cycle=%0d][STORE] addr=0x%08x data=0x%08x be=%b",
                     cycle_count, mem_addr, mem_wdata, mem_be);
            for (i = 0; i < (MEM_W/8); i = i + 1) begin
                if (mem_be[i])
                    mem[mem_idx][(i*8) +: 8] <= mem_wdata[(i*8) +: 8];
            end
        end

        if (MEM_LATENCY == 1) begin
            mem_rvalid <= mem_req;
            mem_err    <= (mem_addr >= MEM_SZ);
            mem_rdata  <= ((mem_idx >= 0) && (mem_idx < MEM_WORDS)) ?
                          mem[mem_idx] : 32'h0;
        end else begin
            mem_rvalid_queue[0] <= mem_req;
            mem_err_queue[0]    <= (mem_addr >= MEM_SZ);
            mem_rdata_queue[0]  <= ((mem_idx >= 0) && (mem_idx < MEM_WORDS)) ?
                                   mem[mem_idx] : 32'h0;
            for (i = 1; i < MEM_LATENCY; i = i + 1) begin
                mem_rvalid_queue[i] <= mem_rvalid_queue[i-1];
                mem_rdata_queue[i]  <= mem_rdata_queue[i-1];
                mem_err_queue[i]    <= mem_err_queue[i-1];
            end
            mem_rvalid <= mem_rvalid_queue[MEM_LATENCY-1];
            mem_rdata  <= mem_rdata_queue[MEM_LATENCY-1];
            mem_err    <= mem_err_queue[MEM_LATENCY-1];
        end
    end

    // -----------------------------------------------------------------
    // Measure handshake simulation
    // -----------------------------------------------------------------
    reg  prev_qvsg_meas;
    reg  prev_measure_issued_done;
    reg  measure_wait_pending;
    reg  resume_stream_seen;
    integer measure_wait_cycles_left;
    reg [31:0] prev_ibex_id_instr;
    reg [2:0]  prev_quantum_instr_id;
    reg        prev_quantum_instr_id_valid;
    reg [31:0] measure_result_val;
    reg [1023:0] measure_input_file;
    reg [1023:0] awg_output_file;
    reg [1023:0] awg_expect_file;
    integer awg_expect_fd;
    integer awg_expect_scan;
    reg [8*8-1:0] exp_role_str;
    integer exp_pv_int;
    integer measure_input_fd;
    integer measure_input_scan;
    integer awg_output_fd;
    integer measure_delay_cycles;
    integer max_cycles_limit;
    reg use_measure_file;

    always @(posedge clk) begin
        if (rst) begin
            measure_done             <= 1'b0;
            prev_qvsg_meas           <= 1'b0;
            prev_measure_issued_done <= 1'b0;
            measure_wait_pending     <= 1'b0;
            measure_wait_cycles_left <= 0;
        end else begin
            measure_done <= 1'b0;

            if (!resume_stream_seen &&
                (ibex_id_instr != prev_ibex_id_instr) &&
                (bell_instr_name(ibex_id_instr) != "unknown                    "))
                $display("[QDISP_TB][cycle=%0d][INSTR] %08x  %0s",
                         cycle_count, ibex_id_instr,
                         bell_instr_name(ibex_id_instr));

            if (qvsg_meas && !prev_qvsg_meas)
                $display("[QDISP_TB][cycle=%0d][MEASURE] qvsg_meas=1 start", cycle_count);
            if (!qvsg_meas && prev_qvsg_meas)
                $display("[QDISP_TB][cycle=%0d][MEASURE] qvsg_meas=0 resume", cycle_count);
            if (measure_issued_done && !prev_measure_issued_done)
                $display("[QDISP_TB][cycle=%0d][MEASURE] measure_issued_done=1", cycle_count);

            if (measure_issued_done && !prev_measure_issued_done) begin
                if (use_measure_file) begin
                    measure_input_scan = $fscanf(measure_input_fd, "%h %d\n",
                                                measure_result_val, measure_delay_cycles);
                    if ((measure_input_scan != 2) || (measure_delay_cycles < 0)) begin
                        $display("[QDISP_TB][cycle=%0d][FAIL] measurement input exhausted or malformed at transaction %0d",
                                 cycle_count, measurement_count);
                        finish_simulation(1);
                    end
                end
                if (!use_measure_file ||
                    ((measure_input_scan == 2) && (measure_delay_cycles >= 0))) begin
                    measure_wait_pending     <= 1'b1;
                    measure_wait_cycles_left <= measure_delay_cycles;
                    measurement_count         = measurement_count + 1;
                    $display("[QDISP_TB][cycle=%0d][WAIT] ADC delay = %0d cycles, result=%08x",
                             cycle_count, measure_delay_cycles, measure_result_val);
                end
            end else if (measure_wait_pending) begin
                if (measure_wait_cycles_left == 0) begin
                    measure_done         <= 1'b1;
                    measure_result       <= measure_result_val;
                    measure_wait_pending <= 1'b0;
                    $display("[QDISP_TB][cycle=%0d][MEASURE] measure_done=1 (sent) result=%08x",
                             cycle_count, measure_result_val);
                end else
                    measure_wait_cycles_left <= measure_wait_cycles_left - 1;
            end

            prev_qvsg_meas           <= qvsg_meas;
            prev_measure_issued_done <= measure_issued_done;
            prev_ibex_id_instr       <= ibex_id_instr;
        end
    end

    // -----------------------------------------------------------------
    // Quantum stream monitor
    // -----------------------------------------------------------------
    always @(posedge clk) begin
        if (!rst && quantum_valid) begin
            if (quantum_event_idx >= EVENT_LOG_LIMIT) begin
                $display("[QDISP_TB][cycle=%0d][FAIL] EVENT_LOG_LIMIT=%0d reached",
                         cycle_count, EVENT_LOG_LIMIT);
                finish_simulation(1);
            end

            if (!prev_quantum_instr_id_valid ||
                (quantum_instr_id != prev_quantum_instr_id))
                $display("[QDISP_TB][cycle=%0d][QX_START] op=%0d(%0s) id=%0d field_11_7=%0d elem2=%08x elem3=%08x ready=%0b",
                         cycle_count, quantum_op, bell_op_name(quantum_op),
                         quantum_instr_id, quantum_vd_addr,
                         quantum_elem2, quantum_elem3, quantum_data_ready);

            $display("[QDISP_TB][cycle=%0d][QX] idx=%0d op=%0s id=%0d elem1=%08x elem2=%08x elem3=%08x ready=%0b t_cnt=%0d",
                     cycle_count, quantum_event_idx, bell_op_name(quantum_op),
                     quantum_instr_id, quantum_elem1, quantum_elem2,
                     quantum_elem3, quantum_data_ready, t_cnt);

            // Detect resume-marker stream (same logic as original Bell TB)
            if (!resume_stream_seen &&
                !qvsg_meas &&
                (quantum_op == ELEM_QSINGLE) &&
                (quantum_elem2 == 32'h00000066)) begin
                resume_stream_seen <= 1'b1;
                resume_event_count <= 1;
                $display("[QDISP_TB][cycle=%0d][RESUME] first post-measure event seen", cycle_count);
            end else if (resume_stream_seen) begin
                resume_event_count <= resume_event_count + 1;
            end

            prev_quantum_instr_id       = quantum_instr_id;
            prev_quantum_instr_id_valid = 1'b1;
            last_quantum_event_cycle    = cycle_count;
            quantum_event_idx           = quantum_event_idx + 1;
        end
    end

    // -----------------------------------------------------------------
    // Qubit dispatcher output monitor
    // Prints one line per t_cnt cycle showing ALL active qubits together,
    // then individual lines for each firing qubit.
    // -----------------------------------------------------------------
    integer qi;
    always @(posedge clk) begin
        if (!rst) begin
            if (|qubit_valid) begin
                // Summary line: full valid mask and gate bus
                $display("[AWG][t_cnt=%0d] valid_mask=%b  (cycle=%0d)",
                         t_cnt, qubit_valid, cycle_count);
                // Per-qubit detail
                for (qi = 0; qi < NUM_QUBITS; qi = qi + 1) begin
                    if (qubit_valid[qi]) begin
                        if (qubit_payload_valid[qi])
                            $display("[AWG][t_cnt=%0d]   qubit[%02d]  gate=0x%02x  role=%0s  payload=0x%08x",
                                     t_cnt, qi,
                                     qubit_gate[(qi+1)*GATE_WIDTH-1 -: GATE_WIDTH],
                                     qubit_ctrl[qi] ? "CTRL" : "TGT ",
                                     qubit_payload[(qi+1)*32-1 -: 32]);
                        else
                            $display("[AWG][t_cnt=%0d]   qubit[%02d]  gate=0x%02x  role=%0s",
                                     t_cnt, qi,
                                     qubit_gate[(qi+1)*GATE_WIDTH-1 -: GATE_WIDTH],
                                     qubit_ctrl[qi] ? "CTRL" : "TGT ");
                        if (awg_output_fd != 0)
                            $fwrite(awg_output_fd, "%0d,%0d,%0d,0x%0h,%0d,0x%02x,%0s,%0d,0x%08x\n",
                                    awg_event_idx, cycle_count, t_cnt, qubit_valid, qi,
                                    qubit_gate[(qi+1)*GATE_WIDTH-1 -: GATE_WIDTH],
                                    qubit_ctrl[qi] ? "CTRL" : "TGT",
                                    qubit_payload_valid[qi],
                                    qubit_payload[(qi+1)*32-1 -: 32]);
                        qubit_fire_count = qubit_fire_count + 1;
                        if (expect_rot_gateid) begin
                            rot_gateid_fire_per_q[qi] =
                                rot_gateid_fire_per_q[qi] + 1;
                            case (qi)
                                0, 1: begin
                                    if ((qubit_gate[(qi+1)*GATE_WIDTH-1 -: GATE_WIDTH] != 7'h6e) ||
                                        (qubit_ctrl[qi] != 1'b1) ||
                                        (qubit_payload_valid[qi] != 1'b1) ||
                                        (qubit_payload[(qi+1)*32-1 -: 32] != 32'h00000555))
                                        rot_gateid_bad_fire_count =
                                            rot_gateid_bad_fire_count + 1;
                                end
                                2: begin
                                    if ((qubit_gate[(qi+1)*GATE_WIDTH-1 -: GATE_WIDTH] != 7'h6a) ||
                                        (qubit_ctrl[qi] != 1'b1) ||
                                        (qubit_payload_valid[qi] != 1'b1) ||
                                        (qubit_payload[(qi+1)*32-1 -: 32] != 32'h00000aaa))
                                        rot_gateid_bad_fire_count =
                                            rot_gateid_bad_fire_count + 1;
                                end
                                3: begin
                                    if ((qubit_gate[(qi+1)*GATE_WIDTH-1 -: GATE_WIDTH] != 7'h6a) ||
                                        (qubit_ctrl[qi] != 1'b1) ||
                                        (qubit_payload_valid[qi] != 1'b1) ||
                                        (qubit_payload[(qi+1)*32-1 -: 32] != 32'h00000bbb))
                                        rot_gateid_bad_fire_count =
                                            rot_gateid_bad_fire_count + 1;
                                end
                                default:
                                    rot_gateid_bad_fire_count =
                                        rot_gateid_bad_fire_count + 1;
                            endcase
                        end
                        if (awg_expect_en) begin : awg_expect_match
                            integer ei;
                            reg matched;
                            matched = 1'b0;
                            for (ei = 0; ei < awg_expect_count; ei = ei + 1) begin
                                if (!matched && !exp_used[ei] &&
                                    (exp_qubit[ei] == qi) &&
                                    (exp_gate[ei] == qubit_gate[(qi+1)*GATE_WIDTH-1 -: GATE_WIDTH]) &&
                                    (exp_ctrl[ei] == qubit_ctrl[qi]) &&
                                    (exp_pv[ei] == qubit_payload_valid[qi]) &&
                                    (!exp_pv[ei] ||
                                     (exp_payload[ei] == qubit_payload[(qi+1)*32-1 -: 32]))) begin
                                    exp_used[ei] = 1'b1;
                                    matched = 1'b1;
                                end
                            end
                            if (!matched) begin
                                awg_unexpected_count = awg_unexpected_count + 1;
                                $display("[AWG_EXPECT][cycle=%0d] UNEXPECTED fire: qubit=%0d gate=0x%02x role=%0s pv=%0d payload=0x%08x",
                                         cycle_count, qi,
                                         qubit_gate[(qi+1)*GATE_WIDTH-1 -: GATE_WIDTH],
                                         qubit_ctrl[qi] ? "CTRL" : "TGT",
                                         qubit_payload_valid[qi],
                                         qubit_payload[(qi+1)*32-1 -: 32]);
                            end
                        end
                    end
                end
                if (awg_output_fd != 0)
                    $fflush(awg_output_fd);
                awg_event_idx = awg_event_idx + 1;
            end

            if (|qubit_error) begin
                $display("[QDISP_TB][cycle=%0d][ERROR][FIFO_OVERFLOW] qubits=%b",
                         cycle_count, qubit_error);
                fifo_overflow_count = fifo_overflow_count + 1;
            end

            if (invalid_index_error) begin
                $display("[QDISP_TB][cycle=%0d][ERROR][INVALID_INDEX] elem1=%0d NUM_QUBITS=%0d",
                         cycle_count, quantum_elem1[7:0], NUM_QUBITS);
                invalid_index_count = invalid_index_count + 1;
            end

            if (invalid_pair_error) begin
                $display("[QDISP_TB][cycle=%0d][ERROR][INVALID_PAIR] elem1=%0d elem2=%0d NUM_QUBITS=%0d",
                         cycle_count, quantum_elem1[7:0], quantum_elem2[7:0], NUM_QUBITS);
                invalid_pair_count = invalid_pair_count + 1;
            end

            if (illegal_error) begin
                $display("[QDISP_TB][cycle=%0d][ERROR][ILLEGAL] duplicate qubit, identical pair endpoints, or timestamp conflict",
                         cycle_count);
                illegal_count = illegal_count + 1;
            end

            if (capacity_error) begin
                $display("[QDISP_TB][cycle=%0d][ERROR][CAPACITY] burst rejected -- at least one touched qubit's FIFO had no room",
                         cycle_count);
                capacity_error_count = capacity_error_count + 1;
            end

            if (cpi_illegal) begin
                trap_count = trap_count + 1;
                $display("[QDISP_TB][cycle=%0d][TRAP] coprocessor rejected instruction (%0s)",
                         cycle_count, expect_trap ? "expected" : "UNEXPECTED");
            end
        end
    end

    // -----------------------------------------------------------------
    // Summary task
    // -----------------------------------------------------------------
    task print_summary;
        begin
            $display("");
            $display("[QDISP_TB] ===== CO-SIM SUMMARY =====");
            $display("[QDISP_TB]  cycles         : %0d", cycle_count);
            $display("[QDISP_TB]  quantum events : %0d", quantum_event_idx);
            $display("[QDISP_TB]  qubit fires    : %0d", qubit_fire_count);
            $display("[QDISP_TB]  AWG events     : %0d", awg_event_idx);
            $display("[QDISP_TB]  measurements   : %0d", measurement_count);
            $display("[QDISP_TB]  TB failures    : %0d", tb_failure_count);
            $display("[QDISP_TB]  invalid-index : %0d", invalid_index_count);
            $display("[QDISP_TB]  invalid-pair  : %0d", invalid_pair_count);
            $display("[QDISP_TB]  FIFO-overflow : %0d", fifo_overflow_count);
            $display("[QDISP_TB]  illegal       : %0d", illegal_count);
            $display("[QDISP_TB]  capacity      : %0d", capacity_error_count);
            $display("[QDISP_TB]  traps         : %0d%0s", trap_count,
                     expect_trap ? " (expected)" : "");
            if ((tb_failure_count + invalid_index_count + invalid_pair_count +
                 fifo_overflow_count + illegal_count + capacity_error_count) == 0)
                $display("[QDISP_TB]  RESULT         : PASS");
            else
                $display("[QDISP_TB]  RESULT         : FAIL - %0d testbench failure(s), %0d dispatcher error pulse(s)",
                         tb_failure_count,
                         invalid_index_count + invalid_pair_count +
                         fifo_overflow_count + illegal_count + capacity_error_count);
            $display("[QDISP_TB] ==========================");
            if (awg_output_fd != 0) begin
                $fflush(awg_output_fd);
                $fclose(awg_output_fd);
                awg_output_fd = 0;
            end
            if (measure_input_fd != 0) begin
                $fclose(measure_input_fd);
                measure_input_fd = 0;
            end
        end
    endtask

    task check_case_expectations;
        integer ei;
        integer missing;
        begin
            if (awg_expect_en) begin
                missing = 0;
                for (ei = 0; ei < awg_expect_count; ei = ei + 1) begin
                    if (!exp_used[ei]) begin
                        missing = missing + 1;
                        $display("[AWG_EXPECT] MISSING fire: qubit=%0d gate=0x%02x role=%0s pv=%0d payload=0x%08x",
                                 exp_qubit[ei], exp_gate[ei],
                                 exp_ctrl[ei] ? "CTRL" : "TGT",
                                 exp_pv[ei], exp_payload[ei]);
                    end
                end
                if ((missing != 0) || (awg_unexpected_count != 0) ||
                    (qubit_fire_count != awg_expect_count)) begin
                    tb_failure_count = tb_failure_count + 1;
                    $display("[FAIL][AWG_EXPECT] expected=%0d fires=%0d missing=%0d unexpected=%0d",
                             awg_expect_count, qubit_fire_count, missing,
                             awg_unexpected_count);
                end else begin
                    $display("[PASS][AWG_EXPECT] all %0d expected fires matched exactly",
                             awg_expect_count);
                end
            end
            if (expect_trap && (trap_count == 0)) begin
                tb_failure_count = tb_failure_count + 1;
                $display("[FAIL][EXPECT_TRAP] no coprocessor rejection observed");
            end
            if (!expect_trap && (trap_count != 0)) begin
                tb_failure_count = tb_failure_count + 1;
                $display("[FAIL][TRAP] %0d unexpected coprocessor rejection(s)", trap_count);
            end
            if (expect_rot_gateid) begin
                if ((quantum_event_idx != 4) ||
                    (awg_event_idx != 2) ||
                    (qubit_fire_count != 4) ||
                    (rot_gateid_fire_per_q[0] != 1) ||
                    (rot_gateid_fire_per_q[1] != 1) ||
                    (rot_gateid_fire_per_q[2] != 1) ||
                    (rot_gateid_fire_per_q[3] != 1) ||
                    (rot_gateid_bad_fire_count != 0)) begin
                    tb_failure_count = tb_failure_count + 1;
                    $display("[FAIL][ROT_GATEID] raw=%0d awg_events=%0d fires=%0d per_q=%0d,%0d,%0d,%0d bad=%0d",
                             quantum_event_idx, awg_event_idx,
                             qubit_fire_count,
                             rot_gateid_fire_per_q[0],
                             rot_gateid_fire_per_q[1],
                             rot_gateid_fire_per_q[2],
                             rot_gateid_fire_per_q[3],
                             rot_gateid_bad_fire_count);
                end else begin
                    $display("[PASS][ROT_GATEID] GateID and payload match on q0-q3");
                end
            end
        end
    endtask

    task finish_simulation;
        input testbench_failure;
        begin
            if (testbench_failure)
                tb_failure_count = tb_failure_count + 1;
            check_case_expectations;
            print_summary;
            if ((tb_failure_count != 0) ||
                ((invalid_index_count + invalid_pair_count +
                  fifo_overflow_count + illegal_count + capacity_error_count) != 0))
                $fatal(1, "[QDISP_TB] simulation failed");
            else
                $finish;
        end
    endtask

    // -----------------------------------------------------------------
    // Stimulus – same flow as vproc_bell_tb.v
    // -----------------------------------------------------------------
    initial begin
        // Initialise
        cycle_count                 = 0;
        quantum_event_idx           = 0;
        last_quantum_event_cycle    = -1;
        idle_count                  = 0;
        qubit_fire_count            = 0;
        invalid_index_count         = 0;
        invalid_pair_count          = 0;
        fifo_overflow_count         = 0;
        illegal_count               = 0;
        capacity_error_count        = 0;
        awg_event_idx               = 0;
        measurement_count           = 0;
        tb_failure_count            = 0;
        resume_event_count          = 0;
        resume_stream_seen          = 1'b0;
        mem_rvalid                  = 1'b0;
        mem_err                     = 1'b0;
        mem_rdata                   = 32'h0;
        prev_quantum_instr_id       = 3'b000;
        prev_quantum_instr_id_valid = 1'b0;
        rot_gateid_bad_fire_count   = 0;
        expect_rot_gateid           = 1'b0;
        awg_expect_en               = 1'b0;
        awg_expect_count            = 0;
        awg_unexpected_count        = 0;
        expect_trap                 = 1'b0;
        trap_count                  = 0;
        trap_idle_count             = 0;
        measure_done                = 1'b0;
        measure_result               = 32'h0;
        prev_qvsg_meas              = 1'b0;
        prev_measure_issued_done    = 1'b0;
        measure_wait_pending        = 1'b0;
        measure_wait_cycles_left    = 0;
        measure_delay_cycles        = MEASURE_DONE_DELAY_CYCLES;
        measure_input_fd            = 0;
        measure_input_scan          = 0;
        awg_output_fd               = 0;
        use_measure_file            = 0;
        max_cycles_limit            = MAX_CYCLES;
        prev_ibex_id_instr          = 32'h0;

        for (i = 0; i < MEM_WORDS; i = i + 1)
            mem[i] = {MEM_W{1'b0}};
        for (i = 0; i < MEM_LATENCY; i = i + 1) begin
            mem_rvalid_queue[i] = 1'b0;
            mem_rdata_queue[i]  = 32'h0;
            mem_err_queue[i]    = 1'b0;
        end
        for (i = 0; i < NUM_QUBITS; i = i + 1)
            rot_gateid_fire_per_q[i] = 0;

        // Load memory.
        // Primary:  +MEM_FILE=combined.mem  (single file, @addr markers for data section)
        // Fallback: +INSTR_MEM_FILE=x +DATA_MEM_FILE=y  (legacy split format)
        if ($value$plusargs("MEM_FILE=%s", combined_mem_file)) begin
            $display("[QDISP_TB][INIT] mem file: %0s", combined_mem_file);
            // Initial sequential words are relocated to byte 0x80. Explicit
            // @ addresses in the combined file still place data absolutely.
            $readmemh(combined_mem_file, mem, BOOT_WORD_ADDR);
        end else begin
            if (!$value$plusargs("INSTR_MEM_FILE=%s", instr_mem_file))
                instr_mem_file = "";
            if (!$value$plusargs("DATA_MEM_FILE=%s", data_mem_file))
                data_mem_file  = "";
            if (instr_mem_file == "") begin
                $display("[QDISP_TB][INIT][WARN] No MEM_FILE or INSTR_MEM_FILE supplied — memory will be zero.");
            end else begin
                $display("[QDISP_TB][INIT] instruction mem : %0s", instr_mem_file);
                $readmemh(instr_mem_file, mem, BOOT_WORD_ADDR);
                if (data_mem_file != "") begin
                    $display("[QDISP_TB][INIT] data mem        : %0s", data_mem_file);
                    $readmemh(data_mem_file,  mem);
                end
            end
        end
        // What the "backend" reports as the measurement result. Defaults to a
        // fixed pattern (0xA5A5A5A5); override per-run with +MEASURE_RESULT=0x...
        if (!$value$plusargs("MEASURE_RESULT=%h", measure_result_val))
            measure_result_val = 32'hA5A5A5A5;

        if (!$value$plusargs("MEASURE_DELAY=%d", measure_delay_cycles))
            measure_delay_cycles = MEASURE_DONE_DELAY_CYCLES;
        if ($value$plusargs("MEASURE_FILE=%s", measure_input_file)) begin
            measure_input_fd = $fopen(measure_input_file, "r");
            if (measure_input_fd == 0) begin
                $display("[QDISP_TB][INIT][FAIL] cannot open measurement file: %0s", measure_input_file);
                finish_simulation(1);
            end else begin
                use_measure_file = 1;
                $display("[QDISP_TB][INIT] measurement file: %0s", measure_input_file);
            end
        end
        if ($value$plusargs("AWG_OUTPUT=%s", awg_output_file)) begin
            awg_output_fd = $fopen(awg_output_file, "w");
            if (awg_output_fd == 0) begin
                $display("[QDISP_TB][INIT][FAIL] cannot open AWG output: %0s", awg_output_file);
                finish_simulation(1);
            end else begin
                $fwrite(awg_output_fd, "event_id,cycle,t_cnt,valid_mask,qubit,gate_id,role,payload_valid,payload\n");
                $display("[QDISP_TB][INIT] AWG output: %0s", awg_output_file);
            end
        end
        if (!$value$plusargs("MAX_CYCLES=%d", max_cycles_limit))
            max_cycles_limit = MAX_CYCLES;

        $display("[QDISP_TB][INIT] Bell co-simulation started.");
        $display("[QDISP_TB][INIT] NUM_QUBITS=%0d  FIXED_LATENCY=%0d  TIME_WIDTH=%0d",
                 NUM_QUBITS, FIXED_LATENCY, TIME_WIDTH);

        // Reset
        rst = 1'b1;
        repeat (10) @(posedge clk);
        rst = 1'b0;
        expect_rot_gateid = $test$plusargs("EXPECT_ROT_GATEID");
        expect_trap       = $test$plusargs("EXPECT_TRAP");
        if ($value$plusargs("AWG_EXPECT=%s", awg_expect_file)) begin
            awg_expect_fd = $fopen(awg_expect_file, "r");
            if (awg_expect_fd == 0) begin
                $display("[QDISP_TB][INIT][FAIL] cannot open AWG expect file: %0s", awg_expect_file);
                finish_simulation(1);
            end
            while (!$feof(awg_expect_fd) && (awg_expect_count < AWG_EXPECT_MAX)) begin
                awg_expect_scan = $fscanf(awg_expect_fd, "%d %h %s %d %h\n",
                                          exp_qubit[awg_expect_count],
                                          exp_gate[awg_expect_count],
                                          exp_role_str,
                                          exp_pv_int,
                                          exp_payload[awg_expect_count]);
                if (awg_expect_scan == 5) begin
                    exp_ctrl[awg_expect_count] = (exp_role_str[7:0] == "C");
                    exp_pv[awg_expect_count]   = (exp_pv_int != 0);
                    exp_used[awg_expect_count] = 1'b0;
                    awg_expect_count = awg_expect_count + 1;
                end
            end
            $fclose(awg_expect_fd);
            awg_expect_en = (awg_expect_count > 0);
            $display("[QDISP_TB][INIT] AWG expect: %0s (%0d fires)",
                     awg_expect_file, awg_expect_count);
        end

        // Run until completion or timeout
        for (i = 0; i < max_cycles_limit; i = i + 1) begin
            @(posedge clk);

            // Stop after we've been idle for a while past the last event (gives
            // the AWG fires behind the resume marker time to drain).
            // Using idle_count here instead of (cycle_count - last_quantum_event_cycle):
            // the cross-block write to last_quantum_event_cycle wasn't visible here
            // under Verilator, so that version never triggered. idle_count works in xsim too.
            // Expected-trap path: once the rejection is seen, drain briefly and
            // finish instead of waiting for quantum events that will never come.
            if (expect_trap && (trap_count != 0)) begin
                trap_idle_count = trap_idle_count + 1;
                if (trap_idle_count >= POST_EVENT_IDLE_CYCLES) begin
                    $display("[QDISP_TB][cycle=%0d][DONE] expected trap observed + %0d idle",
                             cycle_count, POST_EVENT_IDLE_CYCLES);
                    finish_simulation(0);
                end
            end

            if ((quantum_event_idx > 0) &&
                (idle_count >= POST_EVENT_IDLE_CYCLES)) begin
                if (resume_stream_seen) begin
                    $display("[QDISP_TB][cycle=%0d][DONE] resume stream complete (%0d events) + %0d idle",
                             cycle_count, resume_event_count, POST_EVENT_IDLE_CYCLES);
                end else begin
                    $display("[QDISP_TB][cycle=%0d][DONE] %0d idle cycles after last event",
                             cycle_count, POST_EVENT_IDLE_CYCLES);
                end
                finish_simulation(0);
            end
        end

        $display("[QDISP_TB][FAIL] timeout at %0d cycles", max_cycles_limit);
        finish_simulation(1);
    end

endmodule
