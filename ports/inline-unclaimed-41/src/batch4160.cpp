// batch4160.cpp - unclaimed-41 batch 50 (residue 0 of the relevant list): 0x469100 (this+4 = (arg2 & this+4) | arg1); thiscall.
#include "ff.h"

static void THISCALL fn469100(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 4) = (a2 & *(u32 *)(self + 4)) | a1;
}
PCREG(469100, fn469100);
