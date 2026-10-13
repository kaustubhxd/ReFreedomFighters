#include "ff.h"
// batch2750.cpp - unclaimed-27 batch 50 (residue 6). Simple setter, 13 bytes.
// FUN_004d7520: GUESS name. Thiscall, takes argument, sets member at +0x1d, returns 4.

static void THISCALL funcSetMember1d(u8 *this_obj, u32 arg1) {
  *(u32 *)(unsigned long)(this_obj + 0x1d) = arg1;
}

PCREG(4d7520, funcSetMember1d);
