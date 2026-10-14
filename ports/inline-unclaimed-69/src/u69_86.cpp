// u69_86.cpp - area 69, gameplay-core residue-8. 0x519440 ZMoveOnSplineIf::~ZMoveOnSplineIf (scalar deleting, vtable 0x69f224):
// sets the vtable, calls the base destructor 0x500a10 (thiscall, no args; GUESS hook in the spec), then if flags bit 0 is set calls
// the sized delete 0x634273(this, 0x18) (cdecl; GUESS hook), returns this (thiscall, one stack arg, ret 4).
#include "ff.h"

extern "C" void THISCALL ext_500a10(void *self);   // base class destructor (GUESS hook in the spec)
extern "C" void ext_634273(void *p, u32 size);     // sized delete, cdecl (GUESS hook in the spec)

static void *THISCALL dtor519440(u8 *self, u32 flags) {
  *(u32 *)self = 0x69f224;
  ext_500a10(self);
  if (flags & 1)
    ext_634273(self, 0x18);
  return self;
}
PCREG(519440, dtor519440);
