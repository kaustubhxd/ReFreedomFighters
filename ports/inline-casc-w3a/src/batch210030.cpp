// batch210030.cpp - Sonnet-w3a: small BLOCKED rows (recursive table walk with callback, 13 field reads, out-param list loop, serializer)
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *self);
extern "C" u32 THISCALL ext_603c00(u8 *self, u32 *pn);
extern "C" u32 ext_42ab62(u32 fmt);
extern "C" u32 THISCALL ext_605940(u8 *self, u8 *a, u32 b, u32 c);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

struct WalkCtx { u8 *base; u8 *data; u32 (THISCALL *cb)(u32); };

static void THISCALL fn4e3dc0(u8 *self, WalkCtx *a) {
  u32 count = (*(u16 *)self >> 3) & 0xfff;
  if (count) {  // @4e3dc0_a
    u32 *e = (u32 *)(a->data + ((u32)*(u16 *)(self + 4) << 4));  // @4e3dc0_b
    do {
      *e = a->cb(*e);  // @4e3dc0_c
      e += 4;  // @4e3dc0_d
    } while (--count);
  }
  u32 child = *(u16 *)(self + 2);
  if (child) {  // @4e3dc0_e
    u8 *p = a->base + child * 6;  // @4e3dc0_f
    if (p) {
      u16 w;
      do {
        fn4e3dc0(p, a);  // @4e3dc0_g
        w = *(u16 *)p;
        p += 6;
      } while (!(w & 0x8000));  // @4e3dc0_h
    }
  }
}
PCREG(4e3dc0, fn4e3dc0);

static u32 THISCALL fn5d9810(u8 *self, u8 *a) {
  u32 r;
  r = ext_4e5e60(a); *(u32 *)(self + 0x48) = r;  // @5d9810_a
  r = ext_4e5e60(a); *(u32 *)(self + 0x4c) = r;
  r = ext_4e5e60(a); *(u32 *)(self + 0x50) = r;
  r = ext_4e5e60(a); *(u32 *)(self + 0x54) = r;  // @5d9810_b
  r = ext_4e5e60(a); *(u32 *)(self + 0x58) = r;
  r = ext_4e5e60(a); *(u32 *)(self + 0x5c) = r;
  r = ext_4e5e60(a); *(u32 *)(self + 0x60) = r;
  r = ext_4e5e60(a); *(u32 *)(self + 0x68) = r;  // @5d9810_c
  r = ext_4e5e60(a); *(u32 *)(self + 0x6c) = r;
  r = ext_4e5e60(a); *(u32 *)(self + 0x70) = r;
  r = ext_4e5e60(a); *(u32 *)(self + 0x74) = r;  // @5d9810_d
  r = ext_4e5e60(a); *(u32 *)(self + 0x78) = r;
  r = ext_4e5e60(a); *(u32 *)(self + 0x7c) = r;  // @5d9810_e
  return r;
}
PCREG(5d9810, fn5d9810);

typedef u32 (*HookU)();
static void THISCALL fn603c80(u8 *self, u8 *a, u32 b) {
  u32 loc = (u32)a;
  vcall<u32, u32 *>(a, 0x5c, &loc);  // @603c80_a
  ext_603c00(self + 0xc, &loc);  // @603c80_b
  for (u32 i = 0; i < loc; i++) {  // @603c80_c
    if (*(u32 *)(self + 0x14) >= *(u32 *)(self + 0x10)) {  // @603c80_d
      ext_42ab62(0x6b89b4);
      HookU h = G(HookU, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
    u32 idx = *(u32 *)(self + 0x14);
    u8 *base = *(u8 **)(self + 0xc);
    *(u32 *)(self + 0x14) = idx + 1;  // @603c80_e
    ext_605940(base + idx * 8, a, b, 0);  // @603c80_f
  }
}
PCREG(603c80, fn603c80);

static u32 THISCALL fn5de430(u8 *self, u8 *a) {
  u32 loc = (u32)a;
  *(u32 *)(self + 4) &= 0xffffffbfu;  // @5de430_a
  vcall<u32, u8 *, u32>(a, 0x18, self + 0x48, 0xcc);  // @5de430_b
  vcall<u32, u32 *>(a, 0x40, &loc);  // @5de430_c
  u32 v = vcall<u32, u32>(mgr(), 0x58, loc);  // @5de430_d
  *(u32 *)(self + 0x114) = v;  // @5de430_e
  vcall<u32, u8 *>(a, 0x50, self + 0x118);  // @5de430_f
  vcall<u32, u8 *>(a, 0x50, self + 0x11c);
  vcall<u32, u8 *, u32>(a, 0x18, self + 0x120, 0xc);  // @5de430_g
  u32 r = vcall<u32, u8 *>(a, 0x50, self + 0x12c);  // @5de430_h
  return (r & ~0xffu) | 1;
}
PCREG(5de430, fn5de430);
