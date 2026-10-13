// batch770.cpp - gap band batch 770 (docs/20-gap-band-401000.md): 0x406770, cdecl (p), void.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d52(u32 p);   // CRT free (exe code)

static void __attribute__((cdecl)) fn406770(u32 *p) {
  if (p == nullptr) return;
  if (p[2] != 0) ext_634d52(p[2]);
  if (p[3] != 0) ext_634d52(p[3]);
  p[0] = 0;
  p[1] = 0;
  p[2] = 0;
  p[3] = 0;
  p[4] = 0;
}

PCREG(406770, fn406770);
