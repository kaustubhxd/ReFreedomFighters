// batch960.cpp - area 56 band, claims A22-A23.
#include "ff.h"

// A22 0x5373d0: calls the global function pointer at 0x7003b0 (ecx = this, no arguments), then *p = 0; returns 0.
static u32 THISCALL zeroViaGlobal5373d0(u8 *self, u32 *p) {
  ((void(THISCALL *)(u8 *))G(u32, 0x7003b0))(self);
  *p = 0;
  return 0;
}
PCREG(5373d0, zeroViaGlobal5373d0);

// A23 0x536350: if a == 0 return; else a += dword this+0x5302 and tail-jump through vtable slot 0x1ec with the new a.
static u32 THISCALL tailAdd536350(u8 *self, u32 a) {
  if (a == 0) return 0;
  a += *(u32 *)(self + 0x5302);
  u32 vt = *(u32 *)self;
  return ((u32(THISCALL *)(u8 *, u32))(*(u32 *)(vt + 0x1ec)))(self, a);
}
PCREG(536350, tailAdd536350);
