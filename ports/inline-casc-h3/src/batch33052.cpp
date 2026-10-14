// batch33052.cpp - h3 () batch 33052: tiny tier C wrappers (vcalls, import call, call sequence)
#include "ff.h"

extern "C" void THISCALL ext_54e600(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5d0df0(u8 *self);
extern "C" void THISCALL ext_5d2eb0(u8 *self);
extern "C" void THISCALL ext_5d1530(u8 *self);
extern "C" void THISCALL ext_5d28c0(u8 *self);
extern "C" void THISCALL ext_5ce0b0(u8 *self);
extern "C" u32 THISCALL ext_5d1ea0(u8 *self);

// 0x50a410: thiscall(a) ret 4: vt of a is read first; r = slot 0x38(); a->slot 0(r)
static u32 THISCALL fn50a410(u8 *self, u8 *a) {
  u8 *vta = *(u8 **)a;
  u32 r = vcall<u32>(self, 0x38);
  return ((u32(THISCALL *)(u8 *, u32)) * (u32 *)vta)(a, r);
}
PCREG(50a410, fn50a410);

// 0x5217c0: thiscall(a) ret 4: [this+0x260c] = (u8)slot 0x310(a) ? a : 0
static void THISCALL fn5217c0(u8 *self, u32 a) {
  u8 al = (u8)vcall<u32>(self, 0x310, a);
  *(u32 *)(self + 0x260c) = al ? a : 0;
}
PCREG(5217c0, fn5217c0);

// 0x54e920: thiscall(a) ret 4: 0x54e600(a); [this+0x2d6] = import(0x6763b0)(this+0x1ca, 0x678ccc) (cdecl)
typedef u32 (__attribute__((cdecl)) *imp_cdecl_t)(u32, u32);
static void THISCALL fn54e920(u8 *self, u32 a) {
  ext_54e600(self, a);
  u32 r = (*(imp_cdecl_t *)0x6763b0)((u32)(self + 0x1ca), 0x678ccc);
  *(u32 *)(self + 0x2d6) = r;
}
PCREG(54e920, fn54e920);

// 0x5ceb30: thiscall: [this+0xb46]=0; five calls; tail-call 0x5d1ea0
static u32 THISCALL fn5ceb30(u8 *self) {
  self[0xb46] = 0;
  ext_5d0df0(self);
  ext_5d2eb0(self);
  ext_5d1530(self);
  ext_5d28c0(self);
  ext_5ce0b0(self);
  return ext_5d1ea0(self);
}
PCREG(5ceb30, fn5ceb30);

// 0x656900: thiscall(a,b) ret 8: r = slot 0xc(a); return slot 0x144(r, b)
static u32 THISCALL fn656900(u8 *self, u32 a, u32 b) {
  u32 r = vcall<u32>(self, 0xc, a);
  return vcall<u32>(self, 0x144, r, b);
}
PCREG(656900, fn656900);

// 0x4739b0: thiscall(a) ret 4: i = clamp(a, 0, 3); return slot 0x230([this+0x23e+4i], 1)
static u32 THISCALL fn4739b0(u8 *self, int a) {
  int i = a < 0 ? 0 : (a > 3 ? 3 : a);
  return vcall<u32>(self, 0x230, *(u32 *)(self + 0x23e + i * 4), 1u);
}
PCREG(4739b0, fn4739b0);

// 0x47fb70: thiscall: o=[this+4]; if (o && !(u8)o->slot 0xc()) tail slot 0x14()
static void THISCALL fn47fb70(u8 *self) {
  u8 *o = *(u8 **)(self + 4);
  if (!o) return;
  if ((u8)vcall<u32>(o, 0xc)) return;
  vcall<u32>(self, 0x14);
}
PCREG(47fb70, fn47fb70);

// 0x51f780: thiscall(a) ret 4: [this+0x16d5]=(u8)a; if !(u8)slot 0x310([this+0x1654]) [this+0x16d5]=0
static void THISCALL fn51f780(u8 *self, u32 a) {
  *(u32 *)(self + 0x16d5) = (u8)a;
  if (!(u8)vcall<u32>(self, 0x310, *(u32 *)(self + 0x1654))) *(u32 *)(self + 0x16d5) = 0;
}
PCREG(51f780, fn51f780);
