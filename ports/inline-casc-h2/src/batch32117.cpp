// batch32117.cpp - cascade h2 (): tier H (float / SSE) functions, batch 32117.
#include "ff.h"

extern "C" u32 FASTCALL ext_4de420(void *dst, const void *src);                              // 36-byte copy (verified)
extern "C" void FASTCALL ext_633654(u32 cookie);                                             // /GS check
extern "C" void THISCALL ext_467410(u8 *self, u32 a, u32 b, u32 c0, u32 c1, u32 c2, u32 c3);  // thiscall ret 0x18
typedef u32 (STDCALL *s1_t)(u32);
typedef u32 (STDCALL *s4_t)(u32, u32, u32, u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x654940, thiscall(src, p1, p2) ret 0xc (/GS frame): buf[0..8] = 36 bytes of src (0x4de420); buf[9..11] = p1[0..2], buf[12..14] = p2[0..2];
// h = Decode(Decode(unaligned [this+0x137])) (stdcall import 0x676244 twice); import 0x67621c(h, 0x7e4, &buf, 0); /GS check.
static void THISCALL fn654940(u8 *self, u8 *src, u32 *p1, u32 *p2) {
  u32 buf[16];
  ext_4de420(buf, src);
  buf[9] = p1[0]; buf[10] = p1[1]; buf[11] = p1[2];
  buf[12] = p2[0]; buf[13] = p2[1]; buf[14] = p2[2];
  u32 h = G(s1_t, 0x676244)(rd32(self + 0x137));
  h = G(s1_t, 0x676244)(h);
  G(s4_t, 0x67621c)(h, 0x7e4, (u32)buf, 0);
  ext_633654(0);
}
PCREG(654940, fn654940);

// 0x485f90, thiscall no args, returns eax with the low byte cleared: s = slot 0x10 of the object m = [this+0xc]; 0x467410(m+4, [this+8], 0, 0, 0, 0, 0xffffffff); slot 8 of m with ([this+8], 0);
// slot 0x2d0 of s with (0, 0); r = slot 0x4f4 of [this+8] with s; returns r & ~0xff.
static u32 THISCALL fn485f90(u8 *self) {
  void *m = *(void **)(self + 0xc);
  void *s = vcall<void *>(m, 0x10);
  ext_467410(*(u8 **)(self + 0xc) + 4, *(u32 *)(self + 8), 0, 0, 0, 0, 0xffffffffu);
  vcall<void>(*(void **)(self + 0xc), 8, *(u32 *)(self + 8), 0u);
  vcall<void>(s, 0x2d0, 0u, 0u);
  u32 r = vcall<u32>(*(void **)(self + 8), 0x4f4, (u32)s);
  return r & 0xffffff00u;
}
PCREG(485f90, fn485f90);

// 0x5230e0, thiscall no args: byte [this+0x41] != 0 and [this+0x39] == 1; x2 = unaligned float [this+0x5f]; g = x2 == 0 ? 0 : ((0 - f24)*(0 - f24)) / x2 * K(0x67a6ac) (f24 = [this+0x24]);
// g < [this+0x30] (or unordered) -> return; else slot 0x24 of this with (f30 + K2(0x680a70), 0) gives a float v; slot 8 of this with (0, v); [this+0x39] = 2.
static void THISCALL fn5230e0(u8 *self) {
  if (!self[0x41]) return;
  if (*(s32 *)(self + 0x39) != 1) return;
  u32 xb = rd32(self + 0x5f);
  float x2; __builtin_memcpy(&x2, &xb, 4);
  float f24 = *(float *)(self + 0x24);
  float neg = 0.0f - f24;
  float g = 0.0f;
  if (!(x2 == 0.0f)) {
    g = neg * neg;
    g = g / x2;
    g = g * G(float, 0x67a6ac);
  }
  float f30 = *(float *)(self + 0x30);
  if (!(g >= f30)) return;
  float v = vcall<float>(self, 0x24, f30 + G(float, 0x680a70), 0u);
  vcall<void>(self, 8, 0u, v);
  *(u32 *)(self + 0x39) = 2;
}
PCREG(5230e0, fn5230e0);
