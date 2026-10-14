// batch32097.cpp - cascade h2 (): eight tier H (float / SSE) functions, fifth batch.
#include "ff.h"

extern "C" void THISCALL ext_4690b0(u8 *self);            // thiscall, plain ret
extern "C" void THISCALL ext_524890(u8 *self, float a);   // thiscall ret 4
extern "C" double VECTORCALL ext_634d76(double);          // CRT routine, argument/result in XMM0
extern "C" double VECTORCALL ext_634d70(double);          // CRT routine (cos), argument/result in XMM0
extern "C" void FASTCALL ext_633654(u32 cookie);          // /GS check

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

// 0x516690, thiscall(float a) ret 4: four unaligned constants at this+0x11/0x15/0x19/0x1d; 0x4690b0(this+0x41); 0x4690b0(this+0x55); 0x524890(this+0x21, a).
static void THISCALL fn516690(u8 *self, float a) {
  wr32(self + 0x11, 0xc4bb8000);
  wr32(self + 0x15, 0x42200000);
  wr32(self + 0x19, 0x430c0000);
  wr32(self + 0x1d, 0x42be0000);
  ext_4690b0(self + 0x41);
  ext_4690b0(self + 0x55);
  ext_524890(self + 0x21, a);
}
PCREG(516690, fn516690);

// 0x57f300, thiscall no args: [this+0x188] = float result (st0) of slot 0xa8 of o = slot 0xbc of the engine object; [this+0x18c] = AL of slot 0xb8 of a fresh slot 0xbc object.
static void THISCALL fn57f300(u8 *self) {
  void *eng = G(void *, 0x70039c);
  void *o = vcall<void *>(eng, 0xbc);
  *(float *)(self + 0x188) = vcall<float>(o, 0xa8);
  void *o2 = vcall<void *>(eng, 0xbc);
  self[0x18c] = vcall<u8>(o2, 0xb8);
}
PCREG(57f300, fn57f300);

// 0x4217c0, thiscall(ignored) ret 4, bool: float [[0x70039c]+0x9c7] (unaligned) ordered-equal to the constant at 0x6785d0 -> false; else true when slot 0x178 of the object at unaligned [this+0x9b] returns true, else byte [this+0x1b3e].
static u8 THISCALL fn4217c0(u8 *self, u32) {
  float v = rdf(G(u8 *, 0x70039c) + 0x9c7);
  if (v == G(float, 0x6785d0)) return 0;
  void *o = (void *)rd32(self + 0x9b);
  if (vcall<u8>(o, 0x178)) return 1;
  return self[0x1b3e];
}
PCREG(4217c0, fn4217c0);

// 0x4df9f0, register ABI (ecx = P, edx = Q) with a float stack argument ret 4: P[0] = (float)ext_634d76((double)a); Q[0] = (float)ext_634d70((double)a).
static void FASTCALL fn4df9f0(float *P, float *Q, float a) {
  float s = (float)ext_634d76((double)a);
  P[0] = s;
  Q[0] = (float)ext_634d70((double)a);
}
PCREG(4df9f0, fn4df9f0);

// 0x524890, thiscall(float a) ret 4: x = (a == 0) ? K(0x68ced0) : a; [this+0xc] = 0x46c35000; [this+0x10] = 0x44fa0000; [this+0x14] = (x == 0) ? 0.1f : x.
static void THISCALL fn524890(u8 *self, float a) {
  float x = a;
  if (a == 0.0f) x = G(float, 0x68ced0);
  *(u32 *)(self + 0xc) = 0x46c35000;
  *(u32 *)(self + 0x10) = 0x44fa0000;
  if (x == 0.0f) *(u32 *)(self + 0x14) = 0x3dcccccd;
  else *(float *)(self + 0x14) = x;
}
PCREG(524890, fn524890);

// 0x5ab130, thiscall(a) ret 4: byte [this+0x3c6] != 0 and unaligned [this+0x3c2] != a: a == 8 -> [this+0x3d0] = 0.2f only when it is ordered-equal to the constant at 0x6785d0 (else nothing);
// a != 8 -> [this+0x3d0] = 0; [this+0x3c2] = a.
static void THISCALL fn5ab130(u8 *self, u32 a) {
  if (!self[0x3c6]) return;
  if (rd32(self + 0x3c2) == a) return;
  if (a == 8) {
    if (rdf(self + 0x3d0) == G(float, 0x6785d0)) wr32(self + 0x3d0, 0x3e4ccccd);
    return;
  }
  wr32(self + 0x3d0, 0);
  wr32(self + 0x3c2, a);
}
PCREG(5ab130, fn5ab130);

// 0x466420, thiscall no args: slot 0x3c8 of this with (0, 0, 0, 0, 0xffffffff) (a zero argument and a 16-byte block {0, 0, 0, -1}); byte [this+0x158] = 1.
static void THISCALL fn466420(u8 *self) {
  vcall<void>(self, 0x3c8, 0u, 0u, 0u, 0u, 0xffffffffu);
  self[0x158] = 1;
}
PCREG(466420, fn466420);

// 0x4f11f0, thiscall(float a, b, c) ret 0xc (/GS frame): slot 0x70 of this with a pointer to the local {a, b, c}; /GS check.
static void THISCALL fn4f11f0(u8 *self, float a, float b, float c) {
  float v[3] = {a, b, c};
  vcall<void>(self, 0x70, (u32)v);
  ext_633654(0);
}
PCREG(4f11f0, fn4f11f0);
