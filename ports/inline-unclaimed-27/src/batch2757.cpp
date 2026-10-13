#include "ff.h"
// batch2757.cpp - unclaimed-27 batch 57 (residue 6). Word setter, 17 bytes.
// FUN_0047bd60: GUESS name. Thiscall, 1 argument, zero-extends byte to dword at +0x496, returns void.

static void THISCALL funcSetWord496(u8 *this_obj, u8 arg1) {
  *(u32 *)(unsigned long)(this_obj + 0x496) = (u32)arg1;
}

PCREG(47bd60, funcSetWord496);
