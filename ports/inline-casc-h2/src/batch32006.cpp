// batch32006.cpp - h2 batch 32006: early tier B functions with calls
#include "ff.h"

extern "C" void ext_5390b0(void);
extern "C" void ext_4c24b0(u8 *self);

// 0x533ba0, thiscall(self) ret al: call 0x5390b0, return 1
static u8 THISCALL fn533ba0(u8 *self) {
  (void)self;
  ext_5390b0();
  return 1;
}
PCREG(533ba0, fn533ba0);

// 0x4bb9d0, thiscall(self): AND [self + 4] with 0xffffffbf, then call 0x4c24b0
static void THISCALL fn4bb9d0(u8 *self) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  ext_4c24b0(self);
}
PCREG(4bb9d0, fn4bb9d0);
