// batch6180.cpp - unclaimed-68 batch 18 (claim 17, gap band). Name from the GC name map (low confidence).
#include "ff.h"

// The DBREAD readers (exe code, thiscall, no stack arguments): 0x4e5e60 reads a dword, 0x4e5e40 a word. The spec hooks them by address.
extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);

// 0x4bb230, ZCharisma::CopyEventDataBlock(DBREAD&) (low): thiscall, ret 4. The dword goes to this+0x48, the low word to this+0x4c.
static void THISCALL charismaCopyEventDataBlock(u8 *self, u8 *dbread) {
  *(u32 *)(self + 0x48) = ext_4e5e60(dbread);
  *(u16 *)(self + 0x4c) = (u16)ext_4e5e40(dbread);
}
PCREG(4bb230, charismaCopyEventDataBlock);
