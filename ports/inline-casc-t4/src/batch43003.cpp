// batch43003.cpp - t4 () batch 43003: tier H float/SSE functions
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(void *cursor);              // float in st0 (script stream read)
extern "C" u32 THISCALL ext_4e5e60(void *cursor);                // dword/flag read, result in eax
extern "C" void THISCALL ext_4e6180(void *cursor, float *out);   // thiscall ret 4, writes three floats to out

// 0x46f600, thiscall(a) ret 4, returns true: a->slot 0x40(this+0x52); a->slot 0x50(this+0x56); cursor = 0 (a local stream cursor):
// [this+0x4c] = float read (0x4e5e80); byte [this+0x50] = (0x4e5e60 != 0); byte [this+0x51] = (0x4e5e60 != 0)
static bool THISCALL fn46f600(u8 *self, u8 *a) {
  vcall<void>(a, 0x40, (u32)(self + 0x52));
  vcall<void>(a, 0x50, (u32)(self + 0x56));
  u32 cur = 0;
  float f = ext_4e5e80(&cur);
  *(float *)(self + 0x4c) = f;
  u32 r1 = ext_4e5e60(&cur);
  self[0x50] = (r1 != 0);
  u32 r2 = ext_4e5e60(&cur);
  self[0x51] = (r2 != 0);
  return true;
}
PCREG(46f600, fn46f600);

// 0x5ddea0, thiscall(a) ret 4: three floats a->0x4e5e80() into [this+0x48], +0x4c, +0x50; 0x4e6180(a, this+0x54) (writes three floats);
// then [this+0x54], +0x58, +0x5c each divided by the float at 0x68af18
static void THISCALL fn5ddea0(u8 *self, u8 *a) {
  float f0 = ext_4e5e80(a);
  *(float *)(self + 0x48) = f0;
  float f1 = ext_4e5e80(a);
  *(float *)(self + 0x4c) = f1;
  float f2 = ext_4e5e80(a);
  *(float *)(self + 0x50) = f2;
  ext_4e6180(a, (float *)(self + 0x54));
  float k = G(float, 0x68af18);
  *(float *)(self + 0x54) = *(float *)(self + 0x54) / k;
  *(float *)(self + 0x58) = *(float *)(self + 0x58) / k;
  *(float *)(self + 0x5c) = *(float *)(self + 0x5c) / k;
}
PCREG(5ddea0, fn5ddea0);

// 0x5496e0, thiscall(n) ret 4, returns int: m = [[this+0x5d]+0xc] (pointer unaligned), mf = (float)(unsigned-style double of m) via the table at 0x680aa0;
// n < 0: cvttss2si(C1 / (C1 - n / D) * mf); otherwise cvttss2si(mf * (n / D + C1)); C1 float 0x678858, D float 0x68af24
static s32 THISCALL fn5496e0(u8 *self, s32 n) {
  u8 *o = *(u8 **)(self + 0x5d);
  s32 m = *(s32 *)(o + 0xc);
  float c1 = G(float, 0x678858);
  float d = G(float, 0x68af24);
  float mf = (float)((double)m + ((double *)0x680aa0)[(u32)m >> 31]);
  float t;
  if (n < 0) {
    float f = (float)n / d;
    float den = c1 - f;
    t = c1 / den;
    t = t * mf;
  } else {
    float g = (float)n / d;
    g = g + c1;
    t = mf * g;
  }
  return _mm_cvttss_si32(_mm_set_ss(t));
}
PCREG(5496e0, fn5496e0);
