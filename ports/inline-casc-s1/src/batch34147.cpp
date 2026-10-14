// batch34147.cpp - cascade tier H, batch 34147: 0x467700 (float below a limit), 0x524370 (float range test), 0x5243f0 (set a 2D vector), 0x658c20 (store a float in the engine object).
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x467700, thiscall, returns the low byte: [this+0x35] (unaligned float) below the constant at 0x6785d0 (comiss + setb: also true for NaN).
static u32 THISCALL fn467700(u8 *self) {
  __m128 a = _mm_set_ss(bitsf(rd32(self + 0x35)));
  __m128 b = _mm_set_ss(G(float, 0x6785d0));
  return !_mm_comige_ss(a, b);
}
PCREG(467700, fn467700);

// 0x524370, thiscall: ([this+0xc] + constant at 0x67a284) >= [this]  (comiss + setae: false for NaN). Returns 0 or 1.
static u32 THISCALL fn524370(u8 *self) {
  __m128 a = _mm_add_ss(_mm_set_ss(*(float *)(self + 0xc)), _mm_set_ss(G(float, 0x67a284)));
  return _mm_comige_ss(a, _mm_set_ss(*(float *)self));
}
PCREG(524370, fn524370);

// 0x5243f0, thiscall(f) ret 4: [this] = [this+4] = f; [this+8] = 0. (float bits copied)
static void THISCALL fn5243f0(u8 *self, u32 f) {
  *(u32 *)self = f;
  *(u32 *)(self + 4) = f;
  *(u32 *)(self + 8) = 0;
}
PCREG(5243f0, fn5243f0);

// 0x658c20, stdcall(f) ret 4: stores the float bits at the unaligned address [[0x70039c]+0x1aa3] + 0x91.
static void STDCALL fn658c20(u32 f) {
  u8 *p = (u8 *)rd32(G(u8 *, 0x70039c) + 0x1aa3) + 0x91;
  p[0] = f; p[1] = f >> 8; p[2] = f >> 16; p[3] = f >> 24;
}
PCREG(658c20, fn658c20);
