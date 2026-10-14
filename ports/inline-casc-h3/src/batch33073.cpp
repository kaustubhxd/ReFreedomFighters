// batch33073.cpp - h3 () batch 33073: tier C wrappers
#include "ff.h"

extern "C" void THISCALL ext_44b610(u8 *self);
extern "C" void __attribute__((cdecl)) ext_44b740(u8 *p);
extern "C" u8 *THISCALL ext_4daff0(u8 *self);
extern "C" void THISCALL ext_4d9f90(u8 *self);
extern "C" void THISCALL ext_530b60(u8 *self, u32 *out, u32 a);     // ret 8
extern "C" void THISCALL ext_530db0(u8 *self, u32 *out, u32 a);     // ret 8
extern "C" void THISCALL ext_52e4f0(u8 *self, u32 *a, u32 *b, u32 c);   // ret 0xc
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 n);
extern "C" u32 THISCALL ext_603110(u8 *self);
extern "C" void THISCALL ext_6031e0(u8 *self, u8 *p);               // ret 4
extern "C" void THISCALL ext_451a00(u8 *self);                      // tail to 0x43de70
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (__attribute__((cdecl)) *log2_t)(u8 *, u32);

// 0x4b3460: thiscall(a,b) ret 8: id match against words [this+0x72] (clears byte [0x182]) and [this+0x70] (if byte [0x184] or [0x182]: slot 0xa0(); release the table object [this+0x6c]); returns 0
static u32 THISCALL fn4b3460(u8 *self, u32 a, u32 b) {
  u16 w = (u16)a;
  if (w == *(u16 *)(self + 0x72)) self[0x182] = 0;
  if (w == *(u16 *)(self + 0x70)) {
    if (self[0x184] != 0 || self[0x182] != 0) {
      vcall<u32>(self, 0xa0);
      u8 *o = vcall<u8 *>(SYS_TABLE, 0x60, *(u32 *)(self + 0x6c));
      if (o) {
        ext_44b610(o);
        ext_44b740(o);
      }
      *(u32 *)(self + 0x6c) = 0;
    }
  }
  return 0;
}
PCREG(4b3460, fn4b3460);

// 0x4cf410: thiscall(a) ret 4: [this+0xc] negative -> global log; c=*a ? **a : [this+0x20]; *a=c; c ? c+(2-[this+0x18])*4 : 0
static u32 THISCALL fn4cf410(u8 *self, u32 *a) {
  if ((s32) * (u32 *)(self + 0xc) < 0) {
    u8 *g = G(u8 *, 0x700390);
    u8 *r = vcall<u8 *>(g, 0x20, 0x695b7cu, 0x484u);
    (*(log2_t *)(*(u8 **)r + 0x2c))(r, 0x695c50);
  }
  u32 c = *a;
  if (c == 0) c = *(u32 *)(self + 0x20);
  else c = *(u32 *)c;
  *a = c;
  if (c == 0) return 0;
  return c + (2 - *(u32 *)(self + 0x18)) * 4;
}
PCREG(4cf410, fn4cf410);

// 0x4dabe0: thiscall: if byte [this+0x3c]: x=[this+0x50] ? [[this+0x50]+0x54] : 0; r=0x4daff0([x+8]); r && r->slot 0x31c(this); if [this+0x3c]&0x4000: 0x4d9f90(this); w=word [this+0x5c]; w && o=[[sysobj+0x9b]+8]->slot 0x5c(w) && [o+0x18]=0
static void THISCALL fn4dabe0(u8 *self) {
  if (self[0x3c]) {
    u8 *p = *(u8 **)(self + 0x50);
    u8 *x = p ? *(u8 **)(p + 0x54) : 0;
    u8 *r = ext_4daff0(*(u8 **)(x + 8));
    if (r) vcall<u32>(r, 0x31c, (u32)self);
  }
  if (*(u32 *)(self + 0x3c) & 0x4000) {
    ext_4d9f90(self);
    u16 w = *(u16 *)(self + 0x5c);
    if (w) {
      u8 *t = *(u8 **)(SYS_TABLE + 8);
      u8 *o = vcall<u8 *>(t, 0x5c, (u32)w);
      if (o) *(u32 *)(o + 0x18) = 0;
    }
  }
}
PCREG(4dabe0, fn4dabe0);

