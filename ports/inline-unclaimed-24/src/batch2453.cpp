// batch2453.cpp - decomp area 24, batch 2453 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_45f960(void *self, void *sg);      // ZGEOM::Save(ZSaveGame*), ret 4
extern "C" void THISCALL ext_45c3a0(void *self, u32 a0, u32 a1, u32 a2);  // ZGEOM base constructor, ret 12

// 0x442f90 ZTreeGroup::FreeGlobalBounds(), thiscall, plain ret.
static void THISCALL treeGroupFreeGlobalBounds(u8 *self) {
  for (u32 i = 0; i < 5; ++i) {
    u32 *slot = (u32 *)(self + 0x5d + 4 * i);
    if (*slot) {
      vcall<void>((void *)*slot, 0x28, 1u);
      *slot = 0;
    }
  }
}
PCREG(442f90, treeGroupFreeGlobalBounds);

// 0x456f50 ZParticleTemplate::Save(ZSaveGame*), thiscall, ret 4, AL = 1.
static u8 THISCALL particleTemplateSave(u8 *self, void *sg) {
  ext_45f960(self, sg);
  vcall<void>(sg, 0x3c, *(u32 *)(self + 0xed));
  return 1;
}
PCREG(456f50, particleTemplateSave);

// 0x449d40 (GUESS), thiscall, ret 12, eax = this.
static u8 *THISCALL zgeomDerivedCtor449d40(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_45c3a0(self, a0, a1, a2);
  *(u32 *)self = 0x67f61cu;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  return self;
}
PCREG(449d40, zgeomDerivedCtor449d40);
