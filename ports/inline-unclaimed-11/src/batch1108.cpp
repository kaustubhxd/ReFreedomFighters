// batch1108.cpp - unclaimed-11 batch 8 (core-todo residue-10): ZActionReloadItem::Save(ZSaveGame&) (0x487060, medium).
// Thiscall, one argument (ret 4). Saves the float at this+0x30 (save slot 0x4c). If this+0x2c is nonzero: saves 1 (slot
// 0x60), takes an id from this's own slot 0x28 (argument this+0x2c) and saves it (slot 0x3c); otherwise saves 0 (slot 0x60).
#include "ff.h"

typedef void(THISCALL *saveFn)(void *self, u32 value);
typedef u32(THISCALL *idFn)(void *self, u32 value);

// 0x487060, ZActionReloadItem::Save(ZSaveGame&) (medium).
static void THISCALL actionReloadItemSave(u8 *self, u8 *save) {
  void **vt = *(void ***)save;
  ((saveFn)vt[0x4c / 4])(save, *(u32 *)(self + 0x30));
  if (*(u32 *)(self + 0x2c) != 0) {
    ((saveFn)vt[0x60 / 4])(save, 1);
    void **self_vt = *(void ***)self;
    u32 id = ((idFn)self_vt[0x28 / 4])(self, *(u32 *)(self + 0x2c));
    ((saveFn)vt[0x3c / 4])(save, id);
  } else {
    ((saveFn)vt[0x60 / 4])(save, 0);
  }
}
PCREG(487060, actionReloadItemSave);
