#include "ff.h"
// batch3536.cpp - claim 36 (docs/20-gap-band-561000.md): 0x44e800 ZBOUND::CopyDataBlock(DBLK*). Thiscall, one arg, ret 4.
// Stubbed in the harness: 0x610100 (thiscall, one arg), 0x4e1b30 (thiscall, no args), 0x4dc630 (thiscall, two args).

extern "C" void THISCALL ext_610100(u8 *self, u32 a0);
extern "C" void THISCALL ext_4e1b30(u8 *self);
extern "C" void THISCALL ext_4dc630(u8 *self, u32 a0, u32 a1);

void THISCALL zboundCopyDataBlock(u8 *self, u32 arg) {
  ext_610100(self, arg);
  ext_4e1b30((u8 *)arg);
  ext_4dc630(*(u8 **)(self + 8), 0x2000, 3);
}
PCREG(44e800, zboundCopyDataBlock);
