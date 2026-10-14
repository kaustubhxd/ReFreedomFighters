// batch33009.cpp - cascade h3: one simple 4-instruction bit extraction function
#include "ff.h"

// 0x45f8c0: read dword, shift right 5, mask bit 0
static u8 THISCALL fn45f8c0(u8 *self) {
  u32 val = *(u32 *)(self + 0x14);
  return (u8)((val >> 5) & 1);
}
PCREG(45f8c0, fn45f8c0);
