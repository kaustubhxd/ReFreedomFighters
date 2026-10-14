// batch33016.cpp - h3 batch 33016: simple 2-instruction functions
#include "ff.h"

// 0x4744e0, thiscall, no args: return ecx + 0x34f
static void *THISCALL fn4744e0(u8 *self) {
  return self + 0x34f;
}
PCREG(4744e0, fn4744e0);

// 0x486e20, cdecl, no args: return 0x68ccb4
static void *fn486e20(void) {
  return (void *)0x68ccb4;
}
PCREG(486e20, fn486e20);
