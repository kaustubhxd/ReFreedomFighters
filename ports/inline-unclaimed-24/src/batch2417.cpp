// batch2417.cpp - decomp area 24, batch 2417: two tail-jump forwarders (the stack arguments are unchanged).
#include "ff.h"

extern "C" u32 THISCALL ext_4487f0(void *self, const void *geom);  // ZLIGHT::CopyData(const ZGEOM*)
extern "C" u32 THISCALL ext_5ed170(void *self, void *sg);          // CSprite2D::Save(ZSaveGame*)

// 0x452bb0 ZENVIRONMENT::CopyData(const ZGEOM*), thiscall, ret 4.
static u32 THISCALL environmentCopyData(u8 *self, const void *geom) {
  return ext_4487f0(self, geom);
}
PCREG(452bb0, environmentCopyData);

// 0x5f0170 CSpriteDivide2D::Save(ZSaveGame*), thiscall, ret 4.
static u32 THISCALL spriteDivide2DSave(u8 *self, void *sg) {
  return ext_5ed170(self, sg);
}
PCREG(5f0170, spriteDivide2DSave);
