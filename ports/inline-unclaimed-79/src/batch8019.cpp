#include "ff.h"
// batch8019.cpp - unclaimed-79 resumed parked rows (docs/20-unclaimed-79.md). Names GUESS (no GC name).

extern "C" void ext_634273(u8 *p, u32 n);                                             // cdecl heap free wrapper
extern "C" u32 THISCALL ext_4e18e0(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4); // not verified, stubbed in spec

// 0x49d2c0 (GUESS): thiscall, no arguments. Sets vtable 0x68ee80 at this, then frees this+4 and this+8 (size 4 each).
static void THISCALL f_49d2c0(u8 *self) {
  u8 *p1 = *(u8 **)(self + 0x4);
  u8 *p2 = *(u8 **)(self + 0x8);
  *(u32 *)self = 0x68ee80;
  ext_634273(p1, 4);
  ext_634273(p2, 4);
}
PCREG(49d2c0, f_49d2c0);

// 0x493b60 (GUESS): stdcall (ret 0x10). Calls 0x4e18e0 with this = first argument and stack arguments (a, b, c, 0, 0).
// Returns the callee's eax.
static u32 STDCALL f_493b60(u32 p, u32 a, u32 b, u32 c) {
  return ext_4e18e0((u8 *)(unsigned long)p, a, b, c, 0, 0);
}
PCREG(493b60, f_493b60);
