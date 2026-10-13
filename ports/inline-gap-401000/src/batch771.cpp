// batch771.cpp - gap band batch 771 (docs/20-gap-band-401000.md): 0x4106b0, cdecl (a, b), returns 1, 0 or -1.
#include "ff.h"

typedef int i32;
extern "C" i32 __attribute__((cdecl)) ext_410560(u32 a, u32 b);   // cdecl, two arguments (exe code)

static u32 __attribute__((cdecl)) fn4106b0(u32 *a, u32 b) {
  for (;;) {
    const i32 r = ext_410560((u32)a, b);
    if (r > 0) return 1;
    if (r == 0) return 0;
    if (a[4] != 0) continue;
    a[4] = 1;
    return 0xffffffff;
  }
}

PCREG(4106b0, fn4106b0);
