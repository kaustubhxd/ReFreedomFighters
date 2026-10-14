// batch41003.cpp - cascade t2 (): tier H float functions 0x52d3f0 and 0x4bf110.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline u32 rd16(const u8 *p) { return p[0] | (p[1] << 8); }
static inline void wr16(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

extern "C" double VECTORCALL ext_634d7c(double); // CRT sqrt thunk

// 0x52d3f0, thiscall(a1, p, a3, pt, a5, a6, a7) ret 0x1c, returns bool: *p == 0 -> 0. d = (int)pt - (int)[this+4..0xc]; s = (float)(dy*dy int) + (float)dx * (float)dx;
// r = sqrt((double)s) (CRT); w = (float)(r + (double)((float)|dz| * [this+0x20])); when [this+0x1c] > w (ordered): [this+0x1c] = w, [this+0x10..0x18] = pt, return 1; else 0.
static u32 THISCALL fn52d3f0(u8 *self, u32 a1, u32 *p, u32 a3, u32 *pt, u32 a5, u32 a6, u32 a7) {
  if (*p == 0) return 0;
  s32 dx = (s32)(pt[0] - rd32(self + 4));
  s32 dy = (s32)(pt[1] - rd32(self + 8));
  s32 dz = (s32)(pt[2] - rd32(self + 0xc));
  float fx = (float)dx;
  float fy = (float)(s32)((u32)dy * (u32)dy);
  fx = fx * fx;
  float s = fy + fx;
  double r = ext_634d7c((double)s);
  u32 az = (u32)dz;
  s32 ad = (s32)((az ^ (u32)((s32)az >> 31)) - (u32)((s32)az >> 31));
  float t = (float)ad * rdf(self + 0x20);
  float w = (float)(r + (double)t);
  if (rdf(self + 0x1c) > w) {
    wrf(self + 0x1c, w);
    wr32(self + 0x10, pt[0]);
    wr32(self + 0x14, pt[1]);
    wr32(self + 0x18, pt[2]);
    return 1;
  }
  return 0;
}
PCREG(52d3f0, fn52d3f0);

// 0x4bf110, thiscall(a, b) ret 8, returns 0: m = [this+0x44] (null -> 0). When (u16)a == [this+0x4c]: q = [m+0x18]; when !(q[0x40] & 8): slot 0x84 of this, [this+0x50] = 0.
// [this+0x71] != 0 -> [this+0x73] = 1. When [this+0x50] == 0: f = float (st0) of sys slot 0x1c0(0x693c40, 0xb6e); [this+0x6d] >= f (ordered): [this+0x51] = 0x1000101, [this+0x55] = 0, [this+0x61] = 0,
// [this+0x65] != 0 (or NaN) -> [[m+0x18]+0x84] = 0, then slot 0x64(0x10); else (flag set) [this+0x55] = 0, word [this+0x53] = 0x100, byte [this+0x51] = 1, slot 0x64(0x10).
// Then when (u16)a == word [this+0x4e]: [this+0x55] = 0, [this+0x5d] = 0, word [this+0x53] = 0x101.
static u32 THISCALL fn4bf110(u8 *self, u32 a, u32 b) {
  u8 *m = (u8 *)rd32(self + 0x44);
  if (!m) return 0;
  u32 di = a & 0xffff;
  if (di == rd16(self + 0x4c)) {
    u8 *q = (u8 *)rd32(m + 0x18);
    if (!(q[0x40] & 8)) {
      vcall<void>(self, 0x84);
      self[0x50] = 0;
    }
    if (self[0x71]) self[0x73] = 1;
    if (self[0x50] == 0) {
      float f = vcall<float>(G(void *, 0x70039c), 0x1c0, 0x693c40u, 0xb6eu);
      if (rdf(self + 0x6d) >= f) {
        wr32(self + 0x51, 0x1000101);
        wr32(self + 0x55, 0);
        wr32(self + 0x61, 0);
        if (!(rdf(self + 0x65) == 0.0f)) wr32((u8 *)rd32((u8 *)rd32(self + 0x44) + 0x18) + 0x84, 0);
        vcall<void>(self, 0x64, 0x10u);
      }
    } else {
      wr32(self + 0x55, 0);
      wr16(self + 0x53, 0x100);
      self[0x51] = 1;
      vcall<void>(self, 0x64, 0x10u);
    }
  }
  if (di == rd16(self + 0x4e)) {
    wr32(self + 0x55, 0);
    wr32(self + 0x5d, 0);
    wr16(self + 0x53, 0x101);
  }
  return 0;
}
PCREG(4bf110, fn4bf110);
