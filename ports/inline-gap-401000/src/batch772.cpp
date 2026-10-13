// batch772.cpp - gap band batch 772 (docs/20-gap-band-401000.md): 0x410ec0, cdecl (p), returns a bit or -1.
#include "ff.h"

typedef int i32;

static u32 __attribute__((cdecl)) fn410ec0(u32 *p) {
  const i32 esi = (i32)p[0];
  u32 eax;
  if (esi < (i32)p[4]) {
    const u32 byte = *(const u8 *)p[3];
    eax = (byte >> (p[1] & 31)) & 1;
  } else {
    eax = 0xffffffff;
  }
  const i32 ecx = (i32)p[1] + 1;
  p[1] = (u32)ecx;
  if (ecx > 7) {
    const u32 ptr = p[3] + 1;
    p[1] = 0;
    p[3] = ptr;
    p[0] = (u32)(esi + 1);
  }
  return eax;
}

PCREG(410ec0, fn410ec0);
