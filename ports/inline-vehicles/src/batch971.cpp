// batch971.cpp - residue-04 (core todo), batch 971: CMAINCAMERACONTROL::SetDefaultFog(), 0x4fdac0, thiscall, no args.
// f1 = (render manager vslot 0x138())->vslot 0x84(0x6954e8, &f1); f2 = (again)->vslot 0x84(0x6954f8, &f2), both starting at 0.
// When f1 == 0 and f2 == 0 (ordered compare; NaN takes the other path) they become the defaults at 0x68d448 (f1) and 0x67c1ac (f2).
// The pair is stored at [[this+0x44]+0x70] (f1) and [[this+0x44]+0x74] (f2).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x4fdac0 CMAINCAMERACONTROL::SetDefaultFog().
static void THISCALL setDefaultFog(u8 *t) {
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  void *x = (void *)vcall<u32>(rm, 0x138);
  float f1 = 0.0f;
  vcall<void>(x, 0x84, 0x6954e8u, (u32)&f1);
  void *y = (void *)vcall<u32>(rm, 0x138);
  float f2 = 0.0f;
  vcall<void>(y, 0x84, 0x6954f8u, (u32)&f2);
  float a = f1;
  float b = f2;
  if (f1 == 0.0f && f2 == 0.0f) {
    a = *(float *)0x68d448;
    b = *(float *)0x67c1ac;
  }
  u8 *obj = (u8 *)D(t, 0x44);
  F(obj, 0x70) = a;
  F(obj, 0x74) = b;
}
PCREG(4fdac0, setDefaultFog);
