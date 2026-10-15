// batch33112.cpp - h3 (Sonnet) batch 33112: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" void THISCALL ext_467410(u8 *self, u32 p, u32 f, u32 a, u32 b, u32 c, u32 d);   // ret 0x18

// 0x5df8b0: thiscall no args, returns false: s=[this+0xc]->slot 0x10(); table slot 0x4c(s); 0x467410([this+0xc]+4,[this+8],0,0,0,0,-1); [this+0xc]->slot 8([this+8],0); s->slot 0x2d0(3,0); [this+8]->slot 0x4f4(s); r=table slot 0x4c([this+8]); s->slot 0x2f0(r, 0, 1) (the two junk pushes of the previous call become its arguments)
static u8 THISCALL fn5df8b0(u8 *self) {
  u8 *s = vcall<u8 *>(*(u8 **)(self + 0xc), 0x10);
  u8 *tab = *(u8 **)(SYS + 0x9b);
  (void)vcall<u32>(tab, 0x4c, (u32)s);
  ext_467410(*(u8 **)(self + 0xc) + 4, *(u32 *)(self + 8), 0, 0, 0, 0, 0xffffffffu);
  vcall<u32>(*(u8 **)(self + 0xc), 8, *(u32 *)(self + 8), 0u);
  vcall<u32>(s, 0x2d0, 3u, 0u);
  vcall<u32>(*(u8 **)(self + 8), 0x4f4, (u32)s);
  u8 *vt = *(u8 **)s;
  tab = *(u8 **)(SYS + 0x9b);
  u32 r = vcall<u32>(tab, 0x4c, *(u32 *)(self + 8));
  typedef u32(THISCALL * fn3_t)(u8 *, u32, u32, u32);
  (*(fn3_t *)(vt + 0x2f0))(s, r, 0u, 1u);
  return 0;
}
PCREG(5df8b0, fn5df8b0);

// 0x4f39f0: thiscall no args: e=table slot 0x58([this+0x48]); [e+0x48] |= 0x218000; e->slot 0x27c(table slot 0x4c([this+0x44])); r=[this+0x44]->slot 0x2c4(); [r+0x6f]->slot 0x240(l); e->slot 0x23c(l); [sys+0x190f]->slot 0xac(e, (float)(s32)[e+0x4c]); e->slot 0x250(); [[this+0x44]+0x30] |= 0x400
static void THISCALL fn4f39f0(u8 *self) {
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u8 *e = vcall<u8 *>(tab, 0x58, R32(self + 0x48));
  *(u32 *)(e + 0x48) |= 0x218000u;
  u8 *vt = *(u8 **)e;
  tab = *(u8 **)(SYS + 0x9b);
  u32 h = vcall<u32>(tab, 0x4c, R32(self + 0x44));
  typedef u32(THISCALL * fn_t)(u8 *, u32);
  (*(fn_t *)(vt + 0x27c))(e, h);
  u32 l[4];
  u8 *r = vcall<u8 *>(*(u8 **)(self + 0x44), 0x2c4);
  vcall<u32>(*(u8 **)(r + 0x6f), 0x240, (u32)l);
  vcall<u32>(e, 0x23c, (u32)l);
  float f = (float)(s32)*(u32 *)(e + 0x4c);
  vcall<u32>(*(u8 **)(SYS + 0x190f), 0xac, (u32)e, fbits(f));
  vcall<u32>(e, 0x250);
  *(u32 *)(*(u8 **)(self + 0x44) + 0x30) |= 0x400u;
}
PCREG(4f39f0, fn4f39f0);
