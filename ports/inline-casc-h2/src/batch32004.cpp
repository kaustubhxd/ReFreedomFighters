// batch32004.cpp - h2 batch 32004: simple constants and multi-write functions
#include "ff.h"

// 0x64c770, (self) ret eax: return constant 0x71
static u32 fn64c770(void) {
  return 0x71;
}
PCREG(64c770, fn64c770);

// 0x654710, (self) ret eax: return constant 0x6f62b8
static u32 fn654710(void) {
  return 0x6f62b8;
}
PCREG(654710, fn654710);

// 0x549350, thiscall(self): set [self + 0x40b1] = 0x6a3298, then [self] = 0x6a3234
static void THISCALL fn549350(u8 *self) {
  *(u32 *)(self + 0x40b1) = 0x6a3298;
  *(u32 *)self = 0x6a3234;
}
PCREG(549350, fn549350);

// 0x5de3d0, thiscall(self): read global 0x7003b8, write self to [eax + 0x2c4d]
static void THISCALL fn5de3d0(u8 *self) {
  u8 *eax = *(u8 **)0x7003b8;
  *(u32 *)(eax + 0x2c4d) = (u32)self;
}
PCREG(5de3d0, fn5de3d0);
