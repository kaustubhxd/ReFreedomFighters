// batch33082.cpp - h3 () batch 33082: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

extern "C" void THISCALL ext_4604f0(u8 *self, u32 a, u32 f);        // ret 8
extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 which);           // ret 4
extern "C" u32 THISCALL ext_467230(u8 *self, u32 a);                // ret 4

// 0x521a40: thiscall(float *v) ret 4: p=[this+0x5c]; (float)p[0x24] > 50.0 -> return; [this+0x216]=1; [0x2e4]=v[0]; [0x2e8]=0; [0x2ec]=v[2]; obj at this+0x2695: slot 0(0x3f060a92, 0, 0x40c90fdb)
static void THISCALL fn521a40(u8 *self, u32 *v) {
  u8 *p = *(u8 **)(self + 0x5c);
  if (*(float *)(p + 0x24) > 50.0f) return;
  *(u32 *)(self + 0x216) = 1;
  u32 a = v[0], b = v[1], c = v[2];
  *(u32 *)(self + 0x2e4) = a;
  *(u32 *)(self + 0x2e8) = b;
  *(u32 *)(self + 0x2ec) = c;
  *(u32 *)(self + 0x2e8) = 0;
  vcall<u32>(self + 0x2695, 0, 0x3f060a92u, 0u, 0x40c90fdbu);
}
PCREG(521a40, fn521a40);

// 0x460aa0: thiscall(a, float t) ret 8: n=[this+0x10]; x=(float)n*t; k=(int)x; k>=n -> k=n-1; 0x4604f0([this+0xc]+56*k, a, x-(float)k)
static void THISCALL fn460aa0(u8 *self, u32 a, u32 tb) {
  s32 n = *(s32 *)(self + 0x10);
  float x = (float)n * bitsf(tb);
  s32 k = _mm_cvttss_si32(_mm_set_ss(x));
  if (!(k < n)) k = n - 1;
  float f = x - (float)k;
  ext_4604f0(*(u8 **)(self + 0xc) + (u32)k * 56u, a, fbits(f));
}
PCREG(460aa0, fn460aa0);

// 0x51ea70: thiscall(arg) ret 4: o=[arg+4]; p1=0x5003d0(o,1); p0=0x5003d0(o,0); slot 0x3a0 of [this+0x18](*p0, *p1)
static void THISCALL fn51ea70(u8 *self, u8 *arg) {
  u8 *o = *(u8 **)(arg + 4);
  u32 *p1 = ext_5003d0(o, 1);
  u32 *p0 = ext_5003d0(o, 0);
  u8 *q = *(u8 **)(self + 0x18);
  u32 f1 = *p1;
  vcall<u32>(q, 0x3a0, *p0, f1);
}
PCREG(51ea70, fn51ea70);

// 0x656060: stdcall(u32 *out, float *c) ret 8: *out = (int)(c[2]*255) - ((((int)(c[3]*-255) << 8) + (int)(c[0]*-255)) << 8 ...) see body
static void STDCALL fn656060(u32 *out, float *c) {
  u32 d = (u32)_mm_cvttss_si32(_mm_set_ss(c[3] * -255.0f));
  d <<= 8;
  d += (u32)_mm_cvttss_si32(_mm_set_ss(c[0] * -255.0f));
  d <<= 8;
  d += (u32)_mm_cvttss_si32(_mm_set_ss(c[1] * -255.0f));
  d <<= 8;
  u32 r = (u32)_mm_cvttss_si32(_mm_set_ss(c[2] * 255.0f));
  *out = r - d;
}
PCREG(656060, fn656060);

// 0x4bf640: thiscall no args: t=[sys+0x40]; t - (int)([this+0x1c7]*1024) > 0x400: [this+0x1c7]=(float)t/1024; r=slot 0x88(); r: slot 0x90(r), byte [this+0x1ba]=0
static void THISCALL fn4bf640(u8 *self) {
  s32 t = *(s32 *)(SYS + 0x40);
  s32 k = _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x1c7) * 1024.0f));
  if ((s32)((u32)t - (u32)k) <= 0x400) return;
  *(float *)(self + 0x1c7) = (float)t * 0.0009765625f;
  u32 r = vcall<u32>(self, 0x88);
  if (r) {
    vcall<u32>(self, 0x90, r);
    self[0x1ba] = 0;
  }
}
PCREG(4bf640, fn4bf640);

// 0x593ff0: thiscall(a) ret 4: p = sys table slot 0x60([this+0xf5a]); p and not ((float)p[0x70] == 0.0) -> return 0; else [this+0xf5a] = 0x467230(this, a), returned
static u32 THISCALL fn593ff0(u8 *self, u32 a) {
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u32 key = *(u32 *)(self + 0xf5a);
  u8 *p = vcall<u8 *>(tab, 0x60, key);
  if (p && !(*(float *)(p + 0x70) == 0.0f)) return 0;
  u32 r = ext_467230(self, a);
  *(u32 *)(self + 0xf5a) = r;
  return r;
}
PCREG(593ff0, fn593ff0);

// 0x5e9300: thiscall(a) ret 4: t=[sys+0x40]; k=(int)([this+0x44c]*-1024); n=[this+0x48]; [this+8n+0x4c]=a; [this+8n+0x50]=(float)(t-k)/1024; [this+0x48]++
static void THISCALL fn5e9300(u8 *self, u32 a) {
  s32 t = *(s32 *)(SYS + 0x40);
  s32 k = _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x44c) * -1024.0f));
  u32 n = *(u32 *)(self + 0x48);
  *(u32 *)(self + n * 8 + 0x4c) = a;
  float f = (float)(s32)((u32)t - (u32)k) * 0.0009765625f;
  *(float *)(self + n * 8 + 0x50) = f;
  *(u32 *)(self + 0x48) += 1;
}
PCREG(5e9300, fn5e9300);

// 0x51eb80: thiscall(arg) ret 4: o=[arg+4]; p=0x5003d0(o,0); slot 0 of ([this+0x18]+0x3c8)(*p, 0x3d0efa35, 0x3f860a92); p=0x5003d0(o,1); [[this+0x18]+0x346]=*p
static void THISCALL fn51eb80(u8 *self, u8 *arg) {
  u8 *o = *(u8 **)(arg + 4);
  u32 *p = ext_5003d0(o, 0);
  u32 f = *p;
  vcall<u32>(*(u8 **)(self + 0x18) + 0x3c8, 0, f, 0x3d0efa35u, 0x3f860a92u);
  p = ext_5003d0(o, 1);
  u32 v = *p;
  *(u32 *)(*(u8 **)(self + 0x18) + 0x346) = v;
}
PCREG(51eb80, fn51eb80);
