// batch32008.cpp - h2 batch 32008: simple tier B functions
#include "ff.h"

extern "C" u32 ext_4c5770(u32 val);

// 0x4c5680, thiscall(self) ret al: read byte at [self+0x52], push, call 0x4c5770, ret eax
static u8 THISCALL fn4c5680(u8 *self) {
  u8 val = *(u8 *)(self + 0x52);
  u32 result = ext_4c5770(val);
  return (u8)result;
}
PCREG(4c5680, fn4c5680);
