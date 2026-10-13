// batch4141.cpp - unclaimed-41 batch 41 (core-todo residue-19): 0x5856f0 CFFCoverList::~CFFCoverList(), deleting destructor (thiscall, one
// stack argument flags, ret 4; returns this). SEH frame not reproduced (fs:[0] writes are not compared). Calls 0x585620 (thiscall, no
// arguments). When bit 0 is set: bit 2 set calls cdecl 0x4690b0(this, 0x7b) (caller pops); bit 2 clear calls the error hook 0x7003b0 when
// it is set (a zero hook traps in the exe).
#include "ff.h"

extern "C" void THISCALL ext_585620(u8 *self);                         // member destructor, no arguments (stub, GUESS)
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 line);    // free wrapper, two arguments, caller pops (stub, GUESS)

static u8 *THISCALL fn5856f0(u8 *self, u32 flags) {
  ext_585620(self);
  if ((flags & 1) != 0) {
    if ((flags & 4) != 0) {
      ext_4690b0(self, 0x7bu);
    } else {
      void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
      hook();   // a zero hook traps (int3) in the exe; the spec keeps it non-null
    }
  }
  return self;
}
PCREG(5856f0, fn5856f0);
