// batch33086.cpp - h3 () batch 33086: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

extern "C" u32 THISCALL ext_593f40(u8 *self, u32 a);               // ret 4
extern "C" u32 THISCALL ext_594040(u8 *self, u32 a, u32 b);        // ret 8
extern "C" u32 THISCALL ext_596ef0(u8 *self, u32 a, u32 b);        // ret 8

// 0x524540: thiscall(float a) ret 4: v = f4*f2*(a*a) + (f0+f0-f1); d = v-f0; d > 1.5: [4]=f0, [0]=f0+1.5; else [4]=f0, [0] = (-1.5 > d) ? f0-1.5 : v
static void THISCALL fn524540(u8 *self, u32 ab) {
  float a = bitsf(ab);
  float f0 = *(float *)self, f1 = *(float *)(self + 4), f2 = *(float *)(self + 8), f4 = *(float *)(self + 0x10);
  float k = f4 * f2;
  float aa = a * a;
  k = k * aa;
  float s = f0 + f0;
  s = s - f1;
  float v = k + s;
  float d = v - f0;
  if (d > 1.5f) {
    *(float *)(self + 4) = f0;
    *(float *)self = f0 + 1.5f;
    return;
  }
  if (-1.5f > d) v = f0 - 1.5f;
  *(float *)(self + 4) = f0;
  *(float *)self = v;
}
PCREG(524540, fn524540);

// 0x476240: thiscall no args: byte [0x56] set and bit 10 of [[[this+0x44]+8]+0x3c] clear: [this+0x52] = [sys+0x40] - (int)([this+0x48] * -1024.0) (unaligned); slot 0x64(0x10)
static void THISCALL fn476240(u8 *self) {
  if (self[0x56] == 0) return;
  u32 fl = *(u32 *)(*(u8 **)(*(u8 **)(self + 0x44) + 8) + 0x3c);
  if ((fl >> 10) & 1) return;
  s32 k = _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x48) * -1024.0f));
  u32 v = *(u32 *)(SYS + 0x40) - (u32)k;
  __builtin_memcpy(self + 0x52, &v, 4);
  vcall<u32>(self, 0x64, 0x10u);
}
PCREG(476240, fn476240);

// 0x597f00: thiscall no args: 0x593f40([this+0x1d0b], 0); r=(float)sys slot 0x1c0(0x6ad250, 0x380); [this+0xdd] = 0x594040([this+0x1d0b], r > 0.5 ? 0x13 : 0x15, 0); 0x596ef0(this, 3, 0)
static void THISCALL fn597f00(u8 *self) {
  ext_593f40(*(u8 **)(self + 0x1d0b), 0);
  float r = (float)vcall<double>(SYS, 0x1c0, 0x6ad250u, 0x380u);
  u32 which = r > 0.5f ? 0x13u : 0x15u;
  u32 res = ext_594040(*(u8 **)(self + 0x1d0b), which, 0);
  __builtin_memcpy(self + 0xdd, &res, 4);
  ext_596ef0(self, 3, 0);
}
PCREG(597f00, fn597f00);
