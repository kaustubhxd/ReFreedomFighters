// batch821.cpp - core gameplay batch 821 (docs/20-unclaimed-65.md, batch 821): 0x4fbd50, a thiscall with no arguments that returns a bool
// in al. It calls slot 0x58 of the render sub-object ([0x70039c]+0x9b) with the dword at this+0x59; if that gives an object A, it calls
// the same slot again with the dword at this+0x51, giving B. With A and B nonzero it zeroes a local Vec3 v, calls slot 0x84 of A with &v
// (one argument), adds the float at 0x67cd40 to v[1], calls slot 0x8c of B with &v, and returns (slot 0x180 of B with &v and -10.0f) != 0.
// The cookie check 0x633654 of the exe is not reproduced (the harness stubs it to a return for the orig run, as in the other batches).
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u8(THISCALL *F180)(u8 *self, u32 p, float f);

static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

static u8 THISCALL fn4fbd50(u8 *self) {
  u8 *a = (u8 *)vc1(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, *(const u32 *)(self + 0x59));
  if (a == 0) return 0;
  u8 *b = (u8 *)vc1(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, *(const u32 *)(self + 0x51));
  if (b == 0) return 0;

  float v[3] = {0.0f, 0.0f, 0.0f};
  vc1(a, 0x84, (u32)v);
  v[1] = v[1] + G(float, 0x67cd40);
  vc1(b, 0x8c, (u32)v);
  return (((F180)(*(const u32 *)(*(const u32 *)b + 0x180)))(b, (u32)v, -10.0f) & 0xff) != 0;
}

// PCREG(4fbd50, fn4fbd50);   // NOT registered: BLOCKED (see docs/20-unclaimed-65.md batch 821)
