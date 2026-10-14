// batch964.cpp - residue-05 (core todo), batch 964.
//   0x438050: ZInputActions::CheckActionAnalog(const char*, void*), thiscall, ret 8, float result (st0). Vslot 0x38(name, out)
//             answers a flag; false gives 0.0. Otherwise vslot 0xa4(name) (a signed byte) divided by the constant at 0x67af20.
//   0x4a58d0: ZMatPosAnim::FrameUpdate(), thiscall, no args. Time: ([0x70039c]+0x40) - int([this+0xbb] * 1024), scaled by
//             1/1024 (constant at 0x6785e4); 0x4a5f20(this, that) returns a float (stood in); when it is negative, 0x4a5fe0 (this)
//             runs (stood in).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

extern "C" float THISCALL ext_4a5f20(void *self, float x);   // stood in by the checker
extern "C" void THISCALL ext_4a5fe0(void *self);             // stood in by the checker

// 0x438050 ZInputActions::CheckActionAnalog(const char*, void*).
static float THISCALL checkActionAnalog(u8 *t, const char *name, void *out) {
  if (!vcall<u8>(t, 0x38, (u32)name, (u32)out))
    return 0.0f;
  int r = (int)(signed char)vcall<u8>(t, 0xa4, (u32)name);
  return (float)r / *(float *)0x67af20;
}
PCREG(438050, checkActionAnalog);

// 0x4a58d0 ZMatPosAnim::FrameUpdate().
static void THISCALL matPosFrameUpdate(u8 *t) {
  u8 *sys = *(u8 **)0x70039c;
  u32 ticks = D(sys, 0x40);
  float scaled = F(t, 0xbb) * *(float *)0x678620;
  u32 whole = (u32)(int)scaled;
  float x = (float)(int)(ticks - whole) * *(float *)0x6785e4;
  float r = ext_4a5f20(t, x);
  if (r < 0.0f)
    ext_4a5fe0(t);
}
PCREG(4a58d0, matPosFrameUpdate);
