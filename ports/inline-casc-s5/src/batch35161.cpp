// batch35161.cpp - cascade s5 batch 35161: 0x4fb360 (GUESS deserialize two flag bytes and a resolved reference from a stream).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1p_t)(void *, void *);
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef u32(THISCALL *g1_t)(void *, u32);

// 0x4fb360, thiscall(s) ret 4, returns al = 1. this[4] &= ~0x40; this slot 0x84(); stream s slot 0x68 into this+0x5a and this+0x5b, slot 0x40 into a local id. id != 0: this[0x5c] = (engine[+0x9b] slot 0x58(id)) slot 0x100(0x67d9e8);
// otherwise this[0x5c] = 0.
static u8 THISCALL fn4fb360(u8 *self, u8 *s) {
  u32 id;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  (*(v0_t **)self)[0x84 / 4](self);
  (*(v1p_t **)s)[0x68 / 4](s, self + 0x5a);
  (*(v1p_t **)s)[0x68 / 4](s, self + 0x5b);
  (*(v1p_t **)s)[0x40 / 4](s, &id);
  if (id) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tab = *(u8 **)(eng + 0x9b);
    u8 *p = (*(e1_t **)tab)[0x58 / 4](tab, id);
    *(u32 *)(self + 0x5c) = (*(g1_t **)p)[0x100 / 4](p, 0x67d9e8);
  } else {
    *(u32 *)(self + 0x5c) = 0;
  }
  return 1;
}
PCREG(4fb360, fn4fb360);
