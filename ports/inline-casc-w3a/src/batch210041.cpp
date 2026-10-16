// batch210041.cpp - Sonnet-w3a: small BLOCKED rows (UTF-16 class scanners, pool free with callbacks, pool alloc with callbacks)
#include "ff.h"

extern "C" u32 ext_6279e0(const u8 *base, const u8 *p, const u8 *end, const u8 **out);
extern "C" u32 ext_629a40(const u8 *base, const u8 *p, const u8 *end, const u8 **out);
extern "C" u32 ext_62c640(u32 a, u32 b);
extern "C" u32 ext_6322e0(u8 *a, u8 *b, u32 c);

static u32 class_of(const u8 *base, u32 lo, u32 hi, bool le) {
  u32 first = le ? lo : hi;   // the byte tested against zero
  u32 other = le ? hi : lo;   // the byte used as table index when first == 0
  if (first == 0) return base[0x4c + other];
  return le ? ext_62c640(lo, hi) : ext_62c640(hi, lo);
}

static u32 scan16(const u8 *base, const u8 *p, const u8 *end, const u8 **out, bool le) {
  if (p == end) return 0xffffffffu;  // @scan_a
  u32 lo = p[0], hi = p[1];
  if (le ? (lo == 0 && hi == 0x78) : (hi == 0 && lo == 0x78))  // @scan_b
    return le ? ext_6279e0(base, p + 2, end, out) : ext_629a40(base, p + 2, end, out);
  if (class_of(base, lo, hi, le) != 0x19) {  // @scan_c
    *out = p;
    return 0;
  }
  p += 2;
  while (p != end) {  // @scan_d
    u32 c = class_of(base, p[0], p[1], le);
    if (c == 0x12) {  // @scan_e
      *out = p + 2;
      return 10;  // @scan_f
    }
    if (c != 0x19) {
      *out = p;
      return 0;
    }
    p += 2;
  }
  return 0xffffffffu;
}

static u32 fn627470(const u8 *base, const u8 *p, const u8 *end, const u8 **out) { return scan16(base, p, end, out, true); }
PCREG(627470, fn627470);
static u32 fn6294d0(const u8 *base, const u8 *p, const u8 *end, const u8 **out) { return scan16(base, p, end, out, false); }
PCREG(6294d0, fn6294d0);

typedef u32 (*Free2)(u32, u32);
typedef u32 (*Alloc3)(u32, u32, u32);

static u32 STDCALL fn62ee40(u8 *A) {
  if (!A) return 0xfffffffeu;  // @62ee40_a
  u8 *r = *(u8 **)(A + 0x1c);
  if (!r) return 0xfffffffeu;
  u32 kind = *(u32 *)(r + 4);
  if (kind != 0x2a && kind != 0x71 && kind != 0x29a) return 0xfffffffeu;  // @62ee40_b
  Free2 fr = *(Free2 *)(A + 0x24);
  u32 p = *(u32 *)(r + 8);
  if (p) fr(*(u32 *)(A + 0x28), p);  // @62ee40_c
  p = *(u32 *)(*(u8 **)(A + 0x1c) + 0x3c);
  if (p) (*(Free2 *)(A + 0x24))(*(u32 *)(A + 0x28), p);  // @62ee40_d
  p = *(u32 *)(*(u8 **)(A + 0x1c) + 0x38);
  if (p) (*(Free2 *)(A + 0x24))(*(u32 *)(A + 0x28), p);  // @62ee40_e
  p = *(u32 *)(*(u8 **)(A + 0x1c) + 0x30);
  if (p) (*(Free2 *)(A + 0x24))(*(u32 *)(A + 0x28), p);  // @62ee40_f
  (*(Free2 *)(A + 0x24))(*(u32 *)(A + 0x28), *(u32 *)(A + 0x1c));  // @62ee40_g
  *(u32 *)(A + 0x1c) = 0;
  return kind == 0x71 ? 0xfffffffdu : 0;  // @62ee40_h
}
PCREG(62ee40, fn62ee40);

static u8 *fn632230(u8 *A, u32 x, u32 y) {
  u8 *edi = (u8 *)(*(Alloc3 *)(A + 0x20))(*(u32 *)(A + 0x28), 1, 0x40);  // @632230_a
  if (!edi) return 0;
  u32 q = (*(Alloc3 *)(A + 0x20))(*(u32 *)(A + 0x28), 8, 0x5a0);  // @632230_b
  *(u32 *)(edi + 0x24) = q;
  if (!q) {  // @632230_c
    (*(Free2 *)(A + 0x24))(*(u32 *)(A + 0x28), (u32)edi);
    return 0;
  }
  u32 r = (*(Alloc3 *)(A + 0x20))(*(u32 *)(A + 0x28), 1, y);  // @632230_d
  *(u32 *)(edi + 0x28) = r;
  if (!r) {
    (*(Free2 *)(A + 0x24))(*(u32 *)(A + 0x28), *(u32 *)(edi + 0x24));  // @632230_e
    (*(Free2 *)(A + 0x24))(*(u32 *)(A + 0x28), (u32)edi);
    return 0;
  }
  *(u32 *)(edi + 0x2c) = r + y;  // @632230_f
  *(u32 *)edi = 0;
  *(u32 *)(edi + 0x38) = x;  // @632230_g
  ext_6322e0(edi, A, 0);  // @632230_h
  return edi;
}
PCREG(632230, fn632230);
