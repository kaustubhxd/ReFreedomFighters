// batch6221.cpp - unclaimed-62 claim 14 (slice 2): six leaves.
//   0x5edc20  thiscall, three arguments (ret 0xc; the third is popped and unused): if this+0xeb != a or this+0xf3 != b then this+0xdb = 0,
//             this+0xeb = a, this+0xf3 = b, this+0xa6 = 1
//   0x594ed0  thiscall, one argument (ret 4): this+0x417 & 0xe000000 non-zero -> nothing; otherwise |= 0x400 for a set flag byte, &= 0xfffffbff otherwise
//   0x547730  thiscall, two arguments (ret 8): idx, src: at this+0xf base b, dst = b + idx*0x34: dst+0x18, +0x1c, +0x20 = src[0..2]
//   0x465470  thiscall, no arguments, returns ST0: x*x + y*y + z*z for the three floats at this (summed left to right)
//   0x5aef10  thiscall, no arguments: zeroes the sixteen dwords at this+0 .. this+0x3c
//   0x5b7ce0  thiscall, six arguments (ret 0x18): six dwords at this+0xc .. this+0x20 (floats by raw bits), this+0x28 = 1 byte
#include "ff.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn5edc20(u8 *self, u32 a, u32 b, u32 c) {
  (void)c;
  if (rd32u(self + 0xeb) == a && rd32u(self + 0xf3) == b) return;
  wr32u(self + 0xdb, 0);
  wr32u(self + 0xeb, a);
  wr32u(self + 0xf3, b);
  self[0xa6] = 1;
}

static void THISCALL fn594ed0(u8 *self, u32 flag) {
  u32 v = rd32u(self + 0x417);
  if (v & 0xe000000u) return;
  if ((u8)flag) v |= 0x400u;
  else v &= 0xfffffbffu;
  wr32u(self + 0x417, v);
}

static void THISCALL fn547730(u8 *self, u32 idx, u8 *src) {
  u32 base = rd32u(self + 0xf);
  u8 *dst = (u8 *)(base + idx * 0x34);
  wr32u(dst + 0x18, rd32u(src));
  wr32u(dst + 0x1c, rd32u(src + 4));
  wr32u(dst + 0x20, rd32u(src + 8));
}

static float THISCALL fn465470(u8 *self) {
  float x = rdf(self), y = rdf(self + 4), z = rdf(self + 8);
  float xx = x * x;
  float yy = y * y;
  float zz = z * z;
  float s = xx + yy;
  s = s + zz;
  return s;
}

static void THISCALL fn5aef10(u8 *self) {
  for (u32 k = 0; k < 16; k++) wr32u(self + 4 * k, 0);
}

static void THISCALL fn5b7ce0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
  wr32u(self + 0xc, a);
  wr32u(self + 0x10, b);
  wr32u(self + 0x14, c);
  wr32u(self + 0x18, d);
  wr32u(self + 0x1c, e);
  wr32u(self + 0x20, f);
  self[0x28] = 1;
}

PCREG(5edc20, fn5edc20);
PCREG(594ed0, fn594ed0);
PCREG(547730, fn547730);
PCREG(465470, fn465470);
PCREG(5aef10, fn5aef10);
PCREG(5b7ce0, fn5b7ce0);
