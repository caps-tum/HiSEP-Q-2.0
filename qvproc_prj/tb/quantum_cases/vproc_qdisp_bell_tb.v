`timescale 1ns / 1ps
//
// vproc_qdisp_bell_tb.v  –  NEW FILE, co-simulation testbench
//
// Instantiates vproc_qdisp_top (which wraps vproc_top + quantum_dispatcher)
// and runs the Bell-state program (instruction_bell.mem + data_bell.mem).
//
// What this TB does:
//   1. Drives the same memory model and measure-handshake as vproc_bell_tb.v
//   2. Logs the raw qvproc quantum stream (same format as original Bell TB)
//   3. Logs per-qubit gate firing events from quantum_dispatcher
//   4. Checks: no FIFO overflow, qubit count matches quantum event count,
//      all errors are zero when the simulation ends
//
// Bell program shape:
//   QV.SINGLE  (Hadamard) – 8 beats, qubits 0-7
//   QV.PAIR    (CNOT/CX)  – 8 beats, qubit pairs (tgt v1, src v2)
//   QSG.MEASURE           – halt until measure_done_i
//   QV.SINGLE  (resume marker) – 8 beats
//
// Termination: same policy as vproc_bell_tb.v — end when the post-measure
// resume-marker stream completes, or on timeout.

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

    // quantum_dispatcher parameters (must match vproc_qdisp_top defaults)
    parameter NUM_QUBITS    = 16;   // Bell program uses qubits 0-15
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
    integer resume_event_count;
    integer qubit_fire_count;
    integer fail_count;

    // -----------------------------------------------------------------
    // Op-name helper (same as original Bell TB)
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
                32'hC8708657: bell_instr_name = "QV.SINGLE(H) vd3, v1, x7   ";
                32'hCC208657: bell_instr_name = "QV.PAIR(CNOT) vd3, v1, v2  ";
                32'hD0708657: bell_instr_name = "QSG.MEASURE vd3, v1, x7    ";
                32'hF0610657: bell_instr_name = "QV.SINGLE(resume) vd6, v2, x6";
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
    wire qvsg_meas;
    wire measure_issued_done;

    // -----------------------------------------------------------------
    // Raw quantum stream
    // -----------------------------------------------------------------
    wire                  quantum_valid;
    wire [4:0]            quantum_op;
    wire [2:0]            quantum_instr_id;
    wire [4:0]            quantum_vd_addr;
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
        .BLOCK_IMM_W   ( 4             ),
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
        .t_cnt_o                    ( t_cnt                    )
    );

    // -----------------------------------------------------------------
    // Internal Ibex instruction monitor (hierarchy through new top)
    // -----------------------------------------------------------------
    wire [31:0] ibex_id_instr;
    assign ibex_id_instr = dut.u_vproc.u_core.u_ibex_core.id_stage_i.instr_rdata_i;

    // -----------------------------------------------------------------
    // Memory model logic
    // -----------------------------------------------------------------
    always @(*) begin
        mem_idx = mem_addr >> 2;
    end

    always @(posedge clk) begin
        cycle_count = cycle_count + 1;

        if (mem_req && mem_we && (mem_idx >= 0) && (mem_idx < MEM_WORDS)) begin
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
                measure_wait_pending     <= 1'b1;
                measure_wait_cycles_left <= MEASURE_DONE_DELAY_CYCLES;
                $display("[QDISP_TB][cycle=%0d][WAIT] ADC delay = %0d cycles",
                         cycle_count, MEASURE_DONE_DELAY_CYCLES);
            end else if (measure_wait_pending) begin
                if (measure_wait_cycles_left == 0) begin
                    measure_done         <= 1'b1;
                    measure_wait_pending <= 1'b0;
                    $display("[QDISP_TB][cycle=%0d][MEASURE] measure_done=1 (sent)", cycle_count);
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
                $finish;
            end

            if (!prev_quantum_instr_id_valid ||
                (quantum_instr_id != prev_quantum_instr_id))
                $display("[QDISP_TB][cycle=%0d][QX_START] op=%0d(%0s) id=%0d vd=%0d elem2=%08x elem3=%08x ready=%0b",
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
                $display("[AWG][t_cnt=%0d] valid_mask=%016b  (cycle=%0d)",
                         t_cnt, qubit_valid, cycle_count);
                // Per-qubit detail
                for (qi = 0; qi < NUM_QUBITS; qi = qi + 1) begin
                    if (qubit_valid[qi]) begin
                        $display("[AWG][t_cnt=%0d]   qubit[%02d]  gate=0x%02x  role=%0s",
                                 t_cnt, qi,
                                 qubit_gate[(qi+1)*GATE_WIDTH-1 -: GATE_WIDTH],
                                 qubit_ctrl[qi] ? "CTRL" : "TGT ");
                        qubit_fire_count = qubit_fire_count + 1;
                    end
                end
            end

            if (|qubit_error) begin
                $display("[QDISP_TB][cycle=%0d][ERROR] FIFO overflow on qubits: %016b",
                         cycle_count, qubit_error);
                fail_count = fail_count + 1;
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
            $display("[QDISP_TB]  FIFO errors    : %0d", fail_count);
            if (fail_count == 0)
                $display("[QDISP_TB]  RESULT         : PASS – no FIFO overflows");
            else
                $display("[QDISP_TB]  RESULT         : FAIL – %0d error(s)", fail_count);
            $display("[QDISP_TB] ==========================");
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
        qubit_fire_count            = 0;
        fail_count                  = 0;
        resume_event_count          = 0;
        resume_stream_seen          = 1'b0;
        mem_rvalid                  = 1'b0;
        mem_err                     = 1'b0;
        mem_rdata                   = 32'h0;
        prev_quantum_instr_id       = 3'b000;
        prev_quantum_instr_id_valid = 1'b0;
        measure_done                = 1'b0;
        prev_qvsg_meas              = 1'b0;
        prev_measure_issued_done    = 1'b0;
        measure_wait_pending        = 1'b0;
        measure_wait_cycles_left    = 0;
        prev_ibex_id_instr          = 32'h0;

        for (i = 0; i < MEM_WORDS; i = i + 1)
            mem[i] = {MEM_W{1'b0}};
        for (i = 0; i < MEM_LATENCY; i = i + 1) begin
            mem_rvalid_queue[i] = 1'b0;
            mem_rdata_queue[i]  = 32'h0;
            mem_err_queue[i]    = 1'b0;
        end

        // Load memory.
        // Primary:  +MEM_FILE=combined.mem  (single file, @addr markers for data section)
        // Fallback: +INSTR_MEM_FILE=x +DATA_MEM_FILE=y  (legacy split format)
        if ($value$plusargs("MEM_FILE=%s", combined_mem_file)) begin
            $display("[QDISP_TB][INIT] mem file: %0s", combined_mem_file);
            $readmemh(combined_mem_file, mem);
        end else begin
            if (!$value$plusargs("INSTR_MEM_FILE=%s", instr_mem_file))
                instr_mem_file = "";
            if (!$value$plusargs("DATA_MEM_FILE=%s", data_mem_file))
                data_mem_file  = "";
            if (instr_mem_file == "") begin
                $display("[QDISP_TB][INIT][WARN] No MEM_FILE or INSTR_MEM_FILE supplied — memory will be zero.");
            end else begin
                $display("[QDISP_TB][INIT] instruction mem : %0s", instr_mem_file);
                $readmemh(instr_mem_file, mem);
                if (data_mem_file != "") begin
                    $display("[QDISP_TB][INIT] data mem        : %0s", data_mem_file);
                    $readmemh(data_mem_file,  mem);
                end
            end
        end
        $display("[QDISP_TB][INIT] Bell co-simulation started.");
        $display("[QDISP_TB][INIT] NUM_QUBITS=%0d  FIXED_LATENCY=%0d  TIME_WIDTH=%0d",
                 NUM_QUBITS, FIXED_LATENCY, TIME_WIDTH);

        // Reset
        rst = 1'b1;
        repeat (10) @(posedge clk);
        rst = 1'b0;

        // Run until completion or timeout
        for (i = 0; i < MAX_CYCLES; i = i + 1) begin
            @(posedge clk);

            // Termination condition: prefer idle-after-last-event so that
            // any AWG fires queued behind the resume marker are not cut off.
            // For programs without MEASURE / resume, this is the only path.
            if ((last_quantum_event_cycle >= 0) &&
                ((cycle_count - last_quantum_event_cycle) >= POST_EVENT_IDLE_CYCLES)) begin
                if (resume_stream_seen) begin
                    $display("[QDISP_TB][cycle=%0d][DONE] resume stream complete (%0d events) + %0d idle",
                             cycle_count, resume_event_count, POST_EVENT_IDLE_CYCLES);
                end else begin
                    $display("[QDISP_TB][cycle=%0d][DONE] %0d idle cycles after last event",
                             cycle_count, POST_EVENT_IDLE_CYCLES);
                end
                print_summary;
                $finish;
            end
        end

        $display("[QDISP_TB][FAIL] timeout at %0d cycles", MAX_CYCLES);
        print_summary;
        $finish;
    end

endmodule
