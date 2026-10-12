// batch1945.cpp - unclaimed-66 batch 46 (gap band, GUESS name). THISCALL(this), one stack argument x, ret 4.
//   p1 = 0x5003d0(ECX = [x+4], index 0). v = vtable +0x30 of [[this+0xc]+0x18] with the one argument *p1. p2 = 0x5003d0(ECX = [x+8], index 0).
//   Then 0x5002f0(ECX = p2, argument v). 0x5003d0 and 0x5002f0 are other areas' helpers, hooked by address in the spec.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);         // ret 4 (one argument), hooked in the spec

// 0x509870, GUESS FUN_00509870 (batch 46).
static void THISCALL gapFn509870(u8 *self, u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 0);
  u8 *c = *(u8 **)(self + 0xc);
  u32 v = vcall<u32>(*(u8 **)(c + 0x18), 0x30, *(u32 *)p1);
  u8 *p2 = ext_5003d0(*(u8 **)(xo + 8), 0);
  ext_5002f0(p2, v);
}
PCREG(509870, gapFn509870);
