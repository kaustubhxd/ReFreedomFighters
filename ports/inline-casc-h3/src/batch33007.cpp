// batch33007.cpp - cascade h3: four small 2-instruction constant/accessor functions
#include "ff.h"

// 0x614ed0: return constant 0x1c
static u32 THISCALL fn614ed0(u8 *self) {
  return 0x1c;
}
PCREG(614ed0, fn614ed0);

// 0x626a70: return constant 0x6be898
static u32 THISCALL fn626a70(u8 *self) {
  return 0x6be898;
}
PCREG(626a70, fn626a70);

// 0x63db30: return constant 0x10
static u32 THISCALL fn63db30(u8 *self) {
  return 0x10;
}
PCREG(63db30, fn63db30);

// 0x64a6f0: read dword member at offset 0xc
static u32 THISCALL fn64a6f0(u8 *self) {
  return *(u32 *)(self + 0xc);
}
PCREG(64a6f0, fn64a6f0);
