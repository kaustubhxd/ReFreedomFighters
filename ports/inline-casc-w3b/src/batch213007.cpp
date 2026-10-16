#include "ff.h"

typedef u32(*CbFn)(void *, u32, u32, u32);

// 0x622ad0: cdecl(base, p, end, st): walks [p, end) by class (base[0x4c + byte]); st[0] counts lines, st[1] the column
extern "C" u8 *fn_622ad0(u8 *base, u8 *p, u8 *end, volatile s32 *st) {
  if (p == end) return p;
  s32 col = st[1];
  do {
    u32 c = (u32)base[0x4c + *p] - 5;
    if (c > 5) {
      p++;
    } else {
      switch (c) {
        case 0: p += 2; break;
        case 1: p += 3; break;
        case 2: p += 4; break;
        case 3: p++; break;
        case 4:
          st[0] = st[0] + 1;
          p++;
          if (p != end && base[0x4c + *p] == 0xa) p++;
          col = -1;
          st[1] = -1;
          break;
        default:
          col = -1;
          st[1] = -1;
          st[0] = st[0] + 1;
          p++;
          break;
      }
    }
    col++;
    st[1] = col;
  } while (p != end);
  return p;
}
PCREG(622ad0, fn_622ad0);

// 0x62e070: cdecl(a, b, c, d, e): parser step over b-0xb; case 1 calls e->[0x1c](e, c + 2 * e->[0x44], d, 0x6c0164)
extern "C" u32 fn_62e070(u32 *a, int b, u32 c, u32 d, u8 *e) {
  u32 i = (u32)b - 0xb;
  if (i <= 0x12) {
    static const u8 map[19] = {0, 3, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2};
    switch (map[i]) {
      case 0: return 0;
      case 1: {
        CbFn f = *(CbFn *)(e + 0x1c);
        if (f(e, c + *(u32 *)(e + 0x44) * 2, d, 0x6c0164)) {
          a[0] = 0x62cfe0;
          return 0;
        }
        break;
      }
      case 2: a[0] = 0x51f230; return 2;
      default: break;
    }
  }
  if (a[3] == 0 && b == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return 0xffffffffu;
}
PCREG(62e070, fn_62e070);
