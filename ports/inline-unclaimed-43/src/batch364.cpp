// batch364.cpp - 0x40a410 (gap band). cdecl, one pointer p: if p != 0, zero 0x11c dwords at p (rep stosd), then free(p) (exe 0x634d52).
#include "ff.h"

extern "C" void ext_634d52(void *p);   // free (exe code, cdecl)

static void zeroAndFree364(u32 *p) {
  if (p != 0) {
    for (u32 i = 0; i < 0x11cu; i++)
      p[i] = 0;
    ext_634d52(p);
  }
}
PCREG(40a410, zeroAndFree364);
