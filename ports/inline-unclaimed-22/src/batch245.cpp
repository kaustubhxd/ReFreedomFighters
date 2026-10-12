// batch245.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch245"): save and load of
// projectiles and actions. Names from the GameCube name map (high); behaviour from the PC bytes. ZSaveGame/ZLoadGame slots
// as the exe calls them: 0x4c float, 0x3c dword, 0x68 vector pointer (save); 0x60 string out-pointer, 0x44 and 0x40 field
// pointers, 0x18 (buffer, size) (load). Each save slot returns the stream used for the next chained call.
#include "ff.h"

extern "C" void THISCALL ext_4e74d0(u8 *self, u8 *stream);   // original, ZParamParticle-style save helper (ret 4)
extern "C" void ext_634273(u32 p, u32 one);                  // original free-style release (cdecl)

// 0x4ba390 ZProjectile::Save(ZSaveGame*) ret 4, returns al = 1. Floats are passed as their raw bits (movss to the stack).
static bool THISCALL projectileSave_4ba390(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x51));
  u8 *r = vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x55));
  vcall<u8 *>(r, 0x4c, *(u32 *)(self + 0x59));
  r = vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x5d));
  vcall<u8 *>(r, 0x3c, *(u32 *)(self + 0x61));
  vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x65));
  vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x69));
  vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x89));
  ext_4e74d0(*(u8 **)(self + 0x6d), s);
  vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x71));
  vcall<u8 *>(s, 0x68, (u32)(self + 0x75));
  vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x81));
  vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x85));
  return true;
}
PCREG(4ba390, projectileSave_4ba390);

// 0x4a1390 CAction::Load(ZLoadGame*) ret 4, returns al = 1. Clears bit 6 of +4 and sets defaults (+0x5e = 0, +0x66 = 3,
// +0x63 = 0, +0x5a = 2), reads two strings (slot 0x60 into the argument slot and a local), +0x5f and +0x61 (slot 0x44),
// +0x106 (slot 0x40) and 0x17 bytes at +0x48 (slot 0x18); then this->vt[0xb0](str1, str2, [+0x48], (u16)[+0x4c], [+0x4e],
// [+0x52], [+0x56], [+0x106]); releases both strings with 0x634273(p, 1); if +0x5e is set, +0x102 = this + 0x7e.
static bool THISCALL actionLoad_4a1390(u8 *self, u8 *l) {
  u32 str1 = 0, str2 = 0;
  *(u32 *)(self + 4) &= ~0x40u;
  self[0x5e] = 0;
  *(u32 *)(self + 0x66) = 3;
  self[0x63] = 0;
  *(u32 *)(self + 0x5a) = 2;
  vcall<void>(l, 0x60, (u32)&str1);
  vcall<void>(l, 0x60, (u32)&str2);
  vcall<void>(l, 0x44, (u32)(self + 0x5f));
  vcall<void>(l, 0x44, (u32)(self + 0x61));
  vcall<void>(l, 0x40, (u32)(self + 0x106));
  vcall<void>(l, 0x18, (u32)(self + 0x48), 0x17u);
  vcall<void>(self, 0xb0, str1, str2, *(u32 *)(self + 0x48), (u32) * (u16 *)(self + 0x4c), *(u32 *)(self + 0x4e),
              *(u32 *)(self + 0x52), *(u32 *)(self + 0x56), *(u32 *)(self + 0x106));
  ext_634273(str1, 1);
  ext_634273(str2, 1);
  if (self[0x5e]) *(u32 *)(self + 0x102) = (u32)(self + 0x7e);
  return true;
}
PCREG(4a1390, actionLoad_4a1390);
