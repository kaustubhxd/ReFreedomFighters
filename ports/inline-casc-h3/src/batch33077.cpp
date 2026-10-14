// batch33077.cpp - h3 () batch 33077: tier H float/SSE functions
#include "ff.h"

extern "C" void THISCALL ext_525e20(u8 *self, float f, u32 b);     // ret 8
extern "C" void THISCALL ext_65f1e0(u8 *self, u32 a, float f);     // ret 8

// 0x5184d0: thiscall(float f, b) ret 8: 0x525e20(this+0x2d8, f, b)
static void THISCALL fn5184d0(u8 *self, float f, u32 b) { ext_525e20(self + 0x2d8, f, b); }
PCREG(5184d0, fn5184d0);

// 0x63f070: thiscall(a, float f) ret 8: 0x65f1e0(this+0x8270, a, f)
static void THISCALL fn63f070(u8 *self, u32 a, float f) { ext_65f1e0(self + 0x8270, a, f); }
PCREG(63f070, fn63f070);

// 0x4dc5d0: thiscall(f1,f2,f3) ret 0xc: [0x30]=f1,[0x34]=f2,[0x38]=f3,[0x3c]|=0x100000
static void THISCALL fn4dc5d0(u8 *self, float a, float b, float c) {
  *(float *)(self + 0x30) = a;
  *(float *)(self + 0x34) = b;
  *(float *)(self + 0x38) = c;
  *(u32 *)(self + 0x3c) |= 0x100000;
}
PCREG(4dc5d0, fn4dc5d0);

// 0x537860: stdcall(p) ret 4 float: p ? [p+0xc] : 0.0
static float STDCALL fn537860(u8 *p) { return p ? *(float *)(p + 0xc) : 0.0f; }
PCREG(537860, fn537860);

// 0x5d0ba0: thiscall(int a) ret 4: if !byte [this+0xb30]: [this+0xb27] = (float)a / -127.0f; byte [this+0xb30] = 1
static void THISCALL fn5d0ba0(u8 *self, s32 a) {
  if (self[0xb30] == 0) {
    *(float *)(self + 0xb27) = (float)a / -127.0f;
    self[0xb30] = 1;
  }
}
PCREG(5d0ba0, fn5d0ba0);

// 0x487a50: stdcall(p) ret 4 float: (float)(s32)[p+0x5c] / (float)(s32)[p+0x6c]
static float STDCALL fn487a50(u8 *p) {
  float x = (float)*(s32 *)(p + 0x5c);
  float y = (float)*(s32 *)(p + 0x6c);
  return x / y;
}
PCREG(487a50, fn487a50);

// 0x5ea840: thiscall(float f) ret 4: [this+0x1d13] = (0 > f) ? 0 : f (NaN is stored)
static void THISCALL fn5ea840(u8 *self, float f) {
  if (0.0f > f) *(u32 *)(self + 0x1d13) = 0;
  else *(float *)(self + 0x1d13) = f;
}
PCREG(5ea840, fn5ea840);

// 0x523180: thiscall: slot 8([this+0x57], [this+0x5b]) (float bit patterns); [this+0x39]=1; byte [this+0x46]=0
static void THISCALL fn523180(u8 *self) {
  u32 a = *(u32 *)(self + 0x57);
  u32 b = *(u32 *)(self + 0x5b);
  vcall<u32>(self, 8, a, b);
  *(u32 *)(self + 0x39) = 1;
  self[0x46] = 0;
}
PCREG(523180, fn523180);
