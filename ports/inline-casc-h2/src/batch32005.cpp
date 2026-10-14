// batch32005.cpp - h2 batch 32005: bit operations and multi-write functions
#include "ff.h"

// 0x65f560, thiscall(self) ret eax: return [self + 0xc] + 0x181f9
static u32 THISCALL fn65f560(u8 *self) {
  return *(u32 *)(self + 0xc) + 0x181f9;
}
PCREG(65f560, fn65f560);

// 0x4d43c0, thiscall(self) ret al: compare [self + 4] with 0, set byte [self + 4] to result
static u8 THISCALL fn4d43c0(u8 *self) {
  u8 result = (self[4] == 0) ? 1 : 0;
  self[4] = result;
  return result;
}
PCREG(4d43c0, fn4d43c0);

// 0x4f4cc0, thiscall(self) ret al: return ([self + 0x70] >> 4) & 1
static u8 THISCALL fn4f4cc0(u8 *self) {
  u32 eax = *(u32 *)(self + 0x70);
  eax >>= 4;
  return eax & 1;
}
PCREG(4f4cc0, fn4f4cc0);

// 0x52a200, thiscall(self): write 3 dwords
static void THISCALL fn52a200(u8 *self) {
  *(u32 *)(self + 0x29) = 0x437a0000;
  *(u32 *)(self + 0x2d) = 0xc3c80000;
  *(u32 *)(self + 0x31) = 0xc0800000;
}
PCREG(52a200, fn52a200);
