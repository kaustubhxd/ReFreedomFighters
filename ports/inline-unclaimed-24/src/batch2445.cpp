// batch2445.cpp - decomp area 24, batch 2445 (gap band): three constructors.
#include "ff.h"

extern "C" void THISCALL ext_43de40(void *self, u32 a0, u32 a1, u32 a2);  // ZSTDOBJ base constructor, ret 12
extern "C" void THISCALL ext_45c3a0(void *self, u32 a0, u32 a1, u32 a2);  // ZGEOM base constructor, ret 12

// 0x44e6d0 (GUESS, ZSTDOBJ-derived), thiscall, ret 12, eax = this.
static u8 *THISCALL stdObjDerivedCtor44e6d0(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43de40(self, a0, a1, a2);
  *(u32 *)self = 0x680abcu;
  return self;
}
PCREG(44e6d0, stdObjDerivedCtor44e6d0);

// 0x44edf0 (GUESS, ZSTDOBJ-derived), thiscall, ret 12, eax = this.
static u8 *THISCALL stdObjDerivedCtor44edf0(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43de40(self, a0, a1, a2);
  *(u32 *)self = 0x68110cu;
  return self;
}
PCREG(44edf0, stdObjDerivedCtor44edf0);

// 0x452790 (GUESS, ZGEOM-derived), thiscall, ret 12, eax = this.
static u8 *THISCALL geomDerivedCtor452790(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_45c3a0(self, a0, a1, a2);
  *(u32 *)self = 0x6815d8u;
  return self;
}
PCREG(452790, geomDerivedCtor452790);
