// batch205.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. Two thin constructors
// that call an original base constructor and an optional release, and one wrapper that reads two values through the
// original 0x4e5e60 getter.
#include "ff.h"

extern "C" void THISCALL ext_5edea0(u8 *self);     // original base ctor, thiscall, no stack args
extern "C" void THISCALL ext_5421b0(u8 *self);     // original base ctor, thiscall, no stack args
extern "C" void ext_634273(u8 *p, u32 n);          // free-style release, original code (cdecl)
extern "C" u32 THISCALL ext_4e5e60(u8 *self);      // original getter (DBREAD operator unsigned int), thiscall, no args

// 0x5efd70, thiscall(flags): [this] = vtable 0x6b81f8; call base ctor 0x5edea0(this); if flags & 1, release with
// ext_634273(this, 0x99); returns this. Name GUESS.
static u8 *THISCALL ctorRelease_5efd70(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b81f8u;
  ext_5edea0(self);
  if (flags & 1) ext_634273(self, 0x99);
  return self;
}
PCREG(5efd70, ctorRelease_5efd70);

// 0x5422b0, thiscall(flags): call base ctor 0x5421b0(this); if flags & 1, release with ext_634273(this, 0x65); returns
// this. Name GUESS.
static u8 *THISCALL baseRelease_5422b0(u8 *self, u32 flags) {
  ext_5421b0(self);
  if (flags & 1) ext_634273(self, 0x65);
  return self;
}
PCREG(5422b0, baseRelease_5422b0);

// 0x5c5bb0, thiscall(obj): [this+0x48] = ext_4e5e60(obj); [this+0x4c] = ext_4e5e60(obj). Note: the asm passes obj in ecx
// each time. Name GUESS.
static void THISCALL readTwo_5c5bb0(u8 *self, u8 *obj) {
  *(u32 *)(self + 0x48) = ext_4e5e60(obj);
  *(u32 *)(self + 0x4c) = ext_4e5e60(obj);
}
PCREG(5c5bb0, readTwo_5c5bb0);
