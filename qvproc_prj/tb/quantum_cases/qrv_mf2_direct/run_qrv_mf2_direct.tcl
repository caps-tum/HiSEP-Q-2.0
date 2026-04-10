set script_dir [file normalize [file dirname [info script]]]

set project_candidates [list \
  [file normalize [file join $script_dir .. .. .. qvproc qvproc.xpr]] \
  [file normalize [file join $script_dir .. .. .. build qvproc qvproc.xpr]] \
]

set project_path ""
foreach candidate $project_candidates {
  if {[file exists $candidate]} {
    set project_path $candidate
    break
  }
}

if {$project_path eq ""} {
  puts "ERROR: Could not find qvproc.xpr. Expected one of:"
  foreach candidate $project_candidates {
    puts "  $candidate"
  }
  exit 1
}

set debug_root   $script_dir
set tb_file      [file normalize [file join $debug_root "vproc_qrv_mf2_direct_tb.v"]]
set tb_top       "vproc_qrv_mf2_direct_tb"
set vcd_file     [file normalize [file join $debug_root "qrv_mf2_direct.vcd"]]

open_project $project_path

set simset [get_filesets sim_1]
set_property -name {xsim.elaborate.xelab.more_options} -value {} -objects $simset

if {[llength [get_files -quiet $tb_file]] == 0} {
  add_files -fileset sim_1 -norecurse $tb_file
}

set_property top $tb_top $simset
set_property top_lib xil_defaultlib $simset
set_property -name {xsim.simulate.xsim.more_options} -value {} -objects $simset

update_compile_order -fileset sim_1

puts "== QRV MF2 direct debug simulation =="
puts [format "top : %s" $tb_top]
puts [format "tb  : %s" $tb_file]
puts [format "vcd : %s" $vcd_file]

close_sim -quiet
reset_simulation

if {[catch {launch_simulation} sim_err]} {
  puts "ERROR: launch_simulation failed"
  puts $sim_err
  close_project
  exit 1
}

log_wave -recursive /*
open_vcd $vcd_file
log_vcd [get_objects -r /*]

if {[catch {run all} run_err]} {
  puts "ERROR: run all failed"
  puts $run_err
  catch {close_vcd}
  close_sim -quiet
  close_project
  exit 1
}

close_vcd
close_sim
close_project
exit
