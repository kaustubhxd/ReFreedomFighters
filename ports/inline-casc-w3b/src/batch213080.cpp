#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);

extern "C" u32 THISCALL ext_5d7e00(void *self);
extern "C" u32 THISCALL ext_5d7bc0(void *self);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u16 rd16u(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x5d76f0: thiscall() with no defined return value: timed state step of an animated actor. Idle (this[0x1cc] == 0): once the clock ([[0x70039c]+0x40]) passes this[0x1c8] it
// runs 0x5d7e00(this). Otherwise cond = X slot 0x38(0x6b5c9c, 0) or X slot 0x38(0x6b5cb4, 0) (X = [[0x70039c]+0x1907], low bytes). With this[0x1c3] set, state this[0x156] < 2: only state 1 with cond
// calls Q slot 0x12c(P slot 0x30(1), word this[0x142], T slot 0x4c(Q)) (Q = this[0x44], P = this[0x14e], T = [[0x70039c]+0x9b]); state 2 with this[0x1e6] runs 0x5d7bc0(this) once the clock passes
// this[0x1c8] and clears this[0x1e6]; other states with cond load this[0x156] = P slot 0x14() and call Q slot 0x128(word 0x142, 0, 0). With this[0x1c3] clear: cond does the same reload and
// Q slot 0x128 call, then (this[0x1cc] set, this[0x13c] < this[0x48]) the step table (12 byte records from this+0x4c: time, a, b) fires its next record when (clock - this[0x1c4]) scaled by
// [0x6785e4] and [0x685270] exceeds the record time: Q slot 0x130(this[0x1d1], word this[0x14a], &(a, b)) (when this[0x1d1] is nonzero) and this[0x13c] is incremented.
extern "C" void THISCALL fn_5d76f0(u8 *self) {
  u8 *g = G(u8 *, 0x70039c);
  if (self[0x1cc] == 0) {
    if ((s32)rd32u(g + 0x40) <= (s32)rd32u(self + 0x1c8)) return;
    ext_5d7e00(self);
    return;
  }
  bool cond;
  {
    void *X = (void *)rd32u(g + 0x1907);
    if ((u8)(*(V2 *)(vt(X) + 0x38))(X, 0x6b5c9c, 0)) {
      cond = true;
    } else {
      X = (void *)rd32u(G(u8 *, 0x70039c) + 0x1907);
      cond = (u8)(*(V2 *)(vt(X) + 0x38))(X, 0x6b5cb4, 0) != 0;
    }
  }
  if (self[0x1c3] != 0) {
    s32 st = (s32)rd32u(self + 0x156);
    if (st < 2) {
      if (st != 1) return;
      if (!cond) return;
      void *P = (void *)rd32u(self + 0x14e);
      u32 r = (*(V1 *)(vt(P) + 0x30))(P, 1);
      u8 *g2 = G(u8 *, 0x70039c);
      void *Q = (void *)rd32u(self + 0x44);
      u8 *evt = vt(Q);
      void *T = (void *)rd32u(g2 + 0x9b);
      u32 n = (*(V1 *)(vt(T) + 0x4c))(T, (u32)Q);
      Q = (void *)rd32u(self + 0x44);
      (*(V3 *)(evt + 0x12c))(Q, r, rd16u(self + 0x142), n);
      return;
    }
    if (st == 2 && self[0x1e6] != 0) {
      if ((s32)rd32u(G(u8 *, 0x70039c) + 0x40) <= (s32)rd32u(self + 0x1c8)) return;
      ext_5d7bc0(self);
      self[0x1e6] = 0;
      return;
    }
    if (!cond) return;
    void *P = (void *)rd32u(self + 0x14e);
    wr32u(self + 0x156, (*(V0 *)(vt(P) + 0x14))(P));
    void *Q = (void *)rd32u(self + 0x44);
    (*(V3 *)(vt(Q) + 0x128))(Q, rd16u(self + 0x142), 0, 0);
    return;
  }
  if (cond) {
    void *P = (void *)rd32u(self + 0x14e);
    wr32u(self + 0x156, (*(V0 *)(vt(P) + 0x14))(P));
    void *Q = (void *)rd32u(self + 0x44);
    (*(V3 *)(vt(Q) + 0x128))(Q, rd16u(self + 0x142), 0, 0);
  }
  if (self[0x1cc] == 0) return;
  s32 idx = (s32)rd32u(self + 0x13c);
  if (idx >= (s32)rd32u(self + 0x48)) return;
  u32 off = (u32)idx * 3;
  float t = (float)(s32)(rd32u(G(u8 *, 0x70039c) + 0x40) - rd32u(self + 0x1c4));
  t = t * G(float, 0x6785e4);
  t = t * G(float, 0x685270);
  s32 e = _mm_cvttss_si32(_mm_set_ss(t));
  if (e <= (s32)rd32u(self + off * 4 + 0x4c)) return;
  u32 pair[2];
  pair[0] = rd32u(self + off * 4 + 0x50);
  u32 edi = rd32u(self + 0x1d1);
  pair[1] = rd32u(self + off * 4 + 0x54);
  if (edi) {
    void *Q = (void *)rd32u(self + 0x44);
    (*(V3 *)(vt(Q) + 0x130))(Q, edi, rd16u(self + 0x14a), (u32)pair);
  }
  wr32u(self + 0x13c, rd32u(self + 0x13c) + 1);
}
PCREG(5d76f0, fn_5d76f0);
