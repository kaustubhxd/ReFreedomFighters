// batch787.cpp - gap band batch 787 (docs/20-gap-band-401000.md): 0x4063d0, cdecl (p), void.
#include "ff.h"

typedef int i32;

extern "C" void __attribute__((cdecl)) ext_406430(u32 rec);   // cdecl, one argument (band batch 764)
extern "C" void __attribute__((cdecl)) ext_634d52(u32 p);     // CRT free (exe code)

static void __attribute__((cdecl)) fn4063d0(u32 *p) {
  if ((i32)(p[0] << 2) > 0) {
    i32 i = 0;
    do {
      ext_406430(p[4] + (u32)i * 0x18);
      ext_634d52(((u32 *)p[5])[i]);
      ++i;
    } while (i < (i32)(p[0] << 2));
  }
  ext_634d52(p[5]);
  ext_634d52(p[4]);
  for (u32 k = 0; k < 0xb; ++k) p[k] = 0;
}

PCREG(4063d0, fn4063d0);
