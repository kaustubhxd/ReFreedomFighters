// batch2422.cpp - decomp area 24, batch 2422: ZSoundAmbient::GetValues(DBREAD&) (0x4a4260) and CopyEventDataBlock
// (0x4a3e70, a forwarder to GetValues with the same argument).
// GetValues: two REFTABs (+0x5c, +0x108), float v1 -> +0x1c0, float v2 -> +0x1c4; v1 == 0 (ordered, so not NaN) stores
// 0x38d1b717 in +0x1c0, v2 == 0 likewise in +0x1c4. Then the object at +0x44 gets +0x1b8 = 1.0f, +0x1bc = 0,
// +0x1b4 = -0.7f, +0x1d8 = 0x1000101, byte +0x1dc = 0, and four lookups through its slot 0x104 with the exe strings
// 0x68fc78, 0x68fc84, 0x68fc9c, 0x68fcb0 into +0x48, +0x4c, +0x50, +0x54. Returns AL = 1.
#include "ff.h"

extern "C" u32 THISCALL ext_4e6330(void *db, void *reftab);  // DBREAD::GetRefTab(REFTAB*)
extern "C" float THISCALL ext_4e5e80(void *db);              // DBREAD::operator float() (st0)
extern "C" u8 THISCALL ext_4a4260(void *self, void *db);     // GetValues (exe), for the forwarder

// 0x4a4260
static u8 THISCALL soundAmbientGetValues(u8 *self, void *db) {
  ext_4e6330(db, self + 0x5c);
  ext_4e6330(db, self + 0x108);
  *(float *)(self + 0x1c0) = ext_4e5e80(db);
  float v2 = ext_4e5e80(db);
  float v1 = *(float *)(self + 0x1c0);
  *(float *)(self + 0x1c4) = v2;
  if (v1 == 0.0f)
    *(u32 *)(self + 0x1c0) = 0x38d1b717u;
  if (v2 == 0.0f)
    *(u32 *)(self + 0x1c4) = 0x38d1b717u;
  *(u32 *)(self + 0x1b8) = 0x3f800000u;
  *(u32 *)(self + 0x1bc) = 0;
  *(u32 *)(self + 0x1b4) = 0xbf333333u;
  *(u32 *)(self + 0x1d8) = 0x1000101u;
  self[0x1dc] = 0;
  *(u32 *)(self + 0x48) = vcall<u32>(*(void **)(self + 0x44), 0x104, 0x68fc78u);
  *(u32 *)(self + 0x4c) = vcall<u32>(*(void **)(self + 0x44), 0x104, 0x68fc84u);
  *(u32 *)(self + 0x50) = vcall<u32>(*(void **)(self + 0x44), 0x104, 0x68fc9cu);
  *(u32 *)(self + 0x54) = vcall<u32>(*(void **)(self + 0x44), 0x104, 0x68fcb0u);
  return 1;
}
PCREG(4a4260, soundAmbientGetValues);

// 0x4a3e70 ZSoundAmbient::CopyEventDataBlock(DBREAD&), thiscall, forwards to GetValues.
static u8 THISCALL soundAmbientCopyEventDataBlock(u8 *self, void *db) {
  return ext_4a4260(self, db);
}
PCREG(4a3e70, soundAmbientCopyEventDataBlock);
