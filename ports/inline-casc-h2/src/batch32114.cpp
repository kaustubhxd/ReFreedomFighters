// batch32114.cpp - cascade h2 (): tier H (float / SSE) functions, batch 32114.
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                 // thiscall ret 4
extern "C" void THISCALL ext_516070(u8 *self, float a);              // thiscall ret 4
extern "C" s32 VECTORCALL ext_633910(float f);                       // CRT float-to-int helper (XMM0 -> EAX)
extern "C" float THISCALL ext_5162d0(u8 *self);                      // thiscall, plain ret: fld [ecx+0x55]
extern "C" void THISCALL ext_500360(u8 *self, float a);              // thiscall ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);                // thiscall ret 4
typedef u32 (*hook_t)();
typedef u32 (*cd3_t)(u32, u32, u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

// 0x50aa30, stdcall(p) ret 4: r = 0x5003d0([p+8], 0); byte [r+4] is 0 or 2 -> [r] = (float)[[0x70039c]+0x40] * K(0x6785e4), byte [r+4] = 2, returns r;
// otherwise logs through [0x700390] (slot 0x20 with (0x69c8e0, 0xd5), then its cdecl slot 0x2c with (o, 0x69c6b0, 0x69c938)) and returns the assert hook's eax (int3 when null).
static u32 STDCALL fn50aa30(u8 *p) {
  float t = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * G(float, 0x6785e4);
  u8 *r = (u8 *)ext_5003d0(*(u8 **)(p + 8), 0);
  u8 kind = r[4];
  if (kind == 0 || kind == 2) {
    *(float *)r = t;
    r[4] = 2;
    return (u32)r;
  }
  void *g = G(void *, 0x700390);
  u8 *o = vcall<u8 *>(g, 0x20, 0x69c8e0u, 0xd5u);
  (*(cd3_t *)(*(u8 **)o + 0x2c))((u32)o, 0x69c6b0, 0x69c938);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(50aa30, fn50aa30);

// 0x527b30, thiscall no args: [this+0x22cc] = 0; for i < [this+0x8d] (signed): 0x516070(this + 0x95 + 0xde*i, float [this+0x21b5]) and a non-zero byte at this + 0xa5 + 0xde*i sets [this+0x22cc] = 1.0f;
// then the same for i < [this+0x91] with this + 0x785 / 0x795.
static void THISCALL fn527b30(u8 *self) {
  *(u32 *)(self + 0x22cc) = 0;
  for (s32 i = 0; i < *(s32 *)(self + 0x8d); i++) {
    u8 *rec = self + 0xa5 + 0xde * i;
    ext_516070(rec - 0x10, rdf(self + 0x21b5));
    if (*rec) *(u32 *)(self + 0x22cc) = 0x3f800000;
  }
  for (s32 i = 0; i < *(s32 *)(self + 0x91); i++) {
    u8 *rec = self + 0x795 + 0xde * i;
    ext_516070(rec - 0x10, rdf(self + 0x21b5));
    if (*rec) *(u32 *)(self + 0x22cc) = 0x3f800000;
  }
}
PCREG(527b30, fn527b30);

// 0x610070, thiscall(float a) ret 4: [this+0x14f2] = a; k = 0; a == 0.0 (0x6785d0) or a == 1.0 (0x678858) -> k = 0; a == 0.99 (0x680140) -> k = 0x10;
// else k = ftoi(((1.0 - a) * 255.0) / K(0x686080) + 0.5), limited to 0xf unsigned; slot 0xc8 of the object o = unaligned [this+0x1377] with (o, 0x2f, k).
static void THISCALL fn610070(u8 *self, float a) {
  u32 k = 0;
  *(float *)(self + 0x14f2) = a;
  if (a == G(float, 0x6785d0)) {
  } else if (a == G(float, 0x678858)) {
  } else if (a == G(float, 0x680140)) {
    k = 0x10;
  } else {
    float t = (G(float, 0x678858) - a) * G(float, 0x68af18);
    t = t / G(float, 0x686080);
    t = t + G(float, 0x67a6ac);
    k = (u32)ext_633910(t);
    if (k > 0xf) k = 0xf;
  }
  u32 o = rd32(self + 0x1377);
  vcall<void>((void *)o, 0xc8, o, 0x2fu, k);
}
PCREG(610070, fn610070);

// 0x529760, thiscall no args: [this+4] = 0; over the [this+0x8d] records at this + 0x95 + 0xde*i and then the [this+0x91] records at this + 0x785 + 0xde*i (signed counts):
// [this+4] = (float)((double)0x5162d0(rec) + (double)[this+4]); finally [this+4] = [this+4] / (float)([this+0x91] + [this+0x8d]) + K(0x685270).
static void THISCALL fn529760(u8 *self) {
  *(float *)(self + 4) = 0.0f;
  for (s32 i = 0; i < *(s32 *)(self + 0x8d); i++) {
    float r = ext_5162d0(self + 0x95 + 0xde * i);
    *(float *)(self + 4) = (float)((double)r + (double)*(float *)(self + 4));
  }
  for (s32 i = 0; i < *(s32 *)(self + 0x91); i++) {
    float r = ext_5162d0(self + 0x785 + 0xde * i);
    *(float *)(self + 4) = (float)((double)r + (double)*(float *)(self + 4));
  }
  s32 n = *(s32 *)(self + 0x91) + *(s32 *)(self + 0x8d);
  float x = *(float *)(self + 4) / (float)n;
  *(float *)(self + 4) = x + G(float, 0x685270);
}
PCREG(529760, fn529760);

// 0x551670, stdcall(p, a, v) ret 0xc, returns b: b = slot 0x18 of p with a; b == 0 -> 0; q = slot 0x4c of b; 0x500360(0x5003d0(q, 0), float v[0]); 0x5002f0(0x5003d0(q, 1), v[1]); 0x5002f0(0x5003d0(q, 2), v[2]); returns b.
static u32 STDCALL fn551670(void *p, u32 a, u32 *v) {
  void *b = vcall<void *>(p, 0x18, a);
  if (!b) return 0;
  void *q = vcall<void *>(b, 0x4c);
  float v0; __builtin_memcpy(&v0, &v[0], 4);
  u32 r0 = ext_5003d0((u8 *)q, 0);
  ext_500360((u8 *)r0, v0);
  u32 r1 = ext_5003d0((u8 *)q, 1);
  ext_5002f0((u8 *)r1, v[1]);
  u32 r2 = ext_5003d0((u8 *)q, 2);
  ext_5002f0((u8 *)r2, v[2]);
  return (u32)b;
}
PCREG(551670, fn551670);
