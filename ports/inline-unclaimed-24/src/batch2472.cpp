// batch2472.cpp - decomp area 24, batch 2472 (local-pointer rows).
#include "ff.h"

extern "C" void THISCALL ext_610100(void *self, void *dblk);             // ZRenderGC::Init(DBLK*), bare ret 4
extern "C" u32 THISCALL ext_4e11e0(void *db, u32 *out, u32 count);       // DBLK::Get(unsigned int*, int)
extern "C" u32 THISCALL ext_4e1b30(void *db);                            // DBLK::NextBlock()
extern "C" void THISCALL ext_45d3a0(void *self);                         // ZGEOM::ClassInit2()
extern "C" u32 THISCALL ext_456b70(void *self, u32 *a, u8 *b);           // ZParticleTemplate::GetController

// 0x4528c0 ZDebugGeom::CopyDataBlock(DBLK*), thiscall, ret 4.
static void THISCALL debugGeomCopyDataBlock(u8 *self, void *db) {
  ext_610100(self, db);
  u32 local = 0;
  ext_4e11e0(db, &local, 1u);
  ext_4e1b30(db);
}
PCREG(4528c0, debugGeomCopyDataBlock);

// 0x455790 ZParticleTemplate::ClassInit2(), thiscall, plain ret.
static void THISCALL particleTemplateClassInit2(u8 *self) {
  ext_45d3a0(self);
  u32 local = 0;
  ext_456b70(self, &local, self + 0xed);
}
PCREG(455790, particleTemplateClassInit2);
