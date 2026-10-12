#include "ff.h"
// batch920.cpp - unclaimed-01 claim 19 (docs/20-unclaimed-01.md). Address 0x58b740, no name in the GC map (GUESS
// FUN_58b740: a destructor-like function). Calls the base routine 0x58b5a0 (thiscall, no arguments, SEH-framed, original
// code; the spec no-ops it), then, when bit 0 of the argument is set, deletes this: sized (0xf62) when bit 2 is set,
// otherwise the 0x45c510 delete (one argument). Returns this.

extern "C" void THISCALL ext_58b5a0(u8 *self);
extern "C" void ext_4690b0(void *p, u32 n);
extern "C" void ext_45c510(void *p);

static u32 THISCALL guessDtor58b740(u8 *self, u32 flag) {
  ext_58b5a0(self);
  if ((flag & 1) != 0) {
    if ((flag & 4) != 0)
      ext_4690b0(self, 0xf62u);
    else
      ext_45c510(self);
  }
  return (u32)self;
}
PCREG(58b740, guessDtor58b740);
