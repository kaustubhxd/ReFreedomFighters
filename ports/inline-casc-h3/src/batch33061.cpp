// batch33061.cpp - h3 () batch 33061: tier C wrappers
#include "ff.h"

extern "C" void THISCALL ext_43f900(u8 *self, u32 a);                // ret 4
extern "C" void THISCALL ext_4e12e0(u8 *self, u32 a, u32 b);         // ret 8 (tail jump)
extern "C" void THISCALL ext_4e1b30(u8 *self);
extern "C" void THISCALL ext_4e0fd0(u8 *self, u32 a);                // ret 4
extern "C" u8 *THISCALL ext_589c20(u8 *self, u32 a);                 // ret 4
extern "C" void THISCALL ext_59a580(u8 *self, u32 a, u32 b, u32 c);  // ret 0xc
extern "C" void THISCALL ext_59a2d0(u8 *self);
extern "C" void THISCALL ext_43de70(u8 *self);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))

// 0x46cea0: thiscall(a) ret 4: 0x43f900(this,a); a->0x4e12e0(this+0x60,1); a->0x4e1b30(); a->0x4e0fd0([this+0x94]); a->0x4e1b30()
static void THISCALL fn46cea0(u8 *self, u8 *a) {
  ext_43f900(self, (u32)a);
  ext_4e12e0(a, (u32)(self + 0x60), 1);
  ext_4e1b30(a);
  ext_4e0fd0(a, *(u32 *)(self + 0x94));
  ext_4e1b30(a);
}
PCREG(46cea0, fn46cea0);

// 0x4c5820: thiscall(a,b) ret 8: p=table->slot 0x138(); vt of p read first; x=table->slot 0x4c([this+0x44],0x10); p->vtable[0x60](0x694d00, x)
static u32 THISCALL fn4c5820(u8 *self, u32 a, u32 b) {
  u8 *p = vcall<u8 *>(SYS_TABLE, 0x138);
  u8 *vtp = *(u8 **)p;
  u32 x = vcall<u32>(SYS_TABLE, 0x4c, *(u32 *)(self + 0x44), 0x10u);
  return ((u32(THISCALL *)(u8 *, u32, u32)) * (u32 *)(vtp + 0x60))(p, 0x694d00, x);
}
PCREG(4c5820, fn4c5820);

// 0x533d60: thiscall: c=[this]; c && c->slot 0(1); [this+4] && delete(p,4); [this+8] && delete(q,1)
static void THISCALL fn533d60(u8 *self) {
  u8 *c = *(u8 **)self;
  if (c) vcall<u32>(c, 0, 1u);
  u8 *p = *(u8 **)(self + 4);
  if (p) ext_634273(p, 4);
  u8 *q = *(u8 **)(self + 8);
  if (q) ext_634273(q, 1);
}
PCREG(533d60, fn533d60);

// 0x561c60: thiscall: if [this+0x94]: p=slot 0x84(); n=(p+0xcb)->slot 0x14(); n times slot 0x84()->slot 0x300()
static void THISCALL fn561c60(u8 *self) {
  if (*(u32 *)(self + 0x94) == 0) return;
  u8 *p = vcall<u8 *>(self, 0x84);
  u32 n = vcall<u32>(p + 0xcb, 0x14);
  if (n == 0) return;
  do {
    u8 *r = vcall<u8 *>(self, 0x84);
    vcall<u32>(r, 0x300);
    n--;
  } while (n != 0);
}
PCREG(561c60, fn561c60);

// 0x5c7c30: thiscall(a,b) ret 8: if (u16)a == word [this+0x4c]: r=[[sysobj+0x9b]+0xae4]->slot 0([this+0x48], str); 0x59a580(0x589c20(G,0), r, -1, 0); return 0
static u32 THISCALL fn5c7c30(u8 *self, u32 a, u32 b) {
  if ((u16)a == *(u16 *)(self + 0x4c)) {
    u8 *o = *(u8 **)(SYS_TABLE + 0xae4);
    u32 r = vcall<u32>(o, 0, *(u32 *)(self + 0x48), 0x677b5au);
    u8 *g = ext_589c20(G(u8 *, 0x7003b8), 0);
    ext_59a580(g, r, 0xffffffffu, 0);
  }
  return 0;
}
PCREG(5c7c30, fn5c7c30);

// 0x5e9dc0: thiscall: cache lookup in [this+0x1d0b] object, store it, optional second lookup, tail 0x59a2d0(this)
static void THISCALL fn5e9dc0(u8 *self) {
  u8 *edi = *(u8 **)(self + 0x1d0b);
  if (*(u32 *)(edi + 0x85a) == 0) *(u32 *)(edi + 0x85a) = vcall<u32>(edi, 0x100, 0x6a6e88u);
  u8 *c = *(u8 **)(self + 0x4f3);
  *(u32 *)(self + 0x1d03) = *(u32 *)(edi + 0x85a);
  if (c) *(u32 *)(self + 0x4f7) = vcall<u32>(c, 0x100, 0x6a5cf0u);
  ext_59a2d0(self);
}
PCREG(5e9dc0, fn5e9dc0);

// 0x6565e0: thiscall(a,b) ret 8: slot 0x14c(a,b); copy dwords 0x24..0x34 from b to a
static void THISCALL fn6565e0(u8 *self, u8 *a, u8 *b) {
  vcall<u32>(self, 0x14c, (u32)a, (u32)b);
  for (u32 off = 0x24; off <= 0x34; off += 4) *(u32 *)(a + off) = *(u32 *)(b + off);
}
PCREG(6565e0, fn6565e0);

// 0x43e250: thiscall(a) ret 4: 0x43de70(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x48) : cdecl 0x45c510(this)); return this
static u8 *THISCALL fn43e250(u8 *self, u32 a) {
  ext_43de70(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x48);
  }
  return self;
}
PCREG(43e250, fn43e250);
