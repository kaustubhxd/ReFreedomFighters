#include "ff.h"
// batch7914.cpp - unclaimed-79 batch 14 (docs/20-unclaimed-79.md, gap band). Name is GUESS (no GC name; naming only).

// 0x481260, (GUESS) thiscall, three stack arguments (ret 0xc). If the dword at p is zero, returns. Otherwise adds delta to
// this+8; calls slot +4 of the object at this+0x14 with p (its result is a record pointer r); stores val at r and delta at r+4.
static void THISCALL guess481260(u8 *self, u8 *p, u32 val, float delta) {
  if (*(u32 *)p == 0)
    return;
  *(float *)(self + 8) = *(float *)(self + 8) + delta;
  u8 *r = vcall<u8 *, u8 *>(*(u8 **)(self + 0x14), 0x4, p);
  *(u32 *)r = val;
  *(float *)(r + 4) = delta;
}
PCREG(481260, guess481260);
