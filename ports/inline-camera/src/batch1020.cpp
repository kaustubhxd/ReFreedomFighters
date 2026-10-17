// batch1020.cpp - ZCamHelper gamepad focus: UpdateFocusAngleOni, SetPointerOnScreenOni. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" FASTCALL void ext_4e0d80(float *v, float len);                      // vsetlen
extern "C" FASTCALL void ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b
extern "C" FASTCALL void ext_4de7a0(float *m);                                  // mreset
extern "C" THISCALL u32 ext_5ceed0(void *self, float *out, const float *o, const float *d, u32 mask, u32 a, u32 b);  // Find3DPointerPos
extern "C" THISCALL void ext_5cefc0(void *self, float *p, const float *d, float h, u32 n);  // Find3DPointerShadowPos
extern "C" THISCALL void ext_5cf300(void *self, float *scr, const float *p);   // Get2DProjection
extern "C" THISCALL void ext_5a7500(void *osd, float x, float y);              // OSD pointer offset

static inline float minss(float a, float b) { return a < b ? a : b; }
#define DT at<float>(G(u8 *, 0x70039c), 0x48)
#define PI G(float, 0x67da18)
#define TWO_PI G(float, 0x68aef8)

static inline float wrap_pi(float y) {
  if (y > PI)
    y = y - TWO_PI;
  else if (G(float, 0x6ad238) > y)
    y = y + TWO_PI;
  return y;
}
static inline float clamp_step(float s) { return (s > G(float, 0x6ad1fc) || G(float, 0x6ad234) > s) ? PI : s; }

// "WARNING: AngleDist: %f" from angle.h line 0x8f, printed when a yaw difference comes out negative.
static inline void warn_angle(float d) {
  void *s = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6b4d68, 0x8fu);
  typedef void (*logfn)(void *, const char *, double);
  (*(logfn *)(*(u8 **)s + 0x2c))(s, (const char *)0x6b4db8, (double)d);
}

// Yaw of a (pointer) minus yaw of b (focus), as angle.h computes it: a + 2pi when b > a, warn when negative.
static inline float angle_dist(float a, float b) {
  if (b > a) a = a + TWO_PI;
  float d = a - b;
  if (G(float, 0x67af28) > d) warn_angle(d);
  return d;
}

// 0x5d2ab0 ZCamHelper::UpdateFocusAngleOni(): the focus (camera) yaw +0xae9 / pitch +0xaed follow the pointer
// yaw/pitch (+0xa54/+0xa5c). With a lag zone (+0xaf9 yaw, +0xafd pitch, 15 and 7 degrees while aiming) the focus
// turns at (difference / zone) * 200 (yaw) or 100 (pitch) deg/s * +0xb01 * pointer speed, and the pointer may
// never be more than the zone ahead; with no zone the focus turns with the pointer speeds. While aiming the yaw
// speeds are capped at +-60 deg/s. The pitch is kept within 3 degrees above the pointer and within +0xa96..+0xa9a.
static THISCALL void ZCamHelper_UpdateFocusAngleOni(void *self) {
  float d = wrap_pi(angle_dist(at<float>(self, 0xa54), at<float>(self, 0xae9)));
  float zy = at<float>(self, 0xaf9);
  if (zy > G(float, 0x6785d0))
    at<float>(self, 0xaf1) = at<float>(self, 0xb01) * G(float, 0x6b4fbc) * at<float>(self, 0xadd) * (d / zy);
  else
    at<u32>(self, 0xaf1) = at<u32>(self, 0xa60);
  if (at<u8>(self, 0xb45)) {
    const float lo = G(float, 0x6b4fe8), hi = G(float, 0x6a09e4);
    float v = at<float>(self, 0xaf1);
    at<float>(self, 0xaf1) = lo > v ? lo : minss(hi, v);
    v = at<float>(self, 0xa60);
    at<float>(self, 0xa60) = lo > v ? lo : minss(hi, v);
  }
  float f = wrap_pi(clamp_step(DT * at<float>(self, 0xaf1)) + at<float>(self, 0xae9));
  at<float>(self, 0xae9) = f;
  float d2 = wrap_pi(angle_dist(at<float>(self, 0xa54), f));
  float z = at<float>(self, 0xaf9);
  __m128d ad = _mm_and_pd(_mm_cvtps_pd(_mm_set_ss(d2)), *(const __m128d *)0x67cd50);
  if (_mm_cvtsd_f64(ad) >= (double)z) {
    at<u32>(self, 0xaf1) = at<u32>(self, 0xa60);
    float y = 0.0f > d2 ? at<float>(self, 0xa54) + clamp_step(z) : at<float>(self, 0xa54) - clamp_step(z);
    at<float>(self, 0xae9) = wrap_pi(y);
  }
  float zp = at<float>(self, 0xafd);
  if (zp > G(float, 0x6785d0))
    at<float>(self, 0xaf5) = (at<float>(self, 0xa5c) - at<float>(self, 0xaed)) / zp *
                             (at<float>(self, 0xb01) * G(float, 0x6b4fb8) * at<float>(self, 0xadd));
  else
    at<u32>(self, 0xaf5) = at<u32>(self, 0xa64);
  float pp = at<float>(self, 0xa5c);
  float q = DT * at<float>(self, 0xaf5) + at<float>(self, 0xaed);
  float dp = pp - q;
  at<float>(self, 0xaed) = q;
  if (G(float, 0x6b4fdc) > dp) {
    at<float>(self, 0xaed) = pp + G(float, 0x6a066c);
    at<u32>(self, 0xaf5) = at<u32>(self, 0xa64);
  } else if (dp > zp) {
    at<float>(self, 0xaed) = pp - zp;
    at<u32>(self, 0xaf5) = at<u32>(self, 0xa64);
  }
  float a = at<float>(self, 0xaed), lo = at<float>(self, 0xa96);
  at<float>(self, 0xaed) = lo > a ? lo : minss(at<float>(self, 0xa9a), a);
}
PCREG(5d2ab0, ZCamHelper_UpdateFocusAngleOni);

