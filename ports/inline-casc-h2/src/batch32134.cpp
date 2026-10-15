// batch32134.cpp - cascade h2 (Sonnet): four tier H (float / SSE) functions.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

extern "C" void FASTCALL ext_633654(u32 cookie);                                                          // /GS check
extern "C" void THISCALL ext_5de090(u8 *self, u32 *buf);                                                  // thiscall ret 4
extern "C" void THISCALL ext_460100(u8 *self, u8 *a, u8 *b, u8 *c, u8 *d, float f);                       // thiscall ret 0x14

// 0x5ddde0, thiscall(a, unused) ret 8 (/GS frame), returns 0: only when (u16)a == word [0x71439c] and s = [[0x7003b8]+0x2c4d] != 0:
// buf = {0, 0, 0, [[0x70039c]+0x40], 16 bytes at this+0x48, [this+0x58], [this+0x5c]} (10 dwords); slot 0x84 of [this+0x44] with &buf; 0x5de090(s, &buf).
static u32 THISCALL fn5ddde0(u8 *self, u32 a, u32 unused) {
  if ((u16)a == G(u16, 0x71439c)) {
    u8 *s = (u8 *)rd32(G(u8 *, 0x7003b8) + 0x2c4d);
    if (s) {
      u32 buf[10];
      buf[0] = 0;
      buf[1] = 0;
      buf[2] = 0;
      buf[3] = rd32(G(u8 *, 0x70039c) + 0x40);
      for (int i = 0; i < 4; i++) buf[4 + i] = rd32(self + 0x48 + 4 * i);
      buf[8] = rd32(self + 0x58);
      buf[9] = rd32(self + 0x5c);
      vcall<void>(*(void **)(self + 0x44), 0x84, (u32)buf);
      ext_5de090(s, buf);
    }
  }
  ext_633654(0);
  return 0;
}
PCREG(5ddde0, fn5ddde0);

// 0x4609f0, thiscall(a, b, c, float f) ret 0x10: [this+0xc] = a; [this+0x10] = c; return if c == 0, a == 0 or b == 0; [this+4] = 0; [this+8] = 0x7e967699;
// do { 0x460100(a + off, b + 0x24*i + {0, 0xc, 0x18, 0x24}, f) (off = 0x38*i); [this+4] = float [[this+0xc] + off + 0x34] + [this+4];
// if ([this+8] > float [[this+0xc] + off + 0x34]) [this+8] = that; i++ } while (i != [this+0x10]).
static void THISCALL fn4609f0(u8 *self, u8 *a, u8 *b, u32 c, float f) {
  wr32(self + 0x10, c);
  wr32(self + 0xc, (u32)a);
  if (c == 0 || a == 0) return;
  if (b == 0) return;
  wr32(self + 4, 0);
  wr32(self + 8, 0x7e967699);
  u32 i = 0;
  u32 off = 0;
  u8 *base = a;
  u8 *p = b;
  do {
    ext_460100(base + off, p, p + 0xc, p + 0x18, p + 0x24, f);
    base = (u8 *)rd32(self + 0xc);
    float x = rdf(base + off + 0x34);
    wrf(self + 4, x + rdf(self + 4));
    float x2 = rdf(base + off + 0x34);
    if (rdf(self + 8) > x2) wrf(self + 8, x2);
    i++;
    off += 0x38;
    p += 0x24;
  } while (i != rd32(self + 0x10));
}
PCREG(4609f0, fn4609f0);

// 0x4945c0, thiscall(idx, unused, float f) ret 0xc (/GS frame), returns float [this+0xbc5] (st0), or 0.0 when idx == 6:
// table T = {0, 0.2f, 0.4f, 0.8f, 0.9f, 0.95f, 1.0f}; x = (T[idx+1] - T[idx]) * f + T[idx]; if (x > [this+0xbc5] + 0.002f) { [this+0xbc5] = x;
// if x is not ordered-equal to 0.0f: c = [[0x70039c]+0x190f]; if c: slot 0x184 of c with (x, 0xff7f0000, 0xff7f0000) }.
static float THISCALL fn4945c0(u8 *self, u32 idx, u32 unused, float f) {
  if (idx == 6) {
    ext_633654(0);
    return 0.0f;
  }
  float T[7];
  T[0] = 0.0f; T[1] = bitsf(0x3e4ccccd); T[2] = bitsf(0x3ecccccd); T[3] = bitsf(0x3f4ccccd);
  T[4] = bitsf(0x3f666666); T[5] = bitsf(0x3f733333); T[6] = bitsf(0x3f800000);
  float lo = T[idx];
  float x = (T[idx + 1] - lo) * f + lo;
  float lim = rdf(self + 0xbc5) + 0.002f;
  if (x > lim) {
    wrf(self + 0xbc5, x);
    if (!(x == 0.0f)) {
      void *c = *(void **)(G(u8 *, 0x70039c) + 0x190f);
      if (c) vcall<void>(c, 0x184, x, 0xff7f0000u, 0xff7f0000u);
    }
  }
  float r = rdf(self + 0xbc5);
  ext_633654(0);
  return r;
}
PCREG(4945c0, fn4945c0);

// 0x4c2610, thiscall(o) ret 4, returns true (al): [this+4] &= ~0x40; on o: slot 0x60(byte [this+0x1b9]), slot 0x60(byte [this+0x1ba]), slot 0x4c(float [this+0x1c7]),
// slot 0x3c([this+0x1cb]), slot 0x3c([this+0x1cf]), slot 0x40(word [this+0x1b1]), (0x1b3), (0x1b5), (0x1b7).
static u8 THISCALL fn4c2610(u8 *self, void *o) {
  wr32(self + 4, rd32(self + 4) & 0xffffffbf);
  vcall<void>(o, 0x60, (u32)self[0x1b9]);
  vcall<void>(o, 0x60, (u32)self[0x1ba]);
  vcall<void>(o, 0x4c, rdf(self + 0x1c7));
  vcall<void>(o, 0x3c, rd32(self + 0x1cb));
  vcall<void>(o, 0x3c, rd32(self + 0x1cf));
  vcall<void>(o, 0x40, (u32)(u16)(self[0x1b1] | (self[0x1b2] << 8)));
  vcall<void>(o, 0x40, (u32)(u16)(self[0x1b3] | (self[0x1b4] << 8)));
  vcall<void>(o, 0x40, (u32)(u16)(self[0x1b5] | (self[0x1b6] << 8)));
  vcall<void>(o, 0x40, (u32)(u16)(self[0x1b7] | (self[0x1b8] << 8)));
  return 1;
}
PCREG(4c2610, fn4c2610);
