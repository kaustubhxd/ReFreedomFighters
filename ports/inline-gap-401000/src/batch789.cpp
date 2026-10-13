// batch789.cpp - gap band batch 789 (docs/20-gap-band-401000.md): 0x410280, cdecl (p, a2), returns 0 or -1.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_634d58(u32 size);   // CRT allocator, one argument (exe code)

static u32 __attribute__((cdecl)) fn410280(u32 *p, u32 a2) {
  if (p == nullptr) return 0xffffffff;
  for (u32 k = 0; k < 0x5a; ++k) p[k] = 0;
  p[1] = 0x4000;
  p[0] = ext_634d58(0x4000);
  p[6] = 0x400;
  p[4] = ext_634d58(0x1000);
  p[5] = ext_634d58(p[6] << 3);
  p[0x54] = a2;
  return 0;
}

PCREG(410280, fn410280);
