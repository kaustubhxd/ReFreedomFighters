// batch35008.cpp - cascade s5 batch 35008: 0x475010 (GUESS notify state 0xd / 0xc when the argument is the primary / secondary item).
#include "ff.h"

typedef u32(THISCALL *g0_t)(void *);
typedef u32(THISCALL *g1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

// 0x475010, thiscall(a) ret 4. Does nothing unless slot 0x560(a) is non-zero. When a == slot 0x504(): if slot 0x3f0() != 0xd, slot 0x45c(0xd, tab slot 0x4c(a)) with tab = [engine+0x9b].
// Otherwise when a == slot 0x500(): the same with 0xc.
static void THISCALL fn475010(u8 *self, u32 a) {
  if (!(*(g1_t **)self)[0x560 / 4](self, a)) return;
  u32 state;
  if (a == (*(g0_t **)self)[0x504 / 4](self)) {
    state = 0xd;
  } else {
    if (a != (*(g0_t **)self)[0x500 / 4](self)) return;
    state = 0xc;
  }
  if ((*(g0_t **)self)[0x3f0 / 4](self) == state) return;
  u8 *eng = G(u8 *, 0x70039c);
  void *tab = *(void **)(eng + 0x9b);
  u32 r = (*(g1_t **)tab)[0x4c / 4](tab, a);
  (*(v2_t **)self)[0x45c / 4](self, state, r);
}
PCREG(475010, fn475010);
