// batch66042.cpp - cascade s4 batch 66042: 0x6252a0 (tier F row).
#include "ff.h"

// 0x6252a0, cdecl(unused, begin, end), returns the entity code: n = (end - begin) / 2 (signed, rounded toward zero) UTF-16LE characters.
// n == 2: g 00 t 00? -> bytes [g|l] 00 't' 00 -> 'g' 0x3e, 'l' 0x3c. n == 3: 'a' 00 'm' 00 'p' 00 -> 0x26. n == 4: 'a' 00 'p' 00 'o' 00 's' 00 -> 0x27, 'q' 00 'u' 00 'o' 00 't' 00 -> 0x22. Otherwise 0.
extern "C" s32 fn6252a0(u32 unused, const s8 *p, const s8 *end) {
  s32 d = (s32)(end - p);
  s32 n = (d - (d >> 31)) >> 1;
  if (n == 2) {
    if (p[3] == 0 && p[2] == 0x74 && p[1] == 0) {
      if (p[0] == 0x67) return 0x3e;
      if (p[0] == 0x6c) return 0x3c;
    }
    return 0;
  }
  if (n == 3) {
    if (p[1] == 0 && p[0] == 0x61 && p[3] == 0 && p[2] == 0x6d && p[5] == 0 && p[4] == 0x70) return 0x26;
    return 0;
  }
  if (n == 4) {
    if (p[1] != 0) return 0;
    if (p[0] == 0x61) {
      if (p[3] == 0 && p[2] == 0x70 && p[5] == 0 && p[4] == 0x6f && p[7] == 0 && p[6] == 0x73) return 0x27;
      return 0;
    }
    if (p[0] == 0x71) {
      if (p[3] == 0 && p[2] == 0x75 && p[5] == 0 && p[4] == 0x6f && p[7] == 0 && p[6] == 0x74) return 0x22;
    }
    return 0;
  }
  return 0;
}
PCREG(6252a0, fn6252a0);
