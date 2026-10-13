// batch82.cpp - wrench tree, inline session batch 82 (2026-10-12, docs/41): ZFFHeroMovementCloseCombat::GotControl
// (0x5e4980), the start of a close-combat attack: the clip, its timing, and the target (the last character the entity
// tracker returns within reach and in front), then the clip and the "CloseCombatAttackBegin" event.
// "self" is the movement; its +0x36d is the hero. The stack-cookie epilogue (0x633654) is the CRT's own check and is not
// part of the port.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef void(THISCALL *vcallV0)(void *self);
typedef u32(THISCALL *vcallU0)(void *self);
typedef u32(THISCALL *vcallUP)(void *self, const void *a);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef void(THISCALL *vcallVP)(void *self, float *a);
typedef void(THISCALL *vcallVPP)(void *self, float *a, float *b);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef u8(THISCALL *vcallB0)(void *self);
typedef u32(THISCALL *trackFn)(void *self, const float *pos, float range, s32 *iter, u32 team);
typedef void(THISCALL *playFn)(void *self, u32 clip, u32 flags, float a, float b, float c);
typedef void(THISCALL *placeFn)(void *self, const float *m33, const float *pos, float t);
typedef u16(THISCALL *eventFn)(void *self, const char *name, u32 a, const char *file, u32 line, s32 *arg, u32 b);
typedef u8 *(THISCALL *logGetFn)(void *self, const char *file, u32 line);
typedef void (*logPrintFn)(void *self, const char *msg);

extern "C" void THISCALL ext_595510(u8 *hero);                                       // stop firing: +0x813 = 0, RemoveAimTarget
extern "C" void FASTCALL ext_4e09b0(float *v);                                       // vneg
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);                // vdist2 = |a - b|^2 (ST0)
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);       // d = a - b
extern "C" void FASTCALL ext_446ee0(float *out, const float *a, const float *b);     // out = a x b
extern "C" float FASTCALL ext_44c840(float *v);                                      // vnorm in place, returns the length (ST0)
extern "C" void FASTCALL ext_4de040(float *m33, const float *dir, const float *up);  // createmat
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *b, float s);   // out = a + b * s

static u8 *sys() { return G(u8 *, 0x70039c); }
static u8 *hero_of(u8 *self) { return *(u8 **)(self + 0x36d); }
static s32 cvtt(float x) { return _mm_cvttss_si32(_mm_set_ss(x)); }

// The x87 normalise in the target loop: |d| in double (53-bit control), then each component times 1 / |d|, rounded once.
static void norm_x87(float *d) {
  double len = crt::sqrt((double)d[0] * d[0] + (double)d[1] * d[1] + (double)d[2] * d[2]);
  double inv = 1.0 / len;
  d[0] = (float)(d[0] * inv);
  d[1] = (float)(d[1] * inv);
  d[2] = (float)(d[2] * inv);
}

