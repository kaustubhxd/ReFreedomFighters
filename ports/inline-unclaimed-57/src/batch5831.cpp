// batch5831.cpp - residue 9, 0x51e810 (ZHeliIf::~ZHeliIf(), gc name map), thiscall, one stack argument (flags), ret 4, returns this.
// this->vtable = 0x69fa64; base destructor 0x519430 (thiscall, no stack args: stores vtable 0x69f224 and tail-jumps to 0x500a10, which ends in a plain ret;
// hooked in the spec); if (flags & 1): operator delete 0x634273 (cdecl) with (this, 0x1c). returns this.
#include "ff.h"

extern "C" void THISCALL ext_519430(u8 *self);   // base destructor (thiscall, no stack args), original code (hooked in the spec)
extern "C" void ext_634273(void *p, u32 size);  // operator delete (cdecl, two args), original code (hooked in the spec)

// 0x51e810, thiscall, one stack argument (ZHeliIf dtor)
static u8 *THISCALL unnamed51e810(u8 *self, u32 flags) {
  *(u32 *)self = 0x69fa64u;
  ext_519430(self);
  if (flags & 1) ext_634273(self, 0x1c);
  return self;
}
PCREG(51e810, unnamed51e810);
