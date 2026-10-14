// batch1629.cpp - ZDllSound::Reset (soundtimers thread, 2026-10-11).
#include "st.h"

// 0x5396d0 ZDllSound::Reset() [medium]: clears the listener reference (+0x51ad), empties the two embedded lists
// (+0x53b2 and +0x5306, vtable +0xc each), calls the DLL's own virtual +0xf4(0), clears the status word +0x5147 and
// four per-group flag bytes (+0x15, +0x22, +0x2f, +0x3c). GUESS: the meaning of +0xf4 and of the four flags (the group
// muted flags of the layout 9 bytes per group, seen in SetGroupVolume) is not traced.
void THISCALL ZDllSound_Reset(u8 *self) {
  AT(u32, self, 0x51ad) = 0;
  vcall<void>(self + 0x53b2, 0xc);
  vcall<void>(self + 0x5306, 0xc);
  vcall<void>(self, 0xf4, (u32)0);
  AT(u16, self, 0x5147) = 0;
  AT(u8, self, 0x15) = 0;
  AT(u8, self, 0x22) = 0;
  AT(u8, self, 0x2f) = 0;
  AT(u8, self, 0x3c) = 0;
}
PCREG(5396d0, ZDllSound_Reset);
