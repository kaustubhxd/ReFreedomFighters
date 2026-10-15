// batch32094.cpp - cascade h2 (Sonnet): eight tier H (float / SSE) functions, second batch.
#include "ff.h"

extern "C" u32 THISCALL ext_5ef950(u8 *self, u32 a, u32 b, float c);   // thiscall ret 0xc, one float stack argument
extern "C" void THISCALL ext_471680(u8 *self);                         // thiscall, plain ret
extern "C" void THISCALL ext_515930(u8 *self, float a, u32 b);         // thiscall ret 8
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                          // thiscall, plain ret
extern "C" float THISCALL ext_4e5e80(u8 *self);                        // thiscall, plain ret, result in st0

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

// 0x5244d0, thiscall(float a, ignored) ret 8: [this+0xc] = a unless a == the float constant at 0x67cd48 (ordered); NaN a stores.
static void THISCALL fn5244d0(u8 *self, float a, u32) {
  if (!(a == G(float, 0x67cd48))) *(float *)(self + 0xc) = a;
}
PCREG(5244d0, fn5244d0);

// 0x467ca0, thiscall no args, returns float: o = engine table slot 0x60 with unaligned [this+0x13b]; o != 0 -> float [o+0x70], else 0.0.
static float THISCALL fn467ca0(u8 *self) {
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(tbl, 0x60, rd32(self + 0x13b));
  if (!o) return 0.0f;
  return *(float *)(o + 0x70);
}
PCREG(467ca0, fn467ca0);

// 0x529cd0, thiscall(float a) ret 4: t = [this+0x14] * a; [this+0x35] = [this+8] - t; [this+0x39] = t + [this+8] (unaligned floats).
static void THISCALL fn529cd0(u8 *self, float a) {
  float t = *(float *)(self + 0x14) * a;
  float c = *(float *)(self + 8);
  wrf(self + 0x35, c - t);
  wrf(self + 0x39, t + c);
}
PCREG(529cd0, fn529cd0);

// 0x5aaa50, thiscall(a, b, float c) ret 0xc: returns 0x5ef950([this+0x64c], a, b, c).
static u32 THISCALL fn5aaa50(u8 *self, u32 a, u32 b, float c) {
  return ext_5ef950(*(u8 **)(self + 0x64c), a, b, c);
}
PCREG(5aaa50, fn5aaa50);

// 0x46e3b0, thiscall no args: t = [[0x70039c]+0x48] + [this+0x56] (unaligned float); [this+0x56] = t; t >= [this+0x4c] (ordered) -> 0x471680(this), [this+0x56] = 0.
static void THISCALL fn46e3b0(u8 *self) {
  float t = *(float *)(G(u8 *, 0x70039c) + 0x48) + rdf(self + 0x56);
  float limit = *(float *)(self + 0x4c);
  wrf(self + 0x56, t);
  if (t >= limit) {
    ext_471680(self);
    wr32(self + 0x56, 0);
  }
}
PCREG(46e3b0, fn46e3b0);

// 0x535750, stdcall(float a) ret 4, returns x87 value: constant 0x67d164 > a (ordered) -> 0.0; else a * the constant at 0x6a24d4 (exact in double).
static double STDCALL fn535750(float a) {
  if (G(float, 0x67d164) > a) return 0.0;
  return (double)a * (double)G(float, 0x6a24d4);
}
PCREG(535750, fn535750);

// 0x521930, thiscall no args: 0x515930(this, float [this+0x2f8], byte [this+0x2fc]); [this+0x2f0] = -1.0f; [this+0x2f4] = 4; [this+0x216] = 0 (unaligned).
static void THISCALL fn521930(u8 *self) {
  ext_515930(self, *(float *)(self + 0x2f8), (u32)self[0x2fc]);
  *(u32 *)(self + 0x2f0) = 0xbf800000;
  *(u32 *)(self + 0x2f4) = 4;
  wr32(self + 0x216, 0);
}
PCREG(521930, fn521930);

// 0x5d3ac0, thiscall(a) ret 4: [this+0x4c] = 0x4e5e60(a); [this+0x50] = float result (st0) of 0x4e5e80(a).
static void THISCALL fn5d3ac0(u8 *self, u8 *a) {
  *(u32 *)(self + 0x4c) = ext_4e5e60(a);
  *(float *)(self + 0x50) = ext_4e5e80(a);
}
PCREG(5d3ac0, fn5d3ac0);
