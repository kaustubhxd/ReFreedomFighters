// batch33092.cpp - h3 () batch 33092: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

extern "C" void FASTCALL ext_43e920(float *out, u8 *src, u8 *arg);   // ecx=out, edx=src, stack arg, ret 4

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x4f1b80: thiscall(a, b, c, float d, byte e) ret 0x14: t = table slot 0x4c(c); this->slot 0x350(a, b, c); r = [this+0x9f]->slot 0x98(a, d, 0); r[4]=a; r[0xc]=e; r[0]=t; r[8]=b; return r
static u8 *THISCALL fn4f1b80(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u32 t = vcall<u32>(tab, 0x4c, c);
  vcall<u32>(self, 0x350, a, b, c);
  u8 *sub = self + 0x9f;
  u8 *vt = (u8 *)R32(sub);
  typedef u8 *(THISCALL * fn_t)(u8 *, u32, u32, u32);
  u8 *r = (*(fn_t *)(vt + 0x98))(sub, a, d, 0u);
  r[0xc] = (u8)e;
  W32(r + 4, a);
  W32(r, t);
  W32(r + 8, b);
  return r;
}
PCREG(4f1b80, fn4f1b80);

// 0x51c470: thiscall no args, bool: [0x55a]=1.0; byte [0x592]=0; [0x526..0x532) = [0x60..0x6c); [0x532]=0, [0x536]=-1500.0 (0xc4bb8000), [0x53a]=0; o=[[sys+0x9b]+0xadc]; o->slot 0x2e0(this+0x526, 0, 0x20, 0x200000, 1, 0): ok: [0x597]=max(0, [0x64]-[0x552]), true; else [0x597]=1500.0, false
static u8 THISCALL fn51c470(u8 *self) {
  W32(self + 0x55a, 0x3f800000);
  self[0x592] = 0;
  u8 *e = self + 0x526;
  W32(e, R32(self + 0x60));
  W32(e + 4, R32(self + 0x64));
  W32(e + 8, R32(self + 0x68));
  W32(self + 0x532, 0);
  W32(self + 0x536, 0xc4bb8000);
  W32(self + 0x53a, 0);
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u8 *o = *(u8 **)(tab + 0xadc);
  u8 ok = vcall<u8>(o, 0x2e0, (u32)e, 0u, 0x20u, 0x200000u, 1u, 0u);
  if (!ok) {
    W32(self + 0x597, 0x44bb8000);
    return 0;
  }
  float d = bitsf(R32(self + 0x64)) - bitsf(R32(self + 0x552));
  W32(self + 0x597, fbits(d));
  if (0.0f > d) W32(self + 0x597, 0);
  return 1;
}
PCREG(51c470, fn51c470);

// 0x530b60: thiscall(u16 *out, float *p) ret 8: v = 0x43e920(this+0x12 - (this+6)); out[0] = (int)((p0-[+6])/v0*(float)[+0x3c]); out[1] = (int)((p2-[+0xe])/v2*(float)[+0x40]); out[2] = (int)((p1-[+0xa])/v1*(float)[+0x44])
static void THISCALL fn530b60(u8 *self, u16 *out, float *p) {
  float v[3];
  ext_43e920(v, self + 0x12, self + 6);
  float w = (float)*(s32 *)(self + 0x3c);
  float x = bitsf(((u32 *)p)[0]) - bitsf(R32(self + 6));
  float y = bitsf(((u32 *)p)[1]) - bitsf(R32(self + 0xa));
  float z = bitsf(((u32 *)p)[2]) - bitsf(R32(self + 0xe));
  x = x / v[0];
  y = y / v[1];
  z = z / v[2];
  x = x * w;
  s32 ix = _mm_cvttss_si32(_mm_set_ss(x));
  y = y * (float)*(s32 *)(self + 0x44);
  out[0] = (u16)ix;
  z = z * (float)*(s32 *)(self + 0x40);
  out[1] = (u16)_mm_cvttss_si32(_mm_set_ss(z));
  out[2] = (u16)_mm_cvttss_si32(_mm_set_ss(y));
}
PCREG(530b60, fn530b60);
