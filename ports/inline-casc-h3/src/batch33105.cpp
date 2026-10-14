// batch33105.cpp - h3 () batch 33105: tier H float/SSE functions
#include "ff.h"

// 0x464650: thiscall(a, f1, b, f2, f3, f4) ret 0x18: x1=(float)(a[0x64]-a[0x60])*f1; x0=(float)(b[0x64]-b[0x60])*f2; o=[this+0x6c]; o->slot 0x18(this->slot 0x288(a, a, x1, f4, 4)); o->slot 0x18(this->slot 0x288(b, b, x0, f3, 0))
static void THISCALL fn464650(u8 *self, u8 *a, u32 f1, u8 *b, u32 f2, u32 f3, u32 f4) {
  s32 da = (s32)(*(u32 *)(a + 0x64) - *(u32 *)(a + 0x60));
  s32 db = (s32)(*(u32 *)(b + 0x64) - *(u32 *)(b + 0x60));
  float x1 = (float)da * bitsf(f1);
  float x0 = (float)db * bitsf(f2);
  u8 *o = *(u8 **)(self + 0x6c);
  u8 *vt = *(u8 **)o;
  u32 r = vcall<u32>(self, 0x288, (u32)a, (u32)a, fbits(x1), f4, 4u);
  typedef u32(THISCALL * fn_t)(u8 *, u32);
  (*(fn_t *)(vt + 0x18))(*(u8 **)(self + 0x6c), r);
  o = *(u8 **)(self + 0x6c);
  vt = *(u8 **)o;
  r = vcall<u32>(self, 0x288, (u32)b, (u32)b, fbits(x0), f3, 0u);
  (*(fn_t *)(vt + 0x18))(*(u8 **)(self + 0x6c), r);
}
PCREG(464650, fn464650);

// 0x5246a0: thiscall(float t) ret 4, float in st0: e=[this+0x18], g=[this+0x1c]; a=|e[0]-g[0]|; [this]=a; a == 0 -> 0.0; v = -((a-[0x14])*[0xc]) - [0x10]*[8]; s = (e[0]-g[0] < 0) ? -1 : 1; e[2] += s*v; g[2] -= s*v; [this+8] = (a - [this+4]) / t; [this+4]=a; return v
static float THISCALL fn5246a0(u8 *self, u32 tb) {
  float *e = *(float **)(self + 0x18);
  float *g = *(float **)(self + 0x1c);
  float d = e[0] - g[0];
  float a = (float)__builtin_fabs((double)d);
  *(float *)self = a;
  if (a == 0.0f) return 0.0f;
  float v = a - *(float *)(self + 0x14);
  float w = *(float *)(self + 0x10) * *(float *)(self + 8);
  v = v * *(float *)(self + 0xc);
  v = -v;
  v = v - w;
  float d2 = e[0] - g[0];
  float s = 1.0f;
  if (0.0f > d2) s = -1.0f;
  s = s * v;
  e[2] = e[2] + s;
  g = *(float **)(self + 0x1c);
  g[2] = g[2] - s;
  float q = *(float *)self - *(float *)(self + 4);
  *(u32 *)(self + 4) = *(u32 *)self;
  q = q / bitsf(tb);
  *(float *)(self + 8) = q;
  return v;
}
PCREG(5246a0, fn5246a0);
