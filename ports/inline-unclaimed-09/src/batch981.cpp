// batch981.cpp - area 56 band, claim A47 (0x524460): five virtual calls with one float each.
#include "ff.h"

// A47 0x524460: for k in 0, 4, 8, 0xc, 0x10: o->vt[0x4c](float this+k) with ecx = o (thiscall, one float). Returns 1.
static u8 THISCALL f524460(u8 *self, u8 *o) {
  for (u32 k = 0; k <= 0x10; k += 4) {
    u8 *vt = *(u8 **)o;
    ((void(THISCALL *)(u8 *, float))(*(u32 *)(vt + 0x4c)))(o, *(float *)(self + k));
  }
  return 1;
}
PCREG(524460, f524460);
