// batch1045.cpp - ZCAMERA::Save(ZSaveGame*): the engine camera's fields, the mirror of batch1044 (Load). Camera
// thread, 2026-10-11. Each field is a virtual call on the save object: slot 0x3c dword value, 0x44 dword value,
// 0x4c float value, 0x60 byte value, 0x68 12-byte vector (pointer), 0x10 raw block (pointer, size).
// Handles go to the manager at ZSysInterface+0x9b, slot 0x4c; list entries are dereferenced (+0x54) first.
// The helper 0x45f960 (flags, and the room hint of the object at +0x10) is inlined; it always returns 1.
#include "cam.h"

// 0x4464e0 ZCAMERA::Save(void *save) (thiscall, one stack arg): always returns true.
static THISCALL void ZCAMERA_Save(u8 *self, u8 *save) {
  vcall<void>(save, 0x3c, at<u32>(self, 0x14));   // flags
  u32 room = 0;
  u8 *rp = at<u8 *>(self, 0x10);
  if (rp) {
    u32 r = at<u32>(rp, 0x18);
    if (r) room = r;
  }
  vcall<void>(save, 0x3c, room);
  // Geometry list: count at +0x2c, then each entry's handle (its +0x54 word) through manager slot 0x4c.
  vcall<void>(save, 0x3c, at<u32>(self, 0x2c));
  for (u32 i = 0; i < at<u32>(self, 0x2c); i++) {
    u8 *entry = at<u8 *>(self, 0x24 + i * 4);
    vcall<void>(save, 0x3c, vcall<u32>(SYS9B, 0x4c, at<u32>(entry, 0x54)));
  }
  // Single handles through the manager's slot 0x4c: +0x18 and +0x192.
  vcall<void>(save, 0x3c, vcall<u32>(SYS9B, 0x4c, at<u32>(self, 0x18)));
  vcall<void>(save, 0x3c, vcall<u32>(SYS9B, 0x4c, at<u32>(self, 0x192)));
  // The field list, in the original's call order.
  vcall<void>(save, 0x3c, at<u32>(self, 0x1c));
  vcall<void>(save, 0x44, at<u32>(self, 0x30));
  vcall<void>(save, 0x44, at<u32>(self, 0x34));
  vcall<void>(save, 0x4c, at<float>(self, 0x38));
  vcall<void>(save, 0x68, (void *)(self + 0x3c));
  vcall<void>(save, 0x44, at<u32>(self, 0x48));
  vcall<void>(save, 0x44, at<u32>(self, 0x4c));
  vcall<void>(save, 0x4c, at<float>(self, 0x50));
  vcall<void>(save, 0x4c, at<float>(self, 0x54));
  vcall<void>(save, 0x4c, at<float>(self, 0x58));
  vcall<void>(save, 0x4c, at<float>(self, 0x5c));
  vcall<void>(save, 0x4c, at<float>(self, 0x60));
  vcall<void>(save, 0x4c, at<float>(self, 0x64));
  vcall<void>(save, 0x4c, at<float>(self, 0x68));
  vcall<void>(save, 0x3c, at<u32>(self, 0x6c));
  vcall<void>(save, 0x4c, at<float>(self, 0x70));
  vcall<void>(save, 0x4c, at<float>(self, 0x74));
  vcall<void>(save, 0x3c, at<u32>(self, 0x78));
  vcall<void>(save, 0x10, (void *)(self + 0x7c), 0x34u);
  vcall<void>(save, 0x10, (void *)(self + 0xb0), 0xc0u);
  vcall<void>(save, 0x60, (u32)at<u8>(self, 0x170));
  vcall<void>(save, 0x4c, at<float>(self, 0x171));
  vcall<void>(save, 0x4c, at<float>(self, 0x175));
  vcall<void>(save, 0x4c, at<float>(self, 0x179));
  vcall<void>(save, 0x4c, at<float>(self, 0x17d));
  vcall<void>(save, 0x4c, at<float>(self, 0x181));
  vcall<void>(save, 0x4c, at<float>(self, 0x185));
  vcall<void>(save, 0x60, (u32)at<u8>(self, 0x18d));
  vcall<void>(save, 0x44, at<u32>(self, 0x18e));
  vcall<void>(save, 0x60, (u32)at<u8>(self, 0x196));
}
PCREG(4464e0, ZCAMERA_Save);
