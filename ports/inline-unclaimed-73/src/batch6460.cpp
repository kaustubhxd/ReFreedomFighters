// batch6460.cpp - area 73 batch 64 (gap band, GUESS names): FUN_4e8090, FUN_4e66c0, FUN_4f0460, FUN_4f83e0.
#include "ff.h"

extern "C" u32 THISCALL ext_4e8000(u8 *self, u32 a);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);
extern "C" void THISCALL ext_45f070(u8 *self, u32 a);

// 0x4e8090 (GUESS FUN_4e8090): ret 4, returns 0. t = 0x4e8000(this, arg); vtable slot +0x20 on the object at this+0x1d with t.
static u32 THISCALL guess4e8090(u8 *self, u32 arg) {
  u32 t = ext_4e8000(self, arg);
  u8 *obj = *(u8 **)(self + 0x1d);
  vcall<void>(obj, 0x20, t);
  return 0;
}
PCREG(4e8090, guess4e8090);

// 0x4e66c0 (GUESS FUN_4e66c0): ret 4, returns this. Vtable word 0x6974d0; a non-null pointer at this+4 is deleted (size 1);
// when the argument's low bit is set, this is deleted (size 0xc).
static u8 *THISCALL guess4e66c0(u8 *self, u32 flags) {
  *(u32 *)self = 0x6974d0;
  void *p = *(void **)(self + 4);
  if (p)
    ext_634273(p, 1u);
  if (flags & 1)
    ext_634273(self, 0xcu);
  return self;
}
PCREG(4e66c0, guess4e66c0);

// 0x4f0460 (GUESS FUN_4f0460): ret 4. Vtable slot +0x6c on the control object at g_sys+0x9b, then 0x45f070(this, arg), then
// vtable slot +0x68 on the same control object.
static void THISCALL guess4f0460(u8 *self, u32 arg) {
  u8 *ctl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  vcall<void>(ctl, 0x6c);
  ext_45f070(self, arg);
  ctl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  vcall<void>(ctl, 0x68);
}
PCREG(4f0460, guess4f0460);

// 0x4f83e0 (GUESS FUN_4f83e0): ret 8. Stores a2 at this+0x93 and a1 at this+0x8f, calls vtable +0x364 with (a2 - a1 + 1), then
// vtable +0x374 with 0.
static void THISCALL guess4f83e0(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 0x93) = a2;
  *(u32 *)(self + 0x8f) = a1;
  vcall<void>(self, 0x364, a2 - a1 + 1);
  vcall<void>(self, 0x374, 0u);
}
PCREG(4f83e0, guess4f83e0);
