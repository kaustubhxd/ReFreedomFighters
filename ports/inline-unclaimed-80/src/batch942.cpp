#include "ff.h"
// batch942.cpp - unclaimed-80 (docs/20-unclaimed-80.md): GUESS FUN_460bb0 (0x460bb0, no name in the map). Thiscall, no arguments, returns
// bool in al. ref = (float)this+4 / (float)count, where count = this+0x10; limit = ref * C (C at 0x67a288). Result is 1 unless, for some
// item (count items at (this+0xc) + 0x38*i, value at +0x34 of each), |ref - value| > limit (strict, as comiss/cmova). No calls, no writes.

static u8 THISCALL guessFun460bb0(u8 *self) {
  float ref = *(float *)(self + 4) / (float)(*(s32 *)(self + 0x10));
  float C = G(float, 0x67a288);
  float limit = ref * C;
  u8 res = 1;
  u32 count = *(u32 *)(self + 0x10);
  if (count != 0) {
    u8 *p = *(u8 **)(self + 0xc) + 0x34;
    for (u32 i = 0; i < count; i++) {
      float d = ref - *(float *)p;
      u32 bits = *(u32 *)&d & 0x7fffffffu;
      float a = *(float *)&bits;
      if (a > limit)
        res = 0;
      p += 0x38;
    }
  }
  return res;
}
PCREG(460bb0, guessFun460bb0);
