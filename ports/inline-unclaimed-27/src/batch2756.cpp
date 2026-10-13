#include "ff.h"
// batch2756.cpp - unclaimed-27 batch 56 (residue 6). Byte setter, 16 bytes.
// FUN_004bcc20: GUESS name. Thiscall, 1 argument, sets byte at +0xd0, returns void.

static void THISCALL funcSetByteD0(u8 *this_obj, u8 arg1) {
  *(u8 *)(unsigned long)(this_obj + 0xd0) = arg1;
}

PCREG(4bcc20, funcSetByteD0);
