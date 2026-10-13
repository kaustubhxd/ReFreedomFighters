// batch410.cpp - 0x579560 (residue 2; thiscall, no arguments). Calls 0x562440 (thiscall, no arguments), then 0x563510 with
// argument 0x6a6f98 (thiscall, one stack argument), then 0x563610 with argument 0x6a9b08 (thiscall, one stack argument).
// All three are exe functions hooked by address in the spec (GUESS: bodies not ported).
#include "ff.h"

extern "C" void THISCALL ext_562440(void *self);
extern "C" void THISCALL ext_563510(void *self, u32 arg);
extern "C" void THISCALL ext_563610(void *self, u32 arg);

static void THISCALL initThree(u8 *self) {
  ext_562440(self);
  ext_563510(self, 0x6a6f98u);
  ext_563610(self, 0x6a9b08u);
}
PCREG(579560, initThree);
