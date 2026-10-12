// batch2484.cpp - decomp area 24, batch 2484.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract(dst, a) with b on the stack
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                    // vmtmul(float*, const float*)

typedef void (*cdecl2)(u32, u32);

static inline float absf(float v) {
  return v < 0.0f ? -v : v;
}

struct Vec4U {
  u32 a, b, c, d;
};

// 0x486700 ZActionPushButton::Execute(), thiscall, ret 0, AL = 1. Logger message through the global at 0x700390 (cdecl slot 0x2c),
// then child calls on +8, +0xc and +0x10, two vector helpers, and a timed call on +0xc with the chosen values.
static u8 THISCALL pushButtonExecute(u8 *self) {
  u8 *g = G(u8 *, 0x700390);
  u32 r0 = vcall<u32>(g, 0x20, (u32)0x68cdc4, (u32)0x1d8);
  void *vt = *(void **)r0;
  ((cdecl2)(*(void **)((u8 *)vt + 0x2c)))(r0, 0x68ce30u);

  float v10[3], v1c[3], v40[5], v64[9], v70[3];  // v64 is the 3x3 matrix read by vmtmul
  vcall<void>(*(void **)(self + 8), 0x80, v40, v10);
  vcall<void>(*(void **)(self + 0xc), 0x384, v64, v1c);
  ext_43e920(v70, v10, v1c);
  ext_441a60(v70, v64);
  vcall<void>(*(void **)(self + 0xc), 0x8c, v10);
  Vec4U s = {0x465708u, 0, 0, 0};
  vcall<void>(*(void **)(self + 0x10), 0x1c, *(void **)(self + 0xc), (u32)0, v10, 0.8f, s);

  float x = v70[0];
  float z = v70[2];
  float f1 = v40[1];
  float f2 = v40[4];
  float a, b;
  if (absf(z) > absf(x)) {
    if (absf(f2) > absf(f1)) {
      a = 90.0f;
      b = 119.0f;
    } else {
      a = 30.0f;
      b = 59.0f;
    }
  } else if (0.0f <= x) {
    a = 60.0f;
    b = 89.0f;
  } else {
    a = 0.0f;
    b = 29.0f;
  }
  vcall<void>(*(void **)(self + 0xc), 0x228, *(u32 *)(self + 0x14), (u32)1, a, b, 1.0f);
  return 1;
}
PCREG(486700, pushButtonExecute);
