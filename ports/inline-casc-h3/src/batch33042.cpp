// batch33042.cpp - h3 () batch 33042: tier B ctors, vector push, small wrappers
#include "ff.h"

extern "C" void THISCALL ext_5e0e10(u8 *self, u32 a, u32 b);            // ret 8
extern "C" void THISCALL ext_5f4630(u8 *self);                           // ret 0
extern "C" void THISCALL ext_5f3e20(u8 *self);                           // ret 0
extern "C" void THISCALL ext_4f97f0(u8 *self, u32 a, u32 b, u32 c);     // ret 0xc
extern "C" u32 THISCALL ext_5ffd70(u8 *self, u32 a, u32 w);             // ret 8
extern "C" u32 THISCALL ext_5f5620(u8 *self, u32 a);                    // ret 4
extern "C" void THISCALL ext_5ec720(u8 *self, u32 a);                   // ret 4
extern "C" void THISCALL ext_4dbb00(u8 *self, u32 a);                   // ret 4
extern "C" void STDCALL ext_634123(u8 *p, u32 a, u32 b, u32 c, u32 d);  // ret 0x14
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);

// 0x5e0f80: ctor(a,b) ret 8
static u8 *THISCALL fn5e0f80(u8 *self, u32 a, u32 b) {
  ext_5e0e10(self, a, b);
  *(u32 *)self = 0x6b7748;
  *(u32 *)(self + 0x60c) = 0;
  *(u32 *)(self + 0x5d2) = 0;
  *(u32 *)(self + 0x608) = 0;
  *(u8 *)(self + 0x5ac) = 0;
  *(u32 *)(self + 0x5b1) = 0;
  *(u32 *)(self + 0x5ad) = 0;
  *(u8 *)(self + 0x610) = 0;
  return self;
}
PCREG(5e0f80, fn5e0f80);

// 0x5fbac0: thiscall(p) ret 4: p->[4]=this; push p onto vector at this+0x18 (grow via 0x5f4630 when full); 0x5f3e20(p)
static void THISCALL fn5fbac0(u8 *self, u8 *p) {
  u8 *v = self + 0x18;
  *(u8 **)(p + 4) = self;
  if (!(*(u32 *)(v + 8) < *(u32 *)(v + 4))) ext_5f4630(v);
  u32 n = *(u32 *)(v + 8);
  (*(u8 ***)v)[n] = p;
  (*(u32 *)(v + 8))++;
  ext_5f3e20(p);
}
PCREG(5fbac0, fn5fbac0);

// 0x4f6ab0: ctor(a,b,c) ret 0xc
static u8 *THISCALL fn4f6ab0(u8 *self, u32 a, u32 b, u32 c) {
  ext_4f97f0(self, a, b, c);
  *(u32 *)self = 0x69aaf0;
  *(u32 *)(self + 0x93) = 0;
  *(u32 *)(self + 0x8f) = 0;
  *(u32 *)(self + 0xa3) = 0;
  *(u32 *)(self + 0x9b) = 0;
  *(u32 *)(self + 0x9f) = 0;
  *(u8 *)(self + 0xa7) = 0;
  *(u32 *)(self + 0x97) = 0xbb8;
  return self;
}
PCREG(4f6ab0, fn4f6ab0);

// 0x5f4dc0: thiscall(a) ret 4 bool
static u32 THISCALL fn5f4dc0(u8 *self, u32 a) {
  u32 r = ext_5ffd70(*(u8 **)(self + 0x96), a, *(u16 *)(self + 0x1e));
  if (r == 0xffffffffu) return 0;
  *(u32 *)(self + 0xa6) = ext_5f5620(self, r);
  return 1;
}
PCREG(5f4dc0, fn5f4dc0);

// 0x4e6b40: thiscall: release owned pointers
static void THISCALL fn4e6b40(u8 *self) {
  if (self[0x14]) {
    u8 *p = *(u8 **)self;
    if (p) ext_634273(p, 0);
    *(u32 *)self = 0;
    return;
  }
  u8 *q = *(u8 **)(self + 4);
  if (q) ext_634273(q, 2);
  *(u32 *)self = 0;
}
PCREG(4e6b40, fn4e6b40);

// 0x5ed460: ctor
static u8 *THISCALL fn5ed460(u8 *self) {
  ext_5ec720(self, 9);
  *(u32 *)self = 0x6b813c;
  *(u32 *)(self + 0x42) = 9;
  *(u32 *)(self + 0xd7) = 0;
  *(u32 *)(self + 0xdb) = 0;
  *(u32 *)(self + 0xdf) = 0x100;
  *(u32 *)(self + 0xe3) = 0x100;
  *(u32 *)(self + 0xe7) = 0;
  *(u32 *)(self + 0xeb) = 0;
  *(u32 *)(self + 0xef) = 0;
  *(u32 *)(self + 0xf3) = 0;
  *(u32 *)(self + 0x5e) = 2;
  return self;
}
PCREG(5ed460, fn5ed460);

// 0x4951f0: stdcall(arr, n) ret 8: if sysobj table flag [0x5d35] call 0x4dbb00(arr[i], 1) for each i
static void STDCALL fn4951f0(u32 *arr, u32 n) {
  u8 *tab = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  if (*(u32 *)(tab + 0x5d35) == 0) return;
  for (u32 i = 0; i != n && n != 0; i++) ext_4dbb00((u8 *)arr[i], 1);
}
PCREG(4951f0, fn4951f0);

// 0x54e100: ctor: vtable, 0x634123(this+0x10, 0x6b, 4, 0x54e0a0, 0x54e160), fields
static u8 *THISCALL fn54e100(u8 *self) {
  *(u32 *)self = 0x6a3ebc;
  ext_634123(self + 0x10, 0x6b, 4, 0x54e0a0, 0x54e160);
  *(u8 *)(self + 0x1bc) = 1;
  *(u32 *)(self + 4) = 1;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 8) = 0;
  *(u8 *)(self + 0x1c9) = 0;
  *(u32 *)(self + 0x1c5) = 4;
  return self;
}
PCREG(54e100, fn54e100);
