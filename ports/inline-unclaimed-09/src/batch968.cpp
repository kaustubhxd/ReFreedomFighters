// batch968.cpp - area 56 band, claim A33 (0x534d00).
#include "ff.h"

extern "C" void THISCALL ext_534be0(u8 *self);  // original exe helper (hooked in the spec)
extern "C" void ext_634273(u8 *p, u32 n);       // original exe free (cdecl, hooked in the spec)

// A33 0x534d00: call 0x534be0(this), free(this, 0x5462) when the low bit of flags is set; returns this.
static u8 *THISCALL dtor534d00(u8 *self, u32 flags) {
  ext_534be0(self);
  if (flags & 1) ext_634273(self, 0x5462);
  return self;
}
PCREG(534d00, dtor534d00);
