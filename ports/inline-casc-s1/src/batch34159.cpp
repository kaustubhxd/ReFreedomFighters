// batch34159.cpp - cascade tier H, batch 34159: 0x4f84b0 (range to fraction), 0x51aaf0 (forward a cell pair), 0x52cf60 (reset two blocks from exe constants).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);          // ret 4
extern "C" void THISCALL ext_52cea0(void *self, u32 a);         // ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4f84b0, thiscall(a, b) ret 8, returns the low byte: lo = unaligned [this+0x8f], hi = unaligned [this+0x93] (signed); false when a < lo or a > hi; else unaligned float [this+0x9f] = (float)(a - lo) / (float)(hi - lo), this->slot0x374(b), true.
static u32 THISCALL fn4f84b0(u8 *self, s32 a, u32 b) {
  s32 lo = (s32)rd32(self + 0x8f);
  if (a < lo) return 0;
  s32 hi = (s32)rd32(self + 0x93);
  if (a > hi) return 0;
  __m128 x = _mm_cvtepi32_ps(_mm_cvtsi32_si128(a - lo));
  __m128 d = _mm_cvtepi32_ps(_mm_cvtsi32_si128(hi - lo));
  wr32(self + 0x9f, __builtin_bit_cast(u32, _mm_cvtss_f32(_mm_div_ss(x, d))));
  vcall<void>(self, 0x374, b);
  return 1;
}
PCREG(4f84b0, fn4f84b0);

// 0x51aaf0, thiscall(p) ret 4: c1 = ext_5003d0([p+4], 1), c0 = ext_5003d0([p+4], 0); [this+0x18]->slot0x360(*c0 (float bits), *c1 != 0).
static void THISCALL fn51aaf0(u8 *self, u8 *p) {
  u32 *c1 = (u32 *)ext_5003d0(*(u8 **)(p + 4), 1);
  u32 *c0 = (u32 *)ext_5003d0(*(u8 **)(p + 4), 0);
  u32 flag = *c1 != 0;
  vcall<void>(*(u8 **)(self + 0x18), 0x360, *c0, flag);
}
PCREG(51aaf0, fn51aaf0);

// 0x52cf60, thiscall(a) ret 4, returns this: ext_52cea0(this, a); ext_52cea0(this + 0x51, a); then copies exe constant blocks: 0x6a1568 (16 bytes) -> +0x51, 0x6a1578 (8) -> +0x61, 0x6a1580 (2) -> +0x69, 0x6a1582 (1) -> +0x6b,
// 0x6a154c (16) -> +0, 0x6a155c (8) -> +0x10, 0x6a1564 (1) -> +0x18.
static u8 *THISCALL fn52cf60(u8 *self, u32 a) {
  ext_52cea0(self, a);
  ext_52cea0(self + 0x51, a);
  const u8 *k;
  k = (const u8 *)0x6a1568; for (int i = 0; i < 16; i++) self[0x51 + i] = k[i];
  k = (const u8 *)0x6a1578; for (int i = 0; i < 8; i++) self[0x61 + i] = k[i];
  k = (const u8 *)0x6a1580; self[0x69] = k[0]; self[0x6a] = k[1];
  self[0x6b] = *(const u8 *)0x6a1582;
  k = (const u8 *)0x6a154c; for (int i = 0; i < 16; i++) self[i] = k[i];
  k = (const u8 *)0x6a155c; for (int i = 0; i < 8; i++) self[0x10 + i] = k[i];
  self[0x18] = *(const u8 *)0x6a1564;
  return self;
}
PCREG(52cf60, fn52cf60);
