#include "ff.h"

// 0x622410: cdecl(unused, p): parses a wide-character numeric reference body after 4 bytes: "x" + hex digits or decimal digits up to ';'
// (each character is a (0, ch) byte pair); returns the code point, or -1 when too large or invalid
extern "C" s32 fn_622410(u32 unused, u8 *p) {
  (void)unused;
  u8 *e = p + 4;
  s32 v = 0;
  s32 ch;
  if (e[0] == 0 && e[1] == 0x78) {
    for (;;) {
      e += 2;
      if (e[0] == 0) {
        u8 cl = e[1];
        if (cl == 0x3b) goto done;
        ch = (s8)cl;
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
    if (e[0] == 0) {
      u8 cl = e[1];
      if (cl == 0x3b) goto done;
      ch = (s8)cl;
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
PCREG(622410, fn_622410);
