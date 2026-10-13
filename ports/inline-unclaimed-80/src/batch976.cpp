#include "ff.h"
// batch976.cpp - unclaimed-80 residue-19 (docs/20-unclaimed-80.md), batch 54: 0x4bce30 (thiscall, self in ecx, one stack argument a, ret 4).
// Three times: f = 0x4e5e80(a) (thiscall, ecx = a, no arguments, returns a float in st0; claimed elsewhere, hooked by address in the spec);
// store f to self+0x48, self+0x4c, self+0x50 in turn.

extern "C" float THISCALL ext_4e5e80(u8 *self);

static void THISCALL zg4bce30(u8 *self, u8 *a) {
  float f0 = ext_4e5e80(a);
  *(float *)(self + 0x48) = f0;
  float f1 = ext_4e5e80(a);
  *(float *)(self + 0x4c) = f1;
  float f2 = ext_4e5e80(a);
  *(float *)(self + 0x50) = f2;
}
PCREG(4bce30, zg4bce30);
