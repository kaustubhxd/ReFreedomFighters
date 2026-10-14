// batch33075.cpp - h3 () batch 33075: tier C wrappers
#include "ff.h"

extern "C" void THISCALL ext_43ea20(u8 *self);
extern "C" u32 THISCALL ext_4e5e60(u8 *self);
extern "C" u32 THISCALL ext_4464e0(u8 *self, u32 a);                // ret 4
extern "C" void THISCALL ext_57f960(u8 *self);
extern "C" void THISCALL ext_57f9b0(u8 *self, u32 *a, u32 *b);      // ret 8
extern "C" void THISCALL ext_565360(u8 *self, u32 *a);              // ret 4
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (__attribute__((cdecl)) *log3_t)(u8 *, u32, u32);
typedef u32 (__attribute__((cdecl)) *log2_t)(u8 *, u32);
typedef u32 (STDCALL *impc_t)(u32, u32, u32, u32, u32, u32, u32);

// 0x428300: thiscall(a) ret 4 bool: h=import[0x676068](a,0x40000000,0,0,2,0x80,0) (CreateFile-like); h == -1: global slot 0x20(str,0xd1), cdecl log slot 0x2c(r,str,a), 0; else this->slot 0x1c(h), 1
static u32 THISCALL fn428300(u8 *self, u32 a) {
  u32 h = (*(impc_t *)0x676068)(a, 0x40000000, 0, 0, 2, 0x80, 0);
  if (h == 0xffffffffu) {
    u8 *g = G(u8 *, 0x700390);
    u8 *r = vcall<u8 *>(g, 0x20, 0x6789acu, 0xd1u);
    (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x678b54, a);
    return 0;
  }
  vcall<u32>(self, 0x1c, h);
  return 1;
}
PCREG(428300, fn428300);

// 0x46a990: thiscall(a) ret 4: vtable 0x68796c; delete([this+0x98],4); vtable 0x6868e8; c=[this+0x70] (read after the delete): c->slot 0(1); 0x43ea20(this); a&1: (a&4 ? cdecl 0x4690b0(this,0xa4) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn46a990(u8 *self, u32 a) {
  *(u32 *)self = 0x68796c;
  ext_634273(*(void **)(self + 0x98), 4);
  u8 *c = *(u8 **)(self + 0x70);
  *(u32 *)self = 0x6868e8;
  if (c) vcall<u32>(c, 0, 1u);
  ext_43ea20(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0xa4);
  }
  return self;
}
PCREG(46a990, fn46a990);

// 0x4bbba0: thiscall(a,b) ret 8: log-style prints (global slot 0x20 + cdecl slot 0x2c) with [[this+0x44]+4] or a default string; 0x4e5e60(b); if sysobj[0x1a9f]==0 another log line
static void THISCALL fn4bbba0(u8 *self, u32 a, u8 *b) {
  u8 *g = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x693c40u, 0x90u);
  u32 s = *(u32 *)(*(u8 **)(self + 0x44) + 4);
  if (!s) s = 0x67c8e8;
  (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x693c70, s);
  ext_4e5e60(b);
  if (*(u32 *)(SYS + 0x1a9f) == 0) {
    u8 *g2 = G(u8 *, 0x700390);
    u8 *r2 = vcall<u8 *>(g2, 0x20, 0x693c40u, 0xb1u);
    (*(log2_t *)(*(u8 **)r2 + 0x2c))(r2, 0x69269c);
  }
}
PCREG(4bbba0, fn4bbba0);

// 0x4ee070: thiscall(a) ret 4: p=table->slot 0x138(); a ? p->slot 0xa0(str,0) : p->vtable[0x60](str, table->slot 0x4c(this,4))
static void THISCALL fn4ee070(u8 *self, u32 a) {
  u8 *tab = SYS_TABLE;
  if ((u8)a) {
    u8 *p = vcall<u8 *>(tab, 0x138);
    vcall<u32>(p, 0xa0, 0x697b08u, 0u);
    return;
  }
  u8 *p = vcall<u8 *>(tab, 0x138);
  u8 *vtp = *(u8 **)p;
  u32 x = vcall<u32>(SYS_TABLE, 0x4c, (u32)self, 4u);
  ((u32(THISCALL *)(u8 *, u32, u32)) * (u32 *)(vtp + 0x60))(p, 0x697b08, x);
}
PCREG(4ee070, fn4ee070);

