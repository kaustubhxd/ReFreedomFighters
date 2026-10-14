// batch35120.cpp - cascade s5 batch 35120: 0x4728a0 (GUESS notify state 0xe / 0xf when the argument is the primary / secondary item; sibling of 0x475010).
#include "ff.h"

typedef u32(THISCALL *g0_t)(void *);
typedef u32(THISCALL *g1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

// 0x4728a0, thiscall(a) ret 4. a == this slot 0x504(): when this slot 0x3f0() != 0xe, this slot 0x45c(0xe, [engine+0x9b] slot 0x4c(a)). Otherwise a == this slot 0x500(): the same with 0xf.
static void THISCALL fn4728a0(u8 *self, u32 a) {
  u32 state;
  if (a == (*(g0_t **)self)[0x504 / 4](self)) {
    state = 0xe;
  } else {
    if (a != (*(g0_t **)self)[0x500 / 4](self)) return;
    state = 0xf;
  }
  if ((*(g0_t **)self)[0x3f0 / 4](self) == state) return;
  u8 *eng = G(u8 *, 0x70039c);
  u32 f = (*(u32 **)self)[0x45c / 4];
  u32 r = (*(g1_t **)(*(u8 **)(eng + 0x9b)))[0x4c / 4](*(u8 **)(eng + 0x9b), a);
  ((v2_t)f)(self, state, r);
}
PCREG(4728a0, fn4728a0);
