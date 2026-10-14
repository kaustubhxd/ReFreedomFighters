// batch32118.cpp - cascade h2 (): tier H (float / SSE) functions, batch 32118.
#include "ff.h"

extern "C" double THISCALL ext_522f60(u8 *self, float a, float b);   // thiscall ret 8, double in st0
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                 // thiscall ret 4
extern "C" void THISCALL ext_500360(u8 *self, float a);              // thiscall ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);                // thiscall ret 4

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4a39c0, thiscall(o) ret 4, returns true: [this+4] &= ~0x40; slot 0x64 of o with [this+0x48]; slot 0x68 of o with this+0x4c, this+0x58, this+0x64 (three calls);
// slot 0x4c of o with float [this+0x74]; slot 0x3c of o with [this+0x124] and then [this+0x128].
static bool THISCALL fn4a39c0(u8 *self, void *o) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(o, 0x64, *(u32 *)(self + 0x48));
  vcall<void>(o, 0x68, (u32)(self + 0x4c));
  vcall<void>(o, 0x68, (u32)(self + 0x58));
  vcall<void>(o, 0x68, (u32)(self + 0x64));
  vcall<void>(o, 0x4c, *(float *)(self + 0x74));
  vcall<void>(o, 0x3c, *(u32 *)(self + 0x124));
  vcall<void>(o, 0x3c, *(u32 *)(self + 0x128));
  return true;
}
PCREG(4a39c0, fn4a39c0);

// 0x519280, thiscall no args: [this+0x1603] = [this+0x1021] (unaligned dwords); d = 0x522f60([this+0x5c], float [[this+0x5c]+4], 50.0f) (double); x = (float)|d|; x > K(0x69f198)
// -> [this+0x1607] = ([[this+0x5c]+0x24] / 500.0) * (x / K2(0x69f19c)), else 0; byte [this+0x160b] = (float [this+0x358] != 0.0, true for NaN).
static void THISCALL fn519280(u8 *self) {
  u32 v = rd32(self + 0x1021);
  wr32(self + 0x1603, v);
  u8 *obj = *(u8 **)(self + 0x5c);
  double d = ext_522f60(obj, *(float *)(obj + 4), 50.0f);
  u32 lo, hi;
  __builtin_memcpy(&lo, &d, 4);
  __builtin_memcpy(&hi, (u8 *)&d + 4, 4);
  hi &= 0x7fffffffu;
  double ad;
  u32 parts[2] = {lo, hi};
  __builtin_memcpy(&ad, parts, 8);
  float x = (float)ad;
  if (x > G(float, 0x69f198)) {
    float q = x / G(float, 0x69f19c);
    float w = *(float *)(*(u8 **)(self + 0x5c) + 0x24) / G(float, 0x680a90);
    w = w * q;
    *(float *)(self + 0x1607) = w;
  } else {
    *(u32 *)(self + 0x1607) = 0;
  }
  float t = *(float *)(self + 0x358);
  self[0x160b] = !(t == 0.0f);
}
PCREG(519280, fn519280);

// 0x5515f0, stdcall(p, a, v) ret 0xc, returns b: b = slot 0x18 of p with a; b == 0 -> 0; q = slot 0x4c of b; 0x500360(0x5003d0(q, 0), float v[0]); 0x500360(0x5003d0(q, 1), float v[1]); 0x5002f0(0x5003d0(q, 2), v[2]); returns b.
static u32 STDCALL fn5515f0(void *p, u32 a, u32 *v) {
  void *b = vcall<void *>(p, 0x18, a);
  if (!b) return 0;
  void *q = vcall<void *>(b, 0x4c);
  float v0, v1;
  __builtin_memcpy(&v0, &v[0], 4);
  __builtin_memcpy(&v1, &v[1], 4);
  u32 r0 = ext_5003d0((u8 *)q, 0);
  ext_500360((u8 *)r0, v0);
  u32 r1 = ext_5003d0((u8 *)q, 1);
  ext_500360((u8 *)r1, v1);
  u32 r2 = ext_5003d0((u8 *)q, 2);
  ext_5002f0((u8 *)r2, v[2]);
  return (u32)b;
}
PCREG(5515f0, fn5515f0);
