// batch763.cpp - gap band batch 763 (docs/20-gap-band-401000.md): 0x407980, cdecl, (p, b, c), void.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_40f850(u32 p, u32 n);   // cdecl, two arguments (exe code)

static void __attribute__((cdecl)) fn407980(u32 *p, u32 b, u32 c) {
  p[0] = 0;
  p[1] = 0;
  p[2] = 0;
  p[3] = 0;
  p[4] = 0;
  p[3] = b;
  p[4] = c;
  ext_40f850((u32)p, b + b);
}

PCREG(407980, fn407980);
