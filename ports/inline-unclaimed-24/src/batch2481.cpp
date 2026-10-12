// batch2481.cpp - decomp area 24, batch 2481: two save functions (base save, then two slots when AL is set).
#include "ff.h"

extern "C" u8 THISCALL ext_45f960(void *self, void *sg);  // ZGEOM::Save(ZSaveGame*), AL

// 0x4545a0 ZGATE::Save(ZSaveGame*), thiscall, ret 4, AL.
static u8 THISCALL gateSave(u8 *self, void *sg) {
  u8 r = ext_45f960(self, sg);
  if (!r)
    return r;
  vcall<void>(sg, 0x60, (u32)self[0x5a]);
  vcall<void>(sg, 0x3c, *(u32 *)(self + 0x5c));
  return 1;
}
PCREG(4545a0, gateSave);

// 0x44c1e0 ZSNDOBJ::Save(ZSaveGame*), thiscall, ret 4, AL.
static u8 THISCALL sndObjSave(u8 *self, void *sg) {
  u8 r = ext_45f960(self, sg);
  if (!r)
    return r;
  vcall<void>(sg, 0x3c, *(u32 *)(self + 0x1c));
  vcall<void>(sg, 0x60, (u32)self[0x20]);
  return 1;
}
PCREG(44c1e0, sndObjSave);
