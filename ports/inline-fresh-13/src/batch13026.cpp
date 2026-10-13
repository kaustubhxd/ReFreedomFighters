// batch13026.cpp - fresh slice 13, batch 26 (docs/20-fresh-13.md), 2026-10-12.
// 0x620910 GUESS stream/parser step of a C library (no name map entry; cdecl, function-pointer style): int f(state* s,
// a, b, c). Returns 0, 1 (allocation failure), 2 (parse failure), 0x13 (context mismatch) or the result of 0x61fbc0.
//  - r = parse(a, s+0x8c, b, c, &s->+0x118, &pa, &pb, &len, &ctx, &kind) with parse = 0x626dd0 when s+0xe8 is set,
//    else 0x626da0 (10 cdecl words). pb's slot is the caller's `s` argument word, so it starts as s. r == 0 -> 2.
//  - a == 0 and kind == 1: s+0x1c4 = 1 and s+0x26c goes 1 -> 0.
//  - With the callback s+0x88: len != 0 -> d1 = 0x620840(s+0x244, s+0x8c, len, len + (s+0x8c)->+0x20(s+0x8c, len))
//    (0 -> return 1; then s+0x254 = s+0x250); pa != 0 -> d2 = 0x620840(s+0x244, s+0x8c, pa, pb - (s+0x8c)->+0x44)
//    (0 -> return 1); then s+0x88(s+4, d2, d1, kind). Without it, s+0x50 set -> 0x620cb0(s, s+0x8c, b, c).
//  - s+0xe4 clear and ctx set: ctx+0x44 != (s+0x8c)+0x44 -> s+0x118 = len, return 0x13; else s+0x8c = ctx.
//    s+0xe4 clear, no ctx, len set: d1 made as above if not yet made (0 -> 1), r = 0x61fbc0(s, d1),
//    0x6204a0(s+0x22c), r == 0x12 -> s+0x118 = len; return r.
//  - Otherwise 0x6204a0(s+0x244) when d1 or d2 was made; return 0.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_626da0[], ext_626dd0[], ext_620840[], ext_620cb0[], ext_61fbc0[], ext_6204a0[];
typedef u32 (*Parse)(u32 a, u32 o, u32 b, u32 c, u32 *p118, u32 *pa, u32 *pb, u32 *len, u32 *ctx, u32 *kind);
typedef u32 (*F2)(u32 a, u32 b);
typedef u32 (*F4)(u32 a, u32 b, u32 c, u32 d);
typedef u32 (*F1)(u32 a);

static u32 mk(u8 *s, u32 len) {
  u8 *o = AT(u8 *, s, 0x8c);
  u32 n = ((F2)AT(u32, o, 0x20))((u32)o, len);
  return ((F4)(void *)ext_620840)((u32)(s + 0x244), AT(u32, s, 0x8c), len, n + len);
}

static u32 fn620910(u8 *s, u32 a, u32 b, u32 c) {
  u32 len = 0, kind = 0xffffffff, ctx = 0, pa = 0, pb = (u32)s;
  u32 d1 = 0, d2 = 0;
  Parse p = (Parse)(void *)(AT(u32, s, 0xe8) ? ext_626dd0 : ext_626da0);
  if (!p(a, AT(u32, s, 0x8c), b, c, (u32 *)(s + 0x118), &pa, &pb, &len, &ctx, &kind))
    return 2;
  if (a == 0 && kind == 1) {
    AT(u32, s, 0x1c4) = 1;
    if (AT(u32, s, 0x26c) == 1)
      AT(u32, s, 0x26c) = 0;
  }
  if (AT(u32, s, 0x88)) {
    if (len) {
      d1 = mk(s, len);
      if (!d1)
        return 1;
      AT(u32, s, 0x254) = AT(u32, s, 0x250);
    }
    if (pa) {
      u8 *o = AT(u8 *, s, 0x8c);
      d2 = ((F4)(void *)ext_620840)((u32)(s + 0x244), (u32)o, pa, pb - AT(u32, o, 0x44));
      if (!d2)
        return 1;
    }
    ((F4)AT(u32, s, 0x88))(AT(u32, s, 4), d2, d1, kind);
  } else if (AT(u32, s, 0x50)) {
    ((F4)(void *)ext_620cb0)((u32)s, AT(u32, s, 0x8c), b, c);
  }
  if (!AT(u32, s, 0xe4)) {
    if (ctx) {
      if (AT(u32, ctx, 0x44) != AT(u32, AT(u8 *, s, 0x8c), 0x44)) {
        AT(u32, s, 0x118) = len;
        return 0x13;
      }
      AT(u32, s, 0x8c) = ctx;
    } else if (len) {
      if (!d1) {
        d1 = mk(s, len);
        if (!d1)
          return 1;
      }
      u32 r = ((F2)(void *)ext_61fbc0)((u32)s, d1);
      ((F1)(void *)ext_6204a0)((u32)(s + 0x22c));
      if (r == 0x12)
        AT(u32, s, 0x118) = len;
      return r;
    }
  }
  if (d1 || d2)
    ((F1)(void *)ext_6204a0)((u32)(s + 0x244));
  return 0;
}
PCREG(620910, fn620910);
