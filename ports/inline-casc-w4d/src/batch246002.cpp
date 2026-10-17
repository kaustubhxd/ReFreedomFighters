// batch246002.cpp - Sonnet-w4d, tier 6/7 hand ports (run 2).
#include "ff.h"
typedef u32(THISCALL *W4Fn1)(u32, u32);
typedef u32(THISCALL *W4Fn2)(u32, u32, u32);
static inline u32 w4vc1(u32 o, u32 slot, u32 a) { return ((W4Fn1)*(u32 *)(*(u32 *)o + slot))(o, a); }
extern "C" u32 THISCALL ext_43ad20_w4(u32, u32) __asm__("ext_43ad20");

// 0x43ae00: thiscall(out) ret 4, returns 1. Walks the iterator at this[0x1214] (vslot 0x4c reset, 0x5c next(&flag) -> node);
// for each node: if !node[0x10] sends {2, name copy, 0 at +0x80, 0 at +0xfc} via out vslot 0x10(buf, 0x100); then if node[0x22]
// clears it, else walks the inner iterator at node[0x19] (unaligned) calling 0x43ad20(elem-4, out) for each element whose first
// dword is 0. Finally sends an all-zero record.
extern "C" u32 THISCALL GUESS_43ae00(u32 self, u32 out) {
  u32 F, G;
  u8 T[0x100] __attribute__((aligned(4)));
  u32 it = *(u32 *)(self + 0x1214);
  if (it) {
    w4vc1(it, 0x4c, (u32)&F);
    u32 node = w4vc1(*(u32 *)(self + 0x1214), 0x5c, (u32)&F);
    while (F != 0) {
      if (*(u8 *)(node + 0x10) == 0) {
        const u8 *s = *(const u8 **)(node + 8);
        u32 two = 2;
        __builtin_memcpy(T, &two, 4);
        u32 i = 0;
        do { T[4 + i] = s[i]; } while (s[i++]);
        T[0x80] = 0;
        u32 z = 0;
        __builtin_memcpy(T + 0xfc, &z, 4);
        ((W4Fn2)*(u32 *)(*(u32 *)out + 0x10))(out, (u32)T, 0x100);
      }
      if (*(u8 *)(node + 0x22) != 0) {
        *(u8 *)(node + 0x22) = 0;
      } else {
        u32 in;
        __builtin_memcpy(&in, (u8 *)node + 0x19, 4);
        if (in) {
          w4vc1(in, 0x4c, (u32)&G);
          u32 e = w4vc1(in, 0x5c, (u32)&G);
          if (G != 0) {
            for (;;) {
              if (*(u32 *)e == 0) ext_43ad20_w4(e - 4, out);
              __builtin_memcpy(&in, (u8 *)node + 0x19, 4);
              e = w4vc1(in, 0x5c, (u32)&G);
              if (G == 0) break;
            }
          }
        }
      }
      node = w4vc1(*(u32 *)(self + 0x1214), 0x5c, (u32)&F);
    }
  }
  u32 z0 = 0;
  __builtin_memcpy(T, &z0, 4);
  T[4] = 0;
  T[0x80] = 0;
  __builtin_memcpy(T + 0xfc, &z0, 4);
  ((W4Fn2)*(u32 *)(*(u32 *)out + 0x10))(out, (u32)T, 0x100);
  return 1;
}
PCREG(43ae00, GUESS_43ae00);

// 0x621f60: cdecl(unused, s) -> int. Parses the numeric character reference body of "&#...;" starting at s+2: "x" + hex digits or
// decimal digits up to ';'. Over 0x10ffff -> -1; surrogates D800-DFFF, FFFE, FFFF and codes < 256 whose flag in the byte table at
// 0x6bf2f4 is 0 -> -1; otherwise the code point.
extern "C" s32 GUESS_621f60(u32 unused, const u8 *s) {
  (void)unused;
  s32 v = 0;
  const u8 *p = s + 2;
  u8 al = *p;
  if (al == 'x') {
    al = *++p;
    while (al != ';') {
      s32 c = (s8)al;
      u32 esi = (u32)(c - 0x30);
      if (esi <= 0x36) {
        if (esi <= 9) v = (s32)(((u32)v << 4) | esi);
        else if (esi >= 0x11 && esi <= 0x16) v = (s32)(((u32)v << 4) + (u32)-0x37 + (u32)c);
        else if (esi >= 0x31 && esi <= 0x36) v = (s32)(((u32)v << 4) + (u32)-0x57 + (u32)c);
      }
      if (v >= 0x110000) return -1;
      al = *++p;
    }
  } else if (al != ';') {
    do {
      v = (s32)((u32)(s8)al + (((u32)v * 5u - 0x18u) * 2u));
      if (v >= 0x110000) return -1;
      al = *++p;
    } while (al != ';');
  }
  s32 hi = v >> 8;
  if (hi > 0xdf) {
    if (hi != 0xff) return v;
    if (v == 0xfffe || v == 0xffff) return -1;
    return v;
  }
  if (hi >= 0xd8) return -1;
  if (hi != 0) return v;
  if (*(volatile u8 *)(0x6bf2f4 + v) == 0) return -1;
  return v;
}
PCREG(621f60, GUESS_621f60);