// 0x5d2280 ZCamHelper::SetPointerOnScreenOni(): pad pointer ray: from the focal point along the pointer yaw/pitch,
// target point at the pick range (+0xd15) and far point at 10000 (+0xa7e); no lock (+0xd33/+0xd34 cleared); the
// ray (camera distance + pick range, flags 0x10) is cast from the camera (+0xcad) into +0xa7e, its shadow point
// (+0xa8a, 50 units, mode 2) found, and the screen offset sent to the OSD pointer when the lag zones exceed 1 deg.
static THISCALL void ZCamHelper_SetPointerOnScreenOni(void *self) {
  (void)angle_dist(at<float>(self, 0xa54), at<float>(self, 0xae9));
  float eye[3];
  vcall<void>(self, 0x88, eye);
  double p = (double)at<float>(self, 0xa5c);
  double y = (double)at<float>(self, 0xa54);
  float *aim = &at<float>(self, 0xa72);
  double cy = crt::cos(y);
  aim[0] = (float)(cy * crt::cos(p));
  aim[1] = (float)crt::sin(p);
  double sy = crt::sin(y);
  aim[2] = (float)(sy * crt::cos(p));
  ext_4e0d80(aim, at<float>(self, 0xdfd));
  ext_43e8e0(&at<float>(self, 0xd15), eye, aim);
  ext_4e0d80(aim, 10000.0f);
  float *far_ = &at<float>(self, 0xa7e);
  ext_43e8e0(far_, eye, aim);
  at<u16>(self, 0xd33) = 0;
  float m[9];
  ext_4de7a0(m);
  long double cur = vcall<long double>(ptr(self, 0xb54), 0xac);
  ext_4e0d80(aim, (float)(cur + at<float>(self, 0xdfd)));
  ext_5ceed0(self, far_, &at<float>(self, 0xcad), aim, 0x10, 1, 0);
  u32 *sh = &at<u32>(self, 0xa8a);
  sh[0] = ((u32 *)far_)[0];
  sh[1] = ((u32 *)far_)[1];
  sh[2] = ((u32 *)far_)[2];
  ext_5cefc0(self, (float *)sh, aim, 50.0f, 2);
  float scr[2];
  ext_5cf300(self, scr, far_);
  const float one = G(float, 0x67da04);
  float sx = !(one >= at<float>(self, 0xaf9)) ? scr[0] : 0.0f;
  float sy2 = !(one >= at<float>(self, 0xafd)) ? scr[1] : 0.0f;
  if (ptr(self, 0xe18)) ext_5a7500(ptr(self, 0xe18), sx, sy2);
}
PCREG(5d2280, ZCamHelper_SetPointerOnScreenOni);
