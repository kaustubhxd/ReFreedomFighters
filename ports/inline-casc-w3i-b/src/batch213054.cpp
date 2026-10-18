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

// 0x6277b0 (BE pairs) and 0x629810 (LE pairs): cdecl(base, p, end, out): wide-character name scanner, fourth variant (name followed by optional white space):
// start = class 29 through the exe bitmap 0x6bfc20 or classes 22 / 24 (skipped); name characters: 22..27 skip, class 29 through the bitmap 0x6bfd20, classes 9, 10, 21
// start a white space run (classes 9, 10, 21 skipped, class 11 ends with 5 and *out = p + 2, others stop 0), class 11 ends the name with 5 and *out = p + 2;
// classes 5, 6, 7 are cut-off checks (-2, else stop 0); anything else stops with *out = p and 0; end of input returns -1
template <bool LE>
static s32 scan_name4(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -1;
  u32 lead, sec;
  u32 c = cls_w<LE>(base, p, &lead, &sec) - 5;
  static const u8 map1[25] = {0, 1, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 5, 3, 5, 5, 5, 5, 4};
  static const u8 map2[25] = {0, 1, 2, 7, 3, 3, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 5, 5, 5, 5, 5, 5, 7, 6};
  static const u8 map3[13] = {0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0};
  u32 m = c > 0x18 ? 5 : map1[c];
  switch (m) {
    case 0:
    case 1:
    case 2: {
      s32 need = m == 0 ? 2 : m == 1 ? 3 : 4;
      if ((s32)(end - p) >= need) goto stop;
      return -2;
    }
    case 3: break;
    case 4:
      if (!bitmap_hit(0x6bfc20, lead, sec)) goto stop;
      break;
    default: goto stop;
  }
  p += 2;
  if (p == end) return -1;
  for (;;) {
    u32 c2 = cls_w<LE>(base, p, &lead, &sec) - 5;
    u32 m2 = c2 > 0x18 ? 7 : map2[c2];
    switch (m2) {
      case 0:
      case 1:
      case 2: {
        s32 need = m2 == 0 ? 2 : m2 == 1 ? 3 : 4;
        if ((s32)(end - p) >= need) goto stop;
        return -2;
      }
      case 3:
        p += 2;
        if (p == end) return -1;
        for (;;) {
          u32 c3 = cls_w<LE>(base, p, &lead, &sec) - 9;
          u32 m3 = c3 > 0xc ? 2 : map3[c3];
          if (m3 == 1) {
            *out = p + 2;
            return 5;
          }
          if (m3 == 2) goto stop;
          p += 2;
          if (p == end) return -1;
        }
      case 4: *out = p + 2; return 5;
      case 5: break;
      case 6:
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

extern "C" s32 fn_6277b0(u8 *base, u8 *p, u8 *end, u8 **out) { return scan_name4<false>(base, p, end, out); }
PCREG(6277b0, fn_6277b0);
extern "C" s32 fn_629810(u8 *base, u8 *p, u8 *end, u8 **out) { return scan_name4<true>(base, p, end, out); }
PCREG(629810, fn_629810);
