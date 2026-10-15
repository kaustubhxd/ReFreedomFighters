// batch1308.cpp - inventory thread (inline-inventory, 2026-10-11): CInventory Init / Save / Load.
// Layout of CInventory (from these functions): +0x44 owner, +0x48..+0x66 sixteen 16-bit message or state ids,
// +0x6a dword, +0x6e REFTAB (events), +0x11a REFTAB (items), +0x1c6 REFTAB (actions).
#include "ff.h"

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u16 msgId(u32 name, u32 line) { return (u16)vcall<u32>(refTable(), 0x114, name, 0u, 0x6909a4u, line); }

// 0x4ab9e0 CInventory::Init() (map): clears +0x6a, then looks up 14 message ids by name (zitem file/line 0x41..0x51
// with the file literal 0x6909a4). Each id is stored as a 16-bit word:
// +0x4c, +0x4e, +0x5e, +0x60, +0x62, +0x64, +0x66, +0x48, +0x4a, +0x50, +0x52, +0x56, +0x54, +0x5c.
static void THISCALL invInit(u8 *self) {
  *(u32 *)(self + 0x6a) = 0;
  *(u16 *)(self + 0x4c) = msgId(0x6909d0, 0x41);
  *(u16 *)(self + 0x4e) = msgId(0x6909e0, 0x42);
  *(u16 *)(self + 0x5e) = msgId(0x688984, 0x43);
  *(u16 *)(self + 0x60) = msgId(0x688968, 0x44);
  *(u16 *)(self + 0x62) = msgId(0x6909f4, 0x45);
  *(u16 *)(self + 0x64) = msgId(0x690a14, 0x46);
  *(u16 *)(self + 0x66) = msgId(0x690a30, 0x47);
  *(u16 *)(self + 0x48) = msgId(0x690a48, 0x48);
  *(u16 *)(self + 0x4a) = msgId(0x690a64, 0x49);
  *(u16 *)(self + 0x50) = msgId(0x690a88, 0x4a);
  *(u16 *)(self + 0x52) = msgId(0x690aa4, 0x4b);
  *(u16 *)(self + 0x56) = msgId(0x68c71c, 0x4f);
  *(u16 *)(self + 0x54) = msgId(0x690ac0, 0x50);
  *(u16 *)(self + 0x5c) = msgId(0x68ae08, 0x51);
}
PCREG(4ab9e0, invInit);

// 0x4acb30 CInventory::Save(ZSaveGame*) (map): clears flag 0x40 of +4; words (slot 0x40) in the order
// +0x48, +0x4a, +0x4c, +0x4e, +0x50, +0x52, +0x56, +0x54, +0x58, +0x5a, +0x5c, +0x5e, +0x60, +0x62, +0x66; dword +0x6a
// (slot 0x3c); the item REFTAB +0x11a (slot 0x6c); word +0x64 (slot 0x40). Returns true.
static u8 THISCALL invSave(u8 *self, u8 *g) {
  *(u32 *)(self + 4) &= ~0x40u;
  static const u16 order[] = {0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x56, 0x54, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x66};
  for (u32 i = 0; i < sizeof(order) / sizeof(order[0]); i++) vcall<u32>(g, 0x40, (u32)*(u16 *)(self + order[i]));
  vcall<u32>(g, 0x3c, *(u32 *)(self + 0x6a));
  vcall<u32>(g, 0x6c, self + 0x11a);
  vcall<u32>(g, 0x40, (u32)*(u16 *)(self + 0x64));
  return 1;
}
PCREG(4acb30, invSave);

// 0x4acc20 CInventory::Load(ZLoadGame*) (map): clears flag 0x40 of +4; words (slot 0x44) in the same order as Save,
// then the dword +0x6a (slot 0x40), the item REFTAB +0x11a (slot 0x70), word +0x64 (slot 0x44); finally the action
// REFTAB +0x1c6 is cleared (slot 0xc). Returns true.
static u8 THISCALL invLoad(u8 *self, u8 *g) {
  *(u32 *)(self + 4) &= ~0x40u;
  static const u16 order[] = {0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x56, 0x54, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x66};
  for (u32 i = 0; i < sizeof(order) / sizeof(order[0]); i++) vcall<u32>(g, 0x44, self + order[i]);
  vcall<u32>(g, 0x40, self + 0x6a);
  vcall<u32>(g, 0x70, self + 0x11a);
  vcall<u32>(g, 0x44, self + 0x64);
  vcall<u32>(self + 0x1c6, 0xc);
  return 1;
}
PCREG(4acc20, invLoad);
