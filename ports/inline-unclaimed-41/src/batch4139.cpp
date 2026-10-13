// batch4139.cpp - unclaimed-41 batch 39 (core-todo residue-19): 0x5171f0 ZCar::~ZCar() deleting destructor (thiscall, one stack argument
// flags, ret 4; returns this). Calls 0x511950(this+0x2d8) and 0x512070(this) (thiscall, no arguments). When bit 0 of flags is set: bit 2
// clear calls cdecl 0x45c510(this); bit 2 set calls cdecl 0x4690b0(this, 0x1654). The cdecl calls are caller-pop.
#include "ff.h"

extern "C" void THISCALL ext_511950(u8 *self);                          // member destructor, no arguments (stub, GUESS)
extern "C" void THISCALL ext_512070(u8 *self);                          // member destructor, no arguments (stub, GUESS)
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);               // free wrapper, one argument, caller pops (stub, GUESS)
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 line);     // free wrapper, two arguments, caller pops (stub, GUESS)

static u8 *THISCALL fn5171f0(u8 *self, u32 flags) {
  ext_511950(self + 0x2d8);
  ext_512070(self);
  if ((flags & 1) != 0) {
    if ((flags & 4) == 0)
      ext_45c510(self);
    else
      ext_4690b0(self, 0x1654u);
  }
  return self;
}
PCREG(5171f0, fn5171f0);
