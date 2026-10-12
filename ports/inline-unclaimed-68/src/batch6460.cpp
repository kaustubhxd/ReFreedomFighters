// batch6460.cpp - unclaimed-68 batch 46 (claim 46, gap band). Name from the GC name map. Callees 0x44c370 and 0x4bb550 run as exe code.
#include "ff.h"

extern "C" void THISCALL ext_44c370(u8 *self);  // ZSNDOBJ::Stop, no arguments, ret 0
extern "C" void THISCALL ext_4bb550(u8 *self);  // ZSoundToggle::DefaultValues, no arguments, ret 0

// 0x4bb5e0, ZSoundToggle::Init() (high): thiscall, void. When the byte at this+0x50 is zero and the sub-object at this+0x44 is not null,
// ZSNDOBJ::Stop runs on that sub-object. Then the function tail-jumps to DefaultValues with this (the port calls it and returns).
static void THISCALL soundToggleInit(u8 *self) {
  if (self[0x50] == 0) {
    u8 *s = *(u8 **)(self + 0x44);
    if (s) ext_44c370(s);
  }
  ext_4bb550(self);
}
PCREG(4bb5e0, soundToggleInit);
