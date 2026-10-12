// batch6050.cpp - area 73 batch 60 (gap band, GUESS name): FUN_4f50c0.
#include "ff.h"

extern "C" void THISCALL ext_4ef130(u8 *self);
extern "C" void THISCALL ext_4dc630(u8 *self, u32 a, u32 b);

// 0x4f50c0 (GUESS FUN_4f50c0): plain ret. Calls 0x4ef130 on this, vtable slots +0x244 and +0x27c on this, then calls
// 0x4dc630 with this+8 as the object and (0x800000, 0) as the arguments (the first argument pushed last, so it is the 0x800000).
static void THISCALL guess4f50c0(u8 *self) {
  ext_4ef130(self);
  vcall<void>(self, 0x244);
  vcall<void>(self, 0x27c);
  ext_4dc630(*(u8 **)(self + 8), 0x800000u, 0u);
}
PCREG(4f50c0, guess4f50c0);
