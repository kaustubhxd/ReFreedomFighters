// batch2411.cpp - decomp area 24, batch 2411: ZDamageBox2::CopyEventDataBlock(DBREAD&) (0x5db9f0), thiscall, ret 4.
// GetRefTab(+0x48 pointer) first, then u32 -> +0x4c, float -> +0x50, bool -> +0x54, u16 -> +0x55, float -> +0x87,
// float -> +0x93, float -> +0x97.
#include "ff.h"

extern "C" void THISCALL ext_4e6330(void *db, void *reftab);  // DBREAD::GetRefTab(REFTAB*)
extern "C" u32 THISCALL ext_4e5e60(void *db);                 // DBREAD::operator unsigned int()
extern "C" float THISCALL ext_4e5e80(void *db);               // DBREAD::operator float() (st0)
extern "C" u8 THISCALL ext_4e5ef0(void *db);                  // DBREAD::operator bool()
extern "C" u16 THISCALL ext_4e5e40(void *db);                 // DBREAD::operator unsigned short()

// 0x5db9f0
static void THISCALL damageBox2CopyEventDataBlock(u8 *self, void *db) {
  ext_4e6330(db, *(void **)(self + 0x48));
  *(u32 *)(self + 0x4c) = ext_4e5e60(db);
  *(float *)(self + 0x50) = ext_4e5e80(db);
  self[0x54] = ext_4e5ef0(db);
  *(u16 *)(self + 0x55) = ext_4e5e40(db);
  *(float *)(self + 0x87) = ext_4e5e80(db);
  *(float *)(self + 0x93) = ext_4e5e80(db);
  *(float *)(self + 0x97) = ext_4e5e80(db);
}
PCREG(5db9f0, damageBox2CopyEventDataBlock);
