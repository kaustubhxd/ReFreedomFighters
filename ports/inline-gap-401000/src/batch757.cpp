// batch757.cpp - gap band batch 757 (docs/20-gap-band-401000.md): 0x401ef0, cdecl, (a, b), returns 0.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_401970(u8 *a, u32 b, u32 c);   // cdecl, three arguments (exe code)

static u32 __attribute__((cdecl)) fn401ef0(u8 *a, u32 b) {
  ext_401970(a, b, 0);
  const u32 m = 0xffffffff;
  *(u32 *)(a + 0x38) = m;
  *(u32 *)(a + 0x40) = m;
  *(u32 *)(a + 0x18) = m;
  *(u32 *)(a + 0x3c) = m;
  *(u32 *)(a + 0x44) = m;
  return 0;
}

PCREG(401ef0, fn401ef0);
