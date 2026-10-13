// batch8815.cpp - hit-reaction thread, batch 8815: the ragdoll limb capsule against a level triangle 0x544330
// (CollideSolidCappedCylinderAndTriangle) and its segment-segment distance 0x5453c0 (DistLineLineVar).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);                     // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *b, float s);           // vaddscalar out = a + b * s (x87)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                             // vscalar v *= s
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);                          // vscalar3 out = a * s
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);                     // vcross d = a x b
extern "C" float THISCALL ext_44c840(float *v);                                                     // vnorm (in place, returns the length)
extern "C" u8 FASTCALL ext_547860(const float *m, const float *b, float *out);                     // 3x3 Cramer solver
extern "C" void THISCALL ext_547430(float *v);                                                      // random unit vector (engine random)
extern "C" u8 FASTCALL ext_5457f0(const float *pt, const float *l0, const float *l1, float *t, const float *maxD, float *dist,
                                   float *dir);                                                     // point to segment (batch1027)
extern "C" u8 FASTCALL ext_545690(const float *pt, const float *l0, const float *l1, float *t, const float *maxD, float *dist,
                                   float *dir);                                                     // DistPointLineVar2 (batch857)
extern "C" u8 FASTCALL ext_5453c0(const float *p0, const float *p1, const float *q0, const float *q1, float *tP, float *sQ,
                                   const float *maxD, float *dist, float *dir);                     // DistLineLineVar (below)

// The xorps with the sign mask (0x67af40) on the finished value; the volatile keeps clang from moving the negation into an operand
// (which would change the sign of a NaN result).
static inline float negx(float x) {
  volatile float t = x;
  return bitsf(fbits(t) ^ 0x80000000u);
}

// 0x5453c0 DistLineLineVar(p0, p1, q0, q1, float& tP, float& sQ, float& maxD, float& dist, float* dir) , fastcall: ECX = p0,
// EDX = p1, stack q0, q1, tP, sQ, maxD, dist, dir; ret 0x1c; returns al. r2 = maxD^2; v1 = p0 - q0, v2 = p1 - p0, v3 = q0 - q1 (exe
// subtract). d21 = v2.v1, d32 = v3.v2, d22 = v2.v2, d33 = v3.v3, den = d33 d22 - d32^2; |den| (double) < 1e-6 (double 0x67fad0) -> false.
// d31 = v3.v1; sQ = (d32 d21 - d31 d22) / den (stored); |d22| < 1e-6 -> false. tP = -((sQ d32 + d21) / d22) (stored); tP < 0 or
// tP > 1 -> false. sQ (re-read) < 0: sQ = 0, tail call of the point-segment test 0x5457f0 on q0 against p0..p1 (writes tP, dist, dir);
// sQ > 1: sQ = 1, the same on q1. Otherwise X1 = p0 + v2 tP, X2 = q0 + v3 (-sQ) (x87 vaddscalar), dir = X1 - X2; |dir|^2 > r2 ->
// false; dist = (float) sqrt(|dir|^2); dist > 1e-6 (0x681370): dir *= 1 / dist, else dir = random unit vector (0x547430); true.
static u8 FASTCALL distLineLineVar(const float *p0, const float *p1, const float *q0, const float *q1, float *tP, float *sQ,
                                   const float *maxD, float *dist, float *dir) {
  float md = *maxD;
  float r2 = md * md;
  float v1[3], v2[3], v3[3], X1[3], X2[3];
  ext_43e920(v1, p0, q0);
  ext_43e920(v2, p1, p0);
  ext_43e920(v3, q0, q1);
  float d21 = v2[0] * v1[0] + v2[1] * v1[1];
  d21 = d21 + v2[2] * v1[2];
  float d32 = v3[0] * v2[0] + v3[1] * v2[1];
  d32 = d32 + v3[2] * v2[2];
  float d22 = v2[0] * v2[0] + v2[1] * v2[1];
  d22 = d22 + v2[2] * v2[2];
  float d33 = v3[0] * v3[0] + v3[1] * v3[1];
  d33 = d33 + v3[2] * v3[2];
  float den = d33 * d22 - d32 * d32;
  if (G(double, 0x67fad0) > __builtin_fabs((double)den)) return 0;
  float d31 = v3[0] * v1[0] + v3[1] * v1[1];
  d31 = d31 + v3[2] * v1[2];
  float s = (d32 * d21 - d31 * d22) / den;
  *sQ = s;
  if (G(double, 0x67fad0) > __builtin_fabs((double)d22)) return 0;
  float t = negx((s * d32 + d21) / d22);
  *tP = t;
  if (0.0f > t) return 0;
  if (t > 1.0f) return 0;
  float sv = *sQ;
  if (0.0f > sv) {
    *sQ = 0.0f;
    return ext_5457f0(q0, p0, p1, tP, maxD, dist, dir);
  }
  if (sv > 1.0f) {
    *sQ = 1.0f;
    return ext_5457f0(q1, p0, p1, tP, maxD, dist, dir);
  }
  ext_443ef0(X1, p0, v2, t);
  ext_443ef0(X2, q0, v3, negx(*sQ));
  ext_43e920(dir, X1, X2);
  float l2 = dir[0] * dir[0] + dir[1] * dir[1];
  l2 = l2 + dir[2] * dir[2];
  if (l2 > r2) return 0;
  float d = (float)crt::sqrt((double)l2);   // libm_sse2_sqrt_precise 0x634d7c (correctly rounded)
  *dist = d;
  if (d > G(float, 0x681370)) {
    ext_4e0d00(dir, 1.0f / d);
    return 1;
  }
  ext_547430(dir);
  return 1;
}
PCREG(5453c0, distLineLineVar);

