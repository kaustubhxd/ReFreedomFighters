#include "ff.h"
// batch3531.cpp - gap band claim 31 (docs/20-gap-band-561000.md): 0x573490 (GUESS name). Thiscall, two args, ret 8.
// Calls 0x562e90 on this with the two arguments (stubbed), clears the byte at +0x180, returns al = 0.

extern "C" void THISCALL ext_562e90(u8 *self, u32 a0, u32 a1);

u8 THISCALL gapMethod573490(u8 *self, u32 a0, u32 a1) {
  ext_562e90(self, a0, a1);
  *(u8 *)(self + 0x180) = 0;
  return 0;
}
PCREG(573490, gapMethod573490);
