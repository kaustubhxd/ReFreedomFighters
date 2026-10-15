// batch974.cpp - residue-05 (core todo), batch 974: ZFFActorIf::DrawLineToRef(OpaqueCallParameters_t&), 0x558d90, thiscall, ret 4.
// id = 0x5003d0(p->[4], 0) (stood in) is looked up in the render manager (vslot 0x58(*id)). No object: the debug channel
// (0x700390 vslot 0x20(0x6a5eb0, 0x215)) prints through a cdecl vslot 0x2c with (0x6a5f2c, [this+0x1c]+4 or the default).
// An object X: X vslot 0x84(&v0) with v0 = (0, 100, 0); Y = [this+0x1c]: vslot 0x84(&v1) with v1 = (0, 0, 0); r = -(sys vslot
// 0x1bc(0x6a5eb0, 0x22a)); then R = render manager +0xadc: vslot 0x218(&v1, &v0, r) (thiscall, the callee pops 12).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 a);   // stood in by the checker

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x558d90 ZFFActorIf::DrawLineToRef(OpaqueCallParameters_t&).
static void THISCALL drawLineToRef(u8 *t, u8 *p) {
  u32 *cell = (u32 *)ext_5003d0((void *)D(p, 4), 0);
  u8 *sys = *(u8 **)0x70039c;
  u8 *rm = *(u8 **)(sys + 0x9b);
  u8 *x = (u8 *)vcall<u32>(rm, 0x58, *cell);
  u8 *y = (u8 *)D(t, 0x1c);
  if (!x) {
    u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6a5eb0u, 0x215u);
    u32 v = D(y, 4) != 0 ? D(y, 4) : 0x67c8e8u;
    u32 fn = *(u32 *)(*(u32 *)ch + 0x2c);
    ((u32(*)(void *, u32, u32))fn)(ch, 0x6a5f2cu, v);
    return;
  }
  float v0[3] = {0.0f, 100.0f, 0.0f};
  vcall<void>(x, 0x84, (u32)v0);
  float v1[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(y, 0x84, (u32)v1);
  u32 r = -vcall<u32>(sys, 0x1bc, 0x6a5eb0u, 0x22au);
  u8 *R = (u8 *)D(rm, 0xadc);
  vcall<void>(R, 0x218, (u32)v1, (u32)v0, r);
}
PCREG(558d90, drawLineToRef);
