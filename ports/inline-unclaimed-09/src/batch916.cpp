// batch916.cpp - unclaimed-09 batch 8: ZMovementAction::~ZMovementAction() (docs/20-unclaimed-09.md, claim 8).
// Scalar deleting destructor: thiscall with one stack argument (the flags, bit 0 selects the free), ret 4.
#include "ff.h"

// Original free (0x634273, cdecl, two arguments). Its caller pops both; the spec stubs it (unverified callee).
extern "C" void ext_634273(u8 *p, u32 n);

// 0x487900, ZMovementAction::~ZMovementAction() (medium): writes the vtable 0x68cf50 at this; when bit 0 of the flags
// is set, frees this through 0x634273 with size 0x22; returns this in eax.
static u8 *THISCALL movActionDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x68cf50;
  if (flags & 1) ext_634273(self, 0x22);
  return self;
}
PCREG(487900, movActionDtor);
