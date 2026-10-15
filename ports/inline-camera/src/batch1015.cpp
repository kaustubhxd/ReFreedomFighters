// batch1015.cpp - ZCamHelper: GetPolarAngles, Get2DProjection, GetFireAimPos, SetSlowPointer, DoChangeFocus.
// Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_446320(void *zcam, float *out, const float *p);  // ZCAMERA::Proj2D
extern "C" THISCALL u32 ext_5cf110(void *self);                     // (unnamed, x87) pick enemy under pointer
extern "C" THISCALL void ext_5d2630(void *self, u32 target);        // (unnamed) lock onto target
extern "C" THISCALL void ext_5cf420(void *self, float *out);        // (unnamed, x87) aim origin
extern "C" FASTCALL void ext_4e09b0(float *v);                       // vneg
extern "C" FASTCALL void ext_4e0d80(float *v, float len);            // vsetlen
extern "C" THISCALL void ext_5ceed0(void *self, float *out, const float *o, const float *d, u32 flags, u32 a, u32 b);  // Find3DPointerPos
extern "C" THISCALL void ext_5d0bd0(void *self, const float *p, float speed, u32 fromCam);  // MoveFocus (batch1014)
extern "C" THISCALL void ext_662c50(void *e, float *out);  // vector ease: current value
extern "C" THISCALL void ext_662f40(void *e, float *out);  // matrix ease: current facing
extern "C" FASTCALL void ext_4de040(float *m33, const float *dir, const float *up);  // createmat
extern "C" FASTCALL void ext_4de420(float *d, const float *s);  // mcpy

static inline float wrap_pi(float y) {
  if (y > G(float, 0x67da18))
    y = y - G(float, 0x68aef8);
  else if (G(float, 0x6ad238) > y)
    y = y + G(float, 0x68aef8);
  return y;
}

// 0x5cf820 ZCamHelper::GetPolarAngles(CAngle& yaw, float& pitch, const float* dir): dir normalized (x87), yaw =
// atan(z/x) folded to -pi..pi by the sign of x (+-pi/2 when |x| <= 1/8192), pitch = atan(y / |xz|) (0 when
// |xz| <= 1/8192).
static THISCALL void ZCamHelper_GetPolarAngles(void *self, float *yaw, float *pitch, const float *dir) {
  float v[3] = {dir[0], dir[1], dir[2]};
  if (!(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)) {
    long double s = (long double)v[0] * v[0];
    s = s + (long double)v[1] * v[1];
    s = s + (long double)v[2] * v[2];
    long double inv = 1.0L / fsqrt_x87(s);
    v[0] = (float)(v[0] * inv);
    v[1] = (float)(v[1] * inv);
    v[2] = (float)(v[2] * inv);
  }
  float x = v[0], y = v[1], z = v[2];
  __m128d ax = _mm_and_pd(_mm_cvtps_pd(_mm_set_ss(x)), *(const __m128d *)0x67cd50);
  if (G(double, 0x685278) >= _mm_cvtsd_f64(ax)) {
    *(u32 *)yaw = 0.0f > z ? 0xbfc90fdb : 0x3fc90fdb;  // -+pi/2
  } else {
    float a = (float)crt::atan((double)(z / x));
    const float pi = G(float, 0x67da18);
    if (a > G(float, 0x6ad1fc) || G(float, 0x6ad234) > a) a = pi;
    *yaw = a;
    if (0.0f > x) *yaw = wrap_pi(a - pi);
  }
  float h = (float)crt::sqrt((double)(z * z + x * x));
  if (G(float, 0x679540) >= h)
    *(u32 *)pitch = 0;
  else
    *pitch = (float)crt::atan((double)(y / h));
}
PCREG(5cf820, ZCamHelper_GetPolarAngles);

// 0x5cf300 ZCamHelper::Get2DProjection(float* out, const float* p): screen position of p in the engine camera
// (geometry of handle +0xc6d, slot 0x8c to camera space, ZCAMERA::Proj2D), clamped to x -0.44..0.44 and
// y -0.46..0.46 (the OSD pointer's range).
static THISCALL void ZCamHelper_Get2DProjection(void *self, float *out, const float *p) {
  void *g = vcall<void *>(SYS9B, 0x58, at<u32>(self, 0xc6d));
  if (!g) return;
  float v[3] = {p[0], p[1], p[2]};
  vcall<void>(g, 0x8c, v);
  ext_446320(g, out, v);
  if (G(float, 0x6b4fe0) > out[0])
    *(u32 *)&out[0] = 0xbee147ae;
  else if (out[0] > G(float, 0x6b4fac))
    *(u32 *)&out[0] = 0x3ee147ae;
  if (G(float, 0x6b4fe4) > out[1]) *(u32 *)&out[1] = 0xbeeb851f;
  if (out[1] > G(float, 0x6b4fb0)) *(u32 *)&out[1] = 0x3eeb851f;
}
PCREG(5cf300, ZCamHelper_Get2DProjection);

static inline void aim_dir(void *self, float *d) {
  if (at<u32>(self, 0xa4c) == 1) {
    d[0] = at<float>(self, 0xcdd);
    d[1] = at<float>(self, 0xce1);
    d[2] = at<float>(self, 0xce5);
    ext_4e09b0(d);
  } else {
    d[0] = at<float>(self, 0xa72);
    d[1] = at<float>(self, 0xa76);
    d[2] = at<float>(self, 0xa7a);
  }
}

