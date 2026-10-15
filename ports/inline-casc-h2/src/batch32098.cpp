// batch32098.cpp - cascade h2 (Sonnet): eight tier H (float / SSE) functions, sixth batch.
#include "ff.h"

extern "C" void THISCALL ext_4c0d70(u8 *self, u32 a);      // thiscall ret 4
extern "C" double ext_634dca(double);                      // CRT routine, double on the stack (cdecl), result in st0
extern "C" double VECTORCALL ext_634dac(double);           // CRT routine, argument/result in XMM0
extern "C" void THISCALL ext_4de7a0(u8 *self);             // thiscall, plain ret
extern "C" float THISCALL ext_4e5e80(u8 *self);            // thiscall, plain ret, float in st0
extern "C" u32 THISCALL ext_4e5e40(u8 *self);              // thiscall, plain ret, result in AX
extern "C" u32 THISCALL ext_4e5e60(u8 *self);              // thiscall, plain ret

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }
static inline s32 trunc_ss(float f) { s32 t; __asm__("cvttss2si %1, %0" : "=r"(t) : "m"(f)); return t; }

// 0x5244f0, thiscall(float a) ret 4: [this+0x10] = a == K1(0x67cd44) ? 0 : a == K2(0x6785d0) ? 0x7e967699 : K3(0x678858) / a.
static void THISCALL fn5244f0(u8 *self, float a) {
  if (a == G(float, 0x67cd44)) {
    *(u32 *)(self + 0x10) = 0;
  } else if (a == G(float, 0x6785d0)) {
    *(u32 *)(self + 0x10) = 0x7e967699;
  } else {
    *(float *)(self + 0x10) = G(float, 0x678858) / a;
  }
}
PCREG(5244f0, fn5244f0);

// 0x4c1ee0, thiscall(a, b) ret 8: 0x4c0d70(this, b); [this+0x1cc] != 0 -> [0x1c4] = [0x1c8] = 1, else both = [this+0x1c0]; returns slot 0x60 of this with float [this+0x1ac].
static u32 THISCALL fn4c1ee0(u8 *self, u32 a, u32 b) {
  ext_4c0d70(self, b);
  if (*(u32 *)(self + 0x1cc)) {
    *(u32 *)(self + 0x1c4) = 1;
    *(u32 *)(self + 0x1c8) = 1;
  } else {
    u32 v = *(u32 *)(self + 0x1c0);
    *(u32 *)(self + 0x1c4) = v;
    *(u32 *)(self + 0x1c8) = v;
  }
  return vcall<u32>(self, 0x60, *(float *)(self + 0x1ac));
}
PCREG(4c1ee0, fn4c1ee0);

// 0x4f7180, thiscall no args, returns an int: slot 0x2d0 of this; f = float [[this+8]+0x44]; r = CRT 0x634dca((double)(f + f)); returns (int)trunc(r) (cvttsd2si).
static s32 THISCALL fn4f7180(u8 *self) {
  vcall<void>(self, 0x2d0);
  float f = *(float *)(*(u8 **)(self + 8) + 0x44);
  double d = (double)(f + f);
  double r = ext_634dca(d);
  s32 t;
  __asm__("cvttsd2si %1, %0" : "=r"(t) : "m"(r));
  return t;
}
PCREG(4f7180, fn4f7180);

// 0x466220, thiscall no args: 0x4de7a0(this+1); dwords at 0x25/0x29/0x2d = 0; 0x31/0x35/0x39 = 0; the block {0, 0, 0, -1} at 0x3d (unaligned); byte [this] = 0.
static void THISCALL fn466220(u8 *self) {
  ext_4de7a0(self + 1);
  wr32(self + 0x25, 0);
  wr32(self + 0x29, 0);
  wr32(self + 0x2d, 0);
  wr32(self + 0x39, 0);
  wr32(self + 0x31, 0);
  wr32(self + 0x35, 0);
  wr32(self + 0x3d, 0);
  wr32(self + 0x41, 0);
  wr32(self + 0x45, 0);
  wr32(self + 0x49, 0xffffffff);
  self[0] = 0;
}
PCREG(466220, fn466220);

// 0x4b2890, thiscall(o) ret 4: e = object embedded at this+0xaa; r = slot 0x84 of o with 0; returns slot 0x98 of e with (o, (float)(int)r).
static u32 THISCALL fn4b2890(u8 *self, void *o) {
  u8 *e = self + 0xaa;
  u32 r = vcall<u32>(o, 0x84, 0u);
  float f = (float)(s32)r;
  return vcall<u32>(e, 0x98, (u32)o, f);
}
PCREG(4b2890, fn4b2890);

// 0x5d34e0, thiscall(a) ret 4: [this+0x4a] = float 0x4e5e80(a); word [this+0x52] = AX of 0x4e5e40(a); byte [this+0x54] = (0x4e5e60(a) != 0); [this+0x4e] = float 0x4e5e80(a) (unaligned).
static void THISCALL fn5d34e0(u8 *self, u8 *a) {
  wrf(self + 0x4a, ext_4e5e80(a));
  u32 w = ext_4e5e40(a);
  self[0x52] = w;
  self[0x53] = w >> 8;
  self[0x54] = ext_4e5e60(a) != 0;
  wrf(self + 0x4e, ext_4e5e80(a));
}
PCREG(5d34e0, fn5d34e0);

// 0x46b440, thiscall(float a, float b) ret 8: byte [this+0xec] = 1; e = [[0x70039c]+0x40] - (int)trunc(a * K(0x67862c)); [this+0xed] = (float)e * K2(0x6785e4); w = [this+0x88]; [this+0xf1] = w;
// [this+0xf5] = w / (b == K0(0x6785d0) ? K3(0x678858) : b)  (all unaligned stores).
static void THISCALL fn46b440(u8 *self, float a, float b) {
  float t = a * G(float, 0x67862c);
  self[0xec] = 1;
  s32 e = *(s32 *)(G(u8 *, 0x70039c) + 0x40) - trunc_ss(t);
  float x = (float)e * G(float, 0x6785e4);
  wrf(self + 0xed, x);
  float w = *(float *)(self + 0x88);
  wrf(self + 0xf1, w);
  float den = (b == G(float, 0x6785d0)) ? G(float, 0x678858) : b;
  wrf(self + 0xf5, w / den);
}
PCREG(46b440, fn46b440);

// 0x516fd0, thiscall(p) ret 4: [this+0x51], [this+0x55], [this+0x59] = (float)CRT 0x634dac((double)p[0..2]) (unaligned stores).
static void THISCALL fn516fd0(u8 *self, float *p) {
  wrf(self + 0x51, (float)ext_634dac((double)p[0]));
  wrf(self + 0x55, (float)ext_634dac((double)p[1]));
  wrf(self + 0x59, (float)ext_634dac((double)p[2]));
}
PCREG(516fd0, fn516fd0);
