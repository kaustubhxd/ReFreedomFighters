// batch946.cpp - two label-A+D rows from the area-50 claim (2026-10-12), both read in full.
//  0x562e20 (no name in the map): thiscall (ECX = this), no args, plain ret (void). If byte [this+0x84] != 0: tail-jump to 0x59c620 with ECX = [this+0x94]
//    (stood in; no args). Else if [this+0x48] == 0: o = slot +0x84 of this; tail-jump to slot +0x300 of o (no args). Else: if byte [this+0x86] != 0,
//    o1 = slot +0x84 of this and slot +0x300 of o1 (no args). Then o2 = slot +0x84 of this and slot +0x2f8 of o2 with one arg ([this+0x48]).
//  0x574200 (no name in the map): thiscall (ECX = this), one arg (v), ret 4, returns eax. r = slot +0xd8 of this (no args). If low byte of r is
//    non-zero, return r with its low byte cleared (xor al, al). If v == 0x2b67: o = slot +0x84 of this; q = slot +0x300 of o (no args); return
//    (q with low byte 1). Else return 0x562c20(this, v) (thiscall, one arg, ret 4; stood in).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_59c620(void *self);                 // stood in (no args, plain ret)
extern "C" u32 THISCALL ext_562c20(void *self, u32 v);           // stood in (one arg, ret 4)

// 0x562e20 (no name in the map).
static void THISCALL Dispatch562e20(u8 *self) {
  if (U8(self, 0x84)) {
    ext_59c620(FP(self, 0x94));
    return;
  }
  if (U32(self, 0x48) == 0) {
    void *o = vcall<void *>(self, 0x84);
    vcall<void>(o, 0x300);
    return;
  }
  if (U8(self, 0x86)) {
    void *o1 = vcall<void *>(self, 0x84);
    vcall<void>(o1, 0x300);
  }
  void *o2 = vcall<void *>(self, 0x84);
  vcall<void>(o2, 0x2f8, U32(self, 0x48));
}
PCREG(562e20, Dispatch562e20);

// 0x574200 (no name in the map).
static u32 THISCALL Check574200(u8 *self, u32 v) {
  u32 r = vcall<u32>(self, 0xd8);
  if ((u8)r) return r & 0xffffff00u;
  if (v == 0x2b67) {
    void *o = vcall<void *>(self, 0x84);
    u32 q = vcall<u32>(o, 0x300);
    return (q & 0xffffff00u) | 1u;
  }
  return ext_562c20(self, v);
}
PCREG(574200, Check574200);
