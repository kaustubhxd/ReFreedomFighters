#include "ff.h"
// batch7922.cpp - unclaimed-79 batch 22 (docs/20-unclaimed-79.md, gap band). Name from the GC name map (high).

// 0x4836f0, ZPlayer::ForceRHandItem(ZItem*, bool) (high). Thiscall, two stack arguments (ret 8).
static void THISCALL playerForceRHandItem(u8 *self, u8 *item, u8 flag) {
  u32 e = vcall<u32>(self, 0x510);
  if (flag == 0 && e != 0) {
    u32 x = e == 1 ? 6u : 0xau;
    vcall<void, u32, u32>(self, 0x45c, x, 0u);
    return;
  }
  if (item == 0) {
    vcall<void, u32>(self, 0x520, 0u);
    return;
  }
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32, u32>(t, 0x4c, (u32)(unsigned long)item);
  vcall<void, u32>(self, 0x520, r);
  vcall<void, u32, u32>(item, 0x2d0, 0u, 0u);
}
PCREG(4836f0, playerForceRHandItem);
