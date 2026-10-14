// batch33074.cpp - h3 () batch 33074: tier C wrappers
#include "ff.h"

extern "C" void THISCALL ext_43de70(u8 *self);
extern "C" void THISCALL ext_44b610(u8 *self);
extern "C" void __attribute__((cdecl)) ext_44b740(u8 *p);
extern "C" void THISCALL ext_5764c0(u8 *self);
extern "C" void THISCALL ext_5769c0(u8 *self);
extern "C" u32 THISCALL ext_574200(u8 *self, u32 a);                // ret 4
extern "C" void THISCALL ext_5ec190(u8 *self, u8 *a);               // ret 4
extern "C" void __attribute__((cdecl)) ext_42ab62(u32 fmt, s32 v);
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))

// 0x47fd70: thiscall(a) ret 4: e=[this+0x8c]; vtable 0x68b364; e: delete([e+4],0x44), delete(e,8); 0x43de70(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x90) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn47fd70(u8 *self, u32 a) {
  u8 *e = *(u8 **)(self + 0x8c);
  *(u32 *)self = 0x68b364;
  if (e) {
    ext_634273(*(void **)(e + 4), 0x44);
    ext_634273(*(void **)(self + 0x8c), 8);
  }
  ext_43de70(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x90);
  }
  return self;
}
PCREG(47fd70, fn47fd70);

// 0x4b3a00: thiscall(a,b) ret 8: (u16)a == word [this+0x115] && byte [this+0x84]: release the table object [this+0x8d], clear it, slot 0xa0(), slot 0x68(0x10,0); returns 0
static u32 THISCALL fn4b3a00(u8 *self, u32 a, u32 b) {
  if ((u16)a == *(u16 *)(self + 0x115) && self[0x84] != 0) {
    u8 *o = vcall<u8 *>(SYS_TABLE, 0x60, *(u32 *)(self + 0x8d));
    if (o) {
      ext_44b610(o);
      ext_44b740(o);
    }
    *(u32 *)(self + 0x8d) = 0;
    vcall<u32>(self, 0xa0);
    vcall<u32>(self, 0x68, 0x10u, 0u);
  }
  return 0;
}
PCREG(4b3a00, fn4b3a00);

// 0x4e80f0: thiscall(a) ret 4: b=a?a:[this+4]; x=1,y=1; [b+4]!=[this+8] -> x=slot 0x1c([b+4])+1; [b+8]!=[this+8] -> y=slot 0x1c([b+8])+1; returns max(x,y) (signed)
static s32 THISCALL fn4e80f0(u8 *self, u8 *a) {
  u8 *b = a ? a : *(u8 **)(self + 4);
  s32 x = 1;
  s32 y = 1;
  u32 c1 = *(u32 *)(b + 4);
  if (c1 != *(u32 *)(self + 8)) x = (s32)vcall<u32>(self, 0x1c, c1) + 1;
  u32 c2 = *(u32 *)(b + 8);
  if (c2 != *(u32 *)(self + 8)) y = (s32)vcall<u32>(self, 0x1c, c2) + 1;
  if (x < y) x = y;
  return x;
}
PCREG(4e80f0, fn4e80f0);

// 0x576560: thiscall(a) ret 4 bool: slot 0xd8() true -> 0; a==1: 0x5764c0(this), 1; a==2: 0x5769c0(this), 1; else 0x574200(this,a)
static u32 THISCALL fn576560(u8 *self, u32 a) {
  if ((u8)vcall<u32>(self, 0xd8)) return 0;
  if (a == 1) {
    ext_5764c0(self);
    return 1;
  }
  if (a == 2) {
    ext_5769c0(self);
    return 1;
  }
  return ext_574200(self, a);
}
PCREG(576560, fn576560);

