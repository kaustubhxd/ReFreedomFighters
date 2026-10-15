// batch40007.cpp - cascade t1 (Sonnet), tier H: 0x4c1e30, 0x5517a0, 0x4e1e30, 0x610250, 0x4e2bb0.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *s);                                // plain ret, eax = value
extern "C" float THISCALL ext_4e5e80(u8 *s);                              // plain ret, float on st0
extern "C" u32 *THISCALL ext_5003d0(void *self, u32 i);                   // thiscall ret 4
extern "C" void THISCALL ext_5002f0(void *self, u32 v);                   // thiscall ret 4
extern "C" void THISCALL ext_500360(void *self, float v);                 // thiscall ret 4
extern "C" void FASTCALL ext_43e920(void *ecx, void *edx, void *q);       // fastcall, 1 stack arg
extern "C" void FASTCALL ext_4e0d40(void *ecx, void *edx, float f);       // fastcall, 1 stack float
extern "C" void FASTCALL ext_441940(void *ecx, void *edx);                // fastcall, plain ret
extern "C" void FASTCALL ext_446ee0(void *ecx, void *edx, void *q);       // fastcall, 1 stack arg
extern "C" double VECTORCALL ext_634d7c(double);                          // CRT sqrt, argument/result in XMM0

static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4c1e30, thiscall(a, s) ret 8 (a unused): k = ext_4e5e60(s): 0, 1, 2 -> [this+0x48] = k (other values leave it); [this+0x4c], [this+0x50], [this+0x54] = three more ext_4e5e60(s) values;
// byte [this+0x58] = (ext_4e5e60(s) != 0); kind = byte [[s]]; kind != 0xff and (kind & 0x3f) == 2 -> three ext_4e5e80(s) floats at unaligned [this+0x59], [this+0x5d], [this+0x61].
static void THISCALL fn4c1e30(u8 *self, u32 a, u8 *s) {
  (void)a;
  u32 k = ext_4e5e60(s);
  if (k == 0) *(u32 *)(self + 0x48) = 0;
  else if (k == 1) *(u32 *)(self + 0x48) = 1;
  else if (k == 2) *(u32 *)(self + 0x48) = 2;
  *(u32 *)(self + 0x4c) = ext_4e5e60(s);
  *(u32 *)(self + 0x50) = ext_4e5e60(s);
  *(u32 *)(self + 0x54) = ext_4e5e60(s);
  self[0x58] = ext_4e5e60(s) != 0;
  u8 kind = **(u8 **)s;
  if (kind != 0xff && (kind & 0x3f) == 2) {
    wr32(self + 0x59, fbits(ext_4e5e80(s)));
    wr32(self + 0x5d, fbits(ext_4e5e80(s)));
    wr32(self + 0x61, fbits(ext_4e5e80(s)));
  }
}
PCREG(4c1e30, fn4c1e30);

// 0x5517a0, stdcall(a, b, c) ret 0xc, returns o: o = a->slot 0x18(b); o == 0 -> 0; p = o->slot 0x4c(); ext_5002f0(*ext_5003d0(p, 0), [c]); ext_500360(*ext_5003d0(p, 1), float [c+4]); ... 2 with [c+8], 3 with [c+0xc]; returns o.
static u32 STDCALL fn5517a0(u8 *a, u32 b, u32 *c) {
  u8 *o = vcall<u8 *>(a, 0x18, b);
  if (!o) return 0;
  u8 *p = vcall<u8 *>(o, 0x4c);
  ext_5002f0(ext_5003d0(p, 0), c[0]);
  ext_500360(ext_5003d0(p, 1), bitsf(c[1]));
  ext_500360(ext_5003d0(p, 2), bitsf(c[2]));
  ext_500360(ext_5003d0(p, 3), bitsf(c[3]));
  return (u32)o;
}
PCREG(5517a0, fn5517a0);

// 0x4e1e30, fastcall(this, d, a, b, c) ret 0xc, returns float: t = b - d (ext_43e920); dot = c.y*a.y + c.x*a.x + c.z*a.z; dot == K(0x6785d0) -> this = {0x7e967699 x3}, returns K(0x67cd44);
// else r = -((a.x*t.x + a.y*t.y) + a.z*t.z) / dot; this = c * r (ext_4e0d40); this += b (ext_441940); returns r.
static float FASTCALL fn4e1e30(u8 *self, u8 *d, float *a, float *b, float *c) {
  float t[3];
  ext_43e920(t, b, d);
  float xa = a[0], ya = a[1], za = a[2];
  float dot = c[1] * ya + c[0] * xa;
  dot = dot + c[2] * za;
  if (dot == G(float, 0x6785d0)) {
    u32 *w = (u32 *)self;
    w[0] = 0x7e967699; w[1] = 0x7e967699; w[2] = 0x7e967699;
    return G(float, 0x67cd44);
  }
  float num = xa * t[0] + ya * t[1];
  num = num + za * t[2];
  float r = bitsf(fbits(num / dot) ^ G(u32, 0x67af40));
  ext_4e0d40(self, c, r);
  ext_441940(self, b);
  return r;
}
PCREG(4e1e30, fn4e1e30);

// 0x610250, thiscall(A, B, C, D, E, F) ret 0x18: builds a 4x4-style block: [0] = 2E/(B-A); [0x14] = 2E/(C-D); [0x20] = (A+B)/(B-A) - [0]*(A+B); [0x24] = (C+D)/(C-D) - [0x14]*(C+D); g = F/(F-E); [0x28] = g; [0x38] = -(g*E);
// [0x2c] = 1.0; dwords 4, 8, 0xc, 0x10, 0x18, 0x1c, 0x30, 0x34, 0x3c = 0.
static void THISCALL fn610250(u8 *self, float A, float B, float C, float D, float E, float F) {
  float *m = (float *)self;
  u32 *w = (u32 *)self;
  float den = F - E;
  float bma = B - A;
  float apb = A + B;
  w[1] = 0; w[2] = 0; w[3] = 0; w[4] = 0; w[6] = 0; w[7] = 0; w[0xb] = 0x3f800000; w[0xc] = 0; w[0xd] = 0; w[0xf] = 0;
  float g = F / den;
  float twoE = E + E;
  float cmd = C - D;
  float cpd = C + D;
  m[0xa] = g;
  m[0xe] = bitsf(fbits(g * E) ^ 0x80000000u);
  float x0 = twoE / bma;
  float x5 = twoE / cmd;
  m[0] = x0;
  m[8] = apb / bma - x0 * apb;
  m[5] = x5;
  m[9] = cpd / cmd - x5 * cpd;
}
PCREG(610250, fn610250);

// 0x4e2bb0, fastcall(arr, n) returns float: acc = {0, 0, 0}; for i < n: ext_446ee0(tmp, arr + ((i + 1 == n) ? 0 : i + 1) * 12, arr + i * 12); ext_441940(acc, tmp); returns (float)sqrt((double)(y*y + x*x + z*z)) * K(0x67a6ac).
static float FASTCALL fn4e2bb0(u8 *arr, u32 n) {
  float acc[3] = {0, 0, 0};
  for (u32 i = 0; i != n; i++) {
    float tmp[3];
    u32 nx = (i + 1 == n) ? 0 : i + 1;
    ext_446ee0(tmp, arr + nx * 12, arr + i * 12);
    ext_441940(acc, tmp);
  }
  float s = acc[1] * acc[1];
  s = s + acc[0] * acc[0];
  s = s + acc[2] * acc[2];
  float len = (float)ext_634d7c((double)s);
  return len * G(float, 0x67a6ac);
}
PCREG(4e2bb0, fn4e2bb0);
