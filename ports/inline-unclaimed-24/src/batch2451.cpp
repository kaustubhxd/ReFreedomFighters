// batch2451.cpp - decomp area 24, batch 2451 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_43de40(void *self, u32 a0, u32 a1, u32 a2);  // ZSTDOBJ base constructor, ret 12
extern "C" void THISCALL ext_43e990(void *self, u32 a0, u32 a1, u32 a2);  // ZGROUP base constructor, ret 12
extern "C" void THISCALL ext_45c680(void *self, u32 on);                  // ZGEOM::Activate(bool), ret 4
extern "C" void THISCALL ext_44c2b0(void *self);                          // ZSNDOBJ::Start()
extern "C" void THISCALL ext_44c370(void *self);                          // ZSNDOBJ::Stop()

// 0x44c3d0 (GUESS), thiscall, ret 12, eax = this.
static u8 *THISCALL stdObjDerivedCtor44c3d0(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43de40(self, a0, a1, a2);
  *(u32 *)self = 0x67ff2cu;
  self[0x18] = 0;
  return self;
}
PCREG(44c3d0, stdObjDerivedCtor44c3d0);

// 0x4545f0 (GUESS), thiscall, ret 12, eax = this.
static u8 *THISCALL groupDerivedCtor4545f0(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43e990(self, a0, a1, a2);
  *(u32 *)self = 0x6820b8u;
  *(u32 *)(self + 0x5c) = 0;
  return self;
}
PCREG(4545f0, groupDerivedCtor4545f0);

// 0x44b820 ZSNDOBJ::Activate(bool), thiscall, ret 4.
static void THISCALL sndObjActivate(u8 *self, u32 on) {
  ext_45c680(self, on);
  if ((u8)on)
    ext_44c2b0(self);
  else
    ext_44c370(self);
}
PCREG(44b820, sndObjActivate);
