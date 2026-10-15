// batch5800.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 100: 0x5c2b00 (GUESS name unnamed_5c2b00), thiscall, five stack arguments
// (name, val1, flag, val2, bb; ret 0x14), no return value. No callees. Order: n = this+0x2c0; if a stored name (dword at this+8+14i, i < n)
// equals name (byte-wise, up to NUL), return. Otherwise, if n < 16: entry n gets name at +8, val1 at +0xc, flag byte at +0x14, and if val2 != 0:
// val2 at +0x10 and bb at +0x15, else val1 at +0x10 and flag at +0x15; byte this+0xe8+n = 0; n++ (14-byte entries, stride 14).
#include "ff.h"

static bool sameName(const char *a, const char *b) {
  for (;;) {
    if (*a != *b) return false;
    if (!*a) return true;
    a++;
    b++;
  }
}

// 0x5c2b00, thiscall, five stack arguments (GUESS name)
static void THISCALL unnamed5c2b00(u8 *self, const char *name, u32 val1, u8 flag, u32 val2, u8 bb) {
  s32 n = (s32)*(u32 *)(self + 0x2c0);
  for (s32 i = 0; i < n; i++) {
    const char *stored = *(const char **)(self + 8 + 14 * i);
    if (sameName(name, stored)) return;
  }
  n = (s32)*(u32 *)(self + 0x2c0);
  if (n < 16) {
    u8 *ent = self + 14 * n;
    *(u32 *)(ent + 8) = (u32)(unsigned long)name;
    *(u32 *)(ent + 0xc) = val1;
    *(u8 *)(ent + 0x14) = flag;
    if (val2 != 0) {
      *(u32 *)(ent + 0x10) = val2;
      *(u8 *)(ent + 0x15) = bb;
    } else {
      *(u32 *)(ent + 0x10) = val1;
      *(u8 *)(ent + 0x15) = flag;
    }
    *(u8 *)(self + n + 0xe8) = 0;
    *(u32 *)(self + 0x2c0) += 1;
  }
}
PCREG(5c2b00, unnamed5c2b00);
