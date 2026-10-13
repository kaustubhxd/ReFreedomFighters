// batch762.cpp - gap band batch 762 (docs/20-gap-band-401000.md): 0x4103f0, cdecl, (p, b), void. A growth step with a reallocation.
#include "ff.h"
typedef int i32;

extern "C" u32 __attribute__((cdecl)) ext_634dee(u32 ptr, u32 size);   // cdecl, two arguments (exe code)

static void __attribute__((cdecl)) fn4103f0(u32 *p, u32 b) {
  const i32 limit = (i32)(p[2] + b);
  if ((i32)p[1] <= limit) {
    p[1] = (u32)((i32)p[1] + (i32)b + 0x400);
    p[0] = ext_634dee(p[0], p[1]);
  }
}

PCREG(4103f0, fn4103f0);
