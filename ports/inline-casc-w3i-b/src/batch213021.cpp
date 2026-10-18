#include "ff.h"

// class of the (lo, hi) pair at p: hi == 0 -> base[0x4c + lo]; else the 0xd8.. lead byte map on hi (0x62c640's table) with lo as second byte
static inline u32 cls_swapped(u8 *base, u8 *p) {
  u32 hi = p[1];
  if (hi == 0) return base[0x4c + p[0]];
  u32 i = hi - 0xd8;
  if (i > 0x27) return 0x1d;
  static const u8 m1[40] = {0, 0, 0, 0, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2};
  switch (m1[i]) {
    case 0: return 7;
    case 1: return 8;
    case 2: return p[0] < 0xfe ? 0x1d : 0;
    default: return 0x1d;
  }
}

// 0x625cc0: cdecl(base, p, end, st): byte-swapped twin of 0x622ef0 (pairs are (lo, hi)); returns the last class-derived eax
extern "C" u32 fn_625cc0(u8 *base, u8 *p, u8 *end, volatile s32 *st) {
  if (p == end) return 0;
  s32 col = st[1];
  u32 ret = 0;
  do {
    u32 c = cls_swapped(base, p) - 5;
    ret = c;
    if (c > 5) {
      p += 2;
    } else {
      switch (c) {
        case 1: p += 3; break;
        case 2: p += 4; break;
        case 4:
          st[0] = st[0] + 1;
          p += 2;
          if (p != end) {
            ret = cls_swapped(base, p);
            if (ret == 0xa) p += 2;
          }
          col = -1;
          st[1] = -1;
          break;
        case 5:
          col = -1;
          st[1] = -1;
          st[0] = st[0] + 1;
          p += 2;
          break;
        default: p += 2; break;
      }
    }
    col++;
    st[1] = col;
  } while (p != end);
  return ret;
}
PCREG(625cc0, fn_625cc0);
