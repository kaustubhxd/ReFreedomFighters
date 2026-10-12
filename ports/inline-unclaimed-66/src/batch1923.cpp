// batch1923.cpp - unclaimed-66 batch 23: GUESS FUN_00659b90. Thiscall, one argument, ret 4. Original: vtable +0xe0 of this with the
// argument (callee pops), then 0x63f570 with ECX = this and the same argument (exe code, bound; not verified by this batch).
#include "ff.h"

extern "C" void THISCALL ext_63f570(void *self, u32 arg);

// 0x659b90, GUESS FUN_00659b90.
static void THISCALL vtableThenBoundCall(u8 *self, u32 arg) {
  vcall<void>(self, 0xe0, arg);
  ext_63f570(self, arg);
}
PCREG(659b90, vtableThenBoundCall);
