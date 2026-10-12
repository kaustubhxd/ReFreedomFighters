// batch1956.cpp - unclaimed-66 batch 66 (gap band, GUESS name). THISCALL(this), one unread stack argument, ret 4.
//   Locals: A (9 dwords, at ebp-0x34) and B (3 dwords, at ebp-0x10). obj = [this+0x18].
//   vtable +0x57c of obj with (&A, &B); V = vtable +0x5f0 of obj (no arguments); vtable +0x370 of obj with (&A, V).
//   The stack addresses are the arguments; the spec's stubs log the contents of A and B instead (see the spec).
#include "ff.h"

// 0x5064a0, GUESS FUN_005064a0 (batch 66).
static void THISCALL gapFn5064a0(u8 *self, u32 unused) {
  (void)unused;
  u32 A[9];
  u32 B[3];
  u8 *obj = *(u8 **)(self + 0x18);
  vcall<void>(obj, 0x57c, (u32)A, (u32)B);
  u32 V = vcall<u32>(obj, 0x5f0);
  vcall<void>(obj, 0x370, (u32)A, V);
}
PCREG(5064a0, gapFn5064a0);
