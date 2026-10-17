// batch738.cpp - ZFFItemBomb::Load(ZLoadGame*) (0x5d4770) [high], residue 11 slice (2026-10-12).
// Clears bit 0x40 of +4. Reads a dword id from the load object (slot 0x40), maps it through the engine db (slot 0x58) to
// +0x48. Then slot 0x40 writes a value to +0x56, slot 0x68 to +0x5a and slot 0x50 to +0x5b. Two more id reads map to +0x63 and
// +0x6b, and a third id read is discarded. Finally db slot 0x138 gives an object whose slot 0x4c registers "rFF_C4_BombDmgList" with this. Returns true.
#include "ff.h"

static inline void *db() { return *(void **)((u8 *)*(void **)0x70039c + 0x9b); }

// 0x5d4770 ZFFItemBomb::Load(ZLoadGame* load) [high].
static bool THISCALL bomb_Load(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u32 id = 0;
  vcall<void>(load, 0x40, &id);
  *(u32 *)(self + 0x48) = vcall<u32>(db(), 0x58, id);
  vcall<void>(load, 0x40, self + 0x56);
  vcall<void>(load, 0x68, self + 0x5a);
  vcall<void>(load, 0x50, self + 0x5b);
  vcall<void>(load, 0x40, &id);
  *(u32 *)(self + 0x63) = vcall<u32>(db(), 0x58, id);
  vcall<void>(load, 0x40, &id);
  *(u32 *)(self + 0x6b) = vcall<u32>(db(), 0x58, id);
  vcall<void>(load, 0x40, &id);                 // a third id read (its result is not used)
  void *obj = vcall<void *>(db(), 0x138);
  vcall<void>(obj, 0x4c, (const char *)0x6b52cc, self);   // "rFF_C4_BombDmgList"
  return true;
}
PCREG(5d4770, bomb_Load);
