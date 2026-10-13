#include "ff.h"
// batch3535.cpp - gap band claim 35 (docs/20-gap-band-561000.md): 0x561eb0 (GUESS name). Thiscall, one arg, ret 4.
// Calls this's vtable +0xc8 with the argument, then 0x561180, 0x5612c0 and 0x561330 on this with the same argument (stubbed).

typedef void(THISCALL *TV1)(u8 *self, u32 a0);

extern "C" void THISCALL ext_561180(u8 *self, u32 a0);
extern "C" void THISCALL ext_5612c0(u8 *self, u32 a0);
extern "C" void THISCALL ext_561330(u8 *self, u32 a0);

void THISCALL gapMethod561eb0(u8 *self, u32 a0) {
  ((TV1)*(u32 *)(*(u32 *)self + 0xc8))(self, a0);
  ext_561180(self, a0);
  ext_5612c0(self, a0);
  ext_561330(self, a0);
}
PCREG(561eb0, gapMethod561eb0);
