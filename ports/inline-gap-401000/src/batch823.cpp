// batch823.cpp - core gameplay batch 823 (docs/20-unclaimed-65.md, batch 823): 0x584450 (CExplode::Init2), a thiscall with no arguments.
// When bit 10 of the dword at [[this+0x44]+8]+0x3c is clear and the byte at this+0x5d is nonzero, it calls 0x5833e0 with ecx = this and two
// zero arguments (the callee pops them). Other claim, hooked by address in the spec (GUESS).
#include "ff.h"

extern "C" void THISCALL ext_5833e0(u8 *self, u32 a, u32 b);   // thiscall, two arguments, hooked in the spec

static void THISCALL fn584450(u8 *self) {
  const u8 *obj = *(const u8 **)(self + 0x44);
  const u32 v = *(const u32 *)(*(const u8 **)(obj + 8) + 0x3c);
  if (((v >> 10) & 1) == 0 && *(const u8 *)(self + 0x5d) != 0) ext_5833e0(self, 0, 0);
}

PCREG(584450, fn584450);
