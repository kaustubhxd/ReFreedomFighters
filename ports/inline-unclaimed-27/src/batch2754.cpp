#include "ff.h"
// batch2754.cpp - unclaimed-27 batch 54 (residue 6). Dual setter, 19 bytes.
// FUN_004643e0: GUESS name. Thiscall, 2 arguments, sets members at +0x5c and +0x64, returns void.

static void THISCALL funcDualSetter(u8 *this_obj, u32 arg1, u32 arg2) {
  *(u32 *)(unsigned long)(this_obj + 0x5c) = arg1;
  *(u32 *)(unsigned long)(this_obj + 0x64) = arg2;
}

PCREG(4643e0, funcDualSetter);
