// batch1132.cpp - unclaimed-11 batch 33 (gap band): 0x5a5be0, GUESS (one float argument, ret 4).
#include "ff.h"

extern "C" void THISCALL ext_5ec2b0(void *obj, float f, s32 n);   // stubbed in the harness (two stack arguments)

// 0x5a5be0, GUESS: fade counter with a clamp at 1.0 (NaN leaves the value), then a call with (value, -1).
static void THISCALL guessFadeAndFlag(u8 *self, float delta) {
  u8 *obj = *(u8 **)(self + 0x689);
  if (obj == nullptr) return;
  obj[0x35] = 0;
  float x = bitsf(*(u32 *)(self + 0x68d)) + delta;
  if (x > 1.0f) x = 1.0f;
  *(u32 *)(self + 0x68d) = fbits(x);
  ext_5ec2b0(obj, x, -1);
  obj[0x35] = 1;
}
PCREG(5a5be0, guessFadeAndFlag);
