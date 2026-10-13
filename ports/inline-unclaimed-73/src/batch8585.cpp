// batch8585.cpp - residue 6 batch 85 (GUESS names): FUN_0054be20 (thiscall) and FUN_005f51a0 (stdcall).
#include "ff.h"

// 0x54be20 (GUESS FUN_0054be20): s = the pointer at this+0x63ec; when non-null, vtable slot +0x48 is called on s with s.
static void THISCALL guess54be20(u8 *self) {
  u8 *s = *(u8 **)(self + 0x63ec);
  if (s)
    vcall<void>(s, 0x48, (u32)s);
}
PCREG(54be20, guess54be20);

// 0x5f51a0 (GUESS FUN_005f51a0): stdcall, three arguments ignored. Calls the assert hook at 0x7003b0 when it is set; returns 0.
static u32 STDCALL guess5f51a0(u32 a, u32 b, u32 c) {
  (void)a;
  (void)b;
  (void)c;
  void (*hook)() = (void (*)())G(u32, 0x7003b0);
  if (hook)
    hook();
  return 0;
}
PCREG(5f51a0, guess5f51a0);
