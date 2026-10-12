#include "ff.h"
// batch921.cpp - unclaimed-80 claim 1 (docs/20-unclaimed-80.md). ZFFHeroMovementPlaceC4::~ZFFHeroMovementPlaceC4() (0x5e1630,
// medium, from the dtor entry). Member destructors 0x480fd0 (thiscall, no arguments, called four times on members) and the
// base 0x4878d0 are original code (no-op stubs in the spec). Deletes this (size 0x568, cdecl) when bit 0 is set. Returns this.

extern "C" void THISCALL ext_480fd0(u8 *member);
extern "C" void THISCALL ext_4878d0(u8 *self);
extern "C" void ext_634273(void *p, u32 n);

static u32 THISCALL placeC4Dtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x6b7964u;
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if ((flag & 1) != 0)
    ext_634273(self, 0x568u);
  return (u32)self;
}
PCREG(5e1630, placeC4Dtor);
