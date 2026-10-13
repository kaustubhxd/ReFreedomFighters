// batch829.cpp - core gameplay batch 829 (docs/20-unclaimed-65.md, batch 829): 0x5a5650 (ZFFPRIVATESTDOBJ::~ZFFPRIVATESTDOBJ), a thiscall with one
// stack flag word (ret 4). It calls 0x43de70 (thiscall, no arguments, hooked). When bit 0 of the flag is clear it returns this. Otherwise, when
// bit 2 is set it calls 0x4690b0(this, 0x20) (cdecl, the caller removes two words), else 0x45c510(this) (cdecl, the caller removes one word).
// It returns this in every case. Both cdecl callees are other claims, hooked by address in the spec (GUESS).
#include "ff.h"

extern "C" void THISCALL ext_43de70(u8 *self);   // thiscall, no arguments (hooked in the spec)
extern "C" void ext_45c510(u8 *p);               // cdecl, one argument (hooked)
extern "C" void ext_4690b0(u8 *p, u32 n);        // cdecl, two arguments (hooked)

static u8 *THISCALL fn5a5650(u8 *self, u32 flags) {
  ext_43de70(self);
  if ((flags & 1) != 0) {
    if ((flags & 4) != 0)
      ext_4690b0(self, 0x20);
    else
      ext_45c510(self);
  }
  return self;
}

PCREG(5a5650, fn5a5650);
