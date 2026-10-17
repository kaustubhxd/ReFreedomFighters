// batch988.cpp - residue-11 (core todo), batch 988: ZFFItemBomb::Load(ZLoadGame*), 0x5d4770, thiscall, ret 4, returns 1.
// Clears bit 0x40 of [this+4]; L vslot 0x40(&slot) and render vslot 0x58(slot) -> [this+0x48]; L vslot 0x40(this+0x56), vslot 0x68(this+0x5a),
// vslot 0x50(this+0x5b); two more reads through L vslot 0x40 each answered by the render manager's vslot 0x58 (into +0x63 and +0x6b); one
// read into a local v4; then X = render manager vslot 0x138(), X vslot 0x4c(0x6b52cc, v4).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5d4770 ZFFItemBomb::Load(ZLoadGame*).
static u8 THISCALL itemBombLoad(u8 *t, u8 *L) {
  D(t, 4) &= 0xffffffbfu;
  u32 slot = 0;
  vcall<void>(L, 0x40, (u32)&slot);
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  D(t, 0x48) = vcall<u32>(rm, 0x58, slot);
  vcall<void>(L, 0x40, (u32)(t + 0x56));
  vcall<void>(L, 0x68, (u32)(t + 0x5a));
  vcall<void>(L, 0x50, (u32)(t + 0x5b));
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0x63) = vcall<u32>(rm, 0x58, slot);
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0x6b) = vcall<u32>(rm, 0x58, slot);
  u32 v4 = 0;
  vcall<void>(L, 0x40, (u32)&v4);
  void *x = (void *)vcall<u32>(rm, 0x138);
  vcall<void>(x, 0x4c, 0x6b52ccu, v4);
  return 1;
}
PCREG(5d4770, itemBombLoad);
