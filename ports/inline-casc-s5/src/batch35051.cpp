// batch35051.cpp - cascade s5 batch 35051: 0x4f2cf0 (GUESS clear a flag mask on matching entries of an embedded list, removing emptied entries).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, void *);
typedef u8 *(THISCALL *g1p_t)(void *, void *);
typedef u32(THISCALL *g1_t)(void *, u32);

// 0x4f2cf0, thiscall(a, b, c) ret 0xc. x = engine table ([engine+0x9b]) slot 0x4c(c). The list object embedded (unaligned) at this+0x9f: slot 0x4c(&it), then for each p returned by slot 0x64(&it):
// p[4] == x and (byte p[0x10] == 0 or p[0xc] == b): p[8] &= ~a; when that leaves p[8] == 0 the list's slot 0x44(&it) is called.
static void THISCALL fn4f2cf0(u8 *self, u32 a, u32 b, u32 c) {
  u32 it[3];
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u32 x = (*(g1_t **)tab)[0x4c / 4](tab, c);
  u8 *s = self + 0x9f;
  (*(v1_t **)s)[0x4c / 4](s, it);
  u8 *p = (*(g1p_t **)s)[0x64 / 4](s, it);
  while (p) {
    if (*(u32 *)(p + 4) == x) {
      if (p[0x10] == 0 || *(u32 *)(p + 0xc) == b) {
        *(u32 *)(p + 8) &= ~a;
        if (*(u32 *)(p + 8) == 0) (*(v1_t **)s)[0x44 / 4](s, it);
      }
    }
    p = (*(g1p_t **)s)[0x64 / 4](s, it);
  }
}
PCREG(4f2cf0, fn4f2cf0);
