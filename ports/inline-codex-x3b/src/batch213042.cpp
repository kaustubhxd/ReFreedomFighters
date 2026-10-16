#include "ff.h"

extern "C" s32 ext_62c060(u8 *base, u8 *p, u8 *end, u8 **out);
extern "C" s32 ext_62b900(u8 *base, u8 *p, u8 *end, u8 **out);

// 0x625f20: cdecl(base, p, end, out): single-byte class tokenizer like 0x625df0 with different classes: 5, 6, 7 are 2, 3, 4 bytes wide;
// as the first byte class 3 hands over to 0x62c060, class 30 to 0x62b900 (result 0x16 becomes 0), class 10 returns 7 with *out past it,
// class 9 (CR with an absorbed class 10 follower, -3 at the very end) returns 7; later bytes end the run with 6; empty input -4
extern "C" s32 fn_625f20(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -4;
  u8 *start = p;
  u8 *cur = p;
  static const u8 map[28] = {0, 7, 1, 2, 3, 7, 4, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6};
  for (;;) {
    u32 c = (u32)base[0x4c + *cur] - 3;
    u32 m = c > 0x1b ? 7 : map[c];
    u8 *prev = cur;
    switch (m) {
      case 0:
        if (cur != start) goto run_end;
        return ext_62c060(base, cur + 1, end, out);
      case 4:
        if (cur != start) goto run_end;
        cur++;
        if (cur == end) return -3;
        if (base[0x4c + *cur] != 0xa) cur = prev;
        cur++;
        *out = cur;
        return 7;
      case 5:
        if (cur != start) goto run_end;
        cur++;
        *out = cur;
        return 7;
      case 6: {
        if (cur != start) goto run_end;
        s32 r = ext_62b900(base, cur + 1, end, out);
        return r == 0x16 ? 0 : r;
      }
      case 1: cur += 2; break;
      case 2: cur += 3; break;
      case 3: cur += 4; break;
      default: cur += 1; break;
    }
    if (cur == end) goto run_end;
  }
run_end:
  *out = cur;
  return 6;
}
PCREG(625f20, fn_625f20);
