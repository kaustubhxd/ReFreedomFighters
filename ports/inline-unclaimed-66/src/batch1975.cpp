// batch1975.cpp - slice-5 batch 108 (GUESS name). THISCALL(this, a, b, c), ret 0xc.
//   [c] = 0x6b88cc; [b] = 0x0fffffff; t = [[this+0xc]+4]; r = 0x5fb550(ECX = t, a) (THISCALL, one argument, ret 4; GUESS stub by address).
//   If r: [c] = vtable +0x24 of a (no arguments); [b] = vtable +0x28 of a (no arguments).
#include "ff.h"

extern "C" u8 THISCALL ext_5fb550(u8 *self, u32 a);  // THISCALL, one argument, ret 4 (stub by address)

// 0x5f1bd0, GUESS FUN_005f1bd0 (batch 108).
static void THISCALL gapFn5f1bd0(u8 *self, u32 a, u32 b, u32 c) {
  *(u32 *)c = 0x6b88cc;
  *(u32 *)b = 0x0fffffffu;
  u8 *t = *(u8 **)(*(u8 **)(self + 0xc) + 4);
  u8 r = ext_5fb550(t, a);
  if (r) {
    *(u32 *)c = vcall<u32>((u8 *)a, 0x24);
    *(u32 *)b = vcall<u32>((u8 *)a, 0x28);
  }
}
PCREG(5f1bd0, gapFn5f1bd0);
