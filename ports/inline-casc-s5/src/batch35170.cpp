// batch35170.cpp - cascade s5 batch 35170: 0x43fdd0 (GUESS forward an event to a handler, falling back to a default placement).
#include "ff.h"

typedef void(THISCALL *h4_t)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *g0_t)(void *);
typedef void(THISCALL *p3_t)(void *, u32, u32, u32 *);

// 0x43fdd0, thiscall(a, b, c, d) ret 0x10, no return value (the stack cookie is not reproduced). When [[this+8]+0x6c] != 0 or this[0x14] & 1: this slot 0xe0(a, b, c, d); when this slot 0x20() returns 0:
// v = {0x459c4000, 1.0f (0x3f800000), 0x459c4000}; a slot 0x84(c, d, v).
static void THISCALL fn43fdd0(u8 *self, u8 *a, u32 b, u32 c, u32 d) {
  u8 *o = *(u8 **)(self + 8);
  if (*(u32 *)(o + 0x6c) != 0 || (self[0x14] & 1)) {
    (*(h4_t **)self)[0xe0 / 4](self, (u32)a, b, c, d);
    if ((*(g0_t **)self)[0x20 / 4](self) == 0) {
      u32 v[3];
      v[0] = 0x459c4000;
      v[1] = 0x3f800000;
      v[2] = 0x459c4000;
      (*(p3_t **)a)[0x84 / 4](a, c, d, v);
    }
  }
}
PCREG(43fdd0, fn43fdd0);
