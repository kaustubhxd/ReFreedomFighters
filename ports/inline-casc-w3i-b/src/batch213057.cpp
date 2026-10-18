#include "ff.h"

typedef u32 (*Cb2)(u8 *, u8 *);

// 0x62b040: cdecl(base, p, end, out): single-byte name scanner with per-width callbacks in base, fourth variant (name followed by an optional white space run,
// single-byte sibling of 0x6277b0): start = class 22 / 24 (1 byte) or classes 5, 6, 7 (2, 3, 4 bytes, base->[0x158 / 0x15c / 0x160](base, p) must accept, -2 when
// cut off); name characters: 22..27 skip, classes 5, 6, 7 through the callbacks 0x14c / 0x150 / 0x154, class 11 ends with 5 and *out = p + 1, classes 9, 10, 21
// start a white space run (9, 10, 21 skipped, class 11 ends with 5 and *out = p + 1, anything else stops with 0); anything else stops with *out = p and 0;
// the end of input returns -1
extern "C" s32 fn_62b040(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -1;
  static const u8 map1[25] = {0, 1, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 5, 3, 5, 5, 5, 5, 4};
  static const u8 map2[25] = {0, 1, 2, 7, 3, 3, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 5, 5, 5, 5, 5, 5, 7, 6};
  static const u8 map3[13] = {0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0};
  u32 c = (u32)base[0x4c + *p] - 5;
  u32 m = c > 0x18 ? 5 : map1[c];
  u32 w;
  switch (m) {
    case 0:
    case 1:
    case 2: {
      w = m + 2;
      if ((s32)(end - p) < (s32)w) return -2;
      Cb2 f = *(Cb2 *)(base + 0x158 + m * 4);
      if (!f(base, p)) goto stop;
      break;
    }
    case 3: w = 1; break;
    default: goto stop;
  }
  p += w;
  if (p == end) return -1;
  for (;;) {
    u32 c2 = (u32)base[0x4c + *p] - 5;
    u32 m2 = c2 > 0x18 ? 7 : map2[c2];
    switch (m2) {
      case 0:
      case 1:
      case 2: {
        w = m2 + 2;
        if ((s32)(end - p) < (s32)w) return -2;
        Cb2 f = *(Cb2 *)(base + 0x14c + m2 * 4);
        if (!f(base, p)) goto stop;
        break;
      }
      case 3:
        p++;
        if (p == end) return -1;
        for (;;) {
          u32 c3 = (u32)base[0x4c + *p] - 9;
          u32 m3 = c3 > 0xc ? 2 : map3[c3];
          if (m3 == 1) {
            *out = p + 1;
            return 5;
          }
          if (m3 == 2) goto stop;
          p++;
          if (p == end) return -1;
        }
      case 4: *out = p + 1; return 5;
      case 5: w = 1; break;
      default: goto stop;
    }
    p += w;
    if (p == end) return -1;
  }
stop:
  *out = p;
  return 0;
}
PCREG(62b040, fn_62b040);
