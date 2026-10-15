// batch53000.cpp - u6 (Sonnet) batch 53000: tier H float function.
#include "ff.h"

// 0x40e430, cdecl(ido, l1, cc, ch, wa1): FFTPACK-style radf2 real forward radix-2 pass (cc and ch are float arrays).
// Twiddle products are evaluated at 53-bit x87 precision (FPCW 0x27f) and rounded once when stored (the original keeps them on the x87 stack).
static void fn40e430(s32 ido, s32 l1, float *cc, float *ch, float *wa1) {
  s32 n = ido * l1;
  s32 c = 0;
  for (s32 k = 0; k < l1; k++) {
    s32 e = c + ido * 2 - 1;
    ch[k * ido] = (double)cc[e] + (double)cc[c];
    ch[n + k * ido] = (double)cc[c] - (double)cc[e];
    c += ido * 2;
  }
  if (ido < 2) return;
  if (ido != 2) {
    c = 0;
    for (s32 k = 0; k < l1; k++) {
      float *p = cc + c, *q = cc + c + ido * 2;
      float *d = ch + k * ido, *b = ch + n + k * ido;
      float *w = wa1 + 1;
      for (s32 m = (ido - 1) >> 1; m > 0; m--) {
        d[1] = (double)p[1] + (double)q[-3];
        double t1 = (double)p[1] - (double)q[-3];
        d[2] = (double)p[2] - (double)q[-2];
        double s = (double)q[-2] + (double)p[2];
        b[1] = (double)t1 * w[-1] - (double)s * w[0];
        b[2] = (double)t1 * w[0] + (double)s * w[-1];
        p += 2; q -= 2; d += 2; b += 2; w += 2;
      }
      c += ido * 2;
    }
    if (ido % 2 == 1) return;
  }
  for (s32 k = 0; k < l1; k++) {
    ch[ido - 1 + k * ido] = cc[ido - 1 + 2 * k * ido] + cc[ido - 1 + 2 * k * ido];
    ch[n + ido - 1 + k * ido] = -(cc[ido + 2 * k * ido] + cc[ido + 2 * k * ido]);
  }
}
PCREG(40e430, fn40e430);

// 0x4de1d0, register ABI (ecx = out quaternion[4], edx = 3x3 float matrix m[9]), /GS frame (cookie check omitted): rotation matrix to quaternion.
// A = {m6,m7,m8,m3,m4,m5,m0,m1,m2} (row-major, the exe copies the matrix in this order); trace = (m4 + m6) + m2 = A[4] + A[0] + A[8].
// trace > K0 (0x6785d0): s = (float)sqrt((double)(trace + 1.0 (0x678858))); out[3] = s * 0.5 (0x67a6ac), inv = 0.5 / s,
//   out[0] = (m5 - m1) * inv, out[1] = (m0 - m8) * inv, out[2] = (m7 - m3) * inv.
// Otherwise the largest diagonal entry i (0, 1 or 2; strict > against the earlier ones) with j = perm[i], k = perm[j] (perm = 1, 2, 0):
//   s = (float)sqrt((double)((A[4i] - (A[4k] + A[4j])) + 1.0)); out[i] = s * 0.5; inv = 0.5 / s;
//   out[3] = (A[3j+k] - A[3k+j]) * inv; out[j] = (A[3i+j] + A[3j+i]) * inv; out[k] = (A[3i+k] + A[3k+i]) * inv.
extern "C" double VECTORCALL ext_634d7c(double);
static void FASTCALL fn4de1d0(float *out, float *m) {
  float A[9] = {m[6], m[7], m[8], m[3], m[4], m[5], m[0], m[1], m[2]};
  float trace = (m[4] + m[6]) + m[2];
  if (trace > G(float, 0x6785d0)) {
    float s = (float)ext_634d7c((double)(trace + G(float, 0x678858)));
    float half = G(float, 0x67a6ac);
    float inv = half / s;
    out[3] = s * half;
    out[0] = (m[5] - m[1]) * inv;
    out[1] = (m[0] - m[8]) * inv;
    out[2] = (m[7] - m[3]) * inv;
    return;
  }
  static const int perm[3] = {1, 2, 0};
  int i = 0;
  if (A[4] > A[0]) i = 1;
  if (A[8] > A[4 * i]) i = 2;
  int j = perm[i], k = perm[j];
  float s = (float)ext_634d7c((double)((A[4 * i] - (A[4 * k] + A[4 * j])) + G(float, 0x678858)));
  float half = G(float, 0x67a6ac);
  float inv = half / s;
  out[i] = s * half;
  out[3] = (A[3 * j + k] - A[3 * k + j]) * inv;
  out[j] = (A[3 * i + j] + A[3 * j + i]) * inv;
  out[k] = (A[3 * i + k] + A[3 * k + i]) * inv;
}
PCREG(4de1d0, fn4de1d0);

