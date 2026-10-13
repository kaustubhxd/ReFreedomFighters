#include "ff.h"
// batch2760.cpp - unclaimed-27 batch 60 (residue 6). FUN_004f2be0 (GUESS): thiscall, no arguments, plain ret.
// If bytes +0x5fd and +0x5fe are both set: clears dword +0x637, and for k = dword(+0x5ff) - 1 in 0..4 calls vtable slot +0x14
// of the object at [[0x70039c] + 0x1907] (if non-null) with the constant 0x699028 + 0x10 * k.
static void THISCALL funcDispatch5(u8 *self) {
  if (!*(u8 *)(self + 0x5fd) || !*(u8 *)(self + 0x5fe)) return;
  u32 k = *(u32 *)(self + 0x5ff) - 1;
  *(u32 *)(self + 0x637) = 0;
  if (k > 4) return;
  u8 *o = (u8 *)(unsigned long)*(u32 *)(G(u32, 0x70039c) + 0x1907);
  if (!o) return;
  typedef void(THISCALL * F)(u8 *, u32);
  (*(F **)o)[0x14 / 4](o, 0x699028 + 0x10 * k);
}
PCREG(4f2be0, funcDispatch5);
