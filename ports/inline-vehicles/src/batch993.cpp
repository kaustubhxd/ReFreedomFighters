// batch993.cpp - residue-11 (core todo), batch 993: ZActionChamberItem::Save(ZSaveGame&), 0x486f30, thiscall, ret 4, void.
// s vslot 0x4c(float [this+0x2c]); when [this+0x28] is zero: s vslot 0x60(0) and done. Otherwise s vslot 0x60(1), then with e = [this+0x28]:
// e == [this+0x10] -> s vslot 0x3c(1); == [0x14] -> (2); == [0x1c] -> (3); == [0x18] -> (4); == [0x20] -> (5); == [0x24] -> (6);
// otherwise the hook at 0x7003b0 runs (a null hook is an int3) and s vslot 0x3c(s).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x486f30 ZActionChamberItem::Save(ZSaveGame&).
static void THISCALL chamberItemSave(u8 *t, u8 *s) {
  vcall<void>(s, 0x4c, F(t, 0x2c));
  if (D(t, 0x28) == 0) {
    vcall<void>(s, 0x60, 0u);
    return;
  }
  vcall<void>(s, 0x60, 1u);
  u32 e = D(t, 0x28);
  if (e == D(t, 0x10)) {
    vcall<void>(s, 0x3c, 1u);
    return;
  }
  if (e == D(t, 0x14)) {
    vcall<void>(s, 0x3c, 2u);
    return;
  }
  if (e == D(t, 0x1c)) {
    vcall<void>(s, 0x3c, 3u);
    return;
  }
  if (e == D(t, 0x18)) {
    vcall<void>(s, 0x3c, 4u);
    return;
  }
  if (e == D(t, 0x20)) {
    vcall<void>(s, 0x3c, 5u);
    return;
  }
  if (e == D(t, 0x24)) {
    vcall<void>(s, 0x3c, 6u);
    return;
  }
  void (*hook)() = *(void (**)())0x7003b0;
  if (!hook)
    __asm__ volatile("int3");
  hook();
  vcall<void>(s, 0x3c, (u32)s);
}
PCREG(486f30, chamberItemSave);
