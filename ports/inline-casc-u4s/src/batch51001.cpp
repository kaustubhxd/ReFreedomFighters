// batch51001.cpp - u4 (Sonnet) batch 51001: tier H float/SSE functions
#include "ff.h"

extern "C" void THISCALL ext_523330(void *self, float *out);                         // ret 4: writes a vector to out
extern "C" void THISCALL ext_4e0d00(float *v, float s);                              // vscalar in place
extern "C" void FASTCALL ext_4e0be0(float *v, float *t);                             // plain
extern "C" void FASTCALL ext_443ef0(float *dst, float *base, float *v, float s);     // ret 8: dst = base + v * s
extern "C" void FASTCALL ext_43e920(float *dst, float *a, float *b);                 // ret 4: dst = a - b
extern "C" void FASTCALL ext_441940(float *a, float *b);                             // a += b
extern "C" void FASTCALL ext_43e960(float *a, float *b);                             // a -= b
extern "C" float FASTCALL ext_4e0030(float *v, float *u);                            // float in st0
extern "C" void FASTCALL ext_446ee0(float *out, float *a, float *b);                 // ret 4: cross product
extern "C" double VECTORCALL ext_634d7c(double);                                     // CRT sqrt

static inline void norm3_x87(float *v) {
  long double x = v[0], y = v[1], z = v[2];
  long double len = fsqrt_x87(x * x + y * y + z * z);
  long double inv = (long double)1.0f / len;
  v[0] = (float)((long double)v[0] * inv);
  v[1] = (float)((long double)v[1] * inv);
  v[2] = (float)((long double)v[2] * inv);
}

// 0x518190, thiscall(a, b, v, c) ret 0x10, /GS: ext_523330([this+0x5c], v); v[1] = 0; v *= -1; normalise v if nonzero; if float [this+0x15fb] (unaligned) > 0:
// t = {0, [this+0x15f7] * that, 0}; ext_4e0be0(v, t); b = a + v * [this+0x37c] (0x443ef0); u = [this+0x15df] - v; u *= [this+0x378] + [this+0x37c]; u += [this+0x15d3]; u -= a;
// len = sqrt(|u|^2) (SSE float sum, CRT double sqrt); if len > F(0x67a284): *c = ext_4e0030(v, u) (st0); t = cross(u, v) (0x446ee0); if t.y > 0 *c = -*c
static void THISCALL fn518190(u8 *self, float *a, float *b, float *v, float *c) {
  float t[3];
  float u[3];
  ext_523330(*(void **)(self + 0x5c), v);
  v[1] = 0.0f;
  ext_4e0d00(v, -1.0f);
  if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) norm3_x87(v);
  float k = bitsf(*(u32 *)(self + 0x15fb));
  if (k > 0.0f) {
    float y = bitsf(*(u32 *)(self + 0x15f7)) * k;
    t[0] = 0.0f;
    t[1] = y;
    t[2] = 0.0f;
    ext_4e0be0(v, t);
  }
  ext_443ef0(b, a, v, *(float *)(self + 0x37c));
  ext_43e920(u, (float *)(self + 0x15df), v);
  ext_4e0d00(u, *(float *)(self + 0x378) + *(float *)(self + 0x37c));
  ext_441940(u, (float *)(self + 0x15d3));
  ext_43e960(u, a);
  float s = u[0] * u[0];
  float s1 = u[1] * u[1];
  s = s + s1;
  float s2 = u[2] * u[2];
  s = s + s2;
  float len = (float)ext_634d7c((double)s);
  if (len > G(float, 0x67a284)) {
    *c = ext_4e0030(v, u);
    ext_446ee0(t, v, u);
    if (t[1] > 0.0f) *(u32 *)c = fbits(*c) ^ G(u32, 0x67af40);
  }
}
PCREG(518190, fn518190);
