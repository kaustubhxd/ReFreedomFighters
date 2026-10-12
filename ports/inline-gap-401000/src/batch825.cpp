// batch825.cpp - core gameplay batch 825 (docs/20-unclaimed-65.md, batch 825): 0x4fc690 (CMAINCAMERACONTROL::Init2), a thiscall with no
// arguments. If [this+0x6e] is zero: x = slot 0x138 of the render sub-object ([0x70039c]+0x9b), slot 0x88 of x with (0x690410, &local), and
// [this+0x6e] = local. Then slot 0x240 of [this+0x44] with (this+0x4e) (one argument, callee pops), a call to 0x4fdac0 (ecx = this, other
// claim, hooked by address in the spec), and bit 22 of [[this+0x44]+0x48] is set when byte [this+0x4d] is nonzero, else cleared.
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);

extern "C" void THISCALL ext_4fdac0(u8 *self);   // thiscall, no arguments (hooked in the spec)

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }
static u32 vc2(u8 *o, u32 s, u32 a, u32 b) { return ((F2)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b); }

static void THISCALL fn4fc690(u8 *self) {
  if (*(const u32 *)(self + 0x6e) == 0) {
    u8 *x = (u8 *)vc0(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x138);
    u32 local = 0;
    vc2(x, 0x88, 0x690410, (u32)&local);
    *(u32 *)(self + 0x6e) = local;
  }
  vc1(*(u8 **)(self + 0x44), 0x240, (u32)(self + 0x4e));
  ext_4fdac0(self);
  u8 *obj = *(u8 **)(self + 0x44);
  if (*(const u8 *)(self + 0x4d) != 0)
    *(u32 *)(obj + 0x48) |= 0x400000;
  else
    *(u32 *)(obj + 0x48) &= 0xffbfffff;
}

PCREG(4fc690, fn4fc690);
