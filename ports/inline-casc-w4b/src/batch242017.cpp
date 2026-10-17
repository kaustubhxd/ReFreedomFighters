// batch242017.cpp - Sonnet-w4b, hand port of 0x457960 (the lifter rejects its esp frame and the x87 fsubrp).
#include "ff.h"

#define R32(a) (*(u32 *)(u32)(a))

typedef long double ld;

extern "C" u32 THISCALL ext_451fc0_thiscall5(u32, u32, u32, u32, u32, u32) __asm__("ext_451fc0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" ld FASTCALL ext_4e2220_ld5(u32, u32, u32, u32, u32) __asm__("ext_4e2220");

// maxss/minss operand semantics (the second operand wins on NaN or equality)
static inline float mxss(float a, float b) { return a > b ? a : b; }
static inline float mnss(float a, float b) { return a < b ? a : b; }
static inline u32 F2Ub(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

// scale a 3-float vector to unit length (x87 fsqrt/fdiv at the control-word precision); the vector is left alone when all three components are zero
static void norm3(float *v) {
  if (v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f) return;
  ld s = (ld)v[0] * (ld)v[0];
  s += (ld)v[1] * (ld)v[1];
  s += (ld)v[2] * (ld)v[2];
  ld len = fsqrt_x87(s);
  ld inv = (ld)1.0f / len;
  v[0] = (float)((ld)v[0] * inv);
  v[1] = (float)((ld)v[1] * inv);
  v[2] = (float)((ld)v[2] * inv);
}

// 0x457960: thiscall(this, a0 = object, a1 = float[3] direction), ret 8, result on the x87 stack.
// Query up to 8 contact records (0x24 bytes each) around a0, then 1 - max(running min, clamp((-dot(a1, mean dir) + K1) * K2))
extern "C" ld THISCALL port_457960(u32 self, u32 a0, u32 a1) {
  u32 recs[72];       // 8 records of 0x24 bytes
  float W[3];         // the mean-direction scratch (446ee0 output), normalised in place
  float p1[1];
  float V[3] = {0, 0, 0};
  float T1[3], T2[3];
  u32 count = ext_451fc0_thiscall5(self, (u32)recs, 8, (u32)p1, a0, F2Ub(150.0f));
  if (count == 0) return (p1[0] == *(float *)0x6785d0) ? (ld)1.0f : (ld)0.0f;
  float m = *(float *)0x678858;
  u32 rec = (u32)recs;
  for (u32 i = count; i != 0; i--, rec += 0x24) {
    ext_43e920_fastcall3((u32)T1, rec + 0xc, rec);
    ext_43e920_fastcall3((u32)T2, rec + 0x18, rec);
    ext_446ee0_fastcall3((u32)W, (u32)T1, (u32)T2);
    norm3(W);
    float s = (float)crt::sqrt((double)ext_4e2220_ld5(a0, (u32)W, rec, rec + 0xc, rec + 0x18));
    ext_441940_fastcall2((u32)V, (u32)W);
    float t = mxss(0.0f, s - *(float *)0x680a84) / *(float *)0x67cd40;
    m = mnss(t, m);
  }
  norm3(V);
  float *d = (float *)a1;
  float dot = d[1] * V[1];
  dot += d[0] * V[0];
  dot += d[2] * V[2];
  float w = (-dot + *(float *)0x683768) * *(float *)0x683764;
  float f = mxss(m, mxss(0.0f, w));
  return (ld)1.0f - (ld)f;
}
PCREG(457960, port_457960);
