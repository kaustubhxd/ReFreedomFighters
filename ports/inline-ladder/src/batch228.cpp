// batch228.cpp - ZIKLNKOBJ::RemoveFacingTarget (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_4658d0(void *target, void *owner);   // ZTARGET::CallBackAndRemove(ZIKLNKOBJ*)

static inline s32 trunc32(float f) { return _mm_cvttss_si32(_mm_set_ss(f)); }

// 0x4675e0 ZIKLNKOBJ::RemoveFacingTarget(float, void (ZIKLNKOBJ::*cb)(ZIKLNKOBJ*)) (the name map's low "SetFacingTarget"
// is wrong: the GC RemoveFacingTarget 8017d3f4 has the same shape: CallBackAndRemove, SetCallBack, SetTime with a
// constant 0.0 instead of the float argument, which the PC build also never reads). thiscall, ret 0x14 (float + 16-byte
// member pointer). Nothing when facing is disabled (byte +0x158). The facing ZTARGET T is at +0x16d (+0x31 blend
// duration, +0x35 start time in seconds (negative = blending out), +0x39, +0x3d the callback).
// 1. CallBackAndRemove(T, this); flag 0x200000 of +0x136 off; callback = cb.
// 2. ZTARGET::SetTime(0, ...) inlined: the current blend f from the elapsed time el = (ticks - trunc(|start| * 1024)) /
//    1024: blending in (start >= 0): f = el / dur while dur > el, else 1; blending out: f = 0 when el > dur or dur == 0,
//    else 1 - el / dur. Then dur = 0, +0x39 = 0, and start = -(ticks + trunc(((1 - f) * 0) * -1024)) / 1024 (the
//    term is 0, or the integer indefinite 0x80000000 when it is NaN; skipped when f == 1).
// 3. Own slot 0x408 (UpdateTargets' first part).
static void THISCALL ikRemoveFacingTarget(u8 *self, float unused, u32 c0, u32 c1, u32 c2, u32 c3) {
  (void)unused;
  if (self[0x158])
    return;
  u8 *t = self + 0x16d;
  ext_4658d0(t, self);
  U32(self, 0x136) &= 0xffdfffff;
  U32(self, 0x1aa) = c0;
  U32(self, 0x1ae) = c1;
  U32(self, 0x1b2) = c2;
  U32(self, 0x1b6) = c3;
  float start = F32(t, 0x35);
  s32 now = (s32)U32(G(u32, 0x70039c), 0x40);
  float a = (float)__builtin_fabs((double)start) * 1024.0f;
  float el = (float)(now - trunc32(a)) * 0.0009765625f;
  float f;
  if (start >= 0.0f) {
    float d = F32(t, 0x31);
    f = (d > el) ? el / d : 1.0f;
  } else {
    float d = F32(t, 0x31);
    if (el > d)
      f = 0.0f;
    else if (d == 0.0f)
      f = 0.0f;
    else
      f = 1.0f - el / d;
  }
  U32(t, 0x31) = 0;
  s32 now2 = (s32)U32(G(u32, 0x70039c), 0x40);
  U32(t, 0x39) = 0;
  s32 v;
  if (f == 1.0f) {
    v = -now2;
  } else {
    float k = ((1.0f - f) * 0.0f) * -1024.0f;
    v = -now2 - trunc32(k);
  }
  F32(t, 0x35) = (float)v * 0.0009765625f;
  vcall<void>(self, 0x408);
}
PCREG(4675e0, ikRemoveFacingTarget);
