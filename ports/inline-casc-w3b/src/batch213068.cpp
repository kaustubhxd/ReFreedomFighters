#include "ff.h"

typedef u32 (*Cb2)(u8 *, u8 *);

// 0x626850: cdecl(base, p, end, out): single-byte scanner for the end of a markup section, character classes base[0x4c + byte]. The first character decides: classes 0, 1, 8 stop
// with *out = p, return 0; 4 looks for "]]>" (class table: ']' = 0x5d, '>' = 0x3e), returning 0x28 with *out after it, -1 at the end of input; 9 returns 7 with *out = p + 1
// (or after the following character when that one has class 10); 10 returns 7 with *out = p + 1; 5, 6, 7 are 2, 3, 4 byte characters accepted through base->[0x164 / 0x168 / 0x16c]
// (-2 when cut off, 0 and *out = p when the callback accepts); 2, 3 and others skip one byte. Then a second loop scans the rest: classes 5, 6, 7 (callbacks as above, cut off or
// callback accepts ends it), 0, 1, 4 (map 0x626a4c) end it, anything else is one byte; the end of input returns 6 with *out = end.
extern "C" s32 fn_626850(u8 *base, u8 *p, u8 *end, u8 **out) {
  static const u8 map2[11] = {0, 0, 4, 4, 0, 1, 2, 3, 0, 0, 0};
  if (p == end) return -4;
  u8 *s = p;
  u32 c = base[0x4c + *s];
  if (c > 10) {
    s++;
  } else {
    switch (c) {
      case 0:
      case 1:
      case 8:
        *out = s;
        return 0;
      case 2:
      case 3: s++; break;
      case 4: {
        s++;
        u8 *keep = s;
        if (s == end) return -1;
        if (*s != 0x5d) break;
        s++;
        if (s == end) return -1;
        if (*s == 0x3e) {
          *out = s + 1;
          return 0x28;
        }
        s = keep;
        break;
      }
      case 9:
        s++;
        if (s == end) return -1;
        if (base[0x4c + *s] != 10) s = p;
        s++;
        *out = s;
        return 7;
      case 10:
        *out = s + 1;
        return 7;
      case 5:
      case 6:
      case 7: {
        u32 w = c - 3;
        if ((s32)(end - s) < (s32)w) return -2;
        Cb2 f = *(Cb2 *)(base + 0x164 + (c - 5) * 4);
        if (f(base, s)) {
          *out = s;
          return 0;
        }
        s += w;
        break;
      }
    }
  }
  for (;;) {
    if (s == end) break;
    u32 c2 = base[0x4c + *s];
    if (c2 > 10) { s++; continue; }
    u32 m = map2[c2];
    if (m == 0) break;
    if (m == 4) { s++; continue; }
    u32 w = m + 1;
    if ((s32)(end - s) < (s32)w) break;
    Cb2 f = *(Cb2 *)(base + 0x164 + (m - 1) * 4);
    if (f(base, s)) break;
    s += w;
  }
  *out = s;
  return 6;
}
PCREG(626850, fn_626850);
