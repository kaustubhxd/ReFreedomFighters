// batch2414.cpp - decomp area 24, batch 2414: four small accessors.
#include "ff.h"

// 0x49c670 CListUser::GetTotalBufferSize(), thiscall, plain ret. Sum of the dwords at +0x29, +0x21 and +0x19.
static u32 THISCALL listUserTotalBufferSize(u8 *self) {
  u32 t = *(u32 *)(self + 0x29);
  t += *(u32 *)(self + 0x21);
  t += *(u32 *)(self + 0x19);
  return t;
}
PCREG(49c670, listUserTotalBufferSize);

// 0x4dc130 ZBaseGeom::ParentGroup() const, thiscall, plain ret. The group at +0x50 (null when unset) and its +0x54.
static u32 THISCALL baseGeomParentGroup(u8 *self) {
  u8 *p = *(u8 **)(self + 0x50);
  if (!p)
    return 0;
  return *(u32 *)(p + 0x54);
}
PCREG(4dc130, baseGeomParentGroup);

// 0x65f570 ZDrawBuffer::GetCameraToRootMatrix(), thiscall, plain ret. ((this+8)+8) + 8.
static u32 THISCALL drawBufferCameraToRoot(u8 *self) {
  u8 *a = *(u8 **)(self + 8);
  u8 *b = *(u8 **)(a + 8);
  return (u32)(b + 8);
}
PCREG(65f570, drawBufferCameraToRoot);

// 0x602d70, thiscall, plain ret. The pointer at +0x24 (null gives 0) and the dword at its +0x24.
static u32 THISCALL accessor602d70(u8 *self) {
  u8 *p = *(u8 **)(self + 0x24);
  if (!p)
    return 0;
  return *(u32 *)(p + 0x24);
}
PCREG(602d70, accessor602d70);
