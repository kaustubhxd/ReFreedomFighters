// batch5712.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 12: three small thiscall functions with one stack argument (ret 4).
#include "ff.h"

// 0x4db580 (GUESS, unnamed): idx = arg; n = byte this+0x1c; returns 0 if idx >= n (unsigned), else the dword at this + idx * 4.
static u32 THISCALL unnamed4db580(u8 *self, u32 idx) {
  u32 n = self[0x1c];
  if (idx >= n) return 0;
  return *(u32 *)(self + idx * 4);
}
PCREG(4db580, unnamed4db580);

// 0x5ea840, ZGameOSD::SetBombTime(float) (low): if 0.0 > a, the dword this+0x1d13 = 0; otherwise it is the bits of a (movss).
static void THISCALL gameOsdSetBombTime(u8 *self, float a) {
  if (0.0f > a) *(u32 *)(self + 0x1d13) = 0;
  else *(u32 *)(self + 0x1d13) = fbits(a);
}
PCREG(5ea840, gameOsdSetBombTime);

// 0x533500 (GUESS, unnamed): if the dword this+0x546e is non-zero, returns the dword at this + idx * 4 + 0x5462; else 0.
static u32 THISCALL unnamed533500(u8 *self, u32 idx) {
  if (*(u32 *)(self + 0x546e) != 0) return *(u32 *)(self + (u32)(idx * 4 + 0x5462));
  return 0;
}
PCREG(533500, unnamed533500);
