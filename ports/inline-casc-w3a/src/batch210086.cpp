// batch210086.cpp - Sonnet-w3a: 0x4e6700 (call the stdcall import at 0x6760b4 with this[2] and the argument, when this[2] is set)
#include "ff.h"

typedef u32 (STDCALL *Imp)(u32 h, u32 a);

static u32 THISCALL fn4e6700(u8 *self, u32 a) {
  u32 h = *(u32 *)(self + 8);
  if (!h) return 0;  // @4e6700_a
  return G(Imp, 0x6760b4)(h, a);  // @4e6700_b
}
PCREG(4e6700, fn4e6700);
