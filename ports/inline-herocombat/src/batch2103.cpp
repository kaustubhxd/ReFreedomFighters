// batch2103.cpp - wire-hero-combat thread, batch 2103: ZProjectile::CheckHit 0x4b9340, a plain lift for the wasm build
// (2026-10-13). inline-unclaimed-81 batch1018 is strict too, but it is an asm wrapper that models 0x443ef0 as a
// one-argument thiscall and leans on leftover registers; the exe calls vaddscalar4 (ecx = out, edx = the start, stack:
// row 2, -t), which pops both stack words, so the epilogue is an ordinary one.
#include "ff.h"

typedef u8 *(THISCALL *vcallU0)(void *self);
typedef void(THISCALL *vcallP)(void *self, float *p);
typedef u8 *(THISCALL *vcallH)(void *self, u32 handle);
typedef u8(THISCALL *vcallRay)(void *self, u8 *coli, u32 a, u32 mask, u32 b, u32 c, u32 d);

extern "C" void FASTCALL ext_443ef0(float *dst, const float *a, const float *v, float s);  // dst = a + v * s
extern "C" THISCALL void ext_4dc630(void *geom, u32 set, u32 clear);                    // ZBaseGeom::SetControl
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);         // PSVECSubtract d = a - b

// 0x4b9340, thiscall, one float (t), ret 4, result in ST0. t not above 0 (ordered): 0. Otherwise the start s is the geom
// matrix's position (+0x24) and the end e = s - row 2 * t; both go through the geom's parent (slot 0x20) slot 0x84. The
// object +0x65 (a pass-through handle from the last frame) gets its control bits 6 cleared for the cast and restored.
// The COLI [+0x8d] gets from = s, dir = e - s, fraction +0x34 = 1, byte +0x6c = 1; the collision world
// ([[0x70039c]+0x9b]+0xadc) slot 0x2e0(COLI, 0, 6, -1, 1, 1) casts it; +0x65 = 0. Hit: fraction * t (x87 product), else
// t. Name ZProjectile::CheckHit (name map high).
static double THISCALL checkHit(u8 *self, float t) {
  if (0.0f >= t)
    return 0.0;
  u8 *g = *(u8 **)(self + 0x44);
  u8 *m = *(u8 **)(g + 8);
  float s[3] = {*(float *)(m + 0x24), *(float *)(m + 0x28), *(float *)(m + 0x2c)};
  float e[3];
  ext_443ef0(e, s, (const float *)(m + 0x18), -t);
  g = *(u8 **)(self + 0x44);
  u8 *par = ((vcallU0)(*(void ***)g)[0x20 / 4])(g);
  ((vcallP)(*(void ***)par)[0x84 / 4])(par, s);
  g = *(u8 **)(self + 0x44);
  par = ((vcallU0)(*(void ***)g)[0x20 / 4])(g);
  ((vcallP)(*(void ***)par)[0x84 / 4])(par, e);
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *r = ((vcallH)(*(void ***)rm)[0x58 / 4])(rm, *(u32 *)(self + 0x65));
  u32 saved = 0;
  if (r) {
    void *rg = *(void **)(r + 8);
    saved = *(u32 *)((u8 *)rg + 0x3c) & 6;
    ext_4dc630(rg, 0, 6);
  }
  u8 *P = *(u8 **)(self + 0x8d);
  *(float *)(P + 0) = s[0];
  *(float *)(P + 4) = s[1];
  *(float *)(P + 8) = s[2];
  ext_43e920((float *)(*(u8 **)(self + 0x8d) + 0xc), e, s);
  *(u32 *)(*(u8 **)(self + 0x8d) + 0x34) = 0x3f800000u;
  *(*(u8 **)(self + 0x8d) + 0x6c) = 1;
  u8 *w = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  u8 hit = ((vcallRay)(*(void ***)w)[0x2e0 / 4])(w, *(u8 **)(self + 0x8d), 0, 6, 0xffffffffu, 1, 1);
  if (r)
    ext_4dc630(*(void **)(r + 8), saved, 0);
  *(u32 *)(self + 0x65) = 0;
  if (hit)
    return (double)*(float *)(*(u8 **)(self + 0x8d) + 0x34) * (double)t;
  return (double)t;
}
PCREG(4b9340, checkHit);
