// batch2426.cpp - decomp area 24, batch 2426: three short functions with one vtable call each.
#include "ff.h"

// 0x4b1bb0 ZCutSeqBlood::Init(ZGEOM*, DBREAD&), thiscall, ret 8. Slot 0xbc of the object at +0x44 with 1, when bit 10 of
// [[+0x44]+8]+0x3c is clear.
static void THISCALL cutSeqBloodInit(u8 *self, void *geom, void *db) {
  (void)geom;
  (void)db;
  u8 *o2 = *(u8 **)(self + 0x44);
  u8 *o3 = *(u8 **)(o2 + 8);
  u32 v = *(u32 *)(o3 + 0x3c);
  if (((v >> 10) & 1) == 0)
    vcall<void>(o2, 0xbc, 1u);
}
PCREG(4b1bb0, cutSeqBloodInit);

// 0x4743f0 (GUESS), thiscall, plain ret. Zero unless the byte at +0x55 is set; then the sys table's slot 0x58 on +0x51.
static u32 THISCALL sysTableLookup(u8 *self) {
  if (self[0x55] == 0)
    return 0;
  u8 *sys = G(u8 *, 0x70039c);
  void *tab = *(void **)(sys + 0x9b);
  return vcall<u32>(tab, 0x58, *(u32 *)(self + 0x51));
}
PCREG(4743f0, sysTableLookup);

// 0x4f7070 ZScrollArea::DestroyCamera(), thiscall, plain ret. Slot 0x210 with 1 on the camera at +0x93, then cleared.
static void THISCALL scrollAreaDestroyCamera(u8 *self) {
  void *cam = *(void **)(self + 0x93);
  if (cam) {
    vcall<void>(cam, 0x210, 1u);
    *(u32 *)(self + 0x93) = 0;
  }
}
PCREG(4f7070, scrollAreaDestroyCamera);
