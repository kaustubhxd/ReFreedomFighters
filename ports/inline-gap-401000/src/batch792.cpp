// batch792.cpp - gap band batch 792 (docs/20-gap-band-401000.md): 0x4061e0, cdecl (p, out, a3, n), returns 0 or -1.
#include "ff.h"

typedef int i32;

extern "C" i32 __attribute__((cdecl)) ext_405f20(u32 p, u32 a3);   // cdecl, two arguments (exe code)

static u32 __attribute__((cdecl)) fn4061e0(u32 *p, u32 *out, u32 a3, u32 n) {
  if ((i32)n <= 0) return 0;
  u32 k = 0;
  for (;;) {
    const i32 r = ext_405f20((u32)p, a3);
    if (r == -1) return 0xffffffff;
    u32 *row = (u32 *)(p[3] + p[0] * (u32)r * 4);
    for (u32 j = 0; j < p[0]; ++j) out[k++] = row[j];
    if ((i32)k >= (i32)n) break;
  }
  return 0;
}

PCREG(4061e0, fn4061e0);
