#include "ff.h"
// batch2718.cpp - unclaimed-27 batch 18 (gap band; docs/20-unclaimed-27.md). Names unknown (GUESS).

// 0x589600 is original code (bound by build.sh): thiscall, no arguments.
extern "C" void THISCALL ext_589600(u8 *self);
// 0x634273 is the CRT free (cdecl, two arguments: pointer and size; the caller cleans).
extern "C" void ext_634273(u8 *p, u32 size);

// 0x588920 (GUESS): void, no arguments. If the global at 0x7003b8 is nonzero, calls its vtable slot 0 with 1 (thiscall), then
// clears the global.
static void funcGlobalDeleteAndClear() {
  u8 *o = (u8 *)(unsigned long)G(u32, 0x7003b8);
  if (o != 0) {
    typedef void(THISCALL * slot0_fn)(u8 *, u32);
    ((slot0_fn)(*(u32 *)(*(u32 *)o)))(o, 1u);
  }
  G(u32, 0x7003b8) = 0;
}
PCREG(588920, funcGlobalDeleteAndClear);

// 0x589810 (GUESS): thiscall, one argument (flags). Calls 0x589600; if bit 0 of the flags is set, calls the CRT free on this with
// size 0x2c8e; returns this.
static u8 *THISCALL funcCallThenFree(u8 *self, u32 flags) {
  ext_589600(self);
  if (flags & 1u) ext_634273(self, 0x2c8eu);
  return self;
}
PCREG(589810, funcCallThenFree);
