#include "ff.h"
// batch974.cpp - unclaimed-80 residue-19 (docs/20-unclaimed-80.md), batch 52.
// 0x659b30 (stdcall, one argument a, ret 4): o = [a+0x14]; [0x812434] = o; if o != 0: o.vt[0](1) (thiscall, one argument, callee-cleaned);
// then [a+0x14] = 0.
// 0x4f4bf0 (thiscall, one stack argument a, ret 4): 0x4f9c60(self, a) (claimed elsewhere, hooked by address in the spec); then copy the
// dwords at a+0x8f and a+0x93 to self+0x8f and self+0x93.

typedef u32(THISCALL *tc1)(u8 *, u32);
extern "C" void THISCALL ext_4f9c60(u8 *self, u32 a);

static void STDCALL zg659b30(u8 *a) {
  u8 *o = *(u8 **)(a + 0x14);
  *(u32 *)0x812434 = (u32)o;
  if (o != 0) ((tc1)(*(u32 *)(*(u32 *)o + 0)))(o, 1);
  *(u32 *)(a + 0x14) = 0;
}
PCREG(659b30, zg659b30);

static void THISCALL zg4f4bf0(u8 *self, u32 a) {
  u8 *p = (u8 *)a;
  ext_4f9c60(self, a);
  *(u32 *)(self + 0x8f) = *(u32 *)(p + 0x8f);
  *(u32 *)(self + 0x93) = *(u32 *)(p + 0x93);
}
PCREG(4f4bf0, zg4f4bf0);
