// batch32093.cpp - cascade h2 (): eight tier H (float / SSE) small functions.
#include "ff.h"

extern "C" void THISCALL ext_5a83e0(u8 *self, float f);   // thiscall ret 4, one float stack argument

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x473b50, thiscall no args: when the float constant at 0x67c198 is greater than the float [this+0x1e2] (unaligned; unordered compares do not store) the field becomes 1.0f.
static void THISCALL fn473b50(u8 *self) {
  float c = G(float, 0x67c198);
  u32 bits = rd32(self + 0x1e2);
  float f;
  __builtin_memcpy(&f, &bits, 4);
  if (c > f) {
    self[0x1e2] = 0; self[0x1e3] = 0; self[0x1e4] = 0x80; self[0x1e5] = 0x3f;
  }
}
PCREG(473b50, fn473b50);

// 0x5243d0, thiscall(float a) ret 4: [this+0xc] = a.
static void THISCALL fn5243d0(u8 *self, float a) {
  *(float *)(self + 0xc) = a;
}
PCREG(5243d0, fn5243d0);

// 0x4ce680, thiscall(p) ret 4, returns float: p[[this+0x18] - 3].
static float THISCALL fn4ce680(u8 *self, float *p) {
  s32 i = *(s32 *)(self + 0x18);
  return p[i - 3];
}
PCREG(4ce680, fn4ce680);

// 0x4ea8e0, thiscall(float a, float b) ret 8: [this+0x60] = a; [this+0x64] = b.
static void THISCALL fn4ea8e0(u8 *self, float a, float b) {
  *(float *)(self + 0x60) = a;
  *(float *)(self + 0x64) = b;
}
PCREG(4ea8e0, fn4ea8e0);

// 0x5370b0, thiscall(i) ret 4, returns the x87 product: float at this + i*9 + 0x5159 (unaligned) times the float constant at 0x67cd40, exact in double.
static double THISCALL fn5370b0(u8 *self, u32 i) {
  u32 bits = rd32(self + i * 9 + 0x5159);
  float f;
  __builtin_memcpy(&f, &bits, 4);
  return (double)f * (double)G(float, 0x67cd40);
}
PCREG(5370b0, fn5370b0);

// 0x5afce0, thiscall(out) ret 4: copies 20 bytes from this to out.
static void THISCALL fn5afce0(u8 *self, u8 *out) {
  for (int i = 0; i < 20; i++) out[i] = self[i];
}
PCREG(5afce0, fn5afce0);

// 0x5e0df0, thiscall no args: o = [this+0x1d0f] (unaligned) != 0 -> 0x5a83e0(o, float [this+0x1d17]).
static void THISCALL fn5e0df0(u8 *self) {
  u8 *o = (u8 *)rd32(self + 0x1d0f);
  if (!o) return;
  u32 bits = rd32(self + 0x1d17);
  float f;
  __builtin_memcpy(&f, &bits, 4);
  ext_5a83e0(o, f);
}
PCREG(5e0df0, fn5e0df0);

// 0x515930, thiscall(float a, b) ret 8: returns slot 0x2f8 of this with (a, b).
static u32 THISCALL fn515930(void *self, float a, u32 b) {
  return vcall<u32>(self, 0x2f8, a, b);
}
PCREG(515930, fn515930);
