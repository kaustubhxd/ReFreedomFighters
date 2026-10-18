#include "ff.h"

// 0x622310: cdecl(base, a, b): compares two strings whose characters are 1..4 bytes wide (width by the class table base[0x4c + lead]);
// returns 1 when equal up to the first narrow terminator class, else 0
extern "C" u32 fn_622310(u8 *base, u8 *a, u8 *b) {
  static const u8 map1[25] = {0, 1, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 4, 3};
  static const u8 map2[25] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0};
  for (;;) {
    u32 c = (u32)base[0x4c + *a] - 5;
    if (c > 0x18) break;
    u32 m = map1[c];
    if (m == 4) break;
    u32 w = m == 0 ? 2 : m == 1 ? 3 : m == 2 ? 4 : 1;
    for (u32 k = 0; k < w; k++)
      if (a[k] != b[k]) return 0;
    a += w;
    b += w;
  }
  if (*a == *b) return 1;
  u32 c = (u32)base[0x4c + *b] - 5;
  if (c > 0x18) return 1;
  return map2[c] ? 1 : 0;
}
PCREG(622310, fn_622310);
