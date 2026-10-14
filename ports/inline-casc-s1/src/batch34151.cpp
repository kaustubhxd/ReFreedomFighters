// batch34151.cpp - cascade tier H, batch 34151: 0x4e5e80 (float getter with a side call), 0x4850c0 (resync a value with the engine), 0x5b7b90 (init a record), 0x524980 (set two pointers and an absolute difference), 0x5d1350 (store int over constant with a flag).
#include "ff.h"

extern "C" float THISCALL ext_4e5f90(void *self);   // plain ret, float in st0
extern "C" void THISCALL ext_4e6420(void *self);    // plain ret

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4e5e80, thiscall plain, returns a float in st0: x = ext_4e5f90(this); ext_4e6420(this); returns x.
static float THISCALL fn4e5e80(u8 *self) {
  volatile float x = ext_4e5f90(self);
  ext_4e6420(self);
  return x;
}
PCREG(4e5e80, fn4e5e80);

// 0x4850c0, thiscall plain: n = cvttss2si([this+0xc] * constant at 0x678620); when n != [[0x70039c]+0x40]: [this+4] = 0 and [this+0x10] = (float)([[0x70039c]+0x40] + 0x1000) * constant at 0x6785e4.
static void THISCALL fn4850c0(u8 *self) {
  __m128 t = _mm_mul_ss(_mm_set_ss(*(float *)(self + 0xc)), _mm_set_ss(G(float, 0x678620)));
  u8 *eng = G(u8 *, 0x70039c);
  s32 n = _mm_cvttss_si32(t);
  if (n == *(s32 *)(eng + 0x40)) return;
  *(u32 *)(self + 4) = 0;
  s32 m = *(s32 *)(G(u8 *, 0x70039c) + 0x40) + 0x1000;
  __m128 v = _mm_mul_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(m)), _mm_set_ss(G(float, 0x6785e4)));
  *(float *)(self + 0x10) = _mm_cvtss_f32(v);
}
PCREG(4850c0, fn4850c0);

// 0x5b7b90, thiscall(a, f) ret 8: [this] = a; [this+8] = f; [+4], [+0x24], [+0x14], [+0x10], [+0xc] = 0; byte [+0x28] = 0. Returns this.
static u8 *THISCALL fn5b7b90(u8 *self, u32 a, u32 f) {
  *(u32 *)self = a;
  *(u32 *)(self + 8) = f;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0xc) = 0;
  self[0x28] = 0;
  return self;
}
PCREG(5b7b90, fn5b7b90);

// 0x524980, thiscall(pa, pb) ret 8: as 0x5247e0 with the two pointers taken from the arguments and stored at +0x18 and +0x1c first.
static void THISCALL fn524980(u8 *self, float *pa, float *pb) {
  *(float **)(self + 0x18) = pa;
  *(float **)(self + 0x1c) = pb;
  __m128 d = _mm_sub_ss(_mm_set_ss(*pa), _mm_set_ss(*pb));
  *(u32 *)(self + 8) = 0;
  __m128d x = _mm_and_pd(_mm_cvtps_pd(d), _mm_loadu_pd((const double *)0x67cd50));
  float r = _mm_cvtss_f32(_mm_cvtpd_ps(x));
  *(float *)self = r;
  *(float *)(self + 4) = r;
}
PCREG(524980, fn524980);

// 0x5d1350, thiscall(i) ret 4: nothing for 0; else byte [+0xb33] = 1, byte [+0xa70] = (old unaligned float [+0xb1f] >= constant 0x679540), and [+0xb1f] = (float)(int)i / constant 0x67af30.
static void THISCALL fn5d1350(u8 *self, s32 i) {
  if (!i) return;
  __m128 old = _mm_set_ss(bitsf(rd32(self + 0xb1f)));
  self[0xb33] = 1;
  self[0xa70] = _mm_comige_ss(old, _mm_set_ss(G(float, 0x679540)));
  __m128 v = _mm_div_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(i)), _mm_set_ss(G(float, 0x67af30)));
  wr32(self + 0xb1f, __builtin_bit_cast(u32, _mm_cvtss_f32(v)));
}
PCREG(5d1350, fn5d1350);
