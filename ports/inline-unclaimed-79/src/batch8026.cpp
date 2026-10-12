#include "ff.h"
// batch8026.cpp - unclaimed core row (docs/20-unclaimed-79.md). Name GUESS (ContactMove). Helpers stubbed in the spec.

extern "C" void FASTCALL ext_43e920(u8 *c, u8 *d, u32 a);
extern "C" void FASTCALL ext_441a60(u8 *c, u32 a);
extern "C" void FASTCALL ext_4de4b0(u8 *c, u8 *d, u32 a);
extern "C" void FASTCALL ext_4419f0(u8 *c, u32 a);
extern "C" void FASTCALL ext_441940(u8 *c, u32 a);
extern "C" void FASTCALL ext_4de480(u8 *c, u32 a);
extern "C" void FASTCALL ext_4de420(u8 *c, u8 *d);

// 0x4825c0 (GUESS): thiscall (ret 0x10), arguments A, B, V, C.
static void THISCALL f_4825c0(u8 *self, u32 A, u32 B, u32 V, u32 C) {
  u8 l8c[0x40];
  u8 l58[0x30];
  u8 l34[0x30];
  u8 l10[0x10];
  u8 l7c[0x30];
  vcall<void, u32, u32>(self, 0x59c, (u32)(unsigned long)l34, (u32)(unsigned long)l10);
  ext_43e920(l8c, l10, B);
  ext_441a60(l8c, A);
  ext_4de4b0(l58, l34, A);
  ext_4419f0(l8c, V);
  ext_441940(l8c, C);
  ext_4de480(l58, V);
  ext_4de420(l7c, l34);
  void (*cb)() = (void (*)())(unsigned long)G(u32, 0x7003b0);
  if (cb != 0) cb();
}
PCREG(4825c0, f_4825c0);
