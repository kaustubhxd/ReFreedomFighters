// batch38044.cpp - cascade s8 batch 38044: 0x626b00 (build a 256-entry character class table from a mapping).
#include "ff.h"

extern "C" u32 ext_626e10(s32 code, u8 *out);   // cdecl, result in AL

#define IMG8(a) (*(u8 *)(a))
#define IMG32(a) (*(u32 *)(a))

// 0x626b00, cdecl(dst, map, a, b) -> dst or 0. Copies the 0x170-byte template at 0x6bf2a8 into dst, checks that the first 128 entries of map are the identity wherever the class table 0x6bf2f4 says
// the byte is a plain character (neither 0 nor 0x1c), then classifies each of the 256 map entries: -1 = unmapped (class 1), -2..-4 = special (class 3 - v), 0..0x7f = ASCII mapping (class from the
// table, must be the identity or a 0/0x1c class), 0xd800..0xdfff / 0xfffe / 0xffff / (high byte 0 with class 0) = invalid (class 0), others up to 0xffff are looked up in the two bit tables
// (0x6bf720 selected by 0x6bfc20 / 0x6bfd20 per high byte) giving class 0x16 / 0x1a / 0x1c and the width from 0x626e10. dst gets per-entry class bytes (+0x4c), u16 codes (+0x178) and 4-byte records
// (+0x378), the two settings a / b (+0x170 / +0x174) and, when a != 0, the three triples of handler pointers at +0x14c..+0x16c and the common handlers +0x3c / +0x40. Anything out of range returns 0.
static u8 *fn626b00(u8 *dst, s32 *map, u32 a, u32 b) {
  for (int i = 0; i < 0x170; i++) dst[i] = IMG8(0x6bf2a8 + i);
  for (int i = 0; i < 0x80; i++) {
    u8 cl = IMG8(0x6bf2f4 + i);
    if (cl != 0x1c && cl != 0 && map[i] != i) return 0;
  }
  u16 *p16 = (u16 *)(dst + 0x178);
  u8 *tb = dst + 0x378;
  for (s32 i = 0; i < 0x100; i++, p16++, tb += 4) {
    s32 v = map[i];
    if (v == -1) {
      dst[0x4c + i] = 1;
      *p16 = 0xffff;
      *(u16 *)tb = 1;
      continue;
    }
    if (v < 0) {
      if (v < -4) return 0;
      dst[0x4c + i] = (u8)(3 - (u8)v);
      tb[0] = 0;
      *p16 = 0;
      continue;
    }
    if (v < 0x80) {
      u8 al = IMG8(0x6bf2f4 + v);
      if (al != 0x1c && al != 0 && v != i) return 0;
      dst[0x4c + i] = al;
      tb[1] = (u8)v;
      *p16 = v == 0 ? 0xffff : (u16)v;
      tb[0] = 1;
      continue;
    }
    s32 hi = v >> 8;
    bool invalid = false, check = true;
    if (hi > 0xdf) {
      if (hi != 0xff) check = true;
      else if (v == 0xfffe) invalid = true;
      else if (v != 0xffff) check = true;
      else invalid = true;
    } else if (hi >= 0xd8) {
      invalid = true;
    } else if (hi == 0) {
      if (IMG8(0x6bf2f4 + v) == 0) invalid = true;
    }
    if (invalid) {
      dst[0x4c + i] = 0;
      *p16 = 0xffff;
      *(u16 *)tb = 1;
      continue;
    }
    (void)check;
    if (v > 0xffff) return 0;
    u32 col = (u32)(v >> 5) & 7;
    u32 mask = 1u << (v & 0x1f);
    u32 row = IMG8(0x6bfc20 + hi);
    if (IMG32(0x6bf720 + (col + row * 8) * 4) & mask) {
      dst[0x4c + i] = 0x16;
    } else {
      u32 row2 = IMG8(0x6bfd20 + hi);
      bool z = (IMG32(0x6bf720 + (col + row2 * 8) * 4) & mask) == 0;
      dst[0x4c + i] = (u8)(z * 2 + 0x1a);
    }
    u8 r = (u8)ext_626e10(v, tb + 1);
    tb[0] = r;
    *p16 = (u16)v;
  }
  *(u32 *)(dst + 0x174) = b;
  *(u32 *)(dst + 0x170) = a;
  if (a != 0) {
    *(u32 *)(dst + 0x14c) = 0x62c730;
    *(u32 *)(dst + 0x150) = 0x62c730;
    *(u32 *)(dst + 0x154) = 0x62c730;
    *(u32 *)(dst + 0x158) = 0x62c790;
    *(u32 *)(dst + 0x15c) = 0x62c790;
    *(u32 *)(dst + 0x160) = 0x62c790;
    *(u32 *)(dst + 0x164) = 0x62c6c0;
    *(u32 *)(dst + 0x168) = 0x62c6c0;
    *(u32 *)(dst + 0x16c) = 0x62c6c0;
  }
  *(u32 *)(dst + 0x3c) = 0x62c860;
  *(u32 *)(dst + 0x40) = 0x62c7f0;
  return dst;
}
PCREG(626b00, fn626b00);
