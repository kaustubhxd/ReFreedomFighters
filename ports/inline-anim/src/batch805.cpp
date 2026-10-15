// batch805.cpp - animation layer thread, batch 805: ZTARGET (the IK/aim target embedded in ZIKHAND at +4 and in
// ZLNKWHANDS' aim target). PC layout (packed):
//   +0 enabled (byte), +1 matrix 3x3, +0x25 position, +0x31 blend duration (s), +0x35 blend start time (s; the sign
//   is the direction: negative = blending out), +0x39 geom / id, +0x3d callback (MSVC member-function pointer,
//   16 bytes: function, this adjustment, two more words; "empty" = {0, 0, 0, -1}).
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

struct PMF { u32 w[4]; };

extern "C" void FASTCALL ext_4de7a0(float *m);                    // mreset
extern "C" void FASTCALL ext_4de420(float *d, const float *s);     // mcpy

// ZTARGET::Clear() [high, GameCube reference].
static void THISCALL ZTARGET_Clear(u8 *t) {
  ext_4de7a0((float *)(t + 1));
  F32(t, 0x25) = 0;
  F32(t, 0x29) = 0;
  F32(t, 0x2d) = 0;
  PMF e = {{0, 0, 0, 0xffffffff}};
  F32(t, 0x39) = 0;
  F32(t, 0x31) = 0;
  F32(t, 0x35) = 0;
  *(PMF *)(t + 0x3d) = e;
  F8(t, 0) = 0;
}
PCREG(466220, ZTARGET_Clear);

// ZTARGET::Enable(bool) [high, GameCube reference]. Returns the previous byte in AL (the exe loads it; GC's is void).
static u8 THISCALL ZTARGET_Enable(u8 *t, u8 on) {
  u8 old = F8(t, 0);
  F8(t, 0) = on;
  return old;
}
PCREG(466600, ZTARGET_Enable);

// ZTARGET::SetMatPosGeom(const float* mat, const float* pos, unsigned geom) [low map confidence, GameCube reference; the
// body fits]. A null mat / pos stores 0x7fffffff in the first word as "not set".
static void THISCALL ZTARGET_SetMatPosGeom(u8 *t, const float *mat, const float *pos, u32 geom) {
  if (!mat) F32(t, 1) = 0x7fffffff;
  else ext_4de420((float *)(t + 1), mat);
  if (!pos) {
    F32(t, 0x25) = 0x7fffffff;
    F32(t, 0x39) = geom;
    return;
  }
  F32(t, 0x25) = F32(pos, 0);
  F32(t, 0x29) = F32(pos, 4);
  F32(t, 0x2d) = F32(pos, 8);
  F32(t, 0x39) = geom;
}
PCREG(467aa0, ZTARGET_SetMatPosGeom);

// ZTARGET::SetCallBack(member-function pointer by value) [low, GameCube reference; body fits].
static void THISCALL ZTARGET_SetCallBack(u8 *t, PMF cb) { *(PMF *)(t + 0x3d) = cb; }
PCREG(4678e0, ZTARGET_SetCallBack);

// ZTARGET::CallBackAndRemove(ZIKLNKOBJ* obj) [medium, GameCube reference]: while a callback is set, clear it and call it
// on obj + adjustment (no stack arguments in the PC build). A callback may set a new one, which then runs too.
static void THISCALL ZTARGET_CallBackAndRemove(u8 *t, u8 *obj) {
  for (;;) {
    PMF cb = *(PMF *)(t + 0x3d);
    if (cb.w[0] == 0) return;
    PMF e = {{0, 0, 0, 0xffffffff}};
    *(PMF *)(t + 0x3d) = e;
    ((void(THISCALL *)(void *))cb.w[0])(obj + cb.w[1]);
  }
}
PCREG(4658d0, ZTARGET_CallBackAndRemove);

// ZTARGET::SetTime(float T, bool out) [low, GameCube reference; body fits]. Re-times the blend so the current blend
// fraction is kept: frac = elapsed / old T (blending in, start >= 0) or 1 - elapsed / old T (blending out). Then the
// new duration is stored and the start time is moved back so that frac is reached at the new speed, in the
// requested direction; blending out also clears +0x39. Times are clock ticks ([0x70039c]+0x40) / 1024.
static void THISCALL ZTARGET_SetTime(u8 *t, float T, u8 out) {
  const float k1024 = bitsf(0x44800000), inv = bitsf(0x3a800000), one = 1.0f;
  float s = FF(t, 0x35);
  s32 clk = *(s32 *)((u8 *)G(void *, 0x70039c) + 0x40);
  float oldT = FF(t, 0x31);
  s32 k = (s32)((float)__builtin_fabs((double)s) * k1024);
  float cur = (float)(s32)((u32)clk - (u32)k) * inv;
  float frac;
  if (s >= 0.0f) {
    frac = oldT > cur ? cur / oldT : one;
  } else {
    frac = 0.0f;
    if (!(cur > oldT) && !(oldT == 0.0f)) frac = one - cur / oldT;
  }
  FF(t, 0x31) = T;
  clk = *(s32 *)((u8 *)G(void *, 0x70039c) + 0x40);
  if (frac == one) {
    if (out) {
      F32(t, 0x39) = 0;
      FF(t, 0x35) = (float)(s32)(0u - (u32)clk) * inv;
    } else {
      FF(t, 0x35) = (float)clk * inv;
    }
    return;
  }
  if (out) {
    F32(t, 0x39) = 0;
    s32 d = (s32)((one - frac) * T * bitsf(0xc4800000));
    FF(t, 0x35) = (float)(s32)(0u - (u32)clk - (u32)d) * inv;
  } else {
    s32 d = (s32)(frac * T * k1024);
    FF(t, 0x35) = (float)(s32)((u32)clk - (u32)d) * inv;
  }
}
PCREG(467b00, ZTARGET_SetTime);
