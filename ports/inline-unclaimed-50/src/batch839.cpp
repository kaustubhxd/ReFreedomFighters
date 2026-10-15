// batch839.cpp - area 50: 0x47f490 (483 bytes). A per-frame position/state update of an actor-like object (fields at
// +0x660..+0x688 hold a position and direction vectors, +0x695 a path/track object, +0x722 the time). Its helpers
// (0x478ea0, 0x478c10) are other functions and are called through extern declarations (hooked in the checker).
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_478ea0(void *obj, float *out, float t);       // sample the track at t (not ported here)
extern "C" void THISCALL ext_478c10(void *obj, float *out, float t);       // sample the track at t, second helper
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);          // PSVECSubtract d = a - b
extern "C" float FASTCALL ext_44c840(float *v);                                           // vnorm (in place, returns length)
extern "C" void FASTCALL ext_443ef0(float *dst, const float *src, const float *a, float s);   // vaddscalar

// Returns the distance (x87 float). out and p are the two output/input vectors, dt the step.
static float THISCALL Step47f490(u8 *self, float *out, const float *p, float dt) {
  float ret;
  void *obj = FP(self, 0x695);
  if (obj) {
    float t = dt + FF(self, 0x722);
    FF(self, 0x722) = t;
    ext_478ea0(obj, (float *)(self + 0x660), t);
    ext_478ea0(obj, out, FF(self, 0x722) - FF(self, 0x678));
    // the second helper runs unless the object's +4 value is exactly zero (NaN counts as not zero: ucomiss sets PF)
    float k = FF(obj, 4);
    if (k != 0.0f) ext_478c10(obj, (float *)(self + 0x67c), FF(self, 0x722) - FF(self, 0x678));
    if (FF(self, 0x722) > FF(obj, 4)) {
      if (F8(self, 0x6c5) == 0) vcall<void>(self, 0x628, 1u, 0u, 1u);
      else vcall<void>(self, 0x628, 2u, 3u, 0u);
    }
    ret = FF(self, 0x678);
  } else {
    float *a = (float *)(self + 0x660);
    if (p[0] == a[0] && p[2] == a[2]) {
      ret = 0.0f;
    } else {
      ext_43e920((float *)(self + 0x67c), a, p);
      FF(self, 0x680) = 0.0f;
      ret = ext_44c840((float *)(self + 0x67c));
    }
    if (ret > dt) {
      ext_443ef0(out, p, (float *)(self + 0x67c), dt);
      ret = ret - dt;
    } else {
      out[0] = FF(self, 0x660);
      out[1] = FF(self, 0x664);
      out[2] = FF(self, 0x668);
      ret = 0.0f;
    }
  }
  if (!F8(self, 0x72f) && FP(self, 0x695)) {
    void *o = FP(self, 0x695);
    if (FF(self, 0x722) + G(float, 0x680a84) > FF(o, 4)) {
      F8(self, 0x72f) = 1;
      vcall<void>(self, 0x63c, 1u);
    }
  }
  return ret;
}
PCREG(47f490, Step47f490);
