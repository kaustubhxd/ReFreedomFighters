// batch1112.cpp - unclaimed-11 batch 13 (slice 10, full list): 0x493fe0, GUESS name (no GC name).
#include "ff.h"

// 0x493fe0, GUESS: returns (the dword at this+0x5d39 is nonzero) as a bool in AL.
static bool THISCALL guessBoolAt5d39(u8 *self) { return *(u32 *)(self + 0x5d39) != 0; }
PCREG(493fe0, guessBoolAt5d39);
