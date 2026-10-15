// batch50008.cpp - cascade u3, tier H, batch 50008: 0x4669f0 (build an orthonormal frame from a forward vector and a ground offset).
#include "ff.h"

extern "C" void FASTCALL ext_441940(u8 *a, u8 *b);             // a += b (vec3)
extern "C" void FASTCALL ext_446ee0(u8 *out, u8 *p, u8 *q);    // ret 4: out = cross(p, q)
extern "C" void FASTCALL ext_633654(u32 cookie);               // /GS check

// x87 normalisation: when any component is nonzero (or NaN): len = fsqrt(x*x + y*y + z*z) and every component becomes (float)(c * (1.0 / len)), all in long double (x87, control word precision).
static void normalise(float *f) {
  if (f[0] != 0.0f || f[1] != 0.0f || f[2] != 0.0f) {
    long double x2 = (long double)f[0] * (long double)f[0];
    long double y2 = (long double)f[1] * (long double)f[1];
    x2 = x2 + y2;
    long double z2 = (long double)f[2] * (long double)f[2];
    x2 = x2 + z2;
    long double len = fsqrt_x87(x2);
    long double inv = 1.0L / len;
    f[0] = (float)((long double)f[0] * inv);
    f[1] = (float)((long double)f[1] * inv);
    f[2] = (float)((long double)f[2] * inv);
  }
}

// 0x4669f0, thiscall(a, b) ret 8, /GS, void: this slot 0x390(0, a, &t); b = (0, 115.0f (0x42e60000), 0) + t (ext_441940); a[0xc..0x14] = (0, 1.0f, 0); a[0..2] = cross(a+0x18, a+0xc) (ext_446ee0); normalise a[0..2];
// a+0x18 = cross(a+0xc, a); normalise a+0x18; this slot 0x98(a, b).
static void THISCALL fn4669f0(u8 *self, u8 *a, u8 *b) {
  float t[3];
  vcall<void>(self, 0x390, 0, (u32)a, (u32)t);
  *(u32 *)b = 0;
  *(u32 *)(b + 4) = 0x42e60000;
  *(u32 *)(b + 8) = 0;
  ext_441940(b, (u8 *)t);
  *(u32 *)(a + 0xc) = 0;
  *(u32 *)(a + 0x10) = 0x3f800000;
  *(u32 *)(a + 0x14) = 0;
  ext_446ee0(a, a + 0x18, a + 0xc);
  normalise((float *)a);
  ext_446ee0(a + 0x18, a + 0xc, a);
  normalise((float *)(a + 0x18));
  vcall<void>(self, 0x98, (u32)a, (u32)b);
  ext_633654(0);
}
PCREG(4669f0, fn4669f0);
