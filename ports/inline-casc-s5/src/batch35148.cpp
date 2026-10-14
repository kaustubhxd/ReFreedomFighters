// batch35148.cpp - cascade s5 batch 35148: 0x4c2100 (GUESS deserialize a field block from a stream).
#include "ff.h"

typedef void(THISCALL *v1p_t)(void *, void *);

// 0x4c2100, thiscall(s) ret 4, returns al = 1. this[4] &= ~0x40; then stream s slots, each with one out pointer into this: 0x48 (+0x48), 0x48 (+0x4c), 0x40 (+0x50), 0x48 (+0x54), 0x68 (+0x58),
// 0x50 (+0x59), 0x50 (+0x5d), 0x50 (+0x61).
static u8 THISCALL fn4c2100(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  (*(v1p_t **)s)[0x48 / 4](s, self + 0x48);
  (*(v1p_t **)s)[0x48 / 4](s, self + 0x4c);
  (*(v1p_t **)s)[0x40 / 4](s, self + 0x50);
  (*(v1p_t **)s)[0x48 / 4](s, self + 0x54);
  (*(v1p_t **)s)[0x68 / 4](s, self + 0x58);
  (*(v1p_t **)s)[0x50 / 4](s, self + 0x59);
  (*(v1p_t **)s)[0x50 / 4](s, self + 0x5d);
  (*(v1p_t **)s)[0x50 / 4](s, self + 0x61);
  return 1;
}
PCREG(4c2100, fn4c2100);
