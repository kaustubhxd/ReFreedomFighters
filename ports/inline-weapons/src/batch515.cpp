// batch515.cpp - weapons thread, batch 515: ZTARGET blend completion (0x465930, the body of ZTARGET::Update) and the
// release-with-callback (0x467410, no GC name; used by every hand change: get, put, swap, ForceR/LHandItem).
#include "ff.h"

struct PMF { u32 fn, adj, vb, vi; };
typedef void(THISCALL *vCB)(void *self);
extern "C" void THISCALL ext_4658d0(u8 *t, u8 *obj);   // ZTARGET::CallBackAndRemove
extern "C" void THISCALL ext_465930(u8 *t, u8 *obj);   // blend completion (below)

static inline s32 ticks() { return *(s32 *)(G(u8 *, 0x70039c) + 0x40); }
static inline float elapsed(float start) {
  float ab = (float)__builtin_fabs((double)start);
  s32 e = ticks() - _mm_cvttss_si32(_mm_set_ss(ab * 1024.0f));
  return (float)e * 0.0009765625f;
}

// 0x465930: when blending in has reached weight 1, or blending out has reached weight 0 (which also disables the
// target), the callback is cleared and called on obj + this-adjust. Weights as in ZTARGET::SetTime (batch 504).
static void THISCALL targetBlendDone(u8 *t, u8 *obj) {
  float start = *(float *)(t + 0x35);
  float el = elapsed(start);
  float w;
  if (start >= 0.0f) {
    float dur = *(float *)(t + 0x31);
    if (!(dur > el)) {
      w = 1.0f;
      goto done;
    }
    w = el / dur;
  } else {
    float dur = *(float *)(t + 0x31);
    if (el > dur || dur == 0.0f) {
      w = 0.0f;
      goto done;
    }
    w = 1.0f - el / dur;
  }
  if (!(w == 0.0f) && !(w == 1.0f))
    return;
done:
  PMF cb = {0, 0, 0, 0xffffffffu};
  if (start >= 0.0f) {
    if (w == 1.0f)
      cb = *(PMF *)(t + 0x3d);
  } else if (w == 0.0f) {
    t[0] = 0;
    cb = *(PMF *)(t + 0x3d);
  }
  if (!cb.fn)
    return;
  *(PMF *)(t + 0x3d) = PMF{0, 0, 0, 0xffffffffu};
  ((vCB)cb.fn)(obj + cb.adj);
}
PCREG(465930, targetBlendDone);

// 0x467410 release(obj, time, cb), ret 0x18: run and clear the pending callback, store the new one, then blend the
// target out over `time` keeping the current weight. time 0: weight is dropped at once and the completion check
// (0x465930) runs now, so the new callback fires immediately. Already blending out with time != 0: nothing more.
static void THISCALL targetRelease(u8 *t, u8 *obj, float time, PMF cb) {
  ext_4658d0(t, obj);
  *(PMF *)(t + 0x3d) = cb;
  float start = *(float *)(t + 0x35);
  if (time == 0.0f) {
    float el = elapsed(start);
    float w;
    if (start >= 0.0f) {
      float dur = *(float *)(t + 0x31);
      w = dur > el ? el / dur : 1.0f;
    } else {
      float dur = *(float *)(t + 0x31);
      if (el > dur || dur == 0.0f)
        w = 0.0f;
      else
        w = 1.0f - el / dur;
    }
    *(u32 *)(t + 0x31) = 0;
    u32 now = (u32)ticks();
    *(u32 *)(t + 0x39) = 0;
    u32 v;
    if (w == 1.0f)
      v = 0u - now;
    else
      v = (0u - now) - (u32)_mm_cvttss_si32(_mm_set_ss((1.0f - w) * 0.0f * -1024.0f));
    *(float *)(t + 0x35) = (float)(s32)v * 0.0009765625f;
    ext_465930(t, obj);
    return;
  }
  if (start < 0.0f || __builtin_isnan(start))
    return;
  float el = elapsed(start);
  float dur = *(float *)(t + 0x31);
  float w = dur > el ? el / dur : 1.0f;
  *(float *)(t + 0x31) = time;
  u32 now = (u32)ticks();
  *(u32 *)(t + 0x39) = 0;
  u32 v;
  if (w == 1.0f)
    v = 0u - now;
  else
    v = (0u - now) - (u32)_mm_cvttss_si32(_mm_set_ss((1.0f - w) * time * -1024.0f));
  *(float *)(t + 0x35) = (float)(s32)v * 0.0009765625f;
}
PCREG(467410, targetRelease);
