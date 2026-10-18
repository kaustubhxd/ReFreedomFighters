#include "ff.h"

typedef u32(*CbFn2)(void *, u32, u32, u32);

// 0x62dfa0: cdecl(a, b, c, d, e): sibling of 0x62e070; parser step over b-0xb
extern "C" u32 fn_62dfa0(u32 *a, int b, u32 c, u32 d, u8 *e) {
  u32 i = (u32)b - 0xb;
  if (i <= 0x12) {
    static const u8 map[19] = {0, 1, 0, 2, 0, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4};
    switch (map[i]) {
      case 0: a[0] = 0x62e070; return 0;
      case 1: a[0] = 0x62e070; return 1;
      case 2: return 0;
      case 3: {
        CbFn2 f = *(CbFn2 *)(e + 0x1c);
        if (f(e, c + *(u32 *)(e + 0x44) * 2, d, 0x6c0164)) {
          a[0] = 0x62cfe0;
          return 0;
        }
        break;
      }
      case 4: a[0] = 0x51f230; return 2;
      default: break;
    }
  }
  if (a[3] == 0 && b == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return 0xffffffffu;
}
PCREG(62dfa0, fn_62dfa0);
