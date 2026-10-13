// batch1518.cpp - recruits thread, batch 1518: CSaveMissions::LevelCompleted and GetSubZoneMissionInfo (save-mission
// records per sub-zone; used by ZFFLevelController::GiveRemainingCharisma).
//
// CSaveMissions layout (from both bodies; GUESS on the meaning of the arrays):
//   +0x008  pointer array (name strings, one per sub-zone), entry i at +8+4i
//   +0x3c8  flag array "f" (entry i at +0x3c8+4i; the original reads it at +0x3c0 from the pointer base +8)
//   +0x5c0  state array "d" (entry i at +0x5c0+4i; the value 4 means "skip")
//   +0x788  second value array "v" (entry i at +0x790+4i)
//   +0x5b8  entry count n
// Name matching compares the first four bytes of the name with the first four bytes of the stored string.

#include "ff.h"

// 0x5b1000 CSaveMissions::LevelCompleted(const char* name) const, thiscall, ret 4.
// Returns 0 when some entry with the same four-byte prefix is not skipped (d != 0) and has its flag f == 0; else 1.
static u8 THISCALL missionsLevelCompleted(u8 *self, const char *name) {
  s32 n = *(s32 *)(self + 0x5b8);
  for (s32 i = 0; i < n; ++i) {
    if (*(s32 *)(self + 0x5c0 + 4 * i) != 0)
      continue;
    const char *p = *(const char **)(self + 8 + 4 * i);
    bool same = true;
    for (s32 j = 0; j < 4; ++j)
      if (name[j] != p[j]) {
        same = false;
        break;
      }
    if (same && *(s32 *)(self + 0x3c8 + 4 * i) == 0)
      return 0;
  }
  return 1;
}
PCREG(5b1000, missionsLevelCompleted);

extern "C" u8 THISCALL ext_5b1000(u8 *self, const char *name);

// 0x5b0f20 CSaveMissions::GetSubZoneMissionInfo(sSubZoneMissionStatus& out, const char* name), thiscall, ret 8.
// out: +0x000 name pointers (up to 16), +0x040 flags, +0x080 values, +0x0c0 states, +0x100 count, +0x104 result.
// Collects every entry with the name's four-byte prefix that is not skipped (state != 4), then the result is
// LevelCompleted(name) (0 or 1).
static void THISCALL missionsGetSubZoneInfo(u8 *self, u8 *out, const char *name) {
  *(u32 *)(out + 0x100) = 0;
  s32 n = *(s32 *)(self + 0x5b8);
  for (s32 i = 0; i < n; ++i) {
    const char *p = *(const char **)(self + 8 + 4 * i);
    bool same = true;
    for (s32 j = 0; j < 4; ++j)
      if (name[j] != p[j]) {
        same = false;
        break;
      }
    if (!same)
      continue;
    if (*(s32 *)(self + 0x5c0 + 4 * i) == 4)
      continue;
    u32 c = *(u32 *)(out + 0x100);
    *(u32 *)(out + 4 * c) = (u32)(u64)(u32)p;
    *(u32 *)(out + 0x40 + 4 * c) = *(u32 *)(self + 0x3c8 + 4 * i);
    *(u32 *)(out + 0x80 + 4 * c) = *(u32 *)(self + 0x790 + 4 * i);
    *(u32 *)(out + 0xc0 + 4 * c) = *(u32 *)(self + 0x5c0 + 4 * i);
    ++*(u32 *)(out + 0x100);
  }
  *(u8 *)(out + 0x104) = ext_5b1000(self, name);
}
PCREG(5b0f20, missionsGetSubZoneInfo);
