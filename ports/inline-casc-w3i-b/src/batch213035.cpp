#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);

static inline u32 cls_be(u8 *base, u8 *p) {
  if (p[0] == 0) return base[0x4c + p[1]];
  return ext_62c640(p[0], p[1]);
}

// 0x627a80: cdecl(delim, base, p, end, out): scans (lead, second) wide characters from p for one whose class equals delim; classes 5, 6, 7 are
// 2, 3, 4 bytes wide (-2 when cut off), classes 0, 1, 8 stop (*out = p, 0), 12 and 13 are delimiter-capable 2 byte characters; at a delimiter
// match: -27 at the end of input, else *out = the next position and 0x1b when the next character's class is 9, 10, 11 .. (map), else 0
extern "C" s32 fn_627a80(u32 delim, u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -1;
  s32 rem = (s32)(end - p);
  static const u8 map1[14] = {0, 0, 5, 5, 5, 1, 2, 3, 0, 5, 5, 5, 4, 4};
  static const u8 map2[22] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
  do {
    u32 c = cls_be(base, p);
    u32 m = c > 0xd ? 5 : map1[c];
    switch (m) {
      case 0: *out = p; return 0;
      case 1:
        if (rem < 2) return -2;
        p += 2;
        rem -= 2;
        break;
      case 2:
        if (rem < 3) return -2;
        p += 3;
        rem -= 3;
        break;
      case 3:
        if (rem < 4) return -2;
        p += 4;
        rem -= 4;
        break;
      case 4:
        p += 2;
        rem -= 2;
        if (c == delim) {
          if (p == end) return -27;
          *out = p;
          u32 c2 = cls_be(base, p) - 9;
          if (c2 <= 0x15 && map2[c2] == 0) return 0x1b;
          return 0;
        }
        break;
      default:
        p += 2;
        rem -= 2;
        break;
    }
  } while (p != end);
  return -1;
}
PCREG(627a80, fn_627a80);
