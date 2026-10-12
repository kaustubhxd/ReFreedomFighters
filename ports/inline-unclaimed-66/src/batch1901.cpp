// batch1901.cpp - unclaimed-66 batch 1 (residue 5): ZFFSearchLightGroup::CopyEventDataBlock(DBREAD&) (vtable).
// Thiscall, one stack argument (the DBREAD reference), ret 4. Original: float from DBREAD -> this+0x71, dword -> this+0x4c,
// float -> this+0x6d. The readers are the DBREAD operators 0x4e5e80 (float) and 0x4e5e60 (dword); they are STUBBED in the spec
// (see docs/20-unclaimed-66.md), so their real bodies are not covered by this batch.
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(void *);
extern "C" u32 THISCALL ext_4e5e60(void *);

// 0x5c6610, ZFFSearchLightGroup::CopyEventDataBlock(DBREAD&) (vtable).
static void THISCALL searchLightGroupCopyEventDataBlock(u8 *self, void *dbread) {
  *(float *)(self + 0x71) = ext_4e5e80(dbread);
  *(u32 *)(self + 0x4c) = ext_4e5e60(dbread);
  *(float *)(self + 0x6d) = ext_4e5e80(dbread);
}
PCREG(5c6610, searchLightGroupCopyEventDataBlock);
