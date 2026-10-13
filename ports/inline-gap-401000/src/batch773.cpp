// batch773.cpp - gap band batch 773 (docs/20-gap-band-401000.md): 0x410420, cdecl (p, n), void.
#include "ff.h"

typedef int i32;

extern "C" u32 __attribute__((cdecl)) ext_634dee(u32 ptr, u32 size);   // cdecl, two arguments (exe code)

static void __attribute__((cdecl)) fn410420(u32 *p, u32 n) {
  if ((i32)p[6] <= (i32)(p[7] + n)) {
    p[6] = p[6] + n + 0x20;
    p[4] = ext_634dee(p[4], p[6] << 2);
    p[5] = ext_634dee(p[5], p[6] << 3);
  }
}

PCREG(410420, fn410420);
