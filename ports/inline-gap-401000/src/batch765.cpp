// batch765.cpp - gap band batch 765 (docs/20-gap-band-401000.md): 0x405ee0, cdecl (a, idx, c).
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_410bf0(u32 c, u32 v2, u32 v1);   // cdecl, three arguments (exe code)

static u32 __attribute__((cdecl)) fn405ee0(u8 *a, u32 idx, u32 c) {
  u32 *A1 = *(u32 **)(*(u8 **)(a + 8) + 8);
  u32 *A2 = *(u32 **)(a + 0x10);
  const u32 v1 = A1[idx];
  const u32 v2 = A2[idx];
  ext_410bf0(c, v2, v1);
  u32 *A1b = *(u32 **)(*(u8 **)(a + 8) + 8);
  return A1b[idx];
}

PCREG(405ee0, fn405ee0);
