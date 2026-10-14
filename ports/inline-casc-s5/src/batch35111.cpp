// batch35111.cpp - cascade s5 batch 35111: 0x57d780 (GUESS reset a panel: notify, clear the selection, fade matching children, notify again).
#include "ff.h"

extern "C" u8 THISCALL ext_4db9a0(u8 *self, u32 a);   // thiscall, ret 4, bool in AL
typedef u8 *(THISCALL *g0_t)(void *);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v1p_t)(void *, u8 **);

// 0x57d780, thiscall, no arguments. o = this slot 0x84(); o slot 0x350(0x14, 0, [this+0x44]); [this+0x18c] slot 0xbc(1); dword +0x33c = 0. Then the chain starting at [[this+0x310]+8] is walked: every node n for which
// 0x4db9a0(n, 0x20002c) is true gets [n+0x54] slot 0x250(0xff); the next node comes from [this+0x310] slot 0x50(&n). Finally this slot 0x84() slot 0x30c(1).
static void THISCALL fn57d780(u8 *self) {
  u8 *o = (*(g0_t **)self)[0x84 / 4](self);
  (*(v3_t **)o)[0x350 / 4](o, 0x14, 0, *(u32 *)(self + 0x44));
  u8 *X = *(u8 **)(self + 0x18c);
  *(u32 *)(self + 0x33c) = 0;
  (*(v1_t **)X)[0xbc / 4](X, 1);
  u8 *n = *(u8 **)(*(u8 **)(self + 0x310) + 8);
  if (n) {
    do {
      if (ext_4db9a0(n, 0x20002c)) {
        u8 *c = *(u8 **)(n + 0x54);
        (*(v1_t **)c)[0x250 / 4](c, 0xff);
      }
      u8 *L = *(u8 **)(self + 0x310);
      (*(v1p_t **)L)[0x50 / 4](L, &n);
    } while (n);
  }
  u8 *o2 = (*(g0_t **)self)[0x84 / 4](self);
  (*(v1_t **)o2)[0x30c / 4](o2, 1);
}
PCREG(57d780, fn57d780);
