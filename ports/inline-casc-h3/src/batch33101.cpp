// batch33101.cpp - h3 () batch 33101: tier H float/SSE functions
#include "ff.h"

#define LOGOBJ (*(u8 **)0x700390)

typedef void (*hook_t)();
typedef void (*log3_t)(u8 *, u32, u32);

extern "C" float THISCALL ext_4e5e80(u8 *self);                      // float in st0
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                        // eax
extern "C" void THISCALL ext_4e6330(u8 *self, u8 *dst);              // ret 4
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 which);             // ret 4

// 0x4c0d70: thiscall(stream) ret 4, returns true: [0x1a0],[0x1a4] = e60; [0x1ac],[0x1b0],[0x1b4] = e80; [0x1c0],[0x1cc] = e60; [0x1b8]=[0x1bc]=0; b=**s: b != 0xff and (b&0x3f)==9: 0x4e6330(s, this+0x48); 0x4e6330(s, this+0xf4)
static u8 THISCALL fn4c0d70(u8 *self, u8 *s) {
  u32 d;
  float f;
  d = ext_4e5e60(s); *(u32 *)(self + 0x1a0) = d;
  d = ext_4e5e60(s); *(u32 *)(self + 0x1a4) = d;
  f = ext_4e5e80(s); *(float *)(self + 0x1ac) = f;
  f = ext_4e5e80(s); *(float *)(self + 0x1b0) = f;
  f = ext_4e5e80(s); *(float *)(self + 0x1b4) = f;
  d = ext_4e5e60(s); *(u32 *)(self + 0x1c0) = d;
  d = ext_4e5e60(s); *(u32 *)(self + 0x1cc) = d;
  *(u32 *)(self + 0x1b8) = 0;
  *(u32 *)(self + 0x1bc) = 0;
  u8 b = **(u8 **)s;
  if (b != 0xff && (b & 0x3f) == 9) {
    ext_4e6330(s, self + 0x48);
    ext_4e6330(s, self + 0xf4);
  }
  return 1;
}
PCREG(4c0d70, fn4c0d70);

// 0x51e870: thiscall(arg) ret 4: f=(float)[this+0x18]->slot 0x370(); p=0x5003d0([arg+8], 0); byte p[4] not in {0, 2}: log chain (0x69c8e0,0x104)/(r,0x69c6b0,0x69c938) + assert hook; p[4]=2; p[0]=f
static void THISCALL fn51e870(u8 *self, u8 *arg) {
  float f = vcall<float>(*(u8 **)(self + 0x18), 0x370);
  u8 *p = ext_5003d0(*(u8 **)(arg + 8), 0);
  u8 b = p[4];
  if (b != 0 && b != 2) {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x69c8e0u, 0x104u);
    (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  p[4] = 2;
  *(float *)p = f;
}
PCREG(51e870, fn51e870);
