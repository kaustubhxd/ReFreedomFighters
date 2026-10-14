// batch33090.cpp - h3 () batch 33090: tier H float/SSE functions
#include "ff.h"

extern "C" void THISCALL ext_460b60(u8 *self, u8 *out, u32 t);       // ret 8
extern "C" void THISCALL ext_4e0d00(u8 *self, u32 f);                // ret 4
extern "C" float THISCALL ext_44c840(u8 *self);                      // float in st0, plain ret
extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 which);            // ret 4

// 0x5da670: thiscall(obj, float *v) ret 8: locals {v0*[+0x7e]+[+0x76], 1-(v1*[+0x82]+[+0x7a])-v3*[+0x82], v2*[+0x7e], v3*[+0x82]}; obj->slot 0x23c(locals)
static void THISCALL fn5da670(u8 *self, u8 *obj, float *v) {
  float l[4];
  float k = *(float *)(self + 0x82);
  float s = *(float *)(self + 0x7e);
  float a = v[0] * s;
  a = a + *(float *)(self + 0x76);
  l[0] = a;
  float y = v[1] * k;
  float z = v[3] * k;
  y = y + *(float *)(self + 0x7a);
  float w = 1.0f - y;
  w = w - z;
  l[1] = w;
  l[3] = z;
  float c = v[2] * s;
  l[2] = c;
  vcall<u32>(obj, 0x23c, (u32)l);
}
PCREG(5da670, fn5da670);

// 0x523330: thiscall(float *out) ret 4: s=[this+0x4b]: none -> out = (0, 0, 1.0); else 0x460b60(s+0x1c, out, [this+4]); s->slot 0x88(out); 0x4e0d00(out, [this+0x20]); 0x44c840(out)
static void THISCALL fn523330(u8 *self, u8 *out) {
  u8 *s;
  __builtin_memcpy(&s, self + 0x4b, 4);
  if (!s) {
    *(u32 *)(out + 0) = 0;
    *(u32 *)(out + 4) = 0;
    *(u32 *)(out + 8) = 0x3f800000;
    return;
  }
  u32 t = *(u32 *)(self + 4);
  ext_460b60(s + 0x1c, out, t);
  vcall<u32>(s, 0x88, (u32)out);
  u32 f = *(u32 *)(self + 0x20);
  ext_4e0d00(out, f);
  (void)ext_44c840(out);
}
PCREG(523330, fn523330);

// 0x519e00: thiscall(arg) ret 4: t=(float)(*0x5003d0([arg+4],0) / o->slot 0x10()); u=(float)(o->slot 0x14()*t); v=(float)(o->slot 0xc(1)+u); [this+0x14]->slot 0x2f8(v), o=[[this+0x14]+0x5c]
static void THISCALL fn519e00(u8 *self, u8 *arg) {
  u32 *p = ext_5003d0(*(u8 **)(arg + 4), 0);
  u8 *q = *(u8 **)(self + 0x14);
  double r1 = vcall<float>(*(u8 **)(q + 0x5c), 0x10);
  float t = (float)((double)bitsf(*p) / r1);
  q = *(u8 **)(self + 0x14);
  double r2 = vcall<float>(*(u8 **)(q + 0x5c), 0x14);
  q = *(u8 **)(self + 0x14);
  float u = (float)(r2 * (double)t);
  u8 *vt = *(u8 **)q;
  double r3 = vcall<float>(*(u8 **)(q + 0x5c), 0xc, 1u);
  float v = (float)(r3 + (double)u);
  typedef void(THISCALL * fn_t)(u8 *, u32);
  (*(fn_t *)(vt + 0x2f8))(*(u8 **)(self + 0x14), fbits(v));
}
PCREG(519e00, fn519e00);
