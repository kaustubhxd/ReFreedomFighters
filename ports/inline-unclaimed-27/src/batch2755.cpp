#include "ff.h"
// batch2755.cpp - unclaimed-27 batch 55 (residue 6). Byte setter, 16 bytes.
// FUN_0047bfe0: GUESS name. Thiscall, 1 argument, sets byte at +0x6be, returns void.

static void THISCALL funcSetByte6be(u8 *this_obj, u8 arg1) {
  *(u8 *)(unsigned long)(this_obj + 0x6be) = arg1;
}

PCREG(47bfe0, funcSetByte6be);
