// batch35009.cpp - cascade s5 batch 35009: 0x46b650 (GUESS does the iterable at +0x7c contain the entry the engine table resolves for an object).
#include "ff.h"

typedef u32(THISCALL *g0_t)(void *);
typedef u32(THISCALL *g1_t)(void *, void *);
typedef u32(THISCALL *g1u_t)(void *, u32);

// 0x46b650, thiscall(o) ret 4, returns bool (al). L = [this+0x7c]; true when L slot 0x14() is zero. target = engine-table([engine+0x9b]) slot 0x4c(o slot 0x2e8()).
// Then, when L (reloaded) is non-null: L slot 0x4c(&it) starts an iteration; e = L slot 0x5c(&it) (L reloaded every time); while it[0] != 0: e == target gives true, else next e.
static u8 THISCALL fn46b650(u8 *self, void *o) {
  void *L = *(void **)(self + 0x7c);
  if (!(*(g0_t **)L)[0x14 / 4](L)) return 1;
  u32 x = (*(g0_t **)o)[0x2e8 / 4](o);
  u8 *eng = G(u8 *, 0x70039c);
  void *tab = *(void **)(eng + 0x9b);
  u32 target = (*(g1u_t **)tab)[0x4c / 4](tab, x);
  L = *(void **)(self + 0x7c);
  if (!L) return 0;
  u32 it[3];
  (*(g1_t **)L)[0x4c / 4](L, it);
  L = *(void **)(self + 0x7c);
  u32 e = (*(g1_t **)L)[0x5c / 4](L, it);
  while (it[0] != 0) {
    if (e == target) return 1;
    L = *(void **)(self + 0x7c);
    e = (*(g1_t **)L)[0x5c / 4](L, it);
  }
  return 0;
}
PCREG(46b650, fn46b650);
