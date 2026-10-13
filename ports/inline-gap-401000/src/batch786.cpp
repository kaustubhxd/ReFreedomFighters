// batch786.cpp - gap band batch 786 (docs/20-gap-band-401000.md): 0x4017c0, cdecl (a, obj), returns 0.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_634df4(u32 count, u32 size);   // cdecl, two arguments (exe code)
extern "C" void __attribute__((cdecl)) ext_410b50(u32 p);               // cdecl, one argument (band batch 766)
extern "C" u32 __attribute__((cdecl)) ext_4063c0(void);                // no arguments (exe code)
extern "C" u32 __attribute__((cdecl)) ext_634d58(u32 size);             // cdecl, one argument (exe code)

static u32 __attribute__((cdecl)) fn4017c0(u32 a, u32 *obj) {
  for (u32 k = 0; k < 0x1c; ++k) obj[k] = 0;
  obj[0x10] = a;
  obj[0x13] = 0;
  obj[0x11] = 0;
  if (*(u32 *)a != 0) {
    u32 *rec = (u32 *)ext_634df4(1, 0x10);
    obj[0x1a] = (u32)rec;
    ext_410b50((u32)(obj + 1));
    rec[1] = 0xc61c3c00;
    const u32 n = ext_4063c0() << 2;
    rec[3] = ext_634d58(n);
  }
  return 0;
}

PCREG(4017c0, fn4017c0);
