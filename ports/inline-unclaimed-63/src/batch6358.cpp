// batch6358.cpp - unclaimed-63 batch 58: 0x478aa0 ZActor::GetAnimHeader(unsigned int) (core list name), stdcall, one stack argument x, ret 4.
//   Returns 0 if x == 0; else [[[0x70039c] + 0x9b] + 0x44] + x (no ECX use).
#include "ff.h"

// 0x478aa0.
static u32 STDCALL unnamed478aa0(u32 x) {
  if (x == 0)
    return 0;
  u32 db = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  return *(u32 *)(db + 0x44) + x;
}
PCREG(478aa0, unnamed478aa0);
