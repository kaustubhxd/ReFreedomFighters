// batch806.cpp - unclaimed-08 batch 6: ZFFHeroMovementBaseMove and ZFFHeroMovementOpenGate scalar deleting destructors.
// Slice: floor(addr/16) mod 20 = 7. Each destructor runs four member destructors (0x480fd0, bound to the original code),
// then the base destructor (0x4878d0, original code), then, when bit 0 of the flag argument is set, CRT free(this, size).
// OpenGate first stores its vtable 0x6b788c at this+0. Both return this.
#include "ff.h"

extern "C" void THISCALL ext_480fd0(void *);
extern "C" void THISCALL ext_4878d0(void *);
extern "C" void ext_634273(void *, u32);  // CRT free(ptr, size), cdecl

// 0x5e12f0, ZFFHeroMovementBaseMove::~ZFFHeroMovementBaseMove() (high), scalar deleting form.
static void *THISCALL heroMoveBaseMoveDtor(u8 *self, u32 flags) {
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if (flags & 1) ext_634273(self, 0x54c);
  return self;
}
PCREG(5e12f0, heroMoveBaseMoveDtor);

// 0x5e1570, ZFFHeroMovementOpenGate::~ZFFHeroMovementOpenGate() (high), scalar deleting form.
static void *THISCALL heroMoveOpenGateDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b788c;
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if (flags & 1) ext_634273(self, 0x5bf);
  return self;
}
PCREG(5e1570, heroMoveOpenGateDtor);
