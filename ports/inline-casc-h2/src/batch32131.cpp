// batch32131.cpp - cascade h2 (Sonnet): three tier H (float / x87) functions.
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);                              // /GS check
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                          // thiscall ret 4
extern "C" void FASTCALL ext_43e920(void *out, const void *a, const void *b); // x87 vector subtract: out = a - b

// 0x503670, thiscall(p) ret 4 (/GS frame): m = [this+0xc]; slot 0x80 of m with (&a[9 dwords], &v[3 dwords]); x2, x1, x0 = 0x5003d0([p+4], 2), (.., 1), (.., 0); v = {float [x0], float [x1], float [x2]};
// slot 0x7c of m with (&a, &v); /GS check.
static void THISCALL fn503670(u8 *self, u8 *p) {
  u32 a[9];
  float v[3];
  vcall<void>(*(void **)(self + 0xc), 0x80, (u32)a, (u32)v);
  u32 x2 = ext_5003d0(*(u8 **)(p + 4), 2);
  u32 x1 = ext_5003d0(*(u8 **)(p + 4), 1);
  u32 x0 = ext_5003d0(*(u8 **)(p + 4), 0);
  v[0] = *(float *)x0;
  v[1] = *(float *)x1;
  v[2] = *(float *)x2;
  vcall<void>(*(void **)(self + 0xc), 0x7c, (u32)a, (u32)v);
  ext_633654(0);
}
PCREG(503670, fn503670);

// 0x5ec670, thiscall(float f, int idx) ret 8: idx == -1 -> for each i < [this+0x3e] (unsigned) the function calls itself with (f, i); (then continues with idx = -1 like any other index);
// o = [[this+0x62] + idx*4]; [o+8] = [o+0xc] = f; [[[this+0x3a]+4] + idx*40 + 0x1c] = (float)(unsigned)[this+0x52] * f; [... + 0x20] = (float)(unsigned)[this+0x56] * f; byte [this+0xa6] = 1.
static void THISCALL fn5ec670(u8 *self, float f, s32 idx) {
  if (idx == -1) {
    for (u32 i = 0; i < *(u32 *)(self + 0x3e); i++) fn5ec670(self, f, (s32)i);
  }
  u8 *o = *(u8 **)(*(u8 **)(self + 0x62) + (s32)idx * 4);
  *(float *)(o + 8) = f;
  *(float *)(o + 0xc) = f;
  u32 k1 = *(u32 *)(self + 0x52);
  double d1 = (double)(s32)k1 + G(double, 0x680aa0 + 8 * (k1 >> 31));
  u8 *base1 = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
  *(float *)(base1 + (s32)idx * 40 + 0x1c) = (float)d1 * f;
  u32 k2 = *(u32 *)(self + 0x56);
  double d2 = (double)(s32)k2 + G(double, 0x680aa0 + 8 * (k2 >> 31));
  u8 *base2 = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
  *(float *)(base2 + (s32)idx * 40 + 0x20) = (float)d2 * f;
  self[0xa6] = 1;
}
PCREG(5ec670, fn5ec670);

// 0x4a3710, thiscall no args: v = (this+0x58) - (this+0x4c) stored at this+0x64 (0x43e920, exe code); all three components ordered-equal to 0 -> done; otherwise len = sqrt(x*x + y*y + z*z) in double (x87 53-bit),
// inv = 1.0 / len, and each component becomes (float)((double)c * inv).
static void THISCALL fn4a3710(u8 *self) {
  float *v = (float *)(self + 0x64);
  ext_43e920(self + 0x64, self + 0x58, self + 0x4c);
  if (v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f) return;
  double x = (double)v[0], y = (double)v[1], z = (double)v[2];
  double s = x * x;
  s = s + y * y;
  s = s + z * z;
  double len;
  __asm__("sqrtsd %1, %0" : "=x"(len) : "x"(s));
  double inv = 1.0 / len;
  v[0] = (float)(x * inv);
  v[1] = (float)(y * inv);
  v[2] = (float)(z * inv);
}
PCREG(4a3710, fn4a3710);
