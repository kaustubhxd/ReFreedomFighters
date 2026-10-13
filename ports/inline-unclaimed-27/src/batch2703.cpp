#include "ff.h"
// batch2703.cpp - unclaimed-27 claim 3 (docs/20-unclaimed-27.md). Name from the GC name map (high).

// 0x514560, ZMoveOnSpline::StopSound(unsigned int) (high). Thiscall, ret 4.
// p = vtable slot +0x60 of the global's +0x9b object, called with the argument. If p is null, returns. Otherwise: calls
// vtable slot +0x40 of the object at this+0x1ed with the argument; sets the byte at p+0xec to 1; sets the float at p+0xed to
// (float)(int)(the dword at global+0x40) * (1/1024); copies the float at p+0x88 to p+0xf1 and sets p+0xf5 to it / 0.3.
static void THISCALL zMoveOnSplineStopSound(u8 *self, u32 a1) {
  typedef u8 *(THISCALL * slot60_fn)(u8 *, u32);
  typedef void(THISCALL * slot40_fn)(u8 *, u32);

  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *o9 = *(u8 **)(g + 0x9b);
  u8 *p = ((slot60_fn)(*(u32 *)(*(u32 *)o9 + 0x60)))(o9, a1);
  if (p == 0) return;

  u8 *obj = *(u8 **)(self + 0x1ed);
  ((slot40_fn)(*(u32 *)(*(u32 *)obj + 0x40)))(obj, a1);

  p[0xec] = 1;

  g = (u8 *)(unsigned long)G(u32, 0x70039c);
  s32 counter = *(s32 *)(g + 0x40);
  float scaled = (float)counter * 0.0009765625f;
  *(float *)(p + 0xed) = scaled;

  float s = *(float *)(p + 0x88);
  *(float *)(p + 0xf1) = s;
  *(float *)(p + 0xf5) = s / 0.3f;
}
PCREG(514560, zMoveOnSplineStopSound);
