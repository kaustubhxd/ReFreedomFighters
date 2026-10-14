// batch960.cpp - 0x515f00 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), no args, ret 0,
// void. Has stack-cookie prologue and epilogue (NOT reproduced, tagged). Main flow: call helper 0x515f60 on this,
// then call virtual method at [0] on object at this+0xd6 with arg 1, then call virtual method at [0] on object at
// this+0xda with arg 1.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_515f60(u8 *self);   // stood in (one arg, helper function)

// 0x515f00 (no name in the map).
static void THISCALL Apply515f00(u8 *self) {
  ext_515f60(self);
  void *obj_d6 = FP(self, 0xd6);
  void *vt_d6 = FP(obj_d6, 0);
  void (THISCALL *fn_d6)(void *, u32) = (void (THISCALL *)(void *, u32))FP(vt_d6, 0);
  fn_d6(obj_d6, 1u);
  void *obj_da = FP(self, 0xda);
  void *vt_da = FP(obj_da, 0);
  void (THISCALL *fn_da)(void *, u32) = (void (THISCALL *)(void *, u32))FP(vt_da, 0);
  fn_da(obj_da, 1u);
}
PCREG(515f00, Apply515f00);
