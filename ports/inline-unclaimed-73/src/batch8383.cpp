// batch8383.cpp - residue 6 batch 83 (GUESS name): FUN_004d7520.
#include "ff.h"

// 0x4d7520 (GUESS FUN_004d7520): stores the argument at this+0x1d. Ret 4.
static void THISCALL guess4d7520(u8 *self, u32 a) {
  *(u32 *)(self + 0x1d) = a;
}
PCREG(4d7520, guess4d7520);
