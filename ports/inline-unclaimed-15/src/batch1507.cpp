#include "ff.h"
// batch1507.cpp - unclaimed-15 claim 7 (docs/20-unclaimed-15.md): ZFFActor::~ZFFActor() (0x59da20), scalar deleting.
// Name from the GC name map (high). Thiscall, one argument (flags, bit 1 = delete), ret 4.
// Stubbed in the harness: the base destructor 0x59d930 (thiscall, no args), 0x4690b0 (cdecl delete, (this, size)) and
// 0x45c510 (cdecl, (this)).

extern "C" void THISCALL ext_59d930(u8 *self);      // base destructor, stubbed
extern "C" void ext_4690b0(u8 *p, u32 size);        // delete with size, cdecl, stubbed
extern "C" void ext_45c510(u8 *p);                  // delete, cdecl, stubbed

// 0x59da20, ZFFActor::~ZFFActor() (high). Base destructor first. Bit 1 of the flags deletes: with bit 4 it passes the
// size 0x951, without bit 4 it calls the one-argument delete. The result is this.
static u32 THISCALL zffActorDtor(u8 *self, u32 flags) {
  ext_59d930(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0x951);
    else
      ext_45c510(self);
  }
  return (u32)self;
}
PCREG(59da20, zffActorDtor);
