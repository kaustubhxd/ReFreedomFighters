// batch1037.cpp - ZShakeCamera::Save(ZSaveGame*) and ::Load(ZLoadGame*) (0x5d3740, 0x5d3660). Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_6352f0(void *self, void *db);    // ZEventBase::GetInput (original)
extern "C" THISCALL long double ext_4e5e80(void *db);          // DBREAD::operator float
extern "C" THISCALL u32 ext_4e5e40(void *db);                  // DBREAD::operator unsigned short
extern "C" THISCALL u32 ext_4e5e60(void *db);                  // DBREAD::operator unsigned int

// Fields: +0x55, +0x59, +0x5d, +0x61 the four main cameras (handles at save time); +0x4a strength, +0x52 trigger,
// +0x54 shake on start, +0x4e radius.

// 0x5d3740 ZShakeCamera::Save(ZSaveGame*): clears flag 0x40 of +4, then writes the four camera handles.
static THISCALL u32 ZShakeCamera_Save(u8 *self, void *sg) {
  at<u32>(self, 4) &= 0xffffffbf;
  vcall<void>(sg, 0x64, at<u32>(self, 0x55));
  vcall<void>(sg, 0x64, at<u32>(self, 0x59));
  vcall<void>(sg, 0x64, at<u32>(self, 0x5d));
  vcall<void>(sg, 0x64, at<u32>(self, 0x61));
  return 1;
}
PCREG(5d3740, ZShakeCamera_Save);

// 0x5d3660 ZShakeCamera::Load(ZLoadGame*): the event block (strength, trigger, on-start, radius) is read through
// GetInput and DBREAD, then the four camera handles are read and resolved through the manager (slot 0x58).
static THISCALL u32 ZShakeCamera_Load(u8 *self, void *lg) {
  u32 db = 0;
  at<u32>(self, 4) &= 0xffffffbf;
  ext_6352f0(self, &db);
  at<float>(self, 0x4a) = (float)ext_4e5e80(&db);
  at<u16>(self, 0x52) = (u16)ext_4e5e40(&db);
  at<u8>(self, 0x54) = ext_4e5e60(&db) != 0;
  at<float>(self, 0x4e) = (float)ext_4e5e80(&db);
  static const u16 offs[4] = {0x55, 0x59, 0x5d, 0x61};
  for (int i = 0; i < 4; i++) {
    u32 h = 0;
    vcall<void>(lg, 0x40, &h);
    at<u32>(self, offs[i]) = vcall<u32>(SYS9B, 0x58, h);
  }
  return 1;
}
PCREG(5d3660, ZShakeCamera_Load);
