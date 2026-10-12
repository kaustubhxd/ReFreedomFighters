// batch1947.cpp - unclaimed-66 batch 48 (gap band, GUESS name). THISCALL(this), one stack argument x, ret 4.
//   p = 0x5003d0(ECX = [x+4], index 0) (another area's helper, hooked by address in the spec); f = *p * the float at 0x67cd40;
//   then vtable +0x600 of [this+0x18] with the float f as its one argument.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec

// 0x508180, GUESS FUN_00508180 (batch 48).
static void THISCALL gapFn508180(u8 *self, u32 x) {
  u8 *p = ext_5003d0(*(u8 **)((u8 *)x + 4), 0);
  float f = *(float *)p * *(float *)0x67cd40;
  vcall<void>(*(u8 **)(self + 0x18), 0x600, *(u32 *)&f);
}
PCREG(508180, gapFn508180);
