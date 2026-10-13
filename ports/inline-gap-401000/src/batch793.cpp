// batch793.cpp - gap band batch 793 (docs/20-gap-band-401000.md): 0x401890, cdecl (p), void.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d52(u32 p);              // CRT free (exe code)
extern "C" u32 __attribute__((cdecl)) ext_634dee(u32 ptr, u32 size);   // CRT realloc (exe code)

static void __attribute__((cdecl)) fn401890(u32 *p) {
  u32 *node = (u32 *)p[0x15];
  while (node != nullptr) {
    const u32 next = node[1];
    ext_634d52(node[0]);
    node[0] = 0;
    node[1] = 0;
    ext_634d52((u32)node);
    node = (u32 *)next;
  }
  if (p[0x14] != 0) {
    p[0x11] = ext_634dee(p[0x11], p[0x13] + p[0x14]);
    p[0x13] = p[0x13] + p[0x14];
    p[0x14] = 0;
  }
  p[0x12] = 0;
  p[0x15] = 0;
}

PCREG(401890, fn401890);
