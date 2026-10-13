// batch1132.cpp - collision thread, batch 1132: 0x4e31f0 (name GUESS): pops the first 9-byte record of a heap. Calls the
// sift-down 0x4e3230 (fastcall: ECX = base - 9, EDX = new count, one stack argument start = 1, ret 4), which is stubbed by
// address in the spec (its body is not verified here).
#include "ff.h"

extern "C" void FASTCALL ext_4e3230(u8 *base, u32 count, u32 start);   // exe: sift-down, ret 4; stubbed by address

// 0x4e31f0 (name GUESS): fastcall (ECX = base, EDX = count), one stack argument out, ret 4. Copies the 9-byte record at base
// to out, moves the record at index count-1 to base, sets count-1 and sifts from index 1. Returns out.
static u8 *FASTCALL popFirst1132(u8 *base, u32 count, u8 *out) {
  __builtin_memcpy(out, base, 8);
  out[8] = base[8];
  u8 *last = base + 9 * (count - 1);
  __builtin_memcpy(base, last, 8);
  base[8] = last[8];
  count = count - 1;
  ext_4e3230(base - 9, count, 1u);
  return out;
}
PCREG(4e31f0, popFirst1132);
