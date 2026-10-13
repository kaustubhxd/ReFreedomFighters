// batch799.cpp - gap band batch 799 (docs/20-gap-band-401000.md): 0x4104c0, cdecl (p, n), returns p[0] + p[2].
#include "ff.h"

typedef int i32;

extern "C" void __attribute__((cdecl)) ext_634d28(u32 dst, u32 src, u32 n);   // CRT memmove (exe code)
extern "C" u32 __attribute__((cdecl)) ext_634dee(u32 ptr, u32 size);         // CRT realloc (exe code)
extern "C" u32 __attribute__((cdecl)) ext_634d58(u32 size);                  // CRT allocator (exe code)

static u32 __attribute__((cdecl)) fn4104c0(u32 *p, u32 n) {
  if (p[3] != 0) {
    const i32 c = (i32)(p[2] - p[3]);
    p[2] = (u32)c;
    if (c > 0) ext_634d28(p[0], p[0] + p[3], (u32)c);
    p[3] = 0;
  }
  if ((i32)n > (i32)(p[1] - p[2])) {
    const u32 e = p[2] + n + 0x1000;
    if (p[0] != 0) p[0] = ext_634dee(p[0], e);
    else p[0] = ext_634d58(e);
    p[1] = e;
  }
  return p[0] + p[2];
}

PCREG(4104c0, fn4104c0);
