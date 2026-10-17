// batch1028.cpp - ZCamHelper::ControlBodyOni: hero body control relative to the camera (walk/run, strafe,
// turn rate, look-at). Shared by the mouse and pad schemes. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" FASTCALL long double ext_44c840(float *v);                            // vnorm (returns the length)
extern "C" FASTCALL void ext_441970(float *out, const float *v, const float *m);  // out = v * M
extern "C" FASTCALL void ext_4419f0(float *v, const float *m);                    // v = v * M
extern "C" FASTCALL void ext_446ee0(float *out, const float *a, const float *b);  // out = a x b
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);    // d = a - b
extern "C" FASTCALL long double ext_4e0830(const float *a, const float *b);       // |a - b|^2
extern "C" FASTCALL void ext_4e0d80(float *v, float len);                         // vsetlen
extern "C" FASTCALL void ext_4e09b0(float *v);                                    // vneg
extern "C" FASTCALL void ext_443ef0(float *out, const float *a, const float *b, float s);  // out = a + b*s
extern "C" THISCALL void ext_5cf690(void *self, float *out);                      // GetFireAimPos (batch1015)

static inline bool nonzero3(const float *v) { return !(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f); }
static inline float dot3(const float *a, const float *b) {  // (a.y*b.y + a.x*b.x) + a.z*b.z, the original's order
  return a[1] * b[1] + a[0] * b[0] + a[2] * b[2];
}

