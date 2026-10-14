// batch35185.cpp - cascade s5 batch 35185 (tier H): 0x443330 (GUESS cull a candidate array against a box: query the scene, then drop the entries the per-entry test rejects).
#include "ff.h"

extern "C" u32 *THISCALL ext_4e3180(u32 *L);                                   // sets L[0] = 1.0f
extern "C" void FASTCALL ext_4e2c60(float *mat, float *v);                      // v = abs(mat) * v (in place), plain ret
extern "C" void FASTCALL ext_43e920(float *out, float *a, float *b);            // out = a - b, ret 4
extern "C" void FASTCALL ext_43e8e0(float *out, float *a, float *b);            // out = a + b, ret 4
extern "C" void FASTCALL ext_4de420(float *dst, float *src);                    // copies 0x24 bytes, plain ret
extern "C" void THISCALL ext_4daf90(u8 *self, float *out);                      // copies self[0x30..0x3b], ret 4
extern "C" void THISCALL ext_4de7a0(float *m);                                  // identity into 0x24 bytes
extern "C" void THISCALL ext_4db600(u8 *self, float *m, float *z);              // ret 8
extern "C" u8 FASTCALL ext_4df330(float *y, float *w, u32 a, float *m, float *z, u8 *p);   // ret 0x10
typedef u8 *(THISCALL *o1_t)(void *, u32);
typedef void(THISCALL *q3_t)(void *, u32 *, float *, float *);
typedef void(THISCALL *w2_t)(void *, float *, float *);

// 0x443330, thiscall(arr, a2, a3, mat, c, half, a7, flag) ret 0x20, returns the surviving count (the stack cookie is not reproduced). obj = this slot 0x340(a3); null returns 0.
// L = {1.0f, vtable 0x442fc0, ..., +0x5c = a7, +0x60 = arr, +0x64 = a2, +0x68 = 0}; V = half[0..2]; 0x4e2c60(mat, V); X1 = c - V; X2 = c + V; obj slot 0x1c(L, X1, X2) (fills the count at L+0x68).
// With the flag (low byte) and a non-zero count: W = c[0..2]; Y = copy of mat; this slot 0x98(Y, W); the count is re-read; for each index i of arr (from the front): e = arr[i]; Z = e[0x30..]; M = identity; 0x4db600(e, M, Z);
// when 0x4df330(Y, W, half, M, Z, e + 0x40) is false the entry is replaced by the last one and the count shrinks. Returns the count.
static u32 THISCALL fn443330(u8 *self, u32 *arr, u32 a2, u32 a3, float *mat, float *c, float *half, u32 a7, u32 flag) {
  u32 L[0x1b];
  float V[3], X1[3], X2[3], W[3], Z[3], M[9], Y[9];
  u8 *obj = (*(o1_t **)self)[0x340 / 4](self, a3);
  if (!obj) return 0;
  ext_4e3180(L);
  V[0] = half[0];
  V[1] = half[1];
  V[2] = half[2];
  L[1] = 0x442fc0;
  L[0x5c / 4] = a7;
  L[0x60 / 4] = (u32)arr;
  L[0x64 / 4] = a2;
  L[0x68 / 4] = 0;
  ext_4e2c60(mat, V);
  ext_43e920(X1, c, V);
  ext_43e8e0(X2, c, V);
  (*(q3_t **)obj)[0x1c / 4](obj, L, X1, X2);
  u32 cnt = L[0x68 / 4];
  if ((u8)flag == 0 || cnt == 0) return cnt;
  W[0] = c[0];
  W[1] = c[1];
  W[2] = c[2];
  ext_4de420(Y, mat);
  (*(w2_t **)self)[0x98 / 4](self, Y, W);
  cnt = L[0x68 / 4];
  if (cnt == 0) return 0;
  u32 i = 0;
  u32 *last = arr + (cnt - 1);
  do {
    u8 *e = (u8 *)arr[i];
    ext_4daf90(e, Z);
    ext_4de7a0(M);
    ext_4db600(e, M, Z);
    u8 ok = ext_4df330(Y, W, (u32)half, M, Z, e + 0x40);
    if (!ok) {
      cnt--;
      arr[i] = *last;
      i--;
      last--;
    }
    i++;
  } while (i != cnt);
  return cnt;
}
PCREG(443330, fn443330);
