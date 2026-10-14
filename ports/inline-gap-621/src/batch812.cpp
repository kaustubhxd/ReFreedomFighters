// batch812.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" void THISCALL ext_54ac30(u8 *self);            // hooked (GUESS)
extern "C" u32 __attribute__((cdecl)) ext_634273(u32 a, u32 b);   // hooked (GUESS)
typedef u32(THISCALL *VTwoW)(u8 *, u32, u32);   // vt thiscall, two words, callee cleans (ret 8)

// 0x661bf0, stdcall(x) ret 4: reads a chain of globals and returns the dword at P + x[1] + 0x2c.
static u32 STDCALL chainRead_661bf0(u8 *x) {
  u8 *g = *(u8 **)0x70039cu;
  u8 *s = *(u8 **)(g + 0x1aa3);
  u8 *P = *(u8 **)(s + 0x20);
  return *(u32 *)(P + *(u32 *)(x + 4) + 0x2c);
}
PCREG(661bf0, chainRead_661bf0);

// 0x54ad70, thiscall(flag) ret 4: calls 0x54ac30(this); when flag bit 0 is set also calls 0x634273(this, 0x54); returns this.
static u8 *THISCALL callPair_54ad70(u8 *self, u32 flag) {
  ext_54ac30(self);
  if (flag & 1u) ext_634273((u32)self, 0x54u);
  return self;
}
PCREG(54ad70, callPair_54ad70);

// 0x607bf0, thiscall(a, b) ret 8: o = this+0x14; r = o->vt[4](a, 0); o->vt[0x18](b, r).
static void THISCALL twoVt_607bf0(u8 *self, u32 a, u32 b) {
  u8 *o = *(u8 **)(self + 0x14);
  VTwoW f4 = (VTwoW)(*(u32 *)(*(u32 *)o + 4));
  u32 r = f4(o, a, 0u);
  VTwoW f18 = (VTwoW)(*(u32 *)(*(u32 *)o + 0x18));
  f18(o, b, r);
}
PCREG(607bf0, twoVt_607bf0);
