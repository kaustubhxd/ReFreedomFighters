// batch1218.cpp - pathfinding tree: doors and gates on a path (CheckLineAgainst*, PostProcessPath).
//
// ZPathfinder3: +0x2d int "doors changed" (rebuild the door list first), +0x36 / +0x3a gate count / array, +0x3e /
// +0x42 additional-door count / array. A door or gate is a 0x34-byte record: four corners (+0, +0xc, +0x18, +0x24)
// forming two triangles (0,1,2) and (2,3,0), and +0x30 a value copied into the path point's int slot.
#include "pf.h"

extern "C" u32 FASTCALL ext_4e2560(const float *start, const float *dir, const float *v0, const float *v1,
                                   const float *v2, float *t, u32 twoSided);   // IntersectTriangleAndLine
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract: dst = a - b
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);       // vaddscalar: dst += v * s (x87)
extern "C" void THISCALL ext_52b9d0(void *self);
extern "C" u8 *THISCALL ext_52a970(void *self, float *a, float *b, float *t);
extern "C" u8 *THISCALL ext_52a850(void *self, float *a, float *b, float *t);
extern "C" void *THISCALL ext_476dc0(void *lst, int n);
extern "C" void ext_41e2c0(void *p);

// Nearest crossing (smallest t in [0, best]) of the segment a -> b with the quads of a list. Returns the quad or NULL;
// *t gets the best parameter (unchanged when the list pointer is NULL).
static inline u8 *crossQuads(u8 *list, int count, float *a, float *b, float *t, float best) {
  if (!list) return 0;
  float d[3];
  ext_43e920(d, b, a);
  u8 *hit = 0;
  u8 *q = list;
  for (int i = 0; i < count; i++, q += 0x34) {
    if ((u8)ext_4e2560(a, d, (float *)q, (float *)(q + 0xc), (float *)(q + 0x18), t, 1) && *t >= 0.0f && best >= *t) {
      best = *t;
      hit = q;
    }
    if ((u8)ext_4e2560(a, d, (float *)(q + 0x18), (float *)(q + 0x24), (float *)q, t, 1) && *t >= 0.0f &&
        best >= *t) {
      best = *t;
      hit = q;
    }
  }
  *t = best;
  return hit;
}

// 0x52a850 ZPathfinder3::CheckLineAgainstAdditionalDoors(float*, float*, float&) [map high; GameCube reference]. thiscall,
// ret 0xc. Best t starts at 10.0, so crossings beyond the segment end (t up to 10) count too.
static u8 *THISCALL checkLineDoors(u8 *self, float *a, float *b, float *t) {
  return crossQuads(*(u8 **)(self + 0x42), *(int *)(self + 0x3e), a, b, t, 10.0f);
}
PCREG(52a850, checkLineDoors);

// 0x52a970 ZPathfinder3::CheckLineAgainstGates(float*, float*, float&) [map high; GameCube reference]. Same over the gates,
// best t starts at 1.0 (within the segment only).
static u8 *THISCALL checkLineGates(u8 *self, float *a, float *b, float *t) {
  return crossQuads(*(u8 **)(self + 0x3a), *(int *)(self + 0x36), a, b, t, 1.0f);
}
PCREG(52a970, checkLineGates);

static inline void freeList(u8 *lst) {
  if (*(void **)(lst + 0xc)) ext_41e2c0(*(void **)(lst + 0xc));
  if (*(void **)(lst + 0x10)) ext_634273(*(void **)(lst + 0x10), 4);
  if (*(void **)(lst + 0x14)) ext_634273(*(void **)(lst + 0x14), 4);
  ext_634273(lst, 0x18);
}

