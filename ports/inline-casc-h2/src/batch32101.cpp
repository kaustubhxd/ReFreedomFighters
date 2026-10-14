// batch32101.cpp - cascade h2 (): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" void THISCALL ext_4658d0(u8 *self, u32 a);                                 // thiscall ret 4
extern "C" void THISCALL ext_467aa0(u8 *self, u32 a, u32 b, u32 c);                   // thiscall ret 0xc
extern "C" void THISCALL ext_4678e0(u8 *self, u32 e0, u32 e1, u32 e2, u32 e3);        // thiscall ret 0x10
extern "C" void THISCALL ext_467b00(u8 *self, float a, u32 b);                        // thiscall ret 8
extern "C" u32 THISCALL ext_466600(u8 *self, u32 a);                                  // thiscall ret 4

// 0x475a20, thiscall(a, b, c, float d, e0..e3) ret 0x20, returns the last callee's eax: with s = this+4: 0x4658d0(s, a); 0x467aa0(s, b, c, 0); 0x4678e0(s, e0..e3); 0x467b00(s, d, 0); 0x466600(s, 1).
static u32 THISCALL fn475a20(u8 *self, u32 a, u32 b, u32 c, float d, u32 e0, u32 e1, u32 e2, u32 e3) {
  u8 *s = self + 4;
  ext_4658d0(s, a);
  ext_467aa0(s, b, c, 0);
  ext_4678e0(s, e0, e1, e2, e3);
  ext_467b00(s, d, 0);
  return ext_466600(s, 1);
}
PCREG(475a20, fn475a20);

// 0x4f1000, thiscall(float *p) ret 4: g = (int)trunc(p[1]/K * K1(0x698550)) & 0xff00; b = low byte of (int)trunc(p[2]/K * K); r = (int)trunc(p[0]/K * K2(0x698554)) & 0xff0000;
// K = float at 0x68af18; returns slot 0x248 of this with (g | b | r).
static u32 THISCALL fn4f1000(void *self, float *p) {
  float k = G(float, 0x68af18);
  s32 g, b, r;
  float t1 = p[1] / k * G(float, 0x698550);
  __asm__("cvttss2si %1, %0" : "=r"(g) : "m"(t1));
  float t2 = p[2] / k * k;
  __asm__("cvttss2si %1, %0" : "=r"(b) : "m"(t2));
  float t0 = p[0] / k * G(float, 0x698554);
  __asm__("cvttss2si %1, %0" : "=r"(r) : "m"(t0));
  u32 v = ((u32)g & 0xff00) | ((u32)b & 0xff) | ((u32)r & 0xff0000);
  return vcall<u32>(self, 0x248, v);
}
PCREG(4f1000, fn4f1000);

// 0x5b7eb0, thiscall(o) ret 4: slot 0x64 of o with [this]; slot 0x4c of o with float [this+4]; slot 0x4c with float [this+8]; returns slot 0x64 of o with [this+0xc].
static u32 THISCALL fn5b7eb0(u8 *self, void *o) {
  vcall<void>(o, 0x64, *(u32 *)self);
  vcall<void>(o, 0x4c, *(float *)(self + 4));
  vcall<void>(o, 0x4c, *(float *)(self + 8));
  return vcall<u32>(o, 0x64, *(u32 *)(self + 0xc));
}
PCREG(5b7eb0, fn5b7eb0);
