// batch210026.cpp - Sonnet-w3a: small BLOCKED rows (class-table scanner, buffer double, lookup chain, byte-to-word converter)
#include "ff.h"

extern "C" u32 ext_41e290(u32 n);
extern "C" u32 ext_41e2c0(u32 p);
extern "C" u32 ext_634d22(u32 dst, u32 src, u32 n);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 fn62b290(const u8 *base, const u8 *p, const u8 *end, const u8 **out) {
  if (p == end) return 0xffffffffu;  // @62b290_a
  u8 c = base[0x4c + *p];
  if ((u8)(c - 0x18) > 1) {  // @62b290_b
    *out = p;
    return 0;
  }
  p++;
  while (p != end) {  // @62b290_c
    c = base[0x4c + *p];
    if (c == 0x12) {  // @62b290_d
      *out = p + 1;
      return 10;  // @62b290_e
    }
    if ((u8)(c - 0x18) > 1) {
      *out = p;
      return 0;
    }
    p++;
  }
  return 0xffffffffu;
}
PCREG(62b290, fn62b290);

static u32 THISCALL fn4d61e0(u8 *self) {
  u32 n = *(u32 *)self;
  u32 n2 = n + n;
  u64 bytes = (u64)n2 * 4;
  u32 size = (bytes >> 32) ? 0xffffffffu : (u32)bytes;
  u32 buf = ext_41e290(size);  // @4d61e0_a
  if (buf == 0) {
    u8 *g = G(u8 *, 0x700390);
    u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x696770, 0x14f);  // @4d61e0_b
    typedef u32 (*F)(u8 *, u32);
    F f = *(F *)(*(u8 **)o + 0x2c);
    f(o, 0x696be8);  // @4d61e0_c
  }
  ext_634d22(buf, *(u32 *)(self + 8), n << 2);  // @4d61e0_d
  *(u32 *)self = n2;  // @4d61e0_e
  u32 r = ext_41e2c0(*(u32 *)(self + 8));  // @4d61e0_f
  *(u32 *)(self + 8) = buf;  // @4d61e0_g
  return r;
}
PCREG(4d61e0, fn4d61e0);

static u32 STDCALL fn50dad0(u8 *a) {
  u32 *x = (u32 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @50dad0_a
  u8 *o1 = (u8 *)vcall<u32, u32>(mgr(), 0x58, *x);  // @50dad0_b
  u32 *y = (u32 *)ext_5003d0(*(u8 **)(a + 4), 1);  // @50dad0_c
  u8 *o2 = (u8 *)vcall<u32, u32>(mgr(), 0x58, *y);  // @50dad0_d
  u32 r = (u32)o2;
  if (o2 && o1) {  // @50dad0_e
    r = vcall<u32, u32>(o1, 0x1e0, 0x100001);  // @50dad0_f
    if (r & 0xff) r = vcall<u32, u8 *, u32, u32>(o1, 0x288, o2, 0, 1);  // @50dad0_g
  }
  return r;
}
PCREG(50dad0, fn50dad0);

static void fn62c7f0(u8 *ctx, u8 **pp, u8 *end, u16 **dp, u16 *dend) {
  if (*pp == end) return;
  for (;;) {
    if (*dp == dend) break;  // @62c7f0_a
    u8 *cur = *pp;
    u32 c = *cur;
    u32 w = *(u16 *)(ctx + 0x178 + c * 2);
    if (w == 0) {  // @62c7f0_b
      typedef u32 (*CB)(u32, u8 *);
      u32 r = (*(CB *)(ctx + 0x170))(*(u32 *)(ctx + 0x174), cur);  // @62c7f0_c
      w = r & 0xffff;
      *pp = cur + ctx[0x4c + c] - 3;  // @62c7f0_d
    } else {
      *pp = cur + 1;  // @62c7f0_e
    }
    **dp = (u16)w;
    *dp += 1;  // @62c7f0_f
    if (*pp == end) break;
  }
}
PCREG(62c7f0, fn62c7f0);
