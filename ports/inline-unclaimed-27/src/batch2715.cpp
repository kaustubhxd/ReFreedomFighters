#include "ff.h"
// batch2715.cpp - unclaimed-27 batch 15 (docs/20-unclaimed-27.md). Both names are GUESS (no GC name).
// 0x5003d0 is original code (bound by build.sh): thiscall, one argument, ret 4, returns a pointer in eax.
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 a1);

// 0x4e5140 (GUESS): thiscall, no arguments, returns eax. If the dword at this+4 is nonnegative, returns 0; if bit 0x40000000
// of it is clear, returns this+0x10; otherwise returns this + 4 * (the dword at this+0x10 + 5).
static u32 THISCALL funcPickRange(u8 *self) {
  s32 v = *(s32 *)(self + 4);
  if (v >= 0) return 0;
  if (!((u32)v & 0x40000000u)) return (u32)(unsigned long)(self + 0x10);
  u32 n = *(u32 *)(self + 0x10);
  return (u32)(unsigned long)self + (n + 5) * 4;
}
PCREG(4e5140, funcPickRange);

// 0x508640 (GUESS): thiscall, one argument (an object whose +4 field is passed to the lookup with 0), ret 4. Stores 1 at
// (this+0x18)+0x690 when the dword at the lookup's result is nonzero, else 0.
static void THISCALL funcLookupFlag(u8 *self, u8 *arg) {
  u8 *p = ext_5003d0(*(u8 **)(arg + 4), 0u);
  u8 flag = *(u32 *)p != 0 ? 1 : 0;
  u8 *o = *(u8 **)(self + 0x18);
  o[0x690] = flag;
}
PCREG(508640, funcLookupFlag);
