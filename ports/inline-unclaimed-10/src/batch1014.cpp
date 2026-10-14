// batch1014.cpp - unclaimed-10, batch 10 (docs/20-unclaimed-10.md): ZFFActorActionThrow::~ZFFActorActionThrow(), the scalar
// deleting destructor (thiscall, one argument: the flags byte, ret 4). Operator delete 0x634273 is an unverified callee run as
// ORIGINAL code; the spec hooks it only to log the call. Same shape as batch 8 (0x485ed0) with delete size 0x21.
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 size);  // operator delete (cdecl, two arguments), original code

// 0x5eaf50, ZFFActorActionThrow::~ZFFActorActionThrow() (medium, GUESS on the name): vtable 0x685294 at +0; if bit 0 of the
// argument is set, deletes the object with size 0x21; returns this in eax.
static u8 *THISCALL actorActionThrowDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;
  if (flags & 1) ext_634273(self, 0x21);
  return self;
}
PCREG(5eaf50, actorActionThrowDtor);
