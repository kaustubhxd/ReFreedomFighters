// batch859.cpp - area 50 (residue-9 candidate): 0x5434d0 [106 instr, FASTCALL with three float stack args (ret 0xc); no name
// in the map (GUESS "move B toward A along the normal of A - B")]. v = A - B; d = |v|. When d is below 1e-6 the vector is
// replaced by three engine samples (vt +0x1c4, with the file and line 0x893) until d is above 1e-6. N = v / d. Then
// t = (d - p3) * p2 / (p1 + p2), B += t * N (0x451890), and A = B + p3 * N (0x443ef0, the x87 helper).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);                    // d = a - b (exe)
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);                         // out = a * s (exe)
extern "C" void FASTCALL ext_451890(float *out, const float *vec, float s);                       // out += s * vec (exe)
extern "C" void FASTCALL ext_443ef0(float *out, const float *q, const float *v, float ratio);     // out = v*ratio + q (exe)

// 0x5434d0 (name GUESS).
static void FASTCALL Fn5434d0(float *B, float *A, float p1, float p2, float p3) {
  typedef double(VECTORCALL * sqrt_t)(double);
  float v[3], N[3];
  ext_43e920(v, A, B);
  float l = v[0] * v[0];
  float m = v[1] * v[1];
  l = l + m;
  l = l + v[2] * v[2];
  float dist = (float)(*(sqrt_t *)0x676330)((double)l);
  if (G(float, 0x681370) > dist) {
    do {
      u8 *eng = G(u8 *, 0x70039c);
      v[0] = vcall<float>(eng, 0x1c4, (u32)0x6a2e20, 0x893u);
      eng = G(u8 *, 0x70039c);
      v[1] = vcall<float>(eng, 0x1c4, (u32)0x6a2e20, 0x893u);
      eng = G(u8 *, 0x70039c);
      v[2] = vcall<float>(eng, 0x1c4, (u32)0x6a2e20, 0x893u);
      float a = v[0] * v[0];
      float b = v[1] * v[1];
      float c = a + b;
      c = c + v[2] * v[2];
      dist = (float)(*(sqrt_t *)0x676330)((double)c);
    } while (G(float, 0x681370) > dist);
  }
  ext_4e0d40(N, v, G(float, 0x678858) / dist);
  float s12 = p1 + p2;
  float t1 = G(float, 0x678858) / s12;
  float t = t1 * ((dist - p3) * p2);
  ext_451890(B, N, t);
  ext_443ef0(A, B, N, p3);
}
PCREG(5434d0, Fn5434d0);
