#include "ff.h"
// batch955.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x435c60 (high), a constructor. Thiscall with one stack argument, ret 4.
// [self] = 0x67a5d8; [0x7003a0] = 0; if (a1 & 1) the sized free ext_634273(self, 0x7c) (cdecl: the caller pops two arguments); return self.

extern "C" void ext_634273(u8 *p, u32 n);

static u8 *THISCALL zgroupCtor435c60(u8 *self, u32 a1) {
  *(u32 *)self = 0x67a5d8;
  *(u32 *)0x7003a0 = 0;
  if (a1 & 1) ext_634273(self, 0x7c);
  return self;
}
PCREG(435c60, zgroupCtor435c60);
