// batch40002.cpp - cascade t1 (Sonnet), tier H: 0x5ec120, 0x5f3db0, 0x523ec0, 0x500360, 0x5bf550, 0x4e7be0.
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
typedef void (*hook_t)();

// the assertion report shared by 0x5f3db0 and 0x500360: o = [0x700390]->slot 0x20(0x69c8e0, line); o->slot 0x2c(o, 0x69c6b0, 0x69c938) (cdecl, caller pops);
// then the assert hook at 0x7003b0 (int3 when it is null).
static void assertReport(u32 line) {
  u8 *sys2 = G(u8 *, 0x700390);
  u8 *o = vcall<u8 *>(sys2, 0x20, (u32)0x69c8e0, line);
  ((void(*)(u8 *, u32, u32))rd32(*(u8 **)o + 0x2c))(o, 0x69c6b0, 0x69c938);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x5ec120, thiscall(a, b, idx) ret 0xc: t = [unaligned [this+0x62] + idx*4]; when u16 [t+0x28] == a and u16 [t+0x2a] == b nothing happens; else
// u16 [t+0x28] = a, u16 [t+0x2a] = b, float [t+8] = (float)(s32)a / (float)u16[t+4], float [t+0xc] = (float)(s32)b / (float)u16[t+6], byte [this+0xa6] = 1.
static void THISCALL fn5ec120(u8 *self, u32 a, u32 b, u32 idx) {
  u8 *t = *(u8 **)(rd32(self + 0x62) + idx * 4);
  if (*(u16 *)(t + 0x28) == a && *(u16 *)(t + 0x2a) == b) return;
  float w = (float)*(u16 *)(t + 4);
  *(u16 *)(t + 0x28) = a;
  *(u16 *)(t + 0x2a) = b;
  float fa = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(a)));
  float fb = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(b)));
  float h = (float)*(u16 *)(t + 6);
  *(float *)(t + 8) = fa / w;
  *(float *)(t + 0xc) = fb / h;
  self[0xa6] = 1;
}
PCREG(5ec120, fn5ec120);

// 0x5f3db0, thiscall(p) ret 4: kind = byte [this+4]; 0 -> [this] = [p], kind = 2; 2 -> float [this] += float [p]; other -> assertion report (line 0x7d) and return.
static void THISCALL fn5f3db0(u8 *self, u8 *p) {
  u8 kind = self[4];
  if (kind == 0) {
    *(u32 *)self = *(u32 *)p;
    self[4] = 2;
  } else if (kind == 2) {
    *(float *)self = *(float *)p + *(float *)self;
  } else {
    assertReport(0x7d);
  }
}
PCREG(5f3db0, fn5f3db0);

// 0x523ec0, thiscall(float a) ret 4: f = this->slot 0x24(a, 0) (float on st0, callee pops 8); if byte [this+0x46] and |(double)[this+0x28]| (mask 0x67cd50) > (double)f return;
// this->slot 8(0, f); when byte [this+0x46] is 0: unaligned float [this+0x47] = (float)(s32)[sys+0x40] * K(0x6785e4); byte [this+0x46] = 1.
static void THISCALL fn523ec0(u8 *self, float a) {
  float f = vcall<float>(self, 0x24, a, (u32)0);
  if (self[0x46]) {
    u64 m = G(u64, 0x67cd50);
    double x = (double)*(float *)(self + 0x28);
    x = __builtin_bit_cast(double, __builtin_bit_cast(u64, x) & m);
    if (x > (double)f) return;
  }
  vcall<void>(self, 8, (u32)0, f);
  if (!self[0x46]) {
    s32 t = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
    float v = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(t))) * G(float, 0x6785e4);
    wr32(self + 0x47, fbits(v));
  }
  self[0x46] = 1;
}
PCREG(523ec0, fn523ec0);

// 0x500360, thiscall(float f) ret 4, returns this: byte [this+4] not 0 and not 2 -> assertion report (line 0x104); then [this+4] = 2, [this] = f.
static u8 *THISCALL fn500360(u8 *self, float f) {
  u8 kind = self[4];
  if (kind != 0 && kind != 2) assertReport(0x104);
  self[4] = 2;
  *(float *)self = f;
  return self;
}
PCREG(500360, fn500360);

// 0x5bf550, thiscall(): w = unaligned [sys+0x6f], h = unaligned [sys+0x73] (signed); v = {(float)(w / 2), (float)(h / 2), 0}; [this+0x44]->slot 0x70(v); this->slot 0x58().
static void THISCALL fn5bf550(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  s32 w = (s32)rd32(sys + 0x6f), h = (s32)rd32(sys + 0x73);
  float v[3];
  v[0] = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128((s32)((u32)w - (u32)(w >> 31)) >> 1)));
  v[2] = 0.0f;
  v[1] = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128((s32)((u32)h - (u32)(h >> 31)) >> 1)));
  vcall<void>(*(u8 **)(self + 0x44), 0x70, (u32)v);
  vcall<void>(self, 0x58);
}
PCREG(5bf550, fn5bf550);

// 0x4e7be0, thiscall(o) ret 4: o->slot 0x54([this]); o->slot 0x4c([this+4]); o->slot 0x60(byte [this+8]); o->slot 0x4c(unaligned [this+0xd]); o->slot 0x4c(unaligned [this+0x11]).
static void THISCALL fn4e7be0(u8 *self, u8 *o) {
  vcall<void>(o, 0x54, *(u32 *)self);
  vcall<void>(o, 0x4c, *(u32 *)(self + 4));
  vcall<void>(o, 0x60, (u32)self[8]);
  vcall<void>(o, 0x4c, rd32(self + 0xd));
  vcall<void>(o, 0x4c, rd32(self + 0x11));
}
PCREG(4e7be0, fn4e7be0);
