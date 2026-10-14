// batch35067.cpp - cascade s5 batch 35067: 0x5d9e20 (GUESS reset two target objects through the engine table and clear four counters).
#include "ff.h"

typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);

static void reset_pair(u32 id, u32 x) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *o = (*(e1_t **)tab)[0x58 / 4](tab, id);
  (*(v1_t **)o)[0x27c / 4](o, x);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u8 *o2 = (*(e1_t **)tab)[0x58 / 4](tab, x);
  *(u32 *)(o2 + 0x30) |= 0x400;
  *(u32 *)(o + 0x48) = 0x218000;
  *(u32 *)(o + 0x30) = 0;
  (*(v0_t **)o)[0x250 / 4](o);
}

// 0x5d9e20, thiscall, no arguments. For (id, x) = ([+0x48], [+0x4c]) and then ([+0x50], [+0x54]): o = table slot 0x58(id) ([engine+0x9b]); o slot 0x27c(x); o2 = table slot 0x58(x); o2[0x30] |= 0x400;
// o[0x48] = 0x218000; o[0x30] = 0; o slot 0x250(). Finally the dwords +0x88, +0x90, +0x94, +0x8c are cleared.
static void THISCALL fn5d9e20(u8 *self) {
  reset_pair(*(u32 *)(self + 0x48), *(u32 *)(self + 0x4c));
  reset_pair(*(u32 *)(self + 0x50), *(u32 *)(self + 0x54));
  *(u32 *)(self + 0x88) = 0;
  *(u32 *)(self + 0x90) = 0;
  *(u32 *)(self + 0x94) = 0;
  *(u32 *)(self + 0x8c) = 0;
}
PCREG(5d9e20, fn5d9e20);
