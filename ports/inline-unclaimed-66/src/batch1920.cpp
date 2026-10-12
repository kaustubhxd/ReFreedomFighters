// batch1920.cpp - unclaimed-66 batch 20: GUESS FUN_00438e10. Thiscall, one stack argument, ret 4. Original: r = vtable +0x10 of
// this called with the argument; then vtable +0x24 of this called with r (the callees pop their arguments).
#include "ff.h"

// 0x438e10, GUESS FUN_00438e10.
static void THISCALL twoVtableCallsChained(u8 *self, u32 arg) {
  u32 r = vcall<u32>(self, 0x10, arg);
  vcall<void>(self, 0x24, r);
}
PCREG(438e10, twoVtableCallsChained);
