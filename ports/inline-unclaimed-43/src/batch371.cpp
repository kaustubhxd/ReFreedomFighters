// batch371.cpp - 0x405670 (gap band). cdecl(p): if p[+0x30] != 0: call 0x4055a0(p) (exe, cdecl), then free(p) (exe 0x634d52).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void ext_4055a0(void *p);   // exe callee (cdecl, one argument)
extern "C" void ext_634d52(void *p);   // free (cdecl)

static void releaseIfOwned(u8 *p) {
  if (U32(p, 0x30) != 0) {
    ext_4055a0(p);
    ext_634d52(p);
  }
}
PCREG(405670, releaseIfOwned);
