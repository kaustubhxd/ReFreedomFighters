// batch3207.cpp - area 73 batch 7 (residue 12): ZActionChamberItem::Load(ZLoadGame&) (0x486cc0, docs/20-unclaimed-73.md).
#include "ff.h"

// 0x486cc0, ZActionChamberItem::Load(ZLoadGame&) (high), thiscall, ret 4: load slot +0x50(this+0x2c); load slot +0x68(&flag)
// (a byte); when the flag is zero, return. Otherwise load slot +0x40(&val); the switch on val-1 (0..5) stores this+0x10, +0x14,
// +0x1c, +0x18, +0x20, +0x24 at this+0x28. Any other value calls the assert pointer at 0x7003b0 (no arguments).
static void THISCALL actionChamberItemLoad(u8 *self, u8 *load) {
  vcall<void>(load, 0x50, (u32)(self + 0x2c));
  u8 flag = 0;
  vcall<void>(load, 0x68, (u32)&flag);
  if (!flag)
    return;
  u32 val = 0;
  vcall<void>(load, 0x40, (u32)&val);
  static const u32 offs[6] = {0x10, 0x14, 0x1c, 0x18, 0x20, 0x24};
  u32 idx = val - 1;
  if (idx > 5) {
    void *assertp = G(void *, 0x7003b0);
    if (assertp)
      ((void(__attribute__((cdecl)) *)(void))assertp)();
    return;
  }
  *(u32 *)(self + 0x28) = *(u32 *)(self + offs[idx]);
}
PCREG(486cc0, actionChamberItemLoad);
