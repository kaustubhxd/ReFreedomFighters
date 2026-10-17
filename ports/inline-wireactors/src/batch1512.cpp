// batch1512.cpp - recruits thread, batch 1512: CFormationControl::ControlMembers (AI formation steering).
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
#define SYS G(u8 *, 0x70039c)
#define DT (*(float *)(SYS + 0x48))

typedef u64(THISCALL *fStamp)(void *, const char *, u32);
typedef void(THISCALL *fMark)(void *, u32, u32, const char *);
static void prof(u32 slot, u32 line, u32 name) {
  if (!(*(float *)(SYS + 0x9c7) != 0.0f && *(float *)(SYS + 0x9c3) != 0.0f))
    return;
  u8 *s = SYS;
  u64 t = ((fStamp)(*(void ***)s)[0x1c8 / 4])(s, (const char *)0x67a7f8, line);
  u8 *s2 = SYS;
  ((fMark)(*(void ***)s2)[slot / 4])(s2, (u32)t, (u32)(t >> 32), (const char *)name);
}

struct RefIter {
  u32 cur, a, b;
};

extern "C" void THISCALL ext_4de7a0(float *m);                                       // mreset
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);    // dst = a - b
extern "C" void FASTCALL ext_43e960(float *v, const float *b);                       // v -= b (x87)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                  // dst += src
extern "C" void THISCALL ext_4e0d00(float *v, float s);                             // v *= s
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                  // mcpy
extern "C" float FASTCALL ext_44e630(float *dst, const float *src);                 // vnorm, length in ST0
extern "C" void THISCALL ext_4e09b0(float *v);                                       // vneg
extern "C" void FASTCALL ext_4de040(float *m, const float *dir, const float *up);   // createmat
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                      // vmmul

static inline float len3(const float *v) {
  return (float)crt::sqrt((double)(((v[0] * v[0]) + (v[1] * v[1])) + (v[2] * v[2])));
}

