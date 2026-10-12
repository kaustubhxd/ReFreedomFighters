#include "ff.h"
// batch8016.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

extern "C" void THISCALL ext_4e66a0(u8 *self);
extern "C" void ext_634273(u8 *p, u32 n);

// 0x48a340 (GUESS): thiscall (ret 4). Calls 0x4e66a0 on this; if bit 0 of its argument is set, calls 0x634273(this, 0xc).
// Returns this.
static u8 *THISCALL f_48a340(u8 *self, u32 flags) {
  ext_4e66a0(self);
  if ((flags & 1) != 0) ext_634273(self, 0xc);
  return self;
}
PCREG(48a340, f_48a340);

// 0x48f6d0 (GUESS): stdcall (ret 4). Calls 0x634273(argument, 0x18). Returns nothing.
static void STDCALL f_48f6d0(u32 p) { ext_634273((u8 *)(unsigned long)p, 0x18); }
PCREG(48f6d0, f_48f6d0);
