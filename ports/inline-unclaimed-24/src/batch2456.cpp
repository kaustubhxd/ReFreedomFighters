// batch2456.cpp - decomp area 24, batch 2456 (gap band).
#include "ff.h"

extern "C" u8 THISCALL ext_45f3c0(void *self, void *ld);      // ZGEOM::Load(ZLoadGame*), returns AL
extern "C" void THISCALL ext_610100(void *self, void *dblk);  // ZRenderGC::Init(DBLK*), bare ret 4
extern "C" u32 THISCALL ext_4e1b30(void *db);                 // DBLK::NextBlock()

// 0x45bfa0 ZProjectMarks::Load(ZLoadGame*), thiscall, ret 4, AL.
static u8 THISCALL projectMarksLoad(u8 *self, void *ld) {
  vcall<void>(self, 0x214);
  return ext_45f3c0(self, ld) != 0;
}
PCREG(45bfa0, projectMarksLoad);

// 0x45b210 ZStdObjBox::CopyDataBlock(DBLK*), thiscall, ret 4.
static void THISCALL stdObjBoxCopyDataBlock(u8 *self, void *db) {
  ext_610100(self, db);
  ext_4e1b30(db);
  vcall<void>(self, 0xb4, 1u);
}
PCREG(45b210, stdObjBoxCopyDataBlock);

