// batch41010.cpp - cascade t2 (Sonnet): tier H float functions 0x45aa90 and 0x520c50.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline s32 trunc_ss(float f) { return _mm_cvttss_si32(_mm_set_ss(f)); }

extern "C" void FASTCALL ext_633654(u32 cookie);           // /GS check
extern "C" void THISCALL ext_523330(u8 *self, float *out); // thiscall ret 4 (recorded in the spec)
extern "C" void THISCALL ext_4e09b0(float *v);             // negates 3 floats (xor with the sign mask at 0x67af40), plain ret

// 0x45aa90, stdcall(c0, c1, t) ret 0xc, colour lerp: per byte channel i (shift 8*i): v_i = (int)((float)(c1_i - c0_i) * t + (float)c0_i) (cvttss2si, no clamp);
// result = v0 | v1 << 8 | v2 << 16 | v3 << 24 (plain ORs, so out-of-range values bleed into the next channel).
static u32 STDCALL fn45aa90(u32 c0, u32 c1, float t) {
  s32 v[4];
  for (int i = 0; i < 4; i++) {
    s32 a = (c0 >> (8 * i)) & 0xff;
    s32 b = (c1 >> (8 * i)) & 0xff;
    float d = (float)(b - a);
    d = d * t;
    d = d + (float)a;
    v[i] = trunc_ss(d);
  }
  u32 e = ((u32)v[2] | ((u32)v[3] << 8)) << 8;
  e = ((u32)v[1] | e) << 8;
  return e | (u32)v[0];
}
PCREG(45aa90, fn45aa90);

// 0x520c50, thiscall(f, a) ret 8 (/GS frame): A = [this+0x5c]; x = (float)(f - (double)A slot 0xc()) (x87 53-bit); s = x > 0 ? 1.0 : -1.0; 0x523330(A, &v[3]) (recorded);
// y = (float)((double)A slot 0x14() * s); y > 0 is false -> 0x4e09b0(&v) (negate); z = 0.0; d = v0 * [this+0x6c] + v1 * 0.0 + v2 * [this+0x74];
// d > 0 -> this slot 0x360(f, a) else slot 0x364(f, a); /GS check.
static void THISCALL fn520c50(u8 *self, float f, u32 a) {
  u8 *A = (u8 *)rd32(self + 0x5c);
  float r = vcall<float>(A, 0xc);
  float x = (float)((double)f - (double)r);
  float s = (x > 0.0f) ? 1.0f : -1.0f;
  float v[3];
  ext_523330((u8 *)rd32(self + 0x5c), v);
  float t = vcall<float>((void *)rd32(self + 0x5c), 0x14);
  float y = (float)((double)t * (double)s);
  float z = 0.0f;
  if (!(y > 0.0f)) ext_4e09b0(v);
  float d = v[0] * rdf(self + 0x6c);
  float e1 = v[1] * z;
  d = d + e1;
  float e2 = v[2] * rdf(self + 0x74);
  d = d + e2;
  if (d > z) vcall<void>(self, 0x360, f, a);
  else vcall<void>(self, 0x364, f, a);
  ext_633654(0);
}
PCREG(520c50, fn520c50);
