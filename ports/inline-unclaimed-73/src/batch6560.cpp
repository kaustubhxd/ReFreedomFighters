// batch6560.cpp - area 73 batch 65 (gap band, GUESS name): FUN_4f71d0.
#include "ff.h"

extern "C" void THISCALL ext_4fa120(u8 *self, u32 a);

// 0x4f71d0 (GUESS FUN_4f71d0): ret 4. 0x4fa120(this, 1) first. When the argument's low byte is 0, vtable slots +0x35c and
// +0x360 are called; otherwise vtable slot +0x364.
static void THISCALL guess4f71d0(u8 *self, u32 flag) {
  ext_4fa120(self, 1u);
  if ((u8)flag == 0) {
    vcall<void>(self, 0x35c);
    vcall<void>(self, 0x360);
  } else {
    vcall<void>(self, 0x364);
  }
}
PCREG(4f71d0, guess4f71d0);
