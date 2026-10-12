// batch4138.cpp - unclaimed-41 batch 38 (core-todo residue-19): 0x46a770 ZItemAmmo::~ZItemAmmo(), deleting destructor (thiscall, one
// stack argument flags, ret 4; returns this). Vtable 0x687cb0, base destructor 0x46a4f0 (thiscall, no arguments). When bit 0 of flags is
// set: bit 2 clear calls cdecl 0x45c510(this); bit 2 set calls cdecl 0x4690b0(this, 0x92). Both cdecl calls are caller-pop.
#include "ff.h"

extern "C" void THISCALL ext_46a4f0(u8 *self);                          // base destructor, no arguments (stub, GUESS)
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);               // free wrapper, one argument, caller pops (stub, GUESS)
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 line);     // free wrapper, two arguments, caller pops (stub, GUESS)

static u8 *THISCALL fn46a770(u8 *self, u32 flags) {
  *(u32 *)self = 0x687cb0u;
  ext_46a4f0(self);
  if ((flags & 1) != 0) {
    if ((flags & 4) == 0)
      ext_45c510(self);
    else
      ext_4690b0(self, 0x92u);
  }
  return self;
}
PCREG(46a770, fn46a770);
