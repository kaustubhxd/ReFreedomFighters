// batch766.cpp - gap band batch 766 (docs/20-gap-band-401000.md): 0x410b50, cdecl (p), returns the buffer.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_634d58(u32 size);   // cdecl, one argument (the CRT allocator, exe code)

static u32 __attribute__((cdecl)) fn410b50(u32 *p) {
  p[0] = 0;
  p[1] = 0;
  p[2] = 0;
  p[3] = 0;
  p[4] = 0;
  const u32 buf = ext_634d58(0x100);
  p[2] = buf;
  p[3] = buf;
  *(u8 *)buf = 0;
  p[4] = 0x100;
  return buf;
}

PCREG(410b50, fn410b50);
