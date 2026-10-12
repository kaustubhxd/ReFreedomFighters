// batch1948.cpp - unclaimed-66 batch 49 (gap band, GUESS name). THISCALL(this), one stack argument x, ret 4.
//   p1 = 0x5003d0(ECX = [x+4], index 1); p2 = 0x5003d0(ECX = [x+4], index 0) (another area's helper, hooked by address in the spec);
//   then vtable +0x2dc of [this+0x14] with the two arguments *p2 and *p1 (in that stack order).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec

// 0x519bb0, GUESS FUN_00519bb0 (batch 49).
static void THISCALL gapFn519bb0(u8 *self, u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 1);
  u8 *p2 = ext_5003d0(*(u8 **)(xo + 4), 0);
  vcall<void>(*(u8 **)(self + 0x14), 0x2dc, *(u32 *)p2, *(u32 *)p1);
}
PCREG(519bb0, gapFn519bb0);
