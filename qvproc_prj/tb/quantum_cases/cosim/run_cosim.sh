#!/usr/bin/env bash
# Compatibility shim: run_cosim.sh -> run.sh
# Use run.sh for all new work.
exec "$(dirname "$0")/run.sh" "$@"
