// batch764.cpp - gap band batch 764 (docs/20-gap-band-401000.md): 0x406430, cdecl, (p), void. Frees three pointers, then zeroes six dwords.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d52(u32 p);   // cdecl, one argument (CRT free, exe code)

static void __attribute__((cdecl)) fn406430(u32 *p) {
  if (p == nullptr) return;
  ext_634d52(p[1]);
  ext_634d52(p[2]);
  ext_634d52(p[3]);
  for (u32 k = 0; k < 6; ++k) p[k] = 0;
}

PCREG(406430, fn406430);
