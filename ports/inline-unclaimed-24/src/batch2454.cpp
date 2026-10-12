// batch2454.cpp - decomp area 24, batch 2454 (gap band).
#include "ff.h"

extern "C" u8 THISCALL ext_45f3c0(void *self, void *ld);    // ZGEOM::Load(ZLoadGame*), returns AL
extern "C" u32 THISCALL ext_440e10(void *self, void *ld);   // ZGROUP::Load(ZLoadGame*)
extern "C" u32 THISCALL ext_448a30(void *self, void *db);   // ZLIGHT::CopyDataBlock(DBLK*)
extern "C" u32 THISCALL ext_4e1b30(void *db);               // DBLK::NextBlock()
extern "C" u32 THISCALL ext_4e0fd0(void *db, void *reftab); // DBLK::Get(REFTAB*)

// 0x459c10 ZBoneParticle::Load(ZLoadGame*), thiscall, ret 4, AL.
static u8 THISCALL boneParticleLoad(u8 *self, void *ld) {
  if (!ext_45f3c0(self, ld))
    return 0;
  vcall<void>(self, 0x154);
  return 1;
}
PCREG(459c10, boneParticleLoad);

// 0x454920 ZInstance::Load(ZLoadGame*), thiscall, ret 4, AL = 1.
static u8 THISCALL instanceLoad(u8 *self, void *ld) {
  ext_440e10(self, ld);
  vcall<void>(ld, 0x40, self + 0x5c);
  return 1;
}
PCREG(454920, instanceLoad);

// 0x448a00 ZGateLightMaster::CopyDataBlock(DBLK*), thiscall, ret 4.
static void THISCALL gateLightMasterCopyDataBlock(u8 *self, void *db) {
  ext_448a30(self, db);
  ext_4e1b30(db);
  ext_4e0fd0(db, *(void **)(self + 0x1c));
  ext_4e1b30(db);
}
PCREG(448a00, gateLightMasterCopyDataBlock);
