// batch33110.cpp - h3 () batch 33110: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 which);            // ret 4
extern "C" void THISCALL ext_446320(u8 *self, u8 *a, float *l);      // ret 8

// 0x507370: thiscall(arg) ret 4: p2,p1,p0 = 0x5003d0([arg+4], 2/1/0); l10={*p0,*p1,*p2}; q=[this+0x18]: slot 0x624(1.0); slot 0x630(l1c); slot 0x5e8(0); slot 0x5e0(l1c, l10)
static void THISCALL fn507370(u8 *self, u8 *arg) {
  u8 *o = *(u8 **)(arg + 4);
  u32 *p2 = (u32 *)ext_5003d0(o, 2);
  o = *(u8 **)(arg + 4);
  u32 *p1 = (u32 *)ext_5003d0(o, 1);
  o = *(u8 **)(arg + 4);
  u32 *p0 = (u32 *)ext_5003d0(o, 0);
  u32 l10[3];
  u32 l1c[3];
  u32 a = *p0, b = *p1, c = *p2;
  l10[0] = a;
  l10[1] = b;
  l10[2] = c;
  vcall<u32>(*(u8 **)(self + 0x18), 0x624, 0x3f800000u);
  vcall<u32>(*(u8 **)(self + 0x18), 0x630, (u32)l1c);
  vcall<u32>(*(u8 **)(self + 0x18), 0x5e8, 0u);
  vcall<u32>(*(u8 **)(self + 0x18), 0x5e0, (u32)l1c, (u32)l10);
}
PCREG(507370, fn507370);

// 0x5cf300: thiscall(a, p) ret 8: e = table slot 0x58([this+0xc6d]); e: l={p[0..2]}; e->slot 0x8c(l); 0x446320(e, a, l); a[0] clamped to +-0.44 (low test first, else high), a[1]: < -0.46 -> -0.46 then > 0.46 -> 0.46
static void THISCALL fn5cf300(u8 *self, float *a, u32 *p) {
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u8 *e = vcall<u8 *>(tab, 0x58, R32(self + 0xc6d));
  if (!e) return;
  u32 l[3] = {p[0], p[1], p[2]};
  vcall<u32>(e, 0x8c, (u32)l);
  ext_446320(e, (u8 *)a, (float *)l);
  float x = a[0];
  if (-0.4399999976158142f > x) *(u32 *)&a[0] = 0xbee147aeu;
  else if (x > 0.4399999976158142f) *(u32 *)&a[0] = 0x3ee147aeu;
  if (-0.46000000834465027f > a[1]) *(u32 *)&a[1] = 0xbeeb851fu;
  if (a[1] > 0.46000000834465027f) *(u32 *)&a[1] = 0x3eeb851fu;
}
PCREG(5cf300, fn5cf300);

// 0x44a160: thiscall(a, float f) ret 8, bool: o=[this+0x18]; none: false; o->slot 0x4c(&n); e = o->slot 0x5c(&n); while n != 0: p = table slot 0x58(e); p && p->slot 0x180(a, f) -> true; e = [this+0x18]->slot 0x5c(&n); false
static u8 THISCALL fn44a160(u8 *self, u32 a, u32 f) {
  u8 *o = *(u8 **)(self + 0x18);
  if (!o) return 0;
  u32 n = 0;
  vcall<u32>(o, 0x4c, (u32)&n);
  o = *(u8 **)(self + 0x18);
  u32 e = vcall<u32>(o, 0x5c, (u32)&n);
  while (n != 0) {
    u8 *tab = *(u8 **)(SYS + 0x9b);
    u8 *p = vcall<u8 *>(tab, 0x58, e);
    if (p) {
      if (vcall<u8>(p, 0x180, a, f)) return 1;
    }
    o = *(u8 **)(self + 0x18);
    e = vcall<u32>(o, 0x5c, (u32)&n);
  }
  return 0;
}
PCREG(44a160, fn44a160);
