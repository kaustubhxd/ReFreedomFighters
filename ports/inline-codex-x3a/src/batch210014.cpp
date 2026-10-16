// batch210014.cpp - Sonnet-w3a: small BLOCKED rows (selector by flag, sum over array, guarded reset, ctor, string equality)
#include "ff.h"

extern "C" u32 THISCALL ext_5f9570(u8 *self);
extern "C" u32 ext_6322e0(u32 a, u8 *b, u32 c);
extern "C" u32 THISCALL ext_45c3a0(u8 *self, u32 a, u32 b, u32 c);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL fn5aaa80(u8 *self, u32 a, u32 b, u32 c) {
  (void)a; (void)b;
  u8 *obj = *(u8 **)(self + 0x63c);
  obj[4] = 1;  // @5aaa80_a
  u32 idx = *(u32 *)(self + 0x360);
  u8 *t = G(u8 *, 0x7003b8);
  u8 *e = (u8 *)ld32(t + idx * 4 + 0x2c39);
  u8 *f = *(u8 **)(e + 0x54);
  u32 esi = 0xff82b4e1u;  // @5aaa80_b
  if (*(u32 *)(f + 4) != 3) esi = 0xffe15f55u;  // @5aaa80_c
  vcall<u32>(*(u8 **)(self + 0x63c), 8);  // @5aaa80_d
  return vcall<u32, u32, u32>(*(u8 **)(self + 0x63c), 0x14, c, esi);  // @5aaa80_e
}
PCREG(5aaa80, fn5aaa80);

static u32 THISCALL fn500150(u8 *self) {
  u32 sum = 4;
  u32 *begin = *(u32 **)self;
  u32 *end = *(u32 **)(self + 4);
  if (((int)((u32)end - (u32)begin) >> 2) != 0) {  // @500150_a
    u32 i = 0;
    do {
      sum += ext_5f9570((u8 *)(*(u32 **)self)[i]);  // @500150_b
      i++;
    } while (i < (u32)(((int)(*(u32 *)(self + 4) - *(u32 *)self)) >> 2));  // @500150_c
  }
  return sum;
}
PCREG(500150, fn500150);

static u32 STDCALL fn62fad0(u8 *p) {
  if (!p) return 0xfffffffeu;
  u8 *q = *(u8 **)(p + 0x1c);
  if (!q) return 0xfffffffeu;  // @62fad0_a
  *(u32 *)(p + 0x14) = 0;  // @62fad0_b
  *(u32 *)(p + 8) = 0;
  *(u32 *)(p + 0x18) = 0;
  *(u32 *)q = *(u32 *)(q + 0xc) ? 7 : 0;  // @62fad0_c
  ext_6322e0(*(u32 *)(*(u8 **)(p + 0x1c) + 0x14), p, 0);  // @62fad0_d
  return 0;
}
PCREG(62fad0, fn62fad0);

static u8 *THISCALL fn43e990(u8 *self, u32 a, u32 b, u32 c) {
  ext_45c3a0(self, a, b, c);  // @43e990_a
  *(u32 *)self = 0x67c8f8;  // @43e990_vt
  *(u32 *)(self + 0x34) = 0xffffffffu;  // @43e990_b
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x30) = 0x3000000;  // @43e990_c
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x58) = 0x3f800000;  // @43e990_d
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x40) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x2c) = 0;  // @43e990_e
  return self;
}
PCREG(43e990, fn43e990);

static u32 THISCALL fn4cc180(u8 *self, const u8 *q) {
  const u8 *p = *(const u8 **)self;
  for (;;) {
    if (p[0] != q[0]) return 0;  // @4cc180_a
    if (p[0] == 0) return 1;  // @4cc180_b
    if (p[1] != q[1]) return 0;  // @4cc180_c
    p += 2;
    q += 2;
    if (p[-1] == 0) return 1;  // @4cc180_d
  }
}
PCREG(4cc180, fn4cc180);
