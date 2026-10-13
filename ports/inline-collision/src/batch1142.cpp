// batch1142.cpp - collision thread, batch 1142 (hard-row lane, name GUESS): 0x463030, a table lookup. Thiscall (ECX = table), two
// stack arguments (key, out), ret 8. Returns 0 unless the dword at [T+4] is negative. The entries start at T+0x10 (or after the
// block at T+0x10 + 5 dwords when bit 0x40000000 is set), count [T+0xc], stride (dword at +4) & 0x3fffffff. A matching entry
// writes a value to *out (when out is not null) and returns the entry plus an offset.
#include "ff.h"

static u8 *THISCALL lookup463030(u8 *T, u32 key, u32 *out) {
  s32 f = *(s32 *)(T + 4);
  if (f >= 0) return 0;
  u8 *base = (f & 0x40000000) ? T + (*(u32 *)(T + 0x10) + 5) * 4 : T + 0x10;
  if (base == 0) return 0;
  s32 n = *(s32 *)(T + 0xc);
  if (n <= 0) return 0;
  u8 *cur = base;
  bool found = false;
  for (s32 k = 0; k < n; k++) {
    if (*(u32 *)cur == key) {
      found = true;
      break;
    }
    cur += *(u32 *)(cur + 4) & 0x3fffffffu;
  }
  if (!found) return 0;
  if (out != 0) {
    u32 fl = *(u32 *)(cur + 4) & 0xc0000000u;
    u32 val = 1;
    if (fl == 0x40000000u) val = *(u32 *)(cur + 0xc);
    else if (fl == 0xc0000000u) val = *(u32 *)(cur + 0x10);
    *out = val;
  }
  u32 fl2 = *(u32 *)(cur + 4) & 0xc0000000u;
  u32 off = (fl2 == 0x40000000u || fl2 == 0x80000000u || fl2 == 0xc0000000u) ? *(u32 *)(cur + 8) : 8u;
  return cur + off;
}
PCREG(463030, lookup463030);
