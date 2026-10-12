// batch2404.cpp - decomp area 24, batch 2404: GUESS CSaveMissions::CollectSubZoneCodes (0x5b0e30).
// Helper of the sub-zone info code (0x5b0f20 region). For each missions entry whose state is 0 and whose name starts
// with the same three characters as `name`, the entry's code is c3 + 10*c2 - 0x220 (c2, c3 = the entry's characters
// 2 and 3). A code already in the output is skipped; a new code is appended when the entry is completed
// (LevelCompleted) and the output has room (5 codes). out[0..4] are the codes, out[5] is the count.
#include "ff.h"

extern "C" u8 THISCALL ext_5b1000(u8 *missions, const char *name);  // CSaveMissions::LevelCompleted

static void THISCALL collectSubZoneCodes(u8 *self, const char *name, u32 *out) {
  for (u32 k = 0; k < 6; ++k)
    out[k] = 0;
  u32 n = *(u32 *)(self + 0x5b8);
  for (u32 i = 0; i < n; ++i) {
    if (*(u32 *)(self + 0x5c0 + 4 * i) != 0)
      continue;
    const char *entry = *(const char **)(self + 8 + 4 * i);
    bool same = true;
    for (u32 k = 0; k < 3; ++k)
      if (name[k] != entry[k])
        same = false;
    if (!same)
      continue;
    s32 code = (s32)(s8)entry[3] + 10 * (s32)(s8)entry[2] - 0x220;
    u32 cnt = out[5];
    bool seen = false;
    for (u32 k = 0; k < cnt; ++k)
      if ((s32)out[k] == code)
        seen = true;
    if (seen)
      continue;
    if (!ext_5b1000(self, entry))
      continue;
    if (cnt < 5) {
      out[cnt] = (u32)code;
      out[5] = cnt + 1;
    }
  }
}
PCREG(5b0e30, collectSubZoneCodes);
