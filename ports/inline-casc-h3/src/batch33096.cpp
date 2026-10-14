// batch33096.cpp - h3 () batch 33096: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" void THISCALL ext_59a580(u8 *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_45f960(u8 *self, u8 *obj);               // ret 4

// 0x594e30: thiscall(a) ret 4: [this+0x953]==a and (int)([this+0x957]*1024) >= [sys+0x40] -> return; [this+0x852]: p=[[sys+0x9b]+0xae4]->slot 0(0x6a67e8, 0x6acea8); 0x59a580([this+0x852], r, 0xffffff00, 1); [this+0x953]=a; [this+0x957]=(float)([sys+0x40]+0xc00)/1024
static void THISCALL fn594e30(u8 *self, u32 a) {
  if (R32(self + 0x953) == a) {
    float x = bitsf(R32(self + 0x957)) * 1024.0f;
    s32 k = _mm_cvttss_si32(_mm_set_ss(x));
    if (k >= *(s32 *)(SYS + 0x40)) return;
  }
  u32 w = R32(self + 0x852);
  if (w != 0) {
    u8 *tab = *(u8 **)(SYS + 0x9b);
    u8 *p = *(u8 **)(tab + 0xae4);
    u32 r = vcall<u32>(p, 0, 0x6a67e8u, 0x6acea8u);
    ext_59a580(*(u8 **)(self + 0x852), r, 0xffffff00u, 1u);
  }
  W32(self + 0x953, a);
  s32 t = (s32)(*(u32 *)(SYS + 0x40) + 0xc00u);
  float f = (float)t * 0.0009765625f;
  W32(self + 0x957, fbits(f));
}
PCREG(594e30, fn594e30);

// 0x5d8f40: thiscall(obj) ret 4, returns true: 0x45f960(this, obj); obj->slot 0x3c([+0x28]); slot 0x44([+0x2c],[+0x30],[+0x3c],[+0x40]) one call each; slot 0x4c(float [+0x38])
static u8 THISCALL fn5d8f40(u8 *self, u8 *obj) {
  ext_45f960(self, obj);
  vcall<u32>(obj, 0x3c, *(u32 *)(self + 0x28));
  vcall<u32>(obj, 0x44, *(u32 *)(self + 0x2c));
  vcall<u32>(obj, 0x44, *(u32 *)(self + 0x30));
  vcall<u32>(obj, 0x44, *(u32 *)(self + 0x3c));
  vcall<u32>(obj, 0x44, *(u32 *)(self + 0x40));
  vcall<u32>(obj, 0x4c, *(u32 *)(self + 0x38));
  return 1;
}
PCREG(5d8f40, fn5d8f40);

// 0x5245c0: thiscall(float a) ret 4: v = f4*f2*(a*a) + (f0+f0-f1) clamped to f0 +- 1.5; diff = f3 - v; [4]=f0; [0]=v; diff >= 1/8192: [0]=f3; [4] = diff*0.5 + [4]
static void THISCALL fn5245c0(u8 *self, u32 ab) {
  float a = bitsf(ab);
  float f0 = *(float *)self, f1 = *(float *)(self + 4), f2 = *(float *)(self + 8), f3 = *(float *)(self + 0xc), f4 = *(float *)(self + 0x10);
  float s = f0 + f0;
  float k = f4 * f2;
  float aa = a * a;
  s = s - f1;
  k = k * aa;
  float v = k + s;
  float d = v - f0;
  if (d > 1.5f) v = f0 + 1.5f;
  else if (-1.5f > d) v = f0 - 1.5f;
  float diff = f3 - v;
  *(float *)(self + 4) = f0;
  *(float *)self = v;
  if (diff >= 0.0001220703125f) {
    float h = diff * 0.5f;
    *(float *)self = f3;
    float n = h + *(float *)(self + 4);
    *(float *)(self + 4) = n;
  }
}
PCREG(5245c0, fn5245c0);