// One edge plane of 0x544330: the plane perp.x = perp.pt + r clips the axis parameter range [tmin, tmax]. Both ends outside -> reject;
// one end outside and |eb - ea| (double) > 1e-4 (double 0x6a3138): x = -((ea - (ev + r)) / (eb - ea)) raises tmin (a outside) or
// lowers tmax (b outside). Returns true when the capsule is rejected (both outside, or tmin > tmax afterwards).
static inline bool clipEdge(const float *p, const float *pt, const float *a, const float *b, float r, float &tmin, float &tmax) {
  float ea = p[0] * a[0] + p[1] * a[1];
  ea = ea + p[2] * a[2];
  float eb = p[0] * b[0] + p[1] * b[1];
  eb = eb + p[2] * b[2];
  float ev = pt[1] * p[1] + pt[0] * p[0];
  ev = ev + pt[2] * p[2];
  float h = ev + r;
  float xa = ea - h;
  float xb = eb - h;
  bool ao = xa > 0.0f, bo = xb > 0.0f;
  if (ao && bo) return true;
  if (bo != ao) {
    float d = eb - ea;
    if (__builtin_fabs((double)d) > G(double, 0x6a3138)) {
      float x = negx(xa / d);
      if (ao) {
        if (!(tmin > x)) tmin = x;
      } else {
        if (!(x > tmax)) tmax = x;
      }
    }
  }
  return tmin > tmax;
}

