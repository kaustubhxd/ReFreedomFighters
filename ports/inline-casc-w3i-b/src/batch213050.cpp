#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);

template <bool LE>
static inline u32 cls_w(u8 *base, const u8 *p, u32 *lead_out, u32 *sec_out) {
  u32 lead = LE ? p[1] : p[0];
  u32 second = LE ? p[0] : p[1];
  *lead_out = lead;
  *sec_out = second;
  if (lead == 0) return base[0x4c + second];
  return ext_62c640(lead, second);
}

static inline bool bitmap_hit(u32 table, u32 lead, u32 sec) {
  u32 blk = G(u8, table + lead);
  u32 idx = (sec >> 5) + blk * 8;
  return (G(u32, 0x6bf720 + idx * 4) & (1u << (sec & 31))) != 0;
}

// 0x627fd0 (BE pairs) and 0x62a030 (LE pairs): cdecl(base, p, end, out): wide-character name scanner like 0x628470 / 0x62a4d0 but ending differently: a name start is
// class 29 (bitmap 0x6bfc20) or 22 / 24 (skipped), classes 9, 10, 21, 30 as the first pair end with 0x16 (*out = p); later name characters are 22, 24..27 (skip),
// class 29 (bitmap 0x6bfd20), class 18 ends with 0x1c and *out = p + 2, classes 5, 6, 7 are cut-off checks (-2, else stop with 0), others stop with *out = p and 0;
// end of input returns -1
template <bool LE>
static s32 scan_name2(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -1;
  u32 lead, sec;
  u32 c = cls_w<LE>(base, p, &lead, &sec) - 5;
  static const u8 map1[26] = {0, 1, 2, 6, 3, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4, 6, 4, 6, 6, 6, 6, 5, 3};
  static const u8 map2[25] = {0, 1, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 6, 6, 6, 4, 6, 4, 4, 4, 4, 6, 5};
  u32 m = c > 0x19 ? 6 : map1[c];
  switch (m) {
    case 0:
    case 1:
    case 2: {
      s32 need = m == 0 ? 2 : m == 1 ? 3 : 4;
      if ((s32)(end - p) >= need) goto stop;
      return -2;
    }
    case 3: *out = p; return 0x16;
    case 4: break;
    case 5:
      if (!bitmap_hit(0x6bfc20, lead, sec)) goto stop;
      break;
    default: goto stop;
  }
  p += 2;
  if (p == end) return -1;
  for (;;) {
    u32 c2 = cls_w<LE>(base, p, &lead, &sec) - 5;
    u32 m2 = c2 > 0x18 ? 6 : map2[c2];
    switch (m2) {
      case 0:
      case 1:
      case 2: {
        s32 need = m2 == 0 ? 2 : m2 == 1 ? 3 : 4;
        if ((s32)(end - p) >= need) goto stop;
        return -2;
      }
      case 3: *out = p + 2; return 0x1c;
      case 4: break;
      case 5:
        if (!bitmap_hit(0x6bfd20, lead, sec)) goto stop;
        break;
      default: goto stop;
    }
    p += 2;
    if (p == end) return -1;
  }
stop:
  *out = p;
  return 0;
}

extern "C" s32 fn_627fd0(u8 *base, u8 *p, u8 *end, u8 **out) { return scan_name2<false>(base, p, end, out); }
PCREG(627fd0, fn_627fd0);
extern "C" s32 fn_62a030(u8 *base, u8 *p, u8 *end, u8 **out) { return scan_name2<true>(base, p, end, out); }
PCREG(62a030, fn_62a030);
