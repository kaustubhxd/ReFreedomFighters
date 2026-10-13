// batch1965.cpp - unclaimed-66 batch 83 (gap band, GUESS name). THISCALL(this), one stack argument x, ret 4; eax returned.
//   c = [[this+0x20]+0xc]; if [c+0x23] != 0x100bc0 and [0x7003b0] is set: call it (no arguments).
//   p = 0x5003d0(ECX = [x+4], 0) (a GUESS stub by address); flag = (*p != 0); then the tail jump into vtable +0x398 of [this+0x20] with the
//   flag as its one argument (the port returns its eax).
#include "vcall_cc.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec

// 0x51fcc0, GUESS FUN_0051fcc0 (batch 83).
static u32 THISCALL gapFn51fcc0(u8 *self, u32 x) {
  u8 *a = *(u8 **)(self + 0x20);
  u8 *c = *(u8 **)(a + 0xc);
  if (*(u32 *)(c + 0x23) != 0x100bc0) {
    void (*fn)(void) = *(void (**)(void))0x7003b0;
    if (fn) fn();
  }
  u8 *p = ext_5003d0(*(u8 **)((u8 *)x + 4), 0);
  u32 flag = *(u32 *)p != 0;
  u8 *obj = *(u8 **)(self + 0x20);
  return vcall<u32>(obj, 0x398, flag);
}
PCREG(51fcc0, gapFn51fcc0);
