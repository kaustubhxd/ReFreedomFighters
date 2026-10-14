// batch32106.cpp - cascade h2 (): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" s32 VECTORCALL ext_633910(float f);               // CRT float-to-int helper, argument in XMM0, result in EAX
extern "C" void FASTCALL ext_633654(u32 cookie);             // /GS check
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                // thiscall, plain ret
extern "C" float THISCALL ext_4e5e80(u8 *self);              // thiscall, plain ret, float in st0
typedef u32 (STDCALL *s2_t)(u32, u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

// 0x527060, thiscall(float a, float b, float c) ret 0xc, returns byte [this+0x18]: [this+0x18] = 0; [this+0xc] = [this+0x25]; [this+0x19] = 0; [this+4] = a; [this+8] = b;
// [this+0x10] = ([this+0x1d] > c) ? [this+0x1d] : min([this+0x21], c) (minss order); a > b -> [this+0x14] = -1.0f; b > a -> +1.0f; else [this+0x18] = 1 and [this+0x19] = 2 (unaligned fields).
static u8 THISCALL fn527060(u8 *self, float a, float b, float c) {
  float x0 = rdf(self + 0x1d);
  bool gt = x0 > c;
  u32 e = *(u32 *)(self + 0x25);
  self[0x18] = 0;
  *(u32 *)(self + 0xc) = e;
  wr32(self + 0x19, 0);
  *(float *)(self + 4) = a;
  *(float *)(self + 8) = b;
  *(float *)(self + 0x10) = c;
  if (!gt) {
    float y = rdf(self + 0x21);
    x0 = (y < c) ? y : c;
  }
  *(float *)(self + 0x10) = x0;
  if (a > b) {
    *(u32 *)(self + 0x14) = 0xbf800000;
    return self[0x18];
  }
  if (b > a) {
    *(u32 *)(self + 0x14) = 0x3f800000;
    return self[0x18];
  }
  self[0x18] = 1;
  u8 r = self[0x18];
  wr32(self + 0x19, 2);
  return r;
}
PCREG(527060, fn527060);

// 0x610ea0, thiscall(float a, b, c, d) ret 0x10 (/GS frame): block = {ftoi(a), ftoi(b), ftoi(c), ftoi(d), 0, 0x3f800000}; o = unaligned [this+0x1377]; slot 0xa0 of o called stdcall with (o, &block); /GS check.
static void THISCALL fn610ea0(u8 *self, float a, float b, float c, float d) {
  u32 blk[6];
  blk[0] = (u32)ext_633910(a);
  blk[1] = (u32)ext_633910(b);
  blk[2] = (u32)ext_633910(c);
  blk[3] = (u32)ext_633910(d);
  u32 o = rd32(self + 0x1377);
  blk[4] = 0;
  blk[5] = 0x3f800000;
  (*(s2_t *)(*(u8 **)o + 0xa0))(o, (u32)blk);
  ext_633654(0);
}
PCREG(610ea0, fn610ea0);

// 0x4c79f0, thiscall(a) ret 4, returns true: [this+0x54] = 0x4e5e60(a); [this+0x48], [this+0x50] = two successive floats of 0x4e5e80(a); bytes [this+0x58], [this+0x59] = (0x4e5e60(a) != 0) twice;
// [this+0x5e] and [this+0x62] = two further 0x4e5e60(a) results (unaligned).
static bool THISCALL fn4c79f0(u8 *self, u8 *a) {
  *(u32 *)(self + 0x54) = ext_4e5e60(a);
  *(float *)(self + 0x48) = ext_4e5e80(a);
  *(float *)(self + 0x50) = ext_4e5e80(a);
  self[0x58] = ext_4e5e60(a) != 0;
  self[0x59] = ext_4e5e60(a) != 0;
  wr32(self + 0x5e, ext_4e5e60(a));
  wr32(self + 0x62, ext_4e5e60(a));
  return true;
}
PCREG(4c79f0, fn4c79f0);
