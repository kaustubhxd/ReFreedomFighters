// batch790.cpp - gap band batch 790 (docs/20-gap-band-401000.md): 0x41f4a0, stdcall (a), returns a bool.
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

static u8 __attribute__((stdcall)) fn41f4a0(u32 a) {
  u8 *obj = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  if (obj != nullptr) {
    const u32 e = *(const u32 *)(obj + 0x1c5d);
    if (a >= e && e != 0) {
      const u32 size = *(const u32 *)(e - 8) & 0x1fffffff;
      if (a < e + size) {
        void (*cb)(void) = (void (*)(void))G(u32, 0x7003b0);
        if (cb != nullptr) cb();
      }
    }
  }
  const u32 r = vc1(G(u8 *, 0x70038c), 0x20, a);   // the exe pushes a before the call (the callee pops it)
  if (r == 0) return *(const u32 *)(a - 0xc) != 1;
  return 0;
}

PCREG(41f4a0, fn41f4a0);
