// batch5715.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 15: ZMoveOnSpline::GetCurrentSoundSet() (0x512f80, high name),
// thiscall, no arguments. If the engine's dword at +0x1a9f is 0 (engine = global 0x70039c), returns 0; otherwise returns the dword
// at this+0x12f.
#include "ff.h"

#define G(T, addr) (*(T *)(addr))

static u32 THISCALL moveOnSplineGetCurrentSoundSet(u8 *self) {
  u8 *engine = G(u8 *, 0x70039c);
  if (*(u32 *)(engine + 0x1a9f) == 0) return 0;
  return *(u32 *)(self + 0x12f);
}
PCREG(512f80, moveOnSplineGetCurrentSoundSet);
