#include "ff.h"
// batch8020.cpp - unclaimed-79 resumed parked row (docs/20-unclaimed-79.md). Name GUESS (no GC name).

// 0x485060 (GUESS): thiscall (ret 4). Stores its float argument at this+0x4dd, then calls vtable slot +0x5ec with no arguments.
static void THISCALL f_485060(u8 *self, float v) {
  *(float *)(self + 0x4dd) = v;
  vcall<void>(self, 0x5ec);
}
PCREG(485060, f_485060);
