#include "ff.h"
// batch1506.cpp - unclaimed-15 claim 6 (docs/20-unclaimed-15.md): two scalar deleting destructors.
// 0x441d20 is ZOctreeCompiled::~ZOctreeCompiled() (medium name). 0x487960 has no GC name; GUESS: a movement class.
// Both are thiscall with one argument (the flags, bit 1 = delete). The CRT delete 0x634273 is cdecl (this, size) and
// the embedded sub-destructor 0x480fd0 is thiscall with no arguments; both are stubbed in the harness.

extern "C" void ext_634273(u8 *p, u32 size);     // CRT delete, cdecl, stubbed in the harness
extern "C" void THISCALL ext_480fd0(u8 *self);   // embedded sub-destructor, stubbed in the harness

// 0x441d20, ZOctreeCompiled::~ZOctreeCompiled() (medium): vtable 0x67d108, then delete with size 0x18 if bit 1.
static u32 THISCALL octreeCompiledDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x67d108;
  if (flags & 1)
    ext_634273(self, 0x18);
  return (u32)self;
}
PCREG(441d20, octreeCompiledDtor);

// 0x487960, GUESS: a movement class's scalar deleting destructor. Vtable 0x68d018, sub-destructors on +0x55, +0x3d and
// +0x25, vtable 0x68cf50, then delete with size 0x36d if bit 1.
static u32 THISCALL movementDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x68d018;
  ext_480fd0(self + 0x55);
  ext_480fd0(self + 0x3d);
  ext_480fd0(self + 0x25);
  *(u32 *)self = 0x68cf50;
  if (flags & 1)
    ext_634273(self, 0x36d);
  return (u32)self;
}
PCREG(487960, movementDtor);
