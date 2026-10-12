// batch6348.cpp - unclaimed-63 gap-band batch 48: 0x4d3840 (C-set; no GC name), thiscall, one stack argument X (a stream), ret 4.
//   O = this + 0x4008. L; node = O->vtbl[+0x4c](&L) (noop), node = O->vtbl[+0x5c](&L); while L != 0:
//     v = node[0] + node[+8] + 0xc; X->vtbl[+0x10](&v, 4) (thiscall, two stack arguments, ret 8);
//     X->vtbl[+0x10](node, v) (same); idx = (node[+4] - 0x6e7a30) / 20 (signed); X->vtbl[+0x3c](idx) (thiscall, one argument);
//     node = O->vtbl[+0x5c](&L).
//   After the loop: m = -1; X->vtbl[+0x10](&m, 4).
#include "ff.h"

typedef void(THISCALL * w2_fn)(void *, u32, u32);
typedef void(THISCALL * one_fn)(void *, u32);
typedef void(THISCALL * p1_fn)(void *, u32 *);
typedef u32(THISCALL * q_fn)(void *, u32 *);

// 0x4d3840 (C-set).
static void THISCALL unnamed4d3840(u8 *self, u32 x) {
  u8 *o = self + 0x4008;
  u32 L = 0;
  ((p1_fn)(*(u32 *)(*(u32 *)o + 0x4c)))((void *)o, &L);
  u32 node = ((q_fn)(*(u32 *)(*(u32 *)o + 0x5c)))((void *)o, &L);
  while (L != 0) {
    u32 v = *(u32 *)node + *(u32 *)(node + 8) + 0xcu;
    ((w2_fn)(*(u32 *)(*(u32 *)x + 0x10)))((void *)x, (u32)&v, 4u);
    ((w2_fn)(*(u32 *)(*(u32 *)x + 0x10)))((void *)x, node, v);
    int idx = ((int)(*(u32 *)(node + 4) - 0x6e7a30u)) / 20;
    ((one_fn)(*(u32 *)(*(u32 *)x + 0x3c)))((void *)x, (u32)idx);
    node = ((q_fn)(*(u32 *)(*(u32 *)o + 0x5c)))((void *)o, &L);
  }
  u32 m = 0xffffffffu;
  ((w2_fn)(*(u32 *)(*(u32 *)x + 0x10)))((void *)x, (u32)&m, 4u);
}
PCREG(4d3840, unnamed4d3840);
