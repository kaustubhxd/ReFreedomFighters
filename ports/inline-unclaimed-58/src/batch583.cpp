// batch583.cpp - unclaimed area 58 (docs/20-unclaimed-58.md), slice floor(addr/16) mod 20 == 17.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);   // original, thiscall, one stack word (the caller pushes 0)

typedef u32(THISCALL *Vt2e8)(u8 *, u32);

// 0x55c7d0, thiscall(a): r = 5003d0(ecx = [a+4], 0); v = [r] (dword); [[[this+0x1c]+0x54] + 8] = v. Name GUESS.
static void THISCALL storeIntoInner_55c7d0(u8 *self, u8 *a) {
  u8 *r = ext_5003d0(*(u8 **)(a + 4), 0);
  u32 v = *(u32 *)r;
  u8 *inner = *(u8 **)(*(u8 **)(self + 0x1c) + 0x54);
  *(u32 *)(inner + 8) = v;
}
PCREG(55c7d0, storeIntoInner_55c7d0);

// 0x5144d0, thiscall(): if [this+0x1d9] == 0, [this+0x1d9] = this->vtable[0x2e8](this, [this+0x1d5]); return [this+0x1d9].
// Name GUESS (cache a value from a vtable call).
static u32 THISCALL cachedVtCall_5144d0(u8 *self) {
  if (*(u32 *)(self + 0x1d9) == 0) {
    Vt2e8 fn = (Vt2e8)(*(u32 *)(*(u32 *)self + 0x2e8));
    *(u32 *)(self + 0x1d9) = fn(self, *(u32 *)(self + 0x1d5));
  }
  return *(u32 *)(self + 0x1d9);
}
PCREG(5144d0, cachedVtCall_5144d0);
