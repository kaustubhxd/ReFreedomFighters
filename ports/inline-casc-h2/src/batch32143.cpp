// batch32143.cpp - cascade h2 (Sonnet): two tier H (float / SSE) functions.
#include "ff.h"
#include <xmmintrin.h>

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);      // thiscall ret 4: *out = lookup result
extern "C" u32 THISCALL ext_4e5e60(u32 *self);                // thiscall, returns eax
extern "C" double THISCALL ext_4e5e80(u32 *self);             // thiscall, float result on x87

// 0x45aa90, stdcall(c0, c1, t float) ret 0xc: per-byte colour interpolation: v_k = (int)trunc((float)(b_k(c1) - b_k(c0)) * t + (float)b_k(c0)) for k = 3 (bits 24..31), 2, 1, 0;
// result = ((((v2 | v3 << 8) << 8 | v1) << 8) | v0 (the pieces are OR-ed without masking, so out-of-range values bleed into the neighbouring bytes).
static u32 STDCALL fn45aa90(u32 c0, u32 c1, float t) {
  u32 a0 = c0 & 0xff, a1 = (c0 >> 8) & 0xff, a2 = (c0 >> 16) & 0xff, a3 = c0 >> 24;
  s32 d2 = (s32)((c1 >> 16) & 0xff) - (s32)a2;
  s32 d3 = (s32)(c1 >> 24) - (s32)a3;
  s32 d1 = (s32)((c1 >> 8) & 0xff) - (s32)a1;
  s32 d0 = (s32)(c1 & 0xff) - (s32)a0;
  s32 v2 = _mm_cvttss_si32(_mm_set_ss((float)d2 * t + (float)(s32)a2));
  s32 v3 = _mm_cvttss_si32(_mm_set_ss((float)d3 * t + (float)(s32)a3));
  u32 e = (u32)v2 | ((u32)v3 << 8);
  e <<= 8;
  s32 v1 = _mm_cvttss_si32(_mm_set_ss((float)d1 * t + (float)(s32)a1));
  u32 r = (u32)v1 | e;
  r <<= 8;
  s32 v0 = _mm_cvttss_si32(_mm_set_ss((float)d0 * t + (float)(s32)a0));
  return r | (u32)v0;
}
PCREG(45aa90, fn45aa90);

// 0x5d3f70, thiscall(o) ret 4, returns true: b = 0; 0x6352f0(this, &b); [this+0x4c] = 0x4e5e60(&b); [this+0x50] = (float)0x4e5e80(&b);
// then on o: slot 0x48 with (this+0x80), (this+0x58), (this+0x5c), (this+0x60), (this+0x64); slot 0x40 with (this+0x68), (this+0x6c), (this+0x70), (this+0x74).
static u8 THISCALL fn5d3f70(u8 *self, void *o) {
  u32 b = 0;
  ext_6352f0(self, &b);
  wr32(self + 0x4c, ext_4e5e60(&b));
  float f = (float)ext_4e5e80(&b);
  u32 bits;
  __builtin_memcpy(&bits, &f, 4);
  wr32(self + 0x50, bits);
  vcall<void>(o, 0x48, (u32)(self + 0x80));
  vcall<void>(o, 0x48, (u32)(self + 0x58));
  vcall<void>(o, 0x48, (u32)(self + 0x5c));
  vcall<void>(o, 0x48, (u32)(self + 0x60));
  vcall<void>(o, 0x48, (u32)(self + 0x64));
  vcall<void>(o, 0x40, (u32)(self + 0x68));
  vcall<void>(o, 0x44, (u32)(self + 0x6c));
  vcall<void>(o, 0x40, (u32)(self + 0x70));
  vcall<void>(o, 0x40, (u32)(self + 0x74));
  return 1;
}
PCREG(5d3f70, fn5d3f70);
