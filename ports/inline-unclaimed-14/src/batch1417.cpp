// batch1417.cpp - unclaimed-14 batch 17 (residue 13): FUN_5c1910 (GUESS name), an initializer on the engine's objects.
#include "ff.h"

// 0x5c1aa0: a loop over a table; stubbed in the spec (GUESS: its effects are not modelled; the call itself is checked).
extern "C" void THISCALL ext_5c1aa0(u8 *self);

// 0x5c1910 (GUESS: FUN_5c1910; the name is not in the map): thiscall, no arguments, plain ret. Sequence (PC):
//  r = (global+0x9b)->O[+0x25c](0x6b3bc0, 0), O = (global+0x9b)+0xadc;  this+0xe0 = r.
//  if r == 0: r2 = O[+0x294](0x6b3bc0, 0x67f610, 0, 1);  this+0xe0 = r2;
//             S = B[+0x138]();   Y = B[+0x4c](X = this+0xe0, 2);   S[+0x60](0x6b3bc0, Y).   (B = global+0x9b)
//  if byte [this+0x10c] == 0:
//      K = [0x70038c]; v = K[+0x20](this);
//      if v == 0 and K[+8] != 0 and K[+0xc] <= this and this < K[+0x10]: edx = K[+8](this)  (call eax, ecx = this)
//      else if v == 0: if [this-4] == 0: K[+0xac](this);  edx = [this-4]
//      else: edx = 0
//      X[+0x21c](edx) with X = this+0xe0.
//  T = [0x7003b8]+0x2c15; if byte T+0x103f == 0: this+0xe4 = 0x6eef68, this+0xe8 = 0;
//      else: this+0x88 = 0xa, this+0xe4 = 0x6eef78, this+0xe8 = 3, this+0x48 = 7, this+0x4c = 7.
//  P = this+0x44; if P[+0x1e0](0x100001) (al) then e = P else e = P[+0x20]();   this+0x10d = e;
//  ext_5c1aa0(this);   P[+0x3c](1).
static void THISCALL fun5c1910(u8 *self) {
  typedef u32(THISCALL * f_t)(u8 *, u32, u32);
  typedef u32(THISCALL * f4_t)(u8 *, u32, u32, u32, u32);
  typedef u32(THISCALL * f0_t)(u8 *);
  typedef u32(THISCALL * f1_t)(u8 *, u32);
  typedef void(THISCALL * v1_t)(u8 *, u32);
  u8 *g = G(u8 *, 0x70039c);
  u8 *b = *(u8 **)(g + 0x9b);
  u8 *o = *(u8 **)(b + 0xadc);
  u32 r = (*(f_t *)(*(u32 *)o + 0x25c))(o, 0x6b3bc0u, 0u);
  *(u32 *)(self + 0xe0) = r;
  if (r == 0) {
    u32 r2 = (*(f4_t *)(*(u32 *)o + 0x294))(o, 0x6b3bc0u, 0x67f610u, 0u, 1u);
    *(u32 *)(self + 0xe0) = r2;
    u8 *s = (u8 *)(*(f0_t *)(*(u32 *)b + 0x138))(b);
    u32 y = (*(f_t *)(*(u32 *)b + 0x4c))(b, *(u32 *)(self + 0xe0), 2u);
    (*(f_t *)(*(u32 *)s + 0x60))(s, 0x6b3bc0u, y);
  }
  if (self[0x10c] == 0) {
    u8 *k = G(u8 *, 0x70038c);
    u32 v = (*(f1_t *)(*(u32 *)k + 0x20))(k, (u32)self);
    u32 edx;
    if (v == 0) {
      u32 k8 = *(u32 *)(k + 8);
      if (k8 != 0 && !(*(u32 *)(k + 0xc) > (u32)self) && !((u32)self >= *(u32 *)(k + 0x10))) {
        edx = ((f0_t)k8)(self);
      } else {
        if (*(u32 *)(self - 4) == 0)
          (*(f1_t *)(*(u32 *)k + 0xac))(k, (u32)self);
        edx = *(u32 *)(self - 4);
      }
    } else {
      edx = 0;
    }
    u8 *x = *(u8 **)(self + 0xe0);
    (*(f1_t *)(*(u32 *)x + 0x21c))(x, edx);
  }
  u8 *t = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c15);
  if (t[0x103f] == 0) {
    *(u32 *)(self + 0xe4) = 0x6eef68;
    *(u32 *)(self + 0xe8) = 0;
  } else {
    *(u32 *)(self + 0x88) = 0xa;
    *(u32 *)(self + 0xe4) = 0x6eef78;
    *(u32 *)(self + 0xe8) = 3;
    *(u32 *)(self + 0x48) = 7;
    *(u32 *)(self + 0x4c) = 7;
  }
  u8 *p = *(u8 **)(self + 0x44);
  u32 e;
  if ((u8)(*(f1_t *)(*(u32 *)p + 0x1e0))(p, 0x100001u))
    e = (u32)p;
  else
    e = (*(f0_t *)(*(u32 *)p + 0x20))(p);
  *(u32 *)(self + 0x10d) = e;
  ext_5c1aa0(self);
  (*(v1_t *)(*(u32 *)p + 0x3c))(p, 1u);
}
PCREG(5c1910, fun5c1910);
