// batch627.cpp - band 0x421000-0x441000, batch 627: two thiscall functions.
//   0x423950 (thiscall, three arguments x, a, b; ret 0xc): calls slot 0x1fc of this with (&x, 4, 0x11, a, b) (five arguments;
//     the callee writes its result through the first pointer); then dword [this+0x1b49] = x.
//   0x42c0d0 (thiscall, one unused argument; ret 4): p = slot 0x1b0 of this; if p is 0 return 0; else p = slot 0x1b0 of this
//     again; tail-jump to slot 0x28 of p with ecx = p (the one argument is still on the stack, so the target pops 4).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vNone)(void *self);
typedef u32(THISCALL *vFive)(void *self, u32 a, u32 b, u32 c, u32 d, u32 e);
typedef u32(THISCALL *vOneArg)(void *self, u32 a);

static void THISCALL storeFromSlot1fc(u8 *self, u32 x, u32 a, u32 b) {
  ((vFive)VT(self, 0x1fc))(self, (u32)&x, 4u, 0x11u, a, b);
  *(u32 *)(self + 0x1b49) = x;
}
PCREG(423950, storeFromSlot1fc);

static u32 THISCALL slot28OfSlot1b0(u8 *self, u32 unused) {
  (void)unused;
  u32 p = ((vNone)VT(self, 0x1b0))(self);
  if (p == 0)
    return 0;
  p = ((vNone)VT(self, 0x1b0))(self);
  u8 *q = (u8 *)p;
  return ((vOneArg)VT(q, 0x28))(q, unused);
}
PCREG(42c0d0, slot28OfSlot1b0);
