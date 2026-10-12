// batch6316.cpp - unclaimed-63 batch 16 (docs/20-unclaimed-63.md): GUESS FUN_4eaea0 at 0x4eaea0 (no GC name). Thiscall with two
// stack arguments (a1, a2; ret 8). If [this+0xa4] is 0: returns 0. Otherwise: x = a1; 0x43e960(x; this+0x3c); 0x441a60(x; this+0x18);
// bl = 0x4ea900(this; x, a2) (thiscall, returns a byte); 0x4419f0(x; this+0x18); 0x441940(x; this+0x3c); returns bl.
// The helpers are original code (fastcall, ECX and EDX). 0x4ea900 is stubbed by the spec.
#include "ff.h"

extern "C" void FASTCALL ext_43e960(void *ecx, void *edx);
extern "C" void FASTCALL ext_441a60(void *ecx, void *edx);
extern "C" u8 THISCALL ext_4ea900(void *self, u32 a1, u32 a2);   // original, stubbed by the spec
extern "C" void FASTCALL ext_4419f0(void *ecx, void *edx);
extern "C" void FASTCALL ext_441940(void *ecx, void *edx);

// 0x4eaea0 (GUESS FUN_4eaea0).
static u8 THISCALL unnamed4eaea0(u8 *self, u32 a1, u32 a2) {
  if (self[0xa4] == 0)
    return 0;
  u8 *x = (u8 *)a1;
  ext_43e960(x, self + 0x3c);
  ext_441a60(x, self + 0x18);
  u8 bl = ext_4ea900(self, (u32)x, a2);
  ext_4419f0(x, self + 0x18);
  ext_441940(x, self + 0x3c);
  return bl;
}
PCREG(4eaea0, unnamed4eaea0);
