// batch1032.cpp - area 81, batch 1032: 0x512fa0, thiscall (this), no stack arguments, plain ret. Cookie check not reproduced (none in this function). The object
// at this+0x12b is called with slot 0x14 (no arguments), slot 0x4c (the local out pointer), then slot 0x64 (the local out pointer) for the first record. While
// the record's float * 1024 is not below the tick (sys+0x40), the next record is taken from slot 0x64; a null record returns 0. When the float is below the tick,
// the record's float at +4 becomes float(tick + 0x5000) / 1024 and the result is the record's first dword.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x512fa0 (thiscall: this).
static u32 THISCALL recordLoopTick(u8 *self) {
  vcall<u32>((void *)D(self, 0x12b), 0x14);
  u8 *o = (u8 *)D(self, 0x12b);
  if (!o)
    return 0;
  u32 L = 0;
  vcall<void>(o, 0x4c, (u32)&L);
  o = (u8 *)D(self, 0x12b);
  u8 *C = (u8 *)vcall<u32>(o, 0x64, (u32)&L);
  if (!C)
    return 0;
  for (;;) {
    u8 *sys = *(u8 **)0x70039c;
    int t = (int)(*(float *)(C + 4) * 1024.0f);
    if (t < (int)D(sys, 0x40)) {
      *(float *)(C + 4) = (float)(int)(D(sys, 0x40) + 0x5000u) * 0.0009765625f;
      return D(C, 0);
    }
    o = (u8 *)D(self, 0x12b);
    C = (u8 *)vcall<u32>(o, 0x64, (u32)&L);
    if (!C)
      return 0;
  }
}
PCREG(512fa0, recordLoopTick);
