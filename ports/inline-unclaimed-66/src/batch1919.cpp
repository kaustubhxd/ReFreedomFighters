// batch1919.cpp - unclaimed-66 batch 19: GUESS FUN_004a35d0. Thiscall, two stack arguments (the first is unused), ret 8.
// Original: this+0x50 = DBREAD dword (0x4e5e60, stubbed in the spec), this+0x54 = -1, byte this+0x58 = 0.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(void *);

// 0x4a35d0, GUESS FUN_004a35d0.
static void THISCALL readIndexFromDbread(u8 *self, u32 unused, void *dbread) {
  (void)unused;
  *(u32 *)(self + 0x50) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x54) = 0xffffffff;
  self[0x58] = 0;
}
PCREG(4a35d0, readIndexFromDbread);
