// batch946.cpp - vehicles thread, batch 946: ZCar::Save(ZSaveGame*), 0x5184f0, callee pops 4, returns bool.
// The vehicle save (0x515b70, exe code as is) first; then the undercarriage save (0x526090, stood in). The rest goes
// through the save object's slots in this order: 0x68 vectors (+0x15d3, +0x15df, +0x15eb), 0x4c floats (+0x15f7,
// +0x15fb, +0x15ff), 0x10 4-byte blocks (+0x1603), 0x4c (+0x1607), 0x60 byte (+0x160b), 0x10 (+0x160c), 0x4c (+0x1610),
// 0x60 byte (+0x1614), 0x3c dwords (+0x1615, +0x1619, +0x161d, +0x1621, +0x1625, +0x1629, +0x162d, +0x1631),
// 0x44 dwords (+0x1635, +0x1639), 0x4c floats (+0x163d, +0x1641), 0x44 dword (+0x1645), 0x60 byte (+0x1649).
#include "ff.h"

extern "C" u8 THISCALL ext_515b70(void *self, void *sg);     // ZVehicle::Save (exe)
extern "C" void THISCALL ext_526090(void *uc, void *sg);     // CUnderCarriageCar/Tank save (stood in)

#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x5184f0 ZCar::Save(ZSaveGame*).
static u8 THISCALL carSave(u8 *s, void *sg) {
  if (!ext_515b70(s, sg))
    return 0;
  ext_526090(s + 0x2d8, sg);
  vcall<void>(sg, 0x68, (u32)(s + 0x15d3));
  vcall<void>(sg, 0x68, (u32)(s + 0x15df));
  vcall<void>(sg, 0x68, (u32)(s + 0x15eb));
  vcall<void>(sg, 0x4c, F(s, 0x15f7));
  vcall<void>(sg, 0x4c, F(s, 0x15fb));
  vcall<void>(sg, 0x4c, F(s, 0x15ff));
  vcall<void>(sg, 0x10, (u32)(s + 0x1603), 4u);
  vcall<void>(sg, 0x4c, F(s, 0x1607));
  vcall<void>(sg, 0x60, (u32)s[0x160b]);
  vcall<void>(sg, 0x10, (u32)(s + 0x160c), 4u);
  vcall<void>(sg, 0x4c, F(s, 0x1610));
  vcall<void>(sg, 0x60, (u32)s[0x1614]);
  vcall<void>(sg, 0x3c, *(u32 *)(s + 0x1615));
  vcall<void>(sg, 0x3c, *(u32 *)(s + 0x1619));
  vcall<void>(sg, 0x3c, *(u32 *)(s + 0x161d));
  vcall<void>(sg, 0x3c, *(u32 *)(s + 0x1621));
  vcall<void>(sg, 0x3c, *(u32 *)(s + 0x1625));
  vcall<void>(sg, 0x3c, *(u32 *)(s + 0x1629));
  vcall<void>(sg, 0x3c, *(u32 *)(s + 0x162d));
  vcall<void>(sg, 0x3c, *(u32 *)(s + 0x1631));
  vcall<void>(sg, 0x44, *(u32 *)(s + 0x1635));
  vcall<void>(sg, 0x44, *(u32 *)(s + 0x1639));
  vcall<void>(sg, 0x4c, F(s, 0x163d));
  vcall<void>(sg, 0x4c, F(s, 0x1641));
  vcall<void>(sg, 0x44, *(u32 *)(s + 0x1645));
  vcall<void>(sg, 0x60, (u32)s[0x1649]);
  return 1;
}
PCREG(5184f0, carSave);
