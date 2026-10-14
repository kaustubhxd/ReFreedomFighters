// batch917.cpp - unclaimed-09 batch 9: ZFFHeroIf::~ZFFHeroIf() (docs/20-unclaimed-09.md, claim 9).
// Scalar deleting destructor: thiscall with one stack argument (flags, bit 0 selects the free), ret 4.
#include "ff.h"

// Base destructor at 0x504870 (thiscall, no arguments). The spec hooks it (unverified callee).
extern "C" void THISCALL ext_504870(u8 *self);
// Original free at 0x634273 (cdecl, two arguments). The spec hooks it (unverified callee).
extern "C" void ext_634273(u8 *p, u32 n);

// 0x55ee00, ZFFHeroIf::~ZFFHeroIf() (high): writes the vtable 0x6a60d0 at this, calls the base destructor, then when
// bit 0 of the flags is set frees this through 0x634273 with size 0x1c. Returns this in eax.
static u8 *THISCALL heroIfDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a60d0;
  ext_504870(self);
  if (flags & 1) ext_634273(self, 0x1c);
  return self;
}
PCREG(55ee00, heroIfDtor);
