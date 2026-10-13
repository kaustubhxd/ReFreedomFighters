// batch767.cpp - gap band batch 767 (docs/20-gap-band-401000.md): 0x40f850, cdecl (p, n), void.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_634df4(u32 count, u32 size);       // cdecl, two arguments (exe code)
extern "C" void __attribute__((cdecl)) ext_40f890(u32 n, u32 a, u32 b);     // cdecl, three arguments (exe code)

static void __attribute__((cdecl)) fn40f850(u32 *p, u32 n) {
  p[0] = n;
  p[1] = ext_634df4(n * 3, 4);
  p[2] = ext_634df4(0x20, 4);
  ext_40f890(n, p[1], p[2]);
}

PCREG(40f850, fn40f850);
