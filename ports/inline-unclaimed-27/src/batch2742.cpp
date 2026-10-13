#include "ff.h"
// batch2742.cpp - unclaimed-27 batch 44 (residue 6). Names unknown (GUESS).

// 0x606ea0 (GUESS): stdcall, two arguments (pointer to a char pointer, modulus), ret 8, returns eax.
static u32 STDCALL funcStringHashMod(u32 pp, u32 mod) {
  const u8 *s = *(const u8 **)(unsigned long)pp;
  u32 h = 0;
  for (; *s != 0; s++) {
    s8 c = (s8)*s;
    if (*s >= 0x41 && *s <= 0x5a) h = h * 5 + 0x20;
    else h = h * 5;
    h += (u32)(s32)c;
  }
  return h % mod;
}
PCREG(606ea0, funcStringHashMod);

// 0x66ffe0 (GUESS): cdecl-void, no arguments. Splices the two globals 0x6e5d50 and 0x6e5d54 into the lists at 0x7003bc and 0x7003c0, then zeroes them.
static void funcSpliceGlobals() {
  u32 c = G(u32, 0x6e5d50);
  u32 a = G(u32, 0x6e5d54);
  if (c != 0) {
    *(u32 *)(unsigned long)(c + 0x14) = a;
    a = G(u32, 0x6e5d54);
    c = G(u32, 0x6e5d50);
  } else {
    G(u32, 0x7003bc) = a;
  }
  if (a != 0) {
    *(u32 *)(unsigned long)(a + 0x10) = c;
  } else {
    G(u32, 0x7003c0) = c;
  }
  G(u32, 0x6e5d50) = 0;
  G(u32, 0x6e5d54) = 0;
}
PCREG(66ffe0, funcSpliceGlobals);
