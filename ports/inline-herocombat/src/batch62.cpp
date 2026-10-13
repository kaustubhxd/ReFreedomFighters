// batch62.cpp - ladder tree, inline session batch 62: BasicShape::GetSplineVelocity (0x460b60) and
// ZSHAPE::GetSegment (0x44ad50), used by ZFFHeroMovementGuide::WantControl.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8 *(THISCALL *vcallPU)(void *self, u32 a);

extern "C" void THISCALL ext_460570(const u8 *seg, float *out, float t);   // ParametricCurve::GetSplineVelocity

// 0x460b60 BasicShape::GetSplineVelocity(float[3]& vel, float t), thiscall, ret 8. The velocity half of
// GetSplinePosVelocity: segment trunc(count * t) (at most count - 1) sampled at the remainder.
static void THISCALL basicGetSplineVelocity(u8 *self, float *vel, float t) {
  s32 n = *(s32 *)(self + 0x10);
  float x = (float)n * t;
  s32 i = _mm_cvttss_si32(_mm_set_ss(x));
  if (i >= n)
    i = n - 1;
  float f = x - (float)i;
  ext_460570(*(u8 **)(self + 0xc) + i * 0x38, vel, f);
}
PCREG(460b60, basicGetSplineVelocity);

// 0x44ad50 ZSHAPE::GetSegment(float t, float *local), thiscall, ret 8. The shape's points (36-byte records) and their
// count come from the shape list ([[0x70039c]+0x1aa3]+0x18, slots 0xfc and 0x100) by the key at [+8]+0x6c. t is
// clamped to [0, 1] (a NaN passes through), the segment is i = trunc(t / step) with step = 1 / (count - 1), at most
// count - 2, and *local (when given) gets the position inside it, (t - i * step) / step, or t itself at t = 1.
// Returns the segment's first point record.
static u8 *THISCALL getSegment(u8 *self, float t, float *local) {
  u8 *list = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  u8 *pts = ((vcallPU)VT(list, 0xfc))(list, *(u32 *)(*(u8 **)(self + 8) + 0x6c));
  float u = 0.0f;
  if (!(0.0f >= t))
    u = 1.0f < t ? 1.0f : t;
  list = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  s32 n = *(s32 *)((vcallPU)VT(list, 0x100))(list, *(u32 *)(*(u8 **)(self + 8) + 0x6c));
  float step = 1.0f / (float)(n - 1);
  s32 last = n - 2;
  s32 i = _mm_cvttss_si32(_mm_set_ss(u / step));
  if (i <= last)
    last = i;
  if (1.0f > u)
    u = (u - (float)last * step) / step;
  if (local)
    *local = u;
  return pts + last * 36;
}
PCREG(44ad50, getSegment);
