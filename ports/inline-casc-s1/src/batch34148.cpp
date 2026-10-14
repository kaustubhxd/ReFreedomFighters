// batch34148.cpp - cascade tier H, batch 34148: 0x5d1190 (store int / constant), 0x514430 and 0x5213d0 (forward a float argument), 0x466800 (make a vector and tail-call a slot).
#include "ff.h"

extern "C" u32 THISCALL ext_523cc0(void *self, u32 a, u32 f);   // ret 8
extern "C" u32 THISCALL ext_5289d0(void *self, u32 f, u32 b);   // ret 8

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5d1190, thiscall(i) ret 4: [this+0xb2b] (unaligned float) = (float)(int)i / constant at 0x67af20; byte [this+0xb2f] = 1.
static void THISCALL fn5d1190(u8 *self, s32 i) {
  float v = _mm_cvtss_f32(_mm_div_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(i)), _mm_set_ss(G(float, 0x67af20))));
  self[0xb2f] = 1;
  u32 b = __builtin_bit_cast(u32, v);
  self[0xb2b] = b; self[0xb2c] = b >> 8; self[0xb2d] = b >> 16; self[0xb2e] = b >> 24;
}
PCREG(5d1190, fn5d1190);

// 0x514430, thiscall(a, f) ret 8: returns ext_523cc0([this+0x5c], a, f) (the float is passed as its bits).
static u32 THISCALL fn514430(u8 *self, u32 a, u32 f) { return ext_523cc0(*(u8 **)(self + 0x5c), a, f); }
PCREG(514430, fn514430);

// 0x5213d0, thiscall(f, b) ret 8: returns ext_5289d0(this + 0x2fd, f, b).
static u32 THISCALL fn5213d0(u8 *self, u32 f, u32 b) { return ext_5289d0(self + 0x2fd, f, b); }
PCREG(5213d0, fn5213d0);

// 0x466800, thiscall(out) ret 4: out = {0, unaligned float at [this+0x1ca], 0}; then tail-jumps to slot 0x84 of this with out. Returns its result.
static u32 THISCALL fn466800(u8 *self, u32 *out) {
  u32 y = rd32(self + 0x1ca);
  out[0] = 0;
  out[1] = y;
  out[2] = 0;
  return vcall<u32>(self, 0x84, (u32)out);
}
PCREG(466800, fn466800);
