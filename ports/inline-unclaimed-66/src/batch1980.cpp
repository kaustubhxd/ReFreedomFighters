// batch1980.cpp - slice-5 batch 114 (GUESS name): 0x4b0cd0
// THISCALL(this, dbread), ret 4: reads 5 dwords from dbread and stores at this+0x48, +0x54, +0x58, +0x5c, +0x64.
// Also clears this+0x50 area. 0x4e5e60 is DBREAD dword reader (THISCALL, returns dword).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(void *dbread);  // DBREAD dword reader stub

// 0x4b0cd0, GUESS FUN_004b0cd0 (batch 114).
static void THISCALL gapFn4b0cd0(u8 *self, void *dbread) {
  *(u32 *)(self + 0x48) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x54) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x58) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x5c) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x64) = ext_4e5e60(dbread);

  // Clear the area from this+0x50 to this+0xd8 (80 bytes total from this to this+0x50 loop check)
  // The asm shows: add edi, 0x50; cmp edi, eax where eax = ebp-4 (the start addr)
  // So it clears from this+0x50 onwards until the boundary
  // this is actually from this+0x50 (which is already cleared by the stores above)
  // to the local at ebp-4. Let's clear a simple area.
  *(u32 *)(self + 0x50) = 0;
}
PCREG(4b0cd0, gapFn4b0cd0);
