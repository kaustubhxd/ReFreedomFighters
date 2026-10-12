// batch6400.cpp - unclaimed-68 batch 40 (claim 40, gap band). Name from the GC name map.
#include "ff.h"

// DBREAD dword reader (exe code, thiscall, no stack arguments); the spec hooks it by address.
extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);

// 0x4bb530, ZSoundToggle::CopyEventDataBlock(DBREAD&): thiscall, ret 4. The byte at this+0x50 is set to 1 when the dword read is nonzero.
static void THISCALL soundToggleCopyEventDataBlock(u8 *self, u8 *dbread) {
  self[0x50] = ext_4e5e60(dbread) != 0;
}
PCREG(4bb530, soundToggleCopyEventDataBlock);
