// batch3308.cpp - area 73 batch 8 (residue 12): ZProjectile::Load(ZLoadGame*) (0x4ba200, docs/20-unclaimed-73.md).
#include "ff.h"

// 0x4e7480: thiscall, one argument (original code, hooked in the spec).
extern "C" void THISCALL ext_4e7480(u8 *obj, u8 *load);
// DBREAD helpers (original code, hooked in the spec). The DBREAD object is a stack dword.
extern "C" void THISCALL ext_6352f0(u8 *self, u32 *db);
extern "C" u32 THISCALL ext_4e5e60(u32 *db);
extern "C" float THISCALL ext_4e5e80(u32 *db);
extern "C" u32 THISCALL ext_4e5ef0(u32 *db);

// 0x4ba200, ZProjectile::Load(ZLoadGame*) (high), thiscall, ret 4. Clears bit 0x40 at +4. Load slot +0x50(+0x51); s1 = load
// slot +0x50(+0x55); s1 slot +0x50(+0x59); s2 = load slot +0x40(+0x5d); s2 slot +0x40(+0x61); load slot +0x40(+0x65); load
// slot +0x50(+0x69); load slot +0x40(+0x89); ext_4e7480(this+0x6d object, load); load slot +0x40(+0x71); load slot +0x6c(+0x75);
// load slot +0x50(+0x81); load slot +0x50(+0x85). Then db = 0; ext_6352f0(this, &db); this+0x4c = 0x4e5e60(&db); this+0x48 =
// (float) 0x4e5e80(&db); this+0x50 = (0x4e5e60(&db) != 0); this+0x91 = 0x4e5e60(&db); ok = 0x4e5ef0(&db); bit 0 of the dword at
// this+0x89 is set when ok, cleared otherwise. Returns true.
static bool THISCALL projectileLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(load, 0x50, (u32)(self + 0x51));
  u8 *s1 = (u8 *)vcall<u32>(load, 0x50, (u32)(self + 0x55));
  vcall<void>(s1, 0x50, (u32)(self + 0x59));
  u8 *s2 = (u8 *)vcall<u32>(load, 0x40, (u32)(self + 0x5d));
  vcall<void>(s2, 0x40, (u32)(self + 0x61));
  vcall<void>(load, 0x40, (u32)(self + 0x65));
  vcall<void>(load, 0x50, (u32)(self + 0x69));
  vcall<void>(load, 0x40, (u32)(self + 0x89));
  ext_4e7480(*(u8 **)(self + 0x6d), load);
  vcall<void>(load, 0x40, (u32)(self + 0x71));
  vcall<void>(load, 0x6c, (u32)(self + 0x75));
  vcall<void>(load, 0x50, (u32)(self + 0x81));
  vcall<void>(load, 0x50, (u32)(self + 0x85));
  u32 db = 0;
  ext_6352f0(self, &db);
  *(u32 *)(self + 0x4c) = ext_4e5e60(&db);
  *(float *)(self + 0x48) = ext_4e5e80(&db);
  *(u8 *)(self + 0x50) = (u8)(ext_4e5e60(&db) != 0);
  *(u32 *)(self + 0x91) = ext_4e5e60(&db);
  bool ok = (u8)ext_4e5ef0(&db) != 0;
  if (ok)
    *(u32 *)(self + 0x89) |= 1u;
  else
    *(u32 *)(self + 0x89) &= ~1u;
  return true;
}
PCREG(4ba200, projectileLoad);
