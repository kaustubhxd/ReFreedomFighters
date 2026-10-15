// batch33039.cpp - h3 (Sonnet) batch 33039: ctor/dtor shapes with hooked callees + two vcall tail-jump wrappers
#include "ff.h"

extern "C" void THISCALL ext_4ef200(u8 *self, u8 *src);               // thunk to 0x43f8c0, ret 4
extern "C" void THISCALL ext_54cd00(u8 *self);                         // sets vtable, ret 0
extern "C" void THISCALL ext_656e10(u8 *self);                         // sets vtable + tail, ret 0
extern "C" void THISCALL ext_43de40(u8 *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_469870(u8 *self);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);
extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 arg);

// 0x4f9c60: thiscall(src) ret 4: base copy, then copy [0x6c],[0x70]
static void THISCALL fn4f9c60(u8 *self, u8 *src) {
  ext_4ef200(self, src);
  *(u32 *)(self + 0x6c) = *(u32 *)(src + 0x6c);
  *(u32 *)(self + 0x70) = *(u32 *)(src + 0x70);
}
PCREG(4f9c60, fn4f9c60);

// 0x5493c0: scalar deleting dtor: vtable, base dtor 0x54cd00, if flags&1 delete(this, 0xa274)
static u8 *THISCALL fn5493c0(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a3338;
  ext_54cd00(self);
  if (flags & 1) ext_634273(self, 0xa274);
  return self;
}
PCREG(5493c0, fn5493c0);

// 0x607cb0: scalar deleting dtor: vtable, base dtor 0x656e10, if flags&1 delete(this, 4)
static u8 *THISCALL fn607cb0(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b9fc4;
  ext_656e10(self);
  if (flags & 1) ext_634273(self, 4);
  return self;
}
PCREG(607cb0, fn607cb0);

// 0x5c7ce0: ctor: base 0x469870, [4]|=0x20, [0x44]=0, vtable 0x6b4858, [0x4c]=0
static u8 *THISCALL fn5c7ce0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 0x4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b4858;
  *(u32 *)(self + 0x4c) = 0;
  return self;
}
PCREG(5c7ce0, fn5c7ce0);

// 0x5c5260: ctor: as above, vtable 0x6b4180, [0x14e]=0, byte [0x152]=0
static u8 *THISCALL fn5c5260(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 0x4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b4180;
  *(u32 *)(self + 0x14e) = 0;
  *(u8 *)(self + 0x152) = 0;
  return self;
}
PCREG(5c5260, fn5c5260);

// 0x47f6c0: ctor(a,b,c) ret 0xc: base 0x43de40(a,b,c), vtable 0x68af4c, [0x18]=0
static u8 *THISCALL fn47f6c0(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);
  *(u32 *)self = 0x68af4c;
  *(u32 *)(self + 0x18) = 0;
  return self;
}
PCREG(47f6c0, fn47f6c0);

// 0x5080a0: thiscall(arg) ret 4: r = *ext_5003d0([arg+4], 0) != 0; tail-call vtable slot 0x694 of [this+0x18] with r
static u32 THISCALL fn5080a0(u8 *self, u8 *arg) {
  u32 *p = ext_5003d0(*(u8 **)(arg + 4), 0);
  u32 r = *p != 0;
  return vcall<u32>(*(void **)(self + 0x18), 0x694, r);
}
PCREG(5080a0, fn5080a0);

// 0x5227f0: same with [this+0x1c], slot 0x38c
static u32 THISCALL fn5227f0(u8 *self, u8 *arg) {
  u32 *p = ext_5003d0(*(u8 **)(arg + 4), 0);
  u32 r = *p != 0;
  return vcall<u32>(*(void **)(self + 0x1c), 0x38c, r);
}
PCREG(5227f0, fn5227f0);
