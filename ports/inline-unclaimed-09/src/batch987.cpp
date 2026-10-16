// batch987.cpp - area 56 band, claim A53 (0x52cec0): a constructor with one virtual call on the global.
#include "ff.h"

// A53 0x52cec0: this->4 = a; this->8 = b; this->c = 0; r = g->vt[0x1c8](0x6a13d8, 0x23); this->0 = r; this->10 = 1; return this.
static u8 *THISCALL ctor52cec0(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 4) = a;
  *(u32 *)(self + 8) = b;
  *(u32 *)(self + 0xc) = 0;
  u8 *g = (u8 *)G(u32, 0x70039c);
  u32 r = ((u32(THISCALL *)(u8 *, u32, u32))(*(u32 *)(*(u8 **)g + 0x1c8)))(g, 0x6a13d8u, 0x23u);
  *(u32 *)self = r;
  *(u8 *)(self + 0x10) = 1;
  return self;
}
PCREG(52cec0, ctor52cec0);
