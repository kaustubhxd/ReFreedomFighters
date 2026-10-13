// batch4140.cpp - unclaimed-41 batch 40 (core-todo residue-19): 0x4a9970 CCheckVisible::~CCheckVisible(), deleting destructor (thiscall, one
// stack argument flags, ret 4; returns this). SEH frame not reproduced (the fs:[0] push, save and restore are not modelled; fs:[0] writes
// are not compared). Calls 0x4a9880 (thiscall, no arguments). When bit 0 is set: bit 2 set calls cdecl 0x4690b0(this, 0x15e88) (caller
// pops); bit 2 clear calls the error hook 0x7003b0 when it is non-null.
#include "ff.h"

extern "C" void THISCALL ext_4a9880(u8 *self);                         // member destructor, no arguments (stub, GUESS)
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 line);    // free wrapper, two arguments, caller pops (stub, GUESS)

static u8 *THISCALL fn4a9970(u8 *self, u32 flags) {
  ext_4a9880(self);
  if ((flags & 1) != 0) {
    if ((flags & 4) != 0) {
      ext_4690b0(self, 0x15e88u);
    } else {
      void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
      hook();   // the exe traps (int3) when the hook is zero; the spec keeps it non-null
    }
  }
  return self;
}
PCREG(4a9970, fn4a9970);
