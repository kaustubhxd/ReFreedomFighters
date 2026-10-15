// batch205.cpp - ladder tree (inline-ladder thread, 2026-10-11): ZFFHeroMovementGuide::Move (mount, climb, dismount).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);           // PSVECSubtract: dst = src - a
extern "C" void FASTCALL ext_4de420(void *dst, const void *src);                             // mcpy (9 dwords)
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *b, float s);     // vaddscalar(out, a, b, s)
extern "C" void FASTCALL ext_451890(float *v, const float *a, float s);                      // vaddscalar(v, a, s)
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);             // dst = a + b
extern "C" void FASTCALL ext_4de520(float *out, const float *m0, const float *m1, float t); // mpul (matrix blend)
extern "C" long double THISCALL ext_488460(void *self);                                     // ZMovementBase::DeltaTime (ST0)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                     // vscalar in place

#define F32(p, off) (*(float *)((u8 *)(p) + (off)))
#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define PF(off) ((float *)(self + (off)))

static inline void copy3(float *dst, const void *src) {   // dword copies, as the exe does
  ((u32 *)dst)[0] = ((const u32 *)src)[0];
  ((u32 *)dst)[1] = ((const u32 *)src)[1];
  ((u32 *)dst)[2] = ((const u32 *)src)[2];
}

// Frames (25 per second) since the stamp at +0x5dd: the tick count (1/1024 s, engine +0x40) difference times 0x6400,
// shifted right by 10 as a 64-bit value, low 32 bits as a signed int, times 1/1024 (0x6785e4).
static inline float framesSince(u8 *self) {
  s32 d = (s32)(U32(G(u32, 0x70039c), 0x40) - U32(self, 0x5dd));
  long long prod = (long long)d * 0x6400;
  s32 lo = (s32)(u32)(u64)(prod >> 10);
  return (float)lo * 0.0009765625f;
}

static inline void stamp(u8 *self) {   // +0x5dd = engine tick count (the exe skips it when both are the same address)
  u32 *src = (u32 *)(G(u32, 0x70039c) + 0x40);
  u32 *dst = (u32 *)(self + 0x5dd);
  if (dst != src)
    *dst = *src;
}

