// batch794.cpp - gap band batch 794 (docs/20-gap-band-401000.md): 0x401020, cdecl (p), void.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d52(u32 p);   // CRT free (exe code)

static void __attribute__((cdecl)) fn401020(u32 *p) {
  if (p == nullptr) return;   // the exe writes through p at its end: a NULL argument faults there
  for (u32 i = 0; i < p[2]; ++i) {
    const u32 v = ((u32 *)p[0])[i];
    if (v != 0) ext_634d52(v);
  }
  if (p[0] != 0) ext_634d52(p[0]);
  if (p[1] != 0) ext_634d52(p[1]);
  if (p[3] != 0) ext_634d52(p[3]);
  p[0] = 0;
  p[1] = 0;
  p[2] = 0;
  p[3] = 0;
}

PCREG(401020, fn401020);
