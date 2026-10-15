// batch66081.cpp - cascade s4 batch 66081: 0x507420 (tier H row from the queue, redone by Sonnet).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x507420, thiscall(p) ret 4 (this = t): A = {*r0, *r1, *r2} and B = {*r3, *r4, *r5} where rK = 0x5003d0(p[4], K) (called in the order 2, 1, 0, 5, 4, 3); g = t[0x18]: g->slot 0x189 (0x624)(1.0f raw bits 0x3f800000);
// g->slot 0x18c (0x630)(&C) (C: 12 bytes filled by the callee); g->slot 0x17a (0x5e8)(&B); g->slot 0x178 (0x5e0)(&C, &A).
static void THISCALL fn507420(u8 *t, u8 *p) {
  u32 A[3];
  u32 B[3];
  u32 C[3];
  u8 *r2 = ext_5003d0(*(u8 **)(p + 4), 2);
  u8 *r1 = ext_5003d0(*(u8 **)(p + 4), 1);
  u8 *r0 = ext_5003d0(*(u8 **)(p + 4), 0);
  A[0] = rd(r0);
  A[1] = rd(r1);
  A[2] = rd(r2);
  u8 *r5 = ext_5003d0(*(u8 **)(p + 4), 5);
  u8 *r4 = ext_5003d0(*(u8 **)(p + 4), 4);
  u8 *r3 = ext_5003d0(*(u8 **)(p + 4), 3);
  B[0] = rd(r3);
  B[1] = rd(r4);
  B[2] = rd(r5);
  u8 *g = *(u8 **)(t + 0x18);
  (*(v1_t **)g)[0x624 / 4](g, 0x3f800000u);
  g = *(u8 **)(t + 0x18);
  (*(v1_t **)g)[0x630 / 4](g, (u32)C);
  g = *(u8 **)(t + 0x18);
  (*(v1_t **)g)[0x5e8 / 4](g, (u32)B);
  g = *(u8 **)(t + 0x18);
  (*(v2_t **)g)[0x5e0 / 4](g, (u32)C, (u32)A);
}
PCREG(507420, fn507420);
