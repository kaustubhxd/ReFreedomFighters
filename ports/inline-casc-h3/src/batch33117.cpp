// batch33117.cpp - h3 (Sonnet) batch 33117: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x4e0030: fastcall(ecx=a, edx=b) float in st0: c = dot(b,a) / (|b| * |a|) (float math, double sqrt via CRT); c > 1 -> 0; c < -1 -> pi; else acos(c)
static float FASTCALL fn4e0030(float *a, float *b) {
  float b0 = b[0], b1 = b[1], b2 = b[2];
  float lb2 = b0 * b0;
  float t1 = b1 * b1;
  lb2 = lb2 + t1;
  float t2 = b2 * b2;
  lb2 = lb2 + t2;
  float dot = b0 * a[0];
  float d1 = b1 * a[1];
  dot = dot + d1;
  float d2 = b2 * a[2];
  dot = dot + d2;
  float lb = (float)crt::sqrt((double)lb2);
  float la2 = a[0] * a[0];
  float u1 = a[1] * a[1];
  la2 = la2 + u1;
  float u2 = a[2] * a[2];
  la2 = la2 + u2;
  float la = (float)crt::sqrt((double)la2);
  float prod = lb * la;
  float c = dot / prod;
  if (c > 1.0f) return 0.0f;
  if (-1.0f > c) return bitsf(0x40490fdbu);
  return (float)crt::acos((double)c);
}
PCREG(4e0030, fn4e0030);

// 0x58aa40: fastcall(ecx=s, edx=a) returns s: s->slot 0x3c([a]); for p = a+4 until a+4+48*[a] (re-read each time), step 48: s->slot 0x64([p]); slot 0x68(p+4); slot 0x4c([p+0x10]); slot 0x4c([p+0x14]); slot 0x44([p+0x18]); slot 0x4c([p+0x1c]); slot 0x68(p+0x20); slot 0x44([p+0x2c])
static u8 *FASTCALL fn58aa40(u8 *s, u8 *a) {
  vcall<u32>(s, 0x3c, R32(a));
  u8 *p = a + 4;
  u8 *end = a + 4 + 48 * R32(a);
  while (p != end) {
    vcall<u32>(s, 0x64, R32(p));
    vcall<u32>(s, 0x68, (u32)(p + 4));
    vcall<u32>(s, 0x4c, R32(p + 0x10));
    vcall<u32>(s, 0x4c, R32(p + 0x14));
    vcall<u32>(s, 0x44, R32(p + 0x18));
    vcall<u32>(s, 0x4c, R32(p + 0x1c));
    vcall<u32>(s, 0x68, (u32)(p + 0x20));
    vcall<u32>(s, 0x44, R32(p + 0x2c));
    p += 0x30;
    end = a + 4 + 48 * R32(a);
  }
  return s;
}
PCREG(58aa40, fn58aa40);

// 0x449920: thiscall(float f) ret 4: o=[this+0x1c]: for each child (slots 0x4c / 0x5c) with a table entry: entry->slot 0x230(f); this->slot 0x238(); h=[[sys+0x1aa3]+0x18]; h->slot 0x84([[this+8]+0x6c], l); l[5]=f; h->slot 0xa0([[this+8]+0x6c], l); this->slot 0x220(1)
static void THISCALL fn449920(u8 *self, u32 fb) {
  u8 *o = *(u8 **)(self + 0x1c);
  if (o) {
    u32 n = 0;
    vcall<u32>(o, 0x4c, (u32)&n);
    o = *(u8 **)(self + 0x1c);
    u32 e = vcall<u32>(o, 0x5c, (u32)&n);
    while (n != 0) {
      u8 *tab = *(u8 **)(SYS + 0x9b);
      u8 *p = vcall<u8 *>(tab, 0x58, e);
      if (p) vcall<u32>(p, 0x230, fb);
      o = *(u8 **)(self + 0x1c);
      e = vcall<u32>(o, 0x5c, (u32)&n);
    }
  }
  vcall<u32>(self, 0x238);
  u32 l[16];
  u8 *g = *(u8 **)(SYS + 0x1aa3);
  u8 *h = *(u8 **)(g + 0x18);
  u32 hnd = R32(*(u8 **)(self + 8) + 0x6c);
  vcall<u32>(h, 0x84, hnd, (u32)l);
  l[5] = fb;
  g = *(u8 **)(SYS + 0x1aa3);
  h = *(u8 **)(g + 0x18);
  hnd = R32(*(u8 **)(self + 8) + 0x6c);
  vcall<u32>(h, 0xa0, hnd, (u32)l);
  vcall<u32>(self, 0x220, 1u);
}
PCREG(449920, fn449920);
