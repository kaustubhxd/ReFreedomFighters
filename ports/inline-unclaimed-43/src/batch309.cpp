// batch309.cpp - ZPlayer::ForceLHandItem(ZItem *item, bool flag) (area 43, 2026-10-12). 0x483660.
// GC 80153b58 (name map, high). thiscall (this = ECX), two stack arguments (item, flag as a byte), ret 8.
// Body: r = this slot 0x514(). If flag == 0 and r != 0: this slot 0x45c(r == 1 ? 5 : 9, 0); return.
// Else if item == 0: this slot 0x524(0); return. Else r2 = engine(g_pSysInterface->[0x9b]) slot 0x4c(item);
// this slot 0x524(r2); item slot 0x2d0(0, 0).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL playerForceLHandItem(u8 *self, u8 *item, u32 flag) {
  u32 r = vcall<u32>((void *)self, 0x514);
  if ((u8)flag == 0 && r != 0) {
    // the exe pushes 0 first, then 5 or 9: the callee's first parameter is 5 or 9, the second is 0
    if (r == 1)
      vcall<void>((void *)self, 0x45c, 5u, 0u);
    else
      vcall<void>((void *)self, 0x45c, 9u, 0u);
    return;
  }
  if (item == 0) {
    vcall<void>((void *)self, 0x524, 0u);
    return;
  }
  u8 *eng = (u8 *)G(u32, 0x70039c);
  u32 r2 = vcall<u32>((void *)U32(eng, 0x9b), 0x4c, (u32)(unsigned long)item);
  vcall<void>((void *)self, 0x524, r2);
  vcall<void>((void *)item, 0x2d0, 0u, 0u);
}
PCREG(483660, playerForceLHandItem);
