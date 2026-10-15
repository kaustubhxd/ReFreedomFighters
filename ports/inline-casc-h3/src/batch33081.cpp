// batch33081.cpp - h3 (Sonnet) batch 33081: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

extern "C" void THISCALL ext_469870(u8 *self);                          // plain ret
extern "C" u8 *THISCALL ext_4d8fc0(u8 *self, u32 a);                    // ret 4
extern "C" float THISCALL ext_516130(u8 *self, u32 b, u32 d);           // ret 8, float in st0
extern "C" void THISCALL ext_5244d0(u8 *self, u32 x, u32 y);            // ret 8
extern "C" float THISCALL ext_4e5e80(u8 *self);                         // float in st0
extern "C" u16 THISCALL ext_4e5e40(u8 *self);                           // ax
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                           // eax
extern "C" void ext_42ab62(const void *fmt, double d);                  // cdecl
extern "C" u32 THISCALL ext_512be0(u8 *self, u32 a);                    // ret 4
extern "C" u32 THISCALL ext_512ca0(u8 *self, u32 a);                    // ret 4
extern "C" u32 THISCALL ext_512db0(u8 *self, u32 a);                    // ret 4

// 0x4f1290: thiscall(u32 *p, unused) ret 8: when (float)[this+0x22] != p[0] or (float)[this+0x26] != p[1] (NaN counts as different): copy both, byte [this+0x90]=1, slot 0x228()
static void THISCALL fn4f1290(u8 *self, u32 *p, u32 unused) {
  (void)unused;
  float a = *(float *)(self + 0x22), b = *(float *)(self + 0x26);
  float p0 = bitsf(p[0]), p1 = bitsf(p[1]);
  if (a == p0 && b == p1) return;
  u32 q0 = p[0];
  *(u32 *)(self + 0x22) = q0;
  *(u32 *)(self + 0x26) = p[1];
  self[0x90] = 1;
  vcall<u32>(self, 0x228);
}
PCREG(4f1290, fn4f1290);

// 0x5bd6d0: thiscall no args: 0x469870(this); [4]|=0x20; [0x44]=0; vtable=0x6b33b4; [0x48..0x68)=0; [0x68]=[0x6c]=0; [0x70]=-1; [0x7d]=0 (unaligned); returns this
static u8 *THISCALL fn5bd6d0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b33b4;
  for (int i = 0; i < 8; i++) *(u32 *)(self + 0x48 + 4 * i) = 0;
  *(u32 *)(self + 0x68) = 0;
  *(u32 *)(self + 0x6c) = 0;
  *(u32 *)(self + 0x70) = 0xffffffff;
  self[0x7d] = 0; self[0x7e] = 0; self[0x7f] = 0; self[0x80] = 0;
  return self;
}
PCREG(5bd6d0, fn5bd6d0);

// 0x4d70e0: thiscall(a, u8 *out1, u32 *out2) ret 0xc: p = 0x4d8fc0(this+4, a); 0 -> false; else *out2 = [p+0x1a]; out1[0..0x10) = p[0..0x10), out1[0x10..0x18) = p+0x10, out1[0x18..0x1a) = p+0x18; true
static u8 THISCALL fn4d70e0(u8 *self, u32 a, u8 *out1, u32 *out2) {
  u8 *p = ext_4d8fc0(self + 4, a);
  if (!p) return 0;
  u32 t = *(u32 *)(p + 0x1a);
  *out2 = t;
  __builtin_memcpy(out1, p, 16);
  u64 q = *(u64 *)(p + 0x10);
  *(u64 *)(out1 + 0x10) = q;
  u16 w = *(u16 *)(p + 0x18);
  *(u16 *)(out1 + 0x18) = w;
  return 1;
}
PCREG(4d70e0, fn4d70e0);

// 0x5165d0: thiscall(float a, byte c, float b, u32 d) ret 0x10: x = -1e38 const; when (u8)c: x = 0x516130(this, b, d); 0x5244d0(this+0x41, x, a)
static void THISCALL fn5165d0(u8 *self, u32 a, u32 c, u32 b, u32 d) {
  u32 x = 0xfe967699;
  if ((u8)c) x = fbits(ext_516130(self, b, d));
  ext_5244d0(self + 0x41, x, a);
}
PCREG(5165d0, fn5165d0);

// 0x476200: thiscall(stream) ret 4: [this+0x48]=float e80(s); [0x4c]=u16 e40(s); [0x4e]=u32 e60(s) (unaligned); byte [0x56] = e60(s) != 0
static void THISCALL fn476200(u8 *self, u8 *s) {
  float f = ext_4e5e80(s);
  *(float *)(self + 0x48) = f;
  u16 w = ext_4e5e40(s);
  *(u16 *)(self + 0x4c) = w;
  u32 d = ext_4e5e60(s);
  self[0x4e] = d; self[0x4f] = d >> 8; self[0x50] = d >> 16; self[0x51] = d >> 24;
  self[0x56] = ext_4e5e60(s) != 0;
}
PCREG(476200, fn476200);

// 0x4f85c0: thiscall(float x) ret 4: x == 0 -> return; v = [this+0x9f] + x, stored; v < 0 -> 0; v > 1.0 -> 1.0; tail slot 0x374(1)
static void THISCALL fn4f85c0(u8 *self, u32 xb) {
  float x = bitsf(xb);
  if (x == 0.0f) return;
  float v = *(float *)(self + 0x9f) + x;
  *(float *)(self + 0x9f) = v;
  if (0.0f > v) *(u32 *)(self + 0x9f) = 0;
  v = *(float *)(self + 0x9f);
  if (v > 1.0f) *(u32 *)(self + 0x9f) = 0x3f800000;
  vcall<u32>(self, 0x374, 1u);
}
PCREG(4f85c0, fn4f85c0);

// 0x6401f0: thiscall(s32 a) ret 4: f = (float)((double)a + (a<0 ? 2^32 : 0)) * 2^-20 (float); ext 0x42ab62(fmt 0x6c25f0, (double)f) cdecl; [this+0x10] = a
static void THISCALL fn6401f0(u8 *self, s32 a) {
  double d = (double)a + ((u32)a >> 31 ? 4294967296.0 : 0.0);
  float f = (float)d;
  f = f * 9.5367431640625e-07f;
  ext_42ab62((const void *)0x6c25f0, (double)f);
  *(s32 *)(self + 0x10) = a;
}
PCREG(6401f0, fn6401f0);

// 0x512e10: thiscall(a) ret 4: [this+4]==0 -> return; t=[sys+0x40] (s32); (int)([this+0xc]*1024) > t -> 0x512be0(this,a); else (int)([this+0x10]*1024) > t -> 0x512ca0; else 0x512db0
static void THISCALL fn512e10(u8 *self, u32 a) {
  if (*(u32 *)(self + 4) == 0) return;
  s32 t = *(s32 *)(SYS + 0x40);
  s32 k1 = _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0xc) * 1024.0f));
  if (t < k1) { ext_512be0(self, a); return; }
  s32 k2 = _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x10) * 1024.0f));
  if (t < k2) { ext_512ca0(self, a); return; }
  ext_512db0(self, a);
}
PCREG(512e10, fn512e10);
