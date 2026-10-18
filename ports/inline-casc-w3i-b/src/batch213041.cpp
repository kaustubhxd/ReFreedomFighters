#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);
extern "C" s32 ext_629580(u8 *base, u8 *p, u8 *end, u8 **out);

static inline u32 cls_le(u8 *base, u8 *p) {
  if (p[1] == 0) return base[0x4c + p[0]];
  return ext_62c640(p[1], p[0]);
}

// 0x6296a0: cdecl(base, p, end, out): dispatch on the class of the first (lo, hi) pair: 20 -> *out = p+2, 0x21; 27 -> 0x629580 on the
// rest; 22 and 24 skip the pair and scan the following characters (class 30 looks one pair ahead, 22 / 24 continue, 9, 10 and 21 end with 0x10
// and *out = p, other classes stop with 0); everything else stops with *out = p, 0; empty input returns -1
extern "C" s32 fn_6296a0(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -1;
  u32 c = cls_le(base, p) - 0x14;
  if (c > 7) {
    *out = p;
    return 0;
  }
  static const u8 t1[8] = {1, 0, 2, 0, 2, 0, 0, 3};
  switch (t1[c]) {
    case 1: *out = p + 2; return 0x21;
    case 3: return ext_629580(base, p + 2, end, out);
    case 2: break;
    default: *out = p; return 0;
  }
  static const u8 map1[22] = {0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 1, 3, 1, 3, 3, 3, 3, 3, 2};
  static const u8 map2[22] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
  p += 2;
  for (;;) {
    if (p == end) return -1;
    u32 c2 = cls_le(base, p) - 9;
    if (c2 > 0x15) {
      *out = p;
      return 0;
    }
    switch (map1[c2]) {
      case 0: *out = p; return 0x10;
      case 1:
        p += 2;
        if (p == end) return -1;
        break;
      case 3: *out = p; return 0;
      default: {
        u8 *nx = p + 2;
        if (nx == end) return -1;
        u32 c3 = cls_le(base, nx) - 9;
        if (c3 <= 0x15 && map2[c3] == 0) {
          *out = p;
          return 0;
        }
        *out = p;
        return 0x10;
      }
    }
  }
}
PCREG(6296a0, fn_6296a0);
