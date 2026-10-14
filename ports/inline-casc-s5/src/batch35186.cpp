// batch35186.cpp - cascade s5 batch 35186 (tier H): 0x5129c0 (GUESS refresh a scene object: re-register its ids, re-place its attachments and re-resolve its children).
#include "ff.h"

extern "C" void FASTCALL ext_4de040(float *p, float *r, u32 z);                 // ret 4
extern "C" u8 *THISCALL ext_4db3b0(u8 *self);                                   // plain ret
extern "C" void THISCALL ext_45fb00(u8 *self, u32 a, u32 b, u32 c);            // ret 0xc
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(THISCALL *p2_t)(void *, float *, float *);
typedef void(THISCALL *u2_t)(void *, void *, void *);
typedef u32(THISCALL *g1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5129c0, thiscall, no args, no return value (the stack cookie is not reproduced). this slot 0x338(); for each id pointer from this+0xde (count = dword [+0xda]): id = engine[+0x9b] slot 0x4c(*p);
// this slot 0x2e0(id, unaligned dword [+0x11f]) (vtable read before the 0x4c call). byte [+0x215] = 1. X = [+0x134]; when set: this slot 0x80(&P, &Q); R = {P[0], 0, P[2]}; 0x4de040(P, R, 0); X slot 0x7c(&P, &Q); X slot 0x2c();
// o = 0x4db3b0([this+8]); o slot 0x288(X, 0, 1); r = engine[+0x9b] slot 0x4c(X); 0x45fb00(this, r, word [+0x20f], 0). Then this slot 0x28(). Y = [+0x138]: null sets [+0xc4] = 0; otherwise this slot 0x324(1); Y slot 0x7c(this+0x6c, this+0x60);
// Y slot 0x2c(); the nodes of the list at [Y+0x50] (next at +0x60) each give a child [node+0x54] whose slot 0x2c() is called and which is collected; then this slot 0x288(child, 0, 1) for each collected child in order.
// Finally the float [this+0x1c9] = 20.0 (0x41a00000).
static void THISCALL fn5129c0(u8 *self) {
  (*(v0_t **)self)[0x338 / 4](self);
  u32 count = *(u32 *)(self + 0xda);
  u32 *p = (u32 *)(self + 0xde);
  u32 *end = (u32 *)(self + 0xde + count * 4);
  if (p != end) {
    do {
      u8 *eng = G(u8 *, 0x70039c);
      u8 *tab = *(u8 **)(eng + 0x9b);
      u32 **vt = *(u32 ***)self;
      u32 id = (*(g1_t **)tab)[0x4c / 4](tab, *p);
      ((v2_t)vt[0x2e0 / 4])(self, id, rd32u(self + 0x11f));
      p++;
      end = (u32 *)(self + 0xde + *(u32 *)(self + 0xda) * 4);
    } while (p != end);
  }
  self[0x215] = 1;
  u8 *X = *(u8 **)(self + 0x134);
  if (X) {
    float P[9], Q[3], R[3];
    (*(p2_t **)self)[0x80 / 4](self, P, Q);
    R[0] = P[0];
    R[2] = P[2];
    R[1] = 0;
    ext_4de040(P, R, 0);
    X = *(u8 **)(self + 0x134);
    (*(p2_t **)X)[0x7c / 4](X, P, Q);
    X = *(u8 **)(self + 0x134);
    (*(v0_t **)X)[0x2c / 4](X);
    u8 *o = ext_4db3b0(*(u8 **)(self + 8));
    (*(v3_t **)o)[0x288 / 4](o, *(u32 *)(self + 0x134), 0, 1);
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tab = *(u8 **)(eng + 0x9b);
    u32 r = (*(g1_t **)tab)[0x4c / 4](tab, *(u32 *)(self + 0x134));
    ext_45fb00(self, r, *(u16 *)(self + 0x20f), 0);
  }
  (*(v0_t **)self)[0x28 / 4](self);
  u8 *Y = *(u8 **)(self + 0x138);
  if (Y) {
    u32 kids[32];
    u32 n = 0;
    (*(v1_t **)self)[0x324 / 4](self, 1);
    Y = *(u8 **)(self + 0x138);
    (*(u2_t **)Y)[0x7c / 4](Y, self + 0x6c, self + 0x60);
    Y = *(u8 **)(self + 0x138);
    (*(v0_t **)Y)[0x2c / 4](Y);
    Y = *(u8 **)(self + 0x138);
    u8 *node = *(u8 **)(Y + 0x50);
    while (node) {
      u8 *ch = *(u8 **)(node + 0x54);
      (*(v0_t **)ch)[0x2c / 4](ch);
      node = *(u8 **)(node + 0x60);
      kids[n++] = (u32)ch;
    }
    for (u32 i = 0; i < n; i++) (*(v3_t **)self)[0x288 / 4](self, kids[i], 0, 1);
  } else {
    *(u32 *)(self + 0xc4) = 0;
  }
  *(u32 *)(self + 0x1c9) = 0x41a00000;
}
PCREG(5129c0, fn5129c0);
