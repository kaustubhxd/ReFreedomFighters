#include "ff.h"
// batch2759.cpp - unclaimed-27 batch 59 (residue 6). FUN_004d3a60 (GUESS): thiscall, four stack arguments, ret 0x10.
// Scans the 18 entries (stride 0x14) of the table at 0x6e7a38 for a first dword equal to 0xd; passes (entry - 8) or 0 to
// vtable slot +0xac of this, with the four arguments in order (a8, ac, entry-8, a14, a10), and returns its eax.
static u32 THISCALL funcTableVcall(u8 *self, u32 a8, u32 ac, u32 a10, u32 a14) {
  u32 e = 0;
  for (u32 p = 0x6e7a38; p != 0x6e7ba0; p += 0x14) {
    if (*(u32 *)p == 0xd) { e = p - 8; break; }
  }
  typedef u32(THISCALL * F)(u8 *, u32, u32, u32, u32, u32);
  return (*(F **)self)[0xac / 4](self, a8, ac, e, a14, a10);
}
PCREG(4d3a60, funcTableVcall);
