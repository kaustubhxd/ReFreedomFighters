// batch2459.cpp - decomp area 24, batch 2459 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_43f900(void *self, void *dblk);      // ZGROUP::CopyDataBlock(DBLK*), ret 4
extern "C" u32 THISCALL ext_4e12e0(void *db, u32 *out, u32 count); // DBLK::Get(unsigned int*, int)
extern "C" u32 THISCALL ext_4e1b30(void *db);                      // DBLK::NextBlock()

// 0x4548e0 ZInstance::CopyDataBlock(DBLK*), thiscall, ret 4.
static void THISCALL instanceCopyDataBlock(u8 *self, void *db) {
  ext_43f900(self, db);
  ext_4e12e0(db, (u32 *)(self + 0x5c), 1u);
  ext_4e1b30(db);
}
PCREG(4548e0, instanceCopyDataBlock);
