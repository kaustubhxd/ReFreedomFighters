// batch8686.cpp - residue 6 batch 86 (GUESS name): FUN_005ec5a0.
#include "ff.h"

// 0x5ec5a0 (GUESS FUN_005ec5a0): p = the dword at this+0x3a (unaligned read); this+0x42 = arg; *p = arg. Ret 4.
static void THISCALL guess5ec5a0(u8 *self, u32 a) {
  u8 *p = *(u8 **)(self + 0x3a);
  *(u32 *)(self + 0x42) = a;
  *(u32 *)p = a;
}
PCREG(5ec5a0, guess5ec5a0);
