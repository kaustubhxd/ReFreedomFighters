// batch33083.cpp - h3 () batch 33083: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)
#define LOGOBJ (*(u8 **)0x700390)

typedef void (*hook_t)();
typedef void (*log2_t)(u8 *, u32);
typedef void (*log3_t)(u8 *, u32, u32);

extern "C" float THISCALL ext_4e5e80(u8 *self);                         // float in st0
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                           // eax
extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 which);               // ret 4

// 0x527270: thiscall(float a, float b, float c) ret 0xc: [this+0x25]=a; a == 0 (ordered): log call chain, [this+0x25]=0x39000000; [this+0x1d]=b; [this+0x21]=c
static void THISCALL fn527270(u8 *self, u32 a, u32 b, u32 c) {
  *(u32 *)(self + 0x25) = a;
  if (bitsf(a) == 0.0f) {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x6a0a20u, 0x3cu);
    (*(log2_t *)(*(u8 **)r + 0x2c))(r, 0x6a0a58);
    *(u32 *)(self + 0x25) = 0x39000000;
  }
  *(u32 *)(self + 0x1d) = b;
  *(u32 *)(self + 0x21) = c;
}
PCREG(527270, fn527270);

// 0x5d5ea0: thiscall(stream) ret 4: floats [+0x48],[+0x54],[+0x58] from e80; dwords [+0x5e],[+0x62],[+0x66] from e60 (unaligned)
static void THISCALL fn5d5ea0(u8 *self, u8 *s) {
  float f = ext_4e5e80(s);
  *(float *)(self + 0x48) = f;
  f = ext_4e5e80(s);
  *(float *)(self + 0x54) = f;
  f = ext_4e5e80(s);
  *(float *)(self + 0x58) = f;
  u32 d = ext_4e5e60(s);
  __builtin_memcpy(self + 0x5e, &d, 4);
  d = ext_4e5e60(s);
  __builtin_memcpy(self + 0x62, &d, 4);
  d = ext_4e5e60(s);
  __builtin_memcpy(self + 0x66, &d, 4);
}
PCREG(5d5ea0, fn5d5ea0);

// 0x46b5d0: thiscall(a, float t) ret 8, float result in st0: s=[0xb0], e=[0xb4], m=[0xbc]: s>=t -> m*1.0; t>e -> m*0.0; else m*(1-(t-s)/(e-s))
static double THISCALL fn46b5d0(u8 *self, u32 a, u32 tb) {
  (void)a;
  float s = *(float *)(self + 0xb0), e = *(float *)(self + 0xb4), m = *(float *)(self + 0xbc);
  float t = bitsf(tb);
  if (s >= t) return (double)m * 1.0;
  if (t > e) return (double)m * 0.0;
  float q = (t - s) / (e - s);
  float w = 1.0f - q;
  return (double)m * (double)w;
}
PCREG(46b5d0, fn46b5d0);

// 0x4b41b0: thiscall no args: byte [0x181] set: [0x64]==0 or [0x6c]==0 -> return; p=sys table slot 0x60([0x6c]); p and 0 < p[0x70] (or NaN) -> return; slot 0xa0(); then slot 0x68(0x10, 0)
static void THISCALL fn4b41b0(u8 *self) {
  if (self[0x181] != 0) {
    if (*(u32 *)(self + 0x64) == 0) return;
    u32 key = *(u32 *)(self + 0x6c);
    if (key == 0) return;
    u8 *tab = *(u8 **)(SYS + 0x9b);
    u8 *p = vcall<u8 *>(tab, 0x60, key);
    if (p && !(0.0f >= *(float *)(p + 0x70))) return;
    vcall<u32>(self, 0xa0);
  }
  vcall<u32>(self, 0x68, 0x10u, 0u);
}
PCREG(4b41b0, fn4b41b0);

// 0x4f7520: thiscall(a) ret 4: [this+0x97]=a; byte [0xa7]: o=[sys+0x190f]: o->slot 0xb8([this+0x93]); o->slot 0xac([this+0x93], (float)(unsigned)[this+0x97])
static void THISCALL fn4f7520(u8 *self, u32 a) {
  u8 flag = self[0xa7];
  *(u32 *)(self + 0x97) = a;
  if (!flag) return;
  u8 *o = *(u8 **)(SYS + 0x190f);
  vcall<u32>(o, 0xb8, *(u32 *)(self + 0x93));
  o = *(u8 **)(SYS + 0x190f);
  s32 v = *(s32 *)(self + 0x97);
  double d = (double)v + ((u32)v >> 31 ? 4294967296.0 : 0.0);
  float f = (float)d;
  vcall<u32>(o, 0xac, *(u32 *)(self + 0x93), fbits(f));
}
PCREG(4f7520, fn4f7520);

// 0x51aaa0: thiscall(arg) ret 4: o=[arg+4]; p1=5003d0(o,1); p0=5003d0(o,0); slot 0x364 of [this+0x18](*p0, *p1 != 0)
static void THISCALL fn51aaa0(u8 *self, u8 *arg) {
  u8 *o = *(u8 **)(arg + 4);
  u32 *p1 = ext_5003d0(o, 1);
  u32 *p0 = ext_5003d0(o, 0);
  u32 fl = *p1 != 0;
  vcall<u32>(*(u8 **)(self + 0x18), 0x364, *p0, fl);
}
PCREG(51aaa0, fn51aaa0);

// 0x51ec70: thiscall(arg) ret 4: o=[arg+4]; p1=(o,1); p0=(o,0); slot 0 of ([this+0x18]+0x29a)(*p0, 0, *p1)
static void THISCALL fn51ec70(u8 *self, u8 *arg) {
  u8 *o = *(u8 **)(arg + 4);
  u32 *p1 = ext_5003d0(o, 1);
  u32 *p0 = ext_5003d0(o, 0);
  u32 f1 = *p1, f0 = *p0;
  vcall<u32>(*(u8 **)(self + 0x18) + 0x29a, 0, f0, 0u, f1);
}
PCREG(51ec70, fn51ec70);

// 0x5f4110: thiscall(float *d) ret 4: byte [this+4] == 2: [this] /= *d; else log call chain + assert hook
static void THISCALL fn5f4110(u8 *self, float *d) {
  if (self[4] == 2) {
    float x = *(float *)self;
    x = x / *d;
    *(float *)self = x;
    return;
  }
  u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x69c8e0u, 0xb4u);
  (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c938);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
PCREG(5f4110, fn5f4110);
