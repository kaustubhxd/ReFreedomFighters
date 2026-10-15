// batch49001.cpp - cascade u2 batch 49001: 0x5ecd80 (set up scale/offset from a view object, then call 0x5ec8b0 for each entry).
#include "ff.h"

typedef float __attribute__((aligned(1))) uf;
typedef int __attribute__((aligned(1))) ui;
typedef u32 __attribute__((aligned(1))) uu;
#define FL(p, o) (*(uf *)((u8 *)(p) + (o)))
#define I32(p, o) (*(ui *)((u8 *)(p) + (o)))
#define U32(p, o) (*(uu *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4463b0(u8 *ctx, float *out, const float *in);      // ret 8
extern "C" void THISCALL ext_5ec8b0(u8 *self, u8 *a, u8 *ctx, u32 i);           // ret 0xc

typedef int(THISCALL *vi_t)(void *);
typedef float(THISCALL *vf_t)(void *);

static inline float u2f(int x) {
  double d = (double)x + G(double, 0x680aa0 + 8 * ((u32)x >> 31));
  return (float)d;
}

// 0x5ecd80, thiscall(a, ctx) ret 8, /GS frame.
static void THISCALL fn5ecd80(u8 *self, u8 *a, u8 *ctx) {
  if (FL(self, 0xc3) == 0.0f) {
    FL(self, 0xc3) = (float)(*(vi_t **)a)[0](a);
    FL(self, 0xc7) = (float)(*(vi_t **)a)[1](a);
  }
  float in1[3] = {-0.5f, -0.5f, 0};
  float out1[3] = {0, 0, FL(self, 0xbf)};
  ext_4463b0(ctx, out1, in1);
  FL(self, 0xa7) = out1[0];
  FL(self, 0xab) = out1[1];
  FL(self, 0xaf) = out1[2];
  float f = (*(vf_t **)a)[3](a);
  float k = G(float, 0x678858);
  float in2[3];
  in2[0] = (k / FL(self, 0xc3)) / f;
  in2[1] = k / FL(self, 0xc7);
  float out2[3] = {0, 0, FL(self, 0xbf)};
  ext_4463b0(ctx, out2, in2);
  FL(self, 0xb3) = out2[0];
  FL(self, 0xb7) = out2[1];
  FL(self, 0xbb) = out2[2];
  for (u32 i = 0, off = 0; i < U32(self, 0x3e); i++, off += 0x28) {
    u8 *o = (*(u8 ***)(self + 0x62))[i];
    float in3[3];
    float xs = u2f(I32(self, 0x56));
    xs *= FL(o, 0xc);
    xs /= FL(self, 0xc7);
    float xr = u2f(I32(self, 0x52));
    xr *= FL(o, 8);
    xr /= FL(self, 0xc3);
    in3[0] = xr;
    in3[1] = xs;
    float out3[2] = {0, 0};
    ext_4463b0(ctx, out3, in3);
    u8 *p = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
    FL(p, off + 0x1c) = out3[0];
    p = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
    *(uu *)(p + off + 0x20) = fbits(out3[1]) ^ G(u32, 0x67af40);
    ext_5ec8b0(self, a, ctx, i);
  }
}
PCREG(5ecd80, fn5ecd80);
