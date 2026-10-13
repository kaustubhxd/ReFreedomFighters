// batch1966.cpp - unclaimed-66 batch 84 (gap band, GUESS name). STDCALL, one argument x, ret 4.
//   p0 = 0x5003d0(ECX = [x+4], 0); v = vtable +0x60 of the ZSysInterface child with *p0; if v: p1 = 0x5003d0(ECX = [x+4], 1);
//   0x44b8b0(ECX = v, *p1) (THISCALL, one argument, ret 4; a GUESS stub by address). Both 0x5003d0 calls are GUESS stubs by address.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec
extern "C" void THISCALL ext_44b8b0(u8 *self, u32 a);         // THISCALL, one argument, ret 4 (hooked in the spec)

// 0x511330, GUESS FUN_00511330 (batch 84).
static void STDCALL gapFn511330(u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u8 *v = (u8 *)vcall<u32>(child, 0x60, *(u32 *)p0);
  if (v) {
    u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 1);
    ext_44b8b0(v, *(u32 *)p1);
  }
}
PCREG(511330, gapFn511330);
