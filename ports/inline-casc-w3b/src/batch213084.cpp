#include "ff.h"

typedef u32(THISCALL *V0)(void *);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" double VECTORCALL ext_634d7c(double x);  // sqrt
extern "C" void FASTCALL ext_43e920(void *out, void *b, void *c);
extern "C" float FASTCALL ext_4e0030(void *a, void *b);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline float cf(u32 addr) { return G(float, addr); }

// 0x549450: thiscall(R) ret 4 -> int: turn-rate step. S = [[this+8]+0x8049]; V3 = S.slot0x2c()[0..2] - R's vector (R+0x94..0x9c) (0x43e920), t = 0x4e0030(V3, S.slot0x38()[0..2])
// (an angle in radians). A piecewise curve of t (6 cases on the exe constants 60 / 80 / 90 / 100 / 120 / 180 degrees, 0 outside) gives r; len = sqrt(|V3|^2) as float (CRT wrapper 0x634d7c);
// the result is the int of r * 100 (times len / R[0xac] when that ratio is below 1.0) and R[0x4c] is divided by (len (1.0 when len == 0) / R[0xac]) when len exceeds R[0xac].
extern "C" u32 THISCALL fn_549450(u8 *self, u8 *R) {
  float P[3], V2[3], V3[3], V4[3];
  u8 *S = (u8 *)rd32u((u8 *)rd32u(self + 8) + 0x8049);
  P[0] = rdf(R + 0x94);
  P[1] = rdf(R + 0x98);
  P[2] = rdf(R + 0x9c);
  const float *q1 = (const float *)(*(V0 *)(vt(S) + 0x2c))(S);
  V2[0] = q1[0];
  V2[1] = q1[1];
  V2[2] = q1[2];
  ext_43e920(V3, V2, P);
  const float *q2 = (const float *)(*(V0 *)(vt(S) + 0x38))(S);
  V4[0] = q2[0];
  V4[1] = q2[1];
  V4[2] = q2[2];
  float t = ext_4e0030(V3, V4);
  float A = cf(0x693d3c), B = cf(0x693d48), C = cf(0x693d4c), D = cf(0x693d58), E = cf(0x693d38), F = cf(0x693d30);
  float r = 0.0f;
  if (t >= A && B > t) {
    float x = t - A;
    x = x + x;
    r = x / cf(0x693d24);
  } else if (t >= B && C > t) {
    float x = t - B;
    x = x * cf(0x685280);
    x = x / cf(0x693d28);
    r = x + cf(0x680a60);
  } else if (t >= C && D >= t) {
    float x = t - C;
    x = x + x;
    x = x / cf(0x693d34);
    r = x + cf(0x680a6c);
  } else if (A > t && t > E) {
    float x = A - t;
    x = x + x;
    r = x / cf(0x693d68);
  } else if (E >= t && t > F) {
    float x = E - t;
    x = x * cf(0x685280);
    x = x / cf(0x693d2c);
    x = x + cf(0x680a60);
    u32 b = fbits(x) ^ 0x80000000u;
    r = bitsf(b);
  } else if (F >= t && t >= 0.0f) {
    float x = F - t;
    x = x + x;
    x = x / F;
    x = x + cf(0x680a6c);
    u32 b = fbits(x) ^ 0x80000000u;
    r = bitsf(b);
  }
  float s = V3[0] * V3[0];
  float s1 = V3[1] * V3[1];
  s = s + s1;
  float s2 = V3[2] * V3[2];
  s = s + s2;
  float len = (float)ext_634d7c((double)s);
  float W = rdf(R + 0xac);
  float one = cf(0x678858);
  float ratio = len / W;
  float x0 = r * cf(0x67cd40);
  if (one > ratio) x0 = x0 * ratio;
  s32 ret = _mm_cvttss_si32(_mm_set_ss(x0));
  float x1 = len;
  float rv = rdf(R + 0x4c);
  if (len == cf(0x6785d0)) x1 = one;
  if (x1 > W) {
    float q = x1 / W;
    rv = rv / q;
  }
  __builtin_memcpy(R + 0x4c, &rv, 4);
  ext_633654(G(u32, 0x6f5630));
  return (u32)ret;
}
PCREG(549450, fn_549450);
