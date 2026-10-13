// batch734.cpp - residue 11 (2026-10-12): ZMovementGuide::Load(ZLoadGame*) (0x489370) [medium]. The load object's slot 0x50
// receives this+0xc, the guide's slot 0x20 runs, the load's slot 0x40 writes a dword id, and the engine db's slot 0x58 maps the
// id to a reference stored at +0x375. Returns true.
#include "ff.h"

// 0x489370 ZMovementGuide::Load(ZLoadGame* load) [medium].
static bool THISCALL guide_Load(u8 *self, u8 *load) {
  vcall<void>(load, 0x50, self + 0xc);
  vcall<void>(self, 0x20);
  u32 id = 0;
  vcall<void>(load, 0x40, &id);
  void *db = *(void **)((u8 *)*(void **)0x70039c + 0x9b);
  *(u32 *)(self + 0x375) = vcall<u32>(db, 0x58, id);
  return true;
}
PCREG(489370, guide_Load);
