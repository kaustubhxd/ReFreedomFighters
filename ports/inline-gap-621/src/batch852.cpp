// batch852.cpp - gap band numeric character reference parser (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x622410: cdecl(unused, p) - parses the digits of an XML-style numeric reference ("&#...;" without the leading 2 units: p + 4 is the first
// unit after "&#"), big-endian 16-bit units (high byte at +0). A unit "x" (0x00 0x78) first selects hex. Each step: unit with high byte 0
// and low byte ';' ends; the value is the low byte as a signed digit char (-1 when the high byte is not 0). Decimal: v = v*10 + c - '0';
// a v >= 0x110000 returns -1. Hex: digits 0-9 (v = v*16 | d), 'A'-'F' (+ c - 0x37), 'a'-'f' (+ c - 0x57); every other unit is skipped
// without changing v. A finished value is -1 when it is a surrogate (0xd800..0xdfff), 0xfffe, 0xffff, or below 0x100 with a zero entry in the
// table at 0x6bf2f4; otherwise returned as is.
static s32 __attribute__((cdecl)) parseCharRef_622410(u32 unused, const u8 *p0) {
  (void)unused;
  const u8 *p = p0 + 4;
  s32 v = 0;
  s32 c;
  if (p[0] == 0 && p[1] == 0x78) {
    for (;;) {
      p += 2;
      if (p[0] == 0) {
        if (p[1] == 0x3b) goto done;
        c = (s8)p[1];
      } else {
        c = -1;
      }
      u32 d = (u32)(c - 0x30);
      if (d <= 0x36) {
        u32 k = d <= 9 ? 0 : (d >= 0x11 && d <= 0x16) ? 1 : (d >= 0x31 && d <= 0x36) ? 2 : 3;
        if (k == 0) v = (s32)(((u32)v << 4) | d);
        else if (k == 1) v = (s32)(((u32)v << 4) - 0x37 + (u32)c);
        else if (k == 2) v = (s32)(((u32)v << 4) - 0x57 + (u32)c);
      }
      if (v >= 0x110000) return -1;
    }
  } else {
    for (;;) {
      if (p[0] == 0) {
        if (p[1] == 0x3b) goto done;
        c = (s8)p[1];
      } else {
        c = -1;
      }
      v = c + (v * 5 - 0x18) * 2;
      if (v >= 0x110000) return -1;
      p += 2;
    }
  }
done:
  s32 hi = v >> 8;
  if (hi > 0xdf) {
    if (hi != 0xff) return v;
    if (v == 0xfffe || v == 0xffff) v = -1;
    return v;
  }
  if (hi >= 0xd8) return -1;
  if (hi != 0) return v;
  if (*(u8 *)(0x6bf2f4 + (u32)v) != 0) return v;
  return -1;
}
PCREG(622410, parseCharRef_622410);

extern "C" u32 __attribute__((cdecl)) ext_62c640(u32 hi, u32 lo);   // real callee: unit classifier

static inline u32 unitClassLE(const u8 *cvt, const u8 *p) {
  return p[1] == 0 ? (u32)cvt[0x4c + p[0]] : ext_62c640(p[1], p[0]);
}

// 0x6253b0: cdecl(cvt, s1, s2) -> 0 or 1 - little-endian unit-class prefix compare (the 0x622310 relation, with the byte-wise classes:
// class - 5: 0 -> 2 bytes, 1 -> 3, 2 -> 4, 17..22 and 24 -> 2; any other class ends the walk). At the end the class of the unit at s2 decides:
// out of range (> 0x18) or an ending class (3..16, 23) gives 1, a stepping class gives 0.
static u32 __attribute__((cdecl)) matchPrefixLE_6253b0(const u8 *cvt, const u8 *s1, const u8 *s2) {
  for (;;) {
    u32 k = unitClassLE(cvt, s1) - 5;
    u32 n = 0;
    if (k <= 0x18) {
      if (k == 0) n = 2;
      else if (k == 1) n = 3;
      else if (k == 2) n = 4;
      else if ((k >= 17 && k <= 22) || k == 24) n = 2;
    }
    if (!n) break;
    for (u32 j = 0; j < n; j++)
      if (s1[j] != s2[j]) return 0;
    s1 += n;
    s2 += n;
  }
  u32 k2 = unitClassLE(cvt, s2) - 5;
  if (k2 > 0x18) return 1;
  return (k2 >= 3 && k2 <= 16) || k2 == 23 ? 1 : 0;
}
PCREG(6253b0, matchPrefixLE_6253b0);

// 0x624b70: cdecl(unused, p) - the little-endian twin of 0x622410: units are (lo = p[0], hi = p[1]); everything else is the same (hex jump table 0x624c50 / 0x624c60 identical).
static s32 __attribute__((cdecl)) parseCharRefLE_624b70(u32 unused, const u8 *p0) {
  (void)unused;
  const u8 *p = p0 + 4;
  s32 v = 0;
  s32 c;
  if (p[1] == 0 && p[0] == 0x78) {
    for (;;) {
      p += 2;
      if (p[1] == 0) {
        if (p[0] == 0x3b) goto done;
        c = (s8)p[0];
      } else {
        c = -1;
      }
      u32 d = (u32)(c - 0x30);
      if (d <= 0x36) {
        u32 k = d <= 9 ? 0 : (d >= 0x11 && d <= 0x16) ? 1 : (d >= 0x31 && d <= 0x36) ? 2 : 3;
        if (k == 0) v = (s32)(((u32)v << 4) | d);
        else if (k == 1) v = (s32)(((u32)v << 4) - 0x37 + (u32)c);
        else if (k == 2) v = (s32)(((u32)v << 4) - 0x57 + (u32)c);
      }
      if (v >= 0x110000) return -1;
    }
  } else {
    for (;;) {
      if (p[1] == 0) {
        if (p[0] == 0x3b) goto done;
        c = (s8)p[0];
      } else {
        c = -1;
      }
      v = c + (v * 5 - 0x18) * 2;
      if (v >= 0x110000) return -1;
      p += 2;
    }
  }
done:
  s32 hi = v >> 8;
  if (hi > 0xdf) {
    if (hi != 0xff) return v;
    if (v == 0xfffe || v == 0xffff) v = -1;
    return v;
  }
  if (hi >= 0xd8) return -1;
  if (hi != 0) return v;
  if (*(u8 *)(0x6bf2f4 + (u32)v) != 0) return v;
  return -1;
}
PCREG(624b70, parseCharRefLE_624b70);
