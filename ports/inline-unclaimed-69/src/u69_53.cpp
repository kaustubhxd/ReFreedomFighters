// u69_53.cpp - area 69, group 53 (slice 8). A ring index modulo 1000 with signed handling, then a table read. No callees.
#include "ff.h"

// n / 1000 for an unsigned 32-bit n, as the original does it: high dword of n * 0x10624dd3, shifted right by 6.
static u32 divBy1000(u32 n) {
  return (u32)(((u64)n * 0x10624dd3u) >> 32) >> 6;
}

// 0x4d4480, thiscall one stack arg (x, ret 4). x == 0 returns self+0x1007 (the address). Otherwise c = counter(+0xfb3) + x must lie in [-1000, 1000] (signed),
// else the result is 0x677b5a. The index is base(+0xfaf) + counter + x, reduced into [0, 1000) (with the negative case handled first), and the result is the dword at self+0xf + 4*index.
static u32 THISCALL ringIndex4d4480(u8 *self, u32 x) {
  if (x == 0)
    return (u32)(self + 0x1007);
  u32 counter = *(u32 *)(self + 0xfb3);
  s32 c = (s32)(counter + x);
  if (c > 0x3e8)
    return 0x677b5a;
  if (c < -0x3e8)
    return 0x677b5a;
  u32 esi = *(u32 *)(self + 0xfaf) + counter + x;
  if ((s32)esi < 0) {
    u32 n = (u32)-1 - esi;
    esi += 0x3e8;
    esi += divBy1000(n) * 0x3e8;
  }
  if ((s32)esi > 0x3e7) {
    u32 n = esi - 0x3e8;
    u32 q = divBy1000(n);
    esi += 0xfffffc18u - q * 0x3e8;
  }
  return *(u32 *)(self + esi * 4 + 0xf);
}
PCREG(4d4480, ringIndex4d4480);
