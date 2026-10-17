// batch406.cpp - per-frame update chain: ZPlayer::UpdatePoolGeoms (slot 0x5ec, called every frame by
// ZPlayer::ClassFrameUpdate between the "UpdatePool" profiler marks).
#include "ff.h"

extern "C" u8 *THISCALL ext_4e64a0(float *cr);  // CCollisionResponse::CCollisionResponse [medium]: both factors 1.0
extern "C" u8 THISCALL ext_4e65e0(float *cr, float massA, float massB);  // response factors from two masses (no name)
extern "C" void THISCALL ext_4e64b0(float *cr, float *vel, float *off, float *pos, float k);  // apply response (no name)
extern "C" void FASTCALL ext_43e8e0(float *out, const float *a, const float *b);  // out = a + b (x87; no name)
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);  // PSVECSubtract: out = a - b
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *b, float s);  // vaddscalar (batch 402)
extern "C" float FASTCALL ext_44c840(float *v);                   // vnorm in place, returns the length [medium]
extern "C" float FASTCALL ext_44e630(float *out, const float *v);  // vnorm into out [high]
extern "C" void FASTCALL ext_4e0d00(float *v, float s);             // vscalar [low]
extern "C" void FASTCALL ext_441940(float *a, const float *b);      // PSVECAdd, a += b [medium]
extern "C" u8 *THISCALL ext_4e1b60(u8 *coli);                       // COLI::COLI [high]
extern "C" u8 FASTCALL ext_4856f0(const float *v);                  // all three lanes == 0 (no name)

static inline void stamp(u8 *at) {  // the exe's tick assignment, with its self-assignment check
  u8 *now = G(u8 *, 0x70039c) + 0x40;
  if (at != now)
    *(u32 *)at = *(u32 *)now;
}
static inline void cpy3(void *d, const void *s) {
  ((u32 *)d)[0] = ((const u32 *)s)[0];
  ((u32 *)d)[1] = ((const u32 *)s)[1];
  ((u32 *)d)[2] = ((const u32 *)s)[2];
}

