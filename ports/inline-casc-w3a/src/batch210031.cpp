// batch210031.cpp - Sonnet-w3a: small BLOCKED rows (class scanner with tail call, reverse search with register-arg compare, message handler)
#include "ff.h"

extern "C" u32 ext_62b290(const u8 *base, const u8 *p, const u8 *end, const u8 **out);
extern "C" u32 FASTCALL ext_4cc4b0(u32 cl, u32 dl);
extern "C" u32 THISCALL ext_4f9680(u8 *self, u32 a);

static u32 fn62ad60(const u8 *base, const u8 *p, const u8 *end, const u8 **out) {
  if (p == end) return 0xffffffffu;  // @62ad60_a
  u8 c = *p;
  if (c == 0x78) return ext_62b290(base, p + 1, end, out);  // @62ad60_b
  if (base[0x4c + c] != 0x19) {  // @62ad60_c
    *out = p;
    return 0;
  }
  p++;
  while (p != end) {  // @62ad60_d
    u8 k = base[0x4c + *p];
    if (k == 0x12) {  // @62ad60_e
      *out = p + 1;
      return 10;  // @62ad60_f
    }
    if (k != 0x19) {
      *out = p;
      return 0;
    }
    p++;
  }
  return 0xffffffffu;
}
PCREG(62ad60, fn62ad60);

static u32 *FASTCALL fn5f1050(u32 *out, const u8 *s, const u8 *p, const u8 *pend, const u8 *end, u32 unused) {
  (void)unused;
  if (p != pend) {  // @5f1050_a
    do {
      const u8 *q = s;
      while (q != end) {
        u32 al = ext_4cc4b0(p[-1], *q) & 0xff;  // @5f1050_b
        if (al) {  // @5f1050_c
          *out = (u32)p;
          return out;
        }
        q++;
      }
      p--;  // @5f1050_d
    } while (p != pend);
  }
  *out = (u32)pend;  // @5f1050_e
  return out;
}
PCREG(5f1050, fn5f1050);

static u32 THISCALL fn562d90(u8 *self, u32 a) {
  u32 r = vcall<u32>(self, 0xd8);  // @562d90_a
  if (r & 0xff) return r & ~0xffu;  // @562d90_b
  r = a;
  if (a == 0x105) {  // @562d90_c
    if (self[0x87] == 0) return r & ~0xffu;  // @562d90_d
    ext_4f9680((u8 *)0x700e24, 3);  // @562d90_e
    r = vcall<u32>(self, 0xe0);  // @562d90_f
    if (*(u32 *)(self + 0x4c) != 0 && *(u32 *)(self + 0x50) != 0) {  // @562d90_g
      r = vcall<u32, u32>(self, 0xd0, 0);  // @562d90_h
      return r & ~0xffu;
    }
    u8 *o = (u8 *)vcall<u32>(self, 0x84);  // @562d90_i
    r = vcall<u32>(o, 0x300);  // @562d90_j
    return r & ~0xffu;
  }
  if (a == 0x106) r = vcall<u32>(self, 0xdc);  // @562d90_k
  return r & ~0xffu;
}
PCREG(562d90, fn562d90);
