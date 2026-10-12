// batch2479.cpp - decomp area 24, batch 2479.
#include "ff.h"

extern "C" void THISCALL ext_43de40(void *self, u32 a0, u32 a1, u32 a2);  // ZSTDOBJ base constructor, ret 12
extern "C" void THISCALL ext_4dbb00(void *self, u32 flag);                // ZBaseGeom::LightNotifyPotentialDetachment(bool)
extern "C" void THISCALL ext_45c3e0(void *self);                          // SEH destructor body (recorder)

// 0x45b460 (GUESS), thiscall, ret 12, eax = this. 8.0f is 0x41000000 and 10.0f is 0x41200000.
static u8 *THISCALL stdObjDerivedCtor45b460(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43de40(self, a0, a1, a2);
  *(u32 *)self = 0x684358u;
  *(u32 *)(self + 0x28) = 0x41000000u;
  *(u32 *)(self + 0x2c) = 0x41200000u;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)(self + 0x34) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x18) = 0;
  return self;
}
PCREG(45b460, stdObjDerivedCtor45b460);

// 0x447920 (GUESS destructor body). SEH frame not reproduced: the original installs an exception frame on fs:[0] and restores
// it; this port does not.
static void THISCALL lightDtorBody447920(u8 *self) {
  *(u32 *)self = 0x67dc30u;
  ext_4dbb00(*(void **)(self + 8), 0u);
  ext_45c3e0(self);
}
PCREG(447920, lightDtorBody447920);
