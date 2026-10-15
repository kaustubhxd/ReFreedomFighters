// batch66040.cpp - cascade s4 batch 66040: 0x622540 (tier F row).
#include "ff.h"

// 0x622540, cdecl(unused, begin, end), returns the entity code: n = (end - begin) / 2 (signed, rounded toward zero) UTF-16BE characters.
// n == 2: bytes 00 g 00 t -> 0x3e, 00 l 00 t -> 0x3c. n == 3: 00 a 00 m 00 p -> 0x26. n == 4: 00 a 00 p 00 o 00 s -> 0x27, 00 q 00 u 00 o 00 t -> 0x22. Otherwise 0.
extern "C" s32 fn622540(u32 unused, const s8 *p, const s8 *end) {
  s32 d = (s32)(end - p);
  s32 n = (d - (d >> 31)) >> 1;
  if (n == 2) {
    if (p[2] == 0 && p[3] == 0x74 && p[0] == 0) {
      if (p[1] == 0x67) return 0x3e;
      if (p[1] == 0x6c) return 0x3c;
    }
    return 0;
  }
  if (n == 3) {
    if (p[0] == 0 && p[1] == 0x61 && p[2] == 0 && p[3] == 0x6d && p[4] == 0 && p[5] == 0x70) return 0x26;
    return 0;
  }
  if (n == 4) {
    if (p[0] != 0) return 0;
    if (p[1] == 0x61) {
      if (p[2] == 0 && p[3] == 0x70 && p[4] == 0 && p[5] == 0x6f && p[6] == 0 && p[7] == 0x73) return 0x27;
      return 0;
    }
    if (p[1] == 0x71) {
      if (p[2] == 0 && p[3] == 0x75 && p[4] == 0 && p[5] == 0x6f && p[6] == 0 && p[7] == 0x74) return 0x22;
    }
    return 0;
  }
  return 0;
}
PCREG(622540, fn622540);