// 0x52b4e0 ZPathfinder3::PostProcessPath(CChkPntLst*) [map high; GameCube reference; zpathfinder3.cpp line 0x24bb].
// thiscall, ret 4. A path whose last segment crosses a gate (a "DynamicsEnabled gate") is dropped (NULL). Otherwise
// every segment, raised 50 units, is tested against the additional doors; for each crossing (t in [0, 1], up to 5 per
// segment) a point is inserted just behind the door (t + 0.0001) with the door's +0x30 value in the point's int slot,
// and the running lengths are rebuilt. Returns the new list (the old one is freed), or the old one when no door was
// crossed.
static u8 *THISCALL postProcessPath(u8 *self, u8 *lst) {
  if (*(int *)(self + 0x2d)) ext_52b9d0(self);
  if (!lst) return 0;
  int n = *(int *)(lst + 8);
  float *pts = *(float **)(lst + 0xc);
  float A[3] = {pts[(n - 2) * 4 + 1], pts[(n - 2) * 4 + 2], pts[(n - 2) * 4 + 3]};
  float B[3] = {pts[(n - 1) * 4 + 1], pts[(n - 1) * 4 + 2], pts[(n - 1) * 4 + 3]};
  float t;
  if (ext_52a970(self, A, B, &t)) {
    pfReport((const char *)0x6a0f54, 0x24bb, (const char *)0x6a11bc);
    freeList(lst);
    return 0;
  }
  int extra = 0;
  for (int i = 0; i < *(int *)(lst + 8) - 1; i++) {
    float *p = (float *)(*(u8 **)(lst + 0xc) + i * 16);
    float P[3] = {p[1], p[2] + 50.0f, p[3]};
    float Q[3] = {p[5], p[6] + 50.0f, p[7]};
    for (int k = 0; k < 5; k++) {
      if (!ext_52a850(self, P, Q, &t)) break;
      if (!(t >= 0.0f) || !(1.0f >= t)) break;
      float d[3];
      ext_43e920(d, Q, P);
      ext_451890(P, d, t + 0.0001f);
      extra++;
    }
  }
  if (!extra) return lst;
  void *mem = ext_41e290(0x18);
  u8 *out = mem ? (u8 *)ext_476dc0(mem, *(int *)(lst + 8) + extra) : 0;
  *(u32 *)(out + 4) = *(u32 *)(lst + 4);
  int o = 0;
  **(u32 **)(out + 0xc) = 0;
  for (int i = 0; i < *(int *)(lst + 8); i++) {
    float *p = (float *)(*(u8 **)(lst + 0xc) + i * 16);
    float W[3] = {p[1], p[2], p[3]};
    float *q = (float *)(*(u8 **)(out + 0xc) + o * 16);
    q[1] = W[0];
    q[2] = W[1];
    q[3] = W[2];
    if (o) {
      float *qs = *(float **)(out + 0xc);
      float len = (float)((long double)ext_4e0870(W, qs + (o - 1) * 4 + 1) + (long double)qs[(o - 1) * 4]);
      qs[o * 4] = len;
    }
    (*(int **)(out + 0x10))[o] = 0;
    o++;
    if (i >= *(int *)(lst + 8) - 1) continue;
    p = (float *)(*(u8 **)(lst + 0xc) + i * 16);
    float Q[3] = {p[5], p[6] + 50.0f, p[7]};
    W[1] = W[1] + 50.0f;
    for (int k = 0; k < 5; k++) {
      u8 *door = ext_52a850(self, W, Q, &t);
      if (!door) break;
      if (!(t >= 0.0f) || !(1.0f >= t)) break;
      float d[3];
      ext_43e920(d, Q, W);
      ext_451890(W, d, t + 0.0001f);
      float *qs = *(float **)(out + 0xc);
      qs[o * 4 + 1] = W[0];
      qs[o * 4 + 2] = W[1];
      qs[o * 4 + 3] = W[2];
      qs = *(float **)(out + 0xc);
      qs[o * 4 + 2] = qs[o * 4 + 2] - 50.0f;
      qs = *(float **)(out + 0xc);
      qs[o * 4] = (float)((long double)ext_4e0870(qs + o * 4 + 1, qs + (o - 1) * 4 + 1) + (long double)qs[(o - 1) * 4]);
      (*(int **)(out + 0x10))[o] = *(int *)(door + 0x30);
      o++;
    }
  }
  *(float *)(out + 4) = (*(float **)(out + 0xc))[(o - 1) * 4];
  freeList(lst);
  return out;
}
PCREG(52b4e0, postProcessPath);
