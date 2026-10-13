// batch363.cpp - 0x408e00 (gap band). cdecl, one pointer p: if p != 0, zero 0x245 dwords at p (rep stosd), then free(p) (exe 0x634d52).
#include "ff.h"

extern "C" void ext_634d52(void *p);   // free (exe code, cdecl)

static void zeroAndFree363(u32 *p) {
  if (p != 0) {
    for (u32 i = 0; i < 0x245u; i++)
      p[i] = 0;
    ext_634d52(p);
  }
}
PCREG(408e00, zeroAndFree363);
