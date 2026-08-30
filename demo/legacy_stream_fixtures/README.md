# Legacy stream fixtures (not regression tests)

These four images feed vector arithmetic data that is not a valid
bounded-qubit stream: indices go out of range and the dispatcher reports
hundreds of error pulses by design-mismatch, not by defect. They were kept
for raw-stream observation only and always FAILed the unified testbench.

Moved out of `demo/` on 2026-08-30 so the regression glob stays green-on-good.
Directed replacements with exact scoreboards live in `demo/` as
`qv_rot_gateid/vl1/chunk/m1/m2.mem` and the other `qv_*` cases.

Run one manually if needed:

    cd demo/verilator
    ./run_verilator.sh --mem ../legacy_stream_fixtures/qv_single.mem
