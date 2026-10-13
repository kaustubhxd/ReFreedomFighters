#include "ff.h"
// batch8033.cpp - residue 18 unported list (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x6246a0 (GUESS): cdecl, the first argument is unused. Returns 1 when p starts with ED (bit 5 of p[1] set) or with EF BB BF / EF BB BE.
static u32 f_6246a0(u32 unused, u8 *p) {
  (void)unused;
  u8 c = p[0];
  if (c == 0xed) return (u32)((p[1] >> 5) & 1);
  if (c == 0xef && p[1] == 0xbf) {
    u8 d = p[2];
    if (d == 0xbf || d == 0xbe) return 1u;
  }
  return 0u;
}
PCREG(6246a0, f_6246a0);

// 0x4cc5a0 (GUESS): thiscall, the count is the ecx value. For a count in 1..0xff fills 0x700450 with that many spaces, writes a
// zero byte after them, returns 0x700450. Counts of 0x100 or more are not ported (the exe calls 0x634047 there).
static u8 *THISCALL f_4cc5a0(u8 *self) {
  s32 n = (s32)(unsigned long)self;
  u8 *buf = (u8 *)(unsigned long)0x700450u;
  u32 k = n > 0 ? (u32)n : 0u;
  if (k < 0x100u) {
    for (u32 i = 0; i < k; ++i) buf[i] = 0x20;
    buf[k] = 0;
  }
  return buf;
}
PCREG(4cc5a0, f_4cc5a0);
