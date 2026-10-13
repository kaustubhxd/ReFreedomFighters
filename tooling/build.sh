#!/bin/sh
# Mac build for the decomp pilot harness (no ld.lld/llvm-nm/llvm-objcopy needed).
# Usage: sh build.sh <thread folder>   e.g. sh decomp-pilot/shared-harness/build.sh decomp-pilot/inline-ladder
# Builds <folder>/src/*.cpp for i686 ELF with Apple clang, links with mini_ld.py at 0x31000000.
# Output: <folder>/build/pilot.bin and pilot.syms (what harness/pilot.py loads).
set -e
SH=$(cd "$(dirname "$0")" && pwd)
HERE=$(cd "${1:-$SH/..}" && pwd)
OUT=${PILOT_BUILD:-$HERE/build}
mkdir -p "$OUT/obj"
CXXFLAGS="--target=i686-linux-gnu -O2 -msse2 -mfpmath=sse -fno-pic -fno-pie -ffreestanding -fno-builtin -fno-exceptions \
 -fno-rtti -fno-stack-protector -fno-asynchronous-unwind-tables -fno-threadsafe-statics -std=c++20 \
 -ffp-contract=off -fno-strict-aliasing -Wall -Wno-unused-function -I$HERE/src -I$SH"
objs=""
for f in "$HERE"/src/*.cpp; do
  o="$OUT/obj/$(basename "$f" .cpp).o"
  clang++ $CXXFLAGS -c "$f" -o "$o"
  objs="$objs $o"
done
PY=${PY:-$SH/../../tools/venv/bin/python3}
"$PY" -I "$SH/mini_ld.py" --base 0x31000000 -o "$OUT/pilot.bin" --syms "$OUT/pilot.syms" $objs
