// batch33084.cpp - h3 (Sonnet) batch 33084: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

extern "C" u32 THISCALL ext_560360(u8 *self, u32 a);                 // ret 4 (xor al,al)

// 0x4bb260: thiscall no args: p=[[this+0x44]+0x18]; (float)p[0x74] == 0 -> return; o=sys table slot 0x58([this+0x48]); o: o->slot 0x128(u16 [this+0x4c], 0, 0); slot 0x68(0x10, 0)
static void THISCALL fn4bb260(u8 *self) {
  u8 *p = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  if (*(float *)(p + 0x74) == 0.0f) return;
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u8 *o = vcall<u8 *>(tab, 0x58, *(u32 *)(self + 0x48));
  if (o) {
    u32 w = *(u16 *)(self + 0x4c);
    vcall<u32>(o, 0x128, w, 0u, 0u);
  }
  vcall<u32>(self, 0x68, 0x10u, 0u);
}
PCREG(4bb260, fn4bb260);

// 0x4f80a0: thiscall(float *p) ret 4: old=[+0x9f]; slot 0x370((*p - [+0xcf]) / [+0xa3]); [+0xcf] -= (old - [+0x9f]) * [+0xa3]; 0x560360(this, p)
static void THISCALL fn4f80a0(u8 *self, u32 *p) {
  float old = *(float *)(self + 0x9f);
  float x = bitsf(*p) - *(float *)(self + 0xcf);
  x = x / *(float *)(self + 0xa3);
  vcall<u32>(self, 0x370, fbits(x));
  float d = old - *(float *)(self + 0x9f);
  float m = d * *(float *)(self + 0xa3);
  float c = *(float *)(self + 0xcf);
  *(float *)(self + 0xcf) = c - m;
  ext_560360(self, (u32)p);
}
PCREG(4f80a0, fn4f80a0);

// 0x6560c0: stdcall(float *out, u8 *in) ret 8: out[0]=in[2]/255, out[1]=in[1]/255, out[2]=in[0]/255, out[3]=in[3]/255 (multiply by the float 0x3b808081)
static void STDCALL fn6560c0(float *out, u8 *in) {
  const float k = bitsf(0x3b808081);
  out[0] = (float)(s32)in[2] * k;
  out[1] = (float)(s32)in[1] * k;
  out[2] = (float)(s32)in[0] * k;
  out[3] = (float)(s32)in[3] * k;
}
PCREG(6560c0, fn6560c0);
