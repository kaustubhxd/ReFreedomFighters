// batch1004.cpp - ZFFCamera1 camera shake: UpdateShaking and ShakeCamera. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_5ca460(void *self, const float *p);  // ZFFCam SetCamPos (batch1001)
extern "C" FASTCALL float ext_4e0870(const float *a, const float *b);  // |a - b|
// CRT log and pow thunks (libm_sse2_*_precise: arguments and result in XMM0/XMM1 = __vectorcall). Called by address
// because extern "C" vectorcall names get an @@n suffix the linker cannot bind to ext_<hex>.
typedef double(VECTORCALL *libm1_t)(double);
typedef double(VECTORCALL *libm2_t)(double, double);
#define ext_634de8 ((libm1_t)0x634de8)
#define ext_634db2 ((libm2_t)0x634db2)

// ZSysInterface slot 0x1c0: random float in [0,1) (file, line arguments are debug only); result in ST0.
static inline long double sys_rand(u32 line) {
  return vcall<long double>(G(void *, 0x70039c), 0x1c0, (const char *)0x6b4cb4, line);
}

// Shake fields: +0x4ba time left (s), +0x4be amplitude, +0x4c2 time to next amplitude change, +0x4c6 start delay.
// 0x5ccd10 ZFFCamera1::UpdateShaking() (GC name by size 368 B and the shake fields; inferred): after the delay, each
// frame the camera is moved up by amplitude * (25*rand + 50); every 15-30 ms the amplitude flips sign, and halves
// when it becomes positive.
static THISCALL void ZFFCamera1_UpdateShaking(void *self) {
  if (0.0f >= at<float>(self, 0x4ba)) return;
  float delay = at<float>(self, 0x4c6);
  if (delay > 0.0f) {
    at<float>(self, 0x4c6) = delay - at<float>(G(u8 *, 0x70039c), 0x48);
    return;
  }
  float r = (float)(sys_rand(0x47a) * G(float, 0x685270) + G(float, 0x680a84));
  float v[3];
  v[0] = at<float>(self, 0x444);
  v[1] = at<float>(self, 0x448) + at<float>(self, 0x4be) * r;
  v[2] = at<float>(self, 0x44c);
  ext_5ca460(self, v);
  if (0.0f > at<float>(self, 0x4c2)) {
    float a = at<float>(self, 0x4be) * G(float, 0x67af2c);  // * -1
    at<float>(self, 0x4be) = a;
    if (a > 0.0f) at<float>(self, 0x4be) = a * G(float, 0x67a6ac);  // * 0.5
    at<float>(self, 0x4c2) = (float)(sys_rand(0x483) * G(float, 0x699088) + G(float, 0x69f9cc));
  }
  u8 *sys = G(u8 *, 0x70039c);
  at<float>(self, 0x4ba) = at<float>(self, 0x4ba) - at<float>(sys, 0x48);
  at<float>(self, 0x4c2) = at<float>(self, 0x4c2) - at<float>(sys, 0x48);
}
PCREG(5ccd10, ZFFCamera1_UpdateShaking);

// 0x5cc900 ZFFCamera1::ShakeCamera(float* pos, float strength, float radius) (GC name by size 424 B and the only
// caller Command's shake message; inferred). An explosion at `pos` shakes the camera if the player (+0x408) is
// within `radius` (default 4000 when radius <= 1/8192): 0.8 s of shaking, first amplitude change after 30 ms,
// a start delay of distance/20000 + 0.05 s (unless a delay is already pending), and an amplitude that falls from
// `strength` at 500 units to strength/10 at `radius`: strength * (max(500, d) / 500) ^ -(ln 10 / ln(radius/500)).
// A stronger shake replaces a weaker one. The focus geometry is told (slot 0x438, e.g. pad rumble).
static THISCALL void ZFFCamera1_ShakeCamera(void *self, float *pos, float strength, float radius) {
  float d = ext_4e0870(&at<float>(self, 0x408), pos);
  const float eps = G(float, 0x679540);
  if (!(radius > eps)) radius = G(float, 0x6b4d38);
  if (!(radius > d)) return;
  at<u32>(self, 0x4ba) = 0x3f4ccccd;  // 0.8 s
  at<u32>(self, 0x4c2) = 0x3cf5c28f;  // 0.03 s
  if (eps > at<float>(self, 0x4c6)) at<float>(self, 0x4c6) = d / G(float, 0x6a2b00) + G(float, 0x681dc4);
  float m = _mm_cvtss_f32(_mm_max_ss(_mm_set_ss(G(float, 0x680a90)), _mm_set_ss(d)));  // maxss(500, d)
  double x = (double)(m * G(float, 0x68e2c0));
  float l10 = (float)ext_634de8(G(double, 0x692790));
  float lr = (float)ext_634de8((double)radius);
  float l500 = (float)ext_634de8(G(double, 0x69ff70));
  float e = -(l10 / (lr - l500));
  float amp = (float)ext_634db2(x, (double)e) * strength;
  __m128d cur = _mm_and_pd(_mm_cvtps_pd(_mm_load_ss(&at<float>(self, 0x4be))), *(const __m128d *)0x67cd50);
  if ((double)amp > _mm_cvtsd_f64(cur)) at<float>(self, 0x4be) = amp;
  void *g = vcall<void *>(SYS9B, 0x58, at<u32>(self, 0x368));
  if (g) vcall<void>(g, 0x438);
}
PCREG(5cc900, ZFFCamera1_ShakeCamera);
