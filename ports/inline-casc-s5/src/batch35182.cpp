// batch35182.cpp - cascade s5 batch 35182 (tier H): 0x5df1c0 (GUESS read a transform record: two angle pairs packed in dwords, as direction vectors).
#include "ff.h"

extern "C" void THISCALL ext_5de9a0(u8 *self, u8 *s);              // thiscall(s) ret 4
extern "C" void THISCALL ext_4e0d80(u8 *self, float a);            // thiscall(float) ret 4
extern "C" double VECTORCALL ext_634d76(double);                   // CRT routine (sin), argument/result in XMM0
extern "C" double VECTORCALL ext_634d70(double);                   // CRT routine (cos), argument/result in XMM0
typedef u8 *(THISCALL *rd_t)(void *, void *);
typedef void(THISCALL *rd1_t)(void *, void *);

// Decodes one packed dword x: a = ((float)(x >> 16) / K1 * 2) * K2 - K2 (the elevation), b = ((float)(x & 0xffff) / K1 * 2) * K2 (the azimuth);
// *sinOut = (float)sin(a); *cc = (float)(cos(b) * cos(a)); *sc = (float)(sin(b) * cos(a)). K1 = float at 0x6b7308, K2 = float at 0x67da18, T0 = double at 0x680aa0 (added to the unsigned-to-double conversion).
static void unpackDir(u32 x, float *sinOut, float *cc, float *sc) {
  float K1 = G(float, 0x6b7308), K2 = G(float, 0x67da18);
  double T0 = G(double, 0x680aa0);
  float h = (float)((double)(int)(x >> 16) + T0);
  float l = (float)((double)(int)(x & 0xffff) + T0);
  h = h / K1;
  h = h + h;
  h = h * K2;
  h = h - K2;
  l = l / K1;
  float a = h;
  float b = l;
  *sinOut = (float)ext_634d76((double)a);
  b = b + b;
  b = b * K2;
  double ca = ext_634d70((double)a);
  double cb = ext_634d70((double)b);
  *cc = (float)(cb * ca);
  double sb = ext_634d76((double)b);
  *sc = (float)(sb * ca);
}

// 0x5df1c0, thiscall(s) ret 4, no return value. 0x5de9a0(this, s); r = s slot 0x40(this+8); r slot 0x40(this+0xc); s slot 0x6c(this+0x10); s slot 0x40(&x); s slot 0x50(&f);
// unpackDir(x) into this+0x20 (sin), +0x1c, +0x24; 0x4e0d80(this+0x1c, f); s slot 0x40(&x); unpackDir(x) into this+0x2c, +0x28, +0x30; s slot 0x40(this+0x34).
static void THISCALL fn5df1c0(u8 *self, u8 *s) {
  u32 x;
  float f;
  ext_5de9a0(self, s);
  u8 *r = (*(rd_t **)s)[0x40 / 4](s, self + 8);
  (*(rd_t **)r)[0x40 / 4](r, self + 0xc);
  (*(rd1_t **)s)[0x6c / 4](s, self + 0x10);
  (*(rd1_t **)s)[0x40 / 4](s, &x);
  (*(rd1_t **)s)[0x50 / 4](s, &f);
  unpackDir(x, (float *)(self + 0x20), (float *)(self + 0x1c), (float *)(self + 0x24));
  ext_4e0d80(self + 0x1c, f);
  (*(rd1_t **)s)[0x40 / 4](s, &x);
  unpackDir(x, (float *)(self + 0x2c), (float *)(self + 0x28), (float *)(self + 0x30));
  (*(rd1_t **)s)[0x40 / 4](s, self + 0x34);
}
PCREG(5df1c0, fn5df1c0);
