// batch791.cpp - gap band batch 791 (docs/20-gap-band-401000.md): 0x401900, cdecl (p), void.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_410b90(u32 p);   // cdecl, one argument (exe code)
extern "C" void __attribute__((cdecl)) ext_401890(u32 p);   // cdecl, one argument (exe code)
extern "C" void __attribute__((cdecl)) ext_634d52(u32 p);   // CRT free (exe code)

static void __attribute__((cdecl)) fn401900(u32 *p) {
  if (p[0x10] != 0 && *(u32 *)p[0x10] != 0) ext_410b90((u32)(p + 1));
  ext_401890((u32)p);
  if (p[0x11] != 0) ext_634d52(p[0x11]);
  if (p[0x1a] != 0) {
    if (((u32 *)p[0x1a])[3] != 0) ext_634d52(((u32 *)p[0x1a])[3]);
    ext_634d52(p[0x1a]);
  }
  for (u32 k = 0; k < 0x1c; ++k) p[k] = 0;
}

PCREG(401900, fn401900);
