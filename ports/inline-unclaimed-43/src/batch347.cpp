// batch347.cpp - 0x401000 (gap band). cdecl, one pointer argument; writes zero to the four dwords at it.
#include "ff.h"

static void zeroFourDwords(u32 *p) {
  p[0] = 0;
  p[1] = 0;
  p[2] = 0;
  p[3] = 0;
}
PCREG(401000, zeroFourDwords);
