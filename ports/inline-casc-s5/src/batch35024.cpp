// batch35024.cpp - cascade s5 batch 35024: 0x44a510 (GUESS apply every listed entry's value to its engine-table object).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, void *);
typedef u16 *(THISCALL *g1_t)(void *, void *);
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);

// 0x44a510, thiscall(a, b) ret 8; only the low byte of b is tested. L = [this+0x1c]; nothing when null. L slot 0x4c(&it), then for every p returned by L slot 0x64(&it) (L reloaded each time):
// o = (engine table [engine+0x9b]) slot 0x58(*(u32 *)p); when o is set: o slot 0x128(b ? word p[4] : word p[6], a, 0).
static void THISCALL fn44a510(u8 *self, u32 a, u32 b) {
  u32 it[4];
  u8 *L = *(u8 **)(self + 0x1c);
  if (!L) return;
  (*(v1_t **)L)[0x4c / 4](L, it);
  L = *(u8 **)(self + 0x1c);
  u8 *p = (u8 *)(*(g1_t **)L)[0x64 / 4](L, it);
  while (p) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tab = *(u8 **)(eng + 0x9b);
    u8 *o = (*(e1_t **)tab)[0x58 / 4](tab, *(u32 *)p);
    if (o) {
      u32 w = (u8)b ? *(u16 *)(p + 4) : *(u16 *)(p + 6);
      (*(v3_t **)o)[0x128 / 4](o, w, a, 0);
    }
    L = *(u8 **)(self + 0x1c);
    p = (u8 *)(*(g1_t **)L)[0x64 / 4](L, it);
  }
}
PCREG(44a510, fn44a510);
