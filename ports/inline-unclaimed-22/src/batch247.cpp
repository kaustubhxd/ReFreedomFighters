// batch247.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch247"): ZFFSearchLightGroup::Save,
// CExplodeMolotov::Save. Names from the GameCube name map (high); behaviour from the PC bytes. ZSaveGame slots as called:
// 0x3c dword, 0x44 dword (count), 0x4c float bits, 0x60 byte, 0x64 and 0x6c dwords, 0x68 vector pointer, 0x70 pointer.
// Each slot returns the stream used by the next chained call.
#include "ff.h"

extern "C" void THISCALL ext_5c7830(u8 *self, u32 item, u8 *s);   // original (ret 8): saves one light of the group
extern "C" void THISCALL ext_4e74d0(u8 *self, u8 *s);              // original (ret 4): saves a particle parameter block

// 0x5c7740 ZFFSearchLightGroup::Save(ZSaveGame*) ret 4, returns al = 1. Fields, then the light list at +0x60: its count
// (vt[0x14]) is saved, then the list is walked (vt[0x4c](&it) starts, vt[0x5c](&it) returns the next item and clears it at
// the end) and each item goes to 0x5c7830(this, item, s). The list's vt[0x14] is called before the null test, as in the exe.
static bool THISCALL searchLightGroupSave_5c7740(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<u8 *>(s, 0x64, *(u32 *)(self + 0x48));
  vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x4c));
  vcall<u8 *>(s, 0x6c, *(u32 *)(self + 0x50));
  vcall<u8 *>(s, 0x6c, *(u32 *)(self + 0x54));
  vcall<u8 *>(s, 0x6c, *(u32 *)(self + 0x5c));
  vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x64));
  vcall<u8 *>(s, 0x60, (u32)self[0x68]);
  vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x69));
  vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x6d));
  vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x71));
  u32 n = vcall<u32>(*(u8 **)(self + 0x60), 0x14);
  vcall<u8 *>(s, 0x44, n);
  u8 *list = *(u8 **)(self + 0x60);
  if (list) {
    u32 it;
    vcall<void>(list, 0x4c, (u32)&it);
    u32 item = vcall<u32>(*(u8 **)(self + 0x60), 0x5c, (u32)&it);
    while (it) {
      ext_5c7830(self, item, s);
      item = vcall<u32>(*(u8 **)(self + 0x60), 0x5c, (u32)&it);
    }
  }
  return true;
}
PCREG(5c7740, searchLightGroupSave_5c7740);

// 0x584d20 CExplodeMolotov::Save(ZSaveGame*) ret 4, returns al = 1. Header fields, then five particle groups b = 0..4:
// 0x4e74d0(this + 0x9d + 0x2c b, s); (s.byte(+0x1c9 + b)).vec(+0x1ce + 0xc b); (s.dword(+0x179 + 4 b)).vec(+0x18d + 0xc b);
// with e = this + 0x222 + 0x44 b: float e+0x28, pointer e (slot 0x70), dword e+0x24, vectors e-0x18 and e-0xc.
static bool THISCALL explodeMolotovSave_584d20(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x58));
  vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x5c));
  vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x60));
  vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x64));
  vcall<u8 *>(s, 0x68, (u32)(self + 0x68));
  vcall<u8 *>(s, 0x68, (u32)(self + 0x74));
  vcall<u8 *>(s, 0x68, (u32)(self + 0x80));
  vcall<u8 *>(s, 0x60, (u32)self[0x8c]);
  vcall<u8 *>(s, 0x68, (u32)(self + 0x8d));
  vcall<u8 *>(s, 0x4c, *(u32 *)(self + 0x99));
  u8 *r = vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x362));
  vcall<u8 *>(r, 0x3c, *(u32 *)(self + 0x35e));
  for (u32 b = 0; b < 5; b++) {
    u8 *e = self + 0x222 + 0x44 * b;
    ext_4e74d0(self + 0x9d + 0x2c * b, s);
    r = vcall<u8 *>(s, 0x60, (u32)self[0x1c9 + b]);
    vcall<u8 *>(r, 0x68, (u32)(self + 0x1ce + 0xc * b));
    r = vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x179 + 4 * b));
    vcall<u8 *>(r, 0x68, (u32)(self + 0x18d + 0xc * b));
    vcall<u8 *>(s, 0x4c, *(u32 *)(e + 0x28));
    vcall<u8 *>(s, 0x70, (u32)e);
    vcall<u8 *>(s, 0x3c, *(u32 *)(e + 0x24));
    vcall<u8 *>(s, 0x68, (u32)(e - 0x18));
    vcall<u8 *>(s, 0x68, (u32)(e - 0xc));
  }
  return true;
}
PCREG(584d20, explodeMolotovSave_584d20);