// 0x564600: thiscall(a) ret 4 bool: [this+0xc9a]==10: reset, tmp via 0x57f960, 0x57f9b0(this+0x5a6+0xac*a, this+0x184, &tmp), 0x565360(this,&tmp), returns 1; else 0
static u32 THISCALL fn564600(u8 *self, u32 a) {
  if (*(u32 *)(self + 0xc9a) != 0xa) return 0;
  u32 tmp[11];
  u32 *esi = (u32 *)(self + 0x184);
  *(u32 *)(self + 0xc96) = 0;
  *(u32 *)(self + 0xc9a) = a;
  self[0x189] = 0;
  *esi = 1;
  ext_57f960((u8 *)tmp);
  ext_57f9b0(self + 0x5a6 + *(u32 *)(self + 0xc9a) * 0xac, esi, tmp);
  ext_565360(self, tmp);
  return 1;
}
PCREG(564600, fn564600);

// 0x5b2370: thiscall(a) ret 4 bool: !(u8)0x4464e0(this,a) -> 0; a->slot 0x60((u8)[this+0x197]); a->slot 0x64([this+0x198]); a->slot 0x70(this+0x19c); a->slot 0x68(this+0x1c0); return 1
static u32 THISCALL fn5b2370(u8 *self, u8 *a) {
  u32 ok = ext_4464e0(self, (u32)a);
  if (!(u8)ok) return ok;
  vcall<u32>(a, 0x60, (u32)self[0x197]);
  vcall<u32>(a, 0x64, *(u32 *)(self + 0x198));
  vcall<u32>(a, 0x70, (u32)(self + 0x19c));
  vcall<u32>(a, 0x68, (u32)(self + 0x1c0));
  return 1;
}
PCREG(5b2370, fn5b2370);

// 0x456b70: thiscall(p1,p2) ret 8: [this+0xed]==0: o=table->slot 0x58([table+0x18]); o: vtable of o read first, x=table->slot 0x4c(this); [this+0xed]=o->vtable[0x214](x); *p2=[this+0xed]; *p1=[table+0x18]
static void THISCALL fn456b70(u8 *self, u32 *p1, u32 *p2) {
  if (*(u32 *)(self + 0xed) == 0) {
    u8 *tab = SYS_TABLE;
    u8 *o = vcall<u8 *>(tab, 0x58, *(u32 *)(tab + 0x18));
    if (o) {
      u8 *vt = *(u8 **)o;
      u32 x = vcall<u32>(SYS_TABLE, 0x4c, (u32)self);
      u32 v = ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vt + 0x214))(o, x);
      *(u32 *)(self + 0xed) = v;
    }
  }
  *p2 = *(u32 *)(self + 0xed);
  *p1 = *(u32 *)(SYS_TABLE + 0x18);
}
PCREG(456b70, fn456b70);

// 0x4ce550: thiscall(n): this null -> 0; this->slot 0x4c(&loc); r=this->slot 0x5c(&loc); loc==0 -> 0; then up to n more slot 0x5c(&loc) calls (stop at loc==0); n exhausted returns the last slot 0x5c result (eax)
static u32 THISCALL fn4ce550(u8 *self, u32 n) {
  u32 loc;
  if (!self) return 0;
  vcall<u32>(self, 0x4c, (u32)&loc);
  u32 r = vcall<u32>(self, 0x5c, (u32)&loc);
  if (loc == 0) return 0;
  u32 esi = n;
  for (;;) {
    u32 ecx = esi;
    esi--;
    if (ecx == 0) return r;
    r = vcall<u32>(self, 0x5c, (u32)&loc);
    if (loc == 0) return 0;
  }
}
PCREG(4ce550, fn4ce550);
