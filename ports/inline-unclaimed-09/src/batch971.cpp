// batch971.cpp - area 56 band, claim A37 (0x532a80).
#include "ff.h"

extern "C" void THISCALL ext_5329f0(u8 *self);  // original exe helper (hooked in the spec)
extern "C" void ext_634273(u8 *p, u32 n);       // original exe free (cdecl, hooked in the spec)

// A37 0x532a80: call 0x5329f0(this), free(this, 0x548e) when the low bit of flags is set; returns this.
static u8 *THISCALL dtor532a80(u8 *self, u32 flags) {
  ext_5329f0(self);
  if (flags & 1) ext_634273(self, 0x548e);
  return self;
}
PCREG(532a80, dtor532a80);
