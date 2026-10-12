// batch2432.cpp - decomp area 24, batch 2432.
#include "ff.h"

// 0x43e570 ZHELPER::DispBox(int), thiscall, ret 4. The dword at +0x18 changes only when bits 1 and 2 are clear.
static void THISCALL helperDispBox(u8 *self, s32 on) {
  u32 f = *(u32 *)(self + 0x18);
  if ((f & 6u) == 0) {
    if (on != 0)
      f |= 8u;
    else
      f &= 0xfffffff7u;
    *(u32 *)(self + 0x18) = f;
  }
}
PCREG(43e570, helperDispBox);

// 0x4d1c30 (unnamed), thiscall, ret 4. Walks the list at +0x24 (key +0x20, next +0x30).
static u8 *THISCALL listLookup4d1c30(u8 *self, u32 key) {
  u8 *n = *(u8 **)(self + 0x24);
  while (n) {
    if (*(u32 *)(n + 0x20) == key)
      return n;
    n = *(u8 **)(n + 0x30);
  }
  return 0;
}
PCREG(4d1c30, listLookup4d1c30);

// 0x632a70 inflate_trees_fixed, cdecl, plain ret, eax = 0.
static u32 inflateTreesFixed(u32 *bl, u32 *bd, u32 **tl, u32 **td) {
  *bl = G(u32, 0x6f55e0);
  *bd = G(u32, 0x6f55e4);
  *tl = (u32 *)0x6f44e0u;
  *td = (u32 *)0x6f54e0u;
  return 0;
}
PCREG(632a70, inflateTreesFixed);
