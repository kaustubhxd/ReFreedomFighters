// batch4125.cpp - unclaimed-41 batch 25 (slice 13): 0x5af990 ZFFInventoryBridge::GiveWeapon(EFFItemType, unsigned int, bool, bool).
// Thiscall, four stack arguments (type, n, a, b), ret 0x10. Every call is callee-pop (no esp adjustment after the call).
#include "ff.h"

extern "C" u32 THISCALL ext_5af130(u8 *self, u32 type);          // ecx = *(self+4); one stack argument (checksum stub, GUESS)
extern "C" u32 THISCALL ext_473cd0(u8 *self, u8 *a, u32 b);       // ecx = Z; two stack arguments (checksum stub, GUESS)

typedef u32(THISCALL * f0_t)(u8 *);
typedef u32(THISCALL * f1_t)(u8 *, u32);
typedef u32(THISCALL * f2_t)(u8 *, u32, u32);
typedef u32(THISCALL * f3_t)(u8 *, u32, u32, u32);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

// L_a7a..L_afafc of 0x5af990: Z.vt[0x55c](W); esi = Q, or (when Q is null) the object returned through W.vt[0x328] and its
// 0x2c4 result T, with T's slots 0x4c (through the render manager), 0x2f0 and 0x2d0; then esi.vt[0x324](arg2) with arg2
// replaced by R0[+0xc] - N when b is set.
static void tailA7a(u8 *self, u8 *W, u8 *R0, u32 N, u32 b, u32 arg2) {
  u8 *Z = *(u8 **)self;
  u32 Q = ((f1_t)vslot(Z, 0x55c))(Z, (u32)W);
  u8 *esi;
  if (Q != 0) {
    esi = (u8 *)Q;
  } else {
    u8 *R = (u8 *)((f0_t)vslot(W, 0x328))(W);
    u8 *Zc = *(u8 **)self;
    u32 S = ((f1_t)vslot(Zc, 0x20))(Zc, 0x4954454du);
    u8 *Tp = (u8 *)((f1_t)vslot(R, 0x2c4))(R, S);
    u8 *ob2 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 V2 = ((f3_t)vslot(ob2, 0x4c))(ob2, *(u32 *)self, 0u, 1u);
    ((f1_t)vslot(Tp, 0x2f0))(Tp, V2);
    ((f2_t)vslot(Tp, 0x2d0))(Tp, 1u, 0u);
    esi = Tp;
  }
  if (b != 0)
    arg2 = *(u32 *)(R0 + 0xc) - N;
  ((f1_t)vslot(esi, 0x324))(esi, arg2);
}

// 0x5af990: type, n, a and b are stack arguments; a and b are bools (tested as bytes).
static void THISCALL fn5af990(u8 *self, u32 type, u32 n, u32 a, u32 b) {
  u8 *R0 = (u8 *)ext_5af130(*(u8 **)(self + 4), type);
  if (R0 == 0)
    return;
  u8 *X = *(u8 **)R0;
  if (X == 0)
    return;

  u8 *rm = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(rm + 0x9b);
  u8 *W = (u8 *)((f2_t)vslot(X, 0x2c4))(X, *(u32 *)(o + 0xadc), 0x4954454du);
  if (W == 0)
    return;

  u8 *ob = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 V = ((f3_t)vslot(ob, 0x4c))(ob, *(u32 *)self, 0u, 1u);
  ((f1_t)vslot(W, 0x2f0))(W, V);
  ((f2_t)vslot(W, 0x2d0))(W, 1u, 0u);
  u32 N = ((f0_t)vslot(W, 0x364))(W);

  if (N > n && b == 0) {
    ((f1_t)vslot(W, 0x360))(W, n);
  } else {
    ((f1_t)vslot(W, 0x360))(W, N);
    ((f1_t)vslot(W, 0x358))(W, 1u);
    u32 arg2 = (n > N) ? n - N : 0u;
    bool toA7a = (n > N) || (b != 0);
    if (toA7a)
      tailA7a(self, W, R0, N, b, arg2);
  }

  // L_b09
  if (a == 0)
    return;
  u8 *Zb = *(u8 **)self;
  if (((f0_t)vslot(Zb, 0x504))(Zb) != 0)
    return;
  ((f2_t)vslot(W, 0x2d0))(W, 0u, 0u);
  ext_473cd0(Zb, W, 0u);
}
PCREG(5af990, fn5af990);
