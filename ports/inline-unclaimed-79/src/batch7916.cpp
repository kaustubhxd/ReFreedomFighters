#include "ff.h"
// batch7916.cpp - unclaimed-79 batch 16 (docs/20-unclaimed-79.md, gap band). Name from the GC name map (high).
// The free helper 0x634273 (cdecl: block, size) runs as original code (stubbed by the harness).

extern "C" void ext_634273(void *p, u32 size);

// 0x481140, ZAnimDefsListRandom::~ZAnimDefsListRandom() (high). Scalar deleting destructor: stores the vtable constant at
// this+0, releases the object at this+0x14 through its slot 0 (argument 1) when it is not null, and when the low bit of the
// flags argument is set frees this (size 0x18). Returns this. Callee pops 4 bytes.
static u8 *THISCALL animDefsListRandomDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x68b604u;
  u8 *o = *(u8 **)(self + 0x14);
  if (o != 0)
    vcall<void, u32>(o, 0x0, 1u);
  if ((flags & 1) != 0)
    ext_634273(self, 0x18u);
  return self;
}
PCREG(481140, animDefsListRandomDtor);