// ---------------------------------------------------------------- 0x485110 ZPlayer::UpdatePoolGeoms() [high]
// thiscall. Pushes the movable "pool" objects (actor pool at [0x7003b8]+0x4b4, count +0x4b0) out of the player's way.
// Records (rec): +4 object, +8 position, +0x14 matrix, +0x38 radius, +0x3c mass, +0x4c active byte, +0x4d tick stamp.
static void THISCALL playerUpdatePoolGeoms(u8 *self) {
  float cr[2];
  ext_4e64a0(cr);
  float cmat[9], cpos[3], vel[3], pos[3];
  vcall<void>(self, 0x59c, cmat, cpos);  // GetCenterMatPos
  vcall<void>(self, 0x5c4, vel);
  ext_443ef0(pos, cpos, vel, *(float *)(G(u8 *, 0x70039c) + 0x48) * 60.0f);  // [0x67885c]
  u8 *g8 = *(u8 **)(self + 8);
  *(u32 *)(self + 0x4f1) = 0;
  float mid = *(float *)(g8 + 0x34) + pos[1];
  float hi = *(float *)(g8 + 0x44) + mid;
  float lo = mid - *(float *)(g8 + 0x44);
  u8 **it = (u8 **)(G(u8 *, 0x7003b8) + 0x4b4);
  while (it != (u8 **)(G(u8 *, 0x7003b8) + (*(s32 *)(G(u8 *, 0x7003b8) + 0x4b0) + 0x12d) * 4)) {
    u8 *rec = *it;
    u8 *g = vcall<u8 *>(*(u8 **)(rec + 4), 0x20);
    float *rpos = (float *)(rec + 8);
    if (*(u32 *)(*(u8 **)(g + 8) + 0x3c) & 0x800) {
      vcall<void>(g, 0x7c, (float *)(rec + 0x14), rpos);  // SetRootTM
      goto next;
    }
    if (!rec[0x4c] || !self[0x5ff] || (*(u8 *)(*(u8 **)(*(u8 **)(rec + 4) + 0x1c) + 4) & 2)) {
      vcall<void>(g, 0x7c, (float *)(rec + 0x14), rpos);
      goto next;
    }
    {
      float rmat[9], rootPos[3], np[3];
      vcall<void>(g, 0x80, rmat, rootPos);  // GetRootTM
      ext_43e920(np, rpos, pos);
      np[1] = 0.0f;
      float r = *(float *)(rec + 0x38) + 40.0f;  // [0x684cf0]
      float d2 = np[0] * np[0] + 0.0f;
      d2 = d2 + np[2] * np[2];
      float ty, h;
      if (!(r * r > d2))
        goto away;
      ty = *(float *)(*(u8 **)(g + 8) + 0x34) + rootPos[1];
      h = *(float *)(*(u8 **)(g + 8) + 0x44);
      if (!(hi > ty - h) || !(h + ty > lo))
        goto away;
      if (*(float *)(rec + 0x3c) >= 10000.0f) {  // [0x67ff1c]: too heavy to push, remembered as "special"
        s32 n = *(s32 *)(self + 0x4f1);
        if (n < 4) {
          *(u8 **)(self + 0x4e1 + 4 * n) = rec;
          *(s32 *)(self + 0x4f1) = n + 1;
        } else {
          u8 *log = vcall<u8 *>(G(u8 *, 0x700390), 0x20, (const char *)0x68bcbc, 0x5bcu);  // zplayer.cpp, line 1468
          typedef void (*cdeclLog)(void *, const char *);
          (*(cdeclLog *)(*(u8 **)log + 0x30))(log, (const char *)0x68c040);  // "Player: Special movepool full, ..."
        }
        cpy3(np, rpos);
      } else {
        float off[3], n[3];
        ext_43e920(np, rpos, cpos);
        np[1] = 0.0f;
        ext_43e920(off, rpos, rootPos);
        ext_4e65e0(cr, *(float *)(self + 0x4dd), *(float *)(rec + 0x3c));
        ext_4e64b0(cr, vel, off, np, 0.0f);
        ext_43e8e0(np, rootPos, off);
        ext_43e920(n, np, cpos);
        n[1] = 0.0f;
        float rr = *(float *)(rec + 0x38) + 20.0f;  // [0x67da20]
        float len = ext_44c840(n);
        if (rr > len) {
          if (!ext_4856f0(n)) {
            ext_443ef0(np, cpos, n, rr);
            np[1] = *(float *)(rec + 0xc);
          } else {
            cpy3(np, rootPos);
          }
        }
        u8 coli[0x70];
        ext_4e1b60(coli);
        float from[3], to[3];
        from[0] = rpos[0];
        from[1] = *(float *)(rec + 0xc) + 1.0f;  // [0x678858]
        from[2] = *(float *)(rec + 0x10);
        to[0] = np[0];
        to[1] = np[1] + 1.0f;
        to[2] = np[2];
        float *dir = (float *)(coli + 0xc);
        ext_43e920(dir, to, from);
        if (!ext_4856f0(dir)) {
          cpy3(coli, from);
          float w[3];
          ext_44e630(w, dir);
          ext_4e0d00(w, *(float *)(rec + 0x38));
          ext_441940(dir, w);
          u8 *world = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
          if (vcall<u8>(world, 0x2e0, coli, 0u, 0x20u, 0xffffffffu, 1u, 0u))
            cpy3(np, rootPos);
          cpy3(coli, to);
          *(u32 *)(coli + 0x34) = 0x3f800000u;
          *(u32 *)(coli + 0xc) = 0;
          *(u32 *)(coli + 0x10) = 0xc0000000u;  // -2.0: straight down
          *(u32 *)(coli + 0x14) = 0;
          world = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
          if (!vcall<u8>(world, 0x2e0, coli, 0u, 0x20u, 0xffffffffu, 1u, 0u))
            cpy3(np, rootPos);
        }
      }
      stamp(rec + 0x4d);
      vcall<void>(g, 0x7c, (float *)(rec + 0x14), np);
      goto next;
    }
  away:
    if (*(s32 *)(G(u8 *, 0x70039c) + 0x40) > *(s32 *)(rec + 0x4d)) {
      stamp(rec + 0x4d);
      vcall<void>(g, 0x7c, (float *)(rec + 0x14), rpos);
    }
  next:
    it++;
  }
}
PCREG(485110, playerUpdatePoolGeoms);
