// batch4137.cpp - unclaimed-41 batch 37 (core-todo residue-19): 0x4879b0 ZMovementGuide::~ZMovementGuide(), scalar deleting destructor
// (thiscall, one stack argument flags, ret 4; returns this). Vtable 0x68d018 during the member destructors, then 0x68cf50. The CRT free
// wrapper 0x634273 is cdecl (two pushed arguments, caller pops) and is called when bit 0 of the flags is set.
#include "ff.h"

extern "C" void THISCALL ext_480fd0(u8 *self);                          // member destructor, no arguments (stub, GUESS)
extern "C" void __attribute__((cdecl)) ext_634273(u8 *p, u32 line);     // CRT free wrapper, caller pops 8 (stub, GUESS)

static u8 *THISCALL fn4879b0(u8 *self, u32 flags) {
  *(u32 *)self = 0x68d018u;
  ext_480fd0(self + 0x55);
  ext_480fd0(self + 0x3d);
  ext_480fd0(self + 0x25);
  *(u32 *)self = 0x68cf50u;
  if ((flags & 1) != 0)
    ext_634273(self, 0x3bfu);
  return self;
}
PCREG(4879b0, fn4879b0);
