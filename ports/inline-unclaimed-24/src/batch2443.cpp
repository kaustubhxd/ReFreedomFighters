// batch2443.cpp - decomp area 24, batch 2443 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);  // ZBaseGeom::SetControl(unsigned int, unsigned int)

// 0x443300 ZTreeGroup::GetStaticChildTreeGroupList(ZTreeGroup***) const, thiscall, ret 4. The high half of the list pointer
// is kept; the asm barrier keeps clang from dropping it (as in batch 2440).
static u32 THISCALL treeGroupStaticChildList(u8 *self, u32 *out) {
  *out = 0;
  u32 p = *(u32 *)(self + 0x7b);
  if (p == 0)
    return 0;
  *out = p + 4u;
  u32 hi = p & 0xffff0000u;
  asm volatile("" : "+r"(hi));
  u16 w = *(u16 *)p;
  return hi | (u32)w;
}
PCREG(443300, treeGroupStaticChildList);

// 0x4493a0 ZLIGHT::Enable(), thiscall, plain ret.
static void THISCALL lightEnable(u8 *self) {
  ext_4dc630(*(void **)(self + 8), 0u, 0x2000u);
  *(u32 *)(self + 0x18) = (*(u32 *)(self + 0x18) & 0xfffffffeu) | 8u;
}
PCREG(4493a0, lightEnable);

// 0x445140 ZROOM::SetAttachedDrawBaseGeom(ZBaseGeom*), thiscall, ret 4: slot 0x50 of the sys table with the argument.
static void THISCALL roomSetAttachedDrawBaseGeom(u8 *self, void *geom) {
  u8 *sys = G(u8 *, 0x70039c);
  void *tab = *(void **)(sys + 0x9b);
  *(u32 *)(self + 0xc0) = vcall<u32>(tab, 0x50, geom);
}
PCREG(445140, roomSetAttachedDrawBaseGeom);
