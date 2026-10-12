// batch2463.cpp - decomp area 24, batch 2463 (gap band).
#include "ff.h"

extern "C" u8 THISCALL ext_45f960(void *self, void *sg);  // ZGEOM::Save(ZSaveGame*), AL
extern "C" u8 THISCALL ext_45f3c0(void *self, void *ld);  // ZGEOM::Load(ZLoadGame*), AL

// Save/load pair body: the base result is returned unchanged when it is 0; otherwise one slot gets this+0x18 and AL = 1.
// Save passes the value of +0x18; Load passes the address of +0x18 (the loader writes into it).
static u8 savePair(u8 base, void *obj, u8 *self) {
  if (!base)
    return base;
  vcall<void>(obj, 0x3c, *(u32 *)(self + 0x18));
  return 1;
}
static u8 loadPair(u8 base, void *obj, u8 *self) {
  if (!base)
    return base;
  vcall<void>(obj, 0x40, (void *)(self + 0x18));
  return 1;
}

// 0x449600 ZLIGHT::Save(ZSaveGame*), thiscall, ret 4, AL.
static u8 THISCALL lightSave(u8 *self, void *sg) {
  return savePair(ext_45f960(self, sg), sg, self);
}
PCREG(449600, lightSave);

// 0x449550 ZLIGHT::Load(ZLoadGame*), thiscall, ret 4, AL.
static u8 THISCALL lightLoad(u8 *self, void *ld) {
  return loadPair(ext_45f3c0(self, ld), ld, self);
}
PCREG(449550, lightLoad);

// 0x449630 ZSPOTLIGHT::Save(ZSaveGame*), thiscall, ret 4, AL.
static u8 THISCALL spotLightSave(u8 *self, void *sg) {
  return savePair(ext_45f960(self, sg), sg, self);
}
PCREG(449630, spotLightSave);

// 0x449580 ZSPOTLIGHT::Load(ZLoadGame*), thiscall, ret 4, AL.
static u8 THISCALL spotLightLoad(u8 *self, void *ld) {
  return loadPair(ext_45f3c0(self, ld), ld, self);
}
PCREG(449580, spotLightLoad);
