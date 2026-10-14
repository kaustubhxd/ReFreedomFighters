// batch33025.cpp - h3 batch 33025: conditional flag setter
#include "ff.h"

// 0x45e900, thiscall: set/clear bit 0x10 in [ecx + 0x14] based on arg
static void THISCALL fn45e900(u8 *self, u8 flag) {
  u32 *field = (u32 *)(self + 0x14);
  if (flag) {
    *field |= 0x10;
  } else {
    *field &= ~0x10;
  }
}
PCREG(45e900, fn45e900);
