// batch1952.cpp - unclaimed-66 batch 58 (gap band, GUESS name). THISCALL(this), two arguments a and b, ret 8.
//   0x55edc0(a, b) (STDCALL, two arguments, a GUESS stub by address); then r = vtable +0x4c of the ZSysInterface child with [this+0x20];
//   then vtable +0x3c of the object at [a+0x15] with r as its one argument.
#include "ff.h"

extern "C" void STDCALL ext_55edc0(u32 a, u32 b);  // stdcall, two arguments, ret 8 (hooked in the spec)

// 0x5200d0, GUESS FUN_005200d0 (batch 58).
static void THISCALL gapFn5200d0(u8 *self, u32 a, u32 b) {
  ext_55edc0(a, b);
  u8 *obj = *(u8 **)((u8 *)a + 0x15);
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u32 r = vcall<u32>(child, 0x4c, *(u32 *)(self + 0x20));
  vcall<void>(obj, 0x3c, r);
}
PCREG(5200d0, gapFn5200d0);