// 0x544330 CollideSolidCappedCylinderAndTriangle(const float* a, const float* b, float r, SSauColi* out, const SFastBoxColiTri* tri)
// , fastcall: ECX = a, EDX = b, stack r, out, tri; ret 0xc; returns al. Triangle record: +4 normal n, +0x34 v0, +0x40 v1,
// +0x4c v2, +0x58 / +0x64 / +0x70 edge perps (through v1 / v0 / v0). out: +0 n, +0xc axis parameter c, +0x10 depth.
// 1. Slab |x.n - v0.n| <= r clips [0, 1] (both ends above or both below -> false; crossings clipped when |db - da| > 1e-4).
// 2. The edge planes +0x64 (v0), +0x70 (v0), +0x58 (v1): see clipEdge.
// 3. Cramer on rows (b - a, v1 - v0, v2 - v0) with rhs a - v0: u >= 0, u < 1, v >= 0, 0 <= u + v < 1, 0 <= -x <= 1 -> n = unit(e2 x e1),
//    flipped when (a - v0).n > 0; c = 1, depth = (b - v0).n + r; true.
// 4. End caps on rows (unit(e2 x e1), e1, e2): end a then end b; front 0 <= h <= best -> n = -normal, depth = r - h; back -best <= h < 0
//    -> n = normal, depth = r + h (end b back hit returns at once; end b also needs |h| <= r). A cap hit returns true.
// 5. Edges v1-v2, v0-v1, v2-v0 with 0x5453c0 (max distance best, lowered by each hit), n = dir, c = axis parameter, depth = r - dist.
// 6. Vertices v0, v1, v2 with 0x545690, same bookkeeping; returns whether any vertex hit.
static u8 FASTCALL collideCapsuleTri(const float *a, const float *b, float r, float *out, const u8 *tri) {
  const float *n = (const float *)(tri + 4);
  const float *v0 = (const float *)(tri + 0x34);
  const float *v1 = (const float *)(tri + 0x40);
  const float *v2 = (const float *)(tri + 0x4c);
  float da = a[0] * n[0] + a[1] * n[1];
  da = da + a[2] * n[2];
  float db = b[0] * n[0] + b[1] * n[1];
  db = db + b[2] * n[2];
  float dv = v0[1] * n[1] + v0[0] * n[0];
  dv = dv + v0[2] * n[2];
  float hi = dv + r;
  float xa = da - hi;
  float xb = db - hi;
  bool aAbove = xa > 0.0f, bAbove = xb > 0.0f;
  if (aAbove && bAbove) return 0;
  float lo = dv - r;
  float ya = da - lo;
  float yb = db - lo;
  bool aBelow = 0.0f > ya, bBelow = 0.0f > yb;
  if (aBelow && bBelow) return 0;
  float tmin = 0.0f, tmax = 1.0f;
  float dd = db - da;
  bool big = __builtin_fabs((double)dd) > G(double, 0x6a3138);
  if (bAbove != aAbove && big) {
    float x = negx(xa / dd);
    if (aAbove) {
      if (!(0.0f > x)) tmin = x;
    } else {
      if (!(x > 1.0f)) tmax = x;
    }
  }
  if (bBelow != aBelow && big) {
    float x = negx(ya / dd);
    if (aBelow) {
      if (!(tmin > x)) tmin = x;
    } else {
      if (!(x > tmax)) tmax = x;
    }
  }
  if (clipEdge((const float *)(tri + 0x64), v0, a, b, r, tmin, tmax)) return 0;
  if (clipEdge((const float *)(tri + 0x70), v0, a, b, r, tmin, tmax)) return 0;
  if (clipEdge((const float *)(tri + 0x58), v1, a, b, r, tmin, tmax)) return 0;

  float m[9], rhs[3], sol[3], dir[3];
  ext_43e920(m, b, a);
  ext_43e920(m + 3, v1, v0);
  ext_43e920(m + 6, v2, v0);
  ext_43e920(rhs, a, v0);
  if (ext_547860(m, rhs, sol)) {
    float u = sol[1];
    float t = negx(sol[0]);
    if (u >= 0.0f && 1.0f > u) {
      float v = sol[2];
      if (v >= 0.0f) {
        float s = v + u;
        if (s >= 0.0f && 1.0f > s && t >= 0.0f && 1.0f >= t) {
          ext_446ee0(sol, m + 6, m + 3);
          ext_44c840(sol);
          float dot = rhs[0] * sol[0] + rhs[1] * sol[1];
          out[3] = 1.0f;
          dot = dot + rhs[2] * sol[2];
          if (dot > 0.0f) ext_4e0d00(sol, -1.0f);
          goto axis_hit;
        }
      }
    }
  }

  {
    float best = r;
    u8 hit = 0;
    ext_446ee0(m, m + 6, m + 3);
    ext_44c840(m);
    ext_43e920(rhs, a, v0);
    if (ext_547860(m, rhs, sol)) {
      float u = sol[1];
      float h = sol[0];
      if (u >= 0.0f && 1.0f > u) {
        float v = sol[2];
        if (v >= 0.0f) {
          float s = v + u;
          if (s >= 0.0f && 1.0f > s) {
            float bst = r;
            if (h >= 0.0f && r >= h) {
              out[3] = 0.0f;
              ext_4e0d40(out, m, -1.0f);
              h = sol[0];
              out[4] = r - h;
              hit = 1;
              bst = h;
              best = h;
            }
            if (0.0f > h && h >= negx(bst)) {
              out[3] = 0.0f;
              out[0] = m[0];
              out[1] = m[1];
              out[2] = m[2];
              out[4] = h + r;
              hit = 1;
              best = negx(h);
            }
          }
        }
      }
    }
    ext_43e920(rhs, b, v0);
    if (ext_547860(m, rhs, sol)) {
      float u = sol[1];
      float h = sol[0];
      if (u >= 0.0f && 1.0f > u) {
        float v = sol[2];
        if (v >= 0.0f) {
          float s = v + u;
          if (s >= 0.0f && 1.0f > s && (double)r >= __builtin_fabs((double)h)) {
            float bst = best;
            if (h >= 0.0f && bst >= h) {
              out[3] = 1.0f;
              ext_4e0d40(out, m, -1.0f);
              h = sol[0];
              out[4] = r - h;
              hit = 1;
              bst = h;
            }
            if (0.0f > h && h >= negx(bst)) {
              float dep = h + r;
              out[3] = 1.0f;
              out[0] = m[0];
              out[1] = m[1];
              out[2] = m[2];
              out[4] = dep;
              return 1;
            }
          }
        }
      }
    }
    if (hit) return 1;

    best = r;
    float tP, sQ, dist;
    if (ext_5453c0(v1, v2, a, b, &tP, &sQ, &best, &dist, dir)) {
      out[3] = sQ;
      float d = dist;
      best = d;
      hit = 1;
      out[4] = r - d;
      out[0] = dir[0];
      out[1] = dir[1];
      out[2] = dir[2];
    }
    if (ext_5453c0(v0, v1, a, b, &tP, &sQ, &best, &dist, dir)) {
      out[3] = sQ;
      float d = dist;
      best = d;
      hit = 1;
      out[4] = r - d;
      out[0] = dir[0];
      out[1] = dir[1];
      out[2] = dir[2];
    }
    if (ext_5453c0(v2, v0, a, b, &tP, &sQ, &best, &dist, dir)) {
      out[3] = sQ;
      out[4] = r - dist;
      out[0] = dir[0];
      out[1] = dir[1];
      out[2] = dir[2];
      return 1;
    }
    if (hit) return 1;

    u8 found = 0;
    const float *vp = v0;
    for (int i = 3; i != 0; i--) {
      if (ext_545690(vp, a, b, &sQ, &best, &dist, dir)) {
        out[3] = sQ;
        float d = dist;
        best = d;
        found = 1;
        out[4] = r - d;
        out[0] = dir[0];
        out[1] = dir[1];
        out[2] = dir[2];
      }
      vp += 3;
    }
    return found;
  }

axis_hit:
  ext_43e920(rhs, b, v0);
  {
    float n0 = sol[0], n1 = sol[1], n2 = sol[2];
    float dep = rhs[0] * n0 + rhs[1] * n1;
    dep = dep + rhs[2] * n2;
    dep = dep + r;
    out[4] = dep;
    out[0] = n0;
    out[1] = n1;
    out[2] = n2;
  }
  return 1;
}
PCREG(544330, collideCapsuleTri);
