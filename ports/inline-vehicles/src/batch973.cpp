// batch973.cpp - residue-04 (core todo), batch 973: CMoveAlongPath::ChangePath(ZSHAPE*, float), 0x523040, thiscall, ret 8.
// A null shape does nothing. Otherwise: the debug channel (0x700390 vslot 0x20(0x6a0778, 0xcb)) gets a cdecl vslot 0x2c with
// (0x6a07e8); then [this+0x4b] = shape, [this+0x4f] = 0, [this+0x53] = [shape+0x20], [this+0x39] = 3, [this+4] = dist, and
// [this+0x42]/[this+0x20] = (1.0, 1.0) when dist == 0, else (0, -1.0); [this+0x34] = 0; then 0x523280(this) (stood in).
#include "ff.h"

extern "C" void THISCALL ext_523280(void *self);   // stood in by the checker

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x523040 CMoveAlongPath::ChangePath(ZSHAPE*, float).
static void THISCALL changePath(u8 *t, u8 *shape, float dist) {
  if (!shape)
    return;
  u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6a0778u, 0xcbu);
  u32 fn = *(u32 *)(*(u32 *)ch + 0x2c);
  ((u32(*)(void *, u32))fn)(ch, 0x6a07e8u);
  D(t, 0x4b) = (u32)shape;
  D(t, 0x4f) = 0;
  D(t, 0x53) = D(shape, 0x20);
  D(t, 0x39) = 3;
  F(t, 4) = dist;
  if (dist == 0.0f) {
    D(t, 0x42) = 0x3f800000u;
    D(t, 0x20) = 0x3f800000u;
  } else {
    D(t, 0x42) = 0;
    D(t, 0x20) = 0xbf800000u;
  }
  t[0x34] = 0;
  ext_523280(t);
}
PCREG(523040, changePath);
