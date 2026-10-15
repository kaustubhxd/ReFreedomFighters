// batch34166.cpp - cascade escalation, batch 34166: 0x518190 (direction and speed of a moving point, 137 instructions: normalise a vector, derive an offset and a signed length through register-argument vector helpers).
#include "ff.h"

extern "C" void THISCALL ext_523330(void *self, void *v);                       // ret 4: fills the vector v
extern "C" void THISCALL ext_4e0d00(void *v, u32 f);                            // ret 4: scale in place
extern "C" void FASTCALL ext_4e0be0(void *ecx, void *edx);                      // plain ret
extern "C" void FASTCALL ext_443ef0(void *out, void *base, void *p, u32 f);     // ret 8: out = p * f + base
extern "C" void FASTCALL ext_43e920(void *ecx, void *edx, void *p);             // ret 4
extern "C" void FASTCALL ext_441940(void *ecx, void *edx);                      // plain ret
extern "C" void FASTCALL ext_43e960(void *ecx, void *edx);                      // plain ret
extern "C" float FASTCALL ext_4e0030(void *ecx, void *edx);                     // plain ret, float in st0
extern "C" void FASTCALL ext_446ee0(void *ecx, void *edx, void *p);             // ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                                // /GS check

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static __m128 ld_ss(u8 *p) { return _mm_set_ss(bitsf(rd32(p))); }

// 0x518190, thiscall(a0, a1, v, out) ret 0x10, /GS. ext_523330([this+0x5c], v); v[1] = 0; ext_4e0d00(v, -1.0); when v is not the exact zero vector it is normalised with x87 double-precision steps (len = sqrt(x^2 + y^2 + z^2), v = (float)(v * (1.0 / len)));
// F = unaligned float [this+0x15fb]; when F > 0: w = {0, [this+0x15f7] * F, 0} and ext_4e0be0(v, &w). ext_443ef0(a1, a0, v, [this+0x37c]); t (12 bytes) = ext_43e920(&t, this + 0x15df, v); ext_4e0d00(&t, [this+0x378] + [this+0x37c]);
// ext_441940(&t, this + 0x15d3); ext_43e960(&t, a0); r = (float)sqrt(t.x^2 + t.y^2 + t.z^2) (CRT sqrt import [0x676330]); when r > constant 0x67a284: *out = ext_4e0030(v, &t); ext_446ee0(&w, v, &t); when w[1] > 0 the float *out is negated (mask 0x67af40).
static void THISCALL fn518190(u8 *self, u8 *a0, u8 *a1, float *v, float *out) {
  float t[3];
  float w[3];
  ext_523330(*(u8 **)(self + 0x5c), v);
  *(u32 *)(v + 1) = 0;
  ext_4e0d00(v, 0xbf800000);
  if (!(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)) {
    double x = v[0], y = v[1], z = v[2];
    double s = x * x;
    s = s + y * y;
    s = s + z * z;
    double len = _mm_cvtsd_f64(_mm_sqrt_sd(_mm_set_sd(s), _mm_set_sd(s)));
    double inv = 1.0 / len;
    v[0] = (float)((double)v[0] * inv);
    v[1] = (float)((double)v[1] * inv);
    v[2] = (float)((double)v[2] * inv);
  }
  __m128 F = ld_ss(self + 0x15fb);
  if (_mm_comigt_ss(F, _mm_setzero_ps())) {
    w[0] = 0.0f;
    w[1] = _mm_cvtss_f32(_mm_mul_ss(ld_ss(self + 0x15f7), F));
    w[2] = 0.0f;
    ext_4e0be0(v, w);
  }
  ext_443ef0(a1, a0, v, rd32(self + 0x37c));
  ext_43e920(t, self + 0x15df, v);
  ext_4e0d00(t, __builtin_bit_cast(u32, _mm_cvtss_f32(_mm_add_ss(ld_ss(self + 0x378), ld_ss(self + 0x37c)))));
  ext_441940(t, self + 0x15d3);
  ext_43e960(t, a0);
  __m128 x1 = _mm_set_ss(t[0]), x0 = _mm_set_ss(t[1]);
  x0 = _mm_mul_ss(x0, x0);
  x1 = _mm_mul_ss(x1, x1);
  x1 = _mm_add_ss(x1, x0);
  x0 = _mm_set_ss(t[2]);
  x0 = _mm_mul_ss(x0, x0);
  x1 = _mm_add_ss(x1, x0);
  double d = _mm_cvtsd_f64(_mm_cvtps_pd(x1));
  double rr;
  asm volatile("movsd %[d], %%xmm0\n\tcall *0x676330\n\tmovsd %%xmm0, %[rr]" : [rr] "=m"(rr) : [d] "m"(d)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  float r = (float)rr;
  if (_mm_comigt_ss(_mm_set_ss(r), _mm_set_ss(G(float, 0x67a284)))) {
    float f = ext_4e0030(v, t);
    *out = f;
    ext_446ee0(w, v, t);
    if (_mm_comigt_ss(_mm_set_ss(w[1]), _mm_setzero_ps())) *(u32 *)out = *(u32 *)out ^ G(u32, 0x67af40);
  }
  ext_633654(0);
}
PCREG(518190, fn518190);
