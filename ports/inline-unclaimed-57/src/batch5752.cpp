// batch5752.cpp - unclaimed-57, band batch 52 (name GUESS): 0x5d8880, thiscall, no args (non-deleting destructor shape). vtable 0x6b5fc8 at
// this+0; if dword this+0x20 is set: 0x41e2c0(that value) (cdecl, one arg); p = dword this+0x24; if p is set: 0x634273(p, 8) (cdecl, two args);
// dword this+0x24 = 0; dword this+0x20 = 0; then tail-jump to 0x43de70(this). Written as calls followed by return (the callee takes no stack
// arguments). The three callees are unverified: hooked and logged in the spec.
#include "ff.h"

extern "C" void ext_41e2c0(u8 *p);                 // cdecl, one argument (hooked and logged in the spec)
extern "C" void ext_634273(u8 *p, u32 size);       // cdecl, two arguments (hooked and logged in the spec)
extern "C" void THISCALL ext_43de70(u8 *self);    // base dtor, no arguments (hooked and logged in the spec)

static void THISCALL unnamed5d8880(u8 *self) {
  *(u32 *)self = 0x6b5fc8;
  u32 a = *(u32 *)(self + 0x20);
  if (a != 0) ext_41e2c0((u8 *)(unsigned long)a);
  u32 p = *(u32 *)(self + 0x24);
  if (p != 0) ext_634273((u8 *)(unsigned long)p, 8);
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x20) = 0;
  ext_43de70(self);
}
PCREG(5d8880, unnamed5d8880);
