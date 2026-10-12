// batch808.cpp - core gameplay batch 808 (docs/20-unclaimed-65.md, batch 808): 0x485f60, a thiscall with one stack flag word. It sets
// the vtable to 0x685294 and, when bit 0 of the flag is set, calls the CRT free 0x634273 (cdecl, the caller removes two words) with
// size 0x40; it returns this.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);   // cdecl CRT free (exe code, stubbed by the harness)

static u8 *THISCALL fn485f60(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;
  if (flags & 1) ext_634273(self, 0x40);
  return self;
}

PCREG(485f60, fn485f60);
