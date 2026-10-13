// batch68.cpp - grenade flight, inline session batch 68: ZProjectile::FrameUpdateBallistic (0x4b9940), the per-frame
// grenade update (fuse, flight, bounces, resting and the bounce sound), and the in-place subtract 0x43e960.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u32(THISCALL *vcallUUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *vcallU0)(void *self);
typedef u32(THISCALL *vcallUP)(void *self, void *a);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVPP)(void *self, void *a, void *b);
typedef void(THISCALL *vcallVUPU)(void *self, u32 a, void *b, u32 c);
typedef u8(THISCALL *castFn)(void *self, void *coli, u32 a, u32 b, u32 c, u32 d, u32 e);
typedef long double(THISCALL *rndFn)(void *self, u32 file, u32 line);

extern "C" void THISCALL ext_4e71b0(u8 *pp, float *out, float t);                 // ZParamParticle::GetPos (batch 65)
extern "C" void THISCALL ext_4e7330(u8 *pp, float *out, float t);                 // velocity at t (batch 65)
extern "C" void THISCALL ext_4e73b0(u8 *pp, const float *pos, const float *vel, const float *acc, float drag,
                                    float time);                                  // ZParamParticle::Init (batch 65)
extern "C" void THISCALL ext_4b95d0(u8 *self, const float *vel);                 // ZProjectile::Explode (batch 67)
extern "C" u32 THISCALL ext_4ba180(u8 *self, u32 id);                             // GetMaterialDesc (batch 66)
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract (batch 34)
extern "C" void FASTCALL ext_443ef0(float *dst, const float *a, const float *v, float s);   // (batch 65)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                           // vscalar in place (batch 29)
extern "C" void FASTCALL ext_43e960(float *dst, const float *src);                // dst -= src (this batch)
extern "C" void FASTCALL ext_4e09b0(float *v);                                    // vneg in place
extern "C" void THISCALL ext_45bfd0(u8 *coli, float *n);                          // COLI hit-triangle normal
extern "C" void FASTCALL ext_4de7a0(float *m);                                    // mreset
extern "C" u8 *THISCALL ext_4db3b0(u8 *geom);                                     // ZBaseGeom::GetOwnerRoom
extern "C" u32 THISCALL ext_43ec00(u8 *room, float *mat, float *pos, u32 snd, u32 a, u32 b, u32 c);  // AddSound3d

// 0x43e960, fastcall (dst in ECX, src in EDX). dst -= src on three floats, all three before the stores (x87; a float
// subtract rounded through double gives the same bits).
static void FASTCALL vsubInPlace(float *dst, const float *src) {
  float s0 = dst[0] - src[0];
  float s1 = dst[1] - src[1];
  float s2 = dst[2] - src[2];
  dst[0] = s0;
  dst[1] = s1;
  dst[2] = s2;
}
PCREG(43e960, vsubInPlace);

static u8 *sys() { return G(u8 *, 0x70039c); }
static u8 *rmgr() { return *(u8 **)(sys() + 0x9b); }
static float secs(s32 ticks) { return (float)ticks * bitsf(0x3a800000u); }
static float len3(const float *v) {
  float s = ((v[1] * v[1]) + (v[0] * v[0])) + (v[2] * v[2]);
  return (float)crt::sqrt((double)s);
}

