#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);

template <bool LE>
static inline bool is_ch(const u8 *p, u8 ch) {
  return LE ? (p[1] == 0 && p[0] == ch) : (p[0] == 0 && p[1] == ch);
}

template <bool LE>
static inline u32 cls_w(u8 *base, const u8 *p) {
  u32 lead = LE ? p[1] : p[0];
  u32 second = LE ? p[0] : p[1];
  if (lead == 0) return base[0x4c + second];
  return ext_62c640(lead, second);
}

// 0x624350 (LE pairs) and 0x626500 (BE pairs): cdecl(base, p, end, out): scans wide-character text for the end of a nested "<![ ... ]]>" section:
// class 2 ("<") followed by "!" and "[" raises the depth, class 4 ("]") followed by "]" and ">" lowers it (at depth 0 it returns 0x2a with *out past
// the ">"), classes 5, 6, 7 are 2, 3, 4 bytes wide (-2 when cut off), classes 0, 1, 8 stop with *out = p and 0, others are 2 bytes; the end of the input
// returns -1 (an odd length is rounded down to a pair boundary)
template <bool LE>
static s32 scan_cdata(u8 *base, u8 *p, u8 *end, u8 **out) {
  u32 depth = 0;
  s32 diff = (s32)(end - p);
  if (diff & 1) end = p + (diff & ~1);
  if (p == end) return -1;
  s32 rem = (s32)(end - p);
  for (;;) {
    u32 c = cls_w<LE>(base, p);
    u32 m = c > 8 ? 3 : c;
    switch (m) {
      case 0:
      case 1:
      case 8: *out = p; return 0;
      case 5:
        if (rem < 2) return -2;
        p += 2;
        rem -= 2;
        break;
      case 6:
        if (rem < 3) return -2;
        p += 3;
        rem -= 3;
        break;
      case 7:
        if (rem < 4) return -2;
        p += 4;
        rem -= 4;
        break;
      case 2:
        p += 2;
        rem -= 2;
        if (p == end) return -1;
        if (!is_ch<LE>(p, 0x21)) goto cont;
        p += 2;
        rem -= 2;
        if (p == end) return -1;
        if (!is_ch<LE>(p, 0x5b)) goto cont;
        depth++;
        p += 2;
        rem -= 2;
        break;
      case 4:
        p += 2;
        rem -= 2;
        if (p == end) return -1;
        if (!is_ch<LE>(p, 0x5d)) goto cont;
        p += 2;
        rem -= 2;
        if (p == end) return -1;
        if (!is_ch<LE>(p, 0x3e)) goto cont;
        p += 2;
        rem -= 2;
        if (depth == 0) {
          *out = p;
          return 0x2a;
        }
        depth--;
        goto cont;
      default:
        p += 2;
        rem -= 2;
        break;
    }
  cont:
    if (p == end) return -1;
  }
}

extern "C" s32 fn_624350(u8 *base, u8 *p, u8 *end, u8 **out) { return scan_cdata<true>(base, p, end, out); }
PCREG(624350, fn_624350);
extern "C" s32 fn_626500(u8 *base, u8 *p, u8 *end, u8 **out) { return scan_cdata<false>(base, p, end, out); }
PCREG(626500, fn_626500);
