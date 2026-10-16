// batch210022.cpp - Sonnet-w3a: small BLOCKED rows (embedded-object slots, path normalise, record search, list append, lookup chain)
#include "ff.h"

extern "C" u32 THISCALL ext_4cbec0(u8 *self);
extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_596cf0(u8 *self);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 THISCALL fn432c50(u8 *self, u32 a) {
  vcall<u32, u32>(self + 0xc8, 0x88, a);  // @432c50_a
  u8 *p = (u8 *)vcall<u32, u32>(self + 0xac, 0x84, a);  // @432c50_b
  if (p) {
    u8 *q = *(u8 **)(p + 4);
    if (q) {
      ext_4cbec0(q);  // @432c50_c
      ext_634273((u32)q, 0x80);  // @432c50_d
    }
    vcall<u32, u32>(self + 0xac, 0x90, a);  // @432c50_e
  }
  return vcall<u32, u32>(G(u8 *, 0x70039c), 0x64, a);  // @432c50_f
}
PCREG(432c50, fn432c50);

static u32 THISCALL fn49e260(u8 *self, const u8 *src) {
  u32 i = 0, o = 0;
  if (src[0] == '/') {
    i++;
    while (src[i] == '/') i++;  // @49e260_a
  }
  do {
    u8 cl = src[i];
    self[o + 0x104] = cl;  // @49e260_b
    self[o + 4] = cl;
    if (cl == '/' && src[i + 1] == '/') {  // @49e260_c
      do { i++; } while (src[i + 1] == '/');
    }
    i++;
    o++;
  } while (src[i] != 0);  // @49e260_d
  u32 g = G(u32, 0x68f010);
  __builtin_memcpy(self + o + 0x104, &g, 4);  // @49e260_e
  u8 b = G(u8, 0x68f014);
  self[o + 0x108] = b;  // @49e260_f
  return (g & ~0xffu) | b;
}
PCREG(49e260, fn49e260);

static u8 *THISCALL fn45e420(u8 *self, u32 key) {
  u32 flags = *(u32 *)(self + 4);
  if ((int)flags >= 0) return 0;  // @45e420_a
  u8 *rec;
  if (flags & 0x40000000) rec = self + (*(u32 *)(self + 0x10) + 5) * 4;  // @45e420_b
  else rec = self + 0x10;
  if (!rec) return 0;
  int n = *(int *)(self + 0xc);
  if (n <= 0) return 0;  // @45e420_c
  do {
    if (*(u32 *)rec == key) return rec;  // @45e420_d
    u32 sz = *(u32 *)(rec + 4) & 0x3fffffffu;  // @45e420_e
    n--;
    rec += sz;
  } while (n > 0);
  return 0;
}
PCREG(45e420, fn45e420);

static u8 *THISCALL fn4cd540(u8 *self, u32 a) {
  if (*(u32 *)(self + 4) == 0 || *(u32 *)(*(u8 **)(self + 8) + 8) == *(u32 *)(self + 0x10)) {  // @4cd540_a
    u8 *n = (u8 *)vcall<u32>(self, 0x80);  // @4cd540_b
    *(u32 *)(n + 4) = 0;
    if (*(u32 *)(self + 4) == 0) {
      *(u8 **)(self + 4) = n;
      *(u32 *)n = 0;
      *(u32 *)(self + 8) = *(u32 *)(self + 4);
    } else {
      *(u8 **)(*(u8 **)(self + 8) + 4) = n;  // @4cd540_c
      *(u32 *)n = *(u32 *)(self + 8);
      *(u8 **)(self + 8) = n;
    }
    *(u32 *)(*(u8 **)(self + 8) + 8) = 0;  // @4cd540_d
  }
  u8 *cur = *(u8 **)(self + 8);
  u32 idx = *(u32 *)(cur + 8);
  u8 *e = cur + idx * 4;
  *(u32 *)(e + 0x10) = a;  // @4cd540_e
  *(u32 *)(*(u8 **)(self + 8) + 8) += *(u32 *)(self + 0x18);  // @4cd540_f
  (*(u32 *)(self + 0x14))++;  // @4cd540_g
  return e + 0x14;
}
PCREG(4cd540, fn4cd540);

static u32 STDCALL fn5538f0(u8 *a) {
  ext_5002f0((u8 *)ext_5003d0(*(u8 **)(a + 8), 0), 0xffffffffu);  // @5538f0_a
  u8 *g = (u8 *)vcall<u32>(mgr(), 0x138);  // @5538f0_b
  u32 loc = 0;
  vcall<u32, u32, u32 *>(g, 0x88, 0x681320, &loc);  // @5538f0_c
  u32 r = vcall<u32, u32>(mgr(), 0x58, loc);  // @5538f0_d
  if (r) {
    u8 *m = (u8 *)ld32((u8 *)r + 0x852);
    if (m) {
      u32 v = ext_596cf0(m);  // @5538f0_e
      r = ext_5002f0((u8 *)ext_5003d0(*(u8 **)(a + 8), 0), v);  // @5538f0_f
    }
  }
  return r;
}
PCREG(5538f0, fn5538f0);
