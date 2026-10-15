// batch33062.cpp - h3 (Sonnet) batch 33062: dtor-flag dispatchers and small wrappers
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);
extern "C" void THISCALL ext_480fd0(u8 *self);
extern "C" void THISCALL ext_4878d0(u8 *self);
extern "C" void THISCALL ext_465660(u8 *self);
extern "C" void THISCALL ext_480ff0(u8 *self);
extern "C" void THISCALL ext_4ee4e0(u8 *self);
extern "C" void THISCALL ext_52a600(u8 *self);

#define SYS (*(u8 **)0x70039c)

// 0x465720: thiscall(a) ret 4: 0x465660(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x1d2) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn465720(u8 *self, u32 a) {
  ext_465660(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x1d2);
  }
  return self;
}
PCREG(465720, fn465720);

// 0x481180: thiscall(a) ret 4: 0x480ff0(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x64b) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn481180(u8 *self, u32 a) {
  ext_480ff0(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x64b);
  }
  return self;
}
PCREG(481180, fn481180);

// 0x4faca0: thiscall(a) ret 4: 0x4ee4e0(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x93) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn4faca0(u8 *self, u32 a) {
  ext_4ee4e0(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x93);
  }
  return self;
}
PCREG(4faca0, fn4faca0);

// 0x52a6c0: thiscall(a) ret 4: 0x52a600(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x99) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn52a6c0(u8 *self, u32 a) {
  ext_52a600(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x99);
  }
  return self;
}
PCREG(52a6c0, fn52a6c0);

// 0x4b4160: thiscall: g=[sysobj+0x1907] && g->slot 0x14(str); delete [this+0x90] and [this+0x94] (size 1) when set
static void THISCALL fn4b4160(u8 *self) {
  u8 *g = *(u8 **)(SYS + 0x1907);
  if (g) vcall<u32>(g, 0x14, 0x692054u);
  u8 *p = *(u8 **)(self + 0x90);
  if (p) ext_634273(p, 1);
  u8 *q = *(u8 **)(self + 0x94);
  if (q) ext_634273(q, 1);
}
PCREG(4b4160, fn4b4160);

// 0x5613a0: thiscall(a,b) ret 8: 8-entry pair array at this+0x98 (count [this+0xd8]); full -> log slot 0x2c via global 0x700390
typedef u32 (__attribute__((cdecl)) *log2_t)(u8 *, u32);
static u32 THISCALL fn5613a0(u8 *self, u32 a, u32 b) {
  int n = *(int *)(self + 0xd8);
  if (n < 8) {
    *(u32 *)(self + n * 8 + 0x98) = a;
    n = *(int *)(self + 0xd8);
    *(u32 *)(self + n * 8 + 0x9c) = b;
    (*(u32 *)(self + 0xd8))++;
    return b;
  }
  u8 *g = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x6a64b4u, 0xf5u);
  return (*(log2_t *)(*(u8 **)r + 0x2c))(r, 0x6a6560);
}
PCREG(5613a0, fn5613a0);

// 0x5b9830: thiscall: sysobj->slot 0xe4(0x51) -> this->slot 0x88(); sysobj->slot 0xe4(0x57) -> tail this->slot 0x8c()
static u32 THISCALL fn5b9830(u8 *self) {
  if ((u8)vcall<u32>(SYS, 0xe4, 0x51u)) vcall<u32>(self, 0x88);
  u32 r = vcall<u32>(SYS, 0xe4, 0x57u);
  if ((u8)r) return vcall<u32>(self, 0x8c);
  return r;
}
PCREG(5b9830, fn5b9830);

// 0x5e1510: thiscall(a) ret 4: vtable 0x6b7820; 0x480fd0 on four sub-objects; 0x4878d0(this); a&1 -> delete(this,0x591); return this
static u8 *THISCALL fn5e1510(u8 *self, u32 a) {
  *(u32 *)self = 0x6b7820;
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if (a & 1) ext_634273(self, 0x591);
  return self;
}
PCREG(5e1510, fn5e1510);
