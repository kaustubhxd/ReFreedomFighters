#include "ff.h"

extern "C" double VECTORCALL ext_634de2(double x);  // atan

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }

// 0x5162d0 is `fld dword [ecx + 0x55]`: the float at obj + 0x55 on the x87 stack
static inline float F55(const u8 *obj) { return rdf(obj + 0x55); }
// fstp dword (the first value rounded to float), fsubr: (double)t - (double)b in 53-bit precision
static inline double diff(const u8 *a, const u8 *b) {
  float t = F55(a);
  return (double)t - (double)F55(b);
}
static inline double absd(double d) {
  u64 b;
  __builtin_memcpy(&b, &d, 8);
  b &= G(u64, 0x67cd50);
  __builtin_memcpy(&d, &b, 8);
  return d;
}
// keeps the larger-magnitude difference in acc (comisd on the absolute values)
static inline void widen(float &acc, const u8 *a, const u8 *b) {
  double d = diff(a, b);
  if (absd(d) > absd((double)acc)) acc = (float)diff(a, b);
}

// 0x524b00: thiscall(), void. A = the largest-magnitude (obj+0xde - obj) float difference of the point records at this+0xbd + 0x1bc * j (j = 0, 2, 4 ... below this[0x8c]) and
// this+0x435 + 0x1bc * j (below this[0x90]); the differences are x87 (53-bit) values compared in magnitude. B = (this+0x435) - (this+0xbd) float difference, replaced by
// (this+0x513) - (this+0x19b) when that is larger in magnitude. this[0x3c] = atan(A / f[0xa8]), this[0x34] = atan(B / f[0xac]), both clamped to [-0.7853982f, 0.7853982f]
// ([0x69f1a8] / [0x69f1a0], with minss NaN semantics). this[0x38] then moves towards this[0x3c], and this[0x30] towards this[0x34], by dt * [0x6a09e4] ([0x70039c]+0x48 is dt),
// snapping to the target within 2^-13 ([0x679540]).
extern "C" void THISCALL fn_524b00(u8 *self) {
  float A = 0.0f, B;
  s32 n8c = (s32)rd32u(self + 0x8c);
  if (n8c > 0) {
    u8 *edi = self + 0xbd;
    s32 i = 0;
    do {
      widen(A, edi + 0xde, edi);
      i += 2;
      edi += 0x1bc;
    } while (i < (s32)rd32u(self + 0x8c));
  }
  s32 n90 = (s32)rd32u(self + 0x90);
  if (n90 > 0) {
    u8 *edi = self + 0x435;
    s32 i = 0;
    do {
      widen(A, edi + 0xde, edi);
      i += 2;
      edi += 0x1bc;
    } while (i < (s32)rd32u(self + 0x90));
  }
  {
    float t = F55(self + 0x435);
    B = (float)((double)t - (double)F55(self + 0xbd));
    double d2 = diff(self + 0x513, self + 0x19b);
    if (absd(d2) > absd((double)B)) B = (float)diff(self + 0x513, self + 0x19b);
  }
  wrf(self + 0x3c, (float)ext_634de2((double)(A / rdf(self + 0xa8))));
  float y = (float)ext_634de2((double)(B / rdf(self + 0xac)));
  float x3 = rdf(self + 0x3c);
  float lo = G(float, 0x69f1a8), hi = G(float, 0x69f1a0);
  wrf(self + 0x34, y);
  float cx;
  if (lo > x3)
    cx = lo;
  else
    cx = (hi < x3) ? hi : x3;
  float y3 = rdf(self + 0x34);
  wrf(self + 0x3c, cx);
  float cy;
  if (lo > y3)
    cy = lo;
  else
    cy = (hi < y3) ? hi : y3;
  float K = G(float, 0x6a09e4), eps = G(float, 0x679540);
  wrf(self + 0x34, cy);
  u8 *eng = G(u8 *, 0x70039c);
  float v38 = rdf(self + 0x38);
  float dk = rdf(eng + 0x48) * K;
  if (v38 > cx) {
    float t = v38 - dk;
    float lim = cx + eps;
    wrf(self + 0x38, t);
    if (lim > t) wrf(self + 0x38, cx);
  } else if (cx > v38) {
    float t = v38 + dk;
    float lim = cx - eps;
    wrf(self + 0x38, t);
    if (t > lim) wrf(self + 0x38, cx);
  }
  float v30 = rdf(self + 0x30);
  float tgt = rdf(self + 0x34);
  float dk2 = rdf(eng + 0x48) * K;
  if (v30 > tgt) {
    float t = v30 - dk2;
    float lim = tgt + eps;
    wrf(self + 0x30, t);
    if (lim > t) wrf(self + 0x30, tgt);
  } else if (tgt > v30) {
    float t = v30 + dk2;
    float lim = tgt - eps;
    wrf(self + 0x30, t);
    if (t > lim) wrf(self + 0x30, tgt);
  }
}
PCREG(524b00, fn_524b00);
