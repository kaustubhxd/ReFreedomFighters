// batch798.cpp - gap band batch 798 (docs/20-gap-band-401000.md): 0x408e20, cdecl (p), void.
#include "ff.h"

typedef int i32;

extern "C" void __attribute__((cdecl)) ext_634d52(u32 p);   // CRT free (exe code)

static void __attribute__((cdecl)) fn408e20(u32 *p) {
  if (p == nullptr) return;
  for (i32 i = 0; i < (i32)p[2]; ++i) {
    const u32 v = ((u32 *)p[6])[i];
    if (v != 0) ext_634d52(v);
  }
  ext_634d52(p[6]);
  for (i32 i = 0; i < (i32)p[7]; ++i) ext_634d52(((u32 *)p[8])[i]);
  ext_634d52(p[8]);
  for (u32 k = 0; k < 0x1d; ++k) p[k] = 0;
  ext_634d52((u32)p);
}

PCREG(408e20, fn408e20);
