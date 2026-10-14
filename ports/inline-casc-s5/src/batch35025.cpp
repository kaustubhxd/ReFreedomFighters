// batch35025.cpp - cascade s5 batch 35025: 0x44a340 (GUESS register an object with every listed table object that does not know it yet).
#include "ff.h"

extern "C" void THISCALL ext_45eeb0(u8 *self, u8 *s, u32 b);   // thiscall, ret 8
typedef void(THISCALL *v1_t)(void *, void *);
typedef u32(THISCALL *g1_t)(void *, u32);
typedef u32(THISCALL *g1p_t)(void *, void *);
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, void *, u32);

// 0x44a340, thiscall(s, b) ret 8. 0x45eeb0(this, s, b). L = [this+0x18]; when set: L slot 0x4c(&it), then for each e returned by L slot 0x5c(&it) while it[0] != 0: when s slot 0x28(e) is zero
// and the engine-table ([engine+0x9b]) slot 0x58(e) returns an object o, o slot 0x1e4(s, b).
static void THISCALL fn44a340(u8 *self, u8 *s, u32 b) {
  u32 it[3];
  ext_45eeb0(self, s, b);
  u8 *L = *(u8 **)(self + 0x18);
  if (!L) return;
  (*(v1_t **)L)[0x4c / 4](L, it);
  L = *(u8 **)(self + 0x18);
  u32 e = (*(g1p_t **)L)[0x5c / 4](L, it);
  if (it[0] == 0) return;
  do {
    if (!(*(g1_t **)s)[0x28 / 4](s, e)) {
      u8 *eng = G(u8 *, 0x70039c);
      u8 *tab = *(u8 **)(eng + 0x9b);
      u8 *o = (*(e1_t **)tab)[0x58 / 4](tab, e);
      if (o) (*(v2_t **)o)[0x1e4 / 4](o, s, b);
    }
    L = *(u8 **)(self + 0x18);
    e = (*(g1p_t **)L)[0x5c / 4](L, it);
  } while (it[0] != 0);
}
PCREG(44a340, fn44a340);
