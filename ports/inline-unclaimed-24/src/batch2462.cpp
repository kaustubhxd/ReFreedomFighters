// batch2462.cpp - decomp area 24, batch 2462 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_43de40(void *self, u32 a0, u32 a1, u32 a2);  // ZSTDOBJ base constructor, ret 12
extern "C" void THISCALL ext_43e990(void *self, u32 a0, u32 a1, u32 a2);  // ZGROUP base constructor, ret 12
extern "C" void THISCALL ext_44c060(void *self);                           // ZSNDOBJ::Free()
extern "C" void THISCALL ext_43de70(void *self);                           // plain ret

// 0x4519a0 (GUESS), thiscall, ret 12, eax = this. 100.0f is 0x42c80000.
static u8 *THISCALL stdObjDerivedCtor4519a0(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43de40(self, a0, a1, a2);
  *(u32 *)self = 0x6813c0u;
  *(u32 *)(self + 0x18) = 0x42c80000u;
  *(u32 *)(self + 0x1c) = 0x42c80000u;
  *(u32 *)(self + 0x20) = 0x42c80000u;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x2c) = 0;
  *(u32 *)(self + 0x40) = 0;
  *(u32 *)(self + 0x3c) = 0;
  return self;
}
PCREG(4519a0, stdObjDerivedCtor4519a0);

// 0x441b90 (GUESS), thiscall, ret 12, eax = this.
static u8 *THISCALL groupDerivedCtor441b90(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43e990(self, a0, a1, a2);
  *(u32 *)self = 0x67cdbcu;
  *(u32 *)(self + 0x7b) = 0;
  *(u32 *)(self + 0x71) = 0;
  self[0x5c] = 0;
  *(u16 *)(self + 0x75) = 0;
  *(u32 *)(self + 0x77) = 0;
  *(u32 *)(self + 0x7f) = 0xffffffffu;
  for (u32 k = 0; k < 16; ++k)
    self[0x5d + k] = 0;
  *(u32 *)(self + 0x6d) = 0;
  return self;
}
PCREG(441b90, groupDerivedCtor441b90);

// 0x44b5c0 (GUESS destructor body), thiscall, plain ret. SEH frame not reproduced: the original installs an exception frame
// on fs:[0] and restores it; this port does not.
static void THISCALL sndObjDtorBody44b5c0(u8 *self) {
  *(u32 *)self = 0x67fc30u;
  ext_44c060(self);
  ext_43de70(self);
}
PCREG(44b5c0, sndObjDtorBody44b5c0);
