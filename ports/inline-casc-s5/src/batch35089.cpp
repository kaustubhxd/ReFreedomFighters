// batch35089.cpp - cascade s5 batch 35089: 0x5c5620 (GUESS read a configured id, resolve it, look up a resource word and apply it).
#include "ff.h"

typedef u8 *(THISCALL *g0_t)(void *);
typedef void(THISCALL *v2_t)(void *, u32, u32 *);
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef u32(THISCALL *g6_t)(void *, u32, u32, u32, u32, u32 *, u32);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x5c5620, thiscall, no arguments, returns EAX. With tab = [engine+0x9b]: o = tab slot 0x138(); id = 0 then o slot 0x88(0x6a5c48, &id); p = tab slot 0x58(id); null gives 0. Otherwise
// w = low word of tab slot 0x114(0x6a5c68, 0, 0x6b4204, 0x85, &r, 0); p slot 0x128(w) (the vtable of p read first); returns r (written by the 0x114 call).
static u32 THISCALL fn5c5620(u8 *self) {
  u32 id, r;
  (void)self;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *o = (*(g0_t **)tab)[0x138 / 4](tab);
  id = 0;
  (*(v2_t **)o)[0x88 / 4](o, 0x6a5c48, &id);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u8 *p = (*(e1_t **)tab)[0x58 / 4](tab, id);
  if (!p) return 0;
  u32 f = (*(u32 **)p)[0x128 / 4];
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 w = (*(g6_t **)tab)[0x114 / 4](tab, 0x6a5c68, 0, 0x6b4204, 0x85, &r, 0);
  ((v1_t)f)(p, w & 0xffff);
  return r;
}
PCREG(5c5620, fn5c5620);
