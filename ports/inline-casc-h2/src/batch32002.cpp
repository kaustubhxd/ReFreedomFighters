// batch32002.cpp - h2 batch 32002: simple field accessors
#include "ff.h"

// 0x4ea380, thiscall(self): set word [self + 0xa4] = 0x100
static void THISCALL fn4ea380(u8 *self) {
  *(u16 *)(self + 0xa4) = 0x100;
}
PCREG(4ea380, fn4ea380);

// 0x4f4cb0, thiscall(self) ret eax: return dword at [self + 0x8b]
static u32 THISCALL fn4f4cb0(u8 *self) {
  return *(u32 *)(self + 0x8b);
}
PCREG(4f4cb0, fn4f4cb0);

// 0x5333c0, thiscall(self) ret eax: return dword at [self + 0x52fe]
static u32 THISCALL fn5333c0(u8 *self) {
  return *(u32 *)(self + 0x52fe);
}
PCREG(5333c0, fn5333c0);

// 0x5334f0, thiscall(self) ret eax: return dword at [self + 0x548a]
static u32 THISCALL fn5334f0(u8 *self) {
  return *(u32 *)(self + 0x548a);
}
PCREG(5334f0, fn5334f0);
