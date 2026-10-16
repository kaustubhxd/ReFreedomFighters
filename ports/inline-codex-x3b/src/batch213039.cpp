#include "ff.h"

extern "C" s32 ext_62c060(u8 *base, u8 *p, u8 *end, u8 **out);

// 0x625df0: cdecl(base, p, end, out): single-byte tokenizer by class table base[0x4c + byte]: classes 5, 6, 7 are 2, 3, 4 bytes wide, 3 starts a
// nested token (0x62c060 when first, else ends the run with 6), 2 stops (*out = p, 0), 9 / 10 / 21 are line-break like (7, 7, 0x27) when first, else
// end the run with 6; reaching the end returns 6, an empty input -4, a lone class 9 at the very end -3
extern "C" s32 fn_625df0(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -4;
  u8 *start = p;
  u8 *cur = p;
  static const u8 map[20] = {0, 1, 8, 2, 3, 4, 8, 5, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7};
  for (;;) {
    u32 c = (u32)base[0x4c + *cur] - 2;
    u32 m = c > 0x13 ? 8 : map[c];
    u8 *prev = cur;
    switch (m) {
      case 0: *out = cur; return 0;
      case 1:
        if (cur != start) goto run_end;
        return ext_62c060(base, cur + 1, end, out);
      case 5:
        if (cur != start) goto run_end;
        cur++;
        if (cur == end) return -3;
        if (base[0x4c + *cur] != 0xa) cur = prev;
        cur++;
        *out = cur;
        return 7;
      case 6:
        if (cur != start) goto run_end;
        cur++;
        *out = cur;
        return 7;
      case 7:
        if (cur != start) goto run_end;
        cur++;
        *out = cur;
        return 0x27;
      case 2: cur += 2; break;
      case 3: cur += 3; break;
      case 4: cur += 4; break;
      default: cur += 1; break;
    }
    if (cur == end) goto run_end;
  }
run_end:
  *out = cur;
  return 6;
}
PCREG(625df0, fn_625df0);
