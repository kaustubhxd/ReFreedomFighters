// batch5990.cpp - area 73 batch 59 (gap band, GUESS name): FUN_4f2a00.
#include "ff.h"

// 0x4f2a00 (GUESS FUN_4f2a00): ret 4. The control object at g_sys+0x9b gets vtable slot +0x58 with the argument; the result
// goes to this's vtable slot +0x2fc.
static void THISCALL guess4f2a00(u8 *self, u32 a1) {
  u8 *ctl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32>(ctl, 0x58, a1);
  vcall<void>(self, 0x2fc, r);
}
PCREG(4f2a00, guess4f2a00);
