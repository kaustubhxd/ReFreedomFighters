#include "ff.h"
// batch951.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x43ac30 (high). Thiscall (self in ecx), no stack arguments, void.
// Table search: i = index of the first entry equal to 0x6e49c0 in the table at 0x6e48c0 (16-byte stride; a zero entry means not found,
// which the exe reads at address 0; the spec never reaches it). v = [0x6e48b8 + 16*i]; k = 10 * v.
// base = [self+0x1344]; walk(base + 0x32 + k); walk(base + 0x3c + k). The walk is the 0x43aca0 body (stdcall in the exe), copied here
// as a local static (a stdcall extern would need the decorated name, which this build's defsym does not handle).

static void flagWalkLocal(u8 *s) {
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

static void THISCALL zgroupTwoFlagWalks(u8 *self) {
  u32 i = 0;
  u32 e = *(u32 *)0x6e48c0;
  if (e != 0) {
    while (e != 0x6e49c0) {
      i++;
      e = *(u32 *)(0x6e48c0 + 16 * i);
      if (e == 0) break;
    }
  }
  if (e != 0x6e49c0) return;   // not found: the exe reads address 0 here (unreachable in the spec)
  u32 v = *(u32 *)(0x6e48b8 + 16 * i);
  u32 k = v * 10;
  u32 base = *(u32 *)(self + 0x1344);
  flagWalkLocal((u8 *)(base + 0x32 + k));
  flagWalkLocal((u8 *)(base + 0x3c + k));
}
PCREG(43ac30, zgroupTwoFlagWalks);
