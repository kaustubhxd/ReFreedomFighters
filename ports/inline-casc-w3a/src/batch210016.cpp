// batch210016.cpp - Sonnet-w3a: small BLOCKED rows (pool pop with assert, list unlink, tag-to-pointer, string copy, out-param slots)
#include "ff.h"

extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 THISCALL ext_4e4890(u8 *self, u8 *a);
extern "C" u32 THISCALL ext_4e6420(u8 *self);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_4e5ea0(u8 *self);
extern "C" u32 ext_41e290(u32 n);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

typedef void (*Hook)();
static u32 THISCALL fn4d0950(u8 *self, u32 a) {
  u8 *sub = self + 0x1ea;
  u32 p = vcall<u32, u32, u32>(sub, 8, a, 0);  // @4d0950_a
  if (p == 0) {
    Hook h = G(Hook, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u8 *vt = *(u8 **)sub;
  u32 n = *(u32 *)(self + 0xd628) - 1;
  *(u32 *)(self + 0xd628) = n;  // @4d0950_b
  typedef u32 (THISCALL *F)(u8 *, u32);
  u32 r = (*(F *)(vt + 4))(sub, p);  // @4d0950_c
  *(u32 *)(self + n * 4 + 0xc628) = r;  // @4d0950_d
  return r;
}
PCREG(4d0950, fn4d0950);

static u32 THISCALL fn4e4840(u8 *self, u8 *s) {
  u8 *prev = *(u8 **)(s + 4);
  u8 *owner = *(u8 **)(s + 0x18);
  u32 next = *(u32 *)s;
  if (prev) *(u32 *)prev = next;  // @4e4840_a
  else *(u32 *)(owner + 0xc) = next;  // @4e4840_b
  u8 *nx = *(u8 **)s;
  if (nx) *(u32 *)(nx + 4) = *(u32 *)(s + 4);  // @4e4840_c
  u32 cnt = ld32(self + 0x19) - 1;
  __builtin_memcpy(self + 0x19, &cnt, 4);  // @4e4840_d
  ext_4e4890(*(u8 **)(s + 0x18), self + 4);  // @4e4840_e
  return ext_634273((u32)s, 0x1c);  // @4e4840_f
}
PCREG(4e4840, fn4e4840);

static u8 *THISCALL fn4e5ea0(u8 *self) {
  u8 *p = *(u8 **)self;
  u8 t = p[0] & 0x3f;
  u8 *r;
  if (t == 5 || t == 4) r = p + 1;  // @4e5ea0_a
  else if (t == 7) {
    if (ld32(p + 1) == 4) r = 0;  // @4e5ea0_b
    else r = p + 5;  // @4e5ea0_c
  } else r = (u8 *)0x677b5a;  // @4e5ea0_d
  ext_4e6420(self);
  return r;
}
PCREG(4e5ea0, fn4e5ea0);

static u32 THISCALL fn558a90(u8 *self, u8 *a) {
  u32 *x = (u32 *)ext_5003d0(*(u8 **)(a + 4), 1);  // @558a90_a
  u32 *y = (u32 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @558a90_b
  u32 al = vcall<u32, u32, u32>(*(u8 **)(self + 0x1c), 0x708, *y, *x) & 0xff;  // @558a90_c
  u8 *z = (u8 *)ext_5003d0(*(u8 **)(a + 8), 0);  // @558a90_d
  return ext_5002f0(z, al);  // @558a90_e
}
PCREG(558a90, fn558a90);

static u32 THISCALL fn56ae50(u8 *self, u8 *a) {
  u8 *s = (u8 *)ext_4e5ea0(a);  // @56ae50_a
  u32 n = 0;
  while (s[n]) n++;
  u8 *buf = (u8 *)ext_41e290(n + 1);  // @56ae50_b
  for (u32 i = 0; i <= n; i++) buf[i] = s[i];  // @56ae50_c
  *(u32 *)(self + 0x4c) = (u32)buf;  // @56ae50_d
  return (u32)buf;
}
PCREG(56ae50, fn56ae50);

static u32 THISCALL fn5c4240(u8 *self, u8 *a) {
  u32 loc = (u32)a;
  *(u32 *)(self + 4) &= 0xffffffbfu;  // @5c4240_a
  vcall<u32, u32>(a, 0x70, *(u32 *)(self + 0x48));  // @5c4240_b
  vcall<u32, u8 *>(a, 0x40, self + 0x4c);  // @5c4240_c
  vcall<u32, u32 *>(a, 0x40, &loc);  // @5c4240_d
  u8 *mg = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32, u32>(mg, 0x58, loc);  // @5c4240_e
  *(u32 *)(self + 0x50) = r;  // @5c4240_f
  return (r & ~0xffu) | 1;
}
PCREG(5c4240, fn5c4240);