// 0x5c0160, thiscall(float *P, float r0, float tol, s32 *idx, u8 flag, u32 mask) ret 0x18, /GS frame (cookie omitted): sweep search over a sorted table of 23-byte entries.
// this+0x4c = int order array, +0x50 = entry base, +0x54 = count, +0x60 = float pad. Entry = base + order[i] * 0x17: +0 object, +4 key (float x), +8 float y.
// r = flag ? r0 : pad + r0; hi = P[0] + r; lo = P[0] - r.  *idx == -1: start a search: key(order[0]) > hi or lo > key(order[count-1]) -> return 0;
// else binary search for the first i with !(lo > key(order[i])) (lo bound in [0, count-1]) stored in *idx; any other *idx is advanced by one.
// Then for each i < count: key > hi ends the sweep (*idx = -1, return 0). If tol > |P[1] - y| and bit [[obj+0x54]+4] of mask is set, d = 0x4e0830(&entry[4], {P[0], y, P[2]})
// (register ABI, float in st0); when r*r > d and bit 10 of [[obj.vslot(0x20)()+8]+0x3c] is clear, return obj (leaving *idx at i). Otherwise ++*idx; at the end *idx = -1, return 0.
extern "C" float FASTCALL ext_4e0830(u8 *a, float *b);
static inline u32 rd32b(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline float rdfb(const u8 *p) { u32 b = rd32b(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static u32 THISCALL fn5c0160(u8 *self, float *P, float r0, float tol, s32 *idx, u32 flag, u32 mask) {
  s32 count = *(s32 *)(self + 0x54);
  if (count == 0) return 0;
  float r = (flag & 0xff) ? r0 : rdfb(self + 0x60) + r0;
  float hi = P[0] + r;
  float lo = P[0] - r;
  s32 *order = *(s32 **)(self + 0x4c);
  u8 *base = *(u8 **)(self + 0x50);
  if (*idx == -1) {
    if (rdfb(base + order[0] * 0x17 + 4) > hi) return 0;
    if (lo > rdfb(base + order[count - 1] * 0x17 + 4)) return 0;
    u32 e = count - 1, s = 0;
    if (e > 1) {
      do {
        u32 m = (e + s) >> 1;
        if (lo > rdfb(base + order[m] * 0x17 + 4)) s = m;
        else e = m;
      } while (e > s + 1);
    }
    *idx = s;
  } else {
    *idx = *idx + 1;
  }
  while (*idx < *(s32 *)(self + 0x54)) {
    u8 *ent = *(u8 **)(self + 0x50) + (*(s32 **)(self + 0x4c))[*idx] * 0x17;
    if (rdfb(ent + 4) > hi) break;
    float y = rdfb(ent + 8);
    double d = (double)(P[1] - y);
    if (d < 0) d = -d;
    if ((double)tol > d) {
      float v[3] = {P[0], y, P[2]};
      u8 *obj = (u8 *)rd32b(ent);
      u8 *t = (u8 *)rd32b(obj + 0x54);
      u32 sh = rd32b(t + 4) & 31;
      if (mask & (1u << sh)) {
        float dist = ext_4e0830(ent + 4, v);
        if (r * r > dist) {
          u8 *o2 = vcall<u8 *>(obj, 0x20);
          u32 f = rd32b((u8 *)rd32b(o2 + 8) + 0x3c);
          if (!((f >> 10) & 1)) return (u32)obj;
        }
      }
    }
    (*idx)++;
  }
  *idx = -1;
  return 0;
}
PCREG(5c0160, fn5c0160);
