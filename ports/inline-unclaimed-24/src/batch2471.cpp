// batch2471.cpp - decomp area 24, batch 2471 (parked ZLIST rows).
#include "ff.h"

// 0x44a5e0 ZLIST::RemoveGeom(ZGEOM*), thiscall, ret 4: slot 0x4c of the sys table with the argument; then slot 0x224 of this with
// the result.
static void THISCALL listRemoveGeom(u8 *self, void *geom) {
  u8 *sys = G(u8 *, 0x70039c);
  void *tab = *(void **)(sys + 0x9b);
  u32 r = vcall<u32>(tab, 0x4c, geom);
  vcall<void>(self, 0x224, r);
}
PCREG(44a5e0, listRemoveGeom);

// 0x449f70 ZLIST::AddGeom(ZGEOM*), thiscall, ret 4: slot 0x4c of the sys table with the argument; then slot 0x21c of this.
static void THISCALL listAddGeom(u8 *self, void *geom) {
  u8 *sys = G(u8 *, 0x70039c);
  void *tab = *(void **)(sys + 0x9b);
  u32 r = vcall<u32>(tab, 0x4c, geom);
  vcall<void>(self, 0x21c, r);
}
PCREG(449f70, listAddGeom);
