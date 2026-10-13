#include "ff.h"
// batch3537.cpp - claim 37 (docs/20-gap-band-561000.md): 0x5c56c0 CTargetObtained::Load(ZLoadGame*). Thiscall, one unused arg, ret 4.
// Stubbed in the harness: 0x6352f0 (thiscall, one pointer arg; writes a value through it) and 0x5c56f0 (thiscall, one arg).

extern "C" void THISCALL ext_6352f0(u8 *self, u32 a0);
extern "C" void THISCALL ext_5c56f0(u8 *self, u32 a0);

u8 THISCALL ctargetObtainedLoad(u8 *self, u32 unusedArg) {
  u32 local = 0;
  (void)unusedArg;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ext_6352f0(self, (u32)&local);
  ext_5c56f0(self, (u32)&local);
  return 1;
}
PCREG(5c56c0, ctargetObtainedLoad);
