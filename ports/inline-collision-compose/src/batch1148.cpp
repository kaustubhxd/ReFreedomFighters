// batch1148.cpp - collision thread, batch 1148 (hard-row lane, name GUESS): 0x55bd60. Thiscall (ECX = this), one stack argument X,
// ret 4 (void port; the exe's EAX on return is not compared). Helpers are exe code: 0x5003d0 (list accessor), 0x43e920
// (PSVECSubtract, fastcall + stack), 0x43e960 (fastcall), 0x4e0d00 (vscalar, fastcall + stack float), 0x451890 (vaddscalar,
// fastcall + stack float). Virtual: O = [this+0x1c]: slot 0x84 (out vector), slot 0x5d0 (returns R), R slot 0x218; sys object:
// slot 0x1c0 returns a float in ST0. Logger 0x700390 / hook 0x7003b0 on the odd type paths. The stack frame's exception-free
// layout is kept; the cookie check is omitted.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(void *list, u32 idx);
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // PSVECSubtract: ecx out, edx a, stack b, ret 4
extern "C" void FASTCALL ext_43e960(float *out, const float *in);                 // ecx out, edx in, plain ret
extern "C" void FASTCALL ext_4e0d00(float *v, float s);                           // vscalar: ecx v, stack s, ret 4
extern "C" void FASTCALL ext_451890(float *a, float *b, float u);                 // vaddscalar: ecx a, edx b, stack u, ret 4

typedef void (*CdeclLog3)(void *, u32, u32);
typedef void (*CdeclVoid)(void);

// The logger path of the element-type branches: slot 0x20 of the logger (0x69c8e0, 0xd5) opens a stream; its slot 0x2c is cdecl
// (stream, 0x69c6b0, 0x69c938); then the hook at 0x7003b0 (cdecl, no arguments) when set.
static void logAndHook55bd60(void) {
  void *S = vcall<void *>(G(void *, 0x700390), 0x20, 0x69c8e0u, 0xd5u);
  CdeclLog3 f = (CdeclLog3)((*(void ***)S)[0x2c / 4]);
  f(S, 0x69c6b0u, 0x69c938u);
  CdeclVoid h = (CdeclVoid)G(void *, 0x7003b0);
  if (h) h();
}

static void THISCALL run55bd60(u8 *self, u8 *X) {
  u8 *L = *(u8 **)(X + 4);
  float V1[3];
  V1[0] = *(float *)ext_5003d0(L, 0);
  V1[1] = *(float *)ext_5003d0(L, 1);
  V1[2] = *(float *)ext_5003d0(L, 2);
  float s = *(float *)ext_5003d0(L, 3);
  u8 *O = *(u8 **)(self + 0x1c);
  float V2[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(O, 0x84, (u32)V2);
  float V3[3];
  ext_43e920(V3, V1, V2);
  V3[1] = 0.0f;
  if (!(V3[0] == 0.0f && V3[2] == 0.0f)) {
    double x = (double)V3[0];
    double y = 0.0;
    double z = (double)V3[2];
    double sum = ((x * x) + (y * y)) + (z * z);
    double len = crt::sqrt(sum);
    double inv = 1.0 / len;
    V3[0] = (float)(x * inv);
    V3[1] = (float)(y * inv);
    V3[2] = (float)(z * inv);
    float V4[3];
    V4[0] = V3[2];
    V4[1] = 0.0f;
    V4[2] = -V3[0];
    ext_4e0d00(V3, s);
    float v = vcall<float>(G(void *, 0x70039c), 0x1c0, 0x6a5eb0u, 0x655u);
    float t = (float)((double)v * (double)s);
    float a2 = t + t;
    float u = a2 - s;
    ext_451890(V3, V4, u);
  }
  ext_43e960(V1, V3);
  V1[1] = V1[1] + G(float, 0x67da24);
  u8 *R = vcall<u8 *>(O, 0x5d0);
  if (R != 0) vcall<void>(R, 0x218, (u32)V1, 10.0f, 10.0f, 1.0f);
  u8 *E = (u8 *)ext_5003d0(*(u8 **)(X + 8), 0);
  if (E[4] == 0 || E[4] == 2) {
    *(float *)E = V1[0];
    E[4] = 2;
  } else {
    logAndHook55bd60();
  }
  E = (u8 *)ext_5003d0(*(u8 **)(X + 8), 1);
  if (E[4] == 0 || E[4] == 2) {
    *(float *)E = V1[1];
    E[4] = 2;
  } else {
    logAndHook55bd60();
  }
  E = (u8 *)ext_5003d0(*(u8 **)(X + 8), 2);
  if (E[4] == 0 || E[4] == 2) {
    *(float *)E = V1[2];
    E[4] = 2;
  } else {
    logAndHook55bd60();
  }
}
PCREG(55bd60, run55bd60);
