// batch372.cpp - 0x40f890 (gap band). cdecl(n, base, x): if n != 1: call 0x40f8b0(n, base + 4*n, x) (exe, cdecl, three arguments).
#include "ff.h"

extern "C" void ext_40f8b0(u32 n, u32 *p, u32 x);   // exe callee (cdecl, three arguments)

static void recurseHalf(u32 n, u32 *base, u32 x) {
  if (n != 1)
    ext_40f8b0(n, base + n, x);
}
PCREG(40f890, recurseHalf);
