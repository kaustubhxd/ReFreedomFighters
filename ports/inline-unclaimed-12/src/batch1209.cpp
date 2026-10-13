// batch1209.cpp - unclaimed-12: batch 9 (docs/20-unclaimed-12.md, claim 9, in slice). Thiscall with one stack flag argument.
// operator delete (0x634273) is cdecl; the harness replaces it with a logging stub.
#include "ff.h"

// 0x634273, operator delete of (pointer, size) (cdecl).
extern "C" void ext_634273(void *p, u32 size);

// 0x441cf0, ZOctree::~ZOctree() (medium name): vtable := 0x67d108; operator delete of 0x14 bytes when bit 0 of the flag is set.
static u8 *THISCALL octreeDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x67d108;
  if ((u8)flags & 1) ext_634273(self, 0x14);
  return self;
}
PCREG(441cf0, octreeDtor);

// 0x487930, ZMovementAnimation::~ZMovementAnimation() (low name): vtable := 0x68cf50; operator delete of 0x1d bytes when bit 0 is set.
static u8 *THISCALL movementAnimationDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x68cf50;
  if ((u8)flags & 1) ext_634273(self, 0x1d);
  return self;
}
PCREG(487930, movementAnimationDtor);
