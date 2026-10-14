// batch757.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

extern "C" void THISCALL ext_4673d0(u8 *self);   // original, thiscall, no stack args

typedef u32(THISCALL *VtNone)(u8 *);
typedef void(THISCALL *VtVoidNone)(u8 *);
typedef void(THISCALL *VtTwo)(u8 *, u32, u32);   // ecx = object, then two stack words
typedef u32(THISCALL *VtOne)(u8 *, u32);

// 0x484c50, thiscall() void (tail jump to vt[0x368]). Name GUESS (first-call setup).
static void THISCALL firstCallSetup_484c50(u8 *self) {
  u32 old = *(u32 *)(self + 0x60a);
  *(u32 *)(self + 0x60a) = old + 1;
  if (old != 0) return;
  VtVoidNone f418 = (VtVoidNone)(*(u32 *)(*(u32 *)self + 0x418));
  f418(self);
  VtTwo f384 = (VtTwo)(*(u32 *)(*(u32 *)self + 0x384));
  f384(self, (u32)(self + 0x5ce), (u32)(self + 0x5f2));
  VtNone f428 = (VtNone)(*(u32 *)(*(u32 *)self + 0x428));
  u32 r = f428(self);
  *(u32 *)(self + 0x5ca) = r;
  u8 *rm = *(u8 **)0x70039cu;
  u8 *obj = *(u8 **)(rm + 0x9b);
  VtOne f58 = (VtOne)(*(u32 *)(*(u32 *)obj + 0x58));
  u32 r2 = f58(obj, r);
  if (r2 != 0) {
    VtTwo f94 = (VtTwo)(*(u32 *)(*(u32 *)r2 + 0x94));
    f94((u8 *)r2, (u32)(self + 0x5ce), (u32)(self + 0x5f2));
  } else {
    *(u32 *)(self + 0x5ca) = 0;
  }
  ext_4673d0(self);
  VtNone f368 = (VtNone)(*(u32 *)(*(u32 *)self + 0x368));
  f368(self);
}
PCREG(484c50, firstCallSetup_484c50);
