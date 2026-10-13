// batch1978.cpp - slice-5 batch 111 (GUESS name): 0x4d50d0
// THISCALL(this, p), ret 4: if p == this+4, free [this+4] via 0x634273(ptr, 1) when non-null,
// clear +8/+0xc, return 0; else call [0x7003b0] (stub_fn) and return -1.
#include "ff.h"

extern "C" void ext_634273(u8 *ptr, u32 size);  // CRT free, hooked by address

// 0x4d50d0, GUESS FUN_004d50d0 (batch 111).
static u32 THISCALL gapFn4d50d0(u8 *self, void *p) {
  u8 *this_plus_4 = self + 4;
  if (p == this_plus_4) {
    u8 *ptr = *(u8 **)this_plus_4;
    if (ptr) {
      ext_634273(ptr, 1);
      // Only clear [this+8] and [this+0xc] if ptr was non-null
      *(u32 *)(this_plus_4 + 4) = 0;  // [this+8] = 0
      *(u32 *)(this_plus_4 + 8) = 0;  // [this+0xc] = 0
    }
    return 0;
  } else {
    // Call [0x7003b0] (function pointer stubbed via stub_fn)
    void (*fn)() = *(void (**)())0x7003b0;
    if (fn) {
      fn();
    }
    return -1;
  }
}
PCREG(4d50d0, gapFn4d50d0);
