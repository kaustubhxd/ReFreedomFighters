// batch33120.cpp - h3 (Sonnet) batch 33120: tier H float/SSE functions
#include "ff.h"

#define LOGOBJ (*(u8 **)0x700390)

typedef void (*hook_t)();
typedef void (*log3_t)(u8 *, u32, u32);

static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 which);            // ret 4

// 0x4c29a0: thiscall(s) ret 4, returns true: [this+4] &= ~0x40; s->slot 0x40(u16 [0x48], u16 [0x4a]); slot 0x60(byte [0x4c], [0x4d]); slot 0x4c(float [0x4e], [0x52], [0x56], [0x5a], [0x5e], [0x62], [0x66])
static u8 THISCALL fn4c29a0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<u32>(s, 0x40, (u32)*(u16 *)(self + 0x48));
  vcall<u32>(s, 0x40, (u32)*(u16 *)(self + 0x4a));
  vcall<u32>(s, 0x60, (u32)self[0x4c]);
  vcall<u32>(s, 0x60, (u32)self[0x4d]);
  vcall<u32>(s, 0x4c, R32(self + 0x4e));
  vcall<u32>(s, 0x4c, R32(self + 0x52));
  vcall<u32>(s, 0x4c, R32(self + 0x56));
  vcall<u32>(s, 0x4c, R32(self + 0x5a));
  vcall<u32>(s, 0x4c, R32(self + 0x5e));
  vcall<u32>(s, 0x4c, R32(self + 0x62));
  vcall<u32>(s, 0x4c, R32(self + 0x66));
  return 1;
}
PCREG(4c29a0, fn4c29a0);

// 0x5db4f0: thiscall(s) ret 4, returns true: [this+4] &= ~0x40; s->slot 0x64([0x48]); slot 0x4c([0x4c], [0x50]); s->slot 0x3c([0x84]->slot 0x14()); o=[0x84]: iterate slots 0x4c(&n) / 0x5c(&n): per element e: s->slot 0x4c(float [e+9]); s->slot 0x3c([e])
static u8 THISCALL fn5db4f0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<u32>(s, 0x64, R32(self + 0x48));
  vcall<u32>(s, 0x4c, R32(self + 0x4c));
  vcall<u32>(s, 0x4c, R32(self + 0x50));
  u8 *o = *(u8 **)(self + 0x84);
  u8 *vt = *(u8 **)s;
  u32 r = vcall<u32>(o, 0x14);
  typedef u32(THISCALL * fn_t)(u8 *, u32);
  (*(fn_t *)(vt + 0x3c))(s, r);
  o = *(u8 **)(self + 0x84);
  if (o) {
    u32 n = 0;
    vcall<u32>(o, 0x4c, (u32)&n);
    o = *(u8 **)(self + 0x84);
    u8 *e = vcall<u8 *>(o, 0x5c, (u32)&n);
    while (n != 0) {
      vcall<u32>(s, 0x4c, R32(e + 9));
      vcall<u32>(s, 0x3c, R32(e));
      o = *(u8 **)(self + 0x84);
      e = vcall<u8 *>(o, 0x5c, (u32)&n);
    }
  }
  return 1;
}
PCREG(5db4f0, fn5db4f0);

// 0x5023b0: thiscall(arg) ret 4: a=*0x5003d0([arg+4],2); b=*0x5003d0([arg+4],3); q=0x5003d0([arg+4],1): state q[4]: 3 -> v=q[0]; 4 -> v=(*q)->slot 0x34(); else log (0x69c8e0,0x111)/(r,0x69c6b0,0x69c9b0)+assert hook, v=0; id=(u16)table slot 0x114(v, 0, 0x69ca10, 0x257); [this+0xc]->slot 0x12c(*0x5003d0([arg+4],0), id, {a,b})
static void THISCALL fn5023b0(u8 *self, u8 *arg) {
  u8 *o = *(u8 **)(arg + 4);
  u32 l[2];
  l[0] = *ext_5003d0(o, 2);
  o = *(u8 **)(arg + 4);
  l[1] = *ext_5003d0(o, 3);
  o = *(u8 **)(arg + 4);
  u32 *q = ext_5003d0(o, 1);
  u8 st = ((u8 *)q)[4];
  u32 v;
  if (st == 3) {
    v = *q;
  } else if (st == 4) {
    v = vcall<u32>(*(u8 **)q, 0x34);
  } else {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x69c8e0u, 0x111u);
    (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c9b0);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    v = 0;
  }
  u8 *tab = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  u32 id = (u16)vcall<u32>(tab, 0x114, v, 0u, 0x69ca10u, 0x257u);
  o = *(u8 **)(arg + 4);
  u32 *p0 = ext_5003d0(o, 0);
  vcall<u32>(*(u8 **)(self + 0xc), 0x12c, *p0, id, (u32)l);
}
PCREG(5023b0, fn5023b0);
