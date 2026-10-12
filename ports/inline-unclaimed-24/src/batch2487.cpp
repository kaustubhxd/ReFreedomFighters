// batch2487.cpp - decomp area 24, batch 2487.
#include "ff.h"

extern "C" void ext_41e2c0(void *p);           // operator delete (cdecl)
extern "C" void THISCALL ext_47bdf0(void *self, u32 v);  // ZActor::SetHero(unsigned int), thiscall, ret 4

// 0x53e940 CRigidBody::End(), thiscall, void. Frees the pointer at +0x135 when set, then clears it.
static void THISCALL rigidBodyEnd(u8 *self) {
  u32 p = *(u32 *)(self + 0x135);
  if (p)
    ext_41e2c0((void *)p);
  *(u32 *)(self + 0x135) = 0;
}
PCREG(53e940, rigidBodyEnd);

// 0x478a80 ZActor::SMoveType::GetAnimHeader() const, thiscall. Zero when the first dword is zero; otherwise the table object's
// dword at +0x44 plus that value.
static u32 THISCALL smoveGetAnimHeader(u32 *self) {
  u32 p = *self;
  if (!p)
    return 0;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return *(u32 *)(tbl + 0x44) + p;
}
PCREG(478a80, smoveGetAnimHeader);

// 0x59ff70 ZFFActor::GetProjectilesInMagazine(int), thiscall, ret 4. Reads the dword at +0x78e (argument nonzero) or +0x78a, passes
// it to the table's slot 0x58; a non-null result answers slot 0x35c, otherwise -1.
static u32 THISCALL ffGetProjectilesInMagazine(u8 *self, u32 which) {
  u32 val = *(u32 *)(self + (which ? 0x78e : 0x78a));
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 o = vcall<u32>(tbl, 0x58, val);
  if (o)
    return vcall<u32>((void *)o, 0x35c);
  return 0xffffffffu;
}
PCREG(59ff70, ffGetProjectilesInMagazine);

// 0x5a2d60 ZFFActor::SetHero(unsigned int), thiscall, ret 4. Calls ZActor::SetHero with the argument, then stores the table's slot
// 0x58 result at +0x92e.
static void THISCALL ffSetHero(u8 *self, u32 v) {
  ext_47bdf0(self, v);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x92e) = vcall<u32>(tbl, 0x58, v);
}
PCREG(5a2d60, ffSetHero);
