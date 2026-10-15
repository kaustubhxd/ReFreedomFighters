// batch33100.cpp - h3 (Sonnet) batch 33100: tier H float/SSE functions
#include "ff.h"

#define LOGOBJ (*(u8 **)0x700390)

typedef void (*log2_t)(u8 *, u32);

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" void THISCALL ext_523280(u8 *self);                          // plain ret
extern "C" void THISCALL ext_5ec090(u8 *self, u32 v, u32 k);            // ret 8
extern "C" u32 THISCALL ext_5a5d00(u8 *self, u32 f, u32 b, u32 c);      // ret 0xc
extern "C" void THISCALL ext_5ec340(u8 *self, u32 a, u32 b);            // ret 8

// 0x523040: thiscall(a, float f) ret 8: a == 0 -> return; log chain (0x6a0778, 0xcb)/(r, 0x6a07e8); [this+0x4b]=a; [0x4f]=0; [0x53]=[a+0x20]; [0x39]=3; [4]=f; f == 0: [0x42]=[0x20]=1.0 else [0x42]=0,[0x20]=-1.0; byte [0x34]=0; 0x523280(this)
static void THISCALL fn523040(u8 *self, u8 *a, u32 fb) {
  if (!a) return;
  u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x6a0778u, 0xcbu);
  (*(log2_t *)(*(u8 **)r + 0x2c))(r, 0x6a07e8);
  W32(self + 0x4b, (u32)a);
  W32(self + 0x4f, 0);
  W32(self + 0x53, *(u32 *)(a + 0x20));
  W32(self + 0x39, 3);
  W32(self + 4, fb);
  if (bitsf(fb) == 0.0f) {
    W32(self + 0x42, 0x3f800000);
    W32(self + 0x20, 0x3f800000);
  } else {
    W32(self + 0x42, 0);
    W32(self + 0x20, 0xbf800000);
  }
  self[0x34] = 0;
  ext_523280(self);
}
PCREG(523040, fn523040);

// 0x5a83e0: thiscall(float x) ret 4: x == [this+0x2fc] -> return; c = clamp(x, 0, 1) stored at +0x2fc; v = 0 >= c ? 0 : (int)(c * (byte [0x658] ? 55.0 : 119.0) + 1.0); 0x5ec090([this+0x434], v, 8); 0x5ec340([this+0x434], 0x5a5d00(this, c, 1.0, 0), -1)
static void THISCALL fn5a83e0(u8 *self, u32 xb) {
  float x = bitsf(xb);
  if (x == *(float *)(self + 0x2fc)) return;
  u8 flag = self[0x658];
  float m = (1.0f < x) ? 1.0f : x;
  float c = (0.0f > m) ? 0.0f : m;
  *(float *)(self + 0x2fc) = c;
  u32 v;
  if (0.0f >= c) {
    v = 0;
  } else {
    float k = flag ? 55.0f : 119.0f;
    float t = c * k;
    t = t + 1.0f;
    v = (u32)_mm_cvttss_si32(_mm_set_ss(t));
  }
  ext_5ec090(*(u8 **)(self + 0x434), v, 8);
  u32 f = R32(self + 0x2fc);
  u32 r = ext_5a5d00(self, f, 0x3f800000u, 0u);
  ext_5ec340(*(u8 **)(self + 0x434), r, 0xffffffffu);
}
PCREG(5a83e0, fn5a83e0);

// 0x5b7c70: thiscall(o) ret 4: o->slot 0x4c([this+4]); slot 0x4c([this+8]); r = o->slot 0x68(this+0xc); r->slot 0x68(this+0x18); o->slot 0x60(byte [this+0x28]); o->slot 0x3c([this+0x24]); o->slot 0x3c([this])
static void THISCALL fn5b7c70(u8 *self, u8 *o) {
  vcall<u32>(o, 0x4c, *(u32 *)(self + 4));
  vcall<u32>(o, 0x4c, *(u32 *)(self + 8));
  u8 *r = vcall<u8 *>(o, 0x68, (u32)(self + 0xc));
  vcall<u32>(r, 0x68, (u32)(self + 0x18));
  vcall<u32>(o, 0x60, (u32)self[0x28]);
  vcall<u32>(o, 0x3c, *(u32 *)(self + 0x24));
  vcall<u32>(o, 0x3c, *(u32 *)self);
}
PCREG(5b7c70, fn5b7c70);