// 0x4b9940 ZProjectile::FrameUpdateBallistic(), thiscall. Projectile: geometry +0x44, fuse +0x48 and start +0x81
// (seconds), flags +0x89 (2 = resting/done, 4 = exploded, 0x20 = explode on any hit, 0x40 = warning played), the COLI
// +0x8d, the flight (ZParamParticle) +0x6d, the last bounce-sound time +0x85, the surface normal +0x75.
// - 1.5 s before the fuse runs out the warning plays once: the geometry's slot 0x128(+0x9d, position now, 0).
// - A projectile with a fuse that is resting when it runs out explodes (with zero velocity).
// - Otherwise, from the last frame's time to now in up to three steps: the flight's position now is cast from the current
//   position (world slot 0x2e0, mask 0x200000); without a hit the step ends there. On a hit at fraction f the time is
//   moved to the hit, the velocity there is taken, the hit normal (turned to world by the hit object's slot 0x88) is
//   made to face the ray. Hitting a non-bouncy surface (geometry flag 2 clear) first sticks the projectile (slot
//   0x100("...")->0x68(0x10, 0), slot 0xbc(1), flag 2); explode-on-hit projectiles, and sticky ones on a second such
//   hit, explode. A bounce reflects the velocity in the normal (the tangential part is scaled by 0 first and taken
//   away), caps it at 1500, keeps 0.35 of it, and restarts the flight 1 unit off the surface with gravity -982. Below
//   32.73 it comes to rest (flag 2) unless the fuse still runs and the surface is not a room surface.
// - Bounce sound at most every 0.2 s: volume (speed - 5) / 20 in [0, 1]; the sound is the material sound set's entry
//   for the owner's sound type (sound system slots 0x58 and 0x5c("...")), played with AddSound3d in the hit object's
//   room, volume * 0.7 and a random pitch offset (random number - 0.5) * 40.
// - At the end the geometry gets the frame and the final position (slot 0x7c).
static void THISCALL ballistic(u8 *self) {
  float now = secs(*(s32 *)(sys() + 0x40));
  float prev = secs(*(s32 *)(sys() + 0x44));
  float m[9], p[3];
  u8 *geom = *(u8 **)(self + 0x44);
  ((vcallVPP)VT(geom, 0x80))(geom, m, p);
  float g[3] = {0.0f, -982.0f, 0.0f};
  float v[3] = {0.0f, 0.0f, 0.0f};
  s32 ti = _mm_cvttss_si32(_mm_set_ss((*(float *)(self + 0x81) + *(float *)(self + 0x48)) * -1024.0f));
  float rem = secs((s32)(0u - *(u32 *)(sys() + 0x40) - (u32)ti));
  u32 fl = *(u32 *)(self + 0x89);
  if (!(fl & 0x40) && 1.5f > rem) {
    *(u32 *)(self + 0x89) = fl | 0x40;
    float w[3];
    ext_4e71b0(*(u8 **)(self + 0x6d), w, secs(*(s32 *)(sys() + 0x40)));
    geom = *(u8 **)(self + 0x44);
    ((vcallVUPU)VT(geom, 0x128))(geom, *(u16 *)(self + 0x9d), w, 0);
  }
  if (!(*(float *)(self + 0x48) == 0.0f) && 0.0f > rem) {
    fl = *(u32 *)(self + 0x89);
    if (!(fl & 4) && (fl & 2))
      ext_4b95d0(self, v);
  }
  if (*(u32 *)(self + 0x89) & 2)
    return;
  u8 snd = 0;
  s32 cnt = 3;
  float pn[3];
  if (!(prev == now)) {
    for (;;) {
      if (cnt-- == 0)
        break;
      ext_4e71b0(*(u8 **)(self + 0x6d), pn, now);
      u8 *coli = *(u8 **)(self + 0x8d);
      *(float *)(coli + 0x34) = 1.0f;
      (*(u8 **)(self + 0x8d))[0x6c] = 1;
      coli = *(u8 **)(self + 0x8d);
      *(float *)(coli + 0) = p[0];
      *(float *)(coli + 4) = p[1];
      *(float *)(coli + 8) = p[2];
      ext_43e920((float *)(*(u8 **)(self + 0x8d) + 0xc), pn, p);
      u8 *world = *(u8 **)(rmgr() + 0xadc);
      if (!((castFn)VT(world, 0x2e0))(world, *(u8 **)(self + 0x8d), 0, 6, 0x200000, 1, 1)) {
        prev = now;
      } else {
        coli = *(u8 **)(self + 0x8d);
        *(u32 *)(self + 0x71) = *(u32 *)(coli + 0x44);
        float th = prev + (now - prev) * *(float *)(coli + 0x34);
        prev = th;
        ext_4e7330(*(u8 **)(self + 0x6d), v, th);
        float *n = (float *)(self + 0x75);
        ext_45bfd0(*(u8 **)(self + 0x8d), n);
        u8 *rm = rmgr();
        u8 *hit = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(*(u8 **)(self + 0x8d) + 0x44));
        ((vcallVP)VT(hit, 0x88))(hit, n);
        coli = *(u8 **)(self + 0x8d);
        float d = (*(float *)(coli + 0x10) * n[1] + n[0] * *(float *)(coli + 0xc)) + *(float *)(coli + 0x14) * n[2];
        if (d > 0.0f)
          ext_4e09b0(n);
        u32 bouncy = *(u32 *)(*(u8 **)(hit + 8) + 0x3c) & 2;
        if (!bouncy && !(*(u32 *)(self + 0x89) & 0x20)) {
          geom = *(u8 **)(self + 0x44);
          u8 *o = (u8 *)((vcallUU)VT(geom, 0x100))(geom, 0x692b4cu);
          if (o)
            ((vcallUUU)VT(o, 0x68))(o, 0x10, 0);
          geom = *(u8 **)(self + 0x44);
          ((vcallUU)VT(geom, 0xbc))(geom, 1);
          *(u32 *)(self + 0x89) |= 2;
        } else if ((*(u32 *)(self + 0x89) & 0x20) || !bouncy) {
          ext_4b95d0(self, v);
          return;
        }
        ext_443ef0(p, (const float *)(*(u8 **)(self + 0x8d) + 0x28), n, 1.0f);
        float w[3];
        float dn = (n[1] * v[1] + n[0] * v[0]) + n[2] * v[2];
        ext_443ef0(w, v, n, -dn);
        ext_4e0d00(w, 0.0f);
        dn = (n[1] * v[1] + n[0] * v[0]) + n[2] * v[2];
        ext_443ef0(v, v, n, dn * -2.0f);
        ext_43e960(v, w);
        float sp = len3(v);
        if (sp > 1500.0f)
          ext_4e0d00(v, 1500.0f / sp);
        ext_4e0d00(v, bitsf(0x3eb33333u));   // 0.35
        float sp2 = len3(v);
        ext_4e73b0(*(u8 **)(self + 0x6d), p, v, g, 0.0f, th);
        if (bitsf(0x4202eeefu) > sp2) {   // 32.7333
          if (0.0f > rem || !(*(u32 *)(*(u8 **)(hit + 8) + 0x3c) & 0x40040000u))
            *(u32 *)(self + 0x89) |= 2;
        }
        float last = *(float *)(self + 0x85);
        float tn = secs(*(s32 *)(sys() + 0x40));
        u8 play;
        if (tn > last + bitsf(0x3e4ccccdu) || last == 0.0f) {   // 0.2 s
          play = 1;
          snd = 1;
        } else {
          play = snd;
        }
        *(float *)(self + 0x85) = tn;
        if (play) {
          snd = 0;
          float x = (len3(v) - 5.0f) / 20.0f;
          float y = 0.0f > x ? 0.0f : x;
          float vol = 1.0f < y ? 1.0f : y;
          if (!(vol == 0.0f)) {
            u32 kind = 0;
            rm = rmgr();
            u8 *own = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0x61));
            if (own) {
              u8 *o2 = (u8 *)((vcallU0)VT(own, 0x2e8))(own);
              if (o2)
                kind = ((vcallU0)VT(o2, 0x318))(o2);
            }
            u8 *ray = *(u8 **)(*(u8 **)(sys() + 0x1aa3) + 0x1c);
            u32 x2 = ((vcallUP)VT(ray, 0x74))(ray, *(u8 **)(self + 0x8d) + 0x3c);
            u8 *tbl = *(u8 **)(*(u8 **)(sys() + 0x1aa3) + 0x18);
            u8 *mt = (u8 *)((vcallUU)VT(tbl, 0xf8))(tbl, x2);
            u8 *mat = 0;
            if (mt)
              mat = (u8 *)ext_4ba180(self, mt[2]);
            rm = rmgr();
            u8 *o3 = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(*(u8 **)(self + 0x8d) + 0x44));
            if (o3 && ((vcallU0)VT(o3, 0x20))(o3) && *(u32 *)(sys() + 0x1a9f)) {
              u32 set = mat ? *(u32 *)(mat + 0x28) : 0;
              u8 *ss = *(u8 **)(sys() + 0x1a9f);
              u32 s = ((vcallUUU)VT(ss, 0x58))(ss, kind, set);
              if (!s) {
                ss = *(u8 **)(sys() + 0x1a9f);
                u32 n2 = ((vcallUU)VT(ss, 0x5c))(ss, 0x685ffcu);
                ss = *(u8 **)(sys() + 0x1a9f);
                s = ((vcallUUU)VT(ss, 0x58))(ss, kind, n2);
              }
              float id[9];
              ext_4de7a0(id);
              u8 *room = ext_4db3b0(*(u8 **)(hit + 8));
              u32 r = ext_43ec00(room, id, (float *)(*(u8 **)(self + 0x8d) + 0x28), s, 0, 0, 0);
              rm = rmgr();
              u8 *h = (u8 *)((vcallUU)VT(rm, 0x60))(rm, r);
              if (h) {
                *(float *)(h + 0x84) = vol * bitsf(0x3f333333u);   // 0.7
                u8 *sy = sys();
                long double a = ((rndFn)VT(sy, 0x1c0))(sy, 0x692ab4u, 0x223);
                float q = (float)((a - 0.5L) * 40.0L);
                s32 qi = _mm_cvttss_si32(_mm_set_ss(q));
                *(s32 *)(h + 0x60) = (s32)((u32)qi - *(u32 *)(h + 0x64));
                *(s32 *)(h + 0x64) = qi;
              }
            }
          }
        }
      }
      if (prev == now)
        break;
    }
  }
  geom = *(u8 **)(self + 0x44);
  ((vcallVPP)VT(geom, 0x7c))(geom, m, pn);
}
PCREG(4b9940, ballistic);
