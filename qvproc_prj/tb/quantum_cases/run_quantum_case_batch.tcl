set script_dir [file normalize [file dirname [info script]]]

set project_candidates [list \
  [file normalize [file join $script_dir .. .. qvproc qvproc.xpr]] \
  [file normalize [file join $script_dir .. .. build qvproc qvproc.xpr]] \
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

set quantum_root $script_dir

if {[info exists ::env(QUANTUM_CASE)]} {
  set quantum_case $::env(QUANTUM_CASE)
} else {
  set quantum_case "qpr"
}

set valid_cases {qsg qpr qrg qrv bell}
if {[lsearch -exact $valid_cases $quantum_case] < 0} {
  puts "ERROR: QUANTUM_CASE must be one of: qsg qpr qrg qrv bell"
  exit 1
}

set tb_file [file normalize [file join $quantum_root "vproc_${quantum_case}_tb.v"]]
set instr_file [file normalize [file join $quantum_root "instruction_${quantum_case}.mem"]]
set data_file [file normalize [file join $quantum_root "data_${quantum_case}.mem"]]

if {[info exists ::env(QUANTUM_INSTR_FILE)] && ($::env(QUANTUM_INSTR_FILE) ne "")} {
  set instr_file [file normalize $::env(QUANTUM_INSTR_FILE)]
}
if {[info exists ::env(QUANTUM_DATA_FILE)] && ($::env(QUANTUM_DATA_FILE) ne "")} {
  set data_file [file normalize $::env(QUANTUM_DATA_FILE)]
}

set tb_top "vproc_${quantum_case}_tb"

open_project $project_path

set simset [get_filesets sim_1]
set_property -name {xsim.elaborate.xelab.more_options} -value {} -objects $simset

foreach f [list $tb_file $instr_file $data_file] {
  if {[llength [get_files -quiet $f]] == 0} {
    add_files -fileset sim_1 -norecurse $f
  }
}

set_property top $tb_top $simset
set_property top_lib xil_defaultlib $simset
set_property -name {xsim.simulate.xsim.more_options} \
  -value [format {-testplusarg INSTR_MEM_FILE=%s -testplusarg DATA_MEM_FILE=%s} $instr_file $data_file] \
  -objects $simset

update_compile_order -fileset sim_1

puts "== Quantum batch simulation =="
puts [format "project : %s" $project_path]
puts [format "case    : %s" $quantum_case]
puts [format "top     : %s" $tb_top]
puts [format "instr   : %s" $instr_file]
puts [format "data    : %s" $data_file]

close_sim -quiet
reset_simulation

if {[catch {launch_simulation} sim_err]} {
  puts "ERROR: launch_simulation failed"
  puts $sim_err
  close_project
  exit 1
}

if {[catch {run all} run_err]} {
  puts "ERROR: run all failed"
  puts $run_err
  close_sim -quiet
  close_project
  exit 1
}

close_sim
close_project
exit
