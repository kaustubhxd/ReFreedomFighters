// batch8282.cpp - residue 6 batch 82 (GUESS name): FUN_00454620.
#include "ff.h"

extern "C" void THISCALL ext_43ea20(u8 *self);

// 0x454620 (GUESS FUN_00454620): the vtable word is set to 0x6820b8; the call then continues in 0x43ea20 on this, with no
// arguments (the only direct caller pushes none).
static void THISCALL guess454620(u8 *self) {
  *(u32 *)self = 0x6820b8;
  ext_43ea20(self);
}
PCREG(454620, guess454620);
