#include "ff.h"
// batch8017.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x4964b0 (GUESS): thiscall, no arguments. s = this + [this+0x2c]. If the dword at s-4 is zero, sets it to the result of
// slot +0xd0 of the global object at 0x70038c called with this. Returns the dword at s-4.
static u32 THISCALL f_4964b0(u8 *self) {
  u8 *s = self + *(u32 *)(self + 0x2c);
  if (*(u32 *)(s - 4) == 0) {
    u32 v = vcall<u32, u32>(G(u8 *, 0x70038c), 0xd0, (u32)(unsigned long)self);
    *(u32 *)(s - 4) = v;
  }
  return *(u32 *)(s - 4);
}
PCREG(4964b0, f_4964b0);
