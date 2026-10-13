// batch1138.cpp - unclaimed-11 batch 39 (slice 10, full list): five tiny GUESS leaves.
#include "ff.h"

static void THISCALL guessStoreVtable(u8 *self) { *(u32 *)self = 0x6bd594; }
PCREG(612560, guessStoreVtable);

static u32 THISCALL guessConst6bece8(u8 *self) { return 0x6bece8; }
PCREG(626a60, guessConst6bece8);

static u32 THISCALL guessConst4c(u8 *self) { return 0x4c; }
PCREG(63db20, guessConst4c);

static u32 THISCALL guessConstCc(u8 *self) { return 0xcc; }
PCREG(64c760, guessConstCc);

static double THISCALL guessScaledFloat(u8 *self) { return (double)bitsf(*(u32 *)(self + 0xb5)) * (double)G(float, 0x679544); }
PCREG(64fbe0, guessScaledFloat);
