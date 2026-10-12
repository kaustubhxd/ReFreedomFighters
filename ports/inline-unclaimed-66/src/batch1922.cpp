// batch1922.cpp - unclaimed-66 batch 22: GUESS FUN_00656d50. Thiscall, two stack arguments, ret 8. Original: r = vtable +0xc of this
// with a1; then vtable +0xa4 of this with (r, a2). The callees pop their arguments.
#include "ff.h"

// 0x656d50, GUESS FUN_00656d50.
static void THISCALL chainedVtableWithTwoArgs(u8 *self, u32 a1, u32 a2) {
  u32 r = vcall<u32>(self, 0xc, a1);
  vcall<void>(self, 0xa4, r, a2);
}
PCREG(656d50, chainedVtableWithTwoArgs);
