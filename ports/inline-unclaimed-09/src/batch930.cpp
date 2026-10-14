// batch930.cpp - unclaimed-09 batch 22: CActionController::Save(ZSaveGame*) (core-todo residue-10; docs/20-unclaimed-09.md,
// claim 24). thiscall, one stack argument (the save object), ret 4, returns true in al. Save calls are unverified callees.
#include "ff.h"

typedef void(THISCALL *SaveU32)(u8 *self, u32 v);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x4a1bf0, CActionController::Save(ZSaveGame*) (list name): clears bit 6 of this+4; saves the two words at this+0x8b0 and
// this+0x8b2 (vt+0x40), the count at this+0x48 (vt+0x44), then for each of count entries (pointers from this+0x5c) the dword
// they point to (vt+0x3c); saves this+0x6c (vt+0x3c); returns true.
static u8 THISCALL actionCtrlSave(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= ~0x40u;
  ((SaveU32)slot(sg, 0x40))(sg, (u32)*(u16 *)(self + 0x8b0));
  ((SaveU32)slot(sg, 0x40))(sg, (u32)*(u16 *)(self + 0x8b2));
  ((SaveU32)slot(sg, 0x44))(sg, *(u32 *)(self + 0x48));
  u32 i = 0;
  if ((s32)*(u32 *)(self + 0x48) > 0) {
    do {
      u32 p = *(u32 *)(self + 0x5c + 4 * i);
      ((SaveU32)slot(sg, 0x3c))(sg, *(u32 *)p);
      i++;
    } while ((s32)i < (s32)*(u32 *)(self + 0x48));
  }
  ((SaveU32)slot(sg, 0x3c))(sg, *(u32 *)(self + 0x6c));
  return 1;
}
PCREG(4a1bf0, actionCtrlSave);
