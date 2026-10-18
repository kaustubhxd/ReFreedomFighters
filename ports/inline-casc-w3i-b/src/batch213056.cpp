#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);

template <bool LE>
static inline u32 cls_w(u8 *base, const u8 *p) {
  u32 lead = LE ? p[1] : p[0];
  u32 second = LE ? p[0] : p[1];
  if (lead == 0) return base[0x4c + second];
  return ext_62c640(lead, second);
}

template <bool LE>
static inline bool is_ch(const u8 *p, u8 ch) {
  return LE ? (p[1] == 0 && p[0] == ch) : (p[0] == 0 && p[1] == ch);
}

// 0x622080 (BE pairs) and 0x624980 (LE pairs): cdecl(base, p, end, out): wide-character scanner for the end of a "]]>" terminated section (classes are the raw
// table values 0..10): the first pair decides: class 0, 1, 8 stop (*out = p, 0), 2, 3 skip, 4 ("]") followed by "]" and ">" returns 0x28 with *out past
// the ">", 5, 6, 7 are 2, 3, 4 bytes wide (-2 when cut off), 9 (CR, absorbing a class 10 follower) and 10 return 7 with *out past them, 0xb and above skip;
// the following pairs run through a loop that ends with 6 and *out = p at classes 0, 1, 4, 8, 9, 10, at the end of input, or when a wide character is cut off;
// an odd length is rounded down to a pair boundary (empty after that: -1), an empty input is -4, reaching the end in the first stage -1
template <bool LE>
static s32 scan_cdata_end(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -4;
  s32 diff = (s32)(end - p);
  u8 *start = p;
  if (diff & 1) {
    s32 even = diff & ~1;
    if (even == 0) return -1;
    end = p + even;
  }
  u8 *cur = p;
  u32 c = cls_w<LE>(base, cur);
  u32 m = c > 10 ? 2 : c;
  static const u8 map[11] = {0, 0, 4, 4, 0, 1, 2, 3, 0, 0, 0};
  switch (m) {
    case 0:
    case 1:
    case 8: *out = cur; return 0;
    case 2:
    case 3: cur += 2; break;
    case 4: {
      cur += 2;
      u8 *saved = cur;
      if (cur == end) return -1;
      if (is_ch<LE>(cur, 0x5d)) {
        cur += 2;
        if (cur == end) return -1;
        if (is_ch<LE>(cur, 0x3e)) {
          *out = cur + 2;
          return 0x28;
        }
        cur = saved;
      }
      break;
    }
    case 5:
      if ((s32)(end - cur) < 2) return -2;
      cur += 2;
      break;
    case 6:
      if ((s32)(end - cur) < 3) return -2;
      cur += 3;
      break;
    case 7:
      if ((s32)(end - cur) < 4) return -2;
      cur += 4;
      break;
    case 9: {
      cur += 2;
      if (cur == end) return -1;
      if (cls_w<LE>(base, cur) != 0xa) cur = start;
      *out = cur + 2;
      return 7;
    }
    default: *out = cur + 2; return 7;   // class 10
  }
  (void)map;
  for (;;) {
    if (cur == end) {
      *out = cur;
      return 6;
    }
    u32 c2 = cls_w<LE>(base, cur);
    u32 m2 = c2 > 10 ? 4 : map[c2];
    u32 w;
    switch (m2) {
      case 0: *out = cur; return 6;
      case 1:
        if ((s32)(end - cur) < 2) { *out = cur; return 6; }
        w = 2;
        break;
      case 2:
        if ((s32)(end - cur) < 3) { *out = cur; return 6; }
        w = 3;
        break;
      case 3:
        if ((s32)(end - cur) < 4) { *out = cur; return 6; }
        w = 4;
        break;
      default: w = 2; break;
    }
    cur += w;
  }
}

extern "C" s32 fn_622080(u8 *base, u8 *p, u8 *end, u8 **out) { return scan_cdata_end<false>(base, p, end, out); }
PCREG(622080, fn_622080);
extern "C" s32 fn_624980(u8 *base, u8 *p, u8 *end, u8 **out) { return scan_cdata_end<true>(base, p, end, out); }
PCREG(624980, fn_624980);
