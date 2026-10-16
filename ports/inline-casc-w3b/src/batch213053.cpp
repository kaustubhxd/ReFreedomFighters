#include "ff.h"

typedef u32 (*Cb2)(u8 *, u8 *);

// 0x62b900: cdecl(base, p, end, out): single-byte name scanner with per-width callbacks in base (sibling of 0x62be60 with the 0x16 / 0x1c endings of
// 0x627fd0): a name start is class 22 / 24 (1 byte) or classes 5, 6, 7 (2, 3, 4 bytes, accepted when base->[0x158 / 0x15c / 0x160](base, p) is nonzero, -2 when
// cut off); classes 9, 10, 21, 30 as the first byte end with 0x16 (*out = p); later characters: 22, 24..27 (1 byte), classes 5, 6, 7 (callbacks 0x14c / 0x150 /
// 0x154), class 18 ends with 0x1c and *out = p + 1; anything else stops with *out = p and 0; the end of input returns -1
extern "C" s32 fn_62b900(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -1;
  static const u8 map1[26] = {0, 1, 2, 6, 3, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4, 6, 4, 6, 6, 6, 6, 5, 3};
  static const u8 map2[25] = {0, 1, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 6, 6, 6, 4, 6, 4, 4, 4, 4, 6, 5};
  u32 c = (u32)base[0x4c + *p] - 5;
  u32 m = c > 0x19 ? 6 : map1[c];
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
    case 3: *out = p; return 0x16;
    case 4: w = 1; break;
    default: goto stop;
  }
  p += w;
  if (p == end) return -1;
  for (;;) {
    u32 c2 = (u32)base[0x4c + *p] - 5;
    u32 m2 = c2 > 0x18 ? 6 : map2[c2];
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
      case 3: *out = p + 1; return 0x1c;
      case 4: w = 1; break;
      default: goto stop;
    }
    p += w;
    if (p == end) return -1;
  }
stop:
  *out = p;
  return 0;
}
PCREG(62b900, fn_62b900);
