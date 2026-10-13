// batch1208.cpp - unclaimed-12: batch 8 (docs/20-unclaimed-12.md, claim 8, in slice). Thiscall with one stack flag argument;
// the callee pops it. The callees are original code, reached through ext_<hex> (the harness replaces them with logging stubs).
// Names are from the GC name map (high confidence for both).
#include "ff.h"

// 0x504870, base-class destructor (thiscall, no arguments).
extern "C" void THISCALL ext_504870(u8 *self);
// 0x480fd0, member destructor (thiscall, no arguments); used for five members.
extern "C" void THISCALL ext_480fd0(u8 *self);
// 0x4878c0, base-class destructor (thiscall, no arguments).
extern "C" void THISCALL ext_4878c0(u8 *self);
// 0x634273, operator delete of (pointer, size) (cdecl).
extern "C" void ext_634273(void *p, u32 size);

// 0x506370, ZActorIf::~ZActorIf() (high): vtable := 0x69cf6c; base destructor; operator delete of 0x1c bytes when bit 0 of the
// flag argument is set; returns this.
static u8 *THISCALL actorIfDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x69cf6c;
  ext_504870(self);
  if ((u8)flags & 1) ext_634273(self, 0x1c);
  return self;
}
PCREG(506370, actorIfDtor);

// 0x5e16f0, ZFFHeroMovementStand::~ZFFHeroMovementStand() (high): vtable := 0x6b753c; five member destructors at +0x16d, +0x155,
// +0x13d, +0x125, +0x10d; base destructor; operator delete of 0x189 bytes when bit 0 of the flag is set; returns this.
static u8 *THISCALL heroMovementStandDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b753c;
  ext_480fd0(self + 0x16d);
  ext_480fd0(self + 0x155);
  ext_480fd0(self + 0x13d);
  ext_480fd0(self + 0x125);
  ext_480fd0(self + 0x10d);
  ext_4878c0(self);
  if ((u8)flags & 1) ext_634273(self, 0x189);
  return self;
}
PCREG(5e16f0, heroMovementStandDtor);
