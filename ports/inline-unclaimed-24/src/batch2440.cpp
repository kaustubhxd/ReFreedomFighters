// batch2440.cpp - decomp area 24, batch 2440 (gap band).
#include "ff.h"

extern "C" u8 THISCALL ext_449550(void *self, void *ld);  // ZLIGHT::Load(ZLoadGame*)
extern "C" u8 THISCALL ext_449600(void *self, void *sg);  // ZLIGHT::Save(ZSaveGame*)

// 0x449790 ZLIGHT::SetEffectLight(bool), thiscall, ret 4: bit 2 of +0x18.
static void THISCALL lightSetEffectLight(u8 *self, u32 on) {
  if ((u8)on)
    *(u32 *)(self + 0x18) |= 2u;
  else
    *(u32 *)(self + 0x18) &= 0xfffffffdu;
}
PCREG(449790, lightSetEffectLight);

// 0x449820 ZLIGHT::SetLightAttributeChanged(bool), thiscall, ret 4: bit 3 of +0x18.
static void THISCALL lightSetAttributeChanged(u8 *self, u32 on) {
  if ((u8)on)
    *(u32 *)(self + 0x18) |= 8u;
  else
    *(u32 *)(self + 0x18) &= 0xfffffff7u;
}
PCREG(449820, lightSetAttributeChanged);

// 0x44c290 ZSNDOBJ::StartPitchShift(float, float, float) (bit patterns), thiscall, ret 12. Only the first is used.
static void THISCALL sndObjStartPitchShift(u8 *self, u32 a) {
  u8 *d = *(u8 **)(self + 0x18);
  *(u32 *)(d + 0x60) = a - *(u32 *)(d + 0x64);
  *(u32 *)(d + 0x64) = a;
}
PCREG(44c290, sndObjStartPitchShift);

// 0x443030 ZTreeGroup::GetDynamicChildTreeGroupList(ZTreeGroup***) const, thiscall, ret 4. The result keeps the high
// half of the list pointer and takes the word at +2.
static u32 THISCALL treeGroupDynamicChildList(u8 *self, u32 *out) {
  *out = 0;
  u32 p = *(u32 *)(self + 0x7b);
  if (p == 0)
    return 0;
  *out = p + 0x404u;
  u32 hi = p & 0xffff0000u;
  asm volatile("" : "+r"(hi));  // keep the high half live (clang dropped it)
  u16 w = *(u16 *)(p + 2);
  return hi | (u32)w;
}
PCREG(443030, treeGroupDynamicChildList);

// 0x452e20 ZENVIRONMENT::Load(ZLoadGame*), thiscall, ret 4, AL = (ZLIGHT::Load result != 0).
static u8 THISCALL environmentLoad(u8 *self, void *ld) {
  return ext_449550(self, ld) != 0;
}
PCREG(452e20, environmentLoad);

// 0x452e40 ZENVIRONMENT::Save(ZSaveGame*), thiscall, ret 4, AL = (ZLIGHT::Save result != 0).
static u8 THISCALL environmentSave(u8 *self, void *sg) {
  return ext_449600(self, sg) != 0;
}
PCREG(452e40, environmentSave);
