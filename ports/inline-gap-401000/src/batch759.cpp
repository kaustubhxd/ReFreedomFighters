// batch759.cpp - gap band batch 759 (docs/20-gap-band-401000.md): 0x401320, cdecl, (a1, out, n), void.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_410de0(u32 a, u32 b);   // cdecl, two arguments (exe code)

static void __attribute__((cdecl)) fn401320(u32 a1, u8 *out, u32 n) {
  for (u32 k = 0; k < n; ++k) {
    const u32 r = ext_410de0(a1, 8);
    out[k] = (u8)r;
  }
}

PCREG(401320, fn401320);
