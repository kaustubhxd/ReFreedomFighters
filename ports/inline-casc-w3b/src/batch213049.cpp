#include "ff.h"

typedef u32 (*Cb2)(u8 *, u8 *);
typedef u32 (*Cb4)(void *, u32, u32, u32);

// 0x6261b0: cdecl(base, p, end, out): single-byte scanner for the end of a nested "<![" ... "]]>" section (single-byte sibling of 0x624350): class table
// base[0x4c + byte]: class 2 ("<") followed by "!" and "[" raises a depth counter, class 4 ("]") followed by "]" and ">" lowers it (0x2a with *out past the
// ">" at depth 0), classes 5, 6, 7 are 2, 3, 4 bytes wide and ask the callback base->[0x164 / 0x168 / 0x16c](base, p) first (nonzero: *out = p, 0; -2 when cut
// off), classes 0, 1, 8 stop with *out = p and 0, others 1 byte; the end of input returns -1
extern "C" s32 fn_6261b0(u8 *base, u8 *p, u8 *end, u8 **out) {
  u32 depth = 0;
  if (p == end) return -1;
  s32 rem = (s32)(end - p);
  do {
    u32 c = base[0x4c + *p];
    u32 m = c > 8 ? 3 : c;
    switch (m) {
      case 0:
      case 1:
      case 8: *out = p; return 0;
      case 5:
      case 6:
      case 7: {
        s32 w = m - 3;
        if (rem < w) return -2;
        Cb2 f = *(Cb2 *)(base + (m == 5 ? 0x164 : m == 6 ? 0x168 : 0x16c));
        if (f(base, p)) {
          *out = p;
          return 0;
        }
        p += w;
        rem -= w;
        break;
      }
      case 2:
        p++;
        rem--;
        if (p == end) return -1;
        if (*p != 0x21) break;
        p++;
        rem--;
        if (p == end) return -1;
        if (*p != 0x5b) break;
        depth++;
        p++;
        rem--;
        break;
      case 4:
        p++;
        rem--;
        if (p == end) return -1;
        if (*p != 0x5d) break;
        p++;
        rem--;
        if (p == end) return -1;
        if (*p != 0x3e) break;
        p++;
        rem--;
        if (depth == 0) {
          *out = p;
          return 0x2a;
        }
        depth--;
        break;
      default:
        p++;
        rem--;
        break;
    }
  } while (p != end);
  return -1;
}
PCREG(6261b0, fn_6261b0);

// 0x62dc60: cdecl(a, b, c, d, e): parser step over b-0xb: b = 0xb, 0xd, 0xf -> 0, 0x10 -> four successive callbacks
// e->[0x1c](e, c + 2*e->[0x44], d, str) (strings 0x6c0188, 0x6c0154, 0x6c016c, 0x6c01e0) setting [a] to 0x62d790, 0x62c9d0, 0x62d260, 0x62ddb0 on the first hit;
// 0x1a -> [a] = 0x62d210; 0x1c -> 0x35; the fail path returns b+0x18 for b = 0x1c with [a+0xc] clear, else [a] = 0x51f230 and -1
extern "C" u32 fn_62dc60(u32 *a, int b, u32 c, u32 d, u8 *e) {
  u32 i = (u32)b - 0xb;
  if (i <= 0x11) {
    static const u8 map[18] = {0, 4, 0, 4, 0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 3};
    switch (map[i]) {
      case 0: return 0;
      case 1: {
        static const u32 strs[4] = {0x6c0188, 0x6c0154, 0x6c016c, 0x6c01e0};
        static const u32 st[4] = {0x62d790, 0x62c9d0, 0x62d260, 0x62ddb0};
        for (int k = 0; k < 4; k++) {
          Cb4 f = *(Cb4 *)(e + 0x1c);
          if (f(e, c + *(u32 *)(e + 0x44) * 2, d, strs[k])) {
            a[0] = st[k];
            return 0;
          }
        }
        break;
      }
      case 2: a[0] = 0x62d210; return 0;
      case 3: return 0x35;
      default: break;
    }
  }
  if (a[3] == 0 && b == 0x1c) return (u32)b + 0x18;
  a[0] = 0x51f230;
  return 0xffffffffu;
}
PCREG(62dc60, fn_62dc60);
