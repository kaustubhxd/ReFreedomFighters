// batch230.cpp - ZIKLNKOBJ::SetFacingTarget (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

static inline s32 trunc230(float f) { return _mm_cvttss_si32(_mm_set_ss(f)); }

// 0x4678f0 ZIKLNKOBJ::SetFacingTarget(unsigned ref, float t, void (ZIKLNKOBJ::*cb)(ZIKLNKOBJ*)) (vtable neighbour of
// RemoveFacingTarget; the name map's low "IKTargetIdToCallBack" does not fit). thiscall, ret 0x18.
// Facing target T at +0x16d: +0x19e duration, +0x1a2 start (s; negative = blending out), +0x1a6 target ref,
// +0x1aa callback; +0x16e and +0x192 are reset to 0x7fffffff.
// Nothing when facing is disabled (+0x158) or when the same target is already set and blending in (start >= 0).
// Otherwise the target and callback are stored; if already active (flag 0x200000) and blending in, done (flag kept).
// Else the current blend f is measured as in RemoveFacingTarget, the duration becomes t and the start is moved back
// so the blend continues from f: start = (ticks - trunc(f * t * 1024)) / 1024 (just ticks / 1024 when f == 1);
// flag 0x200000 is set.
static void THISCALL ikSetFacingTarget(u8 *self, u32 ref, float t, u32 c0, u32 c1, u32 c2, u32 c3) {
  if (self[0x158])
    return;
  float v = F32(self, 0x1a2);
  if (v >= 0.0f && U32(self, 0x1a6) == ref)
    return;
  U32(self, 0x16e) = 0x7fffffff;
  U32(self, 0x192) = 0x7fffffff;
  U32(self, 0x1a6) = ref;
  U32(self, 0x1aa) = c0;
  U32(self, 0x1ae) = c1;
  U32(self, 0x1b2) = c2;
  U32(self, 0x1b6) = c3;
  if ((U32(self, 0x136) & 0x200000) && F32(self, 0x1a2) >= 0.0f) {
    U32(self, 0x136) |= 0x200000;
    return;
  }
  v = F32(self, 0x1a2);
  s32 now = (s32)U32(G(u32, 0x70039c), 0x40);
  float a = (float)__builtin_fabs((double)v) * 1024.0f;
  float el = (float)(now - trunc230(a)) * 0.0009765625f;
  float d = F32(self, 0x19e);
  float f;
  if (v >= 0.0f) {
    f = (d > el) ? el / d : 1.0f;
  } else {
    if (el > d)
      f = 0.0f;
    else if (d == 0.0f)
      f = 0.0f;
    else
      f = 1.0f - el / d;
  }
  F32(self, 0x19e) = t;
  s32 st;
  if (f == 1.0f)
    st = (s32)U32(G(u32, 0x70039c), 0x40);
  else
    st = (s32)U32(G(u32, 0x70039c), 0x40) - trunc230((f * t) * 1024.0f);
  F32(self, 0x1a2) = (float)st * 0.0009765625f;
  U32(self, 0x136) |= 0x200000;
}
PCREG(4678f0, ikSetFacingTarget);
