// batch979.cpp - area 56 band, claim A45 (0x53b6d0): constant stores only, no calls.
#include "ff.h"

// A45 0x53b6d0: five unaligned dword stores of constants.
static void THISCALL initConst53b6d0(u8 *self) {
  *(u32 *)(self + 0xee) = 1;
  *(u32 *)(self + 0xf2) = 0x12345678u;
  *(u32 *)(self + 0xf6) = 3;
  *(u32 *)(self + 0xce) = 0x12345678u;
  *(u32 *)(self + 0xc5) = 1;
}
PCREG(53b6d0, initConst53b6d0);
