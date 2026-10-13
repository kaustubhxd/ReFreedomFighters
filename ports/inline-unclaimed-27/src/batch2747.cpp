#include "ff.h"
// batch2747.cpp - unclaimed-27 batch 49 (residue 6). Simple setter, 13 bytes.
// FUN_00491b60: GUESS name. Takes this, sets member +0xbc5 to 0, returns 8.

static void THISCALL funcSimpleSetter(u8 *this_obj, u32 arg1, u32 arg2) {
  *(u32 *)(unsigned long)(this_obj + 0xbc5) = 0;
}

PCREG(491b60, funcSimpleSetter);