// Formation slot offsets (exe table 0x6eea08, 12 x vec3, local to the leader, scaled by 1.25 here):
// (-75,0,150) (75,0,150) (-150,0,0) (150,0,0) (-150,0,150) (0,0,150) (150,0,150) (-150,0,325) (0,0,325)
// (150,0,175) (0,425,0) (0,425,0).
//
// 0x5b6110 CFormationControl::ControlMembers(unsigned* f), thiscall, ret 4.
// Leader tracking: speed = |previous leader position (+0x40) - current| / dt; moved = |current - anchor (+0x4c)|.
// While the leader moves (speed > 0.5 or moved > 100) a 3 s linger timer (+0x8c) is set and a move timer (+0x88)
// counts up; when it reaches 1 s (with the linger timer running) the formation is re-anchored: anchor = leader
// position, orientation (+0x64) = leader matrix, heading (+0x58) = -(normalised horizontal movement); a forced update
// (+0x90, set by ForceFormationUpdate) does the same at once. Order mode = 2 if the leader's flags bit 0, 1 if bit 1,
// else 0, plus 2 while the leader is away from the anchor.
// Each member (skipped while its +0x691 counter is positive): target = anchor + slot offset x 1.25 rotated by the
// heading frame (or the leader's matrix when the heading is zero) when the leader is slow, unrotated otherwise; while
// the leader is away the target is pushed 200 units further along the horizontal direction member -> target. A target
// the member's path finder (slot 0x5d0, then slot 0x220) rejects 3 times in a row moves the member to the next free
// slot. On a re-anchor, members further than 100 from their target, not ordered in the last second, get a queued
// order {target, facing point (0, 0, -100) in the leader frame, distance, mode} (sent by SendUpdates); otherwise
// their order time (+0x11) is reset to -1.
static void THISCALL formControlMembers(u8 *self, u32 *f) {
  (void)self;
  u8 *fb = (u8 *)f;
  prof(0x178, 0x259, 0x6b22a0);
  prof(0x178, 0x259, 0x6b22b4);
  u32 update = fb[0x90];
  fb[0x90] = 0;
  u8 *L = vcall<u8 *>(objTable(), 0x58, f[0]);
  float lp[3] = {0, 0, 0};
  float lm[12];
  ext_4de7a0(lm);
  vcall<void>(L, 0x80, lm, lp);
  float d0[3];
  ext_43e920(d0, lp, (float *)(fb + 0x4c));
  float moved = len3(d0);
  float d1[3];
  ext_43e920(d1, (float *)(fb + 0x40), lp);
  float spd;
  if (DT != 0.0f)
    spd = len3(d1) / DT;
  else
    spd = 0.0f;
  float *prev = (float *)(fb + 0x40);
  prev[0] = lp[0];
  prev[1] = lp[1];
  float away = moved;
  prev[2] = lp[2];
  float *tMove = (float *)(fb + 0x88), *tLinger = (float *)(fb + 0x8c);
  if (spd > 0.5f || moved > 100.0f) {
    *(u32 *)tLinger = 0x40400000u;   // 3.0
    *tMove = DT + *tMove;
  } else {
    float t = *tLinger;
    if (t > 0.0f) {
      *tLinger = t - DT;
    } else {
      *(u32 *)tMove = 0;
    }
    away = 0.0f;
    spd = 0.0f;
  }
  if (*tMove >= 1.0f) {
    *(u32 *)tMove = 0x3f800000u;
    if (*tLinger > 0.0f)
      update = 1;
    else
      *(u32 *)tMove = 0;
  }
  u32 lf = *(u32 *)(L + 0x417);
  u32 mode = (lf & 1) ? 2 : ((lf & 2) ? 1 : 0);
  if (away != 0.0f)
    mode += 2;
  prof(0x17c, 0x260, 0x6b22b4);
  prof(0x178, 0x259, 0x6b22c0);
  if (update) {
    float *anchor = (float *)(fb + 0x4c);
    anchor[0] = lp[0];
    anchor[1] = lp[1];
    anchor[2] = lp[2];
    ext_4de420((float *)(fb + 0x64), lm);
    d1[1] = 0.0f;
    ext_44e630((float *)(fb + 0x58), d1);
    ext_4e09b0((float *)(fb + 0x58));
  } else {
    away = 0.0f;
    spd = 0.0f;
  }
  if (*(void **)(fb + 4)) {
    RefIter it;
    vcall<void>(*(void **)(fb + 4), 0x4c, &it);
    for (u8 *m = vcall<u8 *>(*(void **)(fb + 4), 0x64, &it); m; m = vcall<u8 *>(*(void **)(fb + 4), 0x64, &it)) {
      u8 *A = vcall<u8 *>(objTable(), 0x58, *(u32 *)m);
      float ap[3] = {0, 0, 0};
      float am[12];
      ext_4de7a0(am);
      vcall<void>(A, 0x80, am, ap);
      float T[3];
      const float *off = (const float *)(0x6eea08 + *(s32 *)(m + 4) * 12);
      T[0] = off[0];
      T[1] = off[1];
      T[2] = off[2];
      ext_4e0d00(T, 1.25f);
      if (0.5f > spd) {
        float *h = (float *)(fb + 0x58);
        if (h[0] != 0.0f || h[1] != 0.0f || h[2] != 0.0f) {
          float hm[12];
          ext_4de040(hm, h, 0);
          ext_4419f0(T, hm);
        } else {
          ext_4419f0(T, (float *)(fb + 0x64));
        }
      }
      ext_441940(T, (float *)(fb + 0x4c));
      if (away != 0.0f) {
        float U[3] = {T[0], T[1], T[2]};
        ext_43e960(U, ap);
        float ux = U[0], uz = U[2];
        U[1] = 0.0f;
        if (ux != 0.0f || uz != 0.0f) {
          long double x = U[0], y = U[1], z = U[2];
          long double inv = 1.0L / fsqrt_x87(x * x + y * y + z * z);
          U[0] = (float)(U[0] * inv);
          U[1] = (float)(U[1] * inv);
          U[2] = (float)(U[2] * inv);
          ext_4e0d00(U, 200.0f);
        }
        ext_441940(T, U);
      }
      if (*(s32 *)(A + 0x691) > 0)
        continue;
      if (vcall<void *>(A, 0x5d0)) {
        void *pf = vcall<void *>(A, 0x5d0);
        if (!vcall<u8>(pf, 0x220, T)) {
          s32 tries = *(s32 *)(m + 8);
          *(s32 *)(m + 8) = tries + 1;
          if (tries < 3)
            continue;
          s32 c = *(s32 *)(m + 0xc);
          u32 found = 0;
          *(s32 *)(m + 8) = 0;
          if (c < 12) {
            for (; c < 12; ++c) {
              if (found)
                break;
              if (f[3 + c] == 0) {
                f[3 + *(s32 *)(m + 4)] = 0;
                found = 1;
                f[3 + c] = 1;
                *(s32 *)(m + 4) = c;
              }
            }
          }
          if (c == 12) {
            *(s32 *)(m + 0xc) = 0;
            continue;
          }
          *(s32 *)(m + 0xc) = c;
          if (found)
            continue;
        }
      }
      *(u32 *)(m + 8) = 0;
      float D[3];
      *(u32 *)(m + 0xc) = 0;
      ext_43e920(D, T, ap);
      float dist = len3(D);
      if (!update || 100.0f > dist) {
        *(u32 *)(m + 0x11) = 0xbf800000u;
        continue;
      }
      float t = *(float *)(m + 0x11);
      s32 now = *(s32 *)(SYS + 0x40);
      if (now < _mm_cvttss_si32(_mm_set_ss((t + 1.0f) * 1024.0f)) && t >= 0.0f)
        continue;
      *(float *)(m + 0x11) = (float)now * 0.0009765625f;
      float *q;
      u8 *e = vcall<u8 *>(*(void **)(fb + 8), 0x2c, *(u32 *)m);
      if (e) {
        q = (float *)(e + 4);
      } else {
        q = vcall<float *>(*(void **)(fb + 8), 4, *(u32 *)m);
        if (!q)
          continue;
      }
      q[0] = T[0];
      q[1] = T[1];
      q[2] = T[2];
      q[6] = dist;
      ((u32 *)q)[3] = 0;
      ((u32 *)q)[4] = 0;
      ((u32 *)q)[5] = 0xc2c80000u;   // -100.0
      ext_4419f0(q + 3, (float *)(fb + 0x64));
      ((u32 *)q)[7] = mode;
    }
  }
  prof(0x17c, 0x260, 0x6b22c0);
  prof(0x17c, 0x260, 0x6b22a0);
}
PCREG(5b6110, formControlMembers);
