#include "ff.h"

extern "C" double VECTORCALL ext_634d70(double x);  // cos
extern "C" double VECTORCALL ext_634d76(double x);  // sin
extern "C" double VECTORCALL ext_634d7c(double x);  // sqrt
extern "C" double VECTORCALL ext_634dbe(double x);  // acos
extern "C" double VECTORCALL ext_634de2(double x);  // atan
extern "C" long double THISCALL ext_44c840(void *v);

static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline double absd(double d) {
  u64 b;
  __builtin_memcpy(&b, &d, 8);
  b &= G(u64, 0x67cd50);
  __builtin_memcpy(&d, &b, 8);
  return d;
}

// 0x4e1f00: fastcall(v, out, a, b, c, d) ret 0x10 -> 0 / 1: direction clamp. The vector v is normalized in place (x87 stack, 53-bit) unless it is the zero vector. The x and y
// components pick the scales sx = x > 0 ? c : a and sy = y > 0 ? d : b (the stack arguments c / d are replaced by a / b in the other case); the angle is atan(|y / sy| / |x / sx|) (0 when
// x / sx == 0), the radius r = sqrt((cos(angle) * c)^2 + (sin(angle) * d)^2) and the limit thr is 0 for z > 1, pi for z < -1, else acos(z). When thr > r the vector is rebuilt as
// (x * sin r, y * sin r, cos r) with 0x44c840 normalizing before and after, *out = 1.0f and 1 is returned; otherwise *out = thr / r (when out is not null) and 0.
extern "C" u32 FASTCALL fn_4e1f00(u8 *v, float *out, float a, float b, float c, float d) {
  if (rdf(v) != 0.0f || rdf(v + 4) != 0.0f || rdf(v + 8) != 0.0f) {
    long double x = rdf(v), y = rdf(v + 4), z = rdf(v + 8);
    long double s = x * x;
    s += y * y;
    s += z * z;
    long double len = fsqrt_x87(s);
    long double inv = 1.0L / len;
    wrf(v, (float)(x * inv));
    wrf(v + 4, (float)(y * inv));
    wrf(v + 8, (float)(z * inv));
  }
  float x = rdf(v), y = rdf(v + 4);
  float sx, sy;
  if (x > 0.0f) {
    sx = c;
  } else {
    sx = a;
    c = a;
  }
  if (y > 0.0f) {
    sy = d;
  } else {
    sy = b;
    d = b;
  }
  float p = x / sx;
  float angle = 0.0f;
  if (!(p == 0.0f)) {
    float q = y / sy;
    double dp = absd((double)p), dq = absd((double)q);
    angle = (float)ext_634de2(dq / dp);
  }
  float u = (float)ext_634d70((double)angle) * c;
  float w = (float)ext_634d76((double)angle) * d;
  float u2 = u * u;
  float w2 = w * w;
  float r = (float)ext_634d7c((double)(w2 + u2));
  float z = rdf(v + 8);
  float thr;
  if (z > G(float, 0x678858)) {
    thr = 0.0f;
  } else if (G(float, 0x67af2c) > z) {
    thr = G(float, 0x67da18);
  } else {
    thr = (float)ext_634dbe((double)z);
  }
  if (thr > r) {
    float sn = (float)ext_634d76((double)r);
    __builtin_memset(v + 8, 0, 4);
    ext_44c840(v);
    wrf(v, rdf(v) * sn);
    wrf(v + 4, rdf(v + 4) * sn);
    wrf(v + 8, (float)ext_634d70((double)r));
    ext_44c840(v);
    if (out) *out = 1.0f;
    return 1;
  }
  if (out) *out = thr / r;
  return 0;
}
PCREG(4e1f00, fn_4e1f00);
