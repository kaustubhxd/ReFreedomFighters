// batch5880.cpp - area 73 batch 58 (gap band, GUESS names): FUN_4f4520, FUN_4f8480, FUN_4fa5e0.
#include "ff.h"

extern "C" void THISCALL ext_4ef1c0(u8 *self);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

// 0x4f4520 (GUESS FUN_4f4520): plain ret. Calls 0x4ef1c0 on this; a non-null pointer at this+0xac is deleted (size 1) and
// cleared.
static void THISCALL guess4f4520(u8 *self) {
  ext_4ef1c0(self);
  void *p = *(void **)(self + 0xac);
  if (p) {
    ext_634273(p, 1u);
    *(u32 *)(self + 0xac) = 0;
  }
}
PCREG(4f4520, guess4f4520);

// 0x4f8480 (GUESS FUN_4f8480): ret 4. The argument is stored at this+0x97; this+0x9b gets 1.0f / (float)(arg - 1).
static void THISCALL guess4f8480(u8 *self, u32 arg) {
  *(u32 *)(self + 0x97) = arg;
  float one = G(float, 0x678858);
  *(float *)(self + 0x9b) = one / (float)(int)(arg - 1);
}
PCREG(4f8480, guess4f8480);

// 0x4fa5e0 (GUESS FUN_4fa5e0): ret 4. When this+0x70 is not 0x20, vtable +0x2ec(2), vtable +0x314(), vtable +0x2ec(8).
static void THISCALL guess4fa5e0(u8 *self, u32 a1) {
  (void)a1;
  if (*(u32 *)(self + 0x70) == 0x20)
    return;
  vcall<void>(self, 0x2ec, 2u);
  vcall<void>(self, 0x314);
  vcall<void>(self, 0x2ec, 8u);
}
PCREG(4fa5e0, guess4fa5e0);
