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

// 0x628470 (BE pairs) and 0x62a4d0 (LE pairs): cdecl(base, p, end, out): scans a wide-character name: the first pair must be a name start (class 29 through the
// exe bitmap at 0x6bf720 indexed by 0x6bfc20, or classes 22 and 24), later pairs are name characters (classes 24..27 and 22 continue, class 29 through the
// bitmap indexed by 0x6bfd20, classes 9..11, 21, 30, 32, 36 end the name with 0x14 and *out = p, classes 5, 6, 7 are cut-off checks (-2 when too short, else a
// stop with 0), anything else stops with 0); running out of input right after a name start returns -20
template <bool LE>
static s32 scan_name(u8 *base, u8 *p, u8 *end, u8 **out) {
  if (p == end) return -1;
  u32 lead, sec;
  u32 c = cls_w<LE>(base, p, &lead, &sec) - 5;
  static const u8 map1[25] = {0, 1, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 5, 3, 5, 5, 5, 5, 4};
  static const u8 map2[32] = {0, 1, 2, 6, 3, 3, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4, 6, 4, 4, 4, 4, 6, 5, 3, 6, 3, 6, 6, 6, 3};
  u32 m = c > 0x18 ? 5 : map1[c];
  switch (m) {
    case 0:
    case 1:
    case 2: {
      s32 need = m == 0 ? 2 : m == 1 ? 3 : 4;
      if ((s32)(end - p) >= need) goto stop;
      return -2;
    }
    case 4:
      if (!bitmap_hit(0x6bfc20, lead, sec)) goto stop;
      break;
    case 3: break;
    default: goto stop;
  }
  p += 2;
  if (p == end) return -20;
  for (;;) {
    u32 c2 = cls_w<LE>(base, p, &lead, &sec) - 5;
    u32 m2 = c2 > 0x1f ? 6 : map2[c2];
    switch (m2) {
      case 0:
      case 1:
      case 2: {
        s32 need = m2 == 0 ? 2 : m2 == 1 ? 3 : 4;
        if ((s32)(end - p) >= need) goto stop;
        return -2;
      }
      case 3: *out = p; return 0x14;
      case 4: break;
      case 5:
        if (!bitmap_hit(0x6bfd20, lead, sec)) goto stop;
        break;
      default: goto stop;
    }
    p += 2;
    if (p == end) return -20;
  }
stop:
  *out = p;
  return 0;
}

extern "C" s32 fn_628470(u8 *base, u8 *p, u8 *end, u8 **out) { return scan_name<false>(base, p, end, out); }
PCREG(628470, fn_628470);
extern "C" s32 fn_62a4d0(u8 *base, u8 *p, u8 *end, u8 **out) { return scan_name<true>(base, p, end, out); }
PCREG(62a4d0, fn_62a4d0);
