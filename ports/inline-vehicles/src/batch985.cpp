// batch985.cpp - residue-11 (core todo), batch 985: CActionController::Save(ZSaveGame*), 0x4a1bf0, thiscall, ret 4, returns 1.
// Clears bit 0x40 of [this+4]; s vslot 0x40 with the word at +0x8b0, then with the word at +0x8b2; s vslot 0x44 with the count [this+0x48];
// for i < count: s vslot 0x3c with the dword at the element [this+0x5c+4i]; then s vslot 0x3c with [this+0x6c].
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4a1bf0 CActionController::Save(ZSaveGame*).
static u8 THISCALL actionCtrlSave(u8 *t, u8 *s) {
  D(t, 4) &= 0xffffffbfu;
  vcall<void>(s, 0x40, (u32)*(u16 *)(t + 0x8b0));
  vcall<void>(s, 0x40, (u32)*(u16 *)(t + 0x8b2));
  vcall<void>(s, 0x44, D(t, 0x48));
  int n = (int)D(t, 0x48);
  for (int i = 0; i < n; i++) {
    u8 *p = (u8 *)D(t, 0x5c + 4 * i);
    vcall<void>(s, 0x3c, D(p, 0));
  }
  vcall<void>(s, 0x3c, D(t, 0x6c));
  return 1;
}
PCREG(4a1bf0, actionCtrlSave);
