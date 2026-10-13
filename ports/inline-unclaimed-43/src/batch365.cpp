// batch365.cpp - 0x40c400 (gap band). cdecl, one pointer p: if p != 0, zero 0x18 dwords at p (rep stosd), then free(p) (exe 0x634d52).
#include "ff.h"

extern "C" void ext_634d52(void *p);   // free (exe code, cdecl)

static void zeroAndFree365(u32 *p) {
  if (p != 0) {
    for (u32 i = 0; i < 0x18u; i++)
      p[i] = 0;
    ext_634d52(p);
  }
}
PCREG(40c400, zeroAndFree365);