// 0x5e4980 ZFFHeroMovementCloseCombat::GotControl(), thiscall, no result.
// - Stops the hero's current action (slot 0x3dc) and its firing (0x595510).
// - Combo counter +0x60c: counted up when the last attack (+0x5b1) is under 0.2 s old, limited to 1 or 2 by +0x610 /
//   +0x5d2, but then set to 0 in every case (the PC build always starts the first attack).
// - The entity tracker (+0x608) is fetched once by name ("EntityTracker", [0x7003b8]+0x4ac slot 0x100); without it an
//   error line is logged.
// - Clip +0x594: +0x558 (an item whose template slot 0x300 is 2) or +0x54c, 24 bytes per combo step. +0x59c = 4 / and
//   +0x5a0 = 12 / the clip's frame count (+0x6c). Reach +0x5a4 = 60 with the MonkeyWrench (a weapon of kind 10 named so)
//   in hand, else 35. +0x5ad = now (s); +0x5b1 = now - 12 frames' worth (s).
// - Target: from the hero's position P (slot 0x80 also gives its forward, negated here), every character the tracker
//   returns within 170 (slot 0x84 iterator), not the hero, not slot 0x438 (dead), with |T - P|^2 <= 28900 (170^2;
//   72900 for combo steps) and the dot of the forward with the unit direction not below -1. The last one passing is
//   kept: its handle (render manager slot 0x4c) at +0x5b6, its position at +0x5ba, the direction at +0x5c6.
// - With a clip: the hero plays it (slot 0x228, flags 0x1021, 0, -1, 1) and gets flag 0x10000000 at +0x417. With a
//   target as well, the hero is placed facing it at 84..129 units (createmat, slot 0x238 at the clip's 4-frame point)
//   and the target gets the "CloseCombatAttackBegin" event (render manager slots 0x58 and 0x114, object slot 0x128).
// - +0x610 = 0.
static void THISCALL gotControl(u8 *self) {
  u8 *hero = hero_of(self);
  ((vcallV0)VT(hero, 0x3dc))(hero);
  ext_595510(hero_of(self));
  s32 n = cvtt((*(float *)(self + 0x5b1) + bitsf(0x3e4ccccdu)) * 1024.0f);   // (last + 0.2) * 1024
  bool keep = false;
  if (n >= *(s32 *)(sys() + 0x40)) {
    u32 k = ++*(u32 *)(self + 0x60c);
    if (!self[0x610] && *(u32 *)(self + 0x5d2) != 0)
      keep = k <= 1;
    else
      keep = k <= 2;
  }
  if (!keep)
    *(u32 *)(self + 0x60c) = 0;
  bool noTracker = *(u32 *)(self + 0x608) == 0;
  *(u32 *)(self + 0x60c) = 0;
  if (noTracker) {
    u8 *mgr = *(u8 **)(G(u8 *, 0x7003b8) + 0x4ac);
    u32 t = ((vcallUP)VT(mgr, 0x100))(mgr, (const void *)0x6a5cf0u);   // "EntityTracker"
    *(u32 *)(self + 0x608) = t;
    if (!t) {
      u8 *log = G(u8 *, 0x700390);
      u8 *out = ((logGetFn)VT(log, 0x20))(log, (const char *)0x6b7a5cu, 0x579);   // ZFFHeroMovement.cpp
      ((logPrintFn)VT(out, 0x30))(out, (const char *)0x6b7d98u);   // "ERROR: ...GotControl -> can't get m_pEntityTracker"
    }
  }
  hero = hero_of(self);
  self[0x5ac] = 1;
  self[0x5b5] = 0;
  u8 alt = 0, wrench = 0;
  u8 *w = (u8 *)((vcallU0)VT(hero, 0x504))(hero);
  if (w && *(u32 *)(*(u8 **)(w + 0xc) + 0x23) == 0x1007d2u) {
    u8 *m = (u8 *)((vcallU0)VT(w, 0x350))(w);
    if (((vcallU0)VT(m, 0x300))(m) == 2)
      alt = 1;
    m = (u8 *)((vcallU0)VT(w, 0x350))(w);
    if (((vcallU0)VT(m, 0x330))(m) == 0xa) {
      m = (u8 *)((vcallU0)VT(w, 0x350))(w);
      const char *a = *(const char **)(m + 4);
      if (!a)
        a = (const char *)0x67c8e8u;   // "<NONAME>"
      const char *b = (const char *)0x6ad8b4u;   // "MonkeyWrench"
      while (*a == *b && *a) {
        a++;
        b++;
      }
      if (*a == *b)
        wrench = 1;
    }
  }
  hero = hero_of(self);
  u32 combo = *(u32 *)(self + 0x60c);
  s32 set = (*(u32 *)(hero + 0x417) & 0x400) ? 1 : 2;
  if (*(u32 *)(hero + 0x417) & 0x20000000)
    set = 2;
  u32 clip = alt ? *(u32 *)(self + combo * 24 + 0x558) : *(u32 *)(self + combo * 24 + 0x54c);
  *(u32 *)(self + 0x594) = clip;
  *(u32 *)(self + 0x5a8) = 1;
  if (clip) {
    *(float *)(self + 0x59c) = 4.0f / (float)*(s32 *)(clip + 0x6c);
    *(float *)(self + 0x5a0) = 12.0f / (float)*(s32 *)(clip + 0x6c);
  }
  *(u32 *)(self + 0x5a4) = wrench ? 0x42700000u : 0x420c0000u;   // 60 / 35
  *(float *)(self + 0x5ad) = (float)*(s32 *)(sys() + 0x40) * bitsf(0x3a800000u);
  s32 back = cvtt(*(float *)(self + 0x5a0) * -1024.0f);
  s32 now = *(s32 *)(sys() + 0x40);
  *(u32 *)(self + 0x5b6) = 0;
  *(float *)(self + 0x5b1) = (float)(s32)((u32)now - (u32)back) * bitsf(0x3a800000u);
  float fwd[9], pos[3];   // fwd[0..2]: the hero's forward, later the 3x3 frame (createmat writes 9 floats)
  ((vcallVPP)VT(hero, 0x80))(hero, fwd, pos);
  ext_4e09b0(fwd);
  s32 iter = -1;
  float tpos[3] = {0.0f, 0.0f, 0.0f};   // the kept target's position
  u8 *tr = *(u8 **)(self + 0x608);
  if (tr) {
    u8 *e = (u8 *)((trackFn)VT(tr, 0x84))(tr, pos, 170.0f, &iter, *(u32 *)(*(u8 **)(hero_of(self) + 0x54) + 0xc));
    while (e) {
      if (e != hero_of(self) && !((vcallB0)VT(e, 0x438))(e)) {
        float t[3] = {0.0f, 0.0f, 0.0f};
        ((vcallVP)VT(e, 0x84))(e, t);
        float lim = *(u32 *)(self + 0x60c) == 0 ? 28900.0f : 72900.0f;
        float d2 = ext_4e0830(pos, t);
        if (!(d2 > lim)) {
          float d[3], cr[3];
          ext_43e920(d, t, pos);
          if (!(d[0] == 0.0f && d[1] == 0.0f && d[2] == 0.0f))
            norm_x87(d);
          float dot = fwd[1] * d[1] + fwd[0] * d[0] + fwd[2] * d[2];
          ext_446ee0(cr, d, fwd);   // result not used
          if (!(-1.0f > dot)) {
            u8 *rm = *(u8 **)(sys() + 0x9b);
            *(u32 *)(self + 0x5b6) = ((vcallUP)VT(rm, 0x4c))(rm, e);
            *(float *)(self + 0x5ba) = t[0];
            *(float *)(self + 0x5be) = t[1];
            *(float *)(self + 0x5c2) = t[2];
            *(float *)(self + 0x5c6) = d[0];
            *(float *)(self + 0x5ca) = d[1];
            *(float *)(self + 0x5ce) = d[2];
            tpos[0] = t[0];
            tpos[1] = t[1];
            tpos[2] = t[2];
          }
        }
      }
      tr = *(u8 **)(self + 0x608);
      e = (u8 *)((trackFn)VT(tr, 0x84))(tr, pos, 170.0f, &iter, *(u32 *)(*(u8 **)(hero_of(self) + 0x54) + 0xc));
    }
  }
  clip = *(u32 *)(self + 0x594);
  if (clip) {
    hero = hero_of(self);
    ((playFn)VT(hero, 0x228))(hero, clip, 0x1021, 0.0f, -1.0f, 1.0f);
    *(u32 *)(hero_of(self) + 0x417) |= 0x10000000u;
    if (*(u32 *)(self + 0x5b6)) {
      float v[3];
      ext_43e920(v, tpos, pos);
      v[1] = 0.0f;
      float len = ext_44c840(v);
      if (len == 0.0f) {
        v[0] = fwd[0];
        v[1] = fwd[1];
        v[2] = fwd[2];
      } else {
        ext_4e09b0(v);
      }
      float dist = 84.0f;
      if (!(84.0f > len))
        dist = 129.0f < len ? 129.0f : len;
      ext_4de040(fwd, v, 0);
      float py = pos[1];
      ext_443ef0(pos, tpos, v, dist);
      pos[1] = py;
      u8 *c = *(u8 **)(self + 0x594);
      hero = hero_of(self);
      ((placeFn)VT(hero, 0x238))(hero, fwd, pos, (float)*(s32 *)(c + 0x6c) * *(float *)(self + 0x59c));
      u8 *rm = *(u8 **)(sys() + 0x9b);
      u8 *obj = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0x5b6));
      rm = *(u8 **)(sys() + 0x9b);
      u16 ev = ((eventFn)VT(rm, 0x114))(rm, (const char *)0x6a4d40u, 0, (const char *)0x6b7a5cu, 0x60d, &set, 0);
      ((vcallVU)VT(obj, 0x128))(obj, (u32)ev);
    }
  }
  self[0x610] = 0;
}
PCREG(5e4980, gotControl);
