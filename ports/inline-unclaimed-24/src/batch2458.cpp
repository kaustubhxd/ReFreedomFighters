// batch2458.cpp - decomp area 24, batch 2458 (gap band).
#include "ff.h"

extern "C" u8 THISCALL ext_45f3c0(void *self, void *ld);    // ZGEOM::Load(ZLoadGame*), AL
extern "C" void THISCALL ext_455dd0(void *self);            // ZParticleTemplate::CreateColorTable()
extern "C" void THISCALL ext_45d5b0(void *self, const void *src);  // ZGEOM::CopyData(const ZGEOM*), ret 4

// 0x456e30 ZParticleTemplate::Load(ZLoadGame*), thiscall, ret 4, AL = 1.
static u8 THISCALL particleTemplateLoad(u8 *self, void *ld) {
  ext_45f3c0(self, ld);
  vcall<void>(ld, 0x40, self + 0xed);
  ext_455dd0(self);
  return 1;
}
PCREG(456e30, particleTemplateLoad);

// 0x448830 ZSPOTLIGHT::CopyData(const ZGEOM*), thiscall, ret 4.
static void THISCALL spotLightCopyData(u8 *self, const u8 *src) {
  *(u32 *)(self + 0x18) = *(const u32 *)(src + 0x18);
  ext_45d5b0(self, src);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(sys + 0x9b);
  if (tab[0xbad] != 0)
    *(u32 *)(self + 0x14) |= 1u;
  vcall<void>(self, 0x1e0, 0x800023u);
}
PCREG(448830, spotLightCopyData);

// 0x448880 ZSPOTLIGHTSQUARE::CopyData(const ZGEOM*), thiscall, ret 4.
static void THISCALL spotLightSquareCopyData(u8 *self, const u8 *src) {
  *(u32 *)(self + 0x18) = *(const u32 *)(src + 0x18);
  ext_45d5b0(self, src);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(sys + 0x9b);
  if (tab[0xbad] != 0)
    *(u32 *)(self + 0x14) |= 1u;
  vcall<void>(self, 0x1e0, 0x800020u);
}
PCREG(448880, spotLightSquareCopyData);
