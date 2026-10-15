// batch32095.cpp - cascade h2 (Sonnet): eight tier H (float / SSE) functions, third batch.
#include "ff.h"

extern "C" u32 THISCALL ext_467410(u8 *self, u32 a, float b, u32 c0, u32 c1, u32 c2, u32 c3);   // thiscall ret 0x18
extern "C" u32 THISCALL ext_52e670(u8 *self, u32 a, float b, float c, float d);                 // thiscall ret 0x10

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

// 0x475250, thiscall(float a, c0, c1, c2, c3) ret 0x14: returns 0x467410(this+0x2eb, this, a, c0, c1, c2, c3).
static u32 THISCALL fn475250(u8 *self, float a, u32 c0, u32 c1, u32 c2, u32 c3) {
  return ext_467410(self + 0x2eb, (u32)self, a, c0, c1, c2, c3);
}
PCREG(475250, fn475250);

// 0x4dfe20, register ABI (ecx = P, edx = Q), floats: P0 = Q1*P1 + Q0*P0; P1 = Q3*P1 + Q2*P0 (old P0 in both).
static void FASTCALL fn4dfe20(float *P, float *Q) {
  float p0 = P[0];
  float p1 = P[1];
  float n0 = Q[1] * p1 + Q[0] * p0;
  P[0] = n0;
  P[1] = Q[3] * p1 + Q[2] * p0;
}
PCREG(4dfe20, fn4dfe20);

// 0x52b130, thiscall(a, float b, float c, float d) ret 0x10: returns 0x52e670([this+0x65] (unaligned), a, b, c, d).
static u32 THISCALL fn52b130(u8 *self, u32 a, float b, float c, float d) {
  return ext_52e670((u8 *)rd32(self + 0x65), a, b, c, d);
}
PCREG(52b130, fn52b130);

// 0x46ee10, thiscall no args, x87 result: x = [this+0xac] - K(0x678858); m = (0 > x) ? 0 : x; r = (K2(0x680a70) < m) ? K2 : m; returns r / K2 (double division, 53-bit mantissa).
static double THISCALL fn46ee10(u8 *self) {
  float x = *(float *)(self + 0xac) - G(float, 0x678858);
  float m = (0.0f > x) ? 0.0f : x;
  float k2 = G(float, 0x680a70);
  float r = (k2 < m) ? k2 : m;
  return (double)r / (double)k2;
}
PCREG(46ee10, fn46ee10);

// 0x4c2bc0, thiscall(float a, float b) ret 8: byte [this+0xd1] != 0 -> o = [[this+0x44]+0x18]; [o+0x84] = a; [o+0x68] = (int)trunc(b) (cvttss2si).
static void THISCALL fn4c2bc0(u8 *self, float a, float b) {
  if (!self[0xd1]) return;
  s32 t;
  __asm__("cvttss2si %1, %0" : "=r"(t) : "m"(b));
  u8 *o = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  *(float *)(o + 0x84) = a;
  o = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  *(s32 *)(o + 0x68) = t;
}
PCREG(4c2bc0, fn4c2bc0);

// 0x4fa7c0, thiscall(float a) ret 4: v = (0 > a) ? 0 : ((K(0x678858) < a) ? K : a); [this+0xa7] = (float)(int)[this+0xab] * v (unaligned); returns slot 0x358 of this.
static u32 THISCALL fn4fa7c0(u8 *self, float a) {
  float v;
  if (0.0f > a) {
    v = 0.0f;
  } else {
    float k = G(float, 0x678858);
    v = (k < a) ? k : a;
  }
  float f = (float)(s32)rd32(self + 0xab);
  wrf(self + 0xa7, f * v);
  return vcall<u32>(self, 0x358);
}
PCREG(4fa7c0, fn4fa7c0);

// 0x5ab190, thiscall(18 stack dwords) ret 0x48: four 16-byte blocks to this+0x37d/0x38d/0x39d/0x3ad, dword 17 to this+0x3bd, low byte of dword 18 to this+0x3c1 (all unaligned).
static void THISCALL fn5ab190(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u32 a10, u32 a11,
                              u32 a12, u32 a13, u32 a14, u32 a15, u32 a16, u32 a17) {
  u32 v[16] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15};
  for (int i = 0; i < 16; i++) wr32(self + 0x37d + 4 * i, v[i]);
  wr32(self + 0x3bd, a16);
  self[0x3c1] = (u8)a17;
}
PCREG(5ab190, fn5ab190);

// 0x5d13a0, thiscall(int a) ret 4: a != 0 -> f = [this+0xb1f] (unaligned); byte [this+0xb33] = 1; byte [this+0xa70] = (K(0x679540) >= f, ordered); [this+0xb1f] = (float)a / K2(0x67af20).
static void THISCALL fn5d13a0(u8 *self, s32 a) {
  if (!a) return;
  float f = rdf(self + 0xb1f);
  self[0xb33] = 1;
  self[0xa70] = G(float, 0x679540) >= f;
  wrf(self + 0xb1f, (float)a / G(float, 0x67af20));
}
PCREG(5d13a0, fn5d13a0);
