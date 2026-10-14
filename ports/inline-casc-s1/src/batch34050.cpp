// batch34050.cpp - cascade escalation batch 34050 (queue item 0x4c1ed0): a thiscall wrapper that drops its first argument.
#include "ff.h"

extern "C" u32 THISCALL ext_4c0b00(void *self, u32 b);   // thiscall ret 4

// 0x4c1ed0, thiscall(a, b) ret 8: returns 0x4c0b00(this, b); the first argument is ignored.
static u32 THISCALL fn4c1ed0(u8 *self, u32 a, u32 b) {
  (void)a;
  return ext_4c0b00(self, b);
}
PCREG(4c1ed0, fn4c1ed0);
