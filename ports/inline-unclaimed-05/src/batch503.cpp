// batch503.cpp - unclaimed-05 batch 3 (claim 3, slice floor(addr/16) mod 20 = 4). Names from the GC name map (naming
// only, never committed); GUESS where marked.
#include "ff.h"

// ext_480fd0: a sub-object destructor (thiscall, no stack arguments), original code.
extern "C" void THISCALL ext_480fd0(u8 *self);
// ext_634273: CRT sized operator delete (cdecl), original code; the harness hooks and logs it.
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

// 0x487a00, ZMovementStand::~ZMovementStand() scalar deleting destructor (high): writes the vtable word 0x68cfb4, runs
// three sub-object destructors (this+0x10d, +0xf5, +0xdd), writes the final vtable word 0x68cf50, and when bit 0 of
// the stack argument is set calls the sized delete with size 0x125. Returns this in EAX, ret 4.
static u8 *THISCALL movementStandDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x68cfb4;
  ext_480fd0(self + 0x10d);
  ext_480fd0(self + 0xf5);
  ext_480fd0(self + 0xdd);
  *(u32 *)self = 0x68cf50;
  if ((u8)flags & 1) ext_634273(self, 0x125);
  return self;
}
PCREG(487a00, movementStandDtor);
