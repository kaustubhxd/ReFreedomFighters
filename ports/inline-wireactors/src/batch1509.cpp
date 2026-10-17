// batch1509.cpp - recruits thread, batch 1509: ZFFHERO::UpdateFollowers, the per-frame follow logic (formation
// ring around the hero, slot blocking, follower push, follow orders).
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
#define SYS G(u8 *, 0x70039c)
#define DT (*(float *)(SYS + 0x48))

extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // dst = a - b
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);  // dst = a + b (x87)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                // dst += src
extern "C" void THISCALL ext_4e0d00(float *v, float s);                           // v *= s
extern "C" void THISCALL ext_4de7a0(float *m);                                     // mreset
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                     // v = v * m^T (x87)
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);              // squared distance, ST0
extern "C" u8 THISCALL ext_5941d0(u8 *hero, u8 *a, const float *dir, const float *fpos, const float *unused,
                                   const float *hpos, const float *m, float radius);  // ZFFHERO::PushFollower

// Profiling markers on the system object: slot 0x1c8 (file, line) -> 64-bit time, slot 0x178 / 0x17c (time, name)
// begin / end. Only when both [sys+0x9c7] and [sys+0x9c3] are non-zero (NaN counts as non-zero).
typedef u64(THISCALL *fStamp)(void *, const char *, u32);
typedef void(THISCALL *fMark)(void *, u32, u32, const char *);
static inline bool profOn() {
  return *(float *)(SYS + 0x9c7) != 0.0f && *(float *)(SYS + 0x9c3) != 0.0f;
}
static void prof(u32 slot, u32 line, u32 name) {
  if (!profOn())
    return;
  u8 *s = SYS;
  u64 t = ((fStamp)(*(void ***)s)[0x1c8 / 4])(s, (const char *)0x67a7f8, line);
  u8 *s2 = SYS;
  ((fMark)(*(void ***)s2)[slot / 4])(s2, (u32)t, (u32)(t >> 32), (const char *)name);
}

static inline bool dbgDraw(u8 *self) { return *(float *)(self + 0xee8) != 0.0f; }

