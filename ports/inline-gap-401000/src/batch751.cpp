// batch751.cpp - gap band batch 751 (docs/20-gap-band-401000.md): 0x410490, cdecl, one argument. Returns 0.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d52(u32 p);   // CRT free (stubbed in the spec)
extern "C" void __attribute__((cdecl)) ext_410470(u32 p);   // exe code, run for real

static u32 __attribute__((cdecl)) fn410490(u32 a) {
  if (a != 0) {
    const u32 v = G(u32, a);
    if (v != 0) ext_634d52(v);
    ext_410470(a);
  }
  return 0;
}

PCREG(410490, fn410490);
