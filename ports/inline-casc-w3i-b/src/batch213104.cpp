#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V7)(void *, u32, u32, u32, u32, u32, u32, u32);
typedef u32(THISCALL *V8)(void *, u32, u32, u32, u32, u32, u32, u32, u32);
typedef double(THISCALL *VD2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_4664a0(void *self, float f);
extern "C" void FASTCALL ext_441940(void *a, void *b);
extern "C" u32 THISCALL ext_4db3b0(void *self);
extern "C" void THISCALL ext_581b60(void *r, void *m);
extern "C" void FASTCALL ext_4de040(void *n, void *m, u32 zero);
extern "C" void THISCALL ext_4e09b0(void *n);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x591480: thiscall(float f) ret 4, /GS protected. When this[0x417] has none of the bits 0x0c000000 it only forwards f to 0x4664a0(this, f).
// Otherwise: A = table slot 0x160(0xb6), B = table slot 0x58(A[0x18]) (assert hook [0x7003b0] when B[0xc]'s dword +0x23 lacks bit 0x100000); a probe vector
// V = (0, 200, -50) (z = 0 unless this[0x417] & 3) is nudged by two engine randoms W = (r1, 0, r2) with r = (float)(rand * [0x680a84] - [0x685270]) (x87 double precision),
// 0x441940(V, W) and this slot 0x84(V); a ray query on [[0x70039c]+0x1aa3]->[0x1c] slot 0x30(&R, 0, V, P1 = (0, -200, 0), 0, 4, 1, 0) fills R (R[0] preset 1.0f); if it hits and
// X = 0x4db3b0(this[8]) is nonzero, a basis N is built from R (0x581b60 -> M, slot 0x88 of R[0x10]->[0x54], 0x4de040), its first two rows swapped, 0x4e09b0(N), then
// X slot 0x94(N, L = R[1..3]) and B slot 0x1bc(X, N, L, 0, 0, 0, 1) are called.
extern "C" void THISCALL fn_591480(u8 *self, float f) {
  if ((rd32u(self + 0x417) & 0x0c000000) == 0) {
    ext_4664a0(self, f);
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  u8 *eng = G(u8 *, 0x70039c);
  u8 *T = (u8 *)rd32u(eng + 0x9b);
  u8 *A = (u8 *)(*(V1 *)(vt(T) + 0x160))(T, 0xb6);
  if (A == nullptr) {
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  eng = G(u8 *, 0x70039c);
  T = (u8 *)rd32u(eng + 0x9b);
  u8 *B = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, rd32u(A + 0x18));
  if (B == nullptr) {
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  u8 *Bc = (u8 *)rd32u(B + 0xc);
  if ((rd32u(Bc + 0x23) & 0x100000) == 0) {
    typedef void (*Hook)();
    Hook h = G(Hook, 0x7003b0);
    if (!h) __builtin_trap();
    h();
  }
  float V[3], W[3], P1[3], L[3], M[9], N[9];
  u32 R[10];
  V[0] = 0.0f;
  V[1] = 200.0f;
  V[2] = -50.0f;
  if ((self[0x417] & 3) == 0) V[2] = 0.0f;
  eng = G(u8 *, 0x70039c);
  double d1 = (*(VD2 *)(vt(eng) + 0x1c0))(eng, 0x6ac6d0, 0x145e);
  W[1] = 0.0f;
  W[0] = (float)(d1 * (double)G(float, 0x680a84) - (double)G(float, 0x685270));
  eng = G(u8 *, 0x70039c);
  double d2 = (*(VD2 *)(vt(eng) + 0x1c0))(eng, 0x6ac6d0, 0x145e);
  W[2] = (float)(d2 * (double)G(float, 0x680a84) - (double)G(float, 0x685270));
  ext_441940(V, W);
  (*(V1 *)(vt(self) + 0x84))(self, (u32)V);
  P1[0] = 0.0f;
  P1[1] = -200.0f;
  P1[2] = 0.0f;
  R[0] = 0x3f800000;
  eng = G(u8 *, 0x70039c);
  u8 *G1 = (u8 *)rd32u(eng + 0x1aa3);
  u8 *O = (u8 *)rd32u(G1 + 0x1c);
  u32 ok = (*(V8 *)(vt(O) + 0x30))(O, (u32)R, 0, (u32)V, (u32)P1, 0, 4, 1, 0);
  if ((u8)ok == 0) {
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  u8 *X = (u8 *)ext_4db3b0((void *)rd32u(self + 8));
  if (X == nullptr) {
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  ext_581b60(R, M);
  u8 *H = (u8 *)rd32u((u8 *)R + 0x10);
  u8 *Hq = (u8 *)rd32u(H + 0x54);
  (*(V1 *)(vt(Hq) + 0x88))(Hq, (u32)M);
  ext_4de040(N, M, 0);
  float x0 = N[3], x1 = N[0], x2 = N[1], x3 = N[2];
  N[0] = x0;
  x0 = N[4];
  N[1] = x0;
  x0 = N[5];
  N[2] = x0;
  N[3] = x1;
  N[4] = x2;
  N[5] = x3;
  ext_4e09b0(N);
  __builtin_memcpy(&L[0], (u8 *)R + 4, 4);
  __builtin_memcpy(&L[1], (u8 *)R + 8, 4);
  __builtin_memcpy(&L[2], (u8 *)R + 12, 4);
  (*(V2 *)(vt(X) + 0x94))(X, (u32)N, (u32)L);
  (*(V7 *)(vt(B) + 0x1bc))(B, (u32)X, (u32)N, (u32)L, 0, 0, 0, 1);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(591480, fn_591480);