// Hero flag bits at +0x417 used here: 1 walk, 2 run, 4 backwards/strafe-back, 8 / 0x10 strafe right/left,
// 0x20 / 0x40 turn, 0x200 no control, 0x400000 (no turning), 0x4000000 (no running), 0x8000000 (slow turn),
// 0x10000000 (escort / entity-tracking mode). The low flags (mask 0xffff1e00 kept) are rebuilt every frame.
//
// 0x5ce0b0 ZCamHelper::ControlBodyOni()
static THISCALL void ZCamHelper_ControlBodyOni(u8 *self) {
  u8 *hero = ptr(self, 0x44);
  u32 oldFlags = at<u32>(hero, 0x417);
  at<u32>(hero, 0x417) = oldFlags & 0xffff1e00;
  vcall<void>(hero, 0x648, 0u);
  // Move input (side, 0, forward) normalized; its length is the move speed (0.3 or 0 while aiming).
  float *mv = &at<float>(self, 0xb39);
  float fwd = at<float>(self, 0xb27);
  at<u32>(self, 0xb39) = at<u32>(self, 0xb2b);
  at<u32>(self, 0xb3d) = 0;
  mv[2] = fwd;
  float speed = 0.0f;
  if (nonzero3(mv)) {
    long double s = (long double)mv[0] * mv[0];
    s = s + (long double)mv[1] * mv[1];
    s = s + (long double)mv[2] * mv[2];
    long double len = fsqrt_x87(s);
    long double inv = 1.0L / len;
    mv[0] = (float)(mv[0] * inv);
    mv[1] = (float)(mv[1] * inv);
    mv[2] = (float)(mv[2] * inv);
    speed = (float)len;
  }
  at<float>(self, 0xb35) = speed;
  if (at<u8>(self, 0xb45)) at<u32>(self, 0xb35) = speed > G(float, 0x67c1a4) ? 0x3e99999a : 0;
  at<u8>(self, 0xb19) = 0;
  bool strafe = vcall<bool>(hero, 0x4d0) || vcall<u32>(hero, 0x3f0) == 0x11 || at<u8>(self, 0xb45) || at<u8>(hero, 0x94e);
  if (!at<u8>(hero, 0x600) || (at<u32>(hero, 0x417) & 0x200)) return;
  if (at<u8>(hero, 0x66f)) {
    at<u32>(self, 0xb35) = 0;
    ((u32 *)mv)[0] = ((u32 *)mv)[1] = ((u32 *)mv)[2] = 0;
  }
  if (at<float>(self, 0xb35) > 0.0f) {
    at<u8>(self, 0xb19) = 1;
    if (at<float>(hero, 0x80b) == 0.0f)
      at<float>(hero, 0x80b) = (float)at<s32>(G(u8 *, 0x70039c), 0x40) * G(float, 0x6785e4);
    if (at<float>(self, 0xb35) > G(float, 0x67c1a4) && !(at<u32>(hero, 0x417) & 0x4000000))
      at<u32>(hero, 0x417) |= 2;
    else
      at<u32>(hero, 0x417) |= 1;
    if (G(float, 0x67a6b0) > at<float>(self, 0xb41) && strafe) at<u32>(hero, 0x417) |= 4;
    u32 f = at<u32>(hero, 0x417);
    if ((f & 0x400000) && 0.0f > at<float>(self, 0xb41)) at<u32>(hero, 0x417) = f | 4;
  }
  float hm[9], hp[3];  // hero matrix (row 0 negated = facing) and position
  vcall<void>(hero, 0x80, hm, hp);
  float *facing = hm;
  ext_4e09b0(facing);
  float cm[9], cp[3];  // camera focus matrix and position
  vcall<void>(self, 0x90, cm, cp);
  at<u32>(self, 0xb11) = 0x43fa0000;  // 500
  float D[3] = {0.0f, 0.0f, 0.0f};
  bool haveD = false;
  u32 f = at<u32>(hero, 0x417);
  if (f & 0x10000000) {
    if (f & 2) at<u32>(hero, 0x417) = (f & ~2u) | 1;
    void *tl = vcall<void *>(ptr(SYS9B, 0xadc), 0x25c, (const char *)0x685f44, 0u);  // "TrackLinkObjects"
    void *tracker = vcall<void *>(tl, 0x100, (const char *)0x6a5cf0);                 // "EntityTracker"
    s32 iter = -1;
    if (tracker) {
      for (u8 *e = vcall<u8 *>(tracker, 0x84, hp, 500.0f, &iter, 0xffffffffu); e;
           e = vcall<u8 *>(tracker, 0x84, hp, 500.0f, &iter, 0xffffffffu)) {
        if (e == hero || vcall<bool>(e, 0x438)) continue;
        float p[3] = {0.0f, 0.0f, 0.0f};
        vcall<void>(e, 0x84, p);
        float d2 = (float)ext_4e0830(hp, p);
        if (d2 > G(float, 0x6b4fc8)) continue;  // farther than 500
        float u[3];
        ext_43e920(u, p, hp);
        (void)ext_44c840(u);
        float dt = facing[1] * u[1] + facing[0] * u[0] + facing[2] * u[2];
        float cr[3];
        ext_446ee0(cr, u, facing);  // result unused
        if (G(float, 0x67af2c) > dt || 0.0f > dt) continue;
        ext_43e920(D, p, hp);  // an escorted entity in front: steer by it
      }
    }
    if (nonzero3(D)) at<float>(self, 0xb11) = (float)crt::sqrt((double)(D[1] * D[1] + D[0] * D[0] + D[2] * D[2]));
    if (nonzero3(D)) {
      if (!(at<float>(self, 0xb35) == 0.0f)) {
        float w[3];
        ext_441970(w, mv, cm);
        w[1] = 0.0f;
        (void)ext_44c840(w);
        (void)ext_44c840(D);
        float d = w[0] * D[0] + w[1] * D[1] + w[2] * D[2];
        if (!(d > G(float, 0x6ad1f8))) {
          if (d > G(float, 0x6ad230)) {
            float cr[3];
            ext_446ee0(cr, w, D);
            at<u32>(hero, 0x417) |= 0.0f > cr[1] ? 0x10 : 8;
          } else {
            at<u32>(hero, 0x417) |= 4;
          }
        }
      }
      haveD = nonzero3(D);
    }
  }
  if (!haveD) {
    if (!(at<float>(self, 0xb35) == 0.0f)) {
      if (at<u8>(self, 0xb45)) {
        D[0] = cm[0];
        D[2] = cm[2];
      } else {
        ext_441970(D, mv, cm);
        if (G(float, 0x67a6b0) > at<float>(self, 0xb41) && strafe) ext_4e09b0(D);
      }
    } else if (strafe) {
      float a[3];
      ext_5cf690(self, a);
      float t[3] = {hp[0], hp[1] + G(float, 0x67da28), hp[2]};
      ext_43e920(D, a, t);
      if (0.0f > cm[1] * D[1] + cm[0] * D[0] + cm[2] * D[2]) ext_43e920(D, a, hp);
    } else {
      D[0] = facing[0];
      D[2] = facing[2];
    }
  }
  D[1] = 0.0f;
  (void)ext_44c840(D);
  if ((at<u32>(hero, 0x417) ^ oldFlags) & 3) at<u32>(hero, 0x829) = 0;
  ext_4419f0(mv, cm);
  at<u32>(self, 0xb3d) = 0;
  ext_4e0d80(mv, at<float>(self, 0xb35));
  vcall<void>(hero, 0x5c0, mv);
  float df = facing[1] * D[1] + facing[0] * D[0] + facing[2] * D[2];
  if (!(at<u32>(hero, 0x417) & 0x400000)) {
    float ang;
    if (df > G(float, 0x678858))
      ang = 0.0f;
    else if (G(float, 0x67af2c) > df)
      ang = G(float, 0x67da18);
    else
      ang = (float)crt::acos((double)df);
    float cr[3];
    ext_446ee0(cr, facing, D);
    at<u32>(hero, 0x417) |= cr[0] > 0.0f ? 0x40 : 0x20;
    bool slow = (at<u32>(hero, 0x417) >> 27) & 1;
    u8 snap = at<u8>(self, 0xb45) && at<float>(self, 0xb35) == 0.0f && G(float, 0x67a284) > ang;
    vcall<void>(hero, 0x648, (u32)snap);
    float k = slow ? G(float, 0x69f9cc) : G(float, 0x67c194);
    if (snap) k = G(float, 0x678858);
    u8 *sys = G(u8 *, 0x70039c);
    float dt = (float)(at<s32>(sys, 0x40) - at<s32>(sys, 0x44)) * G(float, 0x6785e4);
    if (dt == G(float, 0x6785d0)) dt = G(float, 0x67d9fc);
    float a = k * G(float, 0x67885c) * dt;
    float b = dt * G(float, 0x67885c);
    float one = G(float, 0x678858);
    float rate = (one < a ? one : a) * ang / b;
    at<float>(hero, 0x80f) = rate;
    if (G(float, 0x67da00) > rate) at<u8>(hero, 0x94e) = 0;
  }
  if (vcall<bool>(hero, 0x4d0)) return;
  u32 t = vcall<u32>(hero, 0x5d0);
  if (t == 0x10 || t == 0x11 || t == 0xf) return;
  float F[3] = {cm[0], 0.0f, cm[2]};
  (void)ext_44c840(F);
  if (!(F[1] * facing[1] + F[0] * facing[0] + F[2] * facing[2] > G(float, 0x6ad230))) return;
  float dir[3];
  ext_443ef0(dir, facing, cm, 2.0f);
  dir[1] = 0.0f;
  float bm[9], bp[3];
  u8 *vt = *(u8 **)hero;
  u32 x = (*(u32(THISCALL **)(void *, float *, float *))(vt + 0x3a0))(hero, bm, bp);
  (*(void(THISCALL **)(void *, u32))(vt + 0x390))(hero, x);
  vcall<void>(hero, 0x84, bp);
  float look[3];
  ext_443ef0(look, bp, dir, 100.0f);
  vcall<void>(hero, 0x8c, look);
  vcall<void>(hero, 0x39c, look);
}
PCREG(5ce0b0, ZCamHelper_ControlBodyOni);
