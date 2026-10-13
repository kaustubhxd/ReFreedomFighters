// batch64.cpp - throw tree, inline session batch 64: ZFFActionThrow::Update (0x5e0620), the hold-to-charge grenade
// throw: wind-up and charge meter, the release, the start point and the throw velocity.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u32(THISCALL *vcallU0)(void *self);
typedef u32(THISCALL *vcallUP)(void *self, void *a);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVPU)(void *self, void *a, u32 b);
typedef void(THISCALL *vcallVUU)(void *self, u32 a, u32 b);
typedef void(THISCALL *setAnimFn)(void *self, void *anim, float t, float rate, u32 a, u32 b);
typedef u8(THISCALL *rayFn)(void *self, float *frac, u32 a, float *from, float *dir, u32 b, u32 c, u32 d, u32 e);
typedef void (*assertFn)();

extern "C" void THISCALL ext_59a6b0(u8 *osd, float v);                             // ZGameOSD::ProgressValue (batch 38)
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);          // vaddscalar (batch 63)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                 // PSVECAdd (batch 34)
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract (batch 34)
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);   // PSVECAdd3 (batch 63)
extern "C" float FASTCALL ext_44e630(float *dst, const float *src);                // vnorm(dst, src) (batch 63)
extern "C" float THISCALL ext_44c840(float *v);                                     // vnorm in place (batch 35)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                             // vscalar in place (batch 29)
extern "C" u8 *THISCALL ext_566fa0(u8 *hero);                                       // hero camera helper (batch 63)
extern "C" void THISCALL ext_5cf690(u8 *cam, float *out);                           // ZCamHelper::GetFireAimPos (batch 52)

static u8 *sys() { return G(u8 *, 0x70039c); }
static float secs(s32 ticks) { return (float)ticks * bitsf(0x3a800000u); }   // ticks / 1024
static float u2f(u32 x) { return (float)(double)x; }
static float len3(const float *v) {
  float s = ((v[1] * v[1]) + (v[0] * v[0])) + (v[2] * v[2]);
  return (float)crt::sqrt((double)s);
}

