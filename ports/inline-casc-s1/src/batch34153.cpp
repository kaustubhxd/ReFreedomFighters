// batch34153.cpp - cascade tier H, batch 34153: 0x4f6e00 (scale two floats into a vector), 0x467a40 (set a vector and advance a clamped float), 0x483a20 (forward then accumulate), 0x527360 (integrate and clamp).
#include "ff.h"

extern "C" void FASTCALL ext_451890(u32 ecx, u32 edx, u32 f);   // ecx/edx + one stack argument, ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static __m128 ld_ss(u8 *p) { return _mm_set_ss(bitsf(rd32(p))); }
static void st_ss(u8 *p, __m128 v) { wr32(p, __builtin_bit_cast(u32, _mm_cvtss_f32(v))); }

// 0x4f6e00, thiscall(q, p) ret 8: p[0] = [this+0x9b] * constant 0x67a6ac; p[1] = [this+0x9f] * constant (read after the first store); p[2] = 0; then q[0..2] = p[0..2] (read back in order). All this-fields unaligned.
static void THISCALL fn4f6e00(u8 *self, u32 *q, u32 *p) {
  __m128 k = _mm_set_ss(G(float, 0x67a6ac));
  *(float *)p = _mm_cvtss_f32(_mm_mul_ss(ld_ss(self + 0x9b), k));
  __m128 y = _mm_mul_ss(ld_ss(self + 0x9f), k);
  u32 e = p[0];
  p[2] = 0;
  *(float *)(p + 1) = _mm_cvtss_f32(y);
  q[0] = e;
  q[1] = p[1];
  q[2] = p[2];
}
PCREG(4f6e00, fn4f6e00);

// 0x467a40, thiscall(v) ret 4: unaligned [this+0x1ba], [+0x1be], [+0x1c2] = v[0..2]; t = ([[0x70039c]+0x48] * constant 0x67da1c) * 2 + [this+0x1c6]; [this+0x1c6] = t, or 1.0 when t is above the constant at 0x678858.
static void THISCALL fn467a40(u8 *self, u32 *v) {
  wr32(self + 0x1ba, v[0]);
  wr32(self + 0x1be, v[1]);
  wr32(self + 0x1c2, v[2]);
  __m128 t = _mm_mul_ss(_mm_set_ss(*(float *)(G(u8 *, 0x70039c) + 0x48)), _mm_set_ss(G(float, 0x67da1c)));
  t = _mm_add_ss(t, t);
  t = _mm_add_ss(t, ld_ss(self + 0x1c6));
  st_ss(self + 0x1c6, t);
  if (_mm_comigt_ss(t, _mm_set_ss(G(float, 0x678858)))) wr32(self + 0x1c6, 0x3f800000);
}
PCREG(467a40, fn467a40);

// 0x483a20, thiscall(a, b) ret 8: this->slot0x80(a, b); then ext_451890(b, a + 0xc, [this+0x451] (unaligned float bits)) (ecx = b, edx = a + 0xc). Returns nothing useful.
static void THISCALL fn483a20(u8 *self, u32 a, u32 b) {
  vcall<void>(self, 0x80, a, b);
  ext_451890(b, a + 0xc, rd32(self + 0x451));
}
PCREG(483a20, fn483a20);

// 0x527360, thiscall plain: f = [this+0xc]; t = [[0x70039c]+0x48] * f + [this+0x10]; [this+0x10] = t. When f > 0: lim = unaligned [this+0x21]; when t > lim: [this+0xc] = 0, [this+0x10] = lim.
// When f < 0: lim = unaligned [this+0x1d]; when lim > t: [this+0xc] = 0, [this+0x10] = lim.
static void THISCALL fn527360(u8 *self) {
  __m128 f = _mm_set_ss(*(float *)(self + 0xc));
  __m128 zero = _mm_setzero_ps();
  __m128 t = _mm_add_ss(_mm_mul_ss(_mm_set_ss(*(float *)(G(u8 *, 0x70039c) + 0x48)), f), _mm_set_ss(*(float *)(self + 0x10)));
  *(float *)(self + 0x10) = _mm_cvtss_f32(t);
  __m128 lim;
  if (_mm_comigt_ss(f, zero)) {
    lim = ld_ss(self + 0x21);
    if (!_mm_comigt_ss(t, lim)) return;
  } else if (_mm_comigt_ss(zero, f)) {
    lim = ld_ss(self + 0x1d);
    if (!_mm_comigt_ss(lim, t)) return;
  } else {
    return;
  }
  *(u32 *)(self + 0xc) = 0;
  *(float *)(self + 0x10) = _mm_cvtss_f32(lim);
}
PCREG(527360, fn527360);
