// batch1012.cpp - unclaimed-10, batch 8 (docs/20-unclaimed-10.md): ZActionChamberItem::~ZActionChamberItem(), the scalar
// deleting destructor (thiscall, one stack argument: the flags byte, ret 4). Operator delete 0x634273 is an unverified
// callee run as ORIGINAL code in both runs; the spec hooks it only to log the call.
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 size);  // operator delete (cdecl, two arguments), original code

// 0x485ed0, ZActionChamberItem::~ZActionChamberItem() (high): sets the vtable 0x685294 at this+0; if bit 0 of the argument
// is set, deletes the object with size 0x30; returns this in eax.
static u8 *THISCALL actionChamberItemDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;
  if (flags & 1) ext_634273(self, 0x30);
  return self;
}
PCREG(485ed0, actionChamberItemDtor);
