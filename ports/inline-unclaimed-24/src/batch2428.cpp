// batch2428.cpp - decomp area 24, batch 2428: five short functions.
#include "ff.h"

// 0x61c630 (GUESS owner), cdecl, plain ret.
static void cdeclStoreAt5c(u8 *self, u32 v) {
  *(u32 *)(self + 0x5c) = v;
}
PCREG(61c630, cdeclStoreAt5c);

// 0x4f45f0 ZLINEOBJ::GetWidth() const, thiscall, plain ret, float on st0.
static float THISCALL lineObjGetWidth(u8 *self) {
  return (float)(*(s32 *)(self + 0xb0));
}
PCREG(4f45f0, lineObjGetWidth);

// 0x48f970 ZTimeUpdateList::Find(unsigned int), thiscall, ret 4.
static u8 *THISCALL timeUpdateListFind(u8 *self, u32 key) {
  u8 *n = *(u8 **)(self + 0xa04);
  while (n) {
    if (*(u32 *)n == key)
      return n;
    n = *(u8 **)(n + 0x10);
  }
  return 0;
}
PCREG(48f970, timeUpdateListFind);

// 0x4cf570 LINKREFTAB::RunToRefPtr(RefRun*), thiscall, ret 4.
static u32 THISCALL linkRefTabRunToRefPtr(u8 *self, u8 *run) {
  u32 first = *(u32 *)run;
  if (first == 0)
    return 0;
  return first + (2u - *(u32 *)(self + 0x18)) * 4u;
}
PCREG(4cf570, linkRefTabRunToRefPtr);

// 0x65f1b0 ZGeometryDecal::Init(), thiscall, plain ret.
static void THISCALL geometryDecalInit(u8 *self) {
  u8 *p = self + 0x2d0;
  *(u32 *)(self + 0xcc) = 0;
  *(u32 *)(p + 0x3400) = 0;
  for (u32 i = 0; i < 0x7f; ++i) {
    *(u16 *)p = (u16)(i + 1);
    p += 0x68;
  }
  *(u16 *)p = 0xffff;
}
PCREG(65f1b0, geometryDecalInit);
