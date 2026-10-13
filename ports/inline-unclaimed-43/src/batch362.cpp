// batch362.cpp - 0x4079f0 (gap band). cdecl, one pointer p: if p != 0, zero 0x334 dwords at p (rep stosd), then free(p) (exe 0x634d52).
#include "ff.h"

extern "C" void ext_634d52(void *p);   // free (exe code, cdecl)

static void zeroAndFree362(u32 *p) {
  if (p != 0) {
    for (u32 i = 0; i < 0x334u; i++)
      p[i] = 0;
    ext_634d52(p);
  }
}
PCREG(4079f0, zeroAndFree362);