// 0x5e0620 ZFFActionThrow::Update(), thiscall, al (false when the throw animation has finished). Hero = +8, wind-up
// animation = +0xc, throw animation = +0x10; +0x14, +0x18 and +0x1c are times in seconds (ticks / 1024), +0x20 says the
// grenade has left the hand and +0x21 is the aimed-throw flag (from Execute).
// Before +0x14 nothing happens. During the wind-up the charge meter (shown with ZGameOSD::ProgressValue) is
// (+0x18 - +0x14) over (frames + 9) / 25 seconds, clamped to [0, 1]; holding fire (hero +0x669) moves +0x18 to now.
// While fire is held and the wind-up has not ended, the hero plays it at its own progress (slot 0x244) and +0x1c
// follows now. After that the throw animation plays from +0x1c; 9/25 s in, the grenade is released once:
// - the item is the hero's slot 0x50c. Its start is the hero point (0, 100, 0) (slot 0x84) moved by the arm offset
//   (0, 115, 0) and then forward (0, 0, -100) (slot 0x88 each), each move cut 5 short of a wall when the level's ray
//   test ([[0x70039c]+0x1aa3]+0x1c, slot 0x30) hits. The start goes to item +0x109.
// - speed = meter * 1050 + 450. A free throw goes along the camera direction (forward, or the helper's +0xa72 when
//   its mode +0xa4c is not 1) raised by 0.3 and scaled to the speed. An aimed throw solves for the camera's fire-aim
//   point under gravity -982: flight time t = distance / 1500, v = (d - g t^2 / 2) / t, its length clamped to
//   [0.75, 1.25] x speed and at most 1500.
// - the item gets start + velocity (slot 0x32c), states (3, 0) and (0, 0) on slot 0x2d0, and when the hero's count
//   (slot 0x560) plus the item's (slot 0x35c) is 0 the hero gets slot 0x54c(0, 1) and the item (1, 0).
// The throw animation is set each frame at min(progress, 1) and rate +0x5c / +0x6c of the animation.
static u8 THISCALL throwUpdate(u8 *self) {
  s32 now = *(s32 *)(sys() + 0x40);
  float t0 = *(float *)(self + 0x14);
  s32 t0i = _mm_cvttss_si32(_mm_set_ss(t0 * 1024.0f));
  if (now < t0i)
    return 1;
  u8 *animA = *(u8 **)(self + 0xc);
  u32 la = *(u32 *)(animA + 0x64) - *(u32 *)(animA + 0x60);
  u8 *hero = *(u8 **)(self + 8);
  float p = secs((s32)((u32)now - (u32)t0i)) / (u2f(la) / 25.0f);
  if (hero[0x669])
    *(float *)(self + 0x18) = secs(now);
  float meter = (*(float *)(self + 0x18) - t0) / (u2f(la + 9) / 25.0f);
  float m = 0.0f;
  if (!(0.0f > meter))
    m = 1.0f < meter ? 1.0f : meter;
  ext_59a6b0(*(u8 **)(hero + 0x852), m);
  hero = *(u8 **)(self + 8);
  if (hero[0x669] && 1.0f > p) {
    ((setAnimFn)VT(hero, 0x244))(hero, *(u8 **)(self + 0xc), p, 0.0f, 0, 0);
    *(float *)(self + 0x1c) = secs(*(s32 *)(sys() + 0x40));
    return 1;
  }
  s32 t2i = _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x1c) * 1024.0f));
  float e2 = secs((s32)(*(u32 *)(sys() + 0x40) - (u32)t2i));
  u8 *animB = *(u8 **)(self + 0x10);
  u32 lb = *(u32 *)(animB + 0x64) - *(u32 *)(animB + 0x60);
  if (!self[0x20] && e2 * 25.0f > 9.0f) {
    self[0x20] = 1;
    u8 *item = (u8 *)((vcallU0)VT(hero, 0x50c))(hero);
    float up[3] = {0.0f, 100.0f, 0.0f}, off[3] = {0.0f, 115.0f, 0.0f}, fwd[3] = {0.0f, 0.0f, -100.0f};
    hero = *(u8 **)(self + 8);
    ((vcallVP)VT(hero, 0x84))(hero, up);
    hero = *(u8 **)(self + 8);
    ((vcallVP)VT(hero, 0x88))(hero, off);
    hero = *(u8 **)(self + 8);
    ((vcallVP)VT(hero, 0x88))(hero, fwd);
    float pos[3] = {up[0], up[1], up[2]};
    float frac = 1.0f;
    u8 *ray = *(u8 **)(*(u8 **)(sys() + 0x1aa3) + 0x1c);
    if (((rayFn)VT(ray, 0x30))(ray, &frac, 0, pos, off, 1, 2, 1, 0)) {
      float l = len3(off);
      ext_451890(pos, off, (frac * l - 5.0f) / l);
    } else {
      ext_441940(pos, off);
    }
    ray = *(u8 **)(*(u8 **)(sys() + 0x1aa3) + 0x1c);
    if (((rayFn)VT(ray, 0x30))(ray, &frac, 0, pos, fwd, 1, 2, 1, 0)) {
      float l = len3(fwd);
      ext_451890(pos, fwd, (l * frac - 5.0f) / l);
    } else {
      ext_441940(pos, fwd);
    }
    animB = *(u8 **)(self + 0x10);
    hero = *(u8 **)(self + 8);
    ((vcallVPU)VT(hero, 0x268))(hero, animB, *(u32 *)(animB + 0x7c));
    *(float *)(item + 0x109) = pos[0];
    *(float *)(item + 0x10d) = pos[1];
    *(float *)(item + 0x111) = pos[2];
    hero = *(u8 **)(self + 8);
    float v[3] = {0.0f, 100.0f, 0.0f};
    if (*(u32 *)(hero + 0x85a) == 0) {
      u32 h = ((vcallUU)VT(hero, 0x100))(hero, 0x6a6e88u);   // "ZCamHelper"
      *(u32 *)(hero + 0x85a) = h;
      if (!h) {
        assertFn f = G(assertFn, 0x7003b0);
        if (f)
          f();
        else
          __asm__ volatile("int3");
        goto give;
      }
    }
    {
      float spd = m * 1050.0f + 450.0f;
      hero = *(u8 **)(self + 8);
      if (!self[0x21]) {
        u8 *ch = ext_566fa0(hero);
        hero = *(u8 **)(self + 8);
        if (*(u32 *)(ch + 0xa4c) == 1) {
          v[0] = 0.0f;
          v[1] = 0.0f;
          v[2] = -1.0f;
          ((vcallVP)VT(hero, 0x88))(hero, v);
        } else {
          ch = ext_566fa0(hero);
          ext_44e630(v, (const float *)(ch + 0xa72));
        }
        v[1] = v[1] + bitsf(0x3e99999au);   // 0.3
        ext_44c840(v);
        ext_4e0d00(v, spd);
        ext_441940(v, pos);
      } else {
        u8 *ch = ext_566fa0(hero);
        ext_5cf690(ch, v);
        float g[3] = {0.0f, -982.0f, 0.0f}, d[3];
        ext_43e920(d, v, pos);
        float t = len3(d) * 0.5f / 750.0f;
        ext_451890(d, g, t * -0.5f * t);
        ext_4e0d00(d, 1.0f / t);
        float hi = spd * 1.25f, lo = spd * 0.75f;
        float l = ext_44c840(d);
        float x = hi < l ? hi : l;
        x = lo > x ? lo : x;
        x = 1500.0f < x ? 1500.0f : x;
        ext_4e0d00(d, x);
        ext_43e8e0(v, pos, d);
      }
    }
  give:
    ((vcallVP)VT(item, 0x32c))(item, v);
    ((vcallVUU)VT(item, 0x2d0))(item, 3, 0);
    ((vcallVUU)VT(item, 0x2d0))(item, 0, 0);
    hero = *(u8 **)(self + 8);
    u32 n = ((vcallUP)VT(hero, 0x560))(hero, item);
    n += ((vcallU0)VT(item, 0x35c))(item);
    if (n == 0) {
      hero = *(u8 **)(self + 8);
      ((vcallVUU)VT(hero, 0x54c))(hero, 0, 1);
      ((vcallVUU)VT(item, 0x2d0))(item, 1, 0);
    }
  }
  float q = e2 / (u2f(lb) / 25.0f);
  animB = *(u8 **)(self + 0x10);
  hero = *(u8 **)(self + 8);
  float rate = (float)*(s32 *)(animB + 0x5c) / (float)*(s32 *)(animB + 0x6c);
  ((setAnimFn)VT(hero, 0x244))(hero, animB, q < 1.0f ? q : 1.0f, rate, 0, 0);
  return 1.0f > q;
}
PCREG(5e0620, throwUpdate);
