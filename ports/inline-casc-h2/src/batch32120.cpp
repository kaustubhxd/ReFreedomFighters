// batch32120.cpp - cascade h2 (Sonnet): tier H (float / SSE) functions, batch 32120.
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                 // thiscall ret 4
extern "C" void THISCALL ext_500360(u8 *self, float a);              // thiscall ret 4
extern "C" float THISCALL ext_4e5e80(u8 *self);                      // thiscall, plain ret, float in st0
extern "C" u8 *THISCALL ext_4e5ea0(u8 *self);                        // thiscall, plain ret, returns a char pointer
extern "C" void FASTCALL ext_43e920(void *out, const void *a, const void *b);   // x87 vector subtract: out = a - b (ecx, edx, stack arg ret 4)
extern "C" u32 THISCALL ext_478f90(u8 *self, float t);               // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                     // /GS check

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x59a8f0, thiscall no args (/GS frame): o = unaligned [this+0x1d07]; o != 0 -> slot 0x240 of o fills buf[4]; x = buf[2], y = buf[3]; [this+0x1d23] = (float)[[0x70039c]+0x6f]*x; [this+0x1d1b] = x; v = (float)[[0x70039c]+0x73]*y;
// [this+0x1d1f] = y; o == 0 -> [0x1d1b] = [0x1d1f] = 1.0f, [0x1d23] = (float)[eng+0x6f], v = (float)[eng+0x73]; [this+0x1d27] = v; /GS check (unaligned fields).
static void THISCALL fn59a8f0(u8 *self) {
  float buf[4];
  void *o = (void *)rd32(self + 0x1d07);
  float v;
  u8 *eng;
  if (o) {
    vcall<void>(o, 0x240, (u32)buf);
    float x = buf[2], y = buf[3];
    eng = G(u8 *, 0x70039c);
    float a = (float)(s32)rd32(eng + 0x6f) * x;
    u32 ab; __builtin_memcpy(&ab, &a, 4); wr32(self + 0x1d23, ab);
    eng = G(u8 *, 0x70039c);
    float b = (float)(s32)rd32(eng + 0x73);
    u32 xb; __builtin_memcpy(&xb, &x, 4); wr32(self + 0x1d1b, xb);
    v = b * y;
    u32 yb; __builtin_memcpy(&yb, &y, 4); wr32(self + 0x1d1f, yb);
  } else {
    wr32(self + 0x1d1b, 0x3f800000);
    wr32(self + 0x1d1f, 0x3f800000);
    eng = G(u8 *, 0x70039c);
    float a = (float)(s32)rd32(eng + 0x6f);
    u32 ab; __builtin_memcpy(&ab, &a, 4); wr32(self + 0x1d23, ab);
    eng = G(u8 *, 0x70039c);
    v = (float)(s32)rd32(eng + 0x73);
  }
  u32 vb; __builtin_memcpy(&vb, &v, 4); wr32(self + 0x1d27, vb);
  ext_633654(0);
}
PCREG(59a8f0, fn59a8f0);

// 0x5510e0, stdcall(p, a, v) ret 0xc, returns b: b = slot 0x18 of p with a; b == 0 -> 0; q = slot 0x4c of b; 0x500360(0x5003d0(q, i), float v[i]) for i = 0, 1, 2; returns b.
static u32 STDCALL fn5510e0(void *p, u32 a, u32 *v) {
  void *b = vcall<void *>(p, 0x18, a);
  if (!b) return 0;
  void *q = vcall<void *>(b, 0x4c);
  for (u32 i = 0; i < 3; i++) {
    float f; __builtin_memcpy(&f, &v[i], 4);
    u32 r = ext_5003d0((u8 *)q, i);
    ext_500360((u8 *)r, f);
  }
  return (u32)b;
}
PCREG(5510e0, fn5510e0);

// 0x4cb030, thiscall(a) ret 4, returns true: the string at 0x4e5ea0(a) (with its NUL) is copied to this+0x48; [this+0x8c] = 0; floats [this+0x70], [0x74], [0x78], [0x80], [0x7c] = five 0x4e5e80(a);
// f6 = sixth 0x4e5e80(a); [this+0x7c] -= [this+0x78]; [this+0x68] = 0; [this+0x84] = f6 - [this+0x80]; [this+0x6c] = 0.
static bool THISCALL fn4cb030(u8 *self, u8 *a) {
  const u8 *s = ext_4e5ea0(a);
  u8 *d = self + 0x48;
  u8 ch;
  do { ch = *s++; *d++ = ch; } while (ch);
  *(u32 *)(self + 0x8c) = 0;
  *(float *)(self + 0x70) = ext_4e5e80(a);
  *(float *)(self + 0x74) = ext_4e5e80(a);
  *(float *)(self + 0x78) = ext_4e5e80(a);
  *(float *)(self + 0x80) = ext_4e5e80(a);
  *(float *)(self + 0x7c) = ext_4e5e80(a);
  float f6 = ext_4e5e80(a);
  float d7 = *(float *)(self + 0x7c) - *(float *)(self + 0x78);
  *(u32 *)(self + 0x68) = 0;
  *(float *)(self + 0x7c) = d7;
  *(float *)(self + 0x84) = f6 - *(float *)(self + 0x80);
  *(u32 *)(self + 0x6c) = 0;
  return true;
}
PCREG(4cb030, fn4cb030);

// 0x478c10, thiscall(out, float t) ret 8: m = [this+0xc]; t < 0 -> out = (m+0x14) - (m+4) (0x43e920, x87 vector subtract); t >= float [this+4] (ordered) -> out = (m - 0xc + [this+8]*16) - (m - 0x1c + [this+8]*16);
// otherwise i = 0x478f90(this, t) and out = (m + 4 + i*16) - (m - 0xc + i*16).
static void THISCALL fn478c10(u8 *self, u8 *out, float t) {
  u8 *m = *(u8 **)(self + 0xc);
  if (0.0f > t) {
    ext_43e920(out, m + 0x14, m + 4);
    return;
  }
  if (t >= *(float *)(self + 4)) {
    u32 k = *(u32 *)(self + 8) << 4;
    ext_43e920(out, m - 0xc + k, m - 0x1c + k);
    return;
  }
  u32 i = ext_478f90(self, t) << 4;
  m = *(u8 **)(self + 0xc);
  ext_43e920(out, m + 4 + i, m - 0xc + i);
}
PCREG(478c10, fn478c10);
