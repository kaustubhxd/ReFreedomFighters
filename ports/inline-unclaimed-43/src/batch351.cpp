// batch351.cpp - 0x410f10 (gap band). cdecl, one pointer argument p; returns [p+4] + [p] * 8 (the element address for index [p]
// in the array at [p+4]).
#include "ff.h"

static u32 elementAddr(u32 *p) {
  return p[1] + p[0] * 8u;
}
PCREG(410f10, elementAddr);
