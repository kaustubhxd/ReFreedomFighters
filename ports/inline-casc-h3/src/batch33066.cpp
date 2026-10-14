// batch33066.cpp - h3 () batch 33066: tier C wrappers
#include "ff.h"

extern "C" void THISCALL ext_4c5770(u8 *self, u32 a);                // ret 4
extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 a);                // ret 4
extern "C" u32 THISCALL ext_5a2e20(u8 *self, u32 a, u32 b, u32 c, u32 d);   // ret 0x10
extern "C" u32 THISCALL ext_563620(u8 *self, u32 a, u32 b);          // ret 8
extern "C" u8 *THISCALL ext_591f00(u8 *self);
extern "C" u32 THISCALL ext_4614d0(u8 *self, u32 a, u32 b, u32 c);   // ret 0xc

#define SYS (*(u8 **)0x70039c)
typedef u32 (*hook_t)();
typedef u32 (__attribute__((cdecl)) *log3_t)(u8 *, u32, u32);

// 0x461a00: thiscall bool: for i < [this+0x20]: if (u8)slot 0x324(i) return 1 (vtable re-read each time); else 0
static u32 THISCALL fn461a00(u8 *self) {
  u32 n = *(u32 *)(self + 0x20);
  if (n == 0) return 0;
  u32 i = 0;
  do {
    u8 *vt = *(u8 **)self;
    u32 r = ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vt + 0x324))(self, i);
    if ((u8)r) return (r & 0xffffff00u) | 1;
    i++;
  } while (i != n);
  return 0;
}
PCREG(461a00, fn461a00);

// 0x4901a0: stdcall(a) ret 4: node in list [0x7003bc] (next +0x14) with [+4]==0 and dword [+0x23]==a -> node; else log slot 0x30 and 0
static u8 *STDCALL fn4901a0(u32 a) {
  u8 *n = G(u8 *, 0x7003bc);
  while (n) {
    if (*(u32 *)(n + 4) == 0 && *(u32 *)(n + 0x23) == a) return n;
    n = *(u8 **)(n + 0x14);
  }
  u8 *g = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x68d798u, 0xf00u);
  (*(log3_t *)(*(u8 **)r + 0x30))(r, 0x68df48, a);
  return 0;
}
PCREG(4901a0, fn4901a0);

// 0x4c54d0: thiscall(a,b) ret 8: toggles/sets byte [this+0x52] by which id (a) matches; 0x4c5770(flag); returns 1
static u32 THISCALL fn4c54d0(u8 *self, u32 a, u32 b) {
  u16 w = (u16)a;
  if (w == *(u16 *)(self + 0x4c)) {
    u8 f = self[0x52] == 0;
    self[0x52] = f;
    ext_4c5770(self, (a & 0xff00u) | f);   // eax = ax with al replaced by the flag (eax is 0 at function entry)
    return 1;
  }
  if (w == *(u16 *)(self + 0x4e)) {
    self[0x52] = 1;
    ext_4c5770(self, 1);
    return 1;
  }
  if (w == *(u16 *)(self + 0x50)) {
    self[0x52] = 0;
    ext_4c5770(self, 0);
  }
  return 1;
}
PCREG(4c54d0, fn4c54d0);

// 0x55ca30: thiscall(a) ret 4: p1=0x5003d0([a+4],1); p0=0x5003d0([a+4],0); 0x5a2e20([this+0x1c], *p0, *p1!=0, 0, 5.0f)
static u32 THISCALL fn55ca30(u8 *self, u8 *a) {
  u32 *p1 = ext_5003d0(*(u8 **)(a + 4), 1);
  u32 *p0 = ext_5003d0(*(u8 **)(a + 4), 0);
  u32 flag = *p1 != 0;
  return ext_5a2e20(*(u8 **)(self + 0x1c), *p0, flag, 0, 0x40a00000);
}
PCREG(55ca30, fn55ca30);

// 0x56fe40: thiscall: select string by [this+0x4b6]; r=[[sysobj+0x9b]+0xae4]->slot 0(str1, sel); returns 0x563620(this, [this+0x199], r)
static u32 THISCALL fn56fe40(u8 *self) {
  u32 k = *(u32 *)(self + 0x4b6);
  u32 sel = k == 1 ? 0x6a7b84 : (k == 2 ? 0x6a7b7c : (k == 3 ? 0x6a7b74 : 0x6a7b8c));
  u8 *o = *(u8 **)(*(u8 **)(SYS + 0x9b) + 0xae4);
  u32 r = vcall<u32>(o, 0, 0x6a67e8u, sel);
  return ext_563620(self, *(u32 *)(self + 0x199), r);
}
PCREG(56fe40, fn56fe40);

// 0x5e02e0: thiscall bool: p=0x591f00([this+8]); p->slot 0x2e8(); [this+0x10]=d: d ? (r=[this+8]->slot 0x230(d,1); 0x4614d0(r,0.016f,0x465710,0); eax low byte 1) : tail this->slot 0xc()
static u32 THISCALL fn5e02e0(u8 *self) {
  u8 *p = ext_591f00(*(u8 **)(self + 8));
  vcall<u32>(p, 0x2e8);
  u32 d = *(u32 *)(self + 0x10);
  if (!d) return vcall<u32>(self, 0xc);
  u32 r = vcall<u32>(*(u8 **)(self + 8), 0x230, d, 1u);
  u32 x = ext_4614d0((u8 *)r, 0x3c83126f, 0x465710, 0);
  return (x & 0xffffff00u) | 1;
}
PCREG(5e02e0, fn5e02e0);

// 0x5f4e00: thiscall(a) ret 4: kind byte [this+4]==1: [this] = *a * [this] (returns it); else log + assert hook
static u32 THISCALL fn5f4e00(u8 *self, s32 *a) {
  if (self[4] == 1) {
    s32 v = *a * *(s32 *)self;
    *(s32 *)self = v;
    return (u32)v;
  }
  u8 *g = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x69c8e0u, 0x8au);
  (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c938);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(5f4e00, fn5f4e00);

// 0x64fd10: thiscall(a) ret 4: [this+0x2c] ? a + it : [this+0x68] ? tail slot 0x20(a) of it : log slot 0x2c + 0
static u32 THISCALL fn64fd10(u8 *self, u32 a) {
  u32 x = *(u32 *)(self + 0x2c);
  if (x) return a + x;
  u8 *y = *(u8 **)(self + 0x68);
  if (y) return vcall<u32>(y, 0x20, a);
  u8 *g = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x6c3180u, 0x793u);
  (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x6c3600, a);
  return 0;
}
PCREG(64fd10, fn64fd10);
