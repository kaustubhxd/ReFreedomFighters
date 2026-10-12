// batch213.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. A pure function (no calls):
// it sets the top byte of the dword at offset 36 of 40-byte entries in an array (pointer at obj+4, obj at [this+0x3a]).
#include "ff.h"

typedef int i32;

// cvttss2si as the x86 instruction does it: out-of-range and NaN give 0x80000000.
static i32 cvtt_f32(float f) {
  if (!(f > -2147483649.0f && f < 2147483648.0f)) return (i32)0x80000000u;
  return (i32)f;
}

// 0x5ec2b0, thiscall(a float, b): k = (cvtt(a * 255.0f)) << 24. If b == -1: count = [this+0x3e] (unsigned); for i in
// 0..count-1, the dword at entry_i + 36 is replaced by (old & 0xffffff) | k, with entry_i = ptr + 40*i. Otherwise only
// entry b is updated the same way. ptr = [[this+0x3a] + 4]. Name GUESS.
static void THISCALL setTopByte_5ec2b0(u8 *self, float a, u32 b) {
  u32 k = (u32)cvtt_f32(a * 255.0f) << 24;
  if (b == 0xffffffffu) {
    u32 count = *(u32 *)(self + 0x3e);
    for (u32 i = 0; i < count; ++i) {
      u8 *ptr = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
      u32 *v = (u32 *)(ptr + 40 * i + 36);
      *v = (*v & 0xffffffu) | k;
    }
  } else {
    u8 *ptr = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
    u32 *v = (u32 *)(ptr + 40 * b + 36);
    *v = (*v & 0xffffffu) | k;
  }
}
PCREG(5ec2b0, setTopByte_5ec2b0);
