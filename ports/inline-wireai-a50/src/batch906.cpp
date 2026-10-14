// batch906.cpp - gap band slice: 0x4209f0 [stdcall, two stack args (a, b; ret 8), returns a dword]. A bounded run scan over bytes:
// it returns the number of bytes scanned from a before the first position i where the run of equal bytes starting at i (counted up
// to 0x7fff bytes from a, and to b) is longer than 3. If a >= b it returns 0. Read in full (the body ends at 0x420a51).
#include "ff.h"

// 0x4209f0 (name GUESS "Scan4209f0").
static u32 STDCALL Scan4209f0(const u8 *a, const u8 *b) {
  if ((u32)a >= (u32)b) return 0;
  const u8 *lim = a + 0x7fff;
  const u8 *i = a;
  for (;;) {
    if ((u32)i >= (u32)lim) break;
    if ((u32)b > (u32)i) {
      u8 c = *i;
      const u8 *j = i + 1;
      const u8 *k = j;
      if (j != b) {
        for (;;) {
          if ((u32)k >= (u32)(j + 0x7ffe)) break;
          if (*k != c) break;
          k++;
          if (k == b) break;
        }
      }
      if ((u32)(k - i) > 3u) break;
    }
    i++;
    if (i == b) break;
  }
  return (u32)(i - a);
}
PCREG(4209f0, Scan4209f0);
