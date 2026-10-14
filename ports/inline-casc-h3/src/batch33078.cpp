// batch33078.cpp - h3 () batch 33078: tier H float/SSE functions
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(u8 *self);                                     // float in st0
extern "C" void THISCALL ext_467410(u8 *self, u32 p, u32 f, u32 a, u32 b, u32 c, u32 d);   // ret 0x18
extern "C" void THISCALL ext_52c270(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);   // ret 0x1c

#define SYS (*(u8 **)0x70039c)

// 0x5d6e60: thiscall(a) ret 4: [this+0x48] = a->0x4e5e80() (float from st0); [this+0x4c] = a->0x4e5e80()
static void THISCALL fn5d6e60(u8 *self, u8 *a) {
  float x = ext_4e5e80(a);
  *(float *)(self + 0x48) = x;
  float y = ext_4e5e80(a);
  *(float *)(self + 0x4c) = y;
}
PCREG(5d6e60, fn5d6e60);

// 0x4752b0: thiscall(f, v0..v3) ret 0x14: 0x467410(this+0x353, this, f, v0..v3)
static void THISCALL fn4752b0(u8 *self, u32 f, u32 a, u32 b, u32 c, u32 d) { ext_467410(self + 0x353, (u32)self, f, a, b, c, d); }
PCREG(4752b0, fn4752b0);

// 0x4e0940: fastcall(out, in1, in2) ret 4: out[i] = in1[i] * in2[i] for i < 3 (mulss)
static void __attribute__((fastcall)) fn4e0940(float *out, float *in1, float *in2) {
  out[0] = in1[0] * in2[0];
  out[1] = in1[1] * in2[1];
  out[2] = in1[2] * in2[2];
}
PCREG(4e0940, fn4e0940);

// 0x52c240: thiscall(a1..a7) ret 0x1c: straight pass-through to 0x52c270
static void THISCALL fn52c240(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) { ext_52c270(self, a1, a2, a3, a4, a5, a6, a7); }
PCREG(52c240, fn52c240);

// 0x475710: thiscall(a, f, v0..v3) ret 0x18: this->slot 0x4ac(0, a, f, v0..v3)
static void THISCALL fn475710(u8 *self, u32 a, u32 f, u32 v0, u32 v1, u32 v2, u32 v3) { vcall<u32>(self, 0x4ac, 0u, a, f, v0, v1, v2, v3); }
PCREG(475710, fn475710);

// 0x5138c0: thiscall(f, b) ret 8: [this+0x5c]->slot 0(f, b); word [this+0xcc]=0
static void THISCALL fn5138c0(u8 *self, u32 f, u32 b) {
  vcall<u32>(*(u8 **)(self + 0x5c), 0, f, b);
  *(u16 *)(self + 0xcc) = 0;
}
PCREG(5138c0, fn5138c0);

// 0x5243a0: thiscall float: x=[this+0x10]; x > 0.0 ? 1.0/x (x87 fdiv, double precision) : 9.99999968e37
static double THISCALL fn5243a0(u8 *self) {
  float x = *(float *)(self + 0x10);
  if (x > 0.0f) return 1.0 / (double)x;
  return (double)bitsf(0x7e967699);
}
PCREG(5243a0, fn5243a0);

// 0x5c9130: thiscall(a, float f) ret 8: [this+0x88]=a; [this+0x8c] = (float)([[sysobj]+0x40] - cvttss2si(f * -1024.0f)) * (1/1024)
static void THISCALL fn5c9130(u8 *self, u32 a, float f) {
  float t = f * -1024.0f;
  *(u32 *)(self + 0x88) = a;
  s32 e;
  __asm__("cvttss2si %1, %0" : "=r"(e) : "x"(t));
  s32 v = (s32)(*(u32 *)(SYS + 0x40) - (u32)e);
  *(float *)(self + 0x8c) = (float)v * 0.0009765625f;
}
PCREG(5c9130, fn5c9130);
