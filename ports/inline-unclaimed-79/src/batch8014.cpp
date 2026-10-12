#include "ff.h"
// batch8014.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x4931a0 (GUESS): thiscall, no arguments. Calls slot +0xac for a count n, then calls slot +0xa4 n times.
static void THISCALL f_4931a0(u8 *self) {
  s32 n = vcall<s32>(self, 0xac);
  for (; n > 0; --n) vcall<void>(self, 0xa4);
}
PCREG(4931a0, f_4931a0);
