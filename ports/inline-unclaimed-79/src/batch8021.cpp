#include "ff.h"
// batch8021.cpp - unclaimed-79 resumed parked row (docs/20-unclaimed-79.md). Name GUESS (no GC name).

extern "C" u8 *ext_41e290(u32 n);                  // cdecl allocator, stubbed in spec
extern "C" void THISCALL ext_4e6680(u8 *self);      // area 69's function, runs as exe code

// 0x48a440 (GUESS): no arguments, plain ret. Allocates 0xc bytes via 0x41e290; if nonzero, runs 0x4e6680 on it, sets the
// vtable 0x68d468 at it, and returns it. Returns 0 when the allocation fails.
static u8 *f_48a440() {
  u8 *p = ext_41e290(0xc);
  if (p == 0) return 0;
  ext_4e6680(p);
  *(u32 *)p = 0x68d468;
  return p;
}
PCREG(48a440, f_48a440);
