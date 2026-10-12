// batch1015.cpp - unclaimed-10, batch 11 (docs/20-unclaimed-10.md): ZHeliIf::~ZHeliIf(), the scalar deleting destructor
// (thiscall, one argument: the flags byte, ret 4). Sets vtable 0x69fa64, runs the base destructor 0x519430 (original code;
// it sets 0x69f224 and jumps to 0x500a10, which sets 0x69c968), then deletes with size 0x1c if bit 0 is set. Operator delete
// 0x634273 and the base destructor are unverified callees run as ORIGINAL code; the spec hooks delete only to log it.
#include "ff.h"

extern "C" void THISCALL ext_519430(u8 *self);  // base destructor chain, original code
extern "C" void ext_634273(u8 *p, u32 size);    // operator delete (cdecl, two arguments), original code

// 0x51e810, ZHeliIf::~ZHeliIf() (high)
static u8 *THISCALL heliIfDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x69fa64;
  ext_519430(self);
  if (flags & 1) ext_634273(self, 0x1c);
  return self;
}
PCREG(51e810, heliIfDtor);
