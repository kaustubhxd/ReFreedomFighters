// batch1944.cpp - unclaimed-66 batch 45 (gap band, GUESS name). THISCALL(this), one stack argument x, ret 4.
//   a = 0; if [this+0xc] is set, a = vtable +0x14 of [[this+0xc]+0x18] (no arguments). p = 0x5003d0(holder = [x+8], index 0) (ECX = holder;
//   a helper from another area, hooked by address in the spec). Then 0x5002f0(ECX = p, argument a) (also hooked by address).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);         // ret 4 (one argument), hooked in the spec

// 0x509840, GUESS FUN_00509840 (batch 45).
static void THISCALL gapFn509840(u8 *self, u32 x) {
  u32 a = 0;
  u8 *c = *(u8 **)(self + 0xc);
  if (c) a = vcall<u32>(*(u8 **)(c + 0x18), 0x14);
  u8 *p = ext_5003d0(*(u8 **)((u8 *)x + 8), 0);
  ext_5002f0(p, a);
}
PCREG(509840, gapFn509840);
