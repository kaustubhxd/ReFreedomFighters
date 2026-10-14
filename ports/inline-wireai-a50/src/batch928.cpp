// batch928.cpp - 0x58b930 ZFFHERO::AddToTargetList() [thiscall (ECX = this), no args, no pop]. Body read in full (2026-10-12).
// M = manager object (g+0x9b, then +0xadc). x = M slot +0x25c (0x6acfbc, 0). If x is null: y = M slot +0x294 (0x6acfbc, 0x67f610, 0, 1);
// y slot +0x154 (no args); 0x4dc630 (thiscall, ECX = y+8, args 0x800000 and 0; stood in); y slot +0x124 (1, 0, 0, 0); x = y.
// Then x slot +0x218 with this (one arg). Stood in: 0x4dc630.
#include "ff.h"

#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4dc630(void *obj, u32 a, u32 b);   // stood in (thiscall, two words)

// 0x58b930 (name in the map: ZFFHERO::AddToTargetList()).
static void THISCALL AddToTargetList58b930(u8 *self) {
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  u8 *m = (u8 *)FP(mgr, 0xadc);
  u8 *x = (u8 *)vcall<void *>(m, 0x25c, (void *)0x6acfbcu, 0u);
  if (!x) {
    u8 *y = (u8 *)vcall<void *>(m, 0x294, (void *)0x6acfbcu, (void *)0x67f610u, 0u, 1u);
    vcall<void>(y, 0x154);
    ext_4dc630(FP(y, 8), 0x800000u, 0u);
    vcall<void>(y, 0x124, 1u, 0u, 0u, 0u);
    x = y;
  }
  vcall<void>(x, 0x218, (void *)self);
}
PCREG(58b930, AddToTargetList58b930);
