// batch6760.cpp - area 73 batch 67 (gap band, GUESS name): FUN_4ef050.
#include "ff.h"

extern "C" void STDCALL ext_45d380(u32 a1, u32 a2);

// 0x4ef050 (GUESS FUN_4ef050): ret 8, returns 0. When the low word of a1 is 0x8000, the byte result of vtable slot +0x2c8 on
// this with a2 is stored at a2+0x10. Otherwise 0x45d380(a1, a2) is called (stdcall, pops its arguments).
static u32 THISCALL guess4ef050(u8 *self, u32 a1, u8 *a2) {
  if ((u16)a1 == 0x8000) {
    u8 r = (u8)vcall<u32>(self, 0x2c8, (u32)a2);
    a2[0x10] = r;
  } else {
    ext_45d380(a1, (u32)a2);
  }
  return 0;
}
PCREG(4ef050, guess4ef050);
