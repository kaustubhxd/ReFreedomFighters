// batch32138.cpp - cascade h2 (): two tier H (float / SSE) functions.
#include "ff.h"
#include <xmmintrin.h>

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

extern "C" u32 FASTCALL ext_4cc850(u8 *obj, const char *name);                       // ecx = obj, edx = name, returns eax (0 = match)
extern "C" u32 THISCALL ext_4e4bd0(u8 *self, u32 a, s32 *lo, s32 *hi);               // thiscall ret 0xc

// 0x45f8d0, thiscall(name) ret 4: o = [this+0x10]; c = [o+0x14] (either null -> return); slot 0x4c of c with (&it); s = slot 0x64 of [[this+0x10]+0x14] with (&it);
// while s != 0: if 0x4cc850([s+0x10], name) == 0 -> float [s+8] = (float)(int)[[0x70039c]+0x40] * 0.0009765625f, return; else s = slot 0x64 (same way) again.
static void THISCALL fn45f8d0(u8 *self, const char *name) {
  u8 *o = *(u8 **)(self + 0x10);
  if (!o) return;
  void *c = *(void **)(o + 0x14);
  if (!c) return;
  u32 it[3];
  vcall<void>(c, 0x4c, (u32)it);
  u8 *s = vcall<u8 *>(*(void **)(*(u8 **)(self + 0x10) + 0x14), 0x64, (u32)it);
  while (s) {
    if (ext_4cc850(*(u8 **)(s + 0x10), name) == 0) {
      s32 t = (s32)rd32(G(u8 *, 0x70039c) + 0x40);
      *(float *)(s + 8) = (float)t * 0.0009765625f;
      return;
    }
    s = vcall<u8 *>(*(void **)(*(u8 **)(self + 0x10) + 0x14), 0x64, (u32)it);
  }
}
PCREG(45f8d0, fn45f8d0);

// 0x4e4ef0, thiscall(a, pmin, pmax) ret 0xc, returns the result of 0x4e4bd0: with s = float [this+0x1d], o = float [this+0x21..0x29] (unaligned) and K = 32768.0f:
// lo[i] = (int)trunc((pmin[i] - o[i]) * s + K); hi[i] = (int)trunc((pmax[i] - o[i]) * s + K) + 1 (i = 0..2); return 0x4e4bd0(this, a, lo, hi).
static u32 THISCALL fn4e4ef0(u8 *self, u32 a, const float *pmin, const float *pmax) {
  s32 lo[3], hi[3];
  float s = rdf(self + 0x1d);
  float K = bitsf(0x47000000);
  lo[0] = _mm_cvttss_si32(_mm_set_ss((pmin[0] - rdf(self + 0x21)) * s + K));
  lo[1] = _mm_cvttss_si32(_mm_set_ss((pmin[1] - rdf(self + 0x25)) * s + K));
  lo[2] = _mm_cvttss_si32(_mm_set_ss((pmin[2] - rdf(self + 0x29)) * s + K));
  hi[0] = _mm_cvttss_si32(_mm_set_ss((pmax[0] - rdf(self + 0x21)) * s + K)) + 1;
  hi[1] = _mm_cvttss_si32(_mm_set_ss((pmax[1] - rdf(self + 0x25)) * s + K)) + 1;
  hi[2] = _mm_cvttss_si32(_mm_set_ss((pmax[2] - rdf(self + 0x29)) * s + K)) + 1;
  return ext_4e4bd0(self, a, lo, hi);
}
PCREG(4e4ef0, fn4e4ef0);
