// batch800.cpp - gap band batch 800 (docs/20-gap-band-401000.md): 0x41f6a0, thiscall (this, xp), void.
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

extern "C" void __attribute__((cdecl)) ext_634d22(u32 dst, u32 src, u32 n);   // CRT memcpy (exe code)

static void THISCALL fn41f6a0(u8 *self, u32 *xp) {
  const u32 mask = 0x1fffffff;
  u8 *obj = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  const u32 x = *xp;
  const u32 e = *(const u32 *)(obj + 0x1c5d);
  if (x >= e && e != 0) {
    const u32 size = *(const u32 *)(e - 8) & mask;
    if (x < e + size) {
      void (*cb)(void) = (void (*)(void))G(u32, 0x7003b0);
      if (cb == nullptr) __builtin_trap();   // the exe executes int3 here
      cb();
    }
  }
  if (*(const u32 *)(x - 0xc) != 1) {
    const u32 sz = *(const u32 *)(x - 8) & mask;
    const u32 r = vc1(self, 8, sz);
    ext_634d22(r, x, *(const u32 *)(x - 8) & mask);
    *xp = r;
    *(u32 *)(x - 0xc) -= 1;
  }
}

PCREG(41f6a0, fn41f6a0);
