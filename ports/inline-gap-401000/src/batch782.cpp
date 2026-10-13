// batch782.cpp - gap band batch 782 (docs/20-gap-band-401000.md): 0x4057b0, cdecl (p, q), returns 0 or -1.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_405460(u32 q);   // cdecl, one argument (exe code)
extern "C" u32 __attribute__((cdecl)) ext_405240(u32 p);   // cdecl, one argument (exe code)
extern "C" void __attribute__((cdecl)) ext_405690(u32 p);  // cdecl, one argument (exe code)

static u32 __attribute__((cdecl)) fn4057b0(u32 *p, u32 *q) {
  for (u32 k = 0; k < 7; ++k) p[k] = 0;
  p[2] = (u32)q;
  p[1] = q[1];
  p[0] = q[0];
  p[3] = ext_405460((u32)q);
  p[5] = ext_405240((u32)p);
  if (p[5] != 0) return 0;
  ext_405690((u32)p);
  return 0xffffffff;
}

PCREG(4057b0, fn4057b0);
