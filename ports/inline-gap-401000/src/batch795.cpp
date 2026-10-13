// batch795.cpp - gap band batch 795 (docs/20-gap-band-401000.md): 0x401820, cdecl (p, size), returns a pointer.
#include "ff.h"

typedef int i32;

extern "C" u32 __attribute__((cdecl)) ext_634d58(u32 size);   // CRT allocator (exe code)

static u32 __attribute__((cdecl)) fn401820(u32 *p, u32 size) {
  const u32 edi = (size + 7) & ~7u;
  const u32 ecx = p[0x12] + edi;
  if ((i32)ecx > (i32)p[0x13]) {
    if (p[0x11] != 0) {
      u32 *rec = (u32 *)ext_634d58(8);
      p[0x14] = p[0x14] + p[0x12];
      rec[1] = p[0x15];
      rec[0] = p[0x11];
      p[0x15] = (u32)rec;
    }
    p[0x13] = edi;
    p[0x11] = ext_634d58(edi);
    p[0x12] = 0;
  }
  const u32 eax = p[0x11] + p[0x12];
  p[0x12] = p[0x12] + edi;
  return eax;
}

PCREG(401820, fn401820);
