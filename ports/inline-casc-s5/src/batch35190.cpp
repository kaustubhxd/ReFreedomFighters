// batch35190.cpp - cascade s5 batch 35190 (tier H): 0x4ecd30 (GUESS collect the scene objects inside a box, then cull them with the per-entry test).
#include "ff.h"

extern "C" u32 *THISCALL ext_4e3180(u32 *L);                                   // sets L[0] = 1.0f
extern "C" void FASTCALL ext_4e2c60(float *mat, float *v);                      // v = abs(mat) * v, plain ret
extern "C" void FASTCALL ext_43e920(float *out, float *a, float *b);            // out = a - b, ret 4
extern "C" void FASTCALL ext_43e8e0(float *out, float *a, float *b);            // out = a + b, ret 4
extern "C" void THISCALL ext_4daf90(u8 *self, float *out);                      // ret 4
extern "C" void THISCALL ext_4de7a0(float *m);                                  // identity into 0x24 bytes
extern "C" void THISCALL ext_4db600(u8 *self, float *m, float *z);              // ret 8
extern "C" u8 FASTCALL ext_4df330(float *y, float *w, u32 a, float *m, float *z, u8 *p);   // ret 0x10
extern "C" void THISCALL ext_4e4420(u8 *self, u32 *L, float *x1, float *x2);    // ret 0xc
extern "C" void THISCALL ext_4ec6d0(u32 *L);                                    // plain ret
typedef u8 *(THISCALL *g0_t)(void *);

static u32 gL[0x41e];   // the original keeps this 0x1078-byte record on its stack; static here to avoid a stack probe

// 0x4ecd30, stdcall(arr, a2, a3, items, count, mat, c, half, a9, flag) ret 0x28, returns the surviving count (the stack cookie is not reproduced). M = ([[engine+0x9b]+0xadc]) slot 0x314(); null returns 0.
// L = {1.0f, vtable 0x4edd40, +0x5c = arr, +0x60 = a2, +0x64 = 0, +0x68 = a9, +0x6c = a3, +0x70 = 0, +0x1074 = 0}. With count != 0: V = half; 0x4e2c60(mat, V); X1 = c - V; X2 = c + V; for each i < count: L[+0x70] = items[i]; 0x4e4420(M, L, X1, X2); then 0x4ec6d0(L);
// n = L[+0x64]. With the flag byte set and n != 0: the same cull as 0x443330: Z = e[0x30..]; identity M2; 0x4db600(e, M2, Z); when 0x4df330(mat, c, half, M2, Z, e + 0x40) (ecx = mat, edx = c) is false the entry is replaced by the last one. Returns n.
static u32 STDCALL fn4ecd30(u32 *arr, u32 a2, u32 a3, u32 *items, u32 count, float *mat, float *c, float *half, u32 a9, u32 flag) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *mgr = *(u8 **)(tab + 0xadc);
  u8 *M = (*(g0_t **)mgr)[0x314 / 4](mgr);
  if (!M) return 0;
  u32 *L = gL;
  float V[3], X1[3], X2[3], Z[3], M2[9];
  ext_4e3180(L);
  L[1] = 0x4edd40;
  L[0x5c / 4] = (u32)arr;
  L[0x60 / 4] = a2;
  L[0x64 / 4] = 0;
  L[0x68 / 4] = a9;
  L[0x6c / 4] = a3;
  L[0x70 / 4] = 0;
  L[0x1074 / 4] = 0;
  u32 n = 0;
  if (count != 0) {
    V[0] = half[0];
    V[1] = half[1];
    V[2] = half[2];
    ext_4e2c60(mat, V);
    ext_43e920(X1, c, V);
    ext_43e8e0(X2, c, V);
    for (u32 i = 0; i != count; i++) {
      L[0x70 / 4] = items[i];
      ext_4e4420(M, L, X1, X2);
    }
    ext_4ec6d0(L);
    n = L[0x64 / 4];
  }
  if ((u8)flag == 0 || n == 0) return n;
  u32 i = 0;
  u32 *last = arr + (n - 1);
  do {
    u8 *e = (u8 *)arr[i];
    ext_4daf90(e, Z);
    ext_4de7a0(M2);
    ext_4db600(e, M2, Z);
    u8 ok = ext_4df330(mat, c, (u32)half, M2, Z, e + 0x40);
    if (!ok) {
      n--;
      arr[i] = *last;
      i--;
      last--;
    }
    i++;
  } while (i != n);
  return n;
}
PCREG(4ecd30, fn4ecd30);
