#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);

// 0x627520: cdecl(base, p, end, out): scans wide-character text after a first "-" pair for the closing "-->" ((0, ch) pairs); class table
// base[0x4c + ch] or 0x62c640 for lead bytes; returns 0xd with *out after "->" , -1 at the end of input, -2 when a multi-byte
// character is cut off, else 0 with *out at the first non-comment character
extern "C" s32 fn_627520(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -1;
  if (p[0] != 0 || p[1] != 0x2d) {
    *out = p;
    return 0;
  }
  p += 2;
  if (p == end) return -1;
  s32 rem = (s32)(end - p);
  static const u8 map[28] = {0, 0, 5, 5, 5, 1, 2, 3, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4};
  do {
    u32 c = p[0] == 0 ? (u32)base[0x4c + p[1]] : ext_62c640(p[0], p[1]);
    u32 m = c > 0x1b ? 5 : map[c];
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
        if (p == end) return -1;
        if (p[0] == 0 && p[1] == 0x2d) {
          p += 2;
          if (p == end) return -1;
          if (p[0] != 0 || p[1] != 0x3e) {
            *out = p;
            return 0;
          }
          *out = p + 2;
          return 0xd;
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
PCREG(627520, fn_627520);
