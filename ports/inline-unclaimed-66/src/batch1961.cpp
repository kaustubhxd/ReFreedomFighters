// batch1961.cpp - unclaimed-66 batch 75 (gap band, GUESS name). THISCALL(this), one stack argument x, ret 4.
//   If byte [this+4] <= 1: [this] = *(u32 *)x; byte [this+4] = 1.
//   Else: obj = vtable +0x20 of the logger at [0x700390] with (0x69c8e0, 0xc4) (two arguments; a GUESS stub in the spec); then the caller-
//   cleaned call of [vt+0x2c] with ECX = vt = [obj] and the arguments (obj, 0x69c6b0, 0x69c938); then if [0x7003b0] is set, call it (no
//   arguments).
#include "vcall_cc.h"

// 0x50d7b0, GUESS FUN_0050d7b0 (batch 75).
static void THISCALL gapStore50d7b0(u8 *self, u32 x) {
  if (*(u8 *)(self + 4) <= 1) {
    *(u32 *)self = *(u32 *)x;
    *(u8 *)(self + 4) = 1;
    return;
  }
  u8 *logger = *(u8 **)0x700390;
  u32 obj = vcall<u32>(logger, 0x20, (u32)0x69c8e0, (u32)0xc4);
  u32 vt = *(u32 *)obj;
  call_cc3(vt, 0x2c, obj, (u32)0x69c6b0, (u32)0x69c938);
  void (*fn)(void) = *(void (**)(void))0x7003b0;
  if (fn) fn();
}
PCREG(50d7b0, gapStore50d7b0);
