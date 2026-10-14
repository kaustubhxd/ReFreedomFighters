// batch35109.cpp - cascade s5 batch 35109: 0x5b9640 (GUESS read an entry with two ids resolved through the engine table from a stream).
#include "ff.h"

typedef void(THISCALL *v1p_t)(void *, u32 *);
typedef u32(THISCALL *g1_t)(void *, u32);

// 0x5b9640, thiscall(s) ret 4, returns true. this[4] &= ~0x40. The stream s slot 0x40(&dst) reads one dword into dst: +0x48, +0x4c, an id (resolved with [engine+0x9b] slot 0x58 into +0x50), a second id (into +0x54), then +0x58, +0x5c.
static u8 THISCALL fn5b9640(u8 *self, u8 *s) {
  u32 id;
  *(u32 *)(self + 4) &= 0xffffffbf;
  (*(v1p_t **)s)[0x40 / 4](s, (u32 *)(self + 0x48));
  (*(v1p_t **)s)[0x40 / 4](s, (u32 *)(self + 0x4c));
  (*(v1p_t **)s)[0x40 / 4](s, &id);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  *(u32 *)(self + 0x50) = (*(g1_t **)tab)[0x58 / 4](tab, id);
  (*(v1p_t **)s)[0x40 / 4](s, &id);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  *(u32 *)(self + 0x54) = (*(g1_t **)tab)[0x58 / 4](tab, id);
  (*(v1p_t **)s)[0x40 / 4](s, (u32 *)(self + 0x58));
  (*(v1p_t **)s)[0x40 / 4](s, (u32 *)(self + 0x5c));
  return 1;
}
PCREG(5b9640, fn5b9640);
