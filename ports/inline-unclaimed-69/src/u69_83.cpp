// u69_83.cpp - area 69, residue-8 scalar deleting destructors. Each sets the vtable, and if flags bit 0 is set calls the sized delete
// 0x634273(obj, size) (cdecl, two args; GUESS stub in the spec, a logging hook as in the other areas), then returns this (thiscall, one stack arg, ret 4).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);   // sized delete, cdecl, two args (GUESS stub)

// 0x54cd40 ZSoundListener::~ZSoundListener (scalar deleting): vtable 0x6a3dd0, size 0x14.
static void *THISCALL dtor54cd40(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a3dd0;
  if (flags & 1)
    ext_634273(self, 0x14);
  return self;
}
PCREG(54cd40, dtor54cd40);

// 0x551d40 CFFTools_if::~CFFTools_if (scalar deleting): vtable 0x69c968, size 0x28.
static void *THISCALL dtor551d40(u8 *self, u32 flags) {
  *(u32 *)self = 0x69c968;
  if (flags & 1)
    ext_634273(self, 0x28);
  return self;
}
PCREG(551d40, dtor551d40);
