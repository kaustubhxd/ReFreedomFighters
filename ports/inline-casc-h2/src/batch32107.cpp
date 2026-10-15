// batch32107.cpp - cascade h2 (Sonnet): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" void THISCALL ext_4db500(u8 *self, float *out);   // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);             // /GS check

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x5d86d0, thiscall no args (/GS frame): byte [this+0x54] != 0 -> slot 0x84 of this, byte [this+0x54] = 0; 4db500([[this+0x44]+8], &v) fills v[3]; v[0] -= [[0x70039c]+0x48] * [this+0x48];
// slot 0x70 of [this+0x44] with &v; /GS check.
static void THISCALL fn5d86d0(u8 *self) {
  float v[3];
  if (self[0x54]) {
    vcall<void>(self, 0x84);
    self[0x54] = 0;
  }
  ext_4db500(*(u8 **)(*(u8 **)(self + 0x44) + 8), v);
  float x = v[0] - *(float *)(G(u8 *, 0x70039c) + 0x48) * *(float *)(self + 0x48);
  v[0] = x;
  vcall<void>(*(void **)(self + 0x44), 0x70, (u32)v);
  ext_633654(0);
}
PCREG(5d86d0, fn5d86d0);

// 0x44bc00, thiscall no args, returns AL: byte [this+0xec] == 0 -> 1; t = (int)trunc(unaligned float [this+0xed] * K(0x678620)); [[0x70039c]+0x40] < t -> 1; b = slot 0xb8 of the engine table (al);
// v = [this+0xf1] - ((b ? [eng+0x20] : [eng+0x48]) * [this+0xf5]); [this+0xf1] = v; K2(0x678858) > v (ordered) -> [this+4] = 3, byte [this+0xec] = 0, return 0; else [this+0x88] = v, return 1 (unaligned fields).
static u8 THISCALL fn44bc00(u8 *self) {
  if (!self[0xec]) return 1;
  u32 tb = rd32(self + 0xed);
  float tf;
  __builtin_memcpy(&tf, &tb, 4);
  float p = tf * G(float, 0x678620);
  s32 t;
  __asm__("cvttss2si %1, %0" : "=r"(t) : "m"(p));
  u8 *eng = G(u8 *, 0x70039c);
  if (*(s32 *)(eng + 0x40) < t) return 1;
  u8 b = vcall<u8>(*(u8 **)(eng + 0x9b), 0xb8);
  u32 vb = rd32(self + 0xf1);
  float v;
  __builtin_memcpy(&v, &vb, 4);
  eng = G(u8 *, 0x70039c);
  u32 fb = rd32(self + 0xf5);
  float f5;
  __builtin_memcpy(&f5, &fb, 4);
  float d = (b ? *(float *)(eng + 0x20) : *(float *)(eng + 0x48)) * f5;
  v = v - d;
  u32 o; __builtin_memcpy(&o, &v, 4);
  self[0xf1] = o; self[0xf2] = o >> 8; self[0xf3] = o >> 16; self[0xf4] = o >> 24;
  if (G(float, 0x678858) > v) {
    *(u32 *)(self + 4) = 3;
    self[0xec] = 0;
    return 0;
  }
  *(float *)(self + 0x88) = v;
  return 1;
}
PCREG(44bc00, fn44bc00);

// 0x4f9600, thiscall no args, returns AL: [this+0..0xb] = 0; p = unaligned [[0x70039c]+0x1a9f] == 0 -> 0; else [this], [this+4], [this+8], [this+0xc] = slot 0x68 of p (re-read each time) with
// 0x69b6c4, 0x69b6d0, 0x69b6dc, 0x69b6e4; returns 1.
static u8 THISCALL fn4f9600(u8 *self) {
  *(u32 *)(self + 0) = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  u8 *eng = G(u8 *, 0x70039c);
  void *p = (void *)rd32(eng + 0x1a9f);
  if (!p) return 0;
  *(u32 *)(self + 0) = vcall<u32>(p, 0x68, 0x69b6c4u);
  p = (void *)rd32(G(u8 *, 0x70039c) + 0x1a9f);
  *(u32 *)(self + 4) = vcall<u32>(p, 0x68, 0x69b6d0u);
  p = (void *)rd32(G(u8 *, 0x70039c) + 0x1a9f);
  *(u32 *)(self + 8) = vcall<u32>(p, 0x68, 0x69b6dcu);
  p = (void *)rd32(G(u8 *, 0x70039c) + 0x1a9f);
  *(u32 *)(self + 0xc) = vcall<u32>(p, 0x68, 0x69b6e4u);
  return 1;
}
PCREG(4f9600, fn4f9600);
