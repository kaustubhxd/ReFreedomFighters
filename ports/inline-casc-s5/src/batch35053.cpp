// batch35053.cpp - cascade s5 batch 35053: 0x4af6d0 (GUESS resolve an object through the engine table, by id or by a configured name).
#include "ff.h"

typedef u32(THISCALL *g1_t)(void *, u32);
typedef u32(THISCALL *g0_t)(void *);
typedef void(THISCALL *v3_t)(void *, u32, u32 *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32 *);

static u32 table_lookup(u32 id) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  return (*(g1_t **)tab)[0x58 / 4](tab, id);
}

// 0x4af6d0, thiscall, no arguments, returns EAX. Byte +0x55 clear: table slot 0x58([+0x48]). Otherwise id = [+0x58]; when id resolves to an object o: o slot 0x128(word [+0x5c], &x, 0); when x != 0 and x resolves
// (table slot 0x58(x) non-null) that object is returned. Fallback: the table's slot 0x138() object q: q slot 0x88(0x681320, &x) with x = 0 before, then table slot 0x58(x) is returned.
static u32 THISCALL fn4af6d0(u8 *self) {
  u32 x;
  if (self[0x55] == 0) return table_lookup(*(u32 *)(self + 0x48));
  u32 id = *(u32 *)(self + 0x58);
  if (id) {
    u8 *o = (u8 *)table_lookup(id);
    if (o) {
      (*(v3_t **)o)[0x128 / 4](o, *(u16 *)(self + 0x5c), &x, 0);
      if (x) {
        u32 r = table_lookup(x);
        if (r) return r;
      }
    }
  }
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *q = (u8 *)(*(g0_t **)tab)[0x138 / 4](tab);
  x = 0;
  (*(v2_t **)q)[0x88 / 4](q, 0x681320, &x);
  return table_lookup(x);
}
PCREG(4af6d0, fn4af6d0);
