// batch1010.cpp - unclaimed-04 batch 10 (docs/20-unclaimed-04.md): ZVehicleIf::~ZVehicleIf (0x51aa70, dtor).
// thiscall, one stack argument (flags, ret 4), returns this. The base destructor 0x519430 and the free 0x634273
// (cdecl, pointer and size 0x1c) are original code; the spec hooks the free with a logging stub (GUESS).
#include "ff.h"

extern "C" void THISCALL ext_519430(void *self);  // base destructor, original code
extern "C" void ext_634273(void *p, u32 size);    // delete with size, original code

// 0x51aa70: vtable 0x69f364 first, then the base destructor, then free when flags bit 0 is set.
static u8 *THISCALL vehicleIfDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x69f364;
  ext_519430(self);
  if (flags & 1) ext_634273(self, 0x1c);
  return self;
}
PCREG(51aa70, vehicleIfDtor);