// 0x5cf690 ZCamHelper::GetFireAimPos(float* out): where the hero shoots. With a free pointer (+0xd32) an enemy
// under it is locked first. A locked target gives its point (+0xd15); otherwise the aim ray from the aim origin
// is cast (Find3DPointerPos, flags 2) to camera distance + 10000 (+ 20000 in the sniper scope) and the hit point
// (+0xa7e) is used.
static THISCALL void ZCamHelper_GetFireAimPos(void *self, u32 *out) {
  if (at<u8>(self, 0xd32)) {
    at<u32>(self, 0xb50) = at<u32>(ptr(ptr(self, 0x44), 0x54), 0xc);
    if ((u8)ext_5cf110(self)) ext_5d2630(self, at<u32>(self, 0xd2e));
  }
  if (at<u8>(self, 0xd33)) {
    out[0] = at<u32>(self, 0xd15);
    out[1] = at<u32>(self, 0xd19);
    out[2] = at<u32>(self, 0xd1d);
    return;
  }
  float o[3], d[3];
  ext_5cf420(self, o);
  aim_dir(self, d);
  float len = 10000.0f;
  if (at<u8>(self, 0xb45) && at<u32>(self, 0xad5) == 4) len = 20000.0f;
  long double cur = vcall<long double>(ptr(self, 0xb54), 0xac);
  ext_4e0d80(d, (float)(cur + len));
  u32 *hit = &at<u32>(self, 0xa7e);
  ext_5ceed0(self, (float *)hit, o, d, 2, 1, 1);
  out[0] = hit[0];
  out[1] = hit[1];
  out[2] = hit[2];
}
PCREG(5cf690, ZCamHelper_GetFireAimPos);

// 0x5d24c0 ZCamHelper::SetSlowPointer(char on): the aim button (+0xb45), ignored while +0xb46 is set. Pressing:
// the aim angles are kept, the pointer ray (camera distance + 10000, flags 0x10) is cast from +0xcad and its hit
// becomes the close-up focus point (camera +0x4cb). Releasing: the angles are kept and, when the option at sys
// +0x6c is on, the view turns back toward the last hit at 60 deg/s (MoveFocus).
static THISCALL void ZCamHelper_SetSlowPointer(void *self, u32 on) {
  u8 c = at<u8>(self, 0xb46) == 0 ? (u8)on : 0;
  float *aim = &at<float>(self, 0xa72);
  u32 *hit = &at<u32>(self, 0xa7e);
  if (!c) {
    if (at<u8>(self, 0xb45)) {
      at<u32>(self, 0xa54) = at<u32>(self, 0xae9);
      at<u32>(self, 0xa5c) = at<u32>(self, 0xaed);
      if (at<u8>(G(u8 *, 0x70039c), 0x6c)) {
        long double cur = vcall<long double>(ptr(self, 0xb54), 0xac);
        ext_4e0d80(aim, (float)(cur + G(float, 0x67ff1c)));
        ext_5ceed0(self, (float *)hit, &at<float>(self, 0xcad), aim, 0x10, 1, 1);
        ext_5d0bd0(self, (float *)hit, bitsf(0x3f860a92), 0);
      }
    }
  } else if (!at<u8>(self, 0xb45)) {
    at<u32>(self, 0xa54) = at<u32>(self, 0xae9);
    at<u32>(self, 0xa5c) = at<u32>(self, 0xaed);
    long double cur = vcall<long double>(ptr(self, 0xb54), 0xac);
    ext_4e0d80(aim, (float)(cur + G(float, 0x67ff1c)));
    ext_5ceed0(self, (float *)hit, &at<float>(self, 0xcad), aim, 0x10, 1, 1);
    u8 *cam = ptr(self, 0xb54);
    at<u32>(cam, 0x4cb) = hit[0];
    at<u32>(cam, 0x4cf) = hit[1];
    at<u32>(cam, 0x4d3) = hit[2];
  }
  at<u8>(self, 0xb45) = c != 0;
}
PCREG(5d24c0, ZCamHelper_SetSlowPointer);

// 0x5cebc0 (unnamed) ZCamHelper::DoChangeFocus() (GC name by size 260 B and UpdateFocusSystem's call; inferred):
// step the two eases started by ChangeFocus; the focus position and matrix (built from the eased facing) follow;
// when both report done (slot 0 of each) the change ends.
static THISCALL void ZCamHelper_DoChangeFocus(void *self) {
  ext_662c50((u8 *)self + 0xd36, &at<float>(self, 0xd3a));
  float p0 = at<float>(self, 0xd3a), p1 = at<float>(self, 0xd3e), p2 = at<float>(self, 0xd42);
  ext_662f40((u8 *)self + 0xd87, &at<float>(self, 0xd8b));
  float d[3] = {at<float>(self, 0xd8b), at<float>(self, 0xd8f), at<float>(self, 0xd93)};
  float m[9];
  ext_4de040(m, d, 0);
  ext_4de420(&at<float>(self, 0xc89), m);
  at<float>(self, 0xc71) = p0;
  at<float>(self, 0xc75) = p1;
  at<float>(self, 0xc79) = p2;
  if (vcall<bool>((u8 *)self + 0xd36, 0) && vcall<bool>((u8 *)self + 0xd87, 0)) at<u8>(self, 0xd35) = 0;
}
PCREG(5cebc0, ZCamHelper_DoChangeFocus);
