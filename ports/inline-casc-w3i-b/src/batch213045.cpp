#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);
extern "C" s32 ext_628630(u8 *base, u8 *p, u8 *end, u8 **out);
extern "C" s32 ext_627fd0(u8 *base, u8 *p, u8 *end, u8 **out);

static inline u32 cls_be(u8 *base, const u8 *p) {
  if (p[0] == 0) return base[0x4c + p[1]];
  return ext_62c640(p[0], p[1]);
}

// 0x626310: cdecl(base, p, end, out): wide ((lead, second) pairs) tokenizer: class 3 as the first pair hands over to 0x628630(base, p+2, ...),
// class 30 to 0x627fd0 (result 0x16 becomes 0), class 10 returns 7 with *out past it, class 9 (CR, a following class 10 absorbed, -3 at the very end) returns 7;
// classes 6 and 7 are 3 and 4 bytes wide, everything else 2; later pairs of the special classes end the run with 6; empty input -4
extern "C" s32 fn_626310(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -4;
  u8 *start = p;
  u8 *cur = p;
  static const u8 map[28] = {0, 7, 1, 2, 3, 7, 4, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6};
  for (;;) {
    u32 c = cls_be(base, cur) - 3;
    u32 m = c > 0x1b ? 7 : map[c];
    u8 *prev = cur;
    switch (m) {
      case 0:
        if (cur != start) goto run_end;
        return ext_628630(base, cur + 2, end, out);
      case 6: {
        if (cur != start) goto run_end;
        s32 r = ext_627fd0(base, cur + 2, end, out);
        return r == 0x16 ? 0 : r;
      }
      case 5:
        if (cur != start) goto run_end;
        *out = cur + 2;
        return 7;
      case 4:
        if (cur != start) goto run_end;
        cur += 2;
        if (cur == end) return -3;
        if (cls_be(base, cur) != 0xa) cur = prev;
        *out = cur + 2;
        return 7;
      case 2: cur += 3; break;
      case 3: cur += 4; break;
      default: cur += 2; break;
    }
    if (cur == end) goto run_end;
  }
run_end:
  *out = cur;
  return 6;
}
PCREG(626310, fn_626310);
