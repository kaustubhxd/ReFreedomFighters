// batch40005.cpp - cascade t1 (Sonnet), tier H: 0x524810, 0x4fdac0, 0x5eda70, 0x4f0790, 0x57f580.
#include "ff.h"

extern "C" void THISCALL ext_5ed170(u8 *self, u8 *o);          // thiscall ret 4
extern "C" double ext_634dca(double);                           // CRT routine (floor), double on the stack (cdecl), result in st0
extern "C" void THISCALL ext_57f6b0(u8 *self);                  // thiscall, plain ret

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static u8 *sysobj() { return G(u8 *, 0x70039c); }
static u8 *engTable() { return (u8 *)rd32(sysobj() + 0x9b); }

// 0x524810, thiscall(o) ret 4, returns al = 1: for i in 0..5: o->slot 0x4c(float [this + i*4]).
static u32 THISCALL fn524810(u8 *self, u8 *o) {
  for (int i = 0; i < 6; i++) vcall<void>(o, 0x4c, *(u32 *)(self + i * 4));
  return 1;
}
PCREG(524810, fn524810);

// 0x4fdac0, thiscall(): a = engine table slot 0x138(); f1 = 0; a->slot 0x84(0x6954e8, &f1); b = engine table slot 0x138(); f2 = 0; b->slot 0x84(0x6954f8, &f2);
// both floats equal to zero -> f2 = K(0x67c1ac), f1 = K(0x68d448); [[this+0x44]+0x70] = f1; [[this+0x44]+0x74] = f2.
static void THISCALL fn4fdac0(u8 *self) {
  float f1 = 0, f2 = 0;
  u8 *a = vcall<u8 *>(engTable(), 0x138);
  vcall<void>(a, 0x84, (u32)0x6954e8, (u32)&f1);
  u8 *b = vcall<u8 *>(engTable(), 0x138);
  vcall<void>(b, 0x84, (u32)0x6954f8, (u32)&f2);
  if (f1 == 0.0f && f2 == 0.0f) {
    f2 = G(float, 0x67c1ac);
    f1 = G(float, 0x68d448);
  }
  u8 *o = *(u8 **)(self + 0x44);
  *(float *)(o + 0x70) = f1;
  o = *(u8 **)(self + 0x44);
  *(float *)(o + 0x74) = f2;
}
PCREG(4fdac0, fn4fdac0);

// 0x5eda70, thiscall(o) ret 4: ext_5ed170(this, o); o->slot 0x4c(unaligned [this+0xd7]); slot 0x4c([this+0xdb]); slot 0x3c at +0xdf, +0xe3, +0xe7, +0xeb; slot 0x44 at +0xef, +0xf3.
static void THISCALL fn5eda70(u8 *self, u8 *o) {
  ext_5ed170(self, o);
  vcall<void>(o, 0x4c, rd32(self + 0xd7));
  vcall<void>(o, 0x4c, rd32(self + 0xdb));
  vcall<void>(o, 0x3c, rd32(self + 0xdf));
  vcall<void>(o, 0x3c, rd32(self + 0xe3));
  vcall<void>(o, 0x3c, rd32(self + 0xe7));
  vcall<void>(o, 0x3c, rd32(self + 0xeb));
  vcall<void>(o, 0x44, rd32(self + 0xef));
  vcall<void>(o, 0x44, rd32(self + 0xf3));
}
PCREG(5eda70, fn5eda70);

// 0x4f0790, thiscall(p) ret 4: flags = byte [this+0x20]; byte [this+0xa7] set and flags & 0x10: x = (float)(s32)[unaligned [this+0x9f]]->slot 0x284() * K(0x67c1a8) + K(0x679540);
// else flags & 0xf0 == 0 -> nothing; else x = -[p+4] (sign mask 0x67af40), + [[this+8]+0x44] when flags & 0x10, - it when flags & 0x20, + K(0x679540); unaligned float [this+0x42] = (float)floor((double)x).
static void THISCALL fn4f0790(u8 *self, u8 *p) {
  float x;
  if (self[0xa7] && (self[0x20] & 0x10)) {
    s32 n = vcall<s32>((u8 *)rd32(self + 0x9f), 0x284);
    x = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(n))) * G(float, 0x67c1a8);
    x = x + G(float, 0x679540);
  } else {
    u8 cl = self[0x20];
    if (!(cl & 0xf0)) return;
    x = bitsf(fbits(*(float *)(p + 4)) ^ G(u32, 0x67af40));
    if (cl & 0x10) x = x + *(float *)(*(u8 **)(self + 8) + 0x44);
    if (cl & 0x20) x = x - *(float *)(*(u8 **)(self + 8) + 0x44);
    x = x + G(float, 0x679540);
  }
  float f = (float)ext_634dca((double)x);
  wr32(self + 0x42, fbits(f));
}
PCREG(4f0790, fn4f0790);

// 0x57f580, thiscall(a, n) ret 8, returns al = 0 (a unused): o1 = sys->slot 0xbc(); o1->slot 0xac((float)((double)(s32)n + [0x680aa0 + (n>>31)*8]) * K(0x681dc4));
// o2 = sys->slot 0xbc(); e = this->slot 0x84(); f = o2->slot 0xa8() (st0); e->slot 0x314(f) (vtable of e read before the 0xa8 call); ext_57f6b0(this).
static u32 THISCALL fn57f580(u8 *self, u32 a, u32 n) {
  (void)a;
  u8 *s = sysobj();
  u8 *o1 = vcall<u8 *>(s, 0xbc);
  float f = (float)((double)(s32)n + G(double, 0x680aa0 + (n >> 31) * 8));
  vcall<void>(o1, 0xac, fbits(f * G(float, 0x681dc4)));
  u8 *o2 = vcall<u8 *>(sysobj(), 0xbc);
  u8 *e = vcall<u8 *>(self, 0x84);
  u32 slot = rd32(*(u8 **)e + 0x314);
  float g = vcall<float>(o2, 0xa8);
  ((void(THISCALL *)(u8 *, float))slot)(e, g);
  ext_57f6b0(self);
  return 0;
}
PCREG(57f580, fn57f580);
