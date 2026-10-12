// batch2441.cpp - decomp area 24, batch 2441 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_45f3a0(void *self);             // ZGEOM::Load2()
extern "C" void THISCALL ext_450980(void *self, u32 flag);   // ZCloth::Initialize(bool)
extern "C" void THISCALL ext_45d5b0(void *self, const void *src);  // ZGEOM::CopyData(const ZGEOM*), ret 4
extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);     // ZBaseGeom::SetControl(unsigned int, unsigned int)

// 0x450ed0 ZCloth::Load2(), thiscall, plain ret.
static void THISCALL clothLoad2(u8 *self) {
  ext_45f3a0(self);
  ext_450980(self, 0u);
}
PCREG(450ed0, clothLoad2);

// 0x44c500 Z2DOBJ::CopyData(const ZGEOM*), thiscall, ret 4.
static void THISCALL z2dObjCopyData(u8 *self, const u8 *src) {
  u8 *sub = *(u8 **)(src + 0xc);
  if (*(u32 *)(sub + 0x23) == 0x20000bu)
    self[0x18] = src[0x18];
  ext_45d5b0(self, src);
}
PCREG(44c500, z2dObjCopyData);

// 0x44c160 ZSNDOBJ::ModifyGeomCon(int, int), thiscall, ret 8.
static void THISCALL sndObjModifyGeomCon(u8 *self, u32 a, u32 b) {
  (void)a;
  (void)b;
  ext_4dc630(*(void **)(self + 8), 0u, 0x38003u);
}
PCREG(44c160, sndObjModifyGeomCon);

// 0x448f40 ZLIGHT::Disable(), thiscall, plain ret.
static void THISCALL lightDisable(u8 *self) {
  ext_4dc630(*(void **)(self + 8), 0x2000u, 0u);
  *(u32 *)(self + 0x18) |= 9u;
}
PCREG(448f40, lightDisable);
