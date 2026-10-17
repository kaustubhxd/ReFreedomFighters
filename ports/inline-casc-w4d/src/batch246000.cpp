// batch246000.cpp - Sonnet-w4d, tier 6/7 hand ports.
#include "ff.h"

// 0x628ed0: cdecl, 4 stack args; overwrites arg 0 with 0x6be728 and tail-jumps into 0x622ad0 (cdecl, 4 args, plain ret).
extern "C" u32 ext_622ad0(u32 a, u32 b, u32 c, u32 d);
extern "C" u32 GUESS_628ed0(u32 a, u32 b, u32 c, u32 d) {
  (void)a;
  return ext_622ad0(0x6be728u, b, c, d);
}
PCREG(628ed0, GUESS_628ed0);

// 0x62cf00: cdecl (obj, code). code 0xf -> 0; 0x19 -> obj[2]++, obj[0]=0x62dbb0, 0; else (obj[3]==0 && code==0x1c) -> 0x34
// else obj[0]=0x51f230, -1.
extern "C" u32 GUESS_62cf00(u32 *obj, u32 code) {
  if (code == 0xf) return 0;
  if (code == 0x19) {
    obj[2]++;
    obj[0] = 0x62dbb0;
    return 0;
  }
  if (obj[3] == 0 && code == 0x1c) return 0x34;
  obj[0] = 0x51f230;
  return 0xffffffffu;
}
PCREG(62cf00, GUESS_62cf00);

// 0x499810: thiscall ret 8 (p, v). Stores v into the slot (p - this->+0x14->[1]) / 112 - this->+0x28 / 112 of the table at
// *(this+0x5d) (unaligned). If p[0x3c] has bit 27 the original stores v through a null pointer.
extern "C" u32 THISCALL GUESS_499810(u8 *self, u32 *p, u32 v) {
  if (p[0x3c / 4] & 0x8000000u) {
    *(volatile u32 *)0 = v;
    return v;
  }
  u32 base;
  __builtin_memcpy(&base, (u8 *)*(u32 *)(self + 0x14) + 4, 4);
  s32 d = (s32)((u32)(u32)p - base);
  s32 hi = (s32)(((long long)d * (long long)(s32)0x92492493) >> 32);
  s32 q = (s32)((u32)hi + (u32)d) >> 6;
  s32 q1 = q + (s32)((u32)q >> 31);
  u32 n = *(u32 *)(self + 0x28);
  u32 t = (u32)(((u64)n * 0x24924925ull) >> 32);
  u32 q2 = ((((n - t) >> 1) + t) >> 6);
  u32 tbl;
  __builtin_memcpy(&tbl, self + 0x5d, 4);
  *(u32 *)(tbl + (u32)(q1 - (s32)q2) * 4) = v;
  return v;
}
PCREG(499810, GUESS_499810);
