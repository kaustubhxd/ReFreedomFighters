// batch34149.cpp - cascade tier H, batch 34149: 0x5247e0 (absolute difference), 0x598e10 (forward a float), 0x5d0c30 (store int over constant once), 0x516040 (accumulate scaled float).
#include "ff.h"

extern "C" u32 THISCALL ext_5eab20(void *self, u32 a, u32 b, u32 f);   // ret 0xc

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static __m128 ld_ss(u8 *p) { return _mm_set_ss(bitsf(rd32(p))); }
static void st_ss(u8 *p, __m128 v) { wr32(p, __builtin_bit_cast(u32, _mm_cvtss_f32(v))); }

// 0x5247e0, thiscall plain: d = *[this+0x18] - *[this+0x1c] (floats); [this+8] = 0; [this] = [this+4] = float(double(d) & mask at 0x67cd50) (the absolute value when the mask clears the sign).
static void THISCALL fn5247e0(u8 *self) {
  float *a = *(float **)(self + 0x18);
  float *b = *(float **)(self + 0x1c);
  __m128 d = _mm_sub_ss(_mm_set_ss(*a), _mm_set_ss(*b));
  *(u32 *)(self + 8) = 0;
  __m128d x = _mm_and_pd(_mm_cvtps_pd(d), _mm_loadu_pd((const double *)0x67cd50));
  float r = _mm_cvtss_f32(_mm_cvtpd_ps(x));
  *(float *)self = r;
  *(float *)(self + 4) = r;
}
PCREG(5247e0, fn5247e0);

// 0x598e10, thiscall(a, b, f) ret 0xc: returns ext_5eab20(unaligned [this+0x22d7], a, b, f).
static u32 THISCALL fn598e10(u8 *self, u32 a, u32 b, u32 f) { return ext_5eab20((void *)rd32(self + 0x22d7), a, b, f); }
PCREG(598e10, fn598e10);

// 0x5d0c30, thiscall(i) ret 4: when byte [this+0xb30] is zero: unaligned float [this+0xb27] = (float)(int)i / constant at 0x67af20 and the byte is set to 1.
static void THISCALL fn5d0c30(u8 *self, s32 i) {
  if (self[0xb30]) return;
  __m128 v = _mm_div_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(i)), _mm_set_ss(G(float, 0x67af20)));
  self[0xb30] = 1;
  st_ss(self + 0xb27, v);
}
PCREG(5d0c30, fn5d0c30);

// 0x516040, thiscall(f) ret 4: t = f * constant 0x679544; unaligned floats [this+0x41] = (t + t) + [this+0x41]; [this+0x55] = t + [this+0x55].
static void THISCALL fn516040(u8 *self, u32 f) {
  __m128 t = _mm_mul_ss(_mm_set_ss(bitsf(f)), _mm_set_ss(G(float, 0x679544)));
  __m128 x0 = _mm_add_ss(t, t);
  __m128 x1 = _mm_add_ss(t, ld_ss(self + 0x55));
  x0 = _mm_add_ss(x0, ld_ss(self + 0x41));
  st_ss(self + 0x55, x1);
  st_ss(self + 0x41, x0);
}
PCREG(516040, fn516040);
