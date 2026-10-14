// batch35131.cpp - cascade s5 batch 35131: 0x4b8ec0 (GUESS read a record with one resolved id from stream s).
#include "ff.h"

typedef void(THISCALL *v1p_t)(void *, void *);
typedef u32(THISCALL *g1_t)(void *, u32);

static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4b8ec0, thiscall(s) ret 4, returns true. this[4] &= ~0x40. s slot 0x40(&id) (a stack dword filled by the stream); the unaligned dword +0x59 = [engine+0x9b] slot 0x58(id); s slot 0x68(this + 0x58) (byte); s slot 0x40 into +0x4c, +0x50, +0x54
// (dwords); s slot 0x44 into +0x48 and +0x4a (words).
static u8 THISCALL fn4b8ec0(u8 *self, u8 *s) {
  u32 id;
  *(u32 *)(self + 4) &= 0xffffffbf;
  (*(v1p_t **)s)[0x40 / 4](s, &id);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  wr32u(self + 0x59, (*(g1_t **)tab)[0x58 / 4](tab, id));
  (*(v1p_t **)s)[0x68 / 4](s, self + 0x58);
  (*(v1p_t **)s)[0x40 / 4](s, self + 0x4c);
  (*(v1p_t **)s)[0x40 / 4](s, self + 0x50);
  (*(v1p_t **)s)[0x40 / 4](s, self + 0x54);
  (*(v1p_t **)s)[0x44 / 4](s, self + 0x48);
  (*(v1p_t **)s)[0x44 / 4](s, self + 0x4a);
  return 1;
}
PCREG(4b8ec0, fn4b8ec0);
