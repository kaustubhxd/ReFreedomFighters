#include "ff.h"
// batch2725.cpp - unclaimed-27 batch 25 (gap band; docs/20-unclaimed-27.md). Name unknown (GUESS).
// 0x59ffc0 is a verified getter (docs/20-inline-batch-4-5.md, row 631); here it is a hook (stub) so the port calls the same address.
extern "C" u32 THISCALL ext_59ffc0(u8 *self);

// 0x5979c0 (GUESS): thiscall, no arguments, returns eax (a count). For i in 0 .. count-1 (count = signed dword at this+0x1fae):
// r = slot +0x58 of the global's +0x9b object with the dword at this+0x1dae+4i; if 0x59ffc0(r) == 5, counts it. Returns the count.
static u32 THISCALL funcCountFives(u8 *self) {
  typedef u32(THISCALL * slot58_fn)(u8 *, u32);
  u32 cnt = 0;
  s32 n = *(s32 *)(self + 0x1fae);
  for (s32 i = 0; i < n; i++) {
    u32 arg = *(u32 *)(self + 0x1dae + 4 * i);
    u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
    u8 *eng = *(u8 **)(g + 0x9b);
    u32 r = ((slot58_fn)(*(u32 *)(*(u32 *)eng + 0x58)))(eng, arg);
    if (ext_59ffc0((u8 *)(unsigned long)r) == 5u) cnt++;
  }
  return cnt;
}
PCREG(5979c0, funcCountFives);
