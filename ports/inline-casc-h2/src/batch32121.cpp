// batch32121.cpp - cascade h2 (Sonnet): tier H (float / SSE) functions, batch 32121.
#include "ff.h"

extern "C" void THISCALL ext_5a5730(u8 *self, u32 a, u32 b);              // thiscall ret 8
extern "C" u32 THISCALL ext_5a56d0(u8 *self, u8 *a, u8 *b, u32 c);        // thiscall ret 0xc
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                      // thiscall ret 4
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);                      // thiscall ret 4

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

// 0x5cd5c0, thiscall no args: unaligned dwords [this+0xb1f], [0xb23], [0xb27], [0xb2b] are cleared when the bytes [0xb33], [0xb34], [0xb30], [0xb2f] are zero; byte [this+0xdd8] != 0 clears all four;
// then four (dead) |x| < 0 checks (a double compare of 0 > |x| never holds); finally words at 0xb33 and 0xb2f are cleared.
static void THISCALL fn5cd5c0(u8 *self) {
  if (!self[0xb33]) wr32(self + 0xb1f, 0);
  if (!self[0xb34]) wr32(self + 0xb23, 0);
  if (!self[0xb30]) wr32(self + 0xb27, 0);
  if (!self[0xb2f]) wr32(self + 0xb2b, 0);
  if (self[0xdd8]) {
    wr32(self + 0xb1f, 0);
    wr32(self + 0xb23, 0);
    wr32(self + 0xb2b, 0);
    wr32(self + 0xb27, 0);
  }
  static const u32 offs[4] = {0xb23, 0xb1f, 0xb27, 0xb2b};
  for (int i = 0; i < 4; i++) {
    double x = (double)rdf(self + offs[i]);
    u32 parts[2];
    __builtin_memcpy(parts, &x, 8);
    parts[1] &= 0x7fffffffu;
    double ax;
    __builtin_memcpy(&ax, parts, 8);
    if (0.0 > ax) wr32(self + offs[i], 0);
  }
  self[0xb33] = 0; self[0xb34] = 0;
  self[0xb2f] = 0; self[0xb30] = 0;
}
PCREG(5cd5c0, fn5cd5c0);

// 0x5b7d40, thiscall(p) ret 4, bool: f = [this+4] < 0 -> q = [this+0x24]: q != 0 -> 0x5a5730(p, q, [this]), [this+0x24] = 0; returns false; else byte [this+0x28] set -> the same release and clear the byte;
// [this+0x24] == 0 -> [this+0x24] = 0x5a56d0(p, this+0xc, this+0x18, [this]); [this+4] -= [[0x70039c]+0x48]; true.
static bool THISCALL fn5b7d40(u8 *self, u8 *p) {
  if (0.0f > *(float *)(self + 4)) {
    u32 q = *(u32 *)(self + 0x24);
    if (q) {
      ext_5a5730(p, q, *(u32 *)self);
      *(u32 *)(self + 0x24) = 0;
    }
    return false;
  }
  if (self[0x28]) {
    u32 q = *(u32 *)(self + 0x24);
    if (q) {
      ext_5a5730(p, q, *(u32 *)self);
      *(u32 *)(self + 0x24) = 0;
    }
    self[0x28] = 0;
  }
  if (*(u32 *)(self + 0x24) == 0) {
    u32 r = ext_5a56d0(p, self + 0xc, self + 0x18, *(u32 *)self);
    *(u32 *)(self + 0x24) = r;
  }
  *(float *)(self + 4) = *(float *)(self + 4) - *(float *)(G(u8 *, 0x70039c) + 0x48);
  return true;
}
PCREG(5b7d40, fn5b7d40);

// 0x504c00, thiscall(p) ret 4, returns the last callee's eax: a, b, c = 0x5003d0([p+4], 2), (.., 1), (.., 0); t = [[[0x70039c]+0x9b]+0x44] + [c]; r = slot 0x5c of this with (t, float [b], float [a]);
// returns 0x5002f0(0x5003d0([p+8], 0), r).
static u32 THISCALL fn504c00(u8 *self, u8 *p) {
  u32 a = ext_5003d0(*(u8 **)(p + 4), 2);
  u32 b = ext_5003d0(*(u8 **)(p + 4), 1);
  u32 c = ext_5003d0(*(u8 **)(p + 4), 0);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  float fa = *(float *)a;
  float fb = *(float *)b;
  u32 t = *(u32 *)(tbl + 0x44) + *(u32 *)c;
  u32 r = vcall<u32>(self, 0x5c, t, fb, fa);
  u32 q = ext_5003d0(*(u8 **)(p + 8), 0);
  return ext_5002f0((u8 *)q, r);
}
PCREG(504c00, fn504c00);
