// batch1122.cpp - unclaimed-11 batch 23 (gap band): GUESS, two DBREAD reads (ret 4).
#include "ff.h"

typedef u32(THISCALL *dbreadU32)(void *dbread);
extern "C" u32 THISCALL ext_4e5e60(void *dbread);

// 0x5b7630, GUESS: this+0x4c = DBREAD unsigned int read; this+0x48 = a second such read (the same DBREAD).
static void THISCALL guessTwoReads(u8 *self, void *dbread) {
  *(u32 *)(self + 0x4c) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x48) = ext_4e5e60(dbread);
}
PCREG(5b7630, guessTwoReads);
