// batch1046.cpp - unclaimed-04 batch 46 (docs/20-unclaimed-04.md): 0x497670, thiscall, one stack argument (ret 4).
// The flagged path (bit 0x8000000 of arg+0x3c) loads address 0 in the exe, so it is outside the contract and not ported.
#include "ff.h"

// 0x497670
static u32 THISCALL unk497670(u8 *self, u32 arg) {
  u32 x = arg - *(u32 *)(*(u32 *)(self + 0x14) + 4);
  long long p1 = (long long)(s32)0x92492493u * (long long)(s32)x;
  s32 hi = (s32)(p1 >> 32);
  u32 e = (u32)hi + x;
  s32 q = (s32)e >> 6;
  u32 esi = (u32)q + ((u32)q >> 31);
  u64 p2 = (u64)0x24924925u * (u64)*(u32 *)(self + 0x28);
  u32 hi2 = (u32)(p2 >> 32);
  u32 ecx = *(u32 *)(self + 0x28);
  ecx = ecx - hi2;
  ecx = ecx >> 1;
  ecx = ecx + hi2;
  ecx = ecx >> 6;
  esi = esi - ecx;
  u32 base = *(u32 *)(self + 0x5d);
  return *(u32 *)(base + esi * 4);
}
PCREG(497670, unk497670);