// 0x5e5f90, ZFFHeroMovementGuide::Move(const float *mat, const float *pos, float *matOut, float *posOut, float *delta)
// [GameCube reference, medium; vtable slot 5], thiscall, ret 0x14. State +0x579: 0/1 = mounting (from the bottom / from the top,
// set by WantControl), 2/3 = mount step (bottom / top), 4 = climbing off at the top, 5 = climbing off at the bottom,
// 6 = on the ladder. Timing from the stamp +0x5dd. Positions: +0x554 the bottom grab point, +0x560 the top point,
// +0x56c a direction (with -62 for the step-off offset), +0x57d/+0x5ad matrices, +0x5a1 the start and +0x5d1 the target
// of the walk to the ladder. +0x5e1 is the animation phase (frames / 54), +0x578 a byte flag, +0x550 the ladder (0 on exit).
// Input: the dword at hero(+0x36d)+0x417; bits 0-1 = up/down held, bit 2 = the "down" direction.
static void THISCALL guideMove(u8 *self, const float *mat, const float *pos, float *matOut, float *posOut, float *delta) {
  delta[2] = 0.0f;
  delta[1] = 0.0f;
  delta[0] = 0.0f;
  u32 ctl = U32(U32(self, 0x36d), 0x417);
  u32 st = U32(self, 0x579);
  if (st == 0 || st == 1) {
    // walk/turn to the grab point over 0.24 s (0x6b7f50)
    float f = (float)(s32)(U32(G(u32, 0x70039c), 0x40) - U32(self, 0x5dd)) * 0.0009765625f;
    f = f / bitsf(0x3e75c28f);
    if (f > 1.0f) {
      copy3(posOut, self + 0x5d1);
      ext_4de420(matOut, self + 0x5ad);
      ext_43e920(delta, posOut, pos);
      U32(self, 0x579) = (U32(self, 0x579) != 0) + 2;
      stamp(self);
      return;
    }
    float a = F32(self, 0x5a1);
    posOut[0] = (F32(self, 0x5d1) - a) * f + a;
    a = F32(self, 0x5a5);
    posOut[1] = (F32(self, 0x5d5) - a) * f + a;
    a = F32(self, 0x5a9);
    posOut[2] = (F32(self, 0x5d9) - a) * f + a;
    ext_4de520(matOut, PF(0x57d), PF(0x5ad), f);
    ext_43e920(delta, posOut, pos);
    return;
  }
  if (st == 2) {   // mount at the bottom: 16 frames
    float fr = framesSince(self);
    if (16.0f > fr) {
      F32(self, 0x5e1) = (fr + 0.0f) / 54.0f;
      copy3(posOut, self + 0x554);
      ext_43e920(delta, posOut, pos);
      ext_4de420(matOut, mat);
      return;
    }
    copy3(posOut, pos);
    ext_43e920(delta, posOut, pos);
    ext_4de420(matOut, mat);
    U32(self, 0x579) = 6;
  } else if (st == 3) {   // mount at the top: 18 frames, lerp from the step-off point to the top point
    float fr = framesSince(self);
    if (18.0f > fr) {
      float rem = 18.0f - fr;
      F32(self, 0x5e1) = (rem + 36.0f) / 54.0f;
      float t[3];
      ext_443ef0(t, PF(0x560), PF(0x56c), -62.0f);
      float k = 1.0f - rem / 18.0f;
      float x = (F32(self, 0x560) - t[0]) * k;
      float y = ((F32(self, 0x564) - 100.0f) - t[1]) * k;
      float z = (F32(self, 0x568) - t[2]) * k;
      posOut[0] = x + t[0];
      posOut[1] = y + t[1];
      posOut[2] = z + t[2];
      ext_43e920(delta, posOut, pos);
      ext_4de420(matOut, mat);
      return;
    }
    copy3(posOut, pos);
    ext_4de420(matOut, mat);
    U32(self, 0x579) = 6;
    return;
  }
  // on the ladder: start a climb-off when an end is reached
  if (U32(self, 0x579) == 6) {
    if (pos[1] - F32(self, 0x558) <= 0.0f && (ctl & 4)) {   // at the bottom, pressing down
      U32(self, 0x579) = 4;
      stamp(self);
    }
    if (U32(self, 0x579) == 6 && 100.0f > F32(self, 0x564) - pos[1] && (ctl & 3) && !(ctl & 4)) {   // near the top, going up
      U32(self, 0x579) = 5;
      stamp(self);
    }
  }
  st = U32(self, 0x579);
  if (st == 4) {   // climb off at the bottom: 16 frames
    float fr = framesSince(self);
    if (16.0f > fr) {
      F32(self, 0x5e1) = ((16.0f - fr) + 0.0f) / 54.0f;
      copy3(posOut, self + 0x554);
      ext_43e920(delta, posOut, pos);
      ext_4de420(matOut, mat);
      return;
    }
    copy3(posOut, self + 0x554);
    ext_43e920(delta, posOut, pos);
    ext_4de420(matOut, mat);
    U32(self, 0x550) = 0;
    U32(self, 0x5e1) = 0;
    return;
  }
  if (st == 5) {   // climb off at the top: 18 frames
    float fr = framesSince(self);
    if (18.0f > fr) {
      F32(self, 0x5e1) = (fr + 36.0f) / 54.0f;
      float t[3];
      ext_443ef0(t, PF(0x560), PF(0x56c), -62.0f);
      float k = 1.0f - fr / 18.0f;
      float x = (F32(self, 0x560) - t[0]) * k;
      float y = ((F32(self, 0x564) - 100.0f) - t[1]) * k;
      float z = (F32(self, 0x568) - t[2]) * k;
      posOut[0] = x + t[0];
      posOut[1] = y + t[1];
      posOut[2] = z + t[2];
      ext_43e920(delta, posOut, pos);
      ext_4de420(matOut, mat);
      return;
    }
    ext_443ef0(posOut, PF(0x560), PF(0x56c), -62.0f);
    ext_43e920(delta, posOut, pos);
    ext_4de420(matOut, mat);
    U32(self, 0x550) = 0;
    return;
  }
  // climbing: 5 units per frame up (-5 with bit 2), scaled by the frame time * 25
  float speed = 5.0f;
  self[0x578] = 1;
  delta[2] = 0.0f;
  delta[1] = 0.0f;
  delta[0] = 0.0f;
  if (ctl & 3) {
    if (ctl & 4)
      speed = -5.0f;
    float up[3] = {0.0f, 1.0f, 0.0f};
    ext_451890(delta, up, speed);
  }
  float k = (float)(ext_488460(self) * 25.0L);
  ext_4e0d00(delta, k);
  ext_43e8e0(posOut, pos, delta);
  ext_4de420(matOut, mat);
}
PCREG(5e5f90, guideMove);
