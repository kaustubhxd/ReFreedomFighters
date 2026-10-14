// batch32136.cpp - cascade h2 (): two tier H (float / SSE) functions.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

extern "C" void THISCALL ext_516730(u8 *self, float f);    // thiscall ret 4
extern "C" void THISCALL ext_52a1e0(u8 *self);             // thiscall

// 0x5291f0, thiscall(float f) ret 4: [this+0x21ad] = 0x43c80000, [this+0x21b1] = 0x40060a92, [this+0x21b5] = 0x3b03126f (unaligned);
// for i in 0 .. [this+0x8d] (signed, re-read each pass): 0x516730(this+0x95 + 0xde*i, f); 0x52a1e0(this+0xe75 + 0x133*i);
// for j in 0 .. [this+0x91]: 0x516730(this+0x785 + 0xde*j, f); 0x52a1e0(this+0x180d + 0x133*j).
static void THISCALL fn5291f0(u8 *self, float f) {
  s32 i = 0;
  wr32(self + 0x21ad, 0x43c80000);
  wr32(self + 0x21b1, 0x40060a92);
  wr32(self + 0x21b5, 0x3b03126f);
  if ((s32)rd32(self + 0x8d) > 0) {
    u8 *p = self + 0x95;
    u8 *q = self + 0xe75;
    do {
      ext_516730(p, f);
      ext_52a1e0(q);
      i++;
      p += 0xde;
      q += 0x133;
    } while (i < (s32)rd32(self + 0x8d));
  }
  i = 0;
  if ((s32)rd32(self + 0x91) > 0) {
    u8 *p = self + 0x785;
    u8 *q = self + 0x180d;
    do {
      ext_516730(p, f);
      ext_52a1e0(q);
      i++;
      p += 0xde;
      q += 0x133;
    } while (i < (s32)rd32(self + 0x91));
  }
}
PCREG(5291f0, fn5291f0);

// 0x5d7ef0, thiscall(idx, src) ret 8: array of 12-byte elements at this+4, count in [this]. idx >= count: element idx = *src (12 bytes), count++.
// Otherwise elements idx .. count-1 move up by one (highest first), then element idx = *src (read after the move), count++.
static void THISCALL fn5d7ef0(u8 *self, u32 idx, const u8 *src) {
  u32 count = rd32(self);
  if (idx >= count) {
    u8 *e = self + 4 + 12 * idx;
    for (int k = 0; k < 12; k++) e[k] = src[k];
    wr32(self, rd32(self) + 1);
    return;
  }
  u32 j = count - 1;
  while (j != idx) {
    u8 *from = self + 4 + 12 * j;
    for (int k = 0; k < 12; k++) from[12 + k] = from[k];
    j--;
  }
  u8 *from = self + 4 + 12 * idx;
  for (int k = 0; k < 12; k++) from[12 + k] = from[k];
  for (int k = 0; k < 12; k++) from[k] = src[k];
  wr32(self, rd32(self) + 1);
}
PCREG(5d7ef0, fn5d7ef0);

static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }
static inline u16 rd16(const u8 *p) { return p[0] | (p[1] << 8); }
static inline void wr16(u8 *p, u16 v) { p[0] = v; p[1] = v >> 8; }

// 0x4bf2b0, thiscall(w, p) ret 8, returns 0: (u16)w == word [this+0x48]: r = slot 0x1c0 of the engine with (0x693c40, 0xd11) (float on x87); only when [this+0x66] >= r (ordered):
// if p != 0: [this+0x52] = (float)p[0]; [this+0x56] = (float)p[1]; [this+0x5e] = (float)p[2] (ints) and return unless [this+0x56] != 0 and [this+0x56] > [this+0x52];
// then word [this+0x4c] = 1; dword [this+0x4e] = 0; slot 0x64 of this with 0x10.
// else (u16)w == word [this+0x4a]: byte [this+0x4c] = 0; slot 0x68 of this with (0x10, 0).
static u32 THISCALL fn4bf2b0(u8 *self, u32 w, const u32 *p) {
  u16 ax = (u16)w;
  if (ax == rd16(self + 0x48)) {
    float r = vcall<float>(G(void *, 0x70039c), 0x1c0, 0x693c40u, 0xd11u);
    float lim = rdf(self + 0x66);
    if (lim >= r) {
      if (p) {
        wrf(self + 0x52, (float)(s32)p[0]);
        wrf(self + 0x56, (float)(s32)p[1]);
        wrf(self + 0x5e, (float)(s32)p[2]);
        float y = rdf(self + 0x56);
        if (y == 0.0f) return 0;
        if (!(y > rdf(self + 0x52))) return 0;
      }
      wr16(self + 0x4c, 1);
      wr32(self + 0x4e, 0);
      vcall<void>(self, 0x64, 0x10u);
    }
    return 0;
  }
  if (ax == rd16(self + 0x4a)) {
    self[0x4c] = 0;
    vcall<void>(self, 0x68, 0x10u, 0u);
  }
  return 0;
}
PCREG(4bf2b0, fn4bf2b0);
