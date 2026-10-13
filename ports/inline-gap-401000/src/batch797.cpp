// batch797.cpp - gap band batch 797 (docs/20-gap-band-401000.md): 0x41f320, thiscall (this, a), void.
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

extern "C" void THISCALL ext_41f190(u8 *self, u32 a);   // thiscall, one argument (callee pops 4; exe code)

static void THISCALL fn41f320(u8 *self, u32 a) {
  if (vc1(G(u8 *, 0x70038c), 0x20, a) != 0) return;
  bool in = false;
  u8 *obj = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  if (obj != nullptr) {
    const u32 e = *(const u32 *)(obj + 0x1c5d);
    if (a >= e && e != 0) {
      const u32 size = *(const u32 *)(e - 8) & 0x1fffffff;
      if (a < e + size) in = true;
    }
  }
  if (in) {
    void (*cb)(void) = (void (*)(void))G(u32, 0x7003b0);
    if (cb == nullptr) __builtin_trap();   // the exe executes int3 here
    cb();
  }
  *(u32 *)(a - 0xc) += 1;
  ext_41f190(self, a);
}

PCREG(41f320, fn41f320);
