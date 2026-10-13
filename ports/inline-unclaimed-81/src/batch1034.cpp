// batch1034.cpp - area 81, batch 1034: 0x546fa0, stdcall (a, b, out, v, s, f), ret 0x18. No SEH frame, no cookie check.
// Copies v to out. If the dot product d = v.s is below zero, out += -d * s (0x451890, real exe code), then if |out|^2 is above 9.0
// (threshold at 0x68aefc) out is cleared, else out is scaled by 0.9 (0x4e0d00, real exe code). The tail calls 0x443ef0 (real exe code,
// fastcall with a, b and two stack arguments: s and f). No stand-ins: the helpers are the exe's own code (linked by ext_<hex>).
#include "ff.h"

extern "C" void __attribute__((fastcall)) ext_451890(void *ecx, void *edx, float k);   // real exe code: this = out, vec = s, k on stack
extern "C" void THISCALL ext_4e0d00(void *self, float k);                             // real exe code: this = out, k on stack
extern "C" void __attribute__((fastcall)) ext_443ef0(void *ecx, void *edx, float *s, float f); // real exe code

// 0x546fa0 (stdcall: a, b, out, v, s, f).
static void __attribute__((stdcall)) vecClampStep(void *a, void *b, float *out, float *v, float *s, float f) {
  out[0] = v[0];
  out[1] = v[1];
  out[2] = v[2];
  float d = v[1] * s[1] + v[0] * s[0];
  d = d + v[2] * s[2];
  if (0.0f > d) {
    ext_451890(out, s, -d);
    float l = out[0] * out[0] + out[1] * out[1];
    l = l + out[2] * out[2];
    float thr = *(volatile float *)0x68aefc;
    if (thr > l) {
      out[0] = 0.0f;
      out[1] = 0.0f;
      out[2] = 0.0f;
    } else {
      ext_4e0d00(out, 0.9f);
    }
  }
  ext_443ef0(a, b, s, f);
}
PCREG(546fa0, vecClampStep);
