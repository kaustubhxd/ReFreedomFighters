#include "ff.h"
// batch2751.cpp - unclaimed-27 batch 51 (residue 6). Simple add, 13 bytes.
// FUN_005f2c20: GUESS name. Thiscall, takes argument, adds to member at +8, returns 4.

static void THISCALL funcAddToMember8(u8 *this_obj, u32 arg1) {
  *(u32 *)(unsigned long)(this_obj + 8) += arg1;
}

PCREG(5f2c20, funcAddToMember8);
