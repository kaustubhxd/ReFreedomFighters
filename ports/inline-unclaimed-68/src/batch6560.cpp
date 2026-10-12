// batch6560.cpp - unclaimed-68 batch 56 (claim 57): 0x5124c0, ZMoveOnSpline::ClassInit2() (name from the residue file, medium).
// 0x5124c0 calls 0x45d3a0 (exe, run as is), then falls into the body at 0x5124d0 (ported here). Callees: 0x513d10 and 0x4de7a0 (exe).
#include "ff.h"

typedef void(THISCALL *VSelf2Args)(u8 *self, u32 a, u32 b);
typedef void(THISCALL *VNoArgVoid)(u8 *self);
typedef u32(THISCALL *VBc7)(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

extern "C" void THISCALL ext_45d3a0(u8 *self);   // ret 0
extern "C" void THISCALL ext_513d10(u8 *self);   // ret 0
extern "C" void THISCALL ext_4de7a0(void *self); // ret 0 (writes a 9-dword matrix initialiser through ecx)

static void THISCALL zmosClassInit2Body(u8 *self) {
  ((VSelf2Args)*(u32 *)(*(u8 **)self + 0x110))(self, 0x10u, 0u);
  ((VSelf2Args)*(u32 *)(*(u8 **)self + 0x2c8))(self, *(u32 *)(self + 0xce), 0u);
  ext_513d10(self);
  u8 *o = *(u8 **)(self + 0x134);
  if (o) {
    ((VNoArgVoid)*(u32 *)(*(u8 **)o + 0x28))(o);
    u32 l34[9];
    ext_4de7a0(l34);
    o = *(u8 **)(self + 0x134);
    u32 l10[3] = {0u, 0u, 0u};
    u32 mgrv = *(u32 *)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
    u8 *res = (u8 *)((VBc7)*(u32 *)(*(u8 **)o + 0x1bc))(o, mgrv, (u32)l34, (u32)l10, 0u, 0u, 0u, 1u);
    *(u8 **)(self + 0x134) = res;
    ((VNoArgVoid)*(u32 *)(*(u8 **)res + 0x28))(res);
  }
  ((VNoArgVoid)*(u32 *)(*(u8 **)self + 0x2e4))(self);
}

// 0x5124c0 (ZMoveOnSpline::ClassInit2, residue name): 0x45d3a0 then the body.
static void THISCALL zmosClassInit2(u8 *self) {
  ext_45d3a0(self);
  zmosClassInit2Body(self);
}
PCREG(5124c0, zmosClassInit2);
