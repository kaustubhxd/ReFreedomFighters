#include "ff.h"

typedef u32 (*Cb2)(u8 *, u8 *);

// 0x62be60: cdecl(base, p, end, out): single-byte name scanner (class table base[0x4c + byte]) with per-width callbacks stored in base: a name start is class
// 22 or 24 (1 byte), or classes 5, 6, 7 (2, 3, 4 bytes, accepted when base->[0x158 / 0x15c / 0x160](base, p) is nonzero, -2 when cut off); name characters:
// classes 22, 24..27 (1 byte), classes 5, 6, 7 (callbacks 0x14c / 0x150 / 0x154), classes 9, 10, 11, 21, 30, 32, 36 end the name with 0x14 and *out = p;
// anything else stops with *out = p and 0; running out of input after a name start returns -20, an empty input -1
extern "C" s32 fn_62be60(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -1;
  static const u8 map1[25] = {0, 1, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 5, 3, 5, 5, 5, 5, 4};
  static const u8 map2[32] = {0, 1, 2, 6, 3, 3, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4, 6, 4, 4, 4, 4, 6, 5, 3, 6, 3, 6, 6, 6, 3};
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
  if (p == end) return -20;
  for (;;) {
    u32 c2 = (u32)base[0x4c + *p] - 5;
    u32 m2 = c2 > 0x1f ? 6 : map2[c2];
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
      case 3: *out = p; return 0x14;
      case 4: w = 1; break;
      default: goto stop;
    }
    p += w;
    if (p == end) return -20;
  }
stop:
  *out = p;
  return 0;
}
PCREG(62be60, fn_62be60);