// 0x52b020: thiscall(a,b,c) ret 0xc (stack cookie): s=[this+0x65]; 0x530b60(s,&t1,a); 0x530db0(s,&t2,b); 0x52e4f0(s,&t1,&t2,c)
static void THISCALL fn52b020(u8 *self, u32 a, u32 b, u32 c) {
  u32 t1[2];
  u32 t2[2];
  u8 *s = *(u8 **)(self + 0x65);
  ext_530b60(s, t1, a);
  s = *(u8 **)(self + 0x65);
  ext_530db0(s, t2, b);
  s = *(u8 **)(self + 0x65);
  ext_52e4f0(s, t1, t2, c);
}
PCREG(52b020, fn52b020);

// 0x5a4690: thiscall(a) ret 4: a && (u8)a->slot 0x1e0(0x2003e8) && p=[a+0x54]: k=[p+4]-3; k != -1 && k <= 6 (signed): this+0x61+18k else 0
static u32 THISCALL fn5a4690(u8 *self, u8 *a) {
  if (!a) return 0;
  if (!(u8)vcall<u32>(a, 0x1e0, 0x2003e8u)) return 0;
  u8 *p = *(u8 **)(a + 0x54);
  if (!p) return 0;
  s32 k = (s32)(*(u32 *)(p + 4) - 3u);
  if (k == -1 || k > 6) return 0;
  return (u32)(self + 0x61 + k * 18);
}
PCREG(5a4690, fn5a4690);

// 0x5b96d0: thiscall(a) ret 4 bool: [this+4]&=~0x40; a->slot 0x3c/0x3c/0x64/0x64/0x3c/0x3c of [this+0x48..0x5c]; returns 1
static u32 THISCALL fn5b96d0(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<u32>(a, 0x3c, *(u32 *)(self + 0x48));
  vcall<u32>(a, 0x3c, *(u32 *)(self + 0x4c));
  vcall<u32>(a, 0x64, *(u32 *)(self + 0x50));
  vcall<u32>(a, 0x64, *(u32 *)(self + 0x54));
  vcall<u32>(a, 0x3c, *(u32 *)(self + 0x58));
  vcall<u32>(a, 0x3c, *(u32 *)(self + 0x5c));
  return 1;
}
PCREG(5b96d0, fn5b96d0);

// 0x5fb920: thiscall: p=new(0x15) initialised (vtable 0x6b8508, zero fields); x=0x603110([this]); p->slot 0xc(x+5); 0x6031e0([this], p); returns p
static u8 *THISCALL fn5fb920(u8 *self) {
  u8 *p = (u8 *)ext_41e290(0x15);
  if (p) {
    *(u32 *)p = 0x6b8508;
    *(u32 *)(p + 4) = 0;
    *(u32 *)(p + 8) = 0;
    *(u32 *)(p + 0xc) = 0;
    p[0x14] = 0;
  }
  u32 x = ext_603110(*(u8 **)self);
  vcall<u32>(p, 0xc, x + 5);
  ext_6031e0(*(u8 **)self, p);
  return p;
}
PCREG(5fb920, fn5fb920);

// 0x4572d0: thiscall(a) ret 4: vtable 0x6830e0; e=[this+0x84]: delete([e+4],0x28), delete(e,8); 0x451a00(this); a&1: (a&4 ? cdecl 0x4690b0(this,0xd9) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn4572d0(u8 *self, u32 a) {
  u8 *e = *(u8 **)(self + 0x84);
  *(u32 *)self = 0x6830e0;
  if (e) {
    ext_634273(*(void **)(e + 4), 0x28);
    ext_634273(*(void **)(self + 0x84), 8);
  }
  ext_451a00(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0xd9);
  }
  return self;
}
PCREG(4572d0, fn4572d0);
