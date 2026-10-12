// batch210.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. Two wrappers that make
// several vtable calls on one member object.
#include "ff.h"

typedef void(THISCALL *VtArg1)(u8 *, u32);             // slot taking one stack word, no result used
typedef u32(THISCALL *VtNoArg)(u8 *);                   // slot taking no stack words, returns eax
typedef u32(THISCALL *VtArg1Ret)(u8 *, u32);            // slot taking one stack word, returns eax
typedef void(THISCALL *VtArg2)(u8 *, u32, u32);         // slot taking two stack words

// 0x4415f0, thiscall(a): obj = [this+0x44]; if obj is null, return. obj->vt[0x3c](obj, a); if obj->vt[0x14]() is nonzero,
// return. Otherwise, if [this+0x44] is set, vt[0](that, 1), and then [this+0x44] = 0. Name GUESS.
static void THISCALL callAndMaybeRelease_4415f0(u8 *self, u32 a) {
  u8 *obj = *(u8 **)(self + 0x44);
  if (!obj) return;
  VtArg1 f3c = (VtArg1)(*(u32 *)(*(u32 *)obj + 0x3c));
  f3c(obj, a);
  obj = *(u8 **)(self + 0x44);
  VtNoArg f14 = (VtNoArg)(*(u32 *)(*(u32 *)obj + 0x14));
  if (f14(obj)) return;
  u8 *o2 = *(u8 **)(self + 0x44);
  if (o2) {
    VtArg1 f0 = (VtArg1)(*(u32 *)(*(u32 *)o2 + 0));
    f0(o2, 1);
  }
  *(u8 **)(self + 0x44) = nullptr;
}
PCREG(4415f0, callAndMaybeRelease_4415f0);

// 0x561e30, thiscall(): obj = [this+0x5c]; if obj: r = obj->vt[0x318](obj, 3); if r: r->vt[0x31c](r, obj, 4).
// Then r2 = obj->vt[0x318](obj, 4); if r2: r2->vt[0x31c](r2, obj, 3). Name GUESS.
static void THISCALL twoPairs_561e30(u8 *self) {
  u8 *obj = *(u8 **)(self + 0x5c);
  if (!obj) return;
  VtArg1Ret f318 = (VtArg1Ret)(*(u32 *)(*(u32 *)obj + 0x318));
  u8 *r = (u8 *)f318(obj, 3);
  if (r) {
    VtArg2 f31c = (VtArg2)(*(u32 *)(*(u32 *)r + 0x31c));
    f31c(r, (u32)obj, 4);
  }
  obj = *(u8 **)(self + 0x5c);
  u8 *r2 = (u8 *)f318(obj, 4);
  if (r2) {
    VtArg2 f31c2 = (VtArg2)(*(u32 *)(*(u32 *)r2 + 0x31c));
    f31c2(r2, (u32)obj, 3);
  }
}
PCREG(561e30, twoPairs_561e30);
