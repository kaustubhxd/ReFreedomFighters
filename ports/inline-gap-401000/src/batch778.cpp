// batch778.cpp - gap band batch 778 (docs/20-gap-band-401000.md): 0x40c420, cdecl (p), void.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d52(u32 p);   // CRT free (exe code)
extern "C" void __attribute__((cdecl)) ext_4079c0(u32 p);   // cdecl, one argument (exe code)

static void __attribute__((cdecl)) fn40c420(u32 *p) {
  if (p == nullptr) return;
  if (p[3] != 0) ext_634d52(p[3]);
  if (p[0xa] != 0) ext_634d52(p[0xa]);
  ext_4079c0((u32)(p + 5));
  for (u32 k = 0; k < 0xd; ++k) p[k] = 0;
  ext_634d52((u32)p);
}

PCREG(40c420, fn40c420);
