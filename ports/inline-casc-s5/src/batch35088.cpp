// batch35088.cpp - cascade s5 batch 35088: 0x5d8470 (GUESS drain the engine's embedded queue, notify a listener and copy the engine word).
#include "ff.h"

typedef void(THISCALL *v1p_t)(void *, void *);
typedef u32(THISCALL *g1p_t)(void *, void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *c3_t)(u32 ecx, u32 a, u32 b, u32 c);   // thiscall with three further stack args

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5d8470, thiscall, no arguments. Q = [engine+0x9b] + 0x1c is an embedded object (vtable at Q): Q slot 0x54(&it); then Q slot 0x74(&it) is called (Q recomputed from the engine each time) until it returns 0.
// [this+0x30] slot 0x100(0x691564); [this+0xb7] (unaligned) = [engine+0x40] unless that is its own address; byte +0xbb = 1; o = [this+0x44]: o slot 0x130 called with ECX = o and stack args (o, word [this+0x48], 0).
static void THISCALL fn5d8470(u8 *self) {
  u32 it[3];
  u8 *eng = G(u8 *, 0x70039c);
  u8 *Q = *(u8 **)(eng + 0x9b) + 0x1c;
  (*(v1p_t **)Q)[0x54 / 4](Q, it);
  eng = G(u8 *, 0x70039c);
  Q = *(u8 **)(eng + 0x9b) + 0x1c;
  u32 p = (*(g1p_t **)Q)[0x74 / 4](Q, it);
  while (p) {
    eng = G(u8 *, 0x70039c);
    Q = *(u8 **)(eng + 0x9b) + 0x1c;
    p = (*(g1p_t **)Q)[0x74 / 4](Q, it);
  }
  u8 *l = *(u8 **)(self + 0x30);
  (*(v1_t **)l)[0x100 / 4](l, 0x691564);
  eng = G(u8 *, 0x70039c);
  u8 *src = eng + 0x40;
  if (self + 0xb7 != src) wr32u(self + 0xb7, *(u32 *)src);
  u8 *o = *(u8 **)(self + 0x44);
  u32 w = *(u16 *)(self + 0x48);
  self[0xbb] = 1;
  ((c3_t)(*(u32 **)o)[0x130 / 4])((u32)o, (u32)o, w, 0);
}
PCREG(5d8470, fn5d8470);
