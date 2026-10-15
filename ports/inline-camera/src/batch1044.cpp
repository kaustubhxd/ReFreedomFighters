// batch1044.cpp - ZCAMERA::Load(ZLoadGame*): the engine camera's saved fields, the mirror of Save. Camera thread,
// 2026-10-11. Read order follows the original's calls: each field read is a virtual call on the load object
// (slot 0x40 dword/handle, 0x48 dword, 0x50 float, 0x68 byte, 0x6c 12-byte vector, 0x18 raw block); handles are
// resolved by the manager at ZSysInterface+0x9b (slot 0x54 for the list of geometry, 0x58 for single handles).
// The helper 0x45f3c0 (flags read, and the room pointer at +0x10) is inlined.
#include "cam.h"

// 0x446040 ZCAMERA::Load(ZLoadGame *load) (thiscall, one stack arg): always returns true; the early exit of the
// original is for the helper's result, which is always 1.
static THISCALL void ZCAMERA_Load(u8 *self, u8 *load) {
  vcall<void>(load, 0x40, (void *)(self + 0x14));   // flags
  u32 tmp = 0;
  vcall<void>(load, 0x40, &tmp);
  if (tmp) {
    vcall<void>(self, 0x40);
    at<u32>(at<u8 *>(self, 0x10), 0x18) = tmp;
  }
  // Geometry list: count at +0x2c, then one handle per entry resolved by the manager's slot 0x54 into +0x24.
  vcall<void>(load, 0x40, (void *)(self + 0x2c));
  for (u32 i = 0; i < at<u32>(self, 0x2c); i++) {
    u32 h = 0;
    vcall<void>(load, 0x40, &h);
    at<u32>(self, 0x24 + i * 4) = vcall<u32>(SYS9B, 0x54, h);
  }
  // Single handles resolved by the manager's slot 0x58: +0x18 and +0x192.
  vcall<void>(load, 0x40, &tmp);
  at<u32>(self, 0x18) = vcall<u32>(SYS9B, 0x58, tmp);
  vcall<void>(load, 0x40, &tmp);
  at<u32>(self, 0x192) = vcall<u32>(SYS9B, 0x58, tmp);
  // The field list, in the original's call order.
  vcall<void>(load, 0x40, (void *)(self + 0x1c));
  vcall<void>(load, 0x48, (void *)(self + 0x30));
  vcall<void>(load, 0x48, (void *)(self + 0x34));
  vcall<void>(load, 0x50, (void *)(self + 0x38));
  vcall<void>(load, 0x6c, (void *)(self + 0x3c));
  vcall<void>(load, 0x48, (void *)(self + 0x48));
  vcall<void>(load, 0x48, (void *)(self + 0x4c));
  vcall<void>(load, 0x50, (void *)(self + 0x50));
  vcall<void>(load, 0x50, (void *)(self + 0x54));
  vcall<void>(load, 0x50, (void *)(self + 0x58));
  vcall<void>(load, 0x50, (void *)(self + 0x5c));
  vcall<void>(load, 0x50, (void *)(self + 0x60));
  vcall<void>(load, 0x50, (void *)(self + 0x64));
  vcall<void>(load, 0x50, (void *)(self + 0x68));
  vcall<void>(load, 0x40, (void *)(self + 0x6c));
  vcall<void>(load, 0x50, (void *)(self + 0x70));
  vcall<void>(load, 0x50, (void *)(self + 0x74));
  vcall<void>(load, 0x40, (void *)(self + 0x78));
  vcall<void>(load, 0x18, (void *)(self + 0x7c), 0x34u);
  vcall<void>(load, 0x18, (void *)(self + 0xb0), 0xc0u);
  vcall<void>(load, 0x68, (void *)(self + 0x170));
  vcall<void>(load, 0x50, (void *)(self + 0x171));
  vcall<void>(load, 0x50, (void *)(self + 0x175));
  vcall<void>(load, 0x50, (void *)(self + 0x179));
  vcall<void>(load, 0x50, (void *)(self + 0x17d));
  vcall<void>(load, 0x50, (void *)(self + 0x181));
  vcall<void>(load, 0x50, (void *)(self + 0x185));
  at<u32>(self, 0x189) = 0xbf800000u;   // -1.0f
  vcall<void>(load, 0x68, (void *)(self + 0x18d));
  vcall<void>(load, 0x40, &tmp);
  at<u32>(self, 0x18e) = tmp;
  vcall<void>(load, 0x68, (void *)(self + 0x196));
}
PCREG(446040, ZCAMERA_Load);
