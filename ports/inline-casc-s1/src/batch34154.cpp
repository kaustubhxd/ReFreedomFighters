// batch34154.cpp - cascade tier H, batch 34154: 0x658c40 (event dispatch), 0x477620 (clamped acos), 0x4f21f0 (set a mode flag), 0x59a650 (look up and scale), 0x445ff0 (copy two ints as floats), 0x486430 (stamp a time and look up).
#include "ff.h"

extern "C" void THISCALL ext_4f2240(void *self, u32 a, u32 b);      // ret 8
extern "C" u32 THISCALL ext_59a5e0(void *self, u32 a);               // ret 4
extern "C" u32 THISCALL ext_4869e0(void *self, u32 a);               // ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x658c40, thiscall(code, p) ret 8: code 6 -> this->slot0x1e8(*(float bits *)p) (result returned); code 9 -> this->slot0x30(p) (result returned); otherwise returns code.
static u32 THISCALL fn658c40(u8 *self, u32 code, u32 *p) {
  if (code == 6) return vcall<u32>(self, 0x1e8, *p);
  if (code == 9) return vcall<u32>(self, 0x30, (u32)p);
  return code;
}
PCREG(658c40, fn658c40);

// 0x477620, stdcall(f) ret 4, returns a float in st0: 0.0 when f > constant 0x678858 (1.0); the constant at 0x67da18 (pi) when 0x67af2c (-1.0) > f; otherwise (float)acos((double)f) through the CRT import [0x676354].
static float STDCALL fn477620(u32 fb) {
  float f = bitsf(fb);
  if (_mm_comigt_ss(_mm_set_ss(f), _mm_set_ss(G(float, 0x678858)))) return 0.0f;
  if (_mm_comigt_ss(_mm_set_ss(G(float, 0x67af2c)), _mm_set_ss(f))) return G(float, 0x67da18);
  double d = _mm_cvtsd_f64(_mm_cvtps_pd(_mm_set_ss(f)));
  double r;
  asm volatile("movsd %[d], %%xmm0\n\tcall *0x676354\n\tmovsd %%xmm0, %[r]" : [r] "=m"(r) : [d] "m"(d)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return (float)r;
}
PCREG(477620, fn477620);

// 0x4f21f0, thiscall(b) ret 4: nothing when (u8)b equals byte [this+0x6a]; else [this+0x6a] = b; when non-zero: byte [this+0x68] = 0xfe and unaligned float [this+0x6b] = (float)(int)[[0x70039c]+0x40] * constant 0x6785e4;
// when zero: ext_4f2240(this, 0xfe, [this+0x64]).
static void THISCALL fn4f21f0(u8 *self, u32 b) {
  u8 al = (u8)b;
  if (al == self[0x6a]) return;
  self[0x6a] = al;
  if (al) {
    self[0x68] = 0xfe;
    s32 n = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
    __m128 v = _mm_mul_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(n)), _mm_set_ss(G(float, 0x6785e4)));
    wr32(self + 0x6b, __builtin_bit_cast(u32, _mm_cvtss_f32(v)));
    return;
  }
  ext_4f2240(self, 0xfe, *(u32 *)(self + 0x64));
}
PCREG(4f21f0, fn4f21f0);

// 0x59a650, thiscall(a, f) ret 8: r = ext_59a5e0(this, a); unaligned [this+0xd9] = r; o = [[0x70039c]+0x9b]->slot0x60(r); when o: float [o+0x78] = f * constant 0x67d9fc; returns [this+0xd9].
static u32 THISCALL fn59a650(u8 *self, u32 a, u32 f) {
  u32 r = ext_59a5e0(self, a);
  wr32(self + 0xd9, r);
  u8 *o = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x60, r);
  if (o) *(float *)(o + 0x78) = _mm_cvtss_f32(_mm_mul_ss(_mm_set_ss(bitsf(f)), _mm_set_ss(G(float, 0x67d9fc))));
  return rd32(self + 0xd9);
}
PCREG(59a650, fn59a650);

// 0x445ff0, thiscall(s) ret 4: [this+0x50] = (float)(int)s->slot0xd8(); [this+0x54] = (float)(int)s->slot0xdc().
static void THISCALL fn445ff0(u8 *self, u8 *s) {
  s32 a = (s32)vcall<u32>(s, 0xd8);
  *(float *)(self + 0x50) = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(a)));
  s32 b = (s32)vcall<u32>(s, 0xdc);
  *(float *)(self + 0x54) = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(b)));
}
PCREG(445ff0, fn445ff0);

// 0x486430, thiscall plain, returns true (al): o = [this+0xc]->slot0x10(); [this+0x2c] = (float)([[0x70039c]+0x40] + 0x133) * constant 0x6785e4; r = o->slot0x350(); [this+0x28] = ext_4869e0(this, r).
static u32 THISCALL fn486430(u8 *self) {
  u8 *o = vcall<u8 *>(*(u8 **)(self + 0xc), 0x10);
  s32 n = *(s32 *)(G(u8 *, 0x70039c) + 0x40) + 0x133;
  *(float *)(self + 0x2c) = _mm_cvtss_f32(_mm_mul_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(n)), _mm_set_ss(G(float, 0x6785e4))));
  u32 r = vcall<u32>(o, 0x350);
  *(u32 *)(self + 0x28) = ext_4869e0(self, r);
  return 1;
}
PCREG(486430, fn486430);
