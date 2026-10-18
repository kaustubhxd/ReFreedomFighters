#include "ff.h"

// 0x624b70: cdecl(unused, p): byte-swapped twin of 0x622410: wide characters are (lo, hi) pairs, 4 bytes into p; "x" then hex digits or decimal
// digits up to ';'; returns the code point or -1 (too large, surrogate, 0xfffe/0xffff, or a zero entry of the table at 0x6bf2f4 below 0x100)
extern "C" s32 fn_624b70(u32 unused, u8 *p) {
  (void)unused;
  u8 *e = p + 4;
  s32 v = 0;
  s32 ch;
  if (e[1] == 0 && e[0] == 0x78) {
    for (;;) {
      e += 2;
      if (e[1] == 0) {
        u8 lo = e[0];
        if (lo == 0x3b) goto done;
        ch = (s8)lo;
      } else {
        ch = -1;
      }
      u32 d = (u32)(ch - 0x30);
      if (d <= 0x36) {
        static const u8 map[55] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3,
                                   3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2,
                                   2, 2, 2, 2, 2};
        switch (map[d]) {
          case 0: v = (s32)((u32)v << 4) | (s32)d; break;
          case 1: v = (s32)((u32)v << 4) - 0x37 + ch; break;
          case 2: v = (s32)((u32)v << 4) - 0x57 + ch; break;
          default: break;
        }
      }
      if (!(v < 0x110000)) return -1;
    }
  }
  for (;;) {
    if (e[1] == 0) {
      u8 lo = e[0];
      if (lo == 0x3b) goto done;
      ch = (s8)lo;
    } else {
      ch = -1;
    }
    v = ch + (v * 5 - 0x18) * 2;
    if (v >= 0x110000) return -1;
    e += 2;
  }
done:
  s32 hi = v >> 8;
  if (hi > 0xdf) {
    if (hi != 0xff) return v;
    if (v == 0xfffe || v == 0xffff) return -1;
    return v;
  }
  if (hi >= 0xd8) return -1;
  if (hi != 0) return v;
  if (G(u8, 0x6bf2f4 + v) != 0) return v;
  return -1;
}
PCREG(624b70, fn_624b70);

extern "C" u32 ext_62c640(u32 a, u32 b);

static inline u32 cls_pair(u8 *base, u8 *p) {
  if (p[0] == 0) return base[0x4c + p[1]];
  return ext_62c640(p[0], p[1]);
}

// 0x622980: cdecl(base, a, b): compares two strings of (lead, second) byte pairs (2, 3 or 4 bytes wide by class), stops at the first exit class of a
// and returns 1 when b's class there is also an exit/terminator class, else 0
extern "C" u32 fn_622980(u8 *base, u8 *a, u8 *b) {
  static const u8 map1[25] = {0, 1, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 4, 3};
  static const u8 map2[25] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0};
  for (;;) {
    u32 c = cls_pair(base, a) - 5;
    if (c > 0x18) break;
    u32 m = map1[c];
    if (m == 4) break;
    u32 w = m == 0 ? 2 : m == 1 ? 3 : m == 2 ? 4 : 2;
    for (u32 k = 0; k < w; k++)
      if (a[k] != b[k]) return 0;
    a += w;
    b += w;
  }
  u32 c = cls_pair(base, b) - 5;
  if (c > 0x18) return 1;
  return map2[c] ? 1 : 0;
}
PCREG(622980, fn_622980);
