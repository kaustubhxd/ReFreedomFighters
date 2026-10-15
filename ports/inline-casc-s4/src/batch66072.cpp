// batch66072.cpp - cascade s4 batch 66072: 0x5bdd30 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *ext_41e290(u32 n);   // cdecl

static u32 sat_mul(u32 a, u32 b) {
  u64 p = (u64)a * b;
  return p > 0xffffffffull ? 0xffffffffu : (u32)p;
}

// 0x5bdd30, thiscall(src) ret 4, returns this (this = t): t[4] = s[4]; t[8] = s[8]; t[0] = s[0]; t[0xc] = t[0x10] = 0; n = t[8] == 0 -> return.
// Otherwise t[0xc] = alloc(n * 16), t[0x10] = alloc(n * 4), t[0x14] = alloc(n * 4) (sizes saturate at 0xffffffff); for i < n (signed): t[0x10][i] = s[0x10][i]; t[0x14][i] = s[0x14][i]; the 4 dwords of record i of s[0xc] are copied to t[0xc].
static u8 *THISCALL fn5bdd30(u8 *t, u8 *s) {
  wr(t + 4, rd(s + 4));
  wr(t + 8, rd(s + 8));
  wr(t, rd(s));
  u32 n = rd(t + 8);
  wr(t + 0xc, 0);
  wr(t + 0x10, 0);
  if (!n) return t;
  wr(t + 0xc, (u32)ext_41e290(sat_mul(n, 16)));
  wr(t + 0x10, (u32)ext_41e290(sat_mul(rd(t + 8), 4)));
  wr(t + 0x14, (u32)ext_41e290(sat_mul(rd(t + 8), 4)));
  for (s32 i = 0; i < (s32)rd(t + 8); i++) {
    wr(*(u8 **)(t + 0x10) + i * 4, rd(*(u8 **)(s + 0x10) + i * 4));
    wr(*(u8 **)(t + 0x14) + i * 4, rd(*(u8 **)(s + 0x14) + i * 4));
    u8 *sr = *(u8 **)(s + 0xc) + i * 16;
    u8 *dr = *(u8 **)(t + 0xc) + i * 16;
    wr(dr, rd(sr));
    wr(dr + 4, rd(sr + 4));
    wr(dr + 8, rd(sr + 8));
    wr(dr + 12, rd(sr + 12));
  }
  return t;
}
PCREG(5bdd30, fn5bdd30);
