// batch216.cpp - gameplay-CORE function from decomp-pilot/core-todo/residue-19.txt (area 20, slice 19).
#include "ff.h"

typedef u32(THISCALL *VtArgU32)(u8 *, u32);

// 0x4e6d70, ZRunParamAnim::Create(p, b, t) thiscall ret 0xc (core list, GUESS name). Contract: t >= 0. The asm calls a
// global hook for negative t (and faults when it is null); that path is not a defined input here. Body: [this+0xbc] =
// low byte of b; [this+0xb8] = t (float); r = this->vtable[8](this, p); return (r & ~0xff) | 1 (al = 1).
static u32 THISCALL createAnim_4e6d70(u8 *self, u32 p, u32 b, float t) {
  self[0xbc] = (u8)b;
  *(float *)(self + 0xb8) = t;
  VtArgU32 f8 = (VtArgU32)(*(u32 *)(*(u32 *)self + 8));
  u32 r = f8(self, p);
  return (r & ~0xffu) | 1u;
}
PCREG(4e6d70, createAnim_4e6d70);
