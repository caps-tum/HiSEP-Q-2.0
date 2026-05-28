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

# --verilog-data-width=4 : one 32-bit word per output line (matches MEM_W=32)
"$OBJCOPY" -O verilog --verilog-data-width=4 "$ELF" "$TMP"

# Convert byte addresses (@HHHHHHHH) to word addresses (divide by 4),
# and byte-swap each 32-bit word.
#
# objcopy -O verilog outputs bytes in memory order (LSB first for LE targets),
# so "0x06600313" appears as "13036006".  $readmemh treats hex strings as
# big-endian integers, so we must reverse the byte order to get the right value.
#
# Each data line may contain multiple space-separated 8-hex-char words.
# Note: uses "0x"hex+0 for hex parsing (POSIX awk compatible, no gawk needed).
awk '
function bswap32(w,    b0,b1,b2,b3) {
    b0 = substr(w, 1, 2)
    b1 = substr(w, 3, 2)
    b2 = substr(w, 5, 2)
    b3 = substr(w, 7, 2)
    return toupper(b3 b2 b1 b0)
}

/^@/ {
    byte_addr = "0x" substr($0, 2) + 0
    printf "@%08x\n", byte_addr / 4
    next
}

{
    for (i = 1; i <= NF; i++)
        printf "%s\n", bswap32($i)
}
' "$TMP" > "$OUT"

echo "elf2mem: $ELF  ->  $OUT"
