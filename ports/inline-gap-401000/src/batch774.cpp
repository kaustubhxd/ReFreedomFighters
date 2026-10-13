// batch774.cpp - gap band batch 774 (docs/20-gap-band-401000.md): 0x4102f0, cdecl (p), returns 0.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d52(u32 p);   // CRT free (exe code)

static u32 __attribute__((cdecl)) fn4102f0(u32 *p) {
  if (p == nullptr) return 0;
  if (p[0] != 0) ext_634d52(p[0]);
  if (p[4] != 0) ext_634d52(p[4]);
  if (p[5] != 0) ext_634d52(p[5]);
  for (u32 k = 0; k < 0x5a; ++k) p[k] = 0;
  return 0;
}

PCREG(4102f0, fn4102f0);
