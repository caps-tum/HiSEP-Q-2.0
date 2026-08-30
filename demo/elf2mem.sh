#!/usr/bin/env bash
# elf2mem.sh  –  Convert a RISC-V ELF to a $readmemh-compatible hex file.
#
# objcopy -O verilog emits byte-addressed @ADDR markers; $readmemh for a
# 32-bit-wide memory array needs word addresses, so this script divides
# every address by 4 before writing the output file.
#
# Usage:
#   ./elf2mem.sh <input.elf> [output.mem]
#
# Environment:
#   RISCV_OBJCOPY  – override the objcopy binary (default: riscv32-unknown-elf-objcopy)
#
# Example:
#   ./elf2mem.sh build/bell.elf bell_combined.mem
#   ./elf2mem.sh build/bell.elf               # produces build/bell.mem

set -euo pipefail

OBJCOPY="${RISCV_OBJCOPY:-riscv32-unknown-elf-objcopy}"

if [[ $# -lt 1 ]]; then
    echo "Usage: $0 <input.elf> [output.mem]" >&2
    exit 1
fi

ELF="$1"
if [[ $# -ge 2 ]]; then
    OUT="$2"
else
    OUT="${ELF%.elf}.mem"
fi

if [[ ! -f "$ELF" ]]; then
    echo "Error: ELF file not found: $ELF" >&2
    exit 1
fi

TMP=$(mktemp --suffix=.mem)
trap 'rm -f "$TMP"' EXIT

# --verilog-data-width=4 : one 32-bit word per output line (matches MEM_W=32).
#
# With this flag, recent GNU binutils (≥ 2.40-ish) emits:
#   - one 32-bit word per token in already-big-endian hex (e.g. "06600313"),
#   - @-markers in WORD addresses (not byte addresses).
# That format is already what the testbench's $readmemh expects, so we only
# need to split multi-word lines into one-word-per-line and uppercase them.
"$OBJCOPY" -O verilog --verilog-data-width=4 "$ELF" "$TMP"

awk '
{ sub(/\r$/, "") }                # strip trailing CR (objcopy 2.42 quirk)
# .text is linked at 0x0 but Ibex boots at byte 0x80 (word 0x20); the
# testbench relocates marker-less images there, but an explicit @00000000
# would pin the code at word 0 and boot into mid-program garbage. Map the
# text marker to the boot address; data markers (@00000400) stay absolute.
/^@/ { if (toupper($0) == "@00000000") { print "@00000020" } else { print toupper($0) }; next }
{
    for (i = 1; i <= NF; i++)
        print toupper($i)
}
' "$TMP" > "$OUT"

echo "elf2mem: $ELF  ->  $OUT"