// 0x5a0050: thiscall(a) ret 4 bool: v=table->slot 0x58(a); b=slot 0x504(); c=slot 0x500(); v && (v==b || v==c)
static u32 THISCALL fn5a0050(u8 *self, u32 a) {
  u32 v = vcall<u32>(SYS_TABLE, 0x58, a);
  u32 b = vcall<u32>(self, 0x504);
  u32 c = vcall<u32>(self, 0x500);
  if (v == 0) return 0;
  return v == b || v == c;
}
PCREG(5a0050, fn5a0050);

// 0x5ed170: thiscall(a) ret 4: 0x5ec190(this,a); a->slot 0x68(this+0xa7); a->slot 0x3c(([this+0xcf]-[this+0xcb])>>2); for p in [this+0xcb] .. [this+0xcf]: a->slot 0x10(*p, 0x10)
static void THISCALL fn5ed170(u8 *self, u8 *a) {
  ext_5ec190(self, a);
  vcall<u32>(a, 0x68, (u32)(self + 0xa7));
  s32 n = (s32)(*(u32 *)(self + 0xcf) - *(u32 *)(self + 0xcb)) >> 2;
  vcall<u32>(a, 0x3c, (u32)n);
  u32 *p = *(u32 **)(self + 0xcb);
  if (p == *(u32 **)(self + 0xcf)) return;
  do {
    vcall<u32>(a, 0x10, *p, 0x10u);
    p++;
  } while (p != *(u32 **)(self + 0xcf));
}
PCREG(5ed170, fn5ed170);

// 0x63b6a0: thiscall: p=[this+0x14]->slot 0(([this+0x1c]<<12)+0x1010); !p -> 0; [this+0x18]++; page=(p+0x100f)&~0xfff; byte [this+0x10]=[this+0x18]; hdr=page-0x10; [hdr+4]=p; byte [hdr+1]=0; n entries [page+4+0x1000*i]=hdr; returns hdr
static u32 THISCALL fn63b6a0(u8 *self) {
  u32 n = *(u32 *)(self + 0x1c);
  u32 size = (n << 12) + 0x1010;
  u32 p = vcall<u32>(*(u8 **)(self + 0x14), 0, size);
  if (!p) return 0;
  (*(u32 *)(self + 0x18))++;
  u32 page = (p + 0x100f) & 0xfffff000u;
  self[0x10] = (u8) * (u32 *)(self + 0x18);
  u32 hdr = page - 0x10;
  *(u32 *)(hdr + 4) = p;
  *(u8 *)(hdr + 1) = 0;
  if (*(u32 *)(self + 0x1c) != 0) {
    u32 ecx = page + 4;
    u32 i = 0;
    do {
      *(u32 *)ecx = hdr;
      ecx += 0x1000;
      i++;
    } while (i != *(u32 *)(self + 0x1c));
  }
  return hdr;
}
PCREG(63b6a0, fn63b6a0);

// 0x650040: thiscall(a) ret 4: slot 0x40(); c=[this+0xbd]: c->slot 0x64(), v=c->slot 0x1c()-0x32000 -> [this+0x23]; *a=c->slot 0x20(v); cdecl 0x42ab62(0x6c3384, v/1024); [this+0x1f]=*a; returns v
static u32 THISCALL fn650040(u8 *self, u32 *a) {
  vcall<u32>(self, 0x40);
  vcall<u32>(*(u8 **)(self + 0xbd), 0x64);
  u32 x = vcall<u32>(*(u8 **)(self + 0xbd), 0x1c);
  u8 *c = *(u8 **)(self + 0xbd);
  s32 v = (s32)(x - 0x32000u);
  *(s32 *)(self + 0x23) = v;
  u32 r = vcall<u32>(c, 0x20, (u32)v);
  *a = r;
  s32 w = *(s32 *)(self + 0x23);
  w = (w + ((w >> 31) & 0x3ff)) >> 10;
  ext_42ab62(0x6c3384, w);
  *(u32 *)(self + 0x1f) = *a;
  return *(u32 *)(self + 0x23);
}
PCREG(650040, fn650040);
