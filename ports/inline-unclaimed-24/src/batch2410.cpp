// batch2410.cpp - decomp area 24, batch 2410: CCivilianPath::CopyEventDataBlock(DBREAD&) (0x5bdc70), thiscall, ret 4.
// Reads in order: u32 -> +0x59, u32 -> +0x48, float -> +0x54, u32 -> +0x4c, u32 -> +0x50, bool -> +0x58.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(void *db);    // DBREAD::operator unsigned int()
extern "C" float THISCALL ext_4e5e80(void *db);  // DBREAD::operator float() (st0)
extern "C" u8 THISCALL ext_4e5ef0(void *db);     // DBREAD::operator bool()

// 0x5bdc70
static void THISCALL civilianPathCopy(u8 *self, void *db) {
  *(u32 *)(self + 0x59) = ext_4e5e60(db);
  *(u32 *)(self + 0x48) = ext_4e5e60(db);
  *(float *)(self + 0x54) = ext_4e5e80(db);
  *(u32 *)(self + 0x4c) = ext_4e5e60(db);
  *(u32 *)(self + 0x50) = ext_4e5e60(db);
  self[0x58] = ext_4e5ef0(db);
}
PCREG(5bdc70, civilianPathCopy);
