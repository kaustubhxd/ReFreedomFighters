#include "ff.h"
// batch2716.cpp - unclaimed-27 batch 16 (docs/20-unclaimed-27.md). Name from the GC name map (high).

// 0x513040, ZMoveOnSpline::GetExitRef() (high). Thiscall, no arguments, returns eax.
// n = slot +0x14 of the object at this+0x127 (no args). If n <= 0 returns 0. Else r = slot +0x1bc of the global at 0x70039c
// with (0x69e4bc, 0x4bc); returns slot +0x30 of the object at this+0x127 with the signed remainder r % n.
static u32 THISCALL zMoveOnSplineGetExitRef(u8 *self) {
  typedef u32(THISCALL * noarg_fn)(u8 *);
  typedef u32(THISCALL * slot1bc_fn)(u8 *, u32, u32);
  typedef u32(THISCALL * slot30_fn)(u8 *, u32);

  u8 *o = *(u8 **)(self + 0x127);
  s32 n = (s32)((noarg_fn)(*(u32 *)(*(u32 *)o + 0x14)))(o);
  if (n <= 0) return 0;

  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  s32 r = (s32)((slot1bc_fn)(*(u32 *)(*(u32 *)g + 0x1bc)))(g, 0x69e4bcu, 0x4bcu);
  s32 rem = r % n;

  u8 *o2 = *(u8 **)(self + 0x127);
  return ((slot30_fn)(*(u32 *)(*(u32 *)o2 + 0x30)))(o2, (u32)rem);
}
PCREG(513040, zMoveOnSplineGetExitRef);
