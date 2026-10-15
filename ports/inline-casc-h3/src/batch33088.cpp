// batch33088.cpp - h3 (Sonnet) batch 33088: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)
#define LOGOBJ (*(u8 **)0x700390)

typedef void (*log3_t)(u8 *, u32, u32);

extern "C" float THISCALL ext_4e5e80(u8 *self);                      // float in st0

// 0x4c99a0: thiscall(a, stream) ret 8: six floats from e80 into [this+0x48..0x5c]; [this+0x44]->slot 0x80(this+0x6c, this+0x60)
static void THISCALL fn4c99a0(u8 *self, u32 a, u8 *s) {
  (void)a;
  float f;
  f = ext_4e5e80(s); *(float *)(self + 0x48) = f;
  f = ext_4e5e80(s); *(float *)(self + 0x4c) = f;
  f = ext_4e5e80(s); *(float *)(self + 0x50) = f;
  f = ext_4e5e80(s); *(float *)(self + 0x54) = f;
  f = ext_4e5e80(s); *(float *)(self + 0x58) = f;
  f = ext_4e5e80(s); *(float *)(self + 0x5c) = f;
  vcall<u32>(*(u8 **)(self + 0x44), 0x80, (u32)(self + 0x6c), (u32)(self + 0x60));
}
PCREG(4c99a0, fn4c99a0);

// 0x45bda0: thiscall(i, float f) ret 8: x=[this+4i+0x258]; v = x > 60.0 ? (x-60)/40*0.5 + f : f; r=[sys+0x190f]->slot 0x20(); r->slot 0x44([this+0x40][i], min(1.0, v))
static void THISCALL fn45bda0(u8 *self, u32 i, u32 fb) {
  float x = *(float *)(self + i * 4u + 0x258);
  float v;
  if (x > 60.0f) {
    float t = x - 60.0f;
    t = t / 40.0f;
    t = t * 0.5f;
    v = t + bitsf(fb);
  } else {
    v = bitsf(fb);
  }
  u8 *o = *(u8 **)(SYS + 0x190f);
  u8 *r = vcall<u8 *>(o, 0x20);
  float m = (1.0f < v) ? 1.0f : v;
  u32 h = *(u32 *)(*(u8 **)(self + 0x40) + i * 4u);
  vcall<u32>(r, 0x44, h, fbits(m));
}
PCREG(45bda0, fn45bda0);

// 0x5dd800: thiscall(u16 a, u32 b) ret 8: (u16)a != [this+0x48] -> 0; log chain (0x6b6f64,0x24)/(r,0x6b6fac,b); b-1 <= 199: [sys+0x1b40]=(float)b*0.01 else 1.0; return 0
static u32 THISCALL fn5dd800(u8 *self, u32 a, u32 b) {
  if ((u16)a != *(u16 *)(self + 0x48)) return 0;
  u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x6b6f64u, 0x24u);
  (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x6b6fac, b);
  if (b - 1u <= 0xc7u) {
    float f = (float)(s32)b * 0.01f;
    *(float *)(SYS + 0x1b40) = f;
    return 0;
  }
  *(u32 *)(SYS + 0x1b40) = 0x3f800000;
  return 0;
}
PCREG(5dd800, fn5dd800);
