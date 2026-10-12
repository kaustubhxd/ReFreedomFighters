#include "ff.h"
// batch950.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x43aca0 (high), a list walk. Stdcall, one stack argument s, ret 4.
// If byte s+8 == 0 return. Clear the word s+8. n = [s+4]; while n != 0: pp = [n] (dereferenced, so non-null in practice); if [pp] == 0:
// P = pp - 4; if (P[0x32] & 0x10) and P[0x10] != 0: P[0x32] &= 0xaf; [P+0x21] = [P+0x1d]; if P+0x1d != g+0x1c: [P+0x1d] = [g+0x1c]
// (g = [0x70039c]). Then P[0x32] &= 0xcf; P[0x31] = 0; [P+0x42] = 0. Advance n = [n+5] (unaligned).

static void STDCALL zgroupFlagWalk(u8 *s) {
  if (*(u8 *)(s + 8) == 0) return;
  *(u16 *)(s + 8) = 0;
  u8 *n = *(u8 **)(s + 4);
  if (n == 0) return;
  for (;;) {
    u8 *pp = *(u8 **)n;
    if (*(u32 *)pp == 0) {
      u8 *P = pp - 4;
      u8 cl = P[0x32];
      if ((cl & 0x10) != 0 && P[0x10] != 0) {
        cl &= 0xaf;
        P[0x32] = cl;
        *(u32 *)(P + 0x21) = *(u32 *)(P + 0x1d);
        u8 *g = G(u8 *, 0x70039c);
        if (P + 0x1d != g + 0x1c) *(u32 *)(P + 0x1d) = *(u32 *)(g + 0x1c);
      }
      P[0x32] &= 0xcf;
      P[0x31] = 0;
      *(u32 *)(P + 0x42) = 0;
    }
    n = *(u8 **)(n + 5);
    if (n == 0) break;
  }
}
PCREG(43aca0, zgroupFlagWalk);
