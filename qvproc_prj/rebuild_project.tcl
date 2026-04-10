set bundle_root [file normalize [file dirname [info script]]]
set project_name qvproc
set project_dir [file join $bundle_root build $project_name]

proc resolve_bundle_paths {bundle_root rel_files} {
    set resolved {}
    foreach rel_file $rel_files {
        lappend resolved [file normalize [file join $bundle_root $rel_file]]
    }
    return $resolved
}

set design_rel_files [list \
  core/ibex/syn/rtl/prim_clock_gating.v \
  core/ibex/rtl/ibex_pkg.sv \
  core/ibex/rtl/ibex_alu.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_assert_dummy_macros.svh \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_assert.sv \
  core/ibex/rtl/ibex_branch_predict.sv \
  core/ibex/rtl/ibex_compressed_decoder.sv \
  core/ibex/vendor/lowrisc_ip/dv/sv/dv_utils/dv_fcov_macros.svh \
  core/ibex/rtl/ibex_controller.sv \
  core/ibex/rtl/ibex_core.sv \
  core/ibex/rtl/ibex_counter.sv \
  core/ibex/rtl/ibex_cs_registers.sv \
  core/ibex/rtl/ibex_csr.sv \
  core/ibex/rtl/ibex_decoder.sv \
  core/ibex/rtl/ibex_dummy_instr.sv \
  core/ibex/rtl/ibex_ex_block.sv \
  core/ibex/rtl/ibex_fetch_fifo.sv \
  core/ibex/rtl/ibex_icache.sv \
  core/ibex/rtl/ibex_id_stage.sv \
  core/ibex/rtl/ibex_if_stage.sv \
  core/ibex/rtl/ibex_load_store_unit.sv \
  core/ibex/rtl/ibex_lockstep.sv \
  core/ibex/rtl/ibex_multdiv_fast.sv \
  core/ibex/rtl/ibex_multdiv_slow.sv \
  core/ibex/rtl/ibex_pmp.sv \
  core/ibex/rtl/ibex_prefetch_buffer.sv \
  core/ibex/rtl/ibex_register_file_ff.sv \
  core/ibex/rtl/ibex_register_file_fpga.sv \
  core/ibex/ibex_register_file_latch.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_ram_1p_pkg.sv \
  core/ibex/rtl/ibex_top.sv \
  core/ibex/rtl/ibex_wb_stage.sv \
  core/ibex/prim_buf.sv \
  core/ibex/prim_generic_buf.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_util_memload.svh \
  core/ibex/prim_generic_ram_1p.sv \
  core/ibex/prim_ram_1p.sv \
  rtl/vproc_pkg.sv \
  rtl/vproc_alu.sv \
  rtl/vproc_cache.sv \
  configs/vproc_config_dual_128_32.sv \
  rtl/vproc_core.sv \
  rtl/vproc_decoder.sv \
  rtl/vproc_dispatcher.sv \
  rtl/vproc_elem.sv \
  rtl/vproc_lsu.sv \
  rtl/vproc_mul.sv \
  rtl/vproc_mul_block.sv \
  rtl/vproc_pending_wr.sv \
  rtl/vproc_pipeline.sv \
  rtl/vproc_pipeline_wrapper.sv \
  rtl/vproc_queue.sv \
  rtl/vproc_result.sv \
  rtl/vproc_sld.sv \
  rtl/vproc_unit_mux.sv \
  rtl/vproc_unit_wrapper.sv \
  rtl/vproc_vreg_wr_mux.sv \
  rtl/vproc_vregfile.sv \
  rtl/vproc_vregpack.sv \
  rtl/vproc_vregunpack.sv \
  rtl/vproc_xif.sv \
  rtl/vproc_top.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_cipher_pkg.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_util_pkg.sv \
  core/ibex/rtl/ibex_tracer_pkg.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_alert_pkg.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_esc_pkg.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_ram_2p_pkg.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_rom_pkg.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_assert_yosys_macros.svh \
  core/ibex/vendor/lowrisc_ip/dv/sv/dv_utils/dv_utils_pkg.sv \
  core/ibex/vendor/lowrisc_ip/dv/sv/dv_utils/dv_report_server.sv \
  core/ibex/vendor/lowrisc_ip/dv/sv/dv_utils/dv_test_status_pkg.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_secded_pkg.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_otp_pkg.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_pad_wrapper_pkg.sv \
  core/ibex/vendor/lowrisc_ip/ip/prim/rtl/prim_assert_standard_macros.svh \
  core/ibex/vendor/lowrisc_ip/dv/sv/dv_utils/dv_vif_wrap.sv \
  core/ibex/vendor/lowrisc_ip/dv/sv/dv_utils/dv_macros.svh \
]

set sim_rel_files [list \
  tb/quantum_cases/vproc_qrg_tb.v \
  tb/quantum_cases/qrv_mf2_direct/vproc_qrv_mf2_direct_tb.v \
  tb/quantum_cases/vproc_qrv_tb.v \
  tb/quantum_cases/vproc_qsg_tb.v \
  tb/quantum_cases/vproc_qpr_tb.v \
  tb/vproc_tb_predef.sv \
  tb/quantum_cases/instruction_qpr.mem \
  tb/quantum_cases/data_qpr.mem \
  tb/quantum_cases/instruction_qsg.mem \
  tb/quantum_cases/data_qsg.mem \
  tb/quantum_cases/instruction_qrv.mem \
  tb/quantum_cases/data_qrv.mem \
  tb/quantum_cases/instruction_qrg.mem \
  tb/quantum_cases/data_qrg.mem \
]

create_project $project_name $project_dir -part xcu55c-fsvh2892-2L-e -force

set_property board_part xilinx.com:au55c:part0:1.0 [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property simulator_language Mixed [current_project]

add_files -fileset sources_1 [resolve_bundle_paths $bundle_root $design_rel_files]
add_files -fileset sim_1     [resolve_bundle_paths $bundle_root $sim_rel_files]

set_property top vproc_top [get_filesets sources_1]
set_property top vproc_qrv_mf2_direct_tb [get_filesets sim_1]
set_property top_lib xil_defaultlib [get_filesets sim_1]

update_compile_order -fileset sources_1
update_compile_order -fileset sim_1

close_project

puts ""
puts "Project recreated successfully."
puts "  Bundle root : $bundle_root"
puts "  Project dir : $project_dir"
puts "  XPR         : [file join $project_dir ${project_name}.xpr]"
