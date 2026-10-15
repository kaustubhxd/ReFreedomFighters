// batch45000.cpp - tier H slice 5 (t6, Sonnet): two thiscall helpers that finish with len = sqrt(|P.v|^2) + K, 0x4dce50(P, len).
#include "ff.h"

extern "C" void THISCALL ext_4dc600(void *, void *);
extern "C" void THISCALL ext_4dd060(void *, void *);
extern "C" void THISCALL ext_4dce50(void *, float);
extern "C" double VECTORCALL ext_634d7c(double);   // CRT sqrt

typedef u32 __attribute__((aligned(1))) u32u;

// P = this[8]; v = P+0x40 (3 floats); 0x4dce50(P, (float)sqrt(v.x^2+v.y^2+v.z^2) + K(0x678858)).
static inline void finish_len(u8 *p) {
  float x = *(float *)(p + 0x40), y = *(float *)(p + 0x44), z = *(float *)(p + 0x48);
  x = x * x;
  y = y * y;
  z = z * z;
  x = x + y;
  x = x + z;
  float len = (float)ext_634d7c((double)x);
  len = len + *(float *)0x678858;
  ext_4dce50(p, len);
}

// 0x451b30: P=this[8]: 0x4dc600(P,this+0x24), 0x4dd060(P,this+0x18), then the length tail.
static void THISCALL fn_451b30(u8 *self) {
  void *p = *(void **)(self + 8);
  ext_4dc600(p, self + 0x24);
  p = *(void **)(self + 8);
  ext_4dd060(p, self + 0x18);
  finish_len(*(u8 **)(self + 8));
}
PCREG(451b30, fn_451b30);

// 0x4483a0: P=this[8]; if P[0x6c]: engine(0x70039c)[+0x1aa3 unaligned][+0x18] slot 0x114(P[0x6c], P+0x30, P+0x40); then the length tail on the reloaded this[8].
static void THISCALL fn_4483a0(u8 *self) {
  u8 *p = *(u8 **)(self + 8);
  if (*(u32 *)(p + 0x6c)) {
    u8 *eng = *(u8 **)0x70039c;
    u8 *a = (u8 *)*(u32u *)(eng + 0x1aa3);
    void *c = *(void **)(a + 0x18);
    vcall<void>(c, 0x114, *(u32 *)(p + 0x6c), (void *)(p + 0x30), (void *)(p + 0x40));
    finish_len(*(u8 **)(self + 8));
  }
}
PCREG(4483a0, fn_4483a0);
