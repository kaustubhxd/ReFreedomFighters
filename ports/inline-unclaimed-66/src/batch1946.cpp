// batch1946.cpp - unclaimed-66 batch 47 (gap band, GUESS name). THISCALL(this), one stack argument x, ret 4.
//   a = vtable +0x4c of the ZSysInterface child [sys+0x9b] with the argument [this+0xc]; p = 0x5003d0(ECX = [x+8], index 0);
//   then 0x5002f0(ECX = p, argument a). 0x5003d0 and 0x5002f0 are other areas' helpers, hooked by address in the spec.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);         // ret 4 (one argument), hooked in the spec

// 0x501830, GUESS FUN_00501830 (batch 47).
static void THISCALL gapFn501830(u8 *self, u32 x) {
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u32 a = vcall<u32>(child, 0x4c, *(u32 *)(self + 0xc));
  u8 *p = ext_5003d0(*(u8 **)((u8 *)x + 8), 0);
  ext_5002f0(p, a);
}
PCREG(501830, gapFn501830);
