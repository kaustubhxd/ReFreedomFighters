// batch2606.cpp - wider batch 2606. 0x4d50d0 (GUESS), thiscall(p), ret 4. If p == this+4: when the pointer at this+4 is non-null it is released
// with 0x634273(ptr, 1) (cdecl) and this+8 / this+0xc are cleared; returns 0. Otherwise the hook at 0x7003b0 is called (int3 when null) and -1 is returned.
#include "ff.h"

extern "C" void ext_634273(u8 *ptr, u32 size);
typedef void (*hook_t)();

static u32 THISCALL gapFn4d50d0(u8 *self, void *p) {
  u8 *q = self + 4;
  if (p == q) {
    u8 *ptr = *(u8 **)q;
    if (ptr) {
      ext_634273(ptr, 1);
      *(u32 *)(q + 4) = 0;
      *(u32 *)(q + 8) = 0;
    }
    return 0;
  }
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return (u32)-1;
}
PCREG(4d50d0, gapFn4d50d0);
