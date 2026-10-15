// batch5803.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 103: 0x5d98b0 (GUESS name unnamed_5d98b0), thiscall, no stack args, plain ret.
// Block 1: a = this+0x88, c = this+0x8c; if a != c: v = step(a, c) where bt = trunc((float)(engine+0x48) * G(0x680a90)), d = a - c:
// if d > 0: v = (d > bt) ? bt + c : a; else v = (-d > bt) ? c - bt : a. Then 0x5d9f00(this, this+0x68, c, v), 0x5d9f00(this, this+0x60, c, v),
// 0x5d9f00(this, this+0x5c, c, v) (three hooked calls, ECX = this); this+0x8c = v. Block 2 is the same with a = this+0x90, c = this+0x94,
// the callees' first arguments this+0x74, +0x78, +0x7c, and this+0x94 = v. The 0x5d9f00 callee runs as a hooked stub in the spec.
#include "ff.h"

// 0x5d9f00, thiscall, three stack arguments (another area's function; hooked in the spec)
extern "C" void THISCALL ext_5d9f00(u8 *self, u32 a, u32 b, u32 c);

// the move step shared by both blocks: returns the new value for a, moving toward c by at most the scaled engine value
static s32 moveStep(u32 a, u32 c) {
  float scale = G(float, 0x680a90);
  u8 *eng = G(u8 *, 0x70039c);
  float f = *(float *)(eng + 0x48) * scale;
  s32 bt = _mm_cvttss_si32(_mm_set_ss(f));
  s32 d = (s32)(a - c);
  s32 v = (s32)a;
  if (d > 0) {
    if (d > bt) v = (s32)((u32)bt + c);
  } else {
    s32 nd = (s32)(0u - (u32)d);
    if (nd > bt) v = (s32)(c - (u32)bt);
  }
  return v;
}

// 0x5d98b0, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d98b0(u8 *self) {
  u32 a = *(u32 *)(self + 0x88);
  u32 c = *(u32 *)(self + 0x8c);
  if (a != c) {
    s32 v = moveStep(a, c);
    ext_5d9f00(self, *(u32 *)(self + 0x68), c, (u32)v);
    ext_5d9f00(self, *(u32 *)(self + 0x60), *(u32 *)(self + 0x8c), (u32)v);
    ext_5d9f00(self, *(u32 *)(self + 0x5c), *(u32 *)(self + 0x8c), (u32)v);
    *(u32 *)(self + 0x8c) = (u32)v;
  }
  a = *(u32 *)(self + 0x90);
  c = *(u32 *)(self + 0x94);
  if (a != c) {
    s32 v = moveStep(a, c);
    ext_5d9f00(self, *(u32 *)(self + 0x74), c, (u32)v);
    ext_5d9f00(self, *(u32 *)(self + 0x78), *(u32 *)(self + 0x94), (u32)v);
    ext_5d9f00(self, *(u32 *)(self + 0x7c), *(u32 *)(self + 0x94), (u32)v);
    *(u32 *)(self + 0x94) = (u32)v;
  }
}
PCREG(5d98b0, unnamed5d98b0);
