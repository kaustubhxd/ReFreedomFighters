#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);
extern "C" s32 ext_62a690(u8 *base, u8 *p, u8 *end, u8 **out);
extern "C" s32 ext_628630(u8 *base, u8 *p, u8 *end, u8 **out);

template <bool LE>
static inline u32 cls_w(u8 *base, const u8 *p) {
  u32 lead = LE ? p[1] : p[0];
  u32 second = LE ? p[0] : p[1];
  if (lead == 0) return base[0x4c + second];
  return ext_62c640(lead, second);
}

// 0x623e40 (LE pairs) and 0x626050 (BE pairs): cdecl(base, p, end, out): wide-character tokenizer like 0x625df0 (classes counted from 2): class 2 stops
// (*out = p, 0), class 3 as the first pair hands over to 0x62a690 / 0x628630(base, p+2, end, out), classes 6 and 7 are 3 and 4 bytes wide, everything else 2,
// class 9 (CR, absorbing a class 10 follower; -3 at the very end), 10 and 21 (0x27) as the first pair return 7 / 7 / 0x27 with *out past them, else end the run
// with 6; empty input -4
template <bool LE>
static s32 tokenize(u8 *base, u8 *p, u8 *end, u8 **out, s32 (*nested)(u8 *, u8 *, u8 *, u8 **)) {
  if (p == end) return -4;
  u8 *start = p;
  u8 *cur = p;
  static const u8 map[20] = {0, 1, 8, 2, 3, 4, 8, 5, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7};
  for (;;) {
    u32 c = cls_w<LE>(base, cur) - 2;
    u32 m = c > 0x13 ? 8 : map[c];
    u8 *prev = cur;
    switch (m) {
      case 0: *out = cur; return 0;
      case 1:
        if (cur != start) goto run_end;
        return nested(base, cur + 2, end, out);
      case 5:
        if (cur != start) goto run_end;
        cur += 2;
        if (cur == end) return -3;
        if (cls_w<LE>(base, cur) != 0xa) cur = prev;
        cur += 2;
        *out = cur;
        return 7;
      case 6:
        if (cur != start) goto run_end;
        *out = cur + 2;
        return 7;
      case 7:
        if (cur != start) goto run_end;
        *out = cur + 2;
        return 0x27;
      case 3: cur += 3; break;
      case 4: cur += 4; break;
      default: cur += 2; break;
    }
    if (cur == end) goto run_end;
  }
run_end:
  *out = cur;
  return 6;
}

extern "C" s32 fn_623e40(u8 *base, u8 *p, u8 *end, u8 **out) { return tokenize<true>(base, p, end, out, ext_62a690); }
PCREG(623e40, fn_623e40);
extern "C" s32 fn_626050(u8 *base, u8 *p, u8 *end, u8 **out) { return tokenize<false>(base, p, end, out, ext_628630); }
PCREG(626050, fn_626050);
