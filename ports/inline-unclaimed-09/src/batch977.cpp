// batch977.cpp - area 56 band, claim A43 (0x524780): six virtual calls on the first argument.
#include "ff.h"

// A43 0x524780: for k in 0, 4, 8, 0xc, 0x10, 0x14: o->vt[0x50](this + k) with ecx = o (thiscall, one argument). Returns 1.
static u8 THISCALL f524780(u8 *self, u8 *o) {
  for (u32 k = 0; k <= 0x14; k += 4) {
    u8 *vt = *(u8 **)o;
    ((void(THISCALL *)(u8 *, u8 *))(*(u32 *)(vt + 0x50)))(o, self + k);
  }
  return 1;
}
PCREG(524780, f524780);
