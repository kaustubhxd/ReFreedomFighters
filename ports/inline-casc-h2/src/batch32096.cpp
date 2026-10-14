// batch32096.cpp - cascade h2 (): eight tier H (float / SSE) functions, fourth batch.
#include "ff.h"

extern "C" u32 THISCALL ext_572720(u8 *self);            // thiscall, plain ret (tail jump target)
extern "C" u32 THISCALL ext_4dcd70(u8 *self, u32 a);     // thiscall ret 4
extern "C" float THISCALL ext_4e5e80(u8 *self);          // thiscall, plain ret, float in st0
extern "C" u32 THISCALL ext_4e5e60(u8 *self);            // thiscall, plain ret

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }
static inline s32 trunc_ss(float f) { s32 t; __asm__("cvttss2si %1, %0" : "=r"(t) : "m"(f)); return t; }

// 0x4edeb0, thiscall(p) ret 4: [this+0x10] = p; [this+0xc] = [p+0xc]; floats [p..p+8) copied to this; [this+0x14] = [p+0x18] + p.
static void THISCALL fn4edeb0(u8 *self, u8 *p) {
  *(u8 **)(self + 0x10) = p;
  *(u32 *)(self + 0xc) = *(u32 *)(p + 0xc);
  *(u32 *)(self + 0) = *(u32 *)(p + 0);
  *(u32 *)(self + 4) = *(u32 *)(p + 4);
  *(u32 *)(self + 8) = *(u32 *)(p + 8);
  *(u32 *)(self + 0x14) = *(u32 *)(p + 0x18) + (u32)p;
}
PCREG(4edeb0, fn4edeb0);

// 0x572df0, thiscall no args: byte [this+0x86c] != 0 and (t > (int)([this+0x50]*K) or t > (int)([this+0x58]*K)) with t = [[0x70039c]+0x40] and K = float at 0x678620 -> tail jump to 0x572720(this).
static void THISCALL fn572df0(u8 *self) {
  if (!self[0x86c]) return;
  s32 t = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
  float k = G(float, 0x678620);
  if (t > trunc_ss(*(float *)(self + 0x50) * k)) { ext_572720(self); return; }
  if (t > trunc_ss(*(float *)(self + 0x58) * k)) ext_572720(self);
}
PCREG(572df0, fn572df0);

// 0x467c40, thiscall no args, returns o: o = engine table slot 0x60 with unaligned [this+0x13b]; o != 0 -> byte [o+0xec] = 1; [o+0xed] = (float)(int)[[0x70039c]+0x40] * K(0x6785e4);
// [o+0xf1] = [o+0x88]; [o+0xf5] = [o+0x88] / K2(0x67a284) (unaligned stores).
static u8 *THISCALL fn467c40(u8 *self) {
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(tbl, 0x60, rd32(self + 0x13b));
  if (!o) return 0;
  o[0xec] = 1;
  float t = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40);
  wrf(o + 0xed, t * G(float, 0x6785e4));
  float w = *(float *)(o + 0x88);
  wrf(o + 0xf1, w);
  wrf(o + 0xf5, w / G(float, 0x67a284));
  return o;
}
PCREG(467c40, fn467c40);

// 0x52a220, thiscall(float a) ret 4: s = [this+0x61] + [this+0x44] + a; [this+8] = (lo=[this+0x28] > s) ? lo : ((hi=[this+0x2c] < s) ? hi : s); tail jump to 0x4dcd70([[this+0x18]+8], this+4).
static u32 THISCALL fn52a220(u8 *self, float a) {
  float s = rdf(self + 0x61) + *(float *)(self + 0x44) + a;
  float lo = *(float *)(self + 0x28);
  float v;
  if (lo > s) {
    v = lo;
  } else {
    float hi = *(float *)(self + 0x2c);
    v = (hi < s) ? hi : s;
  }
  *(float *)(self + 8) = v;
  return ext_4dcd70(*(u8 **)(*(u8 **)(self + 0x18) + 8), (u32)(self + 4));
}
PCREG(52a220, fn52a220);

// 0x655ca0, stdcall(p, q, r) ret 0xc, bool true: q[0..2] = 0; v = byte [p+0xc] <= 2 ? float [p+0x1c] : 0.0; r[0..2] = v.
static bool STDCALL fn655ca0(u8 *p, u32 *q, float *r) {
  q[0] = 0; q[1] = 0; q[2] = 0;
  float v = 0.0f;
  if (p[0xc] <= 2) v = *(float *)(p + 0x1c);
  r[0] = v; r[1] = v; r[2] = v;
  return true;
}
PCREG(655ca0, fn655ca0);

// 0x47f680, register ABI (ecx = A, edx = B), bool: A[0..2] == B[0..2] as ordered float compares.
static bool FASTCALL fn47f680(float *A, float *B) {
  return A[0] == B[0] && A[1] == B[1] && A[2] == B[2];
}
PCREG(47f680, fn47f680);

// 0x5a40e0, thiscall(a) ret 4: [this+0x113] = float st0 of 0x4e5e80(a); [this+0x117] = 0x4e5e60(a); [this+0x11f] = 0x4e5e60(a) (unaligned).
static void THISCALL fn5a40e0(u8 *self, u8 *a) {
  wrf(self + 0x113, ext_4e5e80(a));
  wr32(self + 0x117, ext_4e5e60(a));
  wr32(self + 0x11f, ext_4e5e60(a));
}
PCREG(5a40e0, fn5a40e0);

// 0x475940, thiscall(a, b, float c, d0, d1, d2, d3) ret 0x1c: slot 0x1c of the object embedded at this+0x2e7 (unaligned vtable) with (this, a, b, c, d0, d1, d2, d3).
static u32 THISCALL fn475940(u8 *self, u32 a, u32 b, float c, u32 d0, u32 d1, u32 d2, u32 d3) {
  return vcall<u32>(self + 0x2e7, 0x1c, (u32)self, a, b, c, d0, d1, d2, d3);
}
PCREG(475940, fn475940);