// 0x595800 ZFFHERO::UpdateFollowers(), thiscall, plain ret. Nothing happens when the frame time [sys+0x48] is
// below 2^-13. Per frame:
// 1. Follow distance +0xed7 eases toward the target +0xedb (x0.7 when crouched, flag 0x400 at +0x417) at half the
//    target per second, and is pulled back when more than 1 above it.
// 2. Hero velocity +0xebf is smoothed: v = v * (1 - 3 dt) + (pos - lastPos) / dt * 3 dt; lastPos +0xeb3 = pos.
// 3. Formation ring: n = max(followers, 6) slots on a circle of radius R = (+0xed3 + 100 - |0.3 v_xz|) (x0.7
//    crouched) around (pos + (0, 50, 0) + 0.3 v_xz), slot k at angle 2 pi k / n, scaled by its weight (+0x11).
//    Slot "front" index = the hero's heading angle (acos of matrix[0], mirrored by the sign of matrix[6]) * n / 2 pi.
//    One slot per frame (+0xedf, round robin) is checked against the path finder (+0xecb slot 0x220) and the
//    level's blocking boxes (game +0x420, count +0x41c; objects not of class 0x100bc2, box half-size at geom
//    +0x40); a blocked slot shrinks (weight x0.8 while above 0.1), a free one grows back to 1 at 0.2 per second.
//    Debug boxes when +0xee8 is set (draw handle in slot +0).
// 4. Debug circle of the follow distance (+0xee8 set), with 10 segments whose handles live in the exe's statics
//    0x7142a4[10] (index 0x7142a0).
// 5. Each follower: gets its position (actor slot 0x57c into the record +0x20), may be pushed out of the hero's way
//    (PushFollower, at most once a second, time in the record +0x14), and is assigned slot front, front-1,
//    front+1, front-2, ... (record +0x2c).
// 6. Each follower whose slot moved more than 0.3 x +0xed3 since its last order, or whose order is older than 1 s,
//    or (when the hero is not sprinting, flag 2) whose mode is 2, gets the follow event (+0x7e8) with
//    {mode, far, slot position}: mode 1 walk, 2 run (sprinting hero or the follower further than +0xed7 away),
//    0 when it is close to its slot and the hero is slow (|v|^2 < 10000); 90000 / 160000 limits (crouched / not).
//    The record keeps the target (+4), mode (+0x18) and time (+0x10). The crouch state (record +0x1c) is synced with
//    event +0x7ea when +0xee3 is set.
static void THISCALL heroUpdateFollowers(u8 *self) {
  if (0.0001220703125f > DT)   // 0x679540
    return;
  prof(0x178, 0x259, 0x6acaa8);
  u32 fl = *(u32 *)(self + 0x417);
  float tgt = *(float *)(self + 0xedb);
  if (fl & 0x400)
    tgt = tgt * 0.7f;   // 0x67c1a4
  float *fd = (float *)(self + 0xed7);
  if (tgt > *fd)
    *fd = (tgt * 0.5f) * DT + *fd;
  if (*fd > tgt + 1.0f)
    *fd = *fd - (tgt * 0.5f) * DT;

  float P[3], M[9];
  vcall<void>(self, 0x80, M, P);
  float V[3];
  float *last = (float *)(self + 0xeb3);
  ext_43e920(V, P, last);
  ext_4e0d00(V, 1.0f / DT);
  ext_4e0d00(V, DT * 3.0f);
  float *hv = (float *)(self + 0xebf);
  ext_4e0d00(hv, 1.0f - DT * 3.0f);
  ext_441940(hv, V);
  last[0] = P[0];
  last[1] = P[1];
  last[2] = P[2];
  float W[3];
  float wx = hv[0] * 0.3f;   // 0x67c198
  W[1] = 0;
  float wz = hv[2] * 0.3f;
  W[0] = wx;
  W[2] = wz;
  float spd = (float)crt::sqrt((double)(((wx * wx) + 0.0f) + (wz * wz)));
  P[1] = P[1] + 50.0f;
  float a, z;
  float m0 = M[0];
  if (m0 > 1.0f) {
    a = 0.0f;
  } else if (-1.0f > m0) {
    a = 3.14159274f;
  } else {
    a = (float)crt::acos((double)m0);
  }
  z = 0.0f;
  if (z > M[6])
    a = 6.28318548f - a;
  s32 n = *(s32 *)(self + 0xa16);
  if (n < 6)
    n = 6;
  s32 i0 = _mm_cvttss_si32(_mm_set_ss((((float)n * a) / 6.28318548f) + 0.5f));
  s32 front = (i0 < n) ? i0 : 0;
  float Xe0[12];
  ext_4de7a0(Xe0);
  float box[3];
  ((u32 *)box)[0] = 0x41200000u;   // 10.0
  ((u32 *)box)[1] = 0x41200000u;
  ((u32 *)box)[2] = 0x41200000u;
  float R = (*(float *)(self + 0xed3) + 100.0f) - spd;
  if (fl & 0x400)
    R = R * 0.7f;

  for (s32 k = 0; k < n; ++k) {
    u8 *slot = self + 0xd4e + k * 0x15;
    float *w = (float *)(slot + 0x11);
    float ang = ((float)k + (float)k) * 3.14159274f / (float)n;
    double r = (double)(*w * R);
    float Q[3];
    float qx = (float)(crt::cos((double)ang) * r);
    Q[1] = 0;
    Q[0] = qx;
    Q[2] = (float)(crt::sin((double)ang) * r);
    ext_441940(Q, P);
    ext_441940(Q, W);
    u8 ok = 1;
    bool blocked = false;
    void *pf = *(void **)(self + 0xecb);
    if (pf && k == *(s32 *)(self + 0xedf)) {
      if (!vcall<u8>(pf, 0x220, Q))
        blocked = true;
    }
    if (!blocked && k == *(s32 *)(self + 0xedf)) {
      u8 *g = G(u8 *, 0x7003b8);
      u8 **p = (u8 **)(g + 0x420);
      while ((u8 *)p != g + (*(u32 *)(g + 0x41c) + 0x108) * 4) {
        u8 *o = *p;
        if (o) {
          if (vcall<u8>(o, 0x1e0, 0x100bc2u)) {
            g = G(u8 *, 0x7003b8);
            ++p;
            continue;
          }
          float t[3];
          ext_43e920(t, Q, (float *)(*(u8 **)(o + 8) + 0x24));
          ext_441a60(t, *(float **)(o + 8));
          float *bx = (float *)(*(u8 **)(o + 8) + 0x40);
          if ((double)bx[0] > __builtin_fabs((double)t[0]) && (double)bx[1] > __builtin_fabs((double)t[1]) &&
              (double)bx[2] > __builtin_fabs((double)t[2])) {
            blocked = true;
            break;
          }
          g = G(u8 *, 0x7003b8);
        }
        ++p;
      }
    }
    if (blocked) {
      ok = 0;
      if (*w > 0.1f)   // 0x67a284
        *w = *w * 0.8f;
    } else if (1.0f > *w) {
      *w = DT * 0.2f + *w;
    }
    void **hnd = (void **)slot;
    if (dbgDraw(self)) {
      void *coll = *(void **)((u8 *)objTable() + 0xadc);
      if (*hnd) {
        u32 color = ok ? (k == front ? 0xffffffu : 0xff00u) : 0xff0000u;
        vcall<void>(coll, 0x23c, *hnd, Xe0, Q, box, color, 0u);
      } else {
        *hnd = vcall<void *>(coll, 0x238, Xe0, Q, box, 0xff0000u, 0u);
      }
    } else if (*hnd) {
      vcall<void>(*(void **)((u8 *)objTable() + 0xadc), 0x240, *hnd);
      *hnd = 0;
    }
    __builtin_memcpy(slot + 4, Q, 12);
    slot[0x10] = ok;
  }
  if (++*(s32 *)(self + 0xedf) >= n)
    *(s32 *)(self + 0xedf) = 0;

  if (dbgDraw(self)) {
    float A[3];
    A[0] = *fd;
    ((u32 *)A)[1] = 0;
    ((u32 *)A)[2] = 0;
    ext_441940(A, P);
    for (s32 i = 1; i <= 10; ++i) {
      double ang = (double)(((float)i + (float)i) * 3.14159274f / 10.0f);
      float cx = (float)(crt::cos(ang) * (double)*fd);
      float B[3];
      ((u32 *)B)[1] = 0;
      B[0] = cx;
      B[2] = (float)(crt::sin(ang) * (double)*fd);
      ext_441940(B, P);
      s32 j = G(s32, 0x7142a0);
      void *coll = *(void **)((u8 *)objTable() + 0xadc);
      void **h = (void **)(0x7142a4 + j * 4);
      if (!*h)
        *h = vcall<void *>(coll, 0x218, A, B, 0xff0000u);
      else
        vcall<void>(coll, 0x21c, *h, A, B, 0xff0000u);
      G(s32, 0x7142a0) = (G(s32, 0x7142a0) + 1) % 10;
      A[0] = B[0];
      A[1] = B[1];
      A[2] = B[2];
    }
  }
  prof(0x178, 0x259, 0x6acab0);

  s32 alt = 0;
  float X3c[3];
  ext_43e8e0(X3c, P, W);
  for (u8 *rec = self + 0xa1a; rec != self + 0xa1a + *(u32 *)(self + 0xa16) * 0x30; rec += 0x30) {
    u8 *ac = *(u8 **)rec;
    float D[3];
    vcall<void>(ac, 0x57c, D, (float *)(rec + 0x20));
    s32 t = _mm_cvttss_si32(_mm_set_ss((*(float *)(rec + 0x14) + 1.0f) * 1024.0f));
    if (t < *(s32 *)(SYS + 0x40)) {
      if (ext_5941d0(self, *(u8 **)rec, D, (float *)(rec + 0x20), X3c, P, M, spd))
        *(float *)(rec + 0x14) = (float)*(s32 *)(SYS + 0x40) * 0.0009765625f;
    }
    s32 e = front + alt;
    if (e < 0)
      e += n;
    else if (e >= n)
      e -= n;
    *(s32 *)(rec + 0x2c) = e;
    alt = (alt < 0) ? -alt : -1 - alt;
  }
  prof(0x17c, 0x260, 0x6acab0);
  prof(0x178, 0x259, 0x6acab8);

  float hx = hv[0], hy = hv[1], hz = hv[2];
  float v2 = ((hx * hx) + (hy * hy)) + (hz * hz);
  u32 fl2 = *(u32 *)(self + 0x417);
  u8 sprint = (u8)((fl2 >> 1) & 1);
  float lim = (fl2 & 0x400) ? 90000.0f : 160000.0f;
  float ed3 = *(float *)(self + 0xed3);
  float near2 = (ed3 * 0.09f) * ed3;   // 0x6ad1f4
  for (u8 *rec = self + 0xa1a; rec != self + 0xa1a + *(u32 *)(self + 0xa16) * 0x30; rec += 0x30) {
    float *sq = (float *)(self + 0xd52 + *(s32 *)(rec + 0x2c) * 0x15);
    float d2 = ext_4e0830((float *)(rec + 4), sq);
    s32 tt = _mm_cvttss_si32(_mm_set_ss(*(float *)(rec + 0x10) * 1024.0f));
    float age = (float)(*(s32 *)(SYS + 0x40) - tt) * 0.0009765625f;
    if (!(d2 > near2) && !(age > 1.0f) && !(*(s32 *)(rec + 0x18) == 2 && !sprint))
      continue;
    float T[3] = {sq[0], sq[1], sq[2]};
    float fdv = *fd;
    float dd = ext_4e0830((float *)(rec + 0x20), P);
    u32 far = dd > fdv * fdv;
    struct {
      u32 mode, far;
      float tgt[3];
    } ev;
    ev.tgt[0] = T[0];
    ev.tgt[1] = T[1];
    ev.far = far;
    ev.tgt[2] = T[2];
    ev.mode = (sprint || far) ? 2 : 1;
    if (lim > d2 / (age * age)) {
      float d3 = ext_4e0830((float *)(rec + 0x20), T);
      if (lim > d3)
        ev.mode = !(10000.0f > v2);   // 0x67ff1c
    }
    vcall<void>(*(void **)rec, 0x128, (u32) * (u16 *)(self + 0x7e8), &ev, 0u);
    ((float *)(rec + 4))[0] = T[0];
    ((float *)(rec + 4))[1] = T[1];
    ((float *)(rec + 4))[2] = T[2];
    *(u32 *)(rec + 0x18) = ev.mode;
    *(float *)(rec + 0x10) = (float)*(s32 *)(SYS + 0x40) * 0.0009765625f;
    float c = *(float *)(rec + 0x1c);
    u32 crouch;
    if (c != 0.0f && !(*(u32 *)(self + 0x417) & 0x400)) {
      *(u32 *)(rec + 0x1c) = 0;
      crouch = 0;
    } else if (c == 0.0f && (*(u32 *)(self + 0x417) & 0x400)) {
      *(u32 *)(rec + 0x1c) = 0x3f800000u;
      crouch = 1;
    } else {
      continue;
    }
    if (self[0xee3])
      vcall<void>(*(void **)rec, 0x128, (u32) * (u16 *)(self + 0x7ea), &crouch, 0u);
  }
  prof(0x17c, 0x260, 0x6acab8);
  prof(0x17c, 0x260, 0x6acaa8);
}
PCREG(595800, heroUpdateFollowers);
